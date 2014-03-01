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

#include "gameengine.h"
#include "gamestate.h"
#include "gui.h"
#include "input.h"
#include "network.h"
#include "renderengine.h"

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

gameS->setupState();
//#endif
    return true;
}

void gameEngine::quit()
{
    using namespace OIS;
    inputSystem *input = inputSystem::Instance();
    input->destroy();

}

void gameEngine::gameLoop()	// Main Game Loop
{
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID

    renderEngine * render = renderEngine::Instance();

	gameState *gameS = gameState::Instance();

    GUISystem *gui = GUISystem::Instance();

    inputSystem *input = inputSystem::Instance();

    networkEngine *network = networkEngine::Instance();

    players *player = players::Instance();

    float lastFPS = 0.0f;	// stores value of last Frames Per Second
//    float changeInTime;		// stores change in time
//    int newTime;	// stores new time
//    unsigned long oldTime = 0;	// stores old time
    Ogre::Timer loopTime;	// loop timer
    loopTime.reset();	// resets the timer

	   while (!quitGame)
	    {
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//			std::vector<playerState> playerInstance = gameS->getPlayerInstance();	// stores th player instances

	//        ubc->processUnbufferedKeyInput();

	//        render->frameStarted();
			// run the message pump (Eihort)
	//		Ogre::WindowEventUtilities::messagePump();
//		   exit(0);

		   if (gameS->getGameType() == SINGLE)
		   {

				if (!sceneCreated)
				{
					createScene = true;
				}

		   }
		   
		   else if (gameS->getGameType() == MULTI)
		   {
				if (network->getServerReceivedConnection() || network->getClientEstablishedConnection())	// checks if server and client are connected
				{
					if (!sceneCreated)
					{
						createScene = true;
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

	        updateChangeInTime();	// calculates the change in time.

//	        Ogre::LogManager::getSingletonPtr()->logMessage("changeInTime = " +Ogre::StringConverter::toString(changeInTime));
	        // updates game logic every 100 milliseconds
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


//            Ogre::LogManager::getSingletonPtr()->logMessage("changeInTime = " +Ogre::StringConverter::toString(changeInTime));
	           	if (renderScene)
	            {
	           		gameS->logic();
	           	}

	        	oldTime = loopTime.getMilliseconds();

	        }
			

	        // writes Framerate to Ogre.log
//	                Ogre::LogManager::getSingletonPtr()->logMessage("FPS = " +currFPS);

	    	if (input->processInput())
	        {

	    		if (gameS->getTeamInstancesCreated())
                {
					if (gameS->getGameType() == SINGLE)
					{

						std::vector<teamState> teamInstance = gameS->getTeamInstance();
//						exit(0);
						Ogre::String keyPressed = input->getKeyPressed();
						int teamWithBall = gameS->getTeamWithBall();
//						int humanPlayer = teamInstance[teamWithBall].getHumanPlayer();
						if (teamInstance[0].getPlayerInstancesCreated())
						{
//							exit(0);
							std::vector<playerState> playerInstance = teamInstance[0].getPlayerInstance();

							if (teamInstance[0].getHumanControlled())
							{
								int humanPlayer = teamInstance[0].getHumanPlayer();
								if (keyPressed == "q")
								{
									quitGame = true;
								}
								else if (keyPressed == "up")
								{
									Ogre::LogManager::getSingletonPtr()->logMessage("Human Player keypress = " +Ogre::StringConverter::toString(humanPlayer));
									Ogre::String packetData;
									playerInstance[humanPlayer].setMovement(true);
									playerInstance[humanPlayer].setDirection(UP);

									teamInstance[0].setPlayerInstance(playerInstance);
									gameS->setTeamInstance(teamInstance);

								}
								else if (keyPressed == "down")
								{
									Ogre::String packetData;
									playerInstance[humanPlayer].setMovement(true);
									playerInstance[humanPlayer].setDirection(DOWN);
									teamInstance[0].setPlayerInstance(playerInstance);
									gameS->setTeamInstance(teamInstance);
								}
								else if (keyPressed == "left")
								{
									Ogre::String packetData;
									playerInstance[humanPlayer].setMovement(true);
//									exit(0);
									playerInstance[humanPlayer].setDirection(LEFT);
									teamInstance[0].setPlayerInstance(playerInstance);
									gameS->setTeamInstance(teamInstance);
								}
								else if (keyPressed == "right")
								{
									Ogre::String packetData;
									playerInstance[humanPlayer].setMovement(true);
									playerInstance[humanPlayer].setDirection(RIGHT);
									teamInstance[0].setPlayerInstance(playerInstance);
									gameS->setTeamInstance(teamInstance);
								}
								else if (keyPressed == "rightAlt")
								{
									playerInstance[humanPlayer].setPassBall(true);
									playerInstance[humanPlayer].setPassCalculated(false);
									teamInstance[0].setPlayerWithBallDribbling(false);
									teamInstance[0].setPlayerInstance(playerInstance);
									gameS->setTeamInstance(teamInstance);
								}
							}
						}

						if (teamInstance[1].getPlayerInstancesCreated())
						{
							std::vector<playerState> playerInstance = teamInstance[1].getPlayerInstance();

							if (teamInstance[1].getHumanControlled())
							{
								int humanPlayer = teamInstance[1].getHumanPlayer();
								if (keyPressed == "q")
								{
									quitGame = true;
								}
								else if (keyPressed == "w")
								{
									Ogre::String packetData;
									playerInstance[humanPlayer].setMovement(true);
									playerInstance[humanPlayer].setDirection(UP);
									Ogre::LogManager::getSingletonPtr()->logMessage("Human Player keypress = " +Ogre::StringConverter::toString(humanPlayer));

									teamInstance[1].setPlayerInstance(playerInstance);
									gameS->setTeamInstance(teamInstance);

								}
								else if (keyPressed == "s")
								{
									Ogre::String packetData;
									playerInstance[humanPlayer].setMovement(true);
									playerInstance[humanPlayer].setDirection(DOWN);
									teamInstance[1].setPlayerInstance(playerInstance);
									gameS->setTeamInstance(teamInstance);
								}
								else if (keyPressed == "a")
								{
									Ogre::String packetData;
									playerInstance[humanPlayer].setMovement(true);
									playerInstance[humanPlayer].setDirection(LEFT);
									teamInstance[1].setPlayerInstance(playerInstance);
									gameS->setTeamInstance(teamInstance);
								}
								else if (keyPressed == "d")
								{
									Ogre::String packetData;
									playerInstance[humanPlayer].setMovement(true);
									playerInstance[humanPlayer].setDirection(RIGHT);
									teamInstance[1].setPlayerInstance(playerInstance);
									gameS->setTeamInstance(teamInstance);
								}
								else if (keyPressed == "leftAlt")
								{
									playerInstance[humanPlayer].setPassBall(true);
									playerInstance[humanPlayer].setPassCalculated(false);
									teamInstance[1].setPlayerWithBallDribbling(false);
									teamInstance[1].setPlayerInstance(playerInstance);
									gameS->setTeamInstance(teamInstance);
								}
							}
						}
					}

					else if (gameS->getGameType() == MULTI)
					{
						std::vector<teamState> teamInstance = gameS->getTeamInstance();
						int teamWithBall = gameS->getTeamWithBall();
						int playerWithBall = teamInstance[teamWithBall].getPlayerWithBall();
						if (clientRunning)	// checks if game is running in client mode
						{
							std::vector<playerState> playerInstance = teamInstance[1].getPlayerInstance();
							Ogre::String keyPressed = input->getKeyPressed();
							if (keyPressed == "q")
							{
								quitGame =true;
							}
							else if (keyPressed == "up")
							{
								Ogre::String packetData;
								playerInstance[0].setMovement(true);
								playerInstance[0].setDirection(UP);
								teamInstance[1].setPlayerInstance(playerInstance);
								gameS->setTeamInstance(teamInstance);
								packetData = "player0" + keyPressed;
								network->sendPacket(packetData);
							}
							else if (keyPressed == "down")
							{
								Ogre::String packetData;
								playerInstance[0].setMovement(true);
								playerInstance[0].setDirection(DOWN);
								teamInstance[1].setPlayerInstance(playerInstance);
								gameS->setTeamInstance(teamInstance);
								packetData = "player0" + keyPressed;
								network->sendPacket(packetData);
							}
							else if (keyPressed == "left")
							{
								Ogre::String packetData;
								playerInstance[0].setMovement(true);
								playerInstance[0].setDirection(LEFT);
								teamInstance[1].setPlayerInstance(playerInstance);
								gameS->setTeamInstance(teamInstance);
								packetData = "player0" + keyPressed;
								network->sendPacket(packetData);
							}
							else if (keyPressed == "right")
							{
								Ogre::String packetData;
								playerInstance[0].setMovement(true);
								playerInstance[0].setDirection(RIGHT);
								teamInstance[1].setPlayerInstance(playerInstance);
								gameS->setTeamInstance(teamInstance);
								packetData = "player0" + keyPressed;
								network->sendPacket(packetData);
							}
							else if (keyPressed == "rightAlt")
							{
								Ogre::String packetData;
								playerInstance[playerWithBall].setPassBall(true);
								playerInstance[playerWithBall].setPassCalculated(false);
								teamInstance[1].setPlayerWithBallDribbling(false);
								teamInstance[1].setPlayerInstance(playerInstance);
								gameS->setTeamInstance(teamInstance);
								packetData = "player0" + keyPressed;
								network->sendPacket(packetData);
							}
							else
							{
							}
						}
						else if (serverRunning)	// checks if game is running in server mode
						{
							std::vector<playerState> playerInstance = teamInstance[0].getPlayerInstance();
							Ogre::String keyPressed = input->getKeyPressed();
							if (keyPressed == "q")
							{
								quitGame = true;
							}
							else if (keyPressed == "up")
							{
								Ogre::String packetData;
								playerInstance[0].setMovement(true);
								playerInstance[0].setDirection(UP);
								teamInstance[0].setPlayerInstance(playerInstance);
								gameS->setTeamInstance(teamInstance);
								packetData = "player0" + keyPressed;
								network->sendPacket(packetData);
							}
							else if (keyPressed == "down")
							{
								Ogre::String packetData;
								playerInstance[0].setMovement(true);
								playerInstance[0].setDirection(DOWN);
								teamInstance[0].setPlayerInstance(playerInstance);
								gameS->setTeamInstance(teamInstance);
								packetData = "player0" + keyPressed;
								network->sendPacket(packetData);
							}
							else if (keyPressed == "left")
							{
								Ogre::String packetData;
								playerInstance[0].setMovement(true);
								playerInstance[0].setDirection(LEFT);
								teamInstance[0].setPlayerInstance(playerInstance);
								gameS->setTeamInstance(teamInstance);
								packetData = "player0" + keyPressed;
								network->sendPacket(packetData);
							}
							else if (keyPressed == "right")
							{
								Ogre::String packetData;
								playerInstance[0].setMovement(true);
								playerInstance[0].setDirection(RIGHT);
								teamInstance[0].setPlayerInstance(playerInstance);
								gameS->setTeamInstance(teamInstance);
								packetData = "player0" + keyPressed;
								network->sendPacket(packetData);
							}
							else if (keyPressed == "rightAlt")
							{
								Ogre::String packetData;
								playerInstance[playerWithBall].setPassBall(true);
								playerInstance[playerWithBall].setPassCalculated(false);
								teamInstance[0].setPlayerWithBallDribbling(false);
								teamInstance[0].setPlayerInstance(playerInstance);
								gameS->setTeamInstance(teamInstance);
								packetData = "player0" + keyPressed;
								network->sendPacket(packetData);
							}
							else
							{
							}
						}

						else
						{
						}
				    }
                }

            }
	    	else
	    	{
	    	}

	 			//        player->getNode(0)->translate(Pos);
	//        pInstance[bballInstance[0].getPlayer()].getNode()->translate(-0.02f,0.0f,0.0f);

    if( render->getMWindow() != NULL && render->getMWindow()->isActive())
		{
    		render->getMWindow()->windowMovedOrResized();
			render->getMRoot()->renderOneFrame();
        }
//		#endif
    }   
	
}
