/***************************************************************************
 *   Copyright (C) 2014 by Mike McLean   *
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

#include "gameengine.h"
#include "gamestate.h"
#include "gui.h"
#include "input.h"
#include "logging.h"
#include "network.h"
#include "networkplayerstateobject.h"
#include "renderengine.h"
#include "soundengine.h"


gameEngine* gameEngine::pInstance = 0;
gameEngine* gameEngine::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new gameEngine; // create sole instance
    }
    return pInstance; // address of sole instance
}


//-------------------------------------------------------------------------------------
gameEngine::gameEngine()
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
    changeInTime = 0;

    userInputLoaded = false;
    menuActive = false;
    start = false;
    quitGame = false;
    serverRunning = false;
    clientRunning = false;
    sceneCreated = false;
    createScene = false;
    renderScene = false;
    movePlayer = false;
}
//-------------------------------------------------------------------------------------
gameEngine::~gameEngine()
{
}

// gets and sets menuActive
bool gameEngine::getMenuActive()
{
    return(menuActive);
}

void gameEngine::setMenuActive(bool active)
{
    menuActive = active;
}

Ogre::Timer gameEngine::getLoopTime()
{

    return(loopTime);

}

void gameEngine::setLoopTIme(Ogre::Timer time)
{
    loopTime = time;
}

unsigned long gameEngine::getOldTime()
{
    return(oldTime);
}

void gameEngine::setOldTime(unsigned long time)
{
    oldTime = time;
}

unsigned long gameEngine::getChangeInTime()
{
	return (changeInTime);
}

void gameEngine::setChangeInTime(unsigned long change)
{
	changeInTime = change;
}

void gameEngine::updateChangeInTime()
{
    unsigned long newTime = loopTime.getMilliseconds();   // gets the elapsed time since the last reset of the timer

    changeInTime = newTime - oldTime;	// calculates change between new and old time
}

bool gameEngine::getQuitGame()
{
    return(quitGame);
}
void gameEngine::setQuitGame(bool quit)
{
    quitGame = quit;
}

bool gameEngine::getServerRunning()
{
	return (serverRunning);
}

void gameEngine::setServerRunning(bool server)
{
	serverRunning = server;
}

bool gameEngine::getClientRunning()
{
	return (clientRunning);
}

void gameEngine::setClientRunning(bool client)
{
	clientRunning = client;
}

bool gameEngine::getCreateScene()
{
	return (createScene);
}

void gameEngine::setCreateScene(bool scene)
{
	createScene = scene;
}
bool gameEngine::getSceneCreated()
{
	return (sceneCreated);
}

void gameEngine::setSceneCreated(bool created)
{
	sceneCreated = created;
}
bool gameEngine::getRenderScene()
{
	return (renderScene);
}

void gameEngine::setRenderScene(bool scene)
{
	renderScene = scene;
}

bool gameEngine::getMovePlayer()
{
	return (movePlayer);
}

void gameEngine::setMovePlayer(bool player)
{
	movePlayer = player;
}


bool gameEngine::startGame()
{
//    gameState *gameS = gameState::Instance();
    gameState *gameS = gameState::Instance();

//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//    Ogre::LogManager::getSingletonPtr()->logMessage("startGame()");
	logMsg("startGame()");

    gameS->setupState();
//#endif
    return true;
}

void gameEngine::quit()
{
    inputSystem *input = inputSystem::Instance();
    input->destroy();

}

void gameEngine::processInput()  // processes game input
{
    gameState *gameS = gameState::Instance();

    GUISystem *gui = GUISystem::Instance();

    inputSystem *input = inputSystem::Instance();

    networkEngine *network = networkEngine::Instance();
    networkPlayerStateObject netPStateObj;

    logMsg("inputProcess!");
//    players *player = players::Instance();

    
 
    if (input->processInput())
    {
        if (gameS->getTeamInstancesCreated())
        {
            int teamNumber;
            if (serverRunning)
            {
                teamNumber = 0;
            }
            else if (clientRunning)
            {
                teamNumber = 1;
            }
            else
            {
                teamNumber = 1;
            }
            int i = teamNumber;
            std::vector<teamState> teamInstance = gameS->getTeamInstance();
            int humanControlled = teamInstance[i].getHumanControlled();
            logMsg("teamNumber = " +Ogre::StringConverter::toString(teamNumber));
                    
            logMsg("humanControlled = " +Ogre::StringConverter::toString(humanControlled));
            if (teamInstance[i].getPlayerInstancesCreated())
            {
                std::vector<playerState> playerInstance = teamInstance[i].getPlayerInstance();
                if (teamInstance[i].getHumanControlled())
                {
                    int humanPlayer = teamInstance[i].getHumanPlayer();
                    //inputMaps inputMap = input->keyMap();
                    inputWorkQueues inputQueue = input->getInputWorkQueue();
//                              logMsg("INPUT MAP ======== "  +toString(inputMap));
                    std::stringstream ss;
                              //  exit(0);
                    size_t x = 0;
                    logMsg("inputQueue.size = " +Ogre::StringConverter::toString(inputQueue.size()));
                    while (x < inputQueue.size())
                    {
                        logMsg("inputQueue[" +Ogre::StringConverter::toString(x) +"] = " +Ogre::StringConverter::toString(inputQueue[x]));
                        // switch (inputMap)
                        switch (inputQueue[x])
                        {
                            case INUP:
                                playerInstance[humanPlayer].setMovement(true);
                                playerInstance[humanPlayer].setDirection(UP);
                                teamInstance[i].setPlayerInstance(playerInstance);
                                gameS->setTeamInstance(teamInstance);
                            break;
                            case INDOWN:
                                playerInstance[humanPlayer].setMovement(true);
                                playerInstance[humanPlayer].setDirection(DOWN);
                                teamInstance[i].setPlayerInstance(playerInstance);
                                gameS->setTeamInstance(teamInstance);
                            break;
                            case INLEFT:
                                playerInstance[humanPlayer].setMovement(true);
                                playerInstance[humanPlayer].setDirection(LEFT);
                                teamInstance[i].setPlayerInstance(playerInstance);
                                gameS->setTeamInstance(teamInstance);
                            break;
                            case INRIGHT:
                                playerInstance[humanPlayer].setMovement(true);
                                playerInstance[humanPlayer].setDirection(RIGHT);
                                teamInstance[i].setPlayerInstance(playerInstance);
                                gameS->setTeamInstance(teamInstance);
                            break;
                            case INUPLEFT:
                                playerInstance[humanPlayer].setMovement(true);
                                playerInstance[humanPlayer].setDirection(UPLEFT);
                                teamInstance[i].setPlayerInstance(playerInstance);
                                gameS->setTeamInstance(teamInstance);
                            break;
                            case INUPRIGHT:
                                playerInstance[humanPlayer].setMovement(true);
                                playerInstance[humanPlayer].setDirection(UPRIGHT);
                                teamInstance[i].setPlayerInstance(playerInstance);
                                gameS->setTeamInstance(teamInstance);
                            break;
                            case INDOWNLEFT:
                                playerInstance[humanPlayer].setMovement(true);
                                playerInstance[humanPlayer].setDirection(DOWNLEFT);
                                teamInstance[i].setPlayerInstance(playerInstance);
                                gameS->setTeamInstance(teamInstance);
                            break;
                            case INDOWNRIGHT:
                                playerInstance[humanPlayer].setMovement(true);
                                playerInstance[humanPlayer].setDirection(DOWNRIGHT);
                                teamInstance[i].setPlayerInstance(playerInstance);
                                gameS->setTeamInstance(teamInstance);
                            break;
                            case INSHOOTBLOCK:
                                playerInstance[humanPlayer].setMovement(false);
                                playerInstance[humanPlayer].setShootBlock(true);
                                teamInstance[i].setPlayerInstance(playerInstance);
                                gameS->setTeamInstance(teamInstance);
                            break;
                            case INPASSSTEAL:
                                playerInstance[humanPlayer].setMovement(false);
                                playerInstance[humanPlayer].setPassSteal(true);
                                teamInstance[i].setPlayerInstance(playerInstance);
                                gameS->setTeamInstance(teamInstance);
                            break;
                            case INQUIT:
                                logMsg("Quitting!");
                                quitGame = true;
                                exit(0);
                            break;
                            default:
                            break;
                        }
                        ++x;
                    }
                    
                    gameS->setTeamInstance(teamInstance);

                    if (gameS->getGameType() == MULTI)
                    {
                        network->processLocalInput();
                    }
                    inputQueue.clear();
                    input->setInputWorkQueue(inputQueue);
                }
            }
        }
    }   
}

void gameEngine::gameLoop()	// Main Game Loop
{

    renderEngine * render = renderEngine::Instance();

    gameState *gameS = gameState::Instance();

    GUISystem *gui = GUISystem::Instance();

    inputSystem *input = inputSystem::Instance();

    networkEngine *network = networkEngine::Instance();
    networkPlayerStateObject netPStateObj;

    players *player = players::Instance();

    float lastFPS = 0.0f;	// stores value of last Frames Per Second
//    float changeInTime;		// stores change in time
//    int newTime;	// stores new time
//    unsigned long oldTime = 0;	// stores old time
    Ogre::Timer loopTime;	// loop timer
    logMsg("Sound Test!");
    SoundEngine *sound = SoundEngine::Instance();

	logMsg("main: startup");

/*
    threads thread;
    thread.setGRunning(true);

    boost::thread t1(boost::bind(&threads::producerThread,&thread));
    boost::thread t2(boost::bind(&threads::consumerThread,&thread));

    // Let them run for a while

    boost::posix_time::milliseconds workTime(5000);
    boost::this_thread::sleep(workTime);

    // Stop gracefully and wait

    thread.setGRunning(false);
    t1.join();
    t2.join();
*/
//    boost::thread inputThread(boost::bind(&inputSystem::processInput,input));
//    boost::thread t2(boost::bind(&threads::consumerThread,&thread));

    /*    boost::thread *workerThread;
//	workerThread = new boost::thread(boost::bind(&threading::workerFunc,&threads));
    
	boost::thread *workerThread2;
//	workerThread2 = new boost::thread(boost::bind(&threading::workerFunc2,&threads));

    boost::thread *inputWorkerThread;
//    inputWorkerThread = new boost::thread(boost::bind(&threading::inputWorkerFunc,&threads));

    logMsg("main: waiting for thread");

    workerThread->join();
	workerThread2->join();

    logMsg("main: done");
*/

//    threads *thread = threads::Instance();

/*    threads::Reader reads(100);
    threads::Writer writes1(100, 200);
    threads::Writer writes2(200, 200);

    boost::thread readerThread(reads);
    boost::thread writerThread1(writes1);
//    usleep(100);
    boost::this_thread::sleep(boost::posix_time::microseconds(100));

    boost::thread writerThread2(writes2);

    readerThread.join();
    writerThread1.join();
    writerThread2.join();
*/

//	SDL_StartTextInput();
    while (!quitGame)
	{
			//SDL_SetWindowGrab(render->getSDLWindow(), SDL_TRUE);
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//			std::vector<playerState> playerInstance = gameS->getPlayerInstance();	// stores th player instances

	//        ubc->processUnbufferedKeyInput();

	//        render->frameStarted();
			// run the message pump (Eihort)
	//		Ogre::WindowEventUtilities::messagePump();
//		   exit(0);

/*        if (!sound->getSetupComplete())
        {
            logMsg("Sound setup not complete!");
            if (sound->setup())
            {
                logMsg("Sound setup!");
                sound->setSetupComplete(true);
            }
        }
        else
        {
            logMsg("Loading Sound!");
            sound->loadSound("cbeep.wav");
        }
*/
        if (gameS->getGameSetupComplete())   // checks to make sure game setup is complete before continuing
	    {
            if (!sceneCreated)
            {
                if (gameS->getGameType() == SINGLE)
                {
                    createScene = true;
                }
                else if (gameS->getGameType() == MULTI)
                {
                    if (network->getServerReceivedConnection() || network->getClientEstablishedConnection())    // checks if server and client are connected
                    {
                        createScene = true;
                    }
    //			   exit(0);
                }
            }
        }
        
        if (createScene)	// checks if the scene should be created
        {
//	    		if (render->createScene())
            {
                createScene = false;
                start = true;
//	    			renderScene = true;
                sceneCreated = true;
            }
        }

        if (start)	// checks if it's time to start the game
        {
            if (startGame())
            {
                start = false;
                renderScene = true;
            }
        }
//#else
        lastFPS = render->getMWindow()->getLastFPS();
        Ogre::String currFPS = Ogre::StringConverter::toString(lastFPS);

        logMsg("FPS = " +currFPS);
        updateChangeInTime();	// calculates the change in time.

//	        logMsg("changeInTime = " +toString(changeInTime));
        // updates game logic every 100 milliseconds
        if (serverRunning && !network->getIsServer())
        {
            network->setIsServer(true);
        }
        if (clientRunning && !network->getIsClient())
        {
            network->setIsClient(true);
        }

        if (gameS->getGameType() == MULTI && network->getTeamNumber() < 0)
        {
            if (network->getIsServer())
            {
                network->setTeamNumber(0);
            }
            
            if (network->getIsClient())
            {
                network->setTeamNumber(1);
            }
        }
        
        logMsg("serverRunning = " +serverRunning);
        logMsg("clientRunning = " +clientRunning);
        if (changeInTime >= 100)
        {
//	        	exit(0);
            if (serverRunning)
            {
                network->networkServer();	// Runs network server code
                
            }
            if (clientRunning)
            {
                network->networkClient();	// runs network client code
            }


//            logMsg("changeInTime = " +toString(changeInTime));
            if (renderScene)
            {
                logMsg("gameS->logic()");
                gameS->logic();
            }

                oldTime = loopTime.getMilliseconds();

        }
    

	        // writes Framerate to Ogre.log
//	                Ogre::LogManager::getSingletonPtr()->logMessage("FPS = " +currFPS);

        processInput();
//          inputWorkerThread->join();
/*	    	else
	    	{
	    	}
*/
	 			//        player->getNode(0)->translate(Pos);
	//        pInstance[bballInstance[0].getPlayer()].getNode()->translate(-0.02f,0.0f,0.0f);

        if (render->getMWindow() != NULL && render->getMWindow()->isActive())
        {
//			Ogre::LogManager::getSingletonPtr()->logMessage("Rendering frame");
            render->getMWindow()->windowMovedOrResized();
            render->getMRoot()->renderOneFrame();
        }
//		#endif
    }

}
