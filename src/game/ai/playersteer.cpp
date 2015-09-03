/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean   *
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
#include "network.h"

#include "playersteer.h"
#include "ai.h"
#include "conversion.h"
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

playerPositions playerSteer::getPlayerPosition()  // retrieves the value of position
{
    return (playerPosition);
}
void playerSteer::setPlayerPosition(playerPositions set)  // sets the value of position
{
    playerPosition = set;
}

float playerSteer::getDistToPosition() // retrieves the value of distToPosition
{
	return (distToPosition);
}
void playerSteer::setDistToPosition(float dist) // sets value of distToPosition
{
	distToPosition = dist;
}

bool playerSteer::getExecute()  // retrieves the value of execute
{
	return (execute);
}
void playerSteer::setExecute(bool set)  // sets the value of execute
{
	execute = set;
}

OpenSteer::Vec3 playerSteer::getSteerCoords()  // retrieves the value of steerCoords
{
	return (steerCoords);
}
void playerSteer::setSteerCoords(OpenSteer::Vec3 coords)  // sets the value of steerCoords
{
	steerCoords = coords;
}

std::vector<bool> playerSteer::getPositionReached()  // retrieves the value of positionReached
{
	return (positionReached);
}
void playerSteer::setPositionReached(std::vector<bool> reached)  // sets the value of positionReached
{
	positionReached = reached;
}

// reset state
void playerSteer::reset(void)
{
    boost::shared_ptr<conversion> convert = conversion::Instance();

    steering::reset (); // reset the vehicle
    setSpeed (0.0f);         // speed along Forward direction.
//    setMaxForce (3000.7f);      // steering force is clipped to this magnitude
    setMaxForce (30.0f);      // steering force is clipped to this magnitude

//    setMaxSpeed (10);         // velocity is clipped to this magnitude
    setMaxSpeed (20.0f);         // velocity is clipped to this magnitude

//	logMsg("teamNumber = " +convert->toString(teamNumber));

	if (teamNumber >= 0)
	{
	    //gameState *gameS = gameState::Instance();
        boost::shared_ptr<gameState> gameS = gameState::Instance();
        
	    std::vector<teamState> teamInstance = gameS->getTeamInstance();
        std::vector<playerState> activePlayerInstance = teamInstance[teamNumber].getActivePlayerInstance();
	    OpenSteer::Vec3 playerSteerPos;
        std::vector< std::vector<int> > teamStarterID = gameS->getTeamStarterID();
        if(ID < 9 && ID >= 0)
        {
//	        if (gameS->getTipOffComplete())
//	        {
//		        playerSteerPos = toOpenSteerVec3(activePlayerInstance[ID].getNodePosition());
/*	        }
	        else
	        {
	        	exit(0);
*/
                // sets the start steering positions to that of the player's node
            for (size_t x = 0; x<5; ++x)
            {
                logMsg("teamStarterSteerID = " +convert->toString(teamStarterID[teamNumber][x]));
            }
                playerSteerPos.x = 0.0;
                playerSteerPos.y = 0.0;
                playerSteerPos.z = 0.0;
/*	        }
*/
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

void playerSteer::update (const float currentTime, float elapsedTime)
{
    boost::shared_ptr<AISystem> ai = AISystem::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();

    logMsg("Updating playerSteer state");

//	exit(0);
	counter += 1;
//	logMsg("Counter = " +convert->toString(counter));

//	logMsg("elapsedTime = " +convert->toString(elapsedTime));

	std::vector<basketballs> basketball = gameS->getBasketballInstance();
	std::vector<teamState> teamInstance = gameS->getTeamInstance();
    std::vector<playerState> team0ActivePlayerInstance = teamInstance[0].getActivePlayerInstance();
    std::vector<playerState> team1ActivePlayerInstance = teamInstance[1].getActivePlayerInstance();
    std::vector<int> team0ActivePlayerID = teamInstance[0].getActivePlayerID();
    std::vector<int> team1ActivePlayerID = teamInstance[1].getActivePlayerID();
//	std::vector<playerSteer*> playerSteerInstance;
	std::vector<playerSteer*> pSteer = ai->getAllPlayerSteers();
	std::vector<playerSteer*> team0Steers;
	std::vector<playerSteer*> team1Steers;
//    logMsg("Player = " +convert->toString(ID));
//	logMsg("Node position = " +convert->toString(teamInstance[teamNumber].getActivePlayerInstance()[ID].getNodePosition()));
//	logMsg("Steer position = " +convert->toString(toOgreVector3(position())));
    logMsg("Team = " +convert->toString(teamNumber));
    logMsg("ID = " +convert->toString(ID));
//    OpenSteer::Vec3 currentNodePos = toOpenSteerVec3(teamInstance[teamNumber].getActiePlayerInstance()[ID].getNodePosition());

/*	if (position().x != currentNodePos.x || position().y != currentNodePos.y || position().z != currentNodePos.z)
	{
		exit(0);
	}
*/
    logMsg("teamNumber = " +convert->toString(teamNumber));

    size_t x = 0;
  
    while (x < team0ActivePlayerInstance.size())
    {
        if (team0ActivePlayerInstance[x].getInitialized())
        {

        logMsg("upDie?");
//		playerSteerInstance.push_back(team0ActivePlayerInstance[0].getSteer());

//		playerSteerInstance.push_back(team0ActivePlayerInstance[x].getSteer());
                team0Steers.push_back(team0ActivePlayerInstance[x].getSteer());
//		playerSteerInstance.push_back(team0ActivePlayerInstance[2].getSteer());
            }

        ++x;
    }


//    for (int x=0;x<team1ActivePlayerInstance.size();++x)
//	{
    x = 0;
    while (x < team1ActivePlayerInstance.size())
    {
        if (team1ActivePlayerInstance[x].getInitialized())
        {
            logMsg("upDie??");
            logMsg("team1Steers size = " +convert->toString(team1Steers.size()));
            logMsg("team1ActivePlayerInstance size = " +convert->toString(team1ActivePlayerInstance.size()));
            logMsg("x == " +convert->toString(x));
//		playerSteerInstance.push_back(team1ActivePlayerInstance[x].getSteer());
            team1Steers.push_back(team1ActivePlayerInstance[x].getSteer());
            logMsg("Nope!");     
        }
        ++x;
    }
	
	OpenSteer::Vec3 playerSteerPos;
	switch (teamNumber)
	{
		case 0:
            logMsg("activeID size = " +convert->toString((team0ActivePlayerID.size())));
            logMsg("do");
//            logMsg("activeID num = " +convert->toString(team0ActivePlayerID[ID]));
            x = 0;
            while (x < team0ActivePlayerInstance.size())
            {
                if (team0ActivePlayerInstance[x].getInitialized())
                {
                    logMsg("upDie???");
                    playerSteerPos = convert->toOpenSteerVec3(team0ActivePlayerInstance[x].getCourtPosition());
                    logMsg("nope!");
                }
                ++x;
            }
			break;
		case 1:
            logMsg("activeID size = " +convert->toString((team1ActivePlayerID.size())));
            logMsg("team 1 ID = " +convert->toString(ID));
//            logMsg("activeID num = " +convert->toString(team1ActivePlayerID[ID]));
            x = 0;
            while (x < team1ActivePlayerInstance.size())
            {
                logMsg("TEEE");
                if (team1ActivePlayerInstance[x].getInitialized())
                {
                    logMsg("upDie????");
                    playerSteerPos = convert->toOpenSteerVec3(team1ActivePlayerInstance[x].getCourtPosition());
                }
                ++x;
            }
            break;
		default:
			break;
	}

	//OpenSteer::Vec3 m_home = playerSteerPos;
    OpenSteer::Vec3 bballSteerPos = convert->toOpenSteerVec3(basketball[0].getNodePosition());
    logMsg("upDie?????");
// 	logMsg("playerSteerPos = " +convert->toString(toOgreVector3(playerSteerPos)));
//	logMsg("basketballSteerPos = " +convert->toString(toOgreVector3(bballSteerPos)));


	const float distToBall = OpenSteer::Vec3::distance (playerSteerPos, bballSteerPos);
//	logMsg("distToBall = " +convert->toString(distToBall));
    logMsg("upDie??????");
    logMsg("dee");
/*playerSteer *allSteer;

	if (allSteer == NULL)
	{
		allSteer= new playerSteer[pSteer.size()];
	}*/
/*	for (int x=0;x<pSteer.size();++x)
	{
        logMsg(convert->toString(x));
        logMsg(convert->toString(pSteer[x]->radius()));

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
    logMsg("upDie???????");
    logMsg("blah");
	OpenSteer::Vec3 collisionAvoidance = steerToAvoidNeighbors(1, steerees);
    logMsg("nope");
	//	logMsg("Wahoo!");
//	logMsg("collisionAvoidance = " +convert->toString(toOgreVector3(collisionAvoidance)));
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
//		logMsg("m_home = " +convert->toString(toOgreVector3(m_home)));
//		logMsg("distHomeToBall = " +convert->toString(distHomeToBall));
		if (teamNumber != gameS->getTeamWithBall())
		{
           // updateDefense(currentTime, elapsedTime);
		}
		else
		{
			if (execute)
			{
//				exit(0);
                updateOffense(currentTime, elapsedTime);
			}
		}

//		exit(0);
	}

	// moves the player model and physics body
	btVector3 physBodyChange; // = btVector3(0,0,0);
	btTransform physBodyTransform;

	// updates player's position
    Ogre::Vector3 posChange = convert->toOgreVector3(position());
    Ogre::Vector3 *offenseStartPositions;
    OpenSteer::Vec3 startPosition;
    OpenSteer::Vec3 seekTarget;
//			float distPlayerStartPosition;
    switch (teamNumber)
	{
	    case 0:
            x = 0;
            while (x < team0ActivePlayerInstance.size())
            {
                if (team0ActivePlayerInstance[x].getInitialized())
                {
                    logMsg("upDie????????");
                   // team0ActivePlayerInstance[x].getNode()->setPosition(posChange);
                    team0ActivePlayerInstance[ID].getNode()->setPosition(posChange);
                    physBodyChange = BtOgre::Convert::toBullet(posChange); // converts from Ogre::Vector3 to btVector3
                    physBodyTransform.setOrigin(physBodyChange);
                   // team0ActivePlayerInstance[x].getPhysBody()->setWorldTransform(physBodyTransform);
                    team0ActivePlayerInstance[ID].getPhysBody()->setWorldTransform(physBodyTransform);
                    logMsg("nope");
                }
                ++x;
            }
            teamInstance[0].setActivePlayerInstance(team0ActivePlayerInstance);
			break;
		case 1:
            logMsg("ID = " +convert->toString(ID));
            logMsg("posChange = " +convert->toString(posChange));
//			exit(0);
            x = 0;
            while (x < team1ActivePlayerInstance.size())
            {
                if (team1ActivePlayerInstance[x].getInitialized())
                {
                    logMsg("upDie?????????");
                    logMsg("bloop");
                  //  team1ActivePlayerInstance[x].getNode()->setPosition(posChange);
                    team1ActivePlayerInstance[ID].getNode()->setPosition(posChange);
                    physBodyChange = BtOgre::Convert::toBullet(posChange); // converts from Ogre::Vector3 to btVector3
                    physBodyTransform.setOrigin(physBodyChange);
                  //  team1ActivePlayerInstance[x].getPhysBody()->setWorldTransform(physBodyTransform);
                    team1ActivePlayerInstance[ID].getPhysBody()->setWorldTransform(physBodyTransform);
                    logMsg("nope");
                }
                ++x;
            }
            teamInstance[1].setActivePlayerInstance(team1ActivePlayerInstance);
			break;
		default:
		    break;
	}
    logMsg("Alive!");
}

void playerSteer::updateOffense(const float currentTime, const float elapsedTime)	// updates the offense steering sim
{
    //conversion *convert = conversion::Instance();
	boost::shared_ptr<conversion> convert = conversion::Instance();
    
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();

	std::vector<teamState> teamInstance = gameS->getTeamInstance();
    std::vector<playerState> team0ActivePlayerInstance = teamInstance[0].getActivePlayerInstance();
    std::vector<playerState> team1ActivePlayerInstance = teamInstance[1].getActivePlayerInstance();
    std::vector<int> team0ActivePlayerID = teamInstance[0].getActivePlayerID();
    std::vector<int> team1ActivePlayerID = teamInstance[1].getActivePlayerID();

	std::vector<bool> startPositionReached = teamInstance[teamNumber].getOffenseInstance()->getStartPositionReached();

    OpenSteer::Vec3 seekTarget;
    distToPosition = OpenSteer::Vec3::distance (steerCoords, position());
	
	if (distToPosition >= 3)
	{
		logMsg("seeking!");
//		seekTarget = xxxsteerForSeek(startPosition);
		seekTarget = xxxsteerForSeek(steerCoords);
        logMsg("seekTarget = " +convert->toString(convert->toOgreVector3(steerCoords)));
		applySteeringForce (seekTarget, elapsedTime);
        
	}
	else
	{
//		startPositionReached[ID] = true;
		positionReached[0] = true;
//		teamInstance[teamNumber].getOffenseInstance()->setStartPositionReached(startPositionReached);

	}
		
/*
//	logMsg(" speed = " +convert->toString(speed()));

//	if (!startPositionReached[ID])  // moves player into start position
    if (!positionReached[0])
	{
	    std::vector<Ogre::Vector3> offenseStartPositions;
	    OpenSteer::Vec3 startPosition;
	    OpenSteer::Vec3 seekTarget;

	    offenseStartPositions = teamInstance[teamNumber].getOffenseInstance()->getStartPositions();
        logMsg("Team " +convert->toString(teamNumber) +" Player " +convert->toString(ID) +" Seeking Offense Start Position!");
        startPosition = toOpenSteerVec3(offenseStartPositions[ID]);
        logMsg("startPosition = " +convert->toString(offenseStartPositions[ID]));

        logMsg("current position = " +convert->toString(team1ActivePlayerInstance[ID].getNodePosition()));
	    distToPosition = OpenSteer::Vec3::distance (startPosition, position());
        logMsg("Distance to start Position = " +convert->toString(distToPosition));
	    if (distToPosition >= 3)
	    {
		    logMsg("seeking!");
//		    seekTarget = xxxsteerForSeek(startPosition);
		    seekTarget = xxxsteerForSeek(steerCoords);
            logMsg("seekTarget = " +convert->toString(toOgreVector3(startPosition)));
		    applySteeringForce (seekTarget, elapsedTime);
	    }
		else
		{
//			startPositionReached[ID] = true;
			positionReached[0] = true;
//			teamInstance[teamNumber].getOffenseInstance()->setStartPositionReached(startPositionReached);

		}
	}
	else
	{
		exit(0);
	    std::vector< std::vector<Ogre::Vector3> > offenseExecutePositions;
	    std::vector< std::vector<bool> > offenseExecutePositionReached;
	    OpenSteer::Vec3 executePosition;
	    OpenSteer::Vec3 seekTarget;
//	    float distPlayerExecutePosition;

	    offenseExecutePositions = teamInstance[teamNumber].getOffenseInstance()->getExecutePositions();
	    offenseExecutePositionReached = teamInstance[teamNumber].getOffenseInstance()->getExecutePositionReached();

        seekTarget = xxxsteerForSeek(steerCoords);
 //       logMsg("seekTarget = " +convert->toString(toOgreVector3(executePosition)));
        applySteeringForce (seekTarget, elapsedTime);


	}
*/
	// moves the player model and physics body
	btVector3 physBodyChange; // = btVector3(0,0,0);
	btTransform physBodyTransform;

	// updates player's position
    Ogre::Vector3 posChange = convert->toOgreVector3(position());
    Ogre::Vector3 *offenseStartPositions;
	OpenSteer::Vec3 startPosition;
//			OpenSteer::Vec3 seekTarget;
	float distPlayerStartPosition;
    size_t x = 0;
    size_t y = 0;
    
    switch (teamNumber)
	{
	    case 0:
            x = 0;
            while (x < team0ActivePlayerInstance.size())
            {
                if (team0ActivePlayerInstance[x].getInitialized())
                {
                    team0ActivePlayerInstance[x].getNode()->setPosition(posChange);
			        physBodyChange = BtOgre::Convert::toBullet(posChange); // converts from Ogre::Vector3 to btVector3
			        physBodyTransform.setOrigin(physBodyChange);
                    team0ActivePlayerInstance[x].getPhysBody()->setWorldTransform(physBodyTransform);
                }
                ++x;
            }
            teamInstance[0].setActivePlayerInstance(team0ActivePlayerInstance);
			break;
		case 1:
            logMsg("ID = " +convert->toString(ID));
            logMsg("posChange = " +convert->toString(posChange));
//			exit(0);
            x = 0;
            while (x < team1ActivePlayerInstance.size())
            {
                if (team1ActivePlayerInstance[x].getInitialized())
                {
                    team1ActivePlayerInstance[x].getNode()->setPosition(posChange);
			        physBodyChange = BtOgre::Convert::toBullet(posChange); // converts from Ogre::Vector3 to btVector3
			        physBodyTransform.setOrigin(physBodyChange);
                    team1ActivePlayerInstance[x].getPhysBody()->setWorldTransform(physBodyTransform);
                }
                ++x;
            }
            teamInstance[1].setActivePlayerInstance(team1ActivePlayerInstance);
			break;
		default:
		    break;
	}

}

void playerSteer::updateDefense(const float currentTime, const float elapsedTime)	// updates the defense steering sim
{
    //conversion *convert = conversion::Instance();
	boost::shared_ptr<conversion> convert = conversion::Instance();
    
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();

	std::vector<teamState> teamInstance = gameS->getTeamInstance();

    std::vector<playerState> team0ActivePlayerInstance = teamInstance[0].getActivePlayerInstance();
    std::vector<playerState> team1ActivePlayerInstance = teamInstance[1].getActivePlayerInstance();
    std::vector<int> team0ActivePlayerID = teamInstance[0].getActivePlayerID();
    std::vector<int> team1ActivePlayerID = teamInstance[1].getActivePlayerID();

	std::vector<playerSteer*> team0Steers;
	std::vector<playerSteer*> team1Steers;

    for (size_t x=0;x<team0ActivePlayerInstance.size();++x)
	{
//		playerSteerInstance.push_back(team0ActivePlayerInstance[0].getSteer());

//		playerSteerInstance.push_back(team0ActivePlayerInstance[x].getSteer());
        team0Steers.push_back(team0ActivePlayerInstance[x].getSteer());
//		playerSteerInstance.push_back(team0ActivePlayerInstance[2].getSteer());

	}

    for (size_t x=0;x<team1ActivePlayerInstance.size();++x)
	{
//		playerSteerInstance.push_back(team1ActivePlayerInstance[x].getSteer());
        team1Steers.push_back(team1ActivePlayerInstance[x].getSteer());

	}

	OpenSteer::Vec3 playerOPos;
	OpenSteer::Vec3 seekTarget;
	float distPlayerOPosition;
    logMsg("Die?");
    size_t x = 0;
    size_t y = 0;
	switch (teamNumber)
	{
		case 0:
            logMsg("activeID size = " +convert->toString((team1ActivePlayerID.size())));
            logMsg("activeID num = " +convert->toString(team1ActivePlayerID[ID]));
            x = 0;
            while (x < team1ActivePlayerInstance.size())
            {
                if (team1ActivePlayerInstance[x].getInitialized())
                {
                    logMsg("team 1 player ID = " +convert->toString(team1ActivePlayerInstance[x].getPlayerID()));
                    logMsg("Die??");
                    playerOPos = convert->toOpenSteerVec3(team1ActivePlayerInstance[x].getCourtPosition());
                    logMsg("die!");                     
                }
                ++x;
            }
            break;
		case 1:
            logMsg("activeID size = " +convert->toString((team1ActivePlayerID.size())));
            logMsg("activeID num = " +convert->toString(team1ActivePlayerID[ID]));
            x = 0;
            while (x < team0ActivePlayerInstance.size())
            {
                if (team0ActivePlayerInstance[x].getInitialized())
                {
                    logMsg("Die???");
                    playerOPos = convert->toOpenSteerVec3(team0ActivePlayerInstance[x].getCourtPosition());
                }
                ++x;
            }
            break;
		default:
			break;
	}

	distPlayerOPosition = OpenSteer::Vec3::distance (playerOPos, position());
    logMsg("Distance to playerOPos = " +convert->toString(distPlayerOPosition));
	if (distPlayerOPosition >= 3)
	{
        logMsg("ID == " +convert->toString(ID));
		logMsg("seeking!");
//				seekTarget = xxxsteerForSeek(playerOPos);
		const AbstractVehicle &quarry = *team1Steers[ID];
        logMsg("Alive after seek");
		seekTarget = steerForPursuit(quarry);
        logMsg("Alive still after seek");
        logMsg("seekTarget = " +convert->toString(convert->toOgreVector3(playerOPos)));
		applySteeringForce (seekTarget, elapsedTime);
	}

	// moves the player model and physics body
	btVector3 physBodyChange; // = btVector3(0,0,0);
	btTransform physBodyTransform;

	// updates player's position
    Ogre::Vector3 posChange = convert->toOgreVector3(position());
    Ogre::Vector3 *offenseStartPositions;
    OpenSteer::Vec3 startPosition;
//			OpenSteer::Vec3 seekTarget;
    float distPlayerStartPosition;
    switch (teamNumber)
	{
	    case 0:
            x = 0;
            while (x < team0ActivePlayerInstance.size())
            {
                if (team0ActivePlayerInstance[x].getInitialized())
                {
                    logMsg("Die????");
                    team0ActivePlayerInstance[x].getNode()->setPosition(posChange);
                    physBodyChange = BtOgre::Convert::toBullet(posChange); // converts from Ogre::Vector3 to btVector3
                    physBodyTransform.setOrigin(physBodyChange);
                    team0ActivePlayerInstance[x].getPhysBody()->setWorldTransform(physBodyTransform);
                }
                ++x;
            }
            teamInstance[0].setActivePlayerInstance(team0ActivePlayerInstance);
			break;
		case 1:
            logMsg("ID = " +convert->toString(ID));
            logMsg("posChange = " +convert->toString(posChange));
//			exit(0);
            x = 0;
            while (x < team1ActivePlayerInstance.size())
            {
                if (team1ActivePlayerInstance[x].getInitialized())
                {
                    logMsg("Die?????");
                    team1ActivePlayerInstance[x].getNode()->setPosition(posChange);
                    physBodyChange = BtOgre::Convert::toBullet(posChange); // converts from Ogre::Vector3 to btVector3
                    physBodyTransform.setOrigin(physBodyChange);
                    team1ActivePlayerInstance[x].getPhysBody()->setWorldTransform(physBodyTransform);
                }
                ++x;
            }
            teamInstance[1].setActivePlayerInstance(team1ActivePlayerInstance);
			break;
		default:
		    break;
	}

}
