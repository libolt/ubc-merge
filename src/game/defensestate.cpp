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

#include "defensestate.h"
#include "gamestate.h"
#include "logging.h"
#include "teamstate.h"

defenseState::defenseState() // constructor
{
	execute = false;
}

bool defenseState::getExecute()	// retrieves the value of execute variable
{
	return (execute);
}
void defenseState::setExecute(bool ex)	// sets the value of the execute variable
{
	execute = ex;
}

void defenseState::setupState()		// sets up initial state of the object
{

}
void defenseState::updateState(int teamNumber)	// updates the state of the object
{
	gameState *gameS = gameState::Instance();

	int teamWithBall = gameS->getTeamWithBall();

	std::vector<teamState> teamInstance = gameS->getTeamInstance();
    std::vector<playerState> playerDInstance = teamInstance[teamNumber].getPlayerInstance();
    std::vector<playerState> playerOInstance = teamInstance[teamWithBall].getPlayerInstance();
    int humanPlayer = teamInstance[teamNumber].getHumanPlayer();
//	exit(0);
	if (execute)
	{
//	    exit(0);
	    std::vector<Ogre::Vector3> playerOPos;  // stores positions of offensive players
		for (int x=0;x<playerOInstance.size();++x)
		{
			playerOPos.push_back(playerOInstance[x].getNode()->getPosition());
		}

		std::vector<Ogre::Vector3> playerDPos;  // stores positions of defensive players
		for (int x=0;x<playerDInstance.size();++x)
		{
			playerDPos.push_back(playerDInstance[x].getNode()->getPosition());
		}

	    for (int x=0;x<playerDInstance.size();++x)
		{
			if (x != humanPlayer && !playerDInstance[x].getDefenseSet())
			{
	            logMsg("playerO " +Ogre::StringConverter::toString(x) +"X Pos = " +Ogre::StringConverter::toString(playerOPos[x][0]));
	            logMsg("playerD " +Ogre::StringConverter::toString(x) +"X Pos = " +Ogre::StringConverter::toString(playerDPos[x][0]));
	            logMsg("playerO " +Ogre::StringConverter::toString(x) +"Z Pos = " +Ogre::StringConverter::toString(playerOPos[x][2]));
	            logMsg("playerD " +Ogre::StringConverter::toString(x) +"Z Pos = " +Ogre::StringConverter::toString(playerDPos[x][2]));
	            directions playerDirection = playerOInstance[x].getDirection();
	            switch (playerDirection)
	            {
	            case LEFT:
	            	if (playerDPos[x][0] >= (playerOPos[x][0] + 4.0f))
	            	{
	            		playerDInstance[x].setMovement(true);
	            		playerDInstance[x].setDirection(LEFT);
	            	}
	            	else if (playerDPos[x][0] <= (playerOPos[x][0] - 4.0f))
	            	{
	            		playerDInstance[x].setMovement(true);
	            		playerDInstance[x].setDirection(RIGHT);
	            	}
	            	break;
	            case RIGHT:
	            	if (playerDPos[x][0] <= (playerOPos[x][0] + 4.0f))
	            	{
	            		playerDInstance[x].setMovement(true);
	            		playerDInstance[x].setDirection(RIGHT);
	            	}
	            	else if (playerDPos[x][0] >= (playerOPos[x][0] - 4.0f))
	            	{
	            		playerDInstance[x].setMovement(true);
	            		playerDInstance[x].setDirection(LEFT);
	            	}
	            	break;
	            case UP:
	            	if (playerDPos[x][2] >= (playerOPos[x][2] - 1.0f))
	            	{
	            		playerDInstance[x].setMovement(true);
	            		playerDInstance[x].setDirection(UP);
	            	}
	            	else if (playerDPos[x][2] <= (playerOPos[x][2] + 1.0f))
	            	{
	            		playerDInstance[x].setMovement(true);
	            		playerDInstance[x].setDirection(DOWN);
	            	}
	            	break;
	            case DOWN:
	            	if (playerDPos[x][2] <= (playerOPos[x][2] + 1.0f))
	            	{
	            		playerDInstance[x].setMovement(true);
	            		playerDInstance[x].setDirection(DOWN);
	            	}
	            	else if (playerDPos[x][2] >= (playerOPos[x][2] - 1.0f))
	            	{
	            		playerDInstance[x].setMovement(true);
	            		playerDInstance[x].setDirection(UP);

	            	}
	            	break;
	            case UPLEFT:
	            	if (playerDPos[x][2] >= (playerOPos[x][2] - 1.0f) && playerDPos[x][0] >= (playerOPos[x][0] + 4.0f))
	            	{
	            		playerDInstance[x].setMovement(true);
	            		playerDInstance[x].setDirection(UPLEFT);
	            	}
	            	else if (playerDPos[x][2] <= (playerOPos[x][2] + 1.0f) && playerDPos[x][0] <= (playerOPos[x][0] - 4.0f))
	            	{
	            		playerDInstance[x].setMovement(true);
	            		playerDInstance[x].setDirection(DOWNRIGHT);
	            	}
	            	break;
	            case UPRIGHT:
	            	if (playerDPos[x][2] >= (playerOPos[x][2] - 1.0f) && playerDPos[x][0] <= (playerOPos[x][0] + 4.0f))
	            	{
	            		playerDInstance[x].setMovement(true);
	            		playerDInstance[x].setDirection(UPRIGHT);
	            	}
	            	else if (playerDPos[x][2] <= (playerOPos[x][2] + 1.0f) && playerDPos[x][0] >= (playerOPos[x][0] - 4.0f))
	            	{
	            		playerDInstance[x].setMovement(true);
	            		playerDInstance[x].setDirection(DOWNLEFT);
	            	}
	            	break;
	            case DOWNLEFT:
	            	if (playerDPos[x][2] <= (playerOPos[x][2] + 1.0f) && playerDPos[x][0] >= (playerOPos[x][0] + 4.0f))
	            	{
	            		playerDInstance[x].setMovement(true);
	            		playerDInstance[x].setDirection(DOWNLEFT);
	            	}
	            	else if (playerDPos[x][2] >= (playerOPos[x][2] - 1.0f) && playerDPos[x][0] <= (playerOPos[x][0] - 4.0f))
	            	{
	            		playerDInstance[x].setMovement(true);
	            		playerDInstance[x].setDirection(UPRIGHT);
	            	}
	            	break;
	            case DOWNRIGHT:
	            	if (playerDPos[x][2] <= (playerOPos[x][2] + 1.0f) && playerDPos[x][0] <= (playerOPos[x][0] + 4.0f))
	            	{
	            		playerDInstance[x].setMovement(true);
	            		playerDInstance[x].setDirection(DOWNRIGHT);
	            	}
	            	else if (playerDPos[x][2] >= (playerOPos[x][2] - 1.0f) && playerDPos[x][0] >= (playerOPos[x][0] - 4.0f))
	            	{
	            		playerDInstance[x].setMovement(true);
	            		playerDInstance[x].setDirection(UPLEFT);
	            	}
	            	break;
	            default:
	            	playerDInstance[x].setMovement(false);
	            	break;
	            }
/*
	            // checks to see if its the defense is in position
                if (playerDPos[x][0] > (playerOPos[x][0] -4.0f) || playerDPos[x][0] < (playerOPos[x][0] +4.0f))
		        {
//					exit(0);
			        if (playerDPos[x][0] > (playerOPos[x][0] -4.0f))
					{
//						exit(0);
			            Ogre::LogManager::getSingletonPtr()->logMessage("DEEEEE");

						playerDInstance[x].setMovement(true);
						playerDInstance[x].setDirection(LEFT);
					}
					else if (playerDPos[x][0] < (playerOPos[x][0] +4.0f))
					{
//						exit(0);
						playerDInstance[x].setMovement(true);
						playerDInstance[x].setDirection(RIGHT);
					}
					else
					{
						playerDInstance[x].setMovement(false);
					}
		        }
		        else if (playerDPos[x][0] >= (playerOPos[x][0] -4.0f) && playerDPos[x][0] <= (playerOPos[x][0] +4.0f))
		        {
//					exit(0);
			        playerDInstance[x].setDefenseSet(true);
		        }
*/
			}
			else
			{
			}
		}
	}

    teamInstance[teamNumber].setPlayerInstance(playerDInstance);
    gameS->setTeamInstance(teamInstance);

}
