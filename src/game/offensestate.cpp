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

void offenseState::updateState()	// updates the state of the object
{
    gameState *gameS = gameState::Instance();
    std::vector<playerState> playerInstance = gameS->getPlayerInstance();
    Ogre::Vector3 *playerPos = new Ogre::Vector3[5];

    for (int p = 0; p < 5; ++p)
    {
    	playerPos[p] = playerInstance[p].getNode()->getPosition();
    }

    if (execute)
	{
		for (int x = 0; x < 5; ++x)
		{
			// checks the X & Y positions and moves player accordingly
			if (playerPos[x][0] > startPositions[x][0])
			{
				if (playerPos[x][1] < startPositions[x][1])
				{
					playerInstance[x].setMovement(true);
					playerInstance[x].setDirection(UPLEFT);
				}
				else if (playerPos[x][1] > startPositions[x][1])
				{
					playerInstance[x].setMovement(true);
					playerInstance[x].setDirection(UPRIGHT);
				}
				else
				{
					playerInstance[x].setMovement(true);
					playerInstance[x].setDirection(UP);
				}
			}
			else if (playerPos[x][0] < startPositions[x][0])
			{
				if (playerPos[x][1] < startPositions[x][1])
				{
					playerInstance[x].setMovement(true);
					playerInstance[x].setDirection(DOWNLEFT);
				}
				else if (playerPos[x][1] > startPositions[x][1])
				{
					playerInstance[x].setMovement(true);
					playerInstance[x].setDirection(DOWNRIGHT);
				}
				else
				{
					playerInstance[x].setMovement(true);
					playerInstance[x].setDirection(DOWN);
				}
			}
			else
			{
			}

			// checks the X position and moves player accordingly
			if (playerPos[x][0] > startPositions[x][0])
			{
				playerInstance[x].setMovement(true);
				playerInstance[x].setDirection(LEFT);

			}
			else if (playerPos[x][0] < startPositions[x][0])
			{
				playerInstance[x].setMovement(true);
				playerInstance[x].setDirection(RIGHT);
			}
			else
			{
			}

			// checks the Y position and moves player accordingly
			if (playerPos[x][1] > startPositions[x][1])
			{
				playerInstance[x].setMovement(true);
				playerInstance[x].setDirection(DOWN);

			}
			else if (playerPos[x][1] < startPositions[x][1])
			{
				playerInstance[x].setMovement(true);
				playerInstance[x].setDirection(UP);
			}
			else
			{
			}



		}
	}

	gameS->setPlayerInstance(playerInstance);
}
