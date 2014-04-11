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
 *   along with this program; if not, write to the         n                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "teamstate.h"
#include "gamestate.h"
#include "physicsengine.h"
#include "players.h"

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

    offenseInstance = new offenseState;
    defenseInstance = new defenseState;

	playerInstancesCreated = false;
    playerWithBall = -1;
    playerWithBallDribbling = false;

    humanControlled = false;
    humanPlayer = 4;

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

vector<int> teamState::getPlayerID()  // retrieves playerID
{
    return (playerID);
}
void teamState::setPlayerID(std::vector<int> ID)   // sets playerID
{
    playerID = ID;
}
vector<int> teamState::getStarterID() // retrieves starterID
{
    return (starterID);
}
void teamState::setStarterID(std::vector<int> ID)  // sets starterID
{
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

void teamState::setupState()	// sets up the state of the object
{
	physicsEngine *physEngine = physicsEngine::Instance();
    if (!playerInstancesCreated)	// checks if playerInstances have been created
    {
    	if (createPlayerInstances()) // creates the player instances based on playerIDS
		{
    		playerInstancesCreated = true;
//        	exit(0);
		}
    }
    setPlayerStartPositions();	// sets starting positions for the players

//    playerWithBall = 3; // FIXME! Temporarily ahrd code player controlling ball
//    humanPlayer = 3;	// sets the human controlled player to the center for tip off
/*    player->mAnimationState2 =  playerInstance[5].getModel()->getAnimationState("Walk");
    player->mAnimationState2->setLoop(true);
    player->mAnimationState2->setEnabled(true);
*/
}
void teamState::updateState()	// updates the state of the object
{
	
//	exit(0);
	gameState *gameS = gameState::Instance();
	physicsEngine *physEngine = physicsEngine::Instance();

	Ogre::LogManager::getSingletonPtr()->logMessage("Updating team state " +Ogre::StringConverter::toString(teamNumber));
	if (gameS->getBasketballModelLoaded() && playerInstancesCreated)
	{
		std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();

//		exit(0);
		// checks whether to execute offense or defense logic
		if (offense == true && defense == false)
		{
			offenseInstance->setExecute(true);
			defenseInstance->setExecute(false);
		}
		else if (defense == true && offense == false)
		{
			offenseInstance->setExecute(true);
			defenseInstance->setExecute(false);
		}
		else
		{

		}

		if (gameS->getTipOffComplete())
		{
//			exit(0);
			Ogre::LogManager::getSingletonPtr()->logMessage("Team with ball ==  "  +Ogre::StringConverter::toString(gameS->getTeamWithBall()));
			Ogre::LogManager::getSingletonPtr()->logMessage("Player with ball ==  "  +Ogre::StringConverter::toString(playerWithBall));

			if (gameS->getTeamWithBall() == teamNumber) // checks if the team has the basketball
			{
				if (!playerInstance[playerWithBall].getPassBall())	// checks if the player with ball is passing it.
				{
	//				exit(0);
				}
				else if (playerInstance[playerWithBall].getPassBall())
				{
					Ogre::LogManager::getSingletonPtr()->logMessage("Calculating Pass");
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
							exit(0);
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
				Ogre::LogManager::getSingletonPtr()->logMessage("Player with ball ==  "  +Ogre::StringConverter::toString(playerWithBall));
				Ogre::LogManager::getSingletonPtr()->logMessage("Player with ball's name: "  +playerInstance[playerWithBall].getPlayerName());
				Ogre::LogManager::getSingletonPtr()->logMessage("Player with ball's current position: "  +Ogre::StringConverter::toString(playerInstance[playerWithBall].getNode()->getPosition()));
			}
		}

		updatePlayerMovements();	// updates movement of player objects
		updatePlayerDirections();	// updates the direction the players are facing
//		exit(0);


		if (physEngine->getPlayerPhysicsSetup())	// makes sure player physics are setup before modifying physics positions
		{
			updatePositions();
		}
		else
		{
		}
//		Ogre::LogManager::getSingletonPtr()->logMessage("Team ==  "  +Ogre::StringConverter::toString(teamNumber));

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
	        defenseInstance->updateState(); // updates the state of the defenseInstance object
	    }
	}
	else
	{
	}
	
	Ogre::LogManager::getSingletonPtr()->logMessage("team state updated = " +Ogre::StringConverter::toString(teamNumber));
}

bool teamState::createPlayerInstances()
{
//    players *player = players::Instance();

	gameState *gameS = gameState::Instance();

	std::vector<playerData> playerDataInstance = gameS->getPlayerDataInstance();
	int x = 0;
	//	int playerID =
//    std::vector <playerData> playerN = player->getPlayer(); // copies Player values to playerN
    std::vector <playerData>::iterator playerIT;
//    std::vector <playerState>::iterator pInstanceIT;
    Ogre::LogManager::getSingletonPtr()->logMessage("Creating players");


    Ogre::LogManager::getSingletonPtr()->logMessage("playerDataInstance size = " +Ogre::StringConverter::toString(playerDataInstance.size()));
//    exit(0);
//    for (playerIT = playerDataInstance.begin(); playerIT != playerDataInstance.end(); ++playerIT)   // loops through playerID std::vector
    for (size_t i = 0;i < playerDataInstance.size(); ++i)
    {

            playerState pInstance;  // creates a new instance of playerState
/*            pInstance.setModelName(playerDataInstance[playerIT].getModel());  // copies the model name from the playerData std::vector to the pInstance class
            pInstance.setFirstName(playerDataInstance[*playerIT]->getFirstName());  // copies the first name from the playerData std::vector to the pInstance class
            pInstance.setLastName(playerDataInstance[*playerIT]->getLastName());    // copies the last name from the playerData std::vector to the pInstance class
            pInstance.setPlayerName(playerDataInstance[*playerIT]->getFirstName() + playerN[*playerIT]->getLastName());
            pInstance.setPosChange(Ogre::Vector3(0.0f,0.0f,0.0f));
*/
//    	    Ogre::LogManager::getSingletonPtr()->logMessage("Player Team ID = " +Ogre::StringConverter::toString(playerDataInstance[i].getTeamID()));
//    	    Ogre::LogManager::getSingletonPtr()->logMessage("Team Number = " +Ogre::StringConverter::toString(teamNumber));

            if (playerDataInstance[i].getTeamID() == teamNumber)	// checks if player is assigned to this team
            {
				pInstance.setModelName(playerDataInstance[i].getModel());
				pInstance.setFirstName(playerDataInstance[i].getFirstName());  // copies the first name from the playerData std::vector to the pInstance class
				pInstance.setLastName(playerDataInstance[i].getLastName());    // copies the last name from the playerData std::vector to the pInstance class
				pInstance.setPlayerName(playerDataInstance[i].getFirstName() + " " +playerDataInstance[i].getLastName());
				pInstance.setPosChange(Ogre::Vector3(0.0f,0.0f,0.0f));
				playerInstance.push_back(pInstance);    // adds pInstance to the playerInstance std::vector.
				Ogre::LogManager::getSingletonPtr()->logMessage("player name = " +pInstance.getPlayerName());
            }
            else
            {
            }
    }
//    Ogre::LogManager::getSingletonPtr()->logMessage("playerInstance size = " +Ogre::StringConverter::toString(playerInstance.size()));

//    exit(0);
//    std::vector <playerState>::iterator pInstanceIT;


    for (size_t pInstanceIT = 0; pInstanceIT < playerInstance.size(); ++pInstanceIT)
    {
    	if (std::find(playerModelsLoaded.begin(), playerModelsLoaded.end(), playerInstance[pInstanceIT].getPlayerName()) != playerModelsLoaded.end())
    	{
//    		cout << "Found Player Name in list of loaded Models, NOT Loading" << endl;
    	    Ogre::LogManager::getSingletonPtr()->logMessage("Found Player Name in list of loaded Models, NOT Loading");

    	}
    	else
    	{
			if (playerInstance[pInstanceIT].loadModel())	// if player model loads successfully add to loaded models vector
			{
				playerModelsLoaded.push_back(playerInstance[pInstanceIT].getPlayerName());
	    	    Ogre::LogManager::getSingletonPtr()->logMessage("Loading Player Model");
//	    	    exit(0);

			}
    	}
            x += 1;
            cout << "x = " << x << endl;
    }
    return true;
}

void teamState::setPlayerStartPositions()	// sets the initial coordinates for the players.
{

    // set initial player coordinates for the tipoff

	if (teamNumber == 0)	// assigns the positions and directions for team 1 players
	{
		float y = 0.0f;
		// assign positions
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        y = -1.5f;
#else
        y = -23.5f
#endif
		playerInstance[0].getNode()->setPosition(14.4f,y,352.0f);
	    playerInstance[1].getNode()->setPosition(2.0f,y,347.6f);
	    playerInstance[2].getNode()->setPosition(2.0f,y,360.0f);
	    playerInstance[3].getNode()->setPosition(5.2f,y,351.6f);
	    playerInstance[4].getNode()->setPosition(1.6f,y,352.0f);

	    // assign directions
	    playerInstance[0].setDirection(RIGHT);
	    playerInstance[1].setDirection(RIGHT);
	    playerInstance[2].setDirection(RIGHT);
	    playerInstance[3].setDirection(RIGHT);
	    playerInstance[4].setDirection(RIGHT);

	}
	else if (teamNumber == 1) // assigns the positions and directions for team 2 players
	{
		float y = 0.0f;
		// assign positions
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        y = -1.5f;
#else
        y = -23.5f
#endif
	    playerInstance[0].getNode()->setPosition(-12.8f,y,352.0f);
	    playerInstance[1].getNode()->setPosition(-0.8f,y,347.6f);
	    playerInstance[2].getNode()->setPosition(-0.8f,y,360.8f);
	    playerInstance[3].getNode()->setPosition(4.4f,y,348.8f);
	    playerInstance[4].getNode()->setPosition(-0.4f,y,352.0f);

	    // assign directions
	    playerInstance[0].setDirection(LEFT);
	    playerInstance[1].setDirection(LEFT);
	    playerInstance[2].setDirection(LEFT);
	    playerInstance[3].setDirection(LEFT);
	    playerInstance[4].setDirection(LEFT);

	}
	else
	{
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
    Ogre::LogManager::getSingletonPtr()->logMessage("playerID == " +playerID);
    // checks if a player's direction has changed and rotates the model accordingly.
//    for(playersIT = playerNodes.begin(); playersIT != playerNodes.end(); ++playersIT)
    for (size_t i = 0; i < playerInstance.size(); ++i)
    {
    	playerDirection = playerInstance[i].getDirection();
    	oldPlayerDirection = playerInstance[i].getOldDirection();
        if (oldPlayerDirection != playerDirection)
        {
        	/*
        	Ogre::String oldPlayerDirect = Ogre::StringConverter::toString(oldPlayerDirection[i]);
        	Ogre::String playerDirect = Ogre::StringConverter::toString(playerDirection[i]);
        	Ogre::String bballPlayer = Ogre::StringConverter::toString(basketballInstance[0].getPlayer());
            Ogre::LogManager::getSingletonPtr()->logMessage("oldPlayerDirection = " + oldPlayerDirect);
            Ogre::LogManager::getSingletonPtr()->logMessage("playerDirection = " + playerDirect);
            Ogre::LogManager::getSingletonPtr()->logMessage("bball player = " + bballPlayer);
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
        Ogre::LogManager::getSingletonPtr()->logMessage("i == " +Ogre::StringConverter::toString(i));

		if (playerInstance[i].getMovement())	// if true sets coordinate change accordingly
		{
//			exit(0);
			if (playerInstance[i].getDirection() == UP)
			{
				posChange = Ogre::Vector3(0.0f, 0.0f, -0.400f);
//				exit(0);
			}
			else if (playerInstance[i].getDirection() == DOWN)
			{
				posChange = Ogre::Vector3(0.0f, 0.0f, 0.400f);
			}
			else if (playerInstance[i].getDirection() == LEFT)
			{
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
	Ogre::LogManager::getSingletonPtr()->logMessage("In executePass function");

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
    Ogre::LogManager::getSingletonPtr()->logMessage("Basketball = " + Ogre::StringConverter::toString(bballCoords));
    Ogre::LogManager::getSingletonPtr()->logMessage("passToPlayer = " + Ogre::StringConverter::toString(passToPlayerCoords));

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

	// updates the player positions on the court
	for (size_t x = 0; x < playerInstance.size(); ++x)
	{
		Ogre::LogManager::getSingletonPtr()->logMessage("updatePositions X = " +Ogre::StringConverter::toString(x));
        playerInstance[x].updatePosition();
    }

}


