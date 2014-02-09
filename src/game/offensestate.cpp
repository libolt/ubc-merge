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

offenseState::offenseState() // constructor
{
	execute = false;
	startPositions = new Ogre::Vector3[5];
	startPositions[0] = Ogre::Vector3(5.0f,-13.5f,380.0f); // FIXME! doesn't belong here
	startPositions[1]	= Ogre::Vector3(3.0f,-12.5f,375.0f);
	startPositions[2]	= Ogre::Vector3(4.0f,-14.5f,385.0f);
	startPositions[3]	= Ogre::Vector3(6.0f,-11.5f,377.0f);
	startPositions[4]	= Ogre::Vector3(3.0f,-13.5f,378.0f);

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

void offenseState::setupState()		// sets up initial state of the object
{
	startPositions[0] = Ogre::Vector3(5.0f,-13.5f,380.0f);
}

// FIXME! update for class reorganization
void offenseState::updateState()	// updates the state of the object
{
/*    teamState *teamS = gameState::Instance();
    std::vector<playerState> playerInstance = gameS->getPlayerInstance();

    int playerWithBall = gameS->getPlayerWithBall();
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

		    Ogre::LogManager::getSingletonPtr()->logMessage("Player with ball's start position: "  +Ogre::StringConverter::toString(startPositions[playerWithBall]));
		    Ogre::LogManager::getSingletonPtr()->logMessage(("Player with ball's current position: "  +Ogre::StringConverter::toString(playerInstance[playerWithBall].getNode()->getPosition())));

			Ogre::LogManager::getSingletonPtr()->logMessage("playerDirection = " +Ogre::StringConverter::toString(playerInstance[3].getDirection()));


		}
	}

	gameS->setPlayerInstance(playerInstance);
*/
}
