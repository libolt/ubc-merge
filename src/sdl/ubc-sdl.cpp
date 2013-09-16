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

#include "ubc-sdl.h"

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
    gameState *gameS = gameState::Instance();
   GUISystem *gui = GUISystem::Instance();
    networkEngine *network = networkEngine::Instance();
    players *player = players::Instance();

    float lastFPS = 0.0f;
    float changeInTime;
    int newTime;
    unsigned long oldTime = 0;
    Ogre::Timer loopTime;
    loopTime.reset();


/*	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0) {
        fprintf(stderr,
                "\nUnable to initialize SDL:  %s\n",
                SDL_GetError()
               );
        return 1;
    }


	SDL_Window *sdlWindow = SDL_CreateWindow("MainRenderWindow",
	                             SDL_WINDOWPOS_UNDEFINED,
	                             SDL_WINDOWPOS_UNDEFINED,
	                             1024,768, 0);

    SDL_SysWMinfo sysInfo;
    SDL_VERSION( &sysInfo.version );

    SDLTest_CommonState *state;

    if (SDL_GetWindowWMInfo(sdlWindow, &sysInfo) <= 0)
    {
    	assert( false );
    }

    int x = 0;
*/
    render->initSDL(); // Initializes the SDL Subsystem
    render->initOgre(); // Initializes the Ogre Subsystem
//    render->createScene(); // creates rendering scene.
    gui->initMyGUI(); // Initializes MyGUI
    gui->createMainMenuButtons(); // creates a MyGUI button.

    inputSystem *input = inputSystem::Instance();

    while (!gameE->getQuitGame())
    {
//        ubc->processUnbufferedKeyInput();

//        render->frameStarted();
		// run the message pump (Eihort)
//		Ogre::WindowEventUtilities::messagePump();

/*    	if (network->getServerReceivedConnection() || network->getClientEstablishedConnection())	// checks if server and client are connected
    	{
    		gameE->setCreateScene(true);
    	}
*/
    	if (gameE->getCreateScene())
    	{
    		render->createScene();
    		gameE->setCreateScene(false);
    		gameE->setRenderScene(true);
    	}
        lastFPS = render->getMWindow()->getLastFPS();
        Ogre::String currFPS = Ogre::StringConverter::toString(lastFPS);

//        unsigned long oldTime = gameE->getOldTime();
        newTime = loopTime.getMilliseconds();   // gets the elapsed time since the last reset of the timer
        changeInTime = newTime - oldTime;
        if (changeInTime >= 100)
        {
        	if (gameE->getServerRunning())
        	{
        		network->networkServer();	// Runs network server code
        	}
        	if (gameE->getClientRunning())
        	{
        		network->networkClient();	// runs network client code
        	}
//            Ogre::LogManager::getSingletonPtr()->logMessage("changeInTime = " +Ogre::StringConverter::toString(changeInTime));
           	if (gameE->getRenderScene())
            {
           		gameS->logic();
           	}

        	oldTime = newTime;

        }

        //        Ogre::LogManager::getSingletonPtr()->logMessage("FPS = " +currFPS);

    	if (input->processInput())
        {
			std::vector<playerState> playerInstance = gameS->getPlayerInstance();

			if (gameE->getClientRunning())	// checks if game is running in client mode
			{
				Ogre::String keyPressed = input->getKeyPressed();
				if (keyPressed == "q")
				{
					gameE->setQuitGame(true);
				}
				else if (keyPressed == "up")
				{
					Ogre::String packetData;
					playerInstance[6].setMovement(true);
					playerInstance[6].setDirection(UP);
					gameS->setPlayerInstance(playerInstance);
					packetData = "player6" + keyPressed;
					network->sendPacket(packetData);
				}
				else if (keyPressed == "down")
				{
					Ogre::String packetData;
					playerInstance[6].setMovement(true);
					playerInstance[6].setDirection(DOWN);
					gameS->setPlayerInstance(playerInstance);
					packetData = "player6" + keyPressed;
					network->sendPacket(packetData);
				}
				else if (keyPressed == "left")
				{
					Ogre::String packetData;
					playerInstance[6].setMovement(true);
					playerInstance[6].setDirection(LEFT);
					gameS->setPlayerInstance(playerInstance);
					packetData = "player6" + keyPressed;
					network->sendPacket(packetData);
				}
				else if (keyPressed == "right")
				{
					Ogre::String packetData;
					playerInstance[6].setMovement(true);
					playerInstance[6].setDirection(RIGHT);
					gameS->setPlayerInstance(playerInstance);
					packetData = "player6" + keyPressed;
					network->sendPacket(packetData);
				}
				else
				{

				}
    		}
			else if (gameE->getServerRunning())	// checks if game is running in server mode
			{
				Ogre::String keyPressed = input->getKeyPressed();
				if (keyPressed == "q")
				{
					gameE->setQuitGame(true);
				}
				else if (keyPressed == "up")
				{
					Ogre::String packetData;
					playerInstance[0].setMovement(true);
					playerInstance[0].setDirection(UP);
					gameS->setPlayerInstance(playerInstance);
					packetData = "player0" + keyPressed;
					network->sendPacket(packetData);
				}
				else if (keyPressed == "down")
				{
					Ogre::String packetData;
					playerInstance[0].setMovement(true);
					playerInstance[0].setDirection(DOWN);
					gameS->setPlayerInstance(playerInstance);
					packetData = "player0" + keyPressed;
					network->sendPacket(packetData);
				}
				else if (keyPressed == "left")
				{
					Ogre::String packetData;
					playerInstance[0].setMovement(true);
					playerInstance[0].setDirection(LEFT);
					gameS->setPlayerInstance(playerInstance);
					packetData = "player0" + keyPressed;
					network->sendPacket(packetData);
				}
				else if (keyPressed == "right")
				{
					Ogre::String packetData;
					playerInstance[0].setMovement(true);
					playerInstance[0].setDirection(RIGHT);
					gameS->setPlayerInstance(playerInstance);
					packetData = "player0" + keyPressed;
					network->sendPacket(packetData);
				}
				else
				{

				}
    		}

        }

 			//        player->getNode(0)->translate(Pos);
//        pInstance[bballInstance[0].getPlayer()].getNode()->translate(-0.02f,0.0f,0.0f);
		render->getMRoot()->renderOneFrame();

    }



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
