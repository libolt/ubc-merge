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

#include "offensestate.h"
#include "gamestate.h"
#include "logging.h"
#include "playerstate.h"
#include "teamstate.h"

offenseState::offenseState() // constructor
{
	selectedOffense = BOX; // sets the default offense to box
	execute = false;
	offenseSet = false;
	startPositions = new Ogre::Vector3[5];

	for (int x=0; x<5; ++x)
	{
		startPositions[x]	= Ogre::Vector3(0.0f,0.0f,0.0f);

	}
//    startPositions[4]	= Ogre::Vector3(3000.0f,-1300.5f,3780.0f);

//	executePositions = new std::vector<Ogre::Vector3>[5];
//	executePositions[0] = new std::vector<Ogre::Vector3>;
//	exit(0);

    executePositions.resize(5);

	startXPosSet = new bool[5];
	startYPosSet = new bool[5];
	startZPosSet = new bool[5];
	startPositionSet = new bool[5];

//	executePositionSet = new bool[5];

	for (int x=0;x<5;++x)
	{
		startXPosSet[x] = false;
		startYPosSet[x] = false;
		startZPosSet[x] = false;
		startPositionSet[x] = false;
//		executePositionSet[x] = false;
	}

	boxOffenseSetup = false;
}

offenseTypes offenseState::getSelectedOffense() // returns value of selectedOffense
{
	return (selectedOffense);
}
void offenseState::setSelectedOffense(offenseTypes selected) // sets the value of selectedOffense
{
	selectedOffense = selected;
}

bool offenseState::getExecute()	// retrieves the value of execute variable
{
	return (execute);
}
void offenseState::setExecute(bool ex)	// sets the value of the execute variable
{
	execute = ex;
}

Ogre::Vector3 *offenseState::getStartPositions()	// retrieves startPositions variable
{
	return (startPositions);
}

void offenseState::setStartPositions(Ogre::Vector3 *positions)	// sets startPositions
{
	startPositions = positions;
}

std::vector< std::vector<Ogre::Vector3> > offenseState::getExecutePositions()	// retrieves startPositions variable
{
	return (executePositions);
}

void offenseState::setExecutePositions(std::vector< std::vector<Ogre::Vector3> > positions)	// sets startPositions
{
	executePositions = positions;
}

bool offenseState::getStartXPosSet()  // returns the value of startXPosSet
{
    return (startXPosSet);
}
void offenseState::setStartXPosSet(bool *set) // sets the value of startXPosSet
{
	startXPosSet = set;
}

bool offenseState::getStartYPosSet()  // returns the value of startYPosSet
{
    return (startYPosSet);
}
void offenseState::setStartYPosSet(bool *set) // sets the value of startYPosSet
{
	startYPosSet = set;
}

bool offenseState::getStartZPosSet()  // returns the value of startZPosSet
{
    return (startZPosSet);
}
void offenseState::setStartZPosSet(bool *set) // sets the value of startZPosSet
{
	startZPosSet = set;
}

bool *offenseState::getStartPositionSet()  // returns the value of startPositionSet
{
	return (startPositionSet);
}
void offenseState::setStartPositionSet(bool *set) // sets the value of startPositionSet
{
	startPositionSet = set;
}

std::vector< std::vector<bool> > offenseState::getExecutePositionReached()  // returns the value of executePositionSet
{
	return (executePositionReached);
}
void offenseState::setExecutePositionReached(std::vector< std::vector<bool> > reached) // sets the value of executePositionSet
{
	executePositionReached = reached;
}

void offenseState::setupState()		// sets up initial state of the object
{
	startPositions[0] = Ogre::Vector3(5.0f,-13.5f,380.0f);
}

void offenseState::updateState(int teamNumber)	// updates the state of the object
{
//	exit(0);
	gameState *gameS = gameState::Instance();
    std::vector<teamState> teamInstance = gameS->getTeamInstance();
    std::vector<playerState> playerInstance = teamInstance[teamNumber].getPlayerInstance();
/*
    int playerWithBall = teamInstance[teamNumber].getPlayerWithBall();
	int humanPlayer = teamInstance[teamNumber].getHumanPlayer();

    Ogre::Vector3 *playerPos = new Ogre::Vector3[5];

    for (int p = 0; p < 5; ++p)
    {
    	playerPos[p] = playerInstance[p].getNode()->getPosition();
    }

    if (execute)
	{
		for (int x = 0; x < 5; ++x)
//    	int x = 3;
    	{
			// checks if player is human controlled
			if (humanPlayer != x)
			{
				// checks if the player is at their start position
				if (!startPositionSet[x])
				{
			        // checks if player has ball
			        if (x != playerWithBall)
			        {
						if (!startXPosSet[x] && !startZPosSet[x])
						{
				            if (playerPos[x][2] > startPositions[x][2])
				            {
					            if (playerPos[x][0] > startPositions[x][0])
					            {
						            playerInstance[x].setMovement(true);
						            playerInstance[x].setDirection(UPLEFT);
						            logMsg("UPLEFT");
					            }
					            else if (playerPos[x][0] < startPositions[x][0])
					            {
						            playerInstance[x].setMovement(true);
						            playerInstance[x].setDirection(UPRIGHT);
						            logMsg("UPRIGHT");
					            }
				            }
				            else if (playerPos[x][2] < startPositions[x][2])
				            {
					            if (playerPos[x][0] > startPositions[x][0])
					            {
						            playerInstance[x].setMovement(true);
						            playerInstance[x].setDirection(DOWNLEFT);
						            logMsg("DOWNLEFT");
					            }
					            else if (playerPos[x][0] < startPositions[x][0])
					            {
						            playerInstance[x].setMovement(true);
						            playerInstance[x].setDirection(DOWNRIGHT);
						            logMsg("DOWNRIGHT");
					            }
				            }


						}
						else if (!startXPosSet[x])
						{
				            // checks the X position and moves player accordingly
				            if (playerPos[x][0] > startPositions[x][0])
				            {
					            playerInstance[x].setMovement(true);
					            playerInstance[x].setDirection(LEFT);
					            logMsg("LEFT");
				            }
				            else if (playerPos[x][0] < startPositions[x][0])
				            {
					            playerInstance[x].setMovement(true);
					            playerInstance[x].setDirection(RIGHT);
					            logMsg("RIGHT");
				            }
				            else
				            {
				            }

						}
						else if(!startZPosSet[x])
						{
				            // checks the Y position and moves player accordingly
				            if (playerPos[x][2] < startPositions[x][2])
				            {
					            playerInstance[x].setMovement(true);
					            playerInstance[x].setDirection(DOWN);
					            logMsg("DOWN");
				            }
				            else if (playerPos[x][2] > startPositions[x][2])
				            {
					            playerInstance[x].setMovement(true);
					            playerInstance[x].setDirection(UP);
					            logMsg("UP");
				            }
				            else
				            {
				            }

						}
						else
						{

						}			        }
				}
            }
		}
	}
*/
    if (!boxOffenseSetup)
    {
    	setupBoxOffense();
    }
	teamInstance[teamNumber].setPlayerInstance(playerInstance);
    gameS->setTeamInstance(teamInstance);
}

void offenseState::setupBoxOffense() // sets up box offense
{
	startPositions[0] = Ogre::Vector3(5.0f,-13.5f,380.0f);
	startPositions[1] = Ogre::Vector3(3.0f,-12.5f,375.0f);
	startPositions[2] = Ogre::Vector3(4.0f,-14.5f,385.0f);
	startPositions[3] = Ogre::Vector3(6.0f,-11.5f,377.0f);
	startPositions[4] = Ogre::Vector3(3.0f,-13.5f,378.0f);

	executePositions[0].push_back(Ogre::Vector3(5.0f,-13.5f,380.0f));

	executePositions[1].push_back(Ogre::Vector3(13.0f,-12.5f,375.0f));
	executePositions[1].push_back(Ogre::Vector3(11.0f,-12.5f,390.0f));

	executePositions[2].push_back(Ogre::Vector3(14.0f,-14.5f,385.0f));
	executePositions[2].push_back(Ogre::Vector3(16.0f,-14.5f,370.0f));

	executePositions[3].push_back(Ogre::Vector3(16.0f,-11.5f,377.0f));
	executePositions[4].push_back(Ogre::Vector3(13.0f,-13.5f,378.0f));

	executePositionReached.resize(5);
	for (int x=0; x<executePositions.size(); ++x)
	{

		executePositionReached[x].resize(executePositions[x].size());
		for (int y=0;y<executePositionReached[x].size(); ++y)
		{
			logMsg("Y = " +Ogre::StringConverter::toString(y));
			executePositionReached[x][y] = false;
		}
	}
	boxOffenseSetup = true;
}
void offenseState::executeBoxOffense() // executes box offense
{

}
