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
    gameS->setupState();

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
			std::vector<playerState> playerInstance = gameS->getPlayerInstance();	// stores th player instances

	//        ubc->processUnbufferedKeyInput();

	//        render->frameStarted();
			// run the message pump (Eihort)
	//		Ogre::WindowEventUtilities::messagePump();

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
	    		if (render->createScene())
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

				if (gameS->getGameType() == SINGLE)
				{
					Ogre::String keyPressed = input->getKeyPressed();
					int playerWithBall = gameS->getPlayerWithBall();

					if (keyPressed == "q")
					{
						quitGame = true;
					}
					else if (keyPressed == "up")
					{
						Ogre::String packetData;
						playerInstance[playerWithBall].setMovement(true);
						playerInstance[playerWithBall].setDirection(UP);
						gameS->setPlayerInstance(playerInstance);
					}
					else if (keyPressed == "down")
					{
						Ogre::String packetData;
						playerInstance[playerWithBall].setMovement(true);
						playerInstance[playerWithBall].setDirection(DOWN);
						gameS->setPlayerInstance(playerInstance);
					}
					else if (keyPressed == "left")
					{
						Ogre::String packetData;
						playerInstance[playerWithBall].setMovement(true);
						playerInstance[playerWithBall].setDirection(LEFT);
						gameS->setPlayerInstance(playerInstance);
					}
					else if (keyPressed == "right")
					{
						Ogre::String packetData;
						playerInstance[playerWithBall].setMovement(true);
						playerInstance[playerWithBall].setDirection(RIGHT);
						gameS->setPlayerInstance(playerInstance);
					}
					else if (keyPressed == "rightAlt")
					{
						playerInstance[playerWithBall].setPassBall(true);
						playerInstance[playerWithBall].setPassCalculated(false);
						gameS->setPlayerWithBallDribbling(false);
						gameS->setPlayerInstance(playerInstance);
				}

				}

				else if (gameS->getGameType() == MULTI)
				{
					int playerWithBall = gameS->getPlayerWithBall();
					if (clientRunning)	// checks if game is running in client mode
					{
						Ogre::String keyPressed = input->getKeyPressed();
						if (keyPressed == "q")
						{
							quitGame =true;
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
						else if (keyPressed == "rightAlt")
						{
							Ogre::String packetData;
							playerInstance[playerWithBall].setPassBall(true);
							playerInstance[playerWithBall].setPassCalculated(false);
							gameS->setPlayerWithBallDribbling(false);
					    	gameS->setPlayerInstance(playerInstance);
					    	packetData = "player6" + keyPressed;
					    	network->sendPacket(packetData);
						}
					    else
						{
						}
					}
					else if (serverRunning)	// checks if game is running in server mode
					{
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
						else if (keyPressed == "rightAlt")
						{
							Ogre::String packetData;
							playerInstance[playerWithBall].setPassBall(true);
							playerInstance[playerWithBall].setPassCalculated(false);
					    	gameS->setPlayerInstance(playerInstance);
							gameS->setPlayerWithBallDribbling(false);
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
	 			//        player->getNode(0)->translate(Pos);
	//        pInstance[bballInstance[0].getPlayer()].getNode()->translate(-0.02f,0.0f,0.0f);

    if( render->getMWindow() != NULL && render->getMWindow()->isActive())
		{
    		render->getMWindow()->windowMovedOrResized();
			render->getMRoot()->renderOneFrame();
  }
	    }

}
