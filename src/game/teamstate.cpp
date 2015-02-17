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

    stateSet = false;
//    setupState();
}

teamState::~teamState()
{
}

int teamState::getTeamNumber()	// retrieves the value of the teamNumber variable
{
	return (teamNumber);
}
void teamState::setTeamNumber(int number)	// sets the value of the teamNumber variable
{
	teamNumber = number;
}

Ogre::String teamState::getPlayerType()	// retrieves playerType variable
{
	return (playerType);
}
void teamState::setPlayerType(Ogre::String type)	// sets playerType variable
{
	playerType = type;
}
int teamState::getAssists(void)   // retrieves assists
{
    return (assists);
}
void teamState::setAssists(int assist)    // sets assists
{
    assists = assist;
}

int teamState::getBlocks(void)    // retrieves blocks
{
    return (blocks);
}
void teamState::setBlocks(int block)   // sets blocks
{
    blocks = block;
}

int teamState::getFouls(void) // retrieves fouls
{
    return (fouls);
}
void teamState::setFouls(int foul)    // sets fouls
{
    fouls = foul;
}

int teamState::getRebounds(void)  // retrieves rebounds
{
    return (rebounds);
}
void teamState::setRebounds(int rebound)  // sets rebounds
{
    rebounds = rebound;
}

int teamState::getOffensiveRebounds(void) // retrieves offensiveRebounds
{
    return (offensiveRebounds);
}
void teamState::setOffensiveRebounds(int rebounds)    // sets offensiveRebounds
{
    offensiveRebounds = rebounds;
}
int teamState::getDefensiveRebounds(void) // retrieves defensiveRebounds
{
    return (defensiveRebounds);
}
void teamState::setDefensiveRebounds(int rebounds)    // sets defensiveRebounds
{
    defensiveRebounds = rebounds;
}

int teamState::getSteals(void)    // retrieves steals
{
    return (steals);
}
void teamState::setSteals(int steal)    // sets steals
{
    steals = steal;
}

int teamState::getTechnicals(void)    // retrieves technicals
{
    return (technicals);
}
void teamState::setTechnicals(int technical)  // sets technicals
{
    technicals = technical;
}

int teamState::getTimeouts(void)  // retrieves timeouts
{
    return (timeouts);
}
void teamState::setTimeouts(int timeout)  // sets timeouts
{
    timeouts = timeout;
}

int teamState::getTurnovers() // retrieves turnovers variable
{
	return (turnovers);
}
void teamState::setTurnovers(int turnover)    // sets turnovers variable
{
	turnovers = turnover;
}

int teamState::getFieldGoalsAttempted(void)   // retrieves fieldGoalsAttempted
{
    return (fieldGoalsAttempted);
}
void teamState::setFieldGoalsAttempted(int fieldGoals)    // sets fieldGoalsAttempted
{
    fieldGoalsAttempted = fieldGoals;
}

int teamState::getFieldGoalsMade(void)   // retrieves fieldGoalsMade
{
    return (fieldGoalsMade);
}
void teamState::setFieldGoalsMade(int fieldGoals)    // sets fieldGoalsMade
{
    fieldGoalsMade = fieldGoals;
}

int teamState::getThreePointersAttempted(void)   // retrieves threePointersAttempted
{
    return (threePointersAttempted);
}
void teamState::setThreePointersAttempted(int threePointers)  // sets threePointersAttempted
{
    threePointersAttempted = threePointers;
}

int teamState::getThreePointersMade(void)   // retrieves threePointersMade
{
    return (threePointersMade);
}
void teamState::setThreePointersMade(int threePointers)  // sets threePointersMade
{
    threePointersMade = threePointers;
}

int teamState::getFreeThrowsAttempted(void)   // retrieves freeThrowsAttempted
{
    return (freeThrowsAttempted);
}
void teamState::setFreeThrowsAttempted(int freeThrows)    // sets freeThrowsAttempted
{
    freeThrowsAttempted = freeThrows;
}

int teamState::getFreeThrowsMade(void)   // retrieves freeThrowsMade
{
    return (freeThrowsMade);
}
void teamState::setFreeThrowsMade(int freeThrows)    // sets freeThrowsMade
{
    freeThrowsMade = freeThrows;
}

std::vector<int> teamState::getPlayerID()  // retrieves playerID
{
    return (playerID);
}
void teamState::setPlayerID(std::vector<int> ID)   // sets playerID
{
    playerID = ID;
}


std::vector<int> teamState::getActivePlayerID()  // retrieves activePlayerID variable
{
    return (activePlayerID);
}
void teamState::setActivePlayerID(std::vector<int> ID)   // sets activePlayerID variable
{
    activePlayerID = ID;
}

std::vector<int> teamState::getStarterID() // retrieves starterID
{
    return (starterID);
}
void teamState::setStarterID(std::vector<int> ID)  // sets starterID
{
    logMsg("blap");
    starterID = ID;
}

bool teamState::getOffense()	// returns offense variable
{
	return (offense);
}
void teamState::setOffense(bool set)	// sets offense variable
{
	offense = set;
}
bool teamState::getDefense()	// returns defense variable
{
	return (defense);
}
void teamState::setDefense(bool set)	// sets defense variable
{
	defense = set;
}

// gets and sets playerInstance std::vector
std::vector <playerState> teamState::getPlayerInstance()
{
    return (playerInstance);
}

void teamState::setPlayerInstance(std::vector<playerState> pInstance)
{
    playerInstance = pInstance;
}

bool teamState::getPlayerInstancesCreated()	// retrieves the value of the playerInstancesCreated variable
{
	return (playerInstancesCreated);
}
void teamState::setPlayerInstancesCreated(bool created)	// sets the value of the playerInstancesCreated variable
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

bool teamState::getHumanControlled()		// retrieves the value of the humanControlled variable
{
	return (humanControlled);
}
void teamState::setHumanControlled(bool controlled)		// sets the value of the humanControlled variable
{
	humanControlled = controlled;
}

int teamState::getHumanPlayer()		// retrieves the value of the humanPlayer variable
{
	return (humanPlayer);
}
void teamState::setHumanPlayer(int player)		// sets the value of the human player variable
{
	humanPlayer = player;
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
	gameEngine *gameE = gameEngine::Instance();
	gameState *gameS = gameState::Instance();
	physicsEngine *physEngine = physicsEngine::Instance();

//	logMsg("Updating team state " +Ogre::StringConverter::toString(teamNumber));
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
//			logMsg("Team with ball ==  "  +Ogre::StringConverter::toString(gameS->getTeamWithBall()));
//			logMsg("Player with ball ==  "  +Ogre::StringConverter::toString(playerWithBall));

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
//				logMsg("Player with ball ==  "  +Ogre::StringConverter::toString(playerWithBall));
//			    logMsg("Player with ball's name: "  +playerInstance[playerWithBall].getPlayerName());
//				logMsg("Player with ball's current position: "  +Ogre::StringConverter::toString(playerInstance[playerWithBall].getNode()->getPosition()));
			}
		}

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


//   logMsg("team state updated = " +Ogre::StringConverter::toString(teamNumber));
}

bool teamState::createPlayerInstances()
{
//    players *player = players::Instance();

	gameState *gameS = gameState::Instance();

    std::vector< std::vector<int> > teamStarterID = gameS->getTeamStarterID();
	std::vector<playerData> playerDataInstance = gameS->getPlayerDataInstance();
//	int x = 0;
	//	int playerID =
//    std::vector <playerData> playerN = player->getPlayer(); // copies Player values to playerN
    std::vector <playerData>::iterator playerIT;
//    std::vector <playerState>::iterator pInstanceIT;
    logMsg("Creating players");


    logMsg("playerDataInstance size = " +Ogre::StringConverter::toString(playerDataInstance.size()));
//    exit(0);
//    for (playerIT = playerDataInstance.begin(); playerIT != playerDataInstance.end(); ++playerIT)   // loops through playerID std::vector
    int id = -1; // stores id for steer
    size_t i = 0;
    
    //    for (size_t i = 0;i < playerDataInstance.size(); ++i)
    while (i<playerDataInstance.size())
    {

        playerState pInstance;  // creates a new instance of playerState
        playerSteer *pSteer = new playerSteer; // steer instance

//    	    logMsg("Player Team ID = " +Ogre::StringConverter::toString(playerDataInstance[i].getTeamID()));
//    	    logMsg("Team Number = " +Ogre::StringConverter::toString(teamNumber));

        if (playerDataInstance[i].getTeamID() == teamNumber)	// checks if player is assigned to this team
        {
            id += 1;
            pInstance.setModelName(playerDataInstance[i].getModel());
            pInstance.setFirstName(playerDataInstance[i].getFirstName());  // copies the first name from the playerData std::vector to the pInstance class
            pInstance.setLastName(playerDataInstance[i].getLastName());    // copies the last name from the playerData std::vector to the pInstance class
            pInstance.setPlayerName(playerDataInstance[i].getFirstName() + " " +playerDataInstance[i].getLastName());
            pInstance.setPlayerID(playerDataInstance[i].getID());
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
	        logMsg("steerID = " +Ogre::StringConverter::toString(pInstance.getSteer()->getID()));
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
//        logMsg("ID " +Ogre::StringConverter::toString(i) +" = " +Ogre::StringConverter::toString(playerID));
    logMsg("activePlayerID.size() = " +Ogre::StringConverter::toString(activePlayerID.size()));
//    logMsg("playerID = " +Ogre::StringConverter::toString(activePlayerID[i]));
    size_t x = 0;

    logMsg("playerInstance.size() = " +Ogre::StringConverter::toString(playerInstance.size()));

    bool IDMatch = false;
//            for (size_t j=0;j<playerInstance.size();++j)
    while (x<playerInstance.size())
    {
        size_t i = 0;
//        while (!IDMatch && x < playerInstance.size())
        while (i<activePlayerID.size())
        {

            logMsg("playerInstance[x].getPlayerID() = " +Ogre::StringConverter::toString(playerInstance[x].getPlayerID()));
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
        y = -1.5f;
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

        startingPos.push_back(Ogre::Vector3(-12.8f,y,352.0f));
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
            logMsg("ID " +Ogre::StringConverter::toString(i) +" = " +Ogre::StringConverter::toString(playerID));

            size_t x = 0;
            while (x < playerInstance.size()) //&& playerID != playerInstance[x].getPlayerID())
            {
                if (playerID == playerInstance[x].getPlayerID())
                {
                    logMsg("Player ID = " +Ogre::StringConverter::toString(playerInstance[x].getPlayerID()));
                    logMsg("X " +Ogre::StringConverter::toString(i) +" = " +Ogre::StringConverter::toString(x));
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
	gameState *gameS = gameState::Instance();
//    playerState *player = players::Instance();

    directions playerDirection, oldPlayerDirection;
//    std::vector<playerState> pInstance = getPlayerInstance();
 //   std::vector<int> playerDirection = player->getPlayerDirection(); // stores contents of playerDirectdion from players class in local variable
//    std::vector<int> oldPlayerDirection = player->getOldPlayerDirection();   // stores contents of oldPlayerDirection form players in local variable
	std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();
    std::vector<Ogre::SceneNode>::iterator playersIT;

    Ogre::String playerID = Ogre::StringConverter::toString(playerInstance[4].getPlayerID());
//    exit(0);
//    logMsg("playerID == " +playerID);
    // checks if a player's direction has changed and rotates the model accordingly.
//    for(playersIT = playerNodes.begin(); playersIT != playerNodes.end(); ++playersIT)
    for (size_t i = 0; i < playerInstance.size(); ++i)
    {
    	playerDirection = playerInstance[i].getDirection();
    	oldPlayerDirection = playerInstance[i].getOldDirection();
        if (oldPlayerDirection != playerDirection)
        {
        	/*
        	Ogre::String oldPlayerDirect = Ogre::SingConverter::toString(oldPlayerDirection[i]);
        	Ogre::String playerDirect = toString(playerDirection[i]);
        	Ogre::String bballPlayer = toString(basketballInstance[0].getPlayer());
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
                            playerInstance[i].getNode()->yaw(Ogre::Degree (180));
                            break;
                        case LEFT:
                            playerInstance[i].getNode()->yaw(Ogre::Degree (270));
                            break;
                        case RIGHT:
                            playerInstance[i].getNode()->yaw(Ogre::Degree (90));
                            break;
                        default:
                            break;
                    }
                	break;
                case DOWN:
                	switch (playerDirection)
                    {
                        case UP:
                            playerInstance[i].getNode()->yaw(Ogre::Degree (180));
                            break;
                        case LEFT:
                            playerInstance[i].getNode()->yaw(Ogre::Degree (90));
                            break;
                        case RIGHT:
                            playerInstance[i].getNode()->yaw(Ogre::Degree (270));
                            break;
                        default:
                            break;
                    }
                	break;
                	case LEFT:
                    	switch (playerDirection)
                        {
                            case UP:
                                playerInstance[i].getNode()->yaw(Ogre::Degree (90));
                                break;
                            case DOWN:
                                playerInstance[i].getNode()->yaw(Ogre::Degree (270));
                                break;
                            case RIGHT:
                                playerInstance[i].getNode()->yaw(Ogre::Degree (180));
                                break;
                            default:
                                break;
                        }
                    	break;
					case RIGHT:
						switch (playerDirection)
						{
							case UP:
								playerInstance[i].getNode()->yaw(Ogre::Degree (270));
								break;
							case DOWN:
								playerInstance[i].getNode()->yaw(Ogre::Degree (90));
								break;
							case LEFT:
								playerInstance[i].getNode()->yaw(Ogre::Degree (180));
								break;
							default:
								break;
						}
						break;
                default:
                	break;
            }
        }

        if (i != playerWithBall)
        {
        	oldPlayerDirection = playerDirection;
        	playerInstance[i].setOldDirection(oldPlayerDirection);  // copies contents of oldPlayerDirection to the oldDirection variable
        }
        else
        {
        }
    }
}


void teamState::updatePlayerMovements()	// updates player movements
{
	Ogre::Vector3 posChange;	// stores change in position
	posChange = Ogre::Vector3(0.0f, 0.0f, 0.0f);
	for (size_t i = 0; i < playerInstance.size(); ++i)
	{
//		logMsg("Player " +Ogre::StringConverter::toString(i) +" position = " +Ogre::StringConverter::toString(playerInstance[i].getNodePosition()));

//        Ogre::LogManager::getSingletonPtr()->logMessage("i == " +Ogre::StringConverter::toString(i));

		if (playerInstance[i].getMovement())	// if true sets coordinate change accordingly
		{
//			exit(0);
			if (playerInstance[i].getDirection() == UP)
			{
				posChange = Ogre::Vector3(0.0f, 0.0f, -0.400f);
				logMsg("UP!");
//				exit(0);
			}
			else if (playerInstance[i].getDirection() == DOWN)
			{
				posChange = Ogre::Vector3(0.0f, 0.0f, 0.400f);
			}
			else if (playerInstance[i].getDirection() == LEFT)
			{
//			    exit(0);

				posChange = Ogre::Vector3(-0.400f, 0.0f, 0.0f);
//			    playerInstance[i].getPhysBody()->setLinearVelocity(btVector3(0.4,0,0));
			}
			else if (playerInstance[i].getDirection() == RIGHT)
			{
				posChange = Ogre::Vector3(0.400f, 0.0f, 0.0f);
			}
			else if (playerInstance[i].getDirection() == UPLEFT)
			{
				posChange = Ogre::Vector3(-0.400f, 0.0f, -0.400f);
			}
			else if (playerInstance[i].getDirection() == UPRIGHT)
			{
				posChange = Ogre::Vector3(0.400f, 0.0f, -0.400f);
			}
			else if (playerInstance[i].getDirection() == DOWNLEFT)
			{
				posChange = Ogre::Vector3(-0.400f, 0.0f, 0.400f);
			}
			else if (playerInstance[i].getDirection() == DOWNRIGHT)
			{
				posChange = Ogre::Vector3(0.400f, 0.0f, 0.400f);
			}

		}
		else if (!playerInstance[i].getMovement())	// if false then sets their coordinate changes to 0.0
		{
			posChange = Ogre::Vector3(0.0f, 0.0f, 0.0f);
		}

		playerInstance[i].setPosChange(posChange);	// sets the posChange for current playerInstance
/*		if (i != playerWithBall)	// only updates movement flag if player doesn't have ball
		{
		playerInstance[i].setMovement(false);
		}
		else
		{
		}	*/
		playerInstance[i].setMovement(false);
	}

//	exit(0);
}

// FIXME! update for class reorganization

void teamState::executePass()		// executes the pass between players
{
	logMsg("In executePass function");

	gameState *gameS = gameState::Instance();

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
    logMsg("Basketball = " + Ogre::StringConverter::toString(bballCoords));
    logMsg("passToPlayer = " + Ogre::StringConverter::toString(passToPlayerCoords));

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

    size_t x = 0;
	// updates the player positions on the court
//	for (size_t x = 0; x < playerInstance.size(); ++x)
    while (x<playerInstance.size())
	{
//		logMsg("updatePositions X = " +Ogre::StringConverter::toString(x));
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


