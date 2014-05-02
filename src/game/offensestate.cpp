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
#include "playerstate.h"
#include "teamstate.h"

offenseState::offenseState() // constructor
{
	execute = false;
	startPositions = new Ogre::Vector3[5];
	startPositions[0] = Ogre::Vector3(5.0f,-13.5f,380.0f); // FIXME! doesn't belong here
	startPositions[1]	= Ogre::Vector3(3.0f,-12.5f,375.0f);
	startPositions[2]	= Ogre::Vector3(4.0f,-14.5f,385.0f);
	startPositions[3]	= Ogre::Vector3(6.0f,-11.5f,377.0f);
	startPositions[4]	= Ogre::Vector3(3.0f,-13.5f,378.0f);

	startXPosSet = new bool[5];
	startYPosSet = new bool[5];
	startZPosSet = new bool[5];
	startPositionSet = new bool[5];

	for (int x=0;x<5;++x)
	{
		startXPosSet[x] = false;
		startYPosSet[x] = false;
		startZPosSet[x] = false;
		startPositionSet[x] = false;
	}

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

bool offenseState::getStartPositionSet()  // returns the value of startPositionSet
{
	return (startPositionSet);
}
void offenseState::setStartPositionSet(bool *set) // sets the value of startPositionSet
{
	startPositionSet = set;
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
						            Ogre::LogManager::getSingletonPtr()->logMessage("UPLEFT");
					            }
					            else if (playerPos[x][0] < startPositions[x][0])
					            {
						            playerInstance[x].setMovement(true);
						            playerInstance[x].setDirection(UPRIGHT);
						            Ogre::LogManager::getSingletonPtr()->logMessage("UPRIGHT");
					            }
				            }
				            else if (playerPos[x][2] < startPositions[x][2])
				            {
					            if (playerPos[x][0] > startPositions[x][0])
					            {
						            playerInstance[x].setMovement(true);
						            playerInstance[x].setDirection(DOWNLEFT);
						            Ogre::LogManager::getSingletonPtr()->logMessage("DOWNLEFT");
					            }
					            else if (playerPos[x][0] < startPositions[x][0])
					            {
						            playerInstance[x].setMovement(true);
						            playerInstance[x].setDirection(DOWNRIGHT);
						            Ogre::LogManager::getSingletonPtr()->logMessage("DOWNRIGHT");
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
					            Ogre::LogManager::getSingletonPtr()->logMessage("LEFT");
				            }
				            else if (playerPos[x][0] < startPositions[x][0])
				            {
					            playerInstance[x].setMovement(true);
					            playerInstance[x].setDirection(RIGHT);
					            Ogre::LogManager::getSingletonPtr()->logMessage("RIGHT");
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
					            Ogre::LogManager::getSingletonPtr()->logMessage("DOWN");
				            }
				            else if (playerPos[x][2] > startPositions[x][2])
				            {
					            playerInstance[x].setMovement(true);
					            playerInstance[x].setDirection(UP);
					            Ogre::LogManager::getSingletonPtr()->logMessage("UP");
				            }
				            else
				            {
				            }

						}
						else
						{

						}
/*
			            // checks if both x and z coordinates need to be updated
			            if (playerPos[x][0] != startPositions[x][0] && playerPos[x][2] != startPositions[x][2])
			            {
				            Ogre::LogManager::getSingletonPtr()->logMessage("X & Z");
				            if (playerPos[x][2] > startPositions[x][2])
				            {
					            if (playerPos[x][0] > startPositions[x][0])
					            {
						            playerInstance[x].setMovement(true);
						            playerInstance[x].setDirection(UPLEFT);
						            Ogre::LogManager::getSingletonPtr()->logMessage("UPLEFT");
					            }
					            else if (playerPos[x][0] < startPositions[x][0])
					            {
						            playerInstance[x].setMovement(true);
						            playerInstance[x].setDirection(UPRIGHT);
						            Ogre::LogManager::getSingletonPtr()->logMessage("UPRIGHT");
					            }
					            else
					            {
						            playerInstance[x].setMovement(true);
						            playerInstance[x].setDirection(UP);
						            Ogre::LogManager::getSingletonPtr()->logMessage("UP");
					            }
				            }
				            else if (playerPos[x][2] < startPositions[x][2])
				            {
					            if (playerPos[x][0] > startPositions[x][0])
					            {
						            playerInstance[x].setMovement(true);
						            playerInstance[x].setDirection(DOWNLEFT);
						            Ogre::LogManager::getSingletonPtr()->logMessage("DOWNLEFT");
					            }
					            else if (playerPos[x][0] < startPositions[x][0])
					            {
						            playerInstance[x].setMovement(true);
						            playerInstance[x].setDirection(DOWNRIGHT);
						            Ogre::LogManager::getSingletonPtr()->logMessage("DOWNRIGHT");
					            }
					            else
					            {
						            playerInstance[x].setMovement(true);
						            playerInstance[x].setDirection(DOWN);
						            Ogre::LogManager::getSingletonPtr()->logMessage("DOWN");
					            }
				            }
				            else
				            {
				            }

				        //				exit(0);
			            }
			            else if (playerPos[x][0] != startPositions[x][0])
			            {
				            // checks the X position and moves player accordingly
				            if (playerPos[x][0] > startPositions[x][0])
				            {
					            playerInstance[x].setMovement(true);
					            playerInstance[x].setDirection(LEFT);
					            Ogre::LogManager::getSingletonPtr()->logMessage("LEFT");
				            }
				            else if (playerPos[x][0] < startPositions[x][0])
				            {
					            playerInstance[x].setMovement(true);
					            playerInstance[x].setDirection(RIGHT);
					            Ogre::LogManager::getSingletonPtr()->logMessage("RIGHT");
				            }
				            else
				            {
				            }
				            Ogre::LogManager::getSingletonPtr()->logMessage("X");
//				exit(0);
			            }
			            else if (playerPos[x][2] != startPositions[x][2])
			            {
				            // checks the Y position and moves player accordingly
				            if (playerPos[x][2] < startPositions[x][2])
				            {
					            playerInstance[x].setMovement(true);
					            playerInstance[x].setDirection(DOWN);
					            Ogre::LogManager::getSingletonPtr()->logMessage("DOWN");
				            }
				            else if (playerPos[x][2] > startPositions[x][2])
				            {
					            playerInstance[x].setMovement(true);
					            playerInstance[x].setDirection(UP);
					            Ogre::LogManager::getSingletonPtr()->logMessage("UP");
				            }
				            else
				            {
				            }
				            Ogre::LogManager::getSingletonPtr()->logMessage("Y");
//				exit(0);
			            }
			            else
			            {
			            }
                    }
			        else
			        {
			        }*/
//		    Ogre::LogManager::getSingletonPtr()->logMessage("Player with ball's start position: "  +Ogre::StringConverter::toString(startPositions[playerWithBall]));
//		    Ogre::LogManager::getSingletonPtr()->logMessage(("Player with ball's current position: "  +Ogre::StringConverter::toString(playerInstance[playerWithBall].getNode()->getPosition())));
//			Ogre::LogManager::getSingletonPtr()->logMessage("playerDirection = " +Ogre::StringConverter::toString(playerInstance[3].getDirection()));
			        }
				}
            }
		}
	}

	teamInstance[teamNumber].setPlayerInstance(playerInstance);
    gameS->setTeamInstance(teamInstance);
}
