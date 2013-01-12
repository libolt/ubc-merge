/***************************************************************************
 *   Copyright (C) 2006 by Mike McLean   *
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

#include "gamestate.h"
#include "playerdata.h"
#include "players.h"

gameState *gameState::pInstance = 0;

gameState *gameState::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new gameState; // create sole instance
    }
    return pInstance; // address of sole instance
}

gameState::gameState()
{
    currentQuarter = FIRST;
    gameTimeLeft = 0.0f;
    quarterTimeLeft = 0.0f;
    finished = false;
}
gameState::~gameState()
{
}

// gets and sets teamID
vector<int> gameState::getTeamID(void)
{
    return (teamID);
}
void gameState::setTeamID(std::vector<int> ID)
{
    teamID = ID;
}

// gets and sets plaeyrID

vector<int> gameState::getPlayerID(void)
{
    return (playerID);
}
void gameState::setPlayerID(std::vector<int> ID)
{
    playerID = ID;
}

// gets and sets playerInstance std::vector
vector <playerState> gameState::getPlayerInstance()
{
    return (playerInstance);
}

void gameState::setPlayerInstance(std::vector<playerState> pInstance)
{
    playerInstance = pInstance;
}

// creates the player Instances for the particular game

bool gameState::createPlayerInstances()
{
    players *player = players::Instance();

    std::vector <playerData> playerN = player->getPlayer(); // copies Player values to playerN
    std::vector <int>::iterator playerIT;
    for (playerIT = playerID.begin(); playerIT != playerID.end(); ++playerIT)   // loops through playerID std::vector
    {
            playerState pInstance;  // creates a new instance of playerState
            pInstance.setModelName(playerN[*playerIT].getModel());  // copies the model name from the playerData std::vector to the pInstance class
            pInstance.setFirstName(playerN[*playerIT].getFirstName());  // copies the first name from the playerData std::vector to the pInstance class
            pInstance.setLastName(playerN[*playerIT].getLastName());    // copies the last name from the playerData std::vector to the pInstance class
            pInstance.setPosChange(Ogre::Vector3(0.0f,0.0f,0.0f));
            playerInstance.push_back(pInstance);    // adds pInstance to the playerInstance std::vector.
    }
//    exit(0);
//    std::vector <playerState>::iterator pInstanceIT;
    int pInstanceIT = 0;
    for (pInstanceIT = 0; pInstanceIT < playerInstance.size(); ++pInstanceIT)
    {
        playerInstance[pInstanceIT].loadModel();
    }
    return true;
}

// gets and sets basketballInstance std::vector
vector <basketballs> gameState::getBasketballInstance()
{
    return (basketballInstance);
}
 void gameState::setBasketballInstance(std::vector<basketballs> bballInstance)
{
    basketballInstance = bballInstance;
}

// creates basketball Instances
bool gameState::createBasketballInstances()
{
    basketballs bballInstance;  // creates an instance of the basketballs class
    bballInstance.setModelName("bball.mesh");
    bballInstance.loadModel();
    basketballInstance.push_back(bballInstance);
    return true;
}

// gets and sets teamInstance
vector <teamState> gameState::getTeamInstance()
{
    return (teamInstance);
}
void gameState::setTeamInstance(std::vector<teamState> Instance)
{
    teamInstance = Instance;
}

// creates team Instances
bool gameState::createTeamInstances()
{
    return true;
}

// gets and sets courtInstance std::vector
vector <courtState> gameState::getCourtInstance()
{
    return (courtInstance);
}
void gameState::setCourtInstance(std::vector<courtState> Instance)
{
    courtInstance = Instance;
}

// creates court Instances
bool gameState::createCourtInstances()
{
    courtState cInstance;  // creates an instance of the courtState class
    cInstance.setModelName("court.mesh");
    cInstance.loadModel();
    courtInstance.push_back(cInstance);

    return true;
}

// updates positions of gameState objects
bool gameState::updatePositions()
{
    for (int x = 0; x < playerInstance.size(); ++x)
    {
        playerInstance[x].updatePosition();
    }

    return true;
}
