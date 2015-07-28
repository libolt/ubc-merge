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
 *   along with this program; if not, write to the         n                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "conversion.h"
#include "teamstate.h"
#include "gameengine.h"
#include "gamestate.h"
#include "logging.h"
#include "physicsengine.h"
#include "players.h"
#include "playersteer.h"

//extern "C"
//{
teamState::teamState()
{
	teamNumber = -1;
	playerType = ' ';
    assists = 0;
    blocks = 0;
    fouls = 0;
    rebounds = 0;
    steals = 0;
    technicals = 0;
    timeouts = 0;

//    activePlayerID = new int[5];
/*    for (size_t x=0;x<5;++x)
    {
        activePlayerID.push_back(0);
    }
*/
    offenseInstance = new offenseState;
    defenseInstance = new defenseState;

	playerInstancesCreated = false;
    playerWithBall = -1;
    playerWithBallDribbling = false;

    humanControlled = false;
    humanPlayer = 4;

    hoop = -1;

    stateSet = false;
//    setupState();
}

teamState::~teamState()
{
}

int teamState::getTeamNumber()	// retrieves the value of teamNumber
{
	return (teamNumber);
}
void teamState::setTeamNumber(int number)	// sets the value of the teamNumber
{
	teamNumber = number;
}

std::string teamState::getPlayerType()	// retrieves the value of playerType
{
	return (playerType);
}
void teamState::setPlayerType(std::string type)	// sets the value of playerType
{
	playerType = type;
}

int teamState::getAssists(void)   // retrieves the value of assists
{
    return (assists);
}
void teamState::setAssists(int assist)    // sets the value of assists
{
    assists = assist;
}

int teamState::getBlocks(void)    // retrieves the value of blocks
{
    return (blocks);
}
void teamState::setBlocks(int block)   // sets the value of blocks
{
    blocks = block;
}

int teamState::getFouls(void) // retrieves the value of fouls
{
    return (fouls);
}
void teamState::setFouls(int foul)    // sets the value of fouls
{
    fouls = foul;
}

int teamState::getRebounds(void)  // retrieves the value of rebounds
{
    return (rebounds);
}
void teamState::setRebounds(int rebound)  // sets the value of rebounds
{
    rebounds = rebound;
}

int teamState::getOffensiveRebounds(void) // retrieves the value of offensiveRebounds
{
    return (offensiveRebounds);
}
void teamState::setOffensiveRebounds(int rebounds)    // sets the value of offensiveRebounds
{
    offensiveRebounds = rebounds;
}

int teamState::getDefensiveRebounds(void) // retrieves the value of defensiveRebounds
{
    return (defensiveRebounds);
}
void teamState::setDefensiveRebounds(int rebounds)    // sets the value of defensiveRebounds
{
    defensiveRebounds = rebounds;
}

int teamState::getSteals(void)    // retrieves the value of steals
{
    return (steals);
}
void teamState::setSteals(int steal)    // sets the value of steals
{
    steals = steal;
}

int teamState::getTechnicals(void)    // retrieves the value of technicals
{
    return (technicals);
}
void teamState::setTechnicals(int technical)  // sets the value of technicals
{
    technicals = technical;
}

int teamState::getTimeouts(void)  // retrieves the value of timeouts
{
    return (timeouts);
}
void teamState::setTimeouts(int timeout)  // sets the value of timeouts
{
    timeouts = timeout;
}

int teamState::getTurnovers() // retrieves the value of turnovers
{
	return (turnovers);
}
void teamState::setTurnovers(int turnover)    // sets the value of turnovers
{
	turnovers = turnover;
}

int teamState::getFieldGoalsAttempted(void)   // retrieves the value of fieldGoalsAttempted
{
    return (fieldGoalsAttempted);
}
void teamState::setFieldGoalsAttempted(int fieldGoals)    // sets the value of fieldGoalsAttempted
{
    fieldGoalsAttempted = fieldGoals;
}

int teamState::getFieldGoalsMade(void)   // retrieves the value of fieldGoalsMade
{
    return (fieldGoalsMade);
}
void teamState::setFieldGoalsMade(int fieldGoals)    // sets the value of fieldGoalsMade
{
    fieldGoalsMade = fieldGoals;
}

int teamState::getThreePointersAttempted(void)   // retrieves the value of threePointersAttempted
{
    return (threePointersAttempted);
}
void teamState::setThreePointersAttempted(int threePointers)  // sets the value of threePointersAttempted
{
    threePointersAttempted = threePointers;
}

int teamState::getThreePointersMade(void)   // retrieves the value of threePointersMade
{
    return (threePointersMade);
}
void teamState::setThreePointersMade(int threePointers)  // sets the value of threePointersMade
{
    threePointersMade = threePointers;
}

int teamState::getFreeThrowsAttempted(void)   // retrieves the value of freeThrowsAttempted
{
    return (freeThrowsAttempted);
}
void teamState::setFreeThrowsAttempted(int freeThrows)    // sets the value of freeThrowsAttempted
{
    freeThrowsAttempted = freeThrows;
}

int teamState::getFreeThrowsMade(void)   // retrieves the value of freeThrowsMade
{
    return (freeThrowsMade);
}
void teamState::setFreeThrowsMade(int freeThrows)    // sets the value of freeThrowsMade
{
    freeThrowsMade = freeThrows;
}

std::vector<int> teamState::getPlayerID()  // retrieves the value of playerID
{
    return (playerID);
}
void teamState::setPlayerID(std::vector<int> ID)   // sets the value of playerID
{
    playerID = ID;
}


std::vector<int> teamState::getActivePlayerID()  // retrieves the value of activePlayerID
{
    return (activePlayerID);
}
void teamState::setActivePlayerID(std::vector<int> ID)   // sets the value of activePlayerID
{
    activePlayerID = ID;
}

std::vector<int> teamState::getStarterID() // retrieves the value of starterID
{
    return (starterID);
}
void teamState::setStarterID(std::vector<int> ID)  // sets the value of starterID
{
    logMsg("blap");
    starterID = ID;
}

bool teamState::getOffense()	// returns the value of offense
{
	return (offense);
}
void teamState::setOffense(bool set)	// sets the value of offense
{
	offense = set;
}
bool teamState::getDefense()	// returns the value of defense
{
	return (defense);
}
void teamState::setDefense(bool set)	// sets the value of defense
{
	defense = set;
}

std::vector <playerState> teamState::getPlayerInstance()  // retrieves the value of  playerInstance
{
    return (playerInstance);
}

void teamState::setPlayerInstance(std::vector<playerState> pInstance)  // sets the value of playerInstance
{
    playerInstance = pInstance;
}

bool teamState::getPlayerInstancesCreated()	// retrieves the value of playerInstancesCreated
{
	return (playerInstancesCreated);
}
void teamState::setPlayerInstancesCreated(bool created)	// sets the value of playerInstancesCreated
{
	playerInstancesCreated = created;
}

int teamState::getPlayerWithBall(void) 	// retrives the value of playerWithBall
{
	return (playerWithBall);
}
void teamState::setPlayerWithBall(int ball)	// sets the value of playerWithBall
{
	playerWithBall = ball;
}

bool teamState::getPlayerWithBallDribbling()	// retrieves the value of playerWithBallDribbling
{
	return (playerWithBallDribbling);
}
void teamState::setPlayerWithBallDribbling(bool dribbling)	// sets the value of playerWithBallDribbling
{
	playerWithBallDribbling = dribbling;
}

bool teamState::getHumanControlled()		// retrieves the value of humanControlled
{
	return (humanControlled);
}
void teamState::setHumanControlled(bool controlled)		// sets the value of humanControlled
{
	humanControlled = controlled;
}

int teamState::getHumanPlayer()		// retrieves the value of the humanPlayer
{
	return (humanPlayer);
}
void teamState::setHumanPlayer(int player)		// sets the value of human player
{
	humanPlayer = player;
}

int teamState::getHoop()  // retrieves the value of hoop
{
    return (hoop);
}

void teamState::setHoop(int set)  // sets the value of hoop
{
    hoop = set;
}

offenseState *teamState::getOffenseInstance()	// retrievers the value of offenseInstance
{
	return (offenseInstance);
}
void teamState::setOffenseInstance(offenseState *instance)	// sets the value of offenseInstance
{
	offenseInstance = instance;
}
defenseState *teamState::getDefenseInstance()	// retrieves the value of defenseInstance
{
	return (defenseInstance);
}
void teamState::setDefenseInstance(defenseState *instance)	// sets the value of defenseInstance
{
	defenseInstance = instance;
}

bool teamState::getStateSet() // retrieves the value of stateSet
{
    return (stateSet);
}
void teamState::setStateSet(bool set) // sets the value of stateSet
{
    stateSet = set;
}

void teamState::setupState()	// sets up the state of the object
{
    if (!stateSet)
    {
        logMsg("Setting state");
//	    physicsEngine *physEngine = physicsEngine::Instance();
/*        if (!playerInstancesCreated)	// checks if playerInstances have been created
        {
    	    if (createPlayerInstances()) // creates the player instances based on playerIDS
		    {
                logMsg("Player instances created!");
                playerInstancesCreated = true;
//        	exit(0);
		    }
        }
*/
//        setPlayerStartPositions();	// sets starting positions for the players
        logMsg("Player start positions set");
//    playerWithBall = 3; // FIXME! Temporarily ahrd code player controlling ball
//    humanPlayer = 3;	// sets the human controlled player to the center for tip off
/*    player->mAnimationState2 =  playerInstance[5].getModel()->getAnimationState("Walk");
    player->mAnimationState2->setLoop(true);
    player->mAnimationState2->setEnabled(true);
*/
    stateSet = true;
    }
}
void teamState::updateState()	// updates the state of the object
{

//	exit(0);
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    gameEngine *gameE = gameEngine::Instance();
	gameState *gameS = gameState::Instance();
	physicsEngine *physEngine = physicsEngine::Instance();

//	logMsg("Updating team state " +convert->toString(teamNumber));
	if (gameS->getBasketballModelLoaded() && playerInstancesCreated)
	{
		std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();

//		exit(0);

		// checks whether to execute offense or defense logic
		if (offense == true && defense == false)
		{
//            exit(0);
			offenseInstance->setExecute(true);
			defenseInstance->setExecute(false);
		}
		else if (defense == true && offense == false)
		{
			offenseInstance->setExecute(false);
			defenseInstance->setExecute(true);
		}
		else
		{

		}

		if (gameS->getTipOffComplete())
		{
//			exit(0);
//			logMsg("Team with ball ==  "  +convert->toString(gameS->getTeamWithBall()));
//			logMsg("Player with ball ==  "  +convert->toString(playerWithBall));

			if (gameS->getTeamWithBall() == teamNumber) // checks if the team has the basketball
			{
				if (!playerInstance[playerWithBall].getPassBall())	// checks if the player with ball is passing it.
				{
	//				exit(0);
				}
				else if (playerInstance[playerWithBall].getPassBall())
				{
					logMsg("Calculating Pass");
	//				exit(0);
					if (!playerInstance[playerWithBall].getPassCalculated())
					{
	//					exit(0);
						Ogre::Vector3 bballPos;
						Ogre::Vector3 playerPos;
						playerInstance[playerWithBall].calculatePass();

						//sets the basketball Height;
						bballPos = basketballInstance[0].getNode()->getPosition();
						playerPos = playerInstance[playerWithBall].getNode()->getPosition();
						bballPos[1] = playerPos[1];
						basketballInstance[0].getNode()->setPosition(bballPos);

					}
					else if (playerInstance[playerWithBall].getPassCalculated())
					{
//						exit(0);
						executePass();
						if (physEngine->getPassCollision())	// checks if ball has collided with player being passed to.
						{
//							exit(0);
							playerInstance[playerWithBall].setPassBall(false);	// player is no longer passing the ball
							playerWithBall = playerInstance[playerWithBall].getPassToPlayer(); // playerWithBall has changed

							if (humanControlled)
							{
								humanPlayer = playerWithBall;
							}
							physEngine->setPassCollision(false);	// resets the pass collision state

						}
						else
						{
						}

					}
				}
//				logMsg("Player with ball ==  "  +convert->toString(playerWithBall));
//			    logMsg("Player with ball's name: "  +playerInstance[playerWithBall].getPlayerName());
//				logMsg("Player with ball's current position: "  +convert->toString(playerInstance[playerWithBall].getNode()->getPosition()));
			}
		}
        logMsg("Team number = " +convert->toString(teamNumber));

        logMsg("Human player = " +convert->toString(humanPlayer));
                                        
        updatePlayerStates();
		updatePlayerMovements();	// updates movement of player objects
		updatePlayerDirections();	// updates the direction the players are facing
//		exit(0);


		if (physEngine->getPlayerPhysicsSetup())	// makes sure player physics are setup before modifying physics positions
		{
			updatePositions();
//            exit(0);
		}
		else
		{
		}
//	logMsg("Team ==  "  +toString(teamNumber));

		//		exit(0);
	}
	else
	{
	}
//	exit(0);

	if (gameS->getTipOffComplete())
	{
	    if (gameS->getTeamWithBall() == teamNumber)
	    {
	        offenseInstance->updateState(teamNumber);	// updates the state of the offenseInstance object
	    }
	    else
	    {
	        defenseInstance->updateState(teamNumber); // updates the state of the defenseInstance object
	    }
	}
	else
	{
	}


//   logMsg("team state updated = " +convert->toString(teamNumber));
}

bool teamState::createPlayerInstances()
{
//    players *player = players::Instance();

    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    gameState *gameS = gameState::Instance();

    std::vector< std::vector<int> > teamStarterID = gameS->getTeamStarterID();
	std::vector<playerData> playerDataInstance = gameS->getPlayerDataInstance();
//	int x = 0;
	//	int playerID =
//    std::vector <playerData> playerN = player->getPlayer(); // copies Player values to playerN
    std::vector <playerData>::iterator playerIT;
//    std::vector <playerState>::iterator pInstanceIT;
    logMsg("Creating players");


    logMsg("playerDataInstance size = " +convert->toString(playerDataInstance.size()));
//    exit(0);
//    for (playerIT = playerDataInstance.begin(); playerIT != playerDataInstance.end(); ++playerIT)   // loops through playerID std::vector
    int id = -1; // stores id for steer
    size_t i = 0;
    
    //    for (size_t i = 0;i < playerDataInstance.size(); ++i)
    while (i<playerDataInstance.size())
    {

        playerState pInstance;  // creates a new instance of playerState
        playerSteer *pSteer = new playerSteer; // steer instance

//    	    logMsg("Player Team ID = " +convert->toString(playerDataInstance[i].getTeamID()));
//    	    logMsg("Team Number = " +convert->toString(teamNumber));

        if (playerDataInstance[i].getTeamID() == teamNumber)	// checks if player is assigned to this team
        {
            id += 1;
            pInstance.setModelName(playerDataInstance[i].getModel());
            pInstance.setFirstName(playerDataInstance[i].getFirstName());  // copies the first name from the playerData std::vector to the pInstance class
            pInstance.setLastName(playerDataInstance[i].getLastName());    // copies the last name from the playerData std::vector to the pInstance class
            pInstance.setPlayerName(playerDataInstance[i].getFirstName() + " " +playerDataInstance[i].getLastName());
            pInstance.setPlayerID(playerDataInstance[i].getID());
            pInstance.setTeamNumber(teamNumber);  // sets the team number the player belongs to
            pInstance.setPosition(playerDataInstance[i].getPosition());    // copies the position string from the playerData std::vector to the pInstance class
            pInstance.setPosChange(Ogre::Vector3(0.0f,0.0f,0.0f));
            pSteer->setTeamNumber(teamNumber);
            pSteer->setID(id);
            if (pInstance.getPosition() == "PG")
            {
                pSteer->setDesignation(PG);
            }
            else if (pInstance.getPosition() == "SG")
            {
                pSteer->setDesignation(SG);
            }
            else if (pInstance.getPosition() == "SF")
            {
                pSteer->setDesignation(SF);
            }
            else if (pInstance.getPosition() == "PF")
            {
                pSteer->setDesignation(PF);
            }
            else if (pInstance.getPosition() == "C")
            {
                pSteer->setDesignation(C);
            }

            pSteer->reset();
            pInstance.setSteer(pSteer);
            playerInstance.push_back(pInstance);    // adds pInstance to the playerInstance std::vector.
            logMsg("steerID = " +convert->toString(pInstance.getSteer()->getID()));
            logMsg("player name = " +pInstance.getPlayerName());
        }
        else
        {
        }
        i++;
    }

//    std::vector <playerState>::iterator pInstanceIT;

    logMsg("before playerID");
//        int playerID = teamStarterID[teamNumber][i];
//        int playerID = activePlayerID[i];
//        logMsg("ID " +convert->toString(i) +" = " +convert->toString(playerID));
    logMsg("activePlayerID.size() = " +convert->toString(activePlayerID.size()));
//    logMsg("playerID = " +convert->toString(activePlayerID[i]));
    size_t x = 0;

    logMsg("playerInstance.size() = " +convert->toString(playerInstance.size()));

    bool IDMatch = false;
//            for (size_t j=0;j<playerInstance.size();++j)
    while (x<playerInstance.size())
    {
        size_t i = 0;
//        while (!IDMatch && x < playerInstance.size())
        while (i<activePlayerID.size())
        {

            logMsg("playerInstance[x].getPlayerID() = " +convert->toString(playerInstance[x].getPlayerID()));
            if (activePlayerID[i] == playerInstance[x].getPlayerID())
            {
//                exit(0);
//                IDMatch = true;
                logMsg("Success!");
//                exit(0);
                if (!playerInstance[x].getModelLoaded())
                {
                    if (playerInstance[x].loadModel())
                    {
                        logMsg("Loading Model");
//                        exit(0);
                        playerInstance[x].setModelLoaded(true);
                    }
                    else
                    {
                        logMsg("Failed to load model " +playerInstance[x].getPlayerName());
                    }
                }
//                    exit(0);
            }
           i++;
        }
        x++;
    }

    return true;
}

void teamState::setPlayerStartPositions()	// sets the initial coordinates for the players.
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    gameState *gameS = gameState::Instance();

    std::vector< std::vector<int> > teamStarterID = gameS->getTeamStarterID();

    std::vector<Ogre::Vector3> startingPos;
    directions playerDirection; // stores the direction players face at start
    // set initial player coordinates for the tipoff

	if (teamNumber == 0)	// assigns the positions and directions for team 1 players
	{
		float y = 0.0f;
		// assign positions
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        y = -0.0f;
#else
        y = -23.5f;
#endif

        startingPos.push_back(Ogre::Vector3(14.4f,y,352.0f));
        startingPos.push_back(Ogre::Vector3(2.0f,y,347.6f));
        startingPos.push_back(Ogre::Vector3(2.0f,y,360.0f));
        startingPos.push_back(Ogre::Vector3(5.2f,y,351.6f));
        startingPos.push_back(Ogre::Vector3(1.6f,y,352.0f));
    
        playerDirection = RIGHT;
    }
    else if (teamNumber == 1) // assigns the positions and directions for team 2 players
    {
        float y = 0.0f;
        // assign positions
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        y = -1.5f;
#else
        y = -23.5f;
#endif

        startingPos.push_back(Ogre::Vector3(-13.8f,y,352.0f));
        startingPos.push_back(Ogre::Vector3(-0.8f,y,347.6f));
        startingPos.push_back(Ogre::Vector3(-0.8f,y,360.8f));
        startingPos.push_back(Ogre::Vector3(4.4f,y,348.8f));
        startingPos.push_back(Ogre::Vector3(-0.4f,y,352.0f));

        playerDirection = LEFT;
    }
    
    if (startingPos.size() > 0)
    {
        
//        for (size_t i=0;i<5;++i)
        size_t i = 0;
        while (i<teamStarterID[teamNumber].size())
        {
            int playerID = teamStarterID[teamNumber][i];
            logMsg("ID " +convert->toString(i) +" = " +convert->toString(playerID));

            size_t x = 0;
            while (x < playerInstance.size()) //&& playerID != playerInstance[x].getPlayerID())
            {
                if (playerID == playerInstance[x].getPlayerID())
                {
                    logMsg("Player ID = " +convert->toString(playerInstance[x].getPlayerID()));
                    logMsg("X " +convert->toString(i) +" = " +convert->toString(x));
                    playerInstance[x].setIsActive(true);    // sets the player active for startup which is used by other code such as physics and steering

                    if (playerInstance[x].getPosition() == "PG")
                    {
                        playerInstance[x].getNode()->setPosition(startingPos[0]);
                        playerInstance[x].setDirection(playerDirection);
                    }
                    else if (playerInstance[x].getPosition() == "SG")
                    {
                        playerInstance[x].getNode()->setPosition(startingPos[1]);
                        playerInstance[x].setDirection(playerDirection);
                    }
                    else if (playerInstance[x].getPosition() == "SF")
                    {
                        playerInstance[x].getNode()->setPosition(startingPos[2]);
                        playerInstance[x].setDirection(playerDirection);
                    }
                    else if (playerInstance[x].getPosition() == "PF")
                    {
                        playerInstance[x].getNode()->setPosition(startingPos[3]);
                        playerInstance[x].setDirection(playerDirection);

                    }
                    else if (playerInstance[x].getPosition() == "C")
                    {
                        playerInstance[x].getNode()->setPosition(startingPos[4]);
                        playerInstance[x].setDirection(playerDirection);
                    }
                    else
                    {
                    }
                }
                x++;
            }
            i++;
        }

//	    exit(0);
	}

}

void teamState::updatePlayerStates()  // updates the states of active players
{
    size_t x = 0;
    size_t y = 0;
    
    while (x<playerInstance.size())
    {
        while (y<activePlayerID.size())
        {
            if (playerInstance[x].getPlayerID() == activePlayerID[y])
            {
                playerInstance[x].updateState();
            }
            ++y;
        }
        ++x;
    }
}

void teamState::updatePlayerDirections()
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    gameState *gameS = gameState::Instance();
//    playerState *player = players::Instance();

    directions playerDirection, oldPlayerDirection;
//    std::vector<playerState> pInstance = getPlayerInstance();
 //   std::vector<int> playerDirection = player->getPlayerDirection(); // stores contents of playerDirectdion from players class in local variable
//    std::vector<int> oldPlayerDirection = player->getOldPlayerDirection();   // stores contents of oldPlayerDirection form players in local variable
	std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();
    std::vector<Ogre::SceneNode>::iterator playersIT;

    std::string playerID = convert->toString(playerInstance[4].getPlayerID());
//    exit(0);
//    logMsg("playerID == " +playerID);
    // checks if a player's direction has changed and rotates the model accordingly.
//    for(playersIT = playerNodes.begin(); playersIT != playerNodes.end(); ++playersIT)

    size_t x = 0;
    size_t y = 0;
//    for (size_t i = 0; i < playerInstance.size(); ++i)
    while (x<playerInstance.size())
    {
        while (y>activePlayerID.size())
        {
            if (playerInstance[x].getPlayerID() == activePlayerID[y])
            {
                playerDirection = playerInstance[x].getDirection();
                oldPlayerDirection = playerInstance[x].getOldDirection();
                if (oldPlayerDirection != playerDirection)
                {
                    /*
                    std::string oldPlayerDirect = Ogre::SingConverter::toString(oldPlayerDirection[i]);
                    std::string playerDirect = toString(playerDirection[i]);
                    std::string bballPlayer = toString(basketballInstance[0].getPlayer());
                    logMsg("oldPlayerDirection = " + oldPlayerDirect);
                    logMsg("playerDirection = " + playerDirect);
                    logMsg("bball player = " + bballPlayer);
                    playerInstance[basketballInstance[0].getPlayer()] = playerInstance[i];
        //            playerNodes.at(basketballInstance[0].getPlayer()) = playerNodes.at(i);  // sets the current player node
                    */
                    switch (oldPlayerDirection)
                    {
                        case UP:
                            switch (playerDirection)
                            {
                                case DOWN:
                                    playerInstance[x].getNode()->yaw(Ogre::Degree (180));
                                    break;
                                case LEFT:
                                    playerInstance[x].getNode()->yaw(Ogre::Degree (270));
                                    break;
                                case RIGHT:
                                    playerInstance[x].getNode()->yaw(Ogre::Degree (90));
                                    break;
                                default:
                                    break;
                            }
                            break;
                        case DOWN:
                            switch (playerDirection)
                            {
                                case UP:
                                    playerInstance[x].getNode()->yaw(Ogre::Degree (180));
                                    break;
                                case LEFT:
                                    playerInstance[x].getNode()->yaw(Ogre::Degree (90));
                                    break;
                                case RIGHT:
                                    playerInstance[x].getNode()->yaw(Ogre::Degree (270));
                                    break;
                                default:
                                    break;
                            }
                            break;
                            case LEFT:
                                switch (playerDirection)
                                {
                                    case UP:
                                        playerInstance[x].getNode()->yaw(Ogre::Degree (90));
                                        break;
                                    case DOWN:
                                        playerInstance[x].getNode()->yaw(Ogre::Degree (270));
                                        break;
                                    case RIGHT:
                                        playerInstance[x].getNode()->yaw(Ogre::Degree (180));
                                        break;
                                    default:
                                        break;
                                }
                                break;
                            case RIGHT:
                                switch (playerDirection)
                                {
                                    case UP:
                                        playerInstance[x].getNode()->yaw(Ogre::Degree (270));
                                        break;
                                    case DOWN:
                                        playerInstance[x].getNode()->yaw(Ogre::Degree (90));
                                        break;
                                    case LEFT:
                                        playerInstance[x].getNode()->yaw(Ogre::Degree (180));
                                        break;
                                    default:
                                        break;
                                }
                                break;
                        default:
                            break;
                    }
                }

                if (playerInstance[x].getPlayerID() != playerWithBall)
                {
                    oldPlayerDirection = playerDirection;
                    playerInstance[x].setOldDirection(oldPlayerDirection);  // copies contents of oldPlayerDirection to the oldDirection variable
                }
                else
                {
                }
            }
            ++y;
        }
        ++x;
    }
}


void teamState::updatePlayerMovements()	// updates player movements
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    
    Ogre::Vector3 posChange;	// stores change in position
	posChange = Ogre::Vector3(0.0f, 0.0f, 0.0f);

    size_t x = 0;
    size_t y = 0;
//	for (size_t i = 0; i < playerInstance.size(); ++i)
    while(x<playerInstance.size())
	{
//		logMsg("Player " +convert->toString(i) +" position = " +convert->toString(playerInstance[i].getNodePosition()));

//        Ogre::LogManager::getSingletonPtr()->logMessage("i == " +convert->toString(i));

        while (y<activePlayerID.size())
        {
            if (playerInstance[x].getPlayerID() == activePlayerID[y])
            {
                if (playerInstance[x].getMovement())	// if true sets coordinate change accordingly
                {
//                    exit(0);
                    if (playerInstance[x].getDirection() == UP)
                    {
                        posChange = Ogre::Vector3(0.0f, 0.0f, -0.400f);
                        logMsg("UP!");
        //				exit(0);
                    }
                    else if (playerInstance[x].getDirection() == DOWN)
                    {
                        posChange = Ogre::Vector3(0.0f, 0.0f, 0.400f);
                    }
                    else if (playerInstance[x].getDirection() == LEFT)
                    {
        //			    exit(0);

                        posChange = Ogre::Vector3(-0.400f, 0.0f, 0.0f);
        //			    playerInstance[i].getPhysBody()->setLinearVelocity(btVector3(0.4,0,0));
                    }
                    else if (playerInstance[x].getDirection() == RIGHT)
                    {
                        posChange = Ogre::Vector3(0.400f, 0.0f, 0.0f);
                    }
                    else if (playerInstance[x].getDirection() == UPLEFT)
                    {
                        posChange = Ogre::Vector3(-0.400f, 0.0f, -0.400f);
                    }
                    else if (playerInstance[x].getDirection() == UPRIGHT)
                    {
                        posChange = Ogre::Vector3(0.400f, 0.0f, -0.400f);
                    }
                    else if (playerInstance[x].getDirection() == DOWNLEFT)
                    {
                        posChange = Ogre::Vector3(-0.400f, 0.0f, 0.400f);
                    }
                    else if (playerInstance[x].getDirection() == DOWNRIGHT)
                    {
                        posChange = Ogre::Vector3(0.400f, 0.0f, 0.400f);
                    }

                }
                else if (!playerInstance[x].getMovement())	// if false then sets their coordinate changes to 0.0
                {
                    posChange = Ogre::Vector3(0.0f, 0.0f, 0.0f);
                }

                playerInstance[x].setPosChange(posChange);	// sets the posChange for current playerInstance
        /*		if (i != playerWithBall)	// only updates movement flag if player doesn't have ball
                {
                playerInstance[i].setMovement(false);
                }
                else
                {
                }	*/
                playerInstance[x].setMovement(false);
            }
            ++y;
        }
        ++x;
	}

//	exit(0);
}

// FIXME! update for class reorganization

void teamState::executePass()		// executes the pass between players
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    gameState *gameS = gameState::Instance();

    logMsg("In executePass function");

	int passToPlayer = playerInstance[playerWithBall].getPassToPlayer();
	std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();
	Ogre::Vector3 playerWithBallCoords = playerInstance[playerWithBall].getNode()->getPosition();
	Ogre::Vector3 passToPlayerCoords = playerInstance[passToPlayer].getNode()->getPosition();
//	exit(0);
	Ogre::Vector3 bballCoords = basketballInstance[0].getNode()->getPosition();
	btVector3 bballPosChange;
	btVector3 bballPhysCoords;
	btTransform transform;
//	exit(0);
    logMsg("Basketball = " + convert->toString(bballCoords));
    logMsg("passToPlayer = " + convert->toString(passToPlayerCoords));

    if (bballCoords[1] != passToPlayerCoords[1])
    {
    	bballCoords[1] = passToPlayerCoords[1];
    	basketballInstance[0].getNode()->setPosition(bballCoords);
		bballPhysCoords = BtOgre::Convert::toBullet(bballCoords); // converts from Ogre::Vector3 to btVector3
		transform.setOrigin(bballPhysCoords);
		basketballInstance[0].getPhysBody()->setWorldTransform(transform);


    }
	if (bballCoords[0] < passToPlayerCoords[0])
	{
		if (bballCoords[2] < passToPlayerCoords[2])
		{
//	    	basketballInstance[0].getPhysBody()->setLinearVelocity(btVector3(15,0,15));
			bballPosChange[0] = 15;
			bballPosChange[2] = 15;
		}
		else if (bballCoords[2] > passToPlayerCoords[2])
		{
//	    	basketballInstance[0].getPhysBody()->setLinearVelocity(btVector3(15,0,-15));
			bballPosChange[0] = 15;
			bballPosChange[2] = -15;

		}
		else
		{
		}
	}
	else if (bballCoords[0] > passToPlayerCoords[0])
	{
		if (bballCoords[2] < passToPlayerCoords[2])
		{
//	    	basketballInstance[0].getPhysBody()->setLinearVelocity(btVector3(-15,0,15));
			bballPosChange[0] = -15;
			bballPosChange[2] = 15;

		}
		else if (bballCoords[2] > passToPlayerCoords[2])
		{
//	    	basketballInstance[0].getPhysBody()->setLinearVelocity(btVector3(-15,0,-15));
			bballPosChange[0] = -15;
			bballPosChange[2] = -15;

		}
		else
		{
		}
	}
	else
	{
	}

	basketballInstance[0].getPhysBody()->setLinearVelocity(btVector3(bballPosChange));


	gameS->setBasketballInstance(basketballInstance);		// saves changes to the basketballInstance object
}


void teamState::updatePositions()
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    
    size_t x = 0;
	// updates the player positions on the court
//	for (size_t x = 0; x < playerInstance.size(); ++x)
    while (x<playerInstance.size())
	{
//		logMsg("updatePositions X = " +convert->toString(x));
        size_t i = 0;
        while (i<activePlayerID.size())
        {
            if (activePlayerID[i] == playerInstance[x].getPlayerID())
            {
                playerInstance[x].updatePosition();
            }
            i++;
        }
        x++;
    }

}


