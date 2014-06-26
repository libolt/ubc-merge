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
#include "load.h"
#include "logging.h"
#include "playerstate.h"
#include "playersteer.h"
#include "teamstate.h"

offenseState::offenseState() // constructor
{
	selectedOffense = NULL; // sets the default offense to box
	execute = false;
	offenseSet = false;
/*	startPositions = new Ogre::Vector3[5];

	for (int x=0; x<5; ++x)
	{
		startPositions[x]	= Ogre::Vector3(0.0f,0.0f,0.0f);

	}
*/
//    startPositions[4]	= Ogre::Vector3(3000.0f,-1300.5f,3780.0f);

//	executePositions = new std::vector<Ogre::Vector3>[5];
//	executePositions[0] = new std::vector<Ogre::Vector3>;
//	exit(0);

    executePositions.resize(5);

	startXPosSet = new bool[5];
	startYPosSet = new bool[5];
	startZPosSet = new bool[5];

	allStartPositionsReached = false;
    allExecutePositionsReached = false;

//	executePositionSet = new bool[5];

	for (int x=0;x<5;++x)
	{
		startXPosSet[x] = false;
		startYPosSet[x] = false;
		startZPosSet[x] = false;
		startPositionReached.push_back(false);
//		executePositionSet[x] = false;
	}
	numStartPositionsReached = 0;
	offenseSetup = false;
	loadPlays();
}

int offenseState::getSelectedOffense() // returns value of selectedOffense
{
	return (selectedOffense);
}
void offenseState::setSelectedOffense(int selected) // sets the value of selectedOffense
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

std::vector<offensePlays> offenseState::getPlays()	// returns the value of plays
{
	return (plays);
}
void offenseState::setPlays(std::vector<offensePlays> play)	// sets the value of plays
{
	plays = play;
}

std::vector<Ogre::Vector3> offenseState::getStartPositions()	// retrieves startPositions variable
{
	return (startPositions);
}

void offenseState::setStartPositions(std::vector<Ogre::Vector3> positions)	// sets startPositions
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

std::vector<bool> offenseState::getStartPositionReached()  // returns the value of startPositionReached
{
	return (startPositionReached);
}
void offenseState::setStartPositionReached(std::vector<bool> reached) // sets the value of startPositionReached
{
	startPositionReached = reached;
}

bool offenseState::getAllStartPositionsReached() // retrieves the value of allStartPositionsReached
{
	return (allStartPositionsReached);
}
void offenseState::setAllStartPositionsReached(bool reached)  // sets the value of allStartPositionsReached
{
	allStartPositionsReached = reached;
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
//	startPositions[0] = Ogre::Vector3(5.0f,-13.5f,380.0f);
}

void offenseState::updateState(int teamNumber)	// updates the state of the object
{
	gameState *gameS = gameState::Instance();
    std::vector<teamState> teamInstance = gameS->getTeamInstance();
    std::vector<playerState> playerInstance = teamInstance[teamNumber].getPlayerInstance();

    if (!offenseSetup)
    {
    	setupOffense();
    }
	else
	{
		executeOffense();
	}
	teamInstance[teamNumber].setPlayerInstance(playerInstance);
    gameS->setTeamInstance(teamInstance);
}

void offenseState::loadPlays()	// loads offense plays from file
{

	loader *load = loader::Instance();
	plays = load->loadOffensePlays();
}



void offenseState::setupOffense() // sets up box offense
{
	logMsg("plays.size() = " +Ogre::StringConverter::toString(plays.size()));
	for (int x=0;x<plays.size();++x)
	{
		if (plays[x].getPlayName() == "Box")  // sets up the Box offense3
		{
			startPositions = plays[x].getStartPositions();
			executePositions = plays[x].getExecutePositions();
		}
	}

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
	offenseSetup = true;
}


void offenseState::executeOffense() // executes box offense
{
	gameState *gameS = gameState::Instance();
    std::vector<teamState> teamInstance = gameS->getTeamInstance();
    std::vector<playerState> playerInstance = teamInstance[gameS->getTeamWithBall()].getPlayerInstance();

	int teamNumber = gameS->getTeamWithBall();
	int playerWithBall = teamInstance[teamNumber].getPlayerWithBall();
	playerSteer *pSteer;

    if (!allStartPositionsReached)	// checks if all players have reached their start positions for the offense being run
	{
    	for (int x=0;x<5;++x)
		{
			if ( x != playerWithBall)
			{
    		    pSteer = playerInstance[x].getSteer();
			    std::vector<bool> positionReached = pSteer->getPositionReached();
			    if (positionReached.size() != 1)
			    {
				    positionReached.push_back(false);
				    pSteer->setPositionReached(positionReached);
			    }

		        if (!startPositionReached[x])  // checks if each player has reached the start position
		        {
				    std::vector<Ogre::Vector3> steerCoords = plays[0].getStartPositions();
				    OpenSteer::Vec3 coords = pSteer->convertToOpenSteerVec3(startPositions[x]);
				    pSteer->setSteerCoords(coords);
					pSteer->setExecute(true);
		        }
		        else	// increments the counter
		        {
//				numStartPositionsReached += 1;
                    pSteer->setExecute(false);
			    }

			    if (numStartPositionsReached == 4)	// FIXME: hard coded for a human player
			    {
//				exit(0);
				    allStartPositionsReached = true;
			    }
		        if (!startPositionReached[x] && pSteer->getDistToPosition() < 3 && pSteer->getDistToPosition() != -1.0f)
			    {
					
		    	    startPositionReached[x] = true;
				    numStartPositionsReached += 1;
					pSteer->setExecute(false);
			    }
			    logMsg("startPositionsReached = " +Ogre::StringConverter::toString(startPositionReached[x]));
			}
	    }
	}
	else
	{
//		exit(0);
		if (!allExecutePositionsReached)
		{
//			exit(0);
			int allExecutionsReached = 0;
		    for (int ID=0;ID<5;++ID)
		    {
				if (allExecutionsReached < 4)
				{
				    
			        if (ID != playerWithBall)
			        {
						
			            pSteer = playerInstance[ID].getSteer();
				        logMsg("Player " +Ogre::StringConverter::toString(ID) +" executePositionReached size = " +Ogre::StringConverter::toString(executePositionReached[ID].size()));
			            for (int x=0;x<executePositionReached[ID].size();++x)
			            {
				            if (executePositionReached[ID][x] == true)
				            {
				    	        logMsg("Player " +Ogre::StringConverter::toString(ID));
//	    		                exit(0);
				            }
				            else
				            {   int lastPos = executePositionReached[ID].size() - 1;
				                if (executePositionReached[ID][lastPos])
				    		    {
									allExecutionsReached += 1;
							    }
					            // checks if previous position was reached
					            else if ( x > 0 && !executePositionReached[ID][x - 1])
					            {
//					    	        exit(0);
//						        break;
					            }
					            else //if (!executePositionReached[ID][x])
					            {
						            logMsg("Team " +Ogre::StringConverter::toString(teamNumber) +" Player " +Ogre::StringConverter::toString(ID) +" Seeking Offense Execute Position!");
					  	            OpenSteer::Vec3 executePosition = pSteer->convertToOpenSteerVec3(executePositions[ID][x]);
						            pSteer->setSteerCoords(executePosition);
							        if (pSteer->getDistToPosition() < 3 && pSteer->getDistToPosition() != -1.0f)
							        {
								    //    exit(0);
								        executePositionReached[ID][x] = true;
										pSteer->setExecute(false);
							        }
									else
									{
										exit(0);
										pSteer->setExecute(true);
									}
					            }
					        }
							
				        }
			        }
			    }
				else
				{
					allExecutePositionsReached = true;
				}
		    }
		}
		else
		{
			for (int x=0;x<5;++x)
			{
				pSteer = playerInstance[x].getSteer();
				pSteer->setExecute(false);
				playerInstance[x].setSteer(pSteer);
				
			}
		}
//			exit(0);
	}

}
