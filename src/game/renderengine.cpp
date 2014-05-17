/***************************************************************************
 *   Copyright (C) 2013 by Mike McLean   *
 *   libolt@libolt.net   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifdef __ANDROID__
#include "android-config.h"
#else
#include "config.h"
#endif

#include "gameengine.h"
#include "gamestate.h"
#include "gui.h"
#include "logging.h"
#include "physicsengine.h"
#include "renderengine.h"
#include "soundengine.h"
#include "teams.h"

#ifndef OGRE_PLUGIN_DIR
#define OGRE_PLUGIN_DIR
#endif

renderEngine* renderEngine::pInstance = 0;
renderEngine* renderEngine::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new renderEngine; // create sole instance
    }
    return pInstance; // address of sole instance
}


renderEngine::renderEngine()
{

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    gStaticPluginLoader = NULL;
	mAssetMgr = NULL;
	mSceneMgr = NULL;
#endif
   mWindow = NULL;
   mRoot = NULL;
}

renderEngine::~renderEngine()
{
}

bool renderEngine::frameStarted()
{
	return true;
}
bool renderEngine::frameEnded()
{
	return true;
}
Root *renderEngine::getMRoot()
{
	return (mRoot);
}
void renderEngine::setMRoot(Root *root)
{
	mRoot = root;
}

Camera *renderEngine::getMCamera()
{
	return (mCamera);
}
void renderEngine::setMCamera(Camera *camera)
{
	mCamera = camera;
}

SceneManager *renderEngine::getMSceneMgr()
{
	return (mSceneMgr);
}
void renderEngine::setMSceneMgr(SceneManager *sceneMgr)
{
	mSceneMgr = sceneMgr;
}

RenderWindow *renderEngine::getMWindow()
{
	return (mWindow);
}
void renderEngine::setMWindow(RenderWindow *window)
{
	mWindow = window;
}

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID

AAssetManager *renderEngine::getMAssetMgr()
{
	return (mAssetMgr);
}
void renderEngine::setMAssetMgr(AAssetManager *asset)
{
	mAssetMgr = asset;
}

android_app *renderEngine::getApp()
{
	return (app);
}
void renderEngine::setApp(android_app *ap)
{
	app = ap;
}
#endif

Vector3 renderEngine::getMTranslateVector()
{
	return (mTranslateVector);
}
void renderEngine::setMTranslateVector(Vector3 vector)
{
	mTranslateVector = vector;
}

Radian renderEngine::getMRotX()
{
	return (mRotX);
}
void renderEngine::setMRotX(Radian rotX)
{
	mRotX = rotX;
}

Radian renderEngine::getMRotY()
{
	return (mRotY);
}
void renderEngine::setMRotY(Radian rotY)
{
	mRotY = rotY;
}

Real renderEngine::getMMoveSpeed()
{
	return (mMoveSpeed);
}
void renderEngine::setMMoveSpeed(Real speed)
{
	mMoveSpeed = speed;
}

Degree renderEngine::getMRotateSpeed()
{
	return (mRotateSpeed);
}
void renderEngine::setMRotateSpeed(Degree speed)
{
	mRotateSpeed = speed;
}

float renderEngine::getMMoveScale()
{
	return (mMoveScale);
}
void renderEngine::setMMoveScale(float scale)
{
	mMoveScale = scale;
}

Degree renderEngine::getMRotScale()
{
	return (mRotScale);
}
void renderEngine::setMRotScale(Degree scale)
{
	mRotScale = scale;
}

String renderEngine::getMResourceGroup()
{
	return (mResourceGroup);
}

void renderEngine::setMResourceGroup(String resource)
{
	mResourceGroup = resource;
}

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
Ogre::DataStreamPtr renderEngine::openAPKFile(const Ogre::String& fileName)
{
    struct android_app* app;
	Ogre::DataStreamPtr stream;
	AConfiguration* config = AConfiguration_new();

	JNIEnv* env = (JNIEnv*)SDL_AndroidGetJNIEnv();

    jclass class_sdl_activity   = env->FindClass("org/libsdl/app/SDLActivity");
    jclass class_activity       = env->FindClass("android/app/Activity");
    jclass class_resources      = env->FindClass("android/content/res/Resources");
    jmethodID method_get_resources      = env->GetMethodID(class_activity, "getResources", "()Landroid/content/res/Resources;");
    jmethodID method_get_assets         = env->GetMethodID(class_resources, "getAssets", "()Landroid/content/res/AssetManager;");
    jobject raw_activity = (jobject)SDL_AndroidGetActivity();
	jobject raw_resources = env->CallObjectMethod(raw_activity, method_get_resources);
    jobject raw_asset_manager = env->CallObjectMethod(raw_resources, method_get_assets);
    mAssetMgr = AAssetManager_fromJava(env, raw_asset_manager);

//    AConfiguration_fromAssetManager(config, mAssetMgr);
    logMsg("APK?");

//	mAssetMgr = app->activity->assetManager;
    AAsset* asset = AAssetManager_open(mAssetMgr, fileName.c_str(), AASSET_MODE_BUFFER);
    if(asset)
    {
		off_t length = AAsset_getLength(asset);
        void* membuf = OGRE_MALLOC(length, Ogre::MEMCATEGORY_GENERAL);
        memcpy(membuf, AAsset_getBuffer(asset), length);
        AAsset_close(asset);

        stream = Ogre::DataStreamPtr(new Ogre::MemoryDataStream(membuf, length, true, true));
    }
    return stream;
}
#endif

bool renderEngine::initSDL() // Initializes SDL Subsystem
{
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_EVENTS) != 0)
	{
        fprintf(stderr,
                "\nUnable to initialize SDL:  %s\n",
                SDL_GetError()
               );
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID

//        __android_log_print(ANDROID_LOG_DEBUG, "com.libolt.ubc", "SDL Error = %s", SDL_GetError());
        Ogre::String msg = "SDL Error = " +Ogre::StringConverter::toString(SDL_GetError());
        logMsg(msg);
#endif

        return 1;
    }

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
/*    sdlWindow = SDL_CreateWindow("Ultimate Basketball Challenge",
	                             SDL_WINDOWPOS_UNDEFINED,
	                             SDL_WINDOWPOS_UNDEFINED,
	                             0,0,SDL_WINDOW_SHOWN);


    sdlWindow = SDL_CreateWindow("UBC", SDL_WINDOWPOS_UNDEFINED,
	                             SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
*/
    std::string message = "SDL Window Created!";
	logMsg(message);

#else
    sdlWindow = SDL_CreateWindow("Ultimate Basketball Challenge",
	                             SDL_WINDOWPOS_UNDEFINED,
	                             SDL_WINDOWPOS_UNDEFINED,
	                             1024,768,0);

    SDL_VERSION( &sysInfo.version );


    if (SDL_GetWindowWMInfo(sdlWindow, &sysInfo) <= 0)
    {
    	assert( false );
    }
#endif

	return true;
}

bool renderEngine::initOgre() // Initializes Ogre Subsystem
{
	//    GUISystem *gui = GUISystem::Instance();
	//    SoundSystem *sound = SoundSystem::Instance();

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	winHandle = toString((unsigned long int)sysInfo.info.win.window);
#elif OGRE_PLATFORM == OGRE_PLATFORM_LINUX
	winHandle = Ogre::StringConverter::toString((unsigned long)sysInfo.info.x11.window);
#elif OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    JNIEnv* env = (JNIEnv*)SDL_AndroidGetJNIEnv();
//    m_sdl_gl_context = SDL_GL_GetCurrentContext();

    jclass class_sdl_activity   = env->FindClass("org/libsdl/app/SDLActivity");
    jmethodID method_get_native_surface = env->GetStaticMethodID(class_sdl_activity, "getNativeSurface", "()Landroid/view/Surface;");
    jobject raw_surface = env->CallStaticObjectMethod(class_sdl_activity, method_get_native_surface);
    ANativeWindow* native_window = ANativeWindow_fromSurface(env, raw_surface);

	winHandle =  Ogre::StringConverter::toString((int)native_window);
#else
	// Error, both can't be defined or undefined same time
#endif

	//std::cout << "winHandle = " << winHandle << std::endl;
	mRoot = new Ogre::Root("", "", "Ogre.log");
	const Ogre::String pluginDir = OGRE_PLUGIN_DIR;

//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//#else
	inputSystem *input = inputSystem::Instance();
//#endif
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	const Ogre::String buildType = BUILD_TYPE;

	if (buildType == "Debug")
	{
		mRoot->loadPlugin(pluginDir + "/RenderSystem_Direct3D9_d.dll");
		mRoot->loadPlugin(pluginDir + "/Plugin_CgProgramManager_d");
	}
	else
	{
		mRoot->loadPlugin(pluginDir + "/RenderSystem_Direct3D9");
		mRoot->loadPlugin(pluginDir + "/Plugin_CgProgramManager");
	}
#elif OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	//	    mRoot->loadPlugin();
#ifdef OGRE_STATIC_LIB
	gStaticPluginLoader = new Ogre::StaticPluginLoader();
	gStaticPluginLoader->load();
#endif
#elif OGRE_PLATFORM == OGRE_PLATFORM_APPLE
	mRoot->loadPlugin("RenderSystem_GL");
#else
	mRoot->loadPlugin(pluginDir + "/RenderSystem_GL");
	mRoot->loadPlugin(pluginDir + "/Plugin_CgProgramManager");
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	mRoot->setRenderSystem(mRoot->getAvailableRenderers().at(0));
	mRoot->initialise(false);
#else
	Ogre::RenderSystemList rsList = mRoot->getAvailableRenderers();


	//	r_it = renderEngine->begin();
	//    	mRoot->setRenderSystem(*r_it);
	//	mWindow = mRoot->initialise(false);
	//	exit(0);

	int c = 0;
	bool foundit = false;
	Ogre::RenderSystem *selectedRenderSystem = 0;
	while (c < (int)rsList.size())
	{
		selectedRenderSystem = rsList.at(c);
		Ogre::String rname = selectedRenderSystem->getName();
		if (rname.compare("OpenGL Rendering Subsystem") == 0)
		{
			foundit = true;
			break;
		}
		c++; // <-- oh how clever
		logMsg(Ogre::StringConverter::toString(c++));
	}

	//we found it, we might as well use it!
	mRoot->setRenderSystem(selectedRenderSystem);
//		selectedRenderSystem->setConfigOption("Full Screen","False");
//	selectedRenderSystem->setOption("Video Mode","1024 x 768 @ 32-bit colour");

	//	mWindow = mRoot->initialise(true, "Ultimate Basketball Challenge");
	mWindow = mRoot->initialise(false, "Ultimate Basketball Challenge");
#endif

    logMsg("OGRE initialized successfully!");

	return true;
}

void renderEngine::createSceneManager()
{
    renderEngine *render = renderEngine::Instance();

    // Create the SceneManager, in this case a generic one
    render->setMSceneMgr(render->getMRoot()->createSceneManager(ST_EXTERIOR_CLOSE));

}

bool renderEngine::createWindow()
{
	return true;
}



bool renderEngine::createScene()
{


#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    logMsg("Hello");
	config = AConfiguration_new();
	logMsg("Mello");
//	AConfiguration_fromAssetManager(config, app->activity->assetManager);
//	mAssetMgr = app->activity->assetManager;
    JNIEnv* env = (JNIEnv*)SDL_AndroidGetJNIEnv();

    jclass class_sdl_activity   = env->FindClass("org/libsdl/app/SDLActivity");
    jmethodID method_get_native_surface = env->GetStaticMethodID(class_sdl_activity, "getNativeSurface", "()Landroid/view/Surface;");
    jobject raw_surface = env->CallStaticObjectMethod(class_sdl_activity, method_get_native_surface);
    ANativeWindow* native_window = ANativeWindow_fromSurface(env, raw_surface);

    if ( !native_window )
	{
		logMsg("No Window, Goodbye!");
        return(0);
	}

    jclass class_activity       = env->FindClass("android/app/Activity");
    jclass class_resources      = env->FindClass("android/content/res/Resources");
    jmethodID method_get_resources      = env->GetMethodID(class_activity, "getResources", "()Landroid/content/res/Resources;");
    jmethodID method_get_assets         = env->GetMethodID(class_resources, "getAssets", "()Landroid/content/res/AssetManager;");
    jobject raw_activity = (jobject)SDL_AndroidGetActivity();
	jobject raw_resources = env->CallObjectMethod(raw_activity, method_get_resources);
    jobject raw_asset_manager = env->CallObjectMethod(raw_resources, method_get_assets);
    mAssetMgr = AAssetManager_fromJava(env, raw_asset_manager);
	logMsg("Yello");
    AConfiguration_fromAssetManager(config, mAssetMgr);
	logMsg("Bello");
//	mAssetMgr = app->activity->assetManager;

    Ogre::ArchiveManager::getSingleton().addArchiveFactory( new Ogre::APKFileSystemArchiveFactory(mAssetMgr) );
    Ogre::ArchiveManager::getSingleton().addArchiveFactory( new Ogre::APKZipArchiveFactory(mAssetMgr) );
	logMsg("Hello?");
	//  AConfiguration_fromAssetManager(config, app->activity->assetManager);
	//gAssetMgr = app->activity->assetManager;
	misc["androidConfig"] = Ogre::StringConverter::toString((int)config);
	//    misc["externalWindowHandle"] = Ogre::StringConverter::toString((int)app->window);

//	misc["currentGLContext"]     = "true";
//    misc["externalGLContext"]    = Ogre::StringConverter::toString( (int)SDL_GL_GetCurrentContext() );
	misc["externalWindowHandle"] = winHandle;
//	exit(0);
	logMsg("Hello??");
	mWindow = mRoot->createRenderWindow("UBC", 0, 0, false, &misc);
//	exit(0);
	logMsg("Dead");
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	Ogre::ConfigFile cf;
	cf.load(openAPKFile("resources.cfg"));
    logMsg("or");
	Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
//exit(0);
	while (seci.hasMoreElements())
	{
		Ogre::String sec, type, arch;
		sec = seci.peekNextKey();
		Ogre::ConfigFile::SettingsMultiMap* settings = seci.getNext();
		Ogre::ConfigFile::SettingsMultiMap::iterator i;

		for (i = settings->begin(); i != settings->end(); i++)
		{
			type = i->first;
			arch = i->second;
			Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch, type, sec);
		}
	}

	Ogre::ResourceGroupManager::getSingletonPtr()->initialiseResourceGroup(Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

	Ogre::RTShader::ShaderGenerator::initialize();
	Ogre::RTShader::ShaderGenerator::getSingletonPtr()->setTargetLanguage("glsles");
	mMatListener = new Ogre::ShaderGeneratorTechniqueResolverListener();
	Ogre::MaterialManager::getSingleton().addListener(mMatListener);
#else

	// logMsg("Rendering!");
	misc["externalWindowHandle"] = winHandle; //

	mWindow = mRoot->createRenderWindow("Ultimate Basketball Challenge", 1024, 768, false, &misc);

	//    exit(0);
	mWindow->setVisible(true);
#endif
logMsg("Alive?");

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    std::string dataPath = "data";
#else
    std::string dataPath = UBC_DATADIR;
#endif

	mResourceGroup = "UBCData";
	Ogre::ResourceGroupManager *rsm = Ogre::ResourceGroupManager::getSingletonPtr();
	rsm->createResourceGroup(mResourceGroup);
	// load the basic resource location(s)
	rsm->addResourceLocation(dataPath + "/Media", "FileSystem", mResourceGroup);
	rsm->addResourceLocation(dataPath + "/Media/fonts", "FileSystem", mResourceGroup);
	rsm->addResourceLocation(dataPath + "/Media/gui", "FileSystem", mResourceGroup);
	rsm->addResourceLocation(dataPath + "/Media/MyGUI_Media", "FileSystem", mResourceGroup);
	rsm->addResourceLocation(dataPath + "/Media/models", "FileSystem", mResourceGroup);
	rsm->addResourceLocation(dataPath + "/Media/materials/textures", "FileSystem", mResourceGroup);
	rsm->addResourceLocation(dataPath + "/Media/materials/programs", "FileSystem", mResourceGroup);
	rsm->addResourceLocation(dataPath + "/Media/materialss/scripts", "FileSystem", mResourceGroup);
	rsm->addResourceLocation(dataPath + "/Media/materials", "FileSystem", mResourceGroup);
	rsm->addResourceLocation(dataPath + "/Media/overlays", "FileSystem", mResourceGroup);
	rsm->addResourceLocation(dataPath + "/Media/packs", "FileSystem", mResourceGroup);
	rsm->addResourceLocation(dataPath + "/Media/skins", "FileSystem", mResourceGroup);
	rsm->addResourceLocation(dataPath + "/Media/skins/qgui", "FileSystem", mResourceGroup);
	rsm->addResourceLocation(dataPath + "/Media/Audio", "FileSystem", mResourceGroup);

	rsm->initialiseResourceGroup(mResourceGroup);

	mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC); // for OGRE 1.2 Dagon
	mCamera = mSceneMgr->createCamera("camera");

/*
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	mCamera->setNearClipDistance(1.0f);
	mCamera->setFarClipDistance(100000.0f);
	mCamera->setPosition(0, 0, 20.0f);
	mCamera->lookAt(0, 0, 0);
	mCamera->setAutoAspectRatio(true);
#endif
*/

	// Position it at 500 in Z direction
	mCamera->setPosition(Ogre::Vector3(0, 0, 455));
	// Look back along -Z
	mCamera->lookAt(Ogre::Vector3(0, 0, -300));

	mCamera->setNearClipDistance(5);

	viewPort = mWindow->addViewport(mCamera);
	viewPort->setBackgroundColour(Ogre::ColourValue(0, 0, 0));
	viewPort->setOverlaysEnabled(true);	// sets overlays true so that MyGUI can render

	// most examples get the viewport size to calculate this; for now, we'll just
	// set it to 4:3 the easy way

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	viewPort->setMaterialScheme(Ogre::RTShader::ShaderGenerator::DEFAULT_SCHEME_NAME);
#endif
	mCamera->setAspectRatio((Ogre::Real)1.333333);

    // Set ambient light
    mSceneMgr->setAmbientLight(ColourValue(0.5, 0.5, 0.5));

    // Create a light
    Light* l = mSceneMgr->createLight("MainLight");
    l->setPosition(20,80,56);

	//	    Ogre::LogManager::getSingletonPtr()->logMessage("winHandle = " +winHandle);

	// this next bit is for the sake of the input handler
	//	unsigned long hWnd;
	//		mWindow->getCustomAttribute("WINDOW", &winHandle);
/*
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	Ogre::Entity* pEntity = mSceneMgr->createEntity("court", "Player.mesh");
	Ogre::SceneNode* pNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("court");
	pNode->attachObject(pEntity);
	pNode->setScale(1.8f, 1.8f, 1.8f);
#endif
*/
//    GUISystem *gui = GUISystem::Instance();
//    gameEngine *gameE = gameEngine::Instance();
//    teams *team = teams::Instance();
//    players *player = players::Instance();
//    basketballs *basketball = basketballs::Instance();
//    renderEngine *render = renderEngine::Instance();


    // basketball
//    bballInstance[0].setNode(render->getMSceneMgr()->getRootSceneNode()->createChildSceneNode("bball"));

    // Player
//    for (int x = 0; x < 10; ++x)
//    {
//        SceneNode *playerNode = player->getNode(x);
//        playerNode = render->getMSceneMgr()->getRootSceneNode()->createChildSceneNode();
//        player->setNode(x, playerNode);
    //		playerNode[x]->pitch ( Degree (-90));
//    }
//	mSceneMgr->setWorldGeometry( "terrain.cfg" );

    // Set up GUI system
//    gui->setupGUI();

    // loads the Main Menu GUI
//    gui->loadMainMenu();

    // sets up the event handlers for main menu buttons
//    gui->setupMainMenuEventHandlers();

//    setMenuActive(true);

//    startGame();
//	setGameStarted(true);
//	bballInstance[0].setDribbling(true);

/*	vector<players::playerData> playerN = player->getPlayer();
//		exit(0);

	cout << "size = " << playerN.size() << endl;
	for (int i = 0; i < playerN.size(); i++)
	{
		cout << "FIRST name = " << playerN[i].getPlayerFirstName() << endl;
	}
*/
//	load->loadPlayerFile(
//	exit(0);
  //  gameE->startGame();
return (true);
}
