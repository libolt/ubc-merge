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

#include "OgrePrerequisites.h"
#include "gameengine.h"
#include "gamestate.h"
#include "ubcapp.h"



gameObjects::gameObjects()
{
}

gameObjects::~ gameObjects()
{
}


UBC::UBC()
{
	quitGame = false;
}

UBC::~UBC()
{

}

bool UBC::getQuitGame()
{
	return (quitGame);
}

void UBC::setQuitGame(bool quit)
{
    quitGame = quit;
}
// main

int main(int argc, char *argv[])
{

    renderEngine * render = renderEngine::Instance();
    gameEngine *gameE = gameEngine::Instance();
//    gameState *gameS = gameState::Instance();
    GUISystem *gui = GUISystem::Instance();
//    networkEngine *network = networkEngine::Instance();
//    players *player = players::Instance();


    render->initSDL(); // Initializes the SDL Subsystem
    render->initOgre(); // Initializes the Ogre Subsystem
//    render->createScene(); // creates rendering scene.
    gui->initMyGUI(); // Initializes MyGUI
    gui->createMainMenuButtons(); // creates a MyGUI button.

    inputSystem *input = inputSystem::Instance();


    gameE->gameLoop();

  /*
  Ogre::String winHandle;
    #if defined(WIN32) && !defined(__linux__)
		HWND hWnd;
//        hWnd = sysInfo.info.win.window;
		winHandle = Ogre::StringConverter::toString((unsigned long)sysInfo.info.win.window);
		#elif defined(__linux__) && !defined(WIN32)
        winHandle = Ogre::StringConverter::toString((unsigned long)sysInfo.info.x11.window);
	#else
    // Error, both can't be defined or undefined same time
    #endif

    Ogre::Root *mRoot;
    Ogre::Camera *mCamera;
    Ogre::SceneManager *mSceneMgr;
    Ogre::RenderWindow *mWindow;

    Ogre::NameValuePairList misc;

    mRoot = new Ogre::Root("", "", "Ogre.log");
    const Ogre::String pluginDir = OGRE_PLUGIN_DIR;
    inputSystem *input = inputSystem::Instance();

    #if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    const Ogre::String buildType = BUILD_TYPE;

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
 	}

	//we found it, we might as well use it!
 	mRoot->setRenderSystem(selectedRenderSystem);
	selectedRenderSystem->setConfigOption("Full Screen","False");
	selectedRenderSystem->setConfigOption("Video Mode","1024 x 768 @ 32-bit colour");
//	mWindow = mRoot->initialise(true, "Ultimate Basketball Challenge");
	mWindow = mRoot->initialise(false, "");

    std::string dataPath = UBC_DATADIR;

    Ogre::String mResourceGroup;  // stores resource locations
//    QuickGUI::registerScriptParser();
    Ogre::ResourceGroupManager *rsm = Ogre::ResourceGroupManager::getSingletonPtr();
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


    misc["parentWindowHandle"] = winHandle; //

    mWindow = mRoot->createRenderWindow("MainRenderWindow", 1024, 768, false, &misc);
    mWindow->setVisible( true );

	mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC); // for OGRE 1.2 Dagon

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
//	unsigned long hWnd;
	mWindow->getCustomAttribute("WINDOW", &winHandle);

    SDL_Event event;
    bool done;
    float lastFPS = 0.0f;
    float changeInTime;
    int newTime;
    unsigned long oldTime = 0;
    Ogre::Timer loopTime;
    loopTime.reset();

    // models
    Ogre::SceneNode *playerNode;
    Ogre::Entity *playerModel;
    playerNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("Player");
    playerModel = mSceneMgr->createEntity("Player", "Player.mesh");

    // attaches the model to the playerNode
    playerNode->attachObject(playerModel);
    // sets the size of playerNode
//    playerNode->setScale(0.28f,0.28f,0.28f);
    // sets the direction of playerNode
//    playerNode->yaw ( Degree (-270));


    while (!done)
    {

        lastFPS = mWindow->getLastFPS();
        Ogre::String currFPS = Ogre::StringConverter::toString(lastFPS);
    //    cout << "FPS = " << currFPS << endl;

//        unsigned long oldTime = gameE->getOldTime();
        newTime = loopTime.getMilliseconds();   // gets the elapsed time since the last reset of the timer
        changeInTime = newTime - oldTime;

        Ogre::LogManager::getSingletonPtr()->logMessage("FPS = " +currFPS);

        if (input->processInput())
            {
        		Ogre::String keyPressed = input->getKeyPressed();
        		if (keyPressed == "q")
        		{
        	        done = true;
        		}
        	}
		mRoot->renderOneFrame();
//		std::cout << "done = " << done << std::endl;
    }
*/
    	atexit(SDL_Quit);

}



/*UBC* UBC::pInstance = 0;
UBC* UBC::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new UBC; // create sole instance
    }
    return pInstance; // address of sole instance
}


//-------------------------------------------------------------------------------------
UBC::UBC()
//    : player[0](0),
 // playerNode[0](0)
{
    for (int it = 0; it < 10; it++)
    {
        playerDirection[it] = 0;
        oldPlayerDirection[it] = 0;
    }

    x = 0;
    y = 0;
    i = 0;
    j = 0;
    loopTime.reset();
    oldTime = 0;

    menuActive = false;
    quitGame = false;
}
//-------------------------------------------------------------------------------------
UBC::~UBC()
{
}

// gets and sets menuActive
bool UBC::getMenuActive()
{
    return(menuActive);
}
void UBC::setMenuActive(bool active)
{
    menuActive = active;
}
*/

/*void UBC::loads(string pFilename)
{
    TiXmlDocument doc(pFilename);
    if (!doc.LoadFile()) return;

    TiXmlHandle hDoc(&doc);
    TiXmlElement* pElem;
    TiXmlHandle hRoot(0);
    cout << "dee" << endl;
    string m_name, m_messages, WindowSettings;
    // block: name
    {
        pElem=hDoc.FirstChildElement().Element();
        // should always have a valid root but handle gracefully if it does
        if (!pElem) return;
        m_name=pElem->Value();
        cout << m_name << endl;
        //		exit(0);
        // save this for later
        hRoot=TiXmlHandle(pElem);
    }

    pElem=hRoot.FirstChild("PlayerFile").Element();
    {
        string pKey=pElem->Value();
        cout << pKey << endl;
        string pText=pElem->GetText();
        cout << pText << endl;
//        exit(0);
//        m_connection.ip=pElem->Attribute("ip");
//        pElem->QueryDoubleAttribute("timeout",&m_connection.timeout);
	}

//      TiXmlElement* child2;
//      child2 =pElem->NextSiblingElement( "PlayerFile" );
//      do
//      {
//              pElem=hRoot.FirstChild("PlayerFile").Element();
//              child2->ToElement();        basketballs *basketball = basketballs::Instance();

    for( pElem; pElem; pElem=pElem->NextSiblingElement())
    {
        string pKey=pElem->Value();
        cout << pKey << endl;
        string pText=pElem->GetText();
        cout << pText << endl;
//        exit(0);
//        m_connection.ip=pElem->Attribute("ip");
//        pElem->QueryDoubleAttribute("timeout",&m_connection.timeout);
    }

//      } while (1);

}
*/
//-------------------------------------------------------------------------------------
/*
bool UBC::frameStarted()
{

    GUISystem *gui = GUISystem::Instance();
    gameState *gameS = gameState::Instance();
    inputSystem *input = inputSystem::Instance();
    players *player = players::Instance();
    renderEngine * render = renderEngine::Instance();

    float lastFPS = render->getMWindow()->getLastFPS();
    String currFPS = StringConverter::toString(lastFPS);
//    cout << "FPS = " << currFPS << endl;

    int newTime = loopTime.getMilliseconds();   // gets the elapsed time since the last reset of the timer
    float changeInTime = newTime - oldTime;

    LogManager::getSingletonPtr()->logMessage("FPS = " +currFPS);

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

        gameState *gameS = gameState::Instance();setTipOffComplete(true);
        gameState *gameS = gameState::Instance();setGameStarted(true);
        // checks to see if a game has been started
        if (gameState *gameS = gameState::Instance();getGameStarted() && gameState *gameS = gameState::Instance();getTipOffComplete())
        {
            gameState *gameS = gameState::Instance();logic();    // executes the game logic
        //    player->mAnimationState2->addTime(changeInTime);
        }
        else
        {
            gameState *gameS = gameState::Instance();executeTipOff();	// executes the game Tip Off
        }


        oldTime = newTime;

    }

        if (input->processInput() == false)
        {
            quitGame = true;
        }

//	std::cout << "Loop Time = " << loopTime.getMilliseconds() << std::endl;

//    return OgreApplication::frameStarted(evt);
    return true;
}

bool UBC::frameEnded()
{
//	mWindow->update();
//	mRoot->renderOneFrame();

    return true;
}

void UBC::createSceneManager()
{
    renderEngine *render = renderEngine::Instance();

    // Create the SceneManager, in this case a generic one
    render->setMSceneMgr(render->getMRoot()->createSceneManager(ST_EXTERIOR_CLOSE));

}
*/
/*
void UBC::createScene()
{
    GUISystem *gui = GUISystem::Instance();
    teams *team = teams::Instance();
    players *player = players::Instance();
//    basketballs *basketball = basketballs::Instance();
    renderEngine *render = renderEngine::Instance();


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
*/
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
//    startGame();

//}
/*
bool UBC::startGame()
{
    gameState *gameS = gameState::Instance();

    gameState *gameS = gameState::Instance();setupState();

    return true;
}


void UBC::quit()
{
    using namespace OIS;
    inputSystem *input = inputSystem::Instance();
    input->destroy();

}
*/
//-------------------------------------------------------------------------------------

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include "windows.h"
#endif

//#ifdef __cplusplus
//extern "C" {
//#endif

/* SDL Conversion in progress
 *
 *
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
int main(int argc, char *argv[])
#endif
{
   // Create application object
 //   UBC *ubc = UBC::Instance();
    gameEngine *gameE = gameEngine::Instance();
    inputSystem *input = inputSystem::Instance();
    renderEngine *render = renderEngine::Instance();
    GUISystem *gui = GUISystem::Instance();
//    SoundSystem *sound = SoundSystem::Instance();
//    gui->setupGUI();

    render->createScene();
//    ubc->startGame();

    while (!gameE->getQuitGame())
    {
//        ubc->processUnbufferedKeyInput();

        render->frameStarted();
		// run the message pump (Eihort)
		Ogre::WindowEventUtilities::messagePump();

		render->getMRoot()->renderOneFrame();

    }

    input->destroy();

   return 0;
}


#ifdef __cplusplus
}
#endif
*/
