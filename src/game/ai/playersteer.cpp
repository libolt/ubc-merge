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

#include "playersteer.h"
#include "ai.h"
#include "gamestate.h"
#include "logging.h"
#include "playerstate.h"
#include "teamstate.h"


playerSteer::~playerSteer()
{

}


int playerSteer::getTeamNumber() // retrieves the value of team
{
	return (teamNumber);
}
void playerSteer::setTeamNumber(int team) // sets the value of team
{
	teamNumber = team;
}

int playerSteer::getID() // retrieves the value of ID
{
	return (ID);
}
void playerSteer::setID(int id) // sets the value of ID
{
	ID = id;
}

// reset state
void playerSteer::reset(void)
{
    steering::reset (); // reset the vehicle
    setSpeed (0.0f);         // speed along Forward direction.
//    setMaxForce (3000.7f);      // steering force is clipped to this magnitude
    setMaxForce (.7f);      // steering force is clipped to this magnitude

//    setMaxSpeed (10);         // velocity is clipped to this magnitude
    setMaxSpeed (.05);         // velocity is clipped to this magnitude

//	logMsg("teamNumber = " +Ogre::StringConverter::toString(teamNumber));

	if (teamNumber >= 0)
	{
	    gameState *gameS = gameState::Instance();
	    std::vector<teamState> teamInstance = gameS->getTeamInstance();
	    std::vector<playerState> playerInstance = teamInstance[teamNumber].getPlayerInstance();
	    OpenSteer::Vec3 playerSteerPos;

        if(ID < 9 && ID >= 0)
        {
	        if (gameS->getTipOffComplete())
	        {
		        playerSteerPos = convertToOpenSteerVec3(playerInstance[ID].getNodePosition());
	        }
	        else
	        {
		        playerSteerPos.x = 0;
		        playerSteerPos.y = 0;
		        playerSteerPos.z = 0;
	        }
    // Place me on my part of the field, looking at oponnents goal
//    setPosition(b_ImTeamA ? OpenSteer::frandom01()*20 : -OpenSteer::frandom01()*20, 0, (OpenSteer::frandom01()-0.5f)*20);

//        if(b_ImTeamA)
//		{

                setPosition(playerSteerPos);
/*		}
        else
		{
            setPosition(OpenSteer::Vec3(-playerSteerPos.x, playerSteerPos.y, playerSteerPos.z));
		}
*/
        }
	    /*OpenSteer::Vec3*/ m_home = playerSteerPos;
//		exit(0);
	}
//    m_home = position();
 //   AnnotationMixin::clearTrailHistory ();    // prevent long streaks due to teleportation
//    OpenSteer::clearTrailHistory ();
//    setTrailParameters (10, 60);
}

void playerSteer::update (const float /*currentTime*/, float elapsedTime)
{
	logMsg("Updating playerSteer state");

//	exit(0);
	counter += 1;
	logMsg("Counter = " +Ogre::StringConverter::toString(counter));

	logMsg("elapsedTime = " +Ogre::StringConverter::toString(elapsedTime));

	AISystem *ai = AISystem::Instance();
	gameState *gameS = gameState::Instance();
	std::vector<basketballs> basketball = gameS->getBasketballInstance();
	std::vector<teamState> teamInstance = gameS->getTeamInstance();
	std::vector<playerState> team0PlayerInstance = teamInstance[0].getPlayerInstance();
	std::vector<playerState> team1PlayerInstance = teamInstance[1].getPlayerInstance();
//	std::vector<playerSteer*> playerSteerInstance;
	std::vector<playerSteer*> pSteer = ai->getAllPlayerSteers();
	std::vector<playerSteer*> team0Steers;
	std::vector<playerSteer*> team1Steers;

	logMsg("teamNumber = " +Ogre::StringConverter::toString(teamNumber));

    for (int x=0;x<team0PlayerInstance.size();++x)
	{
//		playerSteerInstance.push_back(team0PlayerInstance[0].getSteer());

//		playerSteerInstance.push_back(team0PlayerInstance[x].getSteer());
		team0Steers.push_back(team0PlayerInstance[x].getSteer());
//		playerSteerInstance.push_back(team0PlayerInstance[2].getSteer());

	}

    for (int x=0;x<team1PlayerInstance.size();++x)
	{
//		playerSteerInstance.push_back(team1PlayerInstance[x].getSteer());
		team1Steers.push_back(team1PlayerInstance[x].getSteer());

	}

	OpenSteer::Vec3 playerSteerPos;
	switch (teamNumber)
	{
		case 0:
			playerSteerPos = convertToOpenSteerVec3(team0PlayerInstance[ID].getNodePosition());
			break;
		case 1:
			playerSteerPos = convertToOpenSteerVec3(team1PlayerInstance[ID].getNodePosition());
			break;
		default:
			break;
	}

	//OpenSteer::Vec3 m_home = playerSteerPos;
	OpenSteer::Vec3 bballSteerPos = convertToOpenSteerVec3(basketball[0].getNodePosition());

// 	logMsg("playerSteerPos = " +Ogre::StringConverter::toString(convertToOgreVector3(playerSteerPos)));
//	logMsg("basketballSteerPos = " +Ogre::StringConverter::toString(convertToOgreVector3(bballSteerPos)));


	const float distToBall = OpenSteer::Vec3::distance (playerSteerPos, bballSteerPos);
//	logMsg("distToBall = " +Ogre::StringConverter::toString(distToBall));

	playerSteer *allSteer;

	if (allSteer == NULL)
	{
		allSteer= new playerSteer[pSteer.size()];
	}
/*	for (int x=0;x<pSteer.size();++x)
	{
		logMsg(Ogre::StringConverter::toString(x));
		logMsg(Ogre::StringConverter::toString(pSteer[x]->radius()));

		allSteer[x] = pSteer[x];
	}
*/
//	logMsg("dee");
	OpenSteer::AVGroup steerees; // = new OpenSteer::AVGroup[10];
//    logMsg("doo");
	// checks against players of other team
	switch (teamNumber)
	{
		case 0:
			steerees = (OpenSteer::AVGroup&)team0Steers;

			break;
		case 1:
			steerees = (OpenSteer::AVGroup&)team1Steers;
			break;
		default:
			break;
	}

	OpenSteer::Vec3 collisionAvoidance = steerToAvoidNeighbors(1, steerees);

	//	logMsg("Wahoo!");
//	logMsg("collisionAvoidance = " +Ogre::StringConverter::toString(convertToOgreVector3(collisionAvoidance)));
//	exit(0);
//	if(collisionAvoidance != OpenSteer::Vec3::zero)
	if (collisionAvoidance.x == 9999)
	{
		logMsg("Yyyyyeeearrrgh");
//	    applySteeringForce (collisionAvoidance, elapsedTime);
//	    exit(0);
	}
	else
	{

		float distHomeToBall = OpenSteer::Vec3::distance (m_home, bballSteerPos);
//		logMsg("m_home = " +Ogre::StringConverter::toString(convertToOgreVector3(m_home)));
//		logMsg("distHomeToBall = " +Ogre::StringConverter::toString(distHomeToBall));
		if (teamNumber != gameS->getTeamWithBall())
		{
			OpenSteer::Vec3 playerOPos;
			OpenSteer::Vec3 seekTarget;
			float distPlayerOPosition;

			switch (teamNumber)
			{
				case 0:
					playerOPos = convertToOpenSteerVec3(team1PlayerInstance[ID].getNodePosition());
					break;
				case 1:
					playerOPos = convertToOpenSteerVec3(team0PlayerInstance[ID].getNodePosition());
					break;
				default:
					break;
			}
			distPlayerOPosition = OpenSteer::Vec3::distance (playerOPos, position());
			logMsg("Distance to playerOPos = " +Ogre::StringConverter::toString(distPlayerOPosition));
			if (distPlayerOPosition >= 1)
			{
				logMsg("seeking!");
				seekTarget = xxxsteerForSeek(playerOPos);
				logMsg("seekTarget = " +Ogre::StringConverter::toString(convertToOgreVector3(playerOPos)));
				applySteeringForce (seekTarget, elapsedTime);
			}
		}
		else
		{
			bool *startPositionSet = teamInstance[teamNumber].getOffenseInstance()->getStartPositionSet();

			if (!startPositionSet[ID])
			{
			    Ogre::Vector3 *offenseStartPositions;
			    OpenSteer::Vec3 startPosition;
			    OpenSteer::Vec3 seekTarget;
			    float distPlayerStartPosition;

			    offenseStartPositions = teamInstance[teamNumber].getOffenseInstance()->getStartPositions();
			    logMsg("Team " +Ogre::StringConverter::toString(teamNumber) +" Player " +Ogre::StringConverter::toString(ID) +" Seeking Offense Start Position!");
			    startPosition = convertToOpenSteerVec3(offenseStartPositions[ID]);
			    logMsg("startPosition = " +Ogre::StringConverter::toString(offenseStartPositions[ID]));
			    logMsg("current position = " +Ogre::StringConverter::toString(team1PlayerInstance[ID].getNodePosition()));
			    distPlayerStartPosition = OpenSteer::Vec3::distance (startPosition, position());
			    logMsg("Distance to startPosition = " +Ogre::StringConverter::toString(distPlayerStartPosition));
			    if (distPlayerStartPosition >= 1)
			    {
				    logMsg("seeking!");
				    seekTarget = xxxsteerForSeek(startPosition);
				    logMsg("seekTarget = " +Ogre::StringConverter::toString(convertToOgreVector3(startPosition)));
				    applySteeringForce (seekTarget, elapsedTime);
			    }
				else
				{
					startPositionSet[ID] = true;
				}
			}
			else
			{
			    std::vector< std::vector<Ogre::Vector3> > offenseExecutePositions;
			    OpenSteer::Vec3 executePosition;
			    OpenSteer::Vec3 seekTarget;
			    float distPlayerExecutePosition;

			    offenseExecutePositions = teamInstance[teamNumber].getOffenseInstance()->getExecutePositions();
			    logMsg("Team " +Ogre::StringConverter::toString(teamNumber) +" Player " +Ogre::StringConverter::toString(ID) +" Seeking Offense Execute Position!");
			    executePosition = convertToOpenSteerVec3(offenseExecutePositions[ID][0]);
			    logMsg("executePosition = " +Ogre::StringConverter::toString(offenseExecutePositions[ID][0]));
			    logMsg("current position = " +Ogre::StringConverter::toString(team1PlayerInstance[ID].getNodePosition()));
			    distPlayerExecutePosition = OpenSteer::Vec3::distance (executePosition, position());
			    logMsg("Distance to executePosition = " +Ogre::StringConverter::toString(distPlayerExecutePosition));
			    if (distPlayerExecutePosition >= 1)
			    {
				    logMsg("seeking!");
				    seekTarget = xxxsteerForSeek(executePosition);
				    logMsg("seekTarget = " +Ogre::StringConverter::toString(convertToOgreVector3(executePosition)));
				    applySteeringForce (seekTarget, elapsedTime);
			    }
			}
		}

//		exit(0);
	}

	// moves the player model and physics body
	btVector3 physBodyChange; // = btVector3(0,0,0);
	btTransform physBodyTransform;

	// updates player's position
	Ogre::Vector3 posChange = convertToOgreVector3(position());
			Ogre::Vector3 *offenseStartPositions;
			OpenSteer::Vec3 startPosition;
			OpenSteer::Vec3 seekTarget;
			float distPlayerStartPosition;
    switch (teamNumber)
	{
	    case 0:
			team0PlayerInstance[ID].getNode()->setPosition(posChange);
			physBodyChange = BtOgre::Convert::toBullet(posChange); // converts from Ogre::Vector3 to btVector3
			physBodyTransform.setOrigin(physBodyChange);
			team0PlayerInstance[ID].getPhysBody()->setWorldTransform(physBodyTransform);
			teamInstance[0].setPlayerInstance(team0PlayerInstance);
			break;
		case 1:
			logMsg("ID = " +Ogre::StringConverter::toString(ID));
			logMsg("posChange = " +Ogre::StringConverter::toString(posChange));
//			exit(0);
			team1PlayerInstance[ID].getNode()->setPosition(posChange);
			physBodyChange = BtOgre::Convert::toBullet(posChange); // converts from Ogre::Vector3 to btVector3
			physBodyTransform.setOrigin(physBodyChange);
			team1PlayerInstance[ID].getPhysBody()->setWorldTransform(physBodyTransform);
			teamInstance[1].setPlayerInstance(team1PlayerInstance);
			break;
		default:
		    break;
	}

}
