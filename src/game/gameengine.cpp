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
#include "input.h"

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

    menuActive = false;
    quitGame = false;
    serverRunning = false;
    clientRunning = false;
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
