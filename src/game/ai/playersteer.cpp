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
    setMaxForce (3.7f);      // steering force is clipped to this magnitude

//    setMaxSpeed (10);         // velocity is clipped to this magnitude
    setMaxSpeed (.5f);         // velocity is clipped to this magnitude

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

	// if I hit the ball, kick it.
//    logMsg("playerSteerInstane size = " +Ogre::StringConverter::toString(playerSteerInstance.size()));
//    logMsg("pSteer size = " +Ogre::StringConverter::toString(pSteer.size()));

/*    for(int x=0;x<playerSteerInstance.size();++x)
    {
        logMsg("playerSteerInstane ID = " +Ogre::StringConverter::toString(playerSteerInstance[x]->getID()));
//        logMsg("playerSteerInstane radius = " +Ogre::StringConverter::toString(playerSteerInstance[x]->radius()));

    }
*/
	for(int x=0;x<pSteer.size();++x)
    {
//        logMsg("pSteer ID = " +Ogre::StringConverter::toString(pSteer[x]->getID()));
//        logMsg("pSteer radius = " +Ogre::StringConverter::toString(pSteer[x]->radius()));
//		logMsg("pSteer position = " +Ogre::StringConverter::toString(convertToOgreVector3(pSteer[x]->position())));


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

//            const float sumOfRadii = radius() + m_Ball->radius();
//            if (distToBall < sumOfRadii)
	if (distToBall < 2.0f)
	{
//                m_Ball->kick((bballSteerPos-playerSteerPos)*50, elapsedTime);
	}

	// otherwise consider avoiding collisions with others
//	OpenSteer::Vec3 collisionAvoidance = steerToAvoidNeighbors(1, (OpenSteer::AVGroup&)pSteer);
	playerSteer *allSteer = new playerSteer[pSteer.size()];
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
//	steerees = (OpenSteer::AVGroup&)pSteer;
//    logMsg("Dah");
//	steerees[0]->setRadius(0.5f);
//	logMsg("diii");
//	logMsg(toString(steerees[0]->radius()));
//	steerees.push_back((OpenSteer::AVGroup)playerSteerInstance[0]);
	OpenSteer::Vec3 collisionAvoidance = steerToAvoidNeighbors(1, steerees);
//	logMsg("Wahoo!");
	logMsg("collisionAvoidance = " +Ogre::StringConverter::toString(convertToOgreVector3(collisionAvoidance)));
//	exit(0);
	if(collisionAvoidance != OpenSteer::Vec3::zero)
	{
//	    applySteeringForce (collisionAvoidance, elapsedTime);
//	    exit(0);
	}
	else
	{
		float distHomeToBall = OpenSteer::Vec3::distance (m_home, bballSteerPos);
		logMsg("m_home = " +Ogre::StringConverter::toString(convertToOgreVector3(m_home)));
		logMsg("distHomeToBall = " +Ogre::StringConverter::toString(distHomeToBall));

		if (teamNumber != gameS->getTeamWithBall())
		{
			OpenSteer::Vec3 playerOPos;
			switch (teamNumber)
			{
				case 0:
					playerOPos = convertToOpenSteerVec3(team1PlayerInstance[ID].getNodePosition());
					if (playerSteerPos.x > playerOPos.x || playerSteerPos.x < playerOPos.x)
					{
						OpenSteer::Vec3 seekTarget = xxxsteerForSeek(playerOPos);
						applySteeringForce (seekTarget, elapsedTime);
						logMsg("Farting!");
					}
					break;
				case 1:
					playerOPos = convertToOpenSteerVec3(team0PlayerInstance[ID].getNodePosition());
					if (playerSteerPos.x > playerOPos.x || playerSteerPos.x < playerOPos.x)
					{
						OpenSteer::Vec3 seekTarget = xxxsteerForSeek(playerOPos);
						applySteeringForce (seekTarget, elapsedTime);
						logMsg("Barfing!");
					}
					break;
				default:
					break;
			}
		}
		else
		{
			Ogre::Vector3 *offenseStartPositions;
			OpenSteer::Vec3 startPosition;
			OpenSteer::Vec3 seekTarget;
			
			switch (teamNumber)
			{
				case 0:
					offenseStartPositions = teamInstance[0].getOffenseInstance()->getStartPositions();
					logMsg("Team 0 Player " +Ogre::StringConverter::toString(ID) +" Seeking Offense Start Position!");
					startPosition = convertToOpenSteerVec3(offenseStartPositions[ID]);
					seekTarget = xxxsteerForSeek(startPosition);
					applySteeringForce (seekTarget, elapsedTime);
					break;
				case 1:
					logMsg("Team 1 Player " +Ogre::StringConverter::toString(ID) +" Seeking Offense Start Position!");
					startPosition = convertToOpenSteerVec3(offenseStartPositions[ID]);
					logMsg("startPosition = " +Ogre::StringConverter::toString(offenseStartPositions[ID]));
					logMsg("current position = " +Ogre::StringConverter::toString(team1PlayerInstance[ID].getNodePosition()));
					seekTarget = xxxsteerForSeek(startPosition);
					applySteeringForce (seekTarget, elapsedTime);
					break;
				default:
					break;
			}
		}
//		exit(0);
/*		if( distHomeToBall < 12.0f)
		{
			// go for ball if I'm on the 'right' side of the ball
			if((teamNumber != gameS->getTeamWithBall()) ? playerSteerPos.x > bballSteerPos.x : playerSteerPos.x < bballSteerPos.x)
			{
				logMsg("Here?");
				OpenSteer::Vec3 seekTarget = xxxsteerForSeek(bballSteerPos);
				applySteeringForce (seekTarget, elapsedTime);
			}
			else
			{
				if( distHomeToBall < 12.0f)
				{
					logMsg("Here??");
					float Z = bballSteerPos.z - playerSteerPos.z > 0 ? -1.0f : 1.0f;
					OpenSteer::Vec3 behindBall = bballSteerPos + ((teamNumber == gameS->getTeamWithBall()) ? OpenSteer::Vec3(2.0f,0.0f,Z) : OpenSteer::Vec3(-2.0f,0.0f,Z));
					OpenSteer::Vec3 behindBallForce = xxxsteerForSeek(behindBall);
//FIXME					annotationLine (playerSteerPos, behindBall , OpenSteer::Color(0.0f,1.0f,0.0f));
					OpenSteer::Vec3 evadeTarget = xxxsteerForFlee(bballSteerPos);
					applySteeringForce (behindBallForce*10.0f + evadeTarget, elapsedTime);
				}
			}
		}
		else	// Go home
		{
			logMsg("Here???");
			OpenSteer::Vec3 seekTarget = xxxsteerForSeek(m_home);
			OpenSteer::Vec3 seekHome = xxxsteerForSeek(m_home);
			applySteeringForce (seekTarget+seekHome, elapsedTime);
		}
        logMsg("m_home = " +Ogre::StringConverter::toString(convertToOgreVector3(m_home)));
		logMsg("position = " +Ogre::StringConverter::toString(convertToOgreVector3(position())));

//        exit(0);
*/
	}

	// moves the player model and physics body
	btVector3 physBodyChange; // = btVector3(0,0,0);
	btTransform physBodyTransform;

	// updates player's position
	Ogre::Vector3 posChange = convertToOgreVector3(position());
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
