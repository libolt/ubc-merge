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

#include "config.h"

#include "gameengine.h"
#include "gamestate.h"
#include "gui.h"
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
#endif
}

renderEngine::~renderEngine()
{
}

bool renderEngine::initSDL() // Initializes SDL Subsystem
{
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0) {
        fprintf(stderr,
                "\nUnable to initialize SDL:  %s\n",
                SDL_GetError()
               );
        return 1;
    }


	sdlWindow = SDL_CreateWindow("Ultimate Basketball Challenge",
	                             SDL_WINDOWPOS_UNDEFINED,
	                             SDL_WINDOWPOS_UNDEFINED,
	                             1024,768, 0);


    SDL_VERSION( &sysInfo.version );


    if (SDL_GetWindowWMInfo(sdlWindow, &sysInfo) <= 0)
    {
    	assert( false );
    }

	return true;
}

bool renderEngine::initOgre() // Initializes Ogre Subsystem
{
	//    GUISystem *gui = GUISystem::Instance();
	//    SoundSystem *sound = SoundSystem::Instance();

    #if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
		      winHandle = Ogre::StringConverter::toString((unsigned long int)sysInfo.info.win.window);
	   #elif OGRE_PLATFORM == OGRE_PLATFORM_LINUX
		      winHandle = Ogre::StringConverter::toString((unsigned long)sysInfo.info.x11.window);
	   #elif OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	       winHandle =  Ogre::StringConverter::toString((int)app->window);
	   #else
	    // Error, both can't be defined or undefined same time
	   #endif

std::cout << "winHandle = " << winHandle << std::endl;
	    mRoot = new Ogre::Root("", "", "Ogre.log");
	    const Ogre::String pluginDir = OGRE_PLUGIN_DIR;
	    inputSystem *input = inputSystem::Instance();

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

		int c=0;
		bool foundit = false;
		Ogre::RenderSystem *selectedRenderSystem=0;
		while(c < (int) rsList.size())
		{
			selectedRenderSystem = rsList.at(c);
	   		Ogre::String rname = selectedRenderSystem->getName();
	   		if(rname.compare("OpenGL Rendering Subsystem")==0)
			{
	     			foundit=true;
	     			break;
	   		}
	   		c++; // <-- oh how clever
	   		std::cout << c++ << std::endl;
		}

		//we found it, we might as well use it!
	 	mRoot->setRenderSystem(selectedRenderSystem);
/*		selectedRenderSystem->setConfigOption("Full Screen","False");
		selectedRenderSystem->setConfigOption("Video Mode","1024 x 768 @ 32-bit colour");
*/
		//	mWindow = mRoot->initialise(true, "Ultimate Basketball Challenge");
		mWindow = mRoot->initialise(false, "Ultimate Basketball Challenge");
#endif


	    std::string dataPath = UBC_DATADIR;

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

   //Ogre::LogManager::getSingletonPtr()->logMessage("Rendering!");
 	  misc["externalWindowHandle"] = winHandle; //

   #if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
   config = AConfiguration_new();
//  AConfiguration_fromAssetManager(config, app->activity->assetManager);
   //gAssetMgr = app->activity->assetManager;
		 misc["androidConfig"] = Ogre::StringConverter::toString((int)config);


   mWindow = mRoot->createRenderWindow("UBC", 0, 0, false, &misc);
   #else
	  mWindow = mRoot->createRenderWindow("Ultimate Basketball Challenge", 1024, 768, false, &misc);
	  #endif

	  mWindow->setVisible( true );

 		 mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC); // for OGRE 1.2 Dagon
	    mCamera = mSceneMgr->createCamera("camera");
	    // Position it at 500 in Z direction
	    mCamera->setPosition(Ogre::Vector3(0,0,455));
	    // Look back along -Z
	    mCamera->lookAt(Ogre::Vector3(0,0,-300));

		mCamera->setNearClipDistance(5);
	    viewPort = mWindow->addViewport(mCamera);
	    viewPort->setBackgroundColour(Ogre::ColourValue(0,0,0));
	    viewPort->setOverlaysEnabled(true);	// sets overlays true so that MyGUI can render
		// most examples get the viewport size to calculate this; for now, we'll just
		// set it to 4:3 the easy way
		mCamera->setAspectRatio((Ogre::Real)1.333333);
<<<<<<< HEAD
=======

>>>>>>> acca668115c0ea8dbf8408d98b6d75f625cd0bab

//	    Ogre::LogManager::getSingletonPtr()->logMessage("winHandle = " +winHandle);

		// this next bit is for the sake of the input handler
	//	unsigned long hWnd;
//		mWindow->getCustomAttribute("WINDOW", &winHandle);


/* Old Initialization code
		mRoot = new Ogre::Root("", "", "Ogre.log");

	    const String pluginDir = OGRE_PLUGIN_DIR;

	//    string pluginDir;
	//    const char pluginDir = OGRE_PLUGIN_DIR;

	    #if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	    const String buildType = BUILD_TYPE;

	    if (buildType == "Debug")
	    {
	        mRoot->loadPlugin(pluginDir + "/RenderSystem_Direct3D9_d");
	        mRoot->loadPlugin(pluginDir + "/Plugin_CgProgramManager_d");
	    }
	    else
	    {
	        mRoot->loadPlugin(pluginDir + "/RenderSystem_Direct3D9");
	        mRoot->loadPlugin(pluginDir + "/Plugin_CgProgramManager");
	    }
	    #elif OGRE_PLATFORM == OGRE_PLATFORM_APPLE
	    mRoot->loadPlugin("RenderSystem_GL");
	    #else
	    mRoot->loadPlugin(pluginDir + "/RenderSystem_GL");
	    mRoot->loadPlugin(pluginDir + "/Plugin_CgProgramManager");
	    #endif
	//	Ogre::RenderSystemList *renderEngine = NULL;
	//	Ogre::RenderSystemList::iterator r_it;
	//	renderEngine = mRoot->getAvailableRenderers();
	//	RenderSystemList *rsList = mRoot->getAvailableRenderers()->begin();
	 //   RenderSystemList *rsList = mRoot->getAvailableRenderers().begin();
	    RenderSystemList rsList = mRoot->getAvailableRenderers();

//		r_it = renderEngine->begin();
//	    	mRoot->setRenderSystem(*r_it);
//		mWindow = mRoot->initialise(false);
	//	exit(0);

		int c=0;
		bool foundit = false;
		RenderSystem *selectedRenderSystem=0;
		while(c < (int) rsList.size())
		{
			selectedRenderSystem = rsList.at(c);
	   		String rname = selectedRenderSystem->getName();
	   		if(rname.compare("OpenGL Rendering Subsystem")==0)
			{
	     			foundit=true;
	     			break;
	   		}
	   		c++; // <-- oh how clever
	 	}
	// 	if(!foundit) exit(1); //we didn't find it...

	 	//we found it, we might as well use it!
	 	mRoot->setRenderSystem(selectedRenderSystem);
	//    mRoot->initialise()
		selectedRenderSystem->setConfigOption("Full Screen","False");
		selectedRenderSystem->setConfigOption("Video Mode","1280 x 1024 @ 32-bit colour");
		mWindow = mRoot->initialise(false, "Ultimate Basketball Challenge");

	    std::string dataPath = UBC_DATADIR;


	//    QuickGUI::registerScriptParser();
	    ResourceGroupManager *rsm = ResourceGroupManager::getSingletonPtr();
	    rsm->createResourceGroup(mResourceGroup);
		// load the basic resource location(s)
		rsm->addResourceLocation(dataPath + "/Media", "FileSystem", mResourceGroup);
		rsm->addResourceLocation(dataPath + "/Media/fonts", "FileSystem", mResourceGroup);
		rsm->addResourceLocation(dataPath + "/Media/gui", "FileSystem", mResourceGroup);
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
		// setup main window; hardcode some defaults for the sake of presentation
		Ogre::NameValuePairList opts;
		opts["resolution"] = "1280x720";
		opts["fullscreen"] = "false";
		opts["vsync"] = "false";
		// create a rendering window with the title "Ultimate Basketball Challenge"
	//	mWindow = mRoot->createRenderWindow("Ultimate Basketball Challenge", 800, 600, false, &opts);

	//        mRoot->initialise(false);

		// since this is basically a CEGUI app, we can use the ST_GENERIC scene manager for now; in a later article
		// we'll see how to change this
//		mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC);


		//retrieve the config option map
		ConfigOptionMap comap = selectedRenderSystem->getConfigOptions();

		//and now we need to run through all of it
		ConfigOptionMap::const_iterator start = comap.begin();
		ConfigOptionMap::const_iterator end = comap.end();
		while(start != end)
		{
	   		String OptionName = start->first;
	   		String CurrentValue = start->second.currentValue;
	   		StringVector PossibleValues = start->second.possibleValues;
	   		int c=0;
	   		while (c < (int) PossibleValues.size())
	   		{
	     			String OneValue = PossibleValues.at(c);
	     			c++;
	   		}
			start++;
		}

	    misc["parentWindowHandle"] = winHandle; //

	    mWindow = mRoot->createRenderWindow("MainRenderWindow", 1024, 768, false, &misc);
	    mWindow->setVisible( true );

	//	RenderWindow* mWindow;
	//    mWindow = mRoot->createRenderWindow("Ultimate Basketball Challenge", 1280, 720, false, &opts);

	//	SceneManager* mSceneMgr;
	// mSceneMgr = mRoot->getSceneManager(ST_GENERIC);
		mSceneMgr = mRoot->createSceneManager(ST_GENERIC); // for OGRE 1.2 Dagon

	    mCamera = mSceneMgr->createCamera("camera");
	    // Position it at 500 in Z direction
	    mCamera->setPosition(Ogre::Vector3(0,0,450));
	    // Look back along -Z
	    mCamera->lookAt(Ogre::Vector3(0,0,-300));

		mCamera->setNearClipDistance(5);
	    Ogre::Viewport *vp = mWindow->addViewport(mCamera);
	    vp->setBackgroundColour(Ogre::ColourValue(0,0,0));

		// most examples get the viewport size to calculate this; for now, we'll just
		// set it to 4:3 the easy way
		mCamera->setAspectRatio((Ogre::Real)1.333333);

		// this next bit is for the sake of the input handler
//		unsigned long hWnd;
		mWindow->getCustomAttribute("WINDOW", &winHandle);

	//// FIX SOUND SYSTEM
	//    sound->setup();
	//    OgreAL::SoundManager *soundMgr;
	//    OgreAL::Sound *snd;
	//    soundMgr = OgreAL::SoundManager::getSingletonPtr();
	//    snd = OgreAL::SoundManager::getSingletonPtr()->createSound("dead", "roar.wav", false);
	//    snd = soundMgr->createSound("dead", "roar.wav", false);
	//    soundMgr = new OgreAL::SoundManager();
	//    GUISystem *gui = GUISystem::Instance();
	//    GUISystem *gui = new GUISystem;
	//    ubc->getMSceneMgr()->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
	//	Ogre::Light* l = ubc->getMSceneMgr()->createLight("MainLight");
	//	l->setPosition(20,80,56);

	 */
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

bool renderEngine::frameStarted()
{

    GUISystem *gui = GUISystem::Instance();
    gameEngine *gameE = gameEngine::Instance();
    gameState *gameS = gameState::Instance(); // FIXME: gameState shouldn't be called in render engine
    inputSystem *input = inputSystem::Instance();
    players *player = players::Instance();
    physicsEngine *physEngine = physicsEngine::Instance();
    renderEngine * render = renderEngine::Instance();

    float lastFPS = render->getMWindow()->getLastFPS();
    String currFPS = StringConverter::toString(lastFPS);
//    cout << "FPS = " << currFPS << endl;

    unsigned long oldTime = gameE->getOldTime();
    int newTime = gameE->loopTime.getMilliseconds();   // gets the elapsed time since the last reset of the timer
    float changeInTime = newTime - oldTime;

    Ogre::LogManager::getSingletonPtr()->logMessage("FPS = " +currFPS);

//    std::cout << "oldTime = " << oldTime << std::endl;
//    std::cout << "newTime = " << newTime << std::endl;
//    std::cout << "change in time = " << (newTime - oldTime) << std::endl;


//    event = new OIS::MouseEvent[1];
//    gui->mouseMoved(*event);
//    const OIS::MouseState &ms = input->getMMouse()->getMouseState();
//    mGUIManager->injectMouseMove( ms.X.rel, ms.Y.rel );
    gui->updateTime(changeInTime);
//    exit(0);
    gui->update();
    Ogre::Real times;
    Ogre::FrameEvent evt;
    times = 0.01f;
//    cout << "time since last frame = " << times << endl;

    if ((newTime - oldTime) >= 70)
    {
        gameS->setTipOffComplete(true);
        gameS->setGameStarted(true);
        // checks to see if a game has been started
        if (gameS->getGameStarted() && gameS->getTipOffComplete())
        {
            gameS->logic();    // executes the game logic
        //    player->mAnimationState2->addTime(changeInTime);
        }
        else
        {
            gameS->executeTipOff();	// executes the game Tip Off
        }


        oldTime = newTime;
        gameE->setOldTime(oldTime);
    }

    if (input->processInput() == false)
    {
        gameE->setQuitGame(true);
    }

    if (changeInTime >= 1000.0/60.0)
    {
    physEngine->updateState(changeInTime);
    }
exit(0);
//	std::cout << "Loop Time = " << loopTime.getMilliseconds() << std::endl;

//    return OgreApplication::frameStarted(evt);
    return true;
}

bool renderEngine::frameEnded()
{
//	mWindow->update();
//	mRoot->renderOneFrame();

    return true;
}

void renderEngine::createSceneManager()
{
    renderEngine *render = renderEngine::Instance();

    // Create the SceneManager, in this case a generic one
    render->setMSceneMgr(render->getMRoot()->createSceneManager(ST_EXTERIOR_CLOSE));

}

bool renderEngine::createScene()
{
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
