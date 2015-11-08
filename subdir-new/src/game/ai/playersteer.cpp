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
#include "comparison.h"
playerSteer::~playerSteer()
{

}


teamTypes playerSteer::getTeamType() // retrieves the value of teamType
{
    return (teamType);
}
void playerSteer::setTeamType(teamTypes set) // sets the value of teamType
{
    teamType = set;
}

size_t playerSteer::getID() // retrieves the value of ID
{
	return (ID);
}
void playerSteer::setID(size_t set) // sets the value of ID
{
    ID = set;
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


    if (teamType != NOTEAM)
	{
        logMsg("teamType steer!");
	    //gameState *gameS = gameState::Instance();
        boost::shared_ptr<gameState> gameS = gameState::Instance();
        
	    std::vector<teamState> teamInstance = gameS->getTeamInstance();
        logMsg("teamType == " +convert->toString(teamType));
        std::vector<playerState> activePlayerInstance = teamInstance[teamType].getActivePlayerInstance();
        logMsg("teamType steer2!");

	    OpenSteer::Vec3 playerSteerPos;
        std::vector< std::vector<size_t> > teamStarterID = gameS->getTeamStarterID();
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
                logMsg("teamStarterSteerID = " +convert->toString(teamStarterID[teamType][x]));
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

//	exit(0);
	counter += 1;
//	logMsg("Counter = " +convert->toString(counter));

//	logMsg("elapsedTime = " +convert->toString(elapsedTime));

	std::vector<basketballs> basketball = gameS->getBasketballInstance();
	std::vector<teamState> teamInstance = gameS->getTeamInstance();
//    std::vector<playerState> team0ActivePlayerInstance = teamInstance[0].getActivePlayerInstance();
//    std::vector<playerState> team1ActivePlayerInstance = teamInstance[1].getActivePlayerInstance();
    std::vector<std::vector<playerState> > activePlayerInstance;
//    std::vector<int> team0ActivePlayerID = teamInstance[0].getActivePlayerID();
//    std::vector<int> team1ActivePlayerID = teamInstance[1].getActivePlayerID();
    std::vector<std::vector<int> > activePlayerID;

//	std::vector<playerSteer*> playerSteerInstance;
	std::vector<playerSteer*> pSteer = ai->getAllPlayerSteers();
    //std::vector<playerSteer*> team0Steers;
    //std::vector<playerSteer*> team1Steers;
    std::vector<playerSteer *> teamSteer;
    std::vector<std::vector<playerSteer*> > teamSteers;
    logMsg("Updating playerSteer state");


    size_t z = 0;
    while (z < teamInstance.size())
    {
        activePlayerInstance.push_back(teamInstance[z].getActivePlayerInstance());
        std::vector<int> activeID;
        activePlayerID.push_back(activeID);
        size_t x = 0;
        while (x < activePlayerInstance[z].size())
        {
            teamSteer.push_back(activePlayerInstance[z][x].getSteer());
            ++x;
        }
        teamSteers.push_back(teamSteer);
        ++z;
   }

//    logMsg("Player = " +convert->toString(ID));
//	logMsg("Node position = " +convert->toString(teamInstance[teamType].getActivePlayerInstance()[ID].getNodePosition()));
//	logMsg("Steer position = " +convert->toString(toOgreVector3(position())));
    logMsg("Team = " +convert->toString(teamType));
    logMsg("ID = " +convert->toString(ID));
//    OpenSteer::Vec3 currentNodePos = toOpenSteerVec3(teamInstance[teamType].getActiePlayerInstance()[ID].getNodePosition());

/*	if (position().x != currentNodePos.x || position().y != currentNodePos.y || position().z != currentNodePos.z)
	{
		exit(0);
	}
*/
    logMsg("teamType = " +convert->toString(teamType));

/*    size_t x = 0;
    while (x < activePlayerInstance.size())
    {
        size_t y = 0;
        while (y < activePlayerInstance[x].size())
        {
            if (activePlayerInstance[x][y].getInitialized())
            {

                logMsg("upDie?");
//		playerSteerInstance.push_back(team0ActivePlayerInstance[0].getSteer());

//		playerSteerInstance.push_back(team0ActivePlayerInstance[x].getSteer());
                teamSteers[x].push_back(activePlayerInstance[x][y].getSteer());
//		playerSteerInstance.push_back(team0ActivePlayerInstance[2].getSteer());
            }
            ++y;
        }
        ++x;
    }
*/

//    for (int x=0;x<team1ActivePlayerInstance.size();++x)
//	{
/*    x = 0;
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
*/
	OpenSteer::Vec3 playerSteerPos;
    playerSteerPos = convert->toOpenSteerVec3(activePlayerInstance[teamType][ID].getCourtPosition());
    /*
    size_t z = 0;
    while (z < teamInstance.size())
    {
        size_t x = 0;
        while (x < activePlayerInstance[z].size())
        {
            if (activePlayerInstance[z][x].getInitialized())
            {
                logMsg("upDie???");
                playerSteerPos = convert->toOpenSteerVec3(activePlayerInstance[z][x].getCourtPosition());
                logMsg("nope!");
            }
            ++x;
        }
        ++z
    }
    
    switch (teamType)
	{
		case 0:
            logMsg("activeID size = " +convert->toString((activePlayerID[0].size())));
            logMsg("do");
//            logMsg("activeID num = " +convert->toString(team0ActivePlayerID[ID]));
            x = 0;
            while (x < activePlayerInstance[0].size())
            {
                if (activePlayerInstance[0][x].getInitialized())
                {
                    logMsg("upDie???");
                    playerSteerPos = convert->toOpenSteerVec3(activePlayerInstance[0][x].getCourtPosition());
                    logMsg("nope!");
                }
                ++x;
            }
			break;
		case 1:
            logMsg("activeID size = " +convert->toString((activePlayerID[1].size())));
            logMsg("team 1 ID = " +convert->toString(ID));
//            logMsg("activeID num = " +convert->toString(team1ActivePlayerID[ID]));
            x = 0;
            while (x < activePlayerInstance[1].size())
            {
                logMsg("TEEE");
                if (activePlayerInstance[1][x].getInitialized())
                {
                    logMsg("upDie????");
                    playerSteerPos = convert->toOpenSteerVec3(activePlayerInstance[1][x].getCourtPosition());
                }
                ++x;
            }
            break;
		default:
			break;
	}*/

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
    switch (teamType)
	{
        case HOMETEAM:
            steerees = (OpenSteer::AVGroup&)teamSteers[0];

			break;
        case AWAYTEAM:
            steerees = (OpenSteer::AVGroup&)teamSteers[1];
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
        logMsg("steernotteamwithball");
		float distHomeToBall = OpenSteer::Vec3::distance (m_home, bballSteerPos);
//		logMsg("m_home = " +convert->toString(toOgreVector3(m_home)));
//		logMsg("distHomeToBall = " +convert->toString(distHomeToBall));
        if (teamType != gameS->getTeamWithBall())
        {
            logMsg("teamupdateSteer = " +convert->toString(teamType));
            logMsg("updateSteer ID = " +convert->toString(ID));
            updateDefense(currentTime, elapsedTime);
        }
        else
        {
            logMsg("update offense?");
            if (execute)
            {
//			,	exit(0);
                updateOffense(currentTime, elapsedTime);
            }
        }

//		exit(0);
    }
    logMsg("checking court position!");
    checkCourtPosition(); // checks if steering position matches court position
	
    logMsg("Alive!");
}

void playerSteer::checkCourtPosition()  // checks if the player's position has changed
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    logMsg("checkCourtAlive!");

    comparison compare;
    std::vector<teamState> teamInstance = gameS->getTeamInstance();
    //std::vector<playerState> team0ActivePlayerInstance = teamInstance[0].getActivePlayerInstance();
    //std::vector<playerState> team1ActivePlayerInstance = teamInstance[1].getActivePlayerInstance();
    std::vector<std::vector<playerState> > activePlayerInstance;
    // moves the player model and physics body
    btVector3 physBodyChange; // = btVector3(0,0,0);
    btTransform physBodyTransform;

    
    // updates player's position
    Ogre::Vector3 posChange = convert->toOgreVector3(position());
    Ogre::Vector3 *offenseStartPositions;
    OpenSteer::Vec3 startPosition;
    OpenSteer::Vec3 seekTarget;
    
    size_t z = 0;
    while (z < teamInstance.size())
    {
        activePlayerInstance.push_back(teamInstance[z].getActivePlayerInstance());
        ++z;
    }
    int humanPlayer = teamInstance[teamType].getHumanPlayer();
    logMsg("steer Human Player = " +convert->toString(humanPlayer));
    if (activePlayerInstance[teamType][ID].getPlayerID() != humanPlayer)  // makes sure to not steer human player
    {
        if (activePlayerInstance[teamType][ID].getInitialized())
        {
            Ogre::Vector3 newCourtPosition = convert->toOgreVector3(position());
            Ogre::Vector3 currentCourtPosition = activePlayerInstance[teamType][ID].getCourtPosition();
            if (!compare.OgreVector3ToOgreVector3(currentCourtPosition,newCourtPosition))
            {
                activePlayerInstance[teamType][ID].setCourtPositionChanged(true);
                activePlayerInstance[teamType][ID].setCourtPositionChangedType(STEERCHANGE);
                activePlayerInstance[teamType][ID].setNewCourtPosition(newCourtPosition);
                logMsg("SteerChange!");
            //exit(0);
            }
        }
    }
    else
    {
        
    }
    teamInstance[teamType].setActivePlayerInstance(activePlayerInstance[teamType]);

    gameS->setTeamInstance(teamInstance);
    std::vector<teamState> teamI = gameS->getTeamInstance();
    std::vector<std::vector<playerState> > activePlayerI;
    size_t w = 0;
    while (w < teamInstance.size())
    {
        activePlayerI.push_back(teamInstance[w].getActivePlayerInstance());
        ++w;
    }
    if (activePlayerI[teamType][ID].getCourtPositionChangedType() == STEERCHANGE)
    {
        logMsg("SteerChanged!!");
    }
}

void playerSteer::updateOffense(const float currentTime, const float elapsedTime)	// updates the offense steering sim
{
    //conversion *convert = conversion::Instance();
	boost::shared_ptr<conversion> convert = conversion::Instance();
    
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();

	std::vector<teamState> teamInstance = gameS->getTeamInstance();
    //std::vector<playerState> team0ActivePlayerInstance = teamInstance[0].getActivePlayerInstance();
    //std::vector<playerState> team1ActivePlayerInstance = teamInstance[1].getActivePlayerInstance();
    std::vector<std::vector<playerState> > activePlayerInstance;
    std::vector<size_t> team0ActivePlayerID = teamInstance[0].getActivePlayerID();
    std::vector<size_t> team1ActivePlayerID = teamInstance[1].getActivePlayerID();

    std::vector<bool> startPositionReached = teamInstance[teamType].getOffenseInstance()->getStartPositionReached();

    OpenSteer::Vec3 seekTarget;
    distToPosition = OpenSteer::Vec3::distance (steerCoords, position());
	

    size_t z = 0;
    while (z < teamInstance.size())
    {
        activePlayerInstance.push_back(teamInstance[z].getActivePlayerInstance());
        ++z;
    }
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
        logMsg("not seeking!");
//		startPositionReached[ID] = true;
        logMsg("positionReached size" +convert->toString(positionReached.size()));
//		positionReached[0] = true;
        logMsg("not seeked!");
//		teamInstance[teamType].getOffenseInstance()->setStartPositionReached(startPositionReached);

	}
		
/*
//	logMsg(" speed = " +convert->toString(speed()));

//	if (!startPositionReached[ID])  // moves player into start position
    if (!positionReached[0])
	{
	    std::vector<Ogre::Vector3> offenseStartPositions;
	    OpenSteer::Vec3 startPosition;
	    OpenSteer::Vec3 seekTarget;

        offenseStartPositions = teamInstance[teamType].getOffenseInstance()->getStartPositions();
        logMsg("Team " +convert->toString(teamType) +" Player " +convert->toString(ID) +" Seeking Offense Start Position!");
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
//			teamInstance[teamType].getOffenseInstance()->setStartPositionReached(startPositionReached);

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

        offenseExecutePositions = teamInstance[teamType].getOffenseInstance()->getExecutePositions();
        offenseExecutePositionReached = teamInstance[teamType].getOffenseInstance()->getExecutePositionReached();

        seekTarget = xxxsteerForSeek(steerCoords);
 //       logMsg("seekTarget = " +convert->toString(toOgreVector3(executePosition)));
        applySteeringForce (seekTarget, elapsedTime);


	}
*/

/*
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
    
    switch (teamType)
	{
	    case 0:
            x = 0;
            while (x < activePlayerInstance[0].size())
            {
                if (activePlayerInstance[0][x].getInitialized())
                {
                    activePlayerInstance[0][x].getNode()->setPosition(posChange);
			        physBodyChange = BtOgre::Convert::toBullet(posChange); // converts from Ogre::Vector3 to btVector3
			        physBodyTransform.setOrigin(physBodyChange);
                    team0ActivePlayerInstance[x].getPhysBody()->setWorldTransform(physBodyTransform);
                    
                    logMsg("team 0 player " +convert->toString(x) +"offenseSteer coords = " +convert->toString(posChange));
                }
                ++x;
            }
            //teamInstance[0].setActivePlayerInstance(team0ActivePlayerInstance);
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
*/
}

void playerSteer::updateDefense(const float currentTime, const float elapsedTime)	// updates the defense steering sim
{
    //conversion *convert = conversion::Instance();
	boost::shared_ptr<conversion> convert = conversion::Instance();
    
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();

	std::vector<teamState> teamInstance = gameS->getTeamInstance();

    //std::vector<playerState> team0ActivePlayerInstance = teamInstance[0].getActivePlayerInstance();
    //std::vector<playerState> team1ActivePlayerInstance = teamInstance[1].getActivePlayerInstance();
    std::vector<std::vector<playerState> > activePlayerInstance;
    //std::vector<int> team0ActivePlayerID = teamInstance[0].getActivePlayerID();
    //std::vector<int> team1ActivePlayerID = teamInstance[1].getActivePlayerID();

	//std::vector<playerSteer*> team0Steers;
	//std::vector<playerSteer*> team1Steers;
    std::vector<playerSteer *> teamSteer;
    std::vector<std::vector<playerSteer*> > teamSteers;

    size_t z = 0;
    while (z < teamInstance.size())
    {
        activePlayerInstance.push_back(teamInstance[z].getActivePlayerInstance());
        size_t x = 0;
        while (x < activePlayerInstance[z].size())
        {
            teamSteer.push_back(activePlayerInstance[z][x].getSteer());
            ++x;
        }
        teamSteers.push_back(teamSteer);
        ++z;
    }
    
    logMsg("defensesteer ID = " +convert->toString(ID));


    OpenSteer::Vec3 playerOPos;
    OpenSteer::Vec3 seekTarget;
    float distPlayerOPosition;
    logMsg("Die?");
    size_t x = 0;
    size_t y = 0;
    switch (teamType)
    {
        case HOMETEAM:
            /*
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
            */
            playerOPos = convert->toOpenSteerVec3(activePlayerInstance[1][ID].getCourtPosition());
        break;
        case AWAYTEAM:
            /*logMsg("activeID size = " +convert->toString((team1ActivePlayerID.size())));
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
            }*/
            playerOPos = convert->toOpenSteerVec3(activePlayerInstance[0][ID].getCourtPosition());
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
        //const AbstractVehicle &quarry = NULL;
        std::vector<playerSteer *> quarrySteer;
        switch (teamType)
        {
            case HOMETEAM:
                quarrySteer = teamSteers[1];
            break;
            case AWAYTEAM:
                quarrySteer = teamSteers[0];
            break;
            default:
            break;
        }
		const AbstractVehicle &quarry = *quarrySteer[ID]; //*team1Steers[ID];
        logMsg("Alive after seek");
		seekTarget = steerForPursuit(quarry);
        logMsg("Alive still after seek");
        logMsg("seekTarget = " +convert->toString(convert->toOgreVector3(playerOPos)));
		applySteeringForce (seekTarget, elapsedTime);
	}

/*
	// moves the player model and physics body
	btVector3 physBodyChange; // = btVector3(0,0,0);
	btTransform physBodyTransform;

	// updates player's position
    Ogre::Vector3 posChange = convert->toOgreVector3(position());
    Ogre::Vector3 *offenseStartPositions;
    OpenSteer::Vec3 startPosition;
//			OpenSteer::Vec3 seekTarget;
    float distPlayerStartPosition;
    switch (teamType)
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
*/
}
