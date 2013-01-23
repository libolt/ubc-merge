#include "rendersystems.h"
#include "gui.h"
#include "config.h"
#include "sound.h"

#ifndef OGRE_PLUGIN_DIR
#define OGRE_PLUGIN_DIR
#endif

renderSystems* renderSystems::pInstance = 0;
renderSystems* renderSystems::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new renderSystems; // create sole instance
    }
    return pInstance; // address of sole instance
}


renderSystems::renderSystems()
{
//    GUISystem *gui = GUISystem::Instance();
	    SoundSystem *sound = SoundSystem::Instance();

    mRoot = new Ogre::Root("", "", "Ogre.log");

    const String pluginDir = OGRE_PLUGIN_DIR;

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
//	Ogre::RenderSystemList *renderSystems = NULL;
//	Ogre::RenderSystemList::iterator r_it;
//	renderSystems = mRoot->getAvailableRenderers();
//	RenderSystemList *rsList = mRoot->getAvailableRenderers()->begin();
 //   RenderSystemList *rsList = mRoot->getAvailableRenderers().begin();
    RenderSystemList rsList = mRoot->getAvailableRenderers();

/*	r_it = renderSystems->begin();
    	mRoot->setRenderSystem(*r_it);
	mWindow = mRoot->initialise(false);
//	exit(0);
*/
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
	mWindow = mRoot->initialise(true, "Ultimate Basketball Challenge");

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
/*
//        mRoot->initialise(false);

	// since this is basically a CEGUI app, we can use the ST_GENERIC scene manager for now; in a later article
	// we'll see how to change this
	mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC);
*/


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
	unsigned long hWnd;
	mWindow->getCustomAttribute("WINDOW", &hWnd);

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


}

renderSystems::~renderSystems()
{
}

Root *renderSystems::getMRoot()
{
    return (mRoot);
}
void renderSystems::setMRoot(Root *root)
{
    mRoot = root;
}

Camera *renderSystems::getMCamera()
{
    return (mCamera);
}
void renderSystems::setMCamera(Camera *camera)
{
    mCamera = camera;
}

SceneManager *renderSystems::getMSceneMgr()
{
    return (mSceneMgr);
}
void renderSystems::setMSceneMgr(SceneManager *sceneMgr)
{
    mSceneMgr = sceneMgr;
}

RenderWindow *renderSystems::getMWindow()
{
    return (mWindow);
}
void renderSystems::setMWindow(RenderWindow *window)
{
    mWindow = window;
}

Vector3 renderSystems::getMTranslateVector()
{
    return (mTranslateVector);
}
void renderSystems::setMTranslateVector(Vector3 vector)
{
    mTranslateVector = vector;
}

Radian renderSystems::getMRotX()
{
    return (mRotX);
}
void renderSystems::setMRotX(Radian rotX)
{
    mRotX = rotX;
}

Radian renderSystems::getMRotY()
{
    return (mRotY);
}
void renderSystems::setMRotY(Radian rotY)
{
    mRotY = rotY;
}

Real renderSystems::getMMoveSpeed()
{
    return (mMoveSpeed);
}
void renderSystems::setMMoveSpeed(Real speed)
{
    mMoveSpeed = speed;
}

Degree renderSystems::getMRotateSpeed()
{
    return (mRotateSpeed);
}
void renderSystems::setMRotateSpeed(Degree speed)
{
    mRotateSpeed = speed;
}

float renderSystems::getMMoveScale()
{
    return (mMoveScale);
}
void renderSystems::setMMoveScale(float scale)
{
    mMoveScale = scale;
}

Degree renderSystems::getMRotScale()
{
    return (mRotScale);
}
void renderSystems::setMRotScale(Degree scale)
{
    mRotScale = scale;
}

String renderSystems::getMResourceGroup()
{
    return (mResourceGroup);
}

void renderSystems::setMResourceGroup(String resource)
{
    mResourceGroup = resource;
}
