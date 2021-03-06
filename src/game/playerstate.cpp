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

#include "playerstate.h"
#include "renderengine.h"
#include "gamestate.h"
#include "logging.h"
#include "physicsengine.h"
#include "steering.h"
#include "teamstate.h"
#include "Ogre.h"


playerState::playerState()
{
    playerID = 0;
    teamNumber = -1;
    isActive = false;
    modelLoaded = false;
    networkControlled = false;
    playerXCoord = 0;
    playerYCoord = 0;
    offDef = 0;
    defending = -1;
    position = -1;
    userControlled = false;
    user = -1;
    points = 0;
    fouls = 0;
    offensiveRebounds = 0;
    defensiveRebounds = 0;
    totalRebounds = 0;
    stamina = 0;
    steals = 0;
    blocks = 0;
    turnovers = 0;
    assists = 0;
    fieldGoalsAttemped = 0;
    fieldGoalsMade = 0;
    threePointersAttempted = 0;
    threePointersMade = 0;
    freeThrowsAttempted = 0;
    freeThrowsMade = 0;
    posChange = Ogre::Vector3(0.0f,0.0f,0.0f);
    movement = false;
    shootBlock = false;
    passSteal = false;
    passBall = false;
    passCalculated = false;
    passToPlayer = -1;
    shotTaken = false;
    shotSet = false;
    shotComplete = false;
	offenseSet = false;
	defenseSet = false;
    initialized = false;
    jumpSet = false;
    jumpComplete = false;
}

playerState::~playerState()
{
}




Ogre::Vector3 playerState::getNodePosition()  // retrieves the position of player node
{
    logMsg("node position = " +Ogre::StringConverter::toString(node->getPosition()));
	return (node->getPosition());
}

int playerState::getPlayerID(void)
{
    return(playerID);
}

void playerState::setPlayerID(int id)
{
    playerID = id;
}

int playerState::getTeamNumber()  // retrieves the value of teamNumber
{
    return (teamNumber);
}
void playerState::setTeamNumber(int set)  // sets the value of teamNumber
{
    teamNumber = set;
}

bool playerState::getNetworkControlled()
{
	return (networkControlled);
}

void playerState::setNetworkControlled(bool controlled)
{
	networkControlled = controlled;
}

Ogre::String playerState::getFirstName(void)
{
    return(firstName);
}

void playerState::setFirstName(Ogre::String first)
{
    firstName = first;
}

Ogre::String playerState::getLastName(void)
{
    return(lastName);
}

void playerState::setLastName(Ogre::String last)
{
    lastName = last;
}

Ogre::String playerState::getPlayerName(void)
{
    return(playerName);
}

void playerState::setPlayerName(Ogre::String name)
{
    playerName = name;
}

int playerState::getAge(void)
{
    return(age);
}

void playerState::setAge(int playerAge)
{
    age = playerAge;
}

int playerState::getHeight(void)
{
    return(height);
}

void playerState::setHeight(int playerHeight)
{
    height = playerHeight;
}

int playerState::getWeight(void)
{
    return(weight);
}

void playerState::setWeight(int playerWeight)
{
    weight = playerWeight;
}

string playerState::getPosition(void)
{
    return(position);
}

void playerState::setPosition(string set)
{
    position = set;
}

bool playerState::getIsActive() // retrieves the value of isActive
{
    return (isActive);
}
void playerState::setIsActive(bool set) // sets the value of isActive
{
    isActive = set;
}

bool playerState::getModelLoaded()  // retrieves the value of modelLoaded
{
    return (modelLoaded);
}
void playerState::setModelLoaded(bool set) // sets the value of modelLoaded
{
    modelLoaded = set;
}

// gets and sets player X and Y positions

int playerState::getPlayerXCoord(void)
{
//	cout << "dee" << endl;

//	cout << "playerXCoord = " << playerXCoord << endl;
//	cout << "dah" << endl;
    return(playerXCoord);
}

void playerState::setPlayerXCoord(int XCoord)
{
    playerXCoord = XCoord;
}

int playerState::getPlayerYCoord(void)
{
    return (playerYCoord);
}

void playerState::setPlayerYCoord(int YCoord)
{
    playerYCoord = YCoord;
}

int playerState::getOffDef(void)
{
    return(offDef);
}

void playerState::setOffDef(int set)
{
    offDef = set;
}

int playerState::getDefending(void)
{
    return (defending);
}

void playerState::setDefending(int set)
{
    defending = set;
}

bool playerState::getUserControlled(void)
{
    return(userControlled);
}

void playerState::setUserControlled(bool set)
{
    userControlled = set;
}

int playerState::getUser(void)
{
    return(user);
}

void playerState::setUser(int set)
{
    user = set;
}

int playerState::getPoints(void)
{
    return(points);
}
void playerState::setPoints(int total)
{
    points = total;
}

int playerState::getFouls(void)
{
    return(fouls);
}

void playerState::setFoulds(int total)
{
    fouls = total;
}

int playerState::getOffensiveRebounds(void)
{
    return(offensiveRebounds);
}

void playerState::setOffensiveRebounds(int rebounds)
{
    offensiveRebounds = rebounds;
}

int playerState::getDefensiveRebounds(void)
{
    return(defensiveRebounds);
}

void playerState::setDefensiveRebounds(int rebounds)
{
    defensiveRebounds = rebounds;
}

int playerState::getTotalRebounds(void)
{
    return(totalRebounds);
}

void playerState::setTotalReboundS(int rebounds)
{
    totalRebounds = rebounds;
}

int playerState::getStamina(void)
{
    return(stamina);
}

void playerState::setStamina(int total)
{
    stamina = total;
}

int playerState::getSteals(void)
{
    return(steals);
}

void playerState::setSteals(int total)
{
    steals = total;
}

int playerState::getBlocks(void)
{
    return(blocks);
}

void playerState::setBlocks(int total)
{
    blocks = total;
}

int playerState::getTurnovers(void)
{
    return(turnovers);
}

void playerState::setTurnovers(int total)
{
    turnovers = total;
}

int playerState::getAssists(void)
{
    return(assists);
}

void playerState::setAssists(int total)
{
    assists = total;
}

int playerState::getFieldGoalsAttemped(void)
{
    return(fieldGoalsAttemped);
}

void playerState::setFieldGoalsAttempted(int attempted)
{
    fieldGoalsAttemped = attempted;
}

int playerState::getFieldGoalsMade(void)
{
    return(fieldGoalsMade);
}
void playerState::setFieldGoalsmade(int made)
{
    fieldGoalsMade = made;
}

int playerState::getThreePointersAttempted(void)
{
    return(threePointersAttempted);
}

void playerState::setThreePointersAttempted(int attempted)
{
    threePointersAttempted = attempted;
}

int playerState::getThreePointersMade(void)
{
    return(threePointersMade);
}

void playerState::setThreePointersMade(int made)
{
    threePointersMade = made;
}

int playerState::getFreeThrowsAttempted(void)
{
    return(freeThrowsAttempted);
}

void playerState::setFreeThrowsAttempted(int attempted)
{
    freeThrowsAttempted = attempted;
}

int playerState::getFreeThrowsMade(void)
{
    return(freeThrowsMade);
}

void playerState::setFreeThrowsMade(int made)
{
    freeThrowsMade = made;
}

string playerState::getModelName()
{
    return (modelName);
}

void playerState::setModelName(string name)
{
    modelName = name;
}

Ogre::Entity *playerState::getModel()
{
    return (model);
}

void playerState::setModel(Ogre::Entity *Model)
{
    model = Model;
}

Ogre::SceneNode *playerState::getNode()
{
    return (node);
}

void playerState::setNode(Ogre::SceneNode *Node)
{
    node = Node;
}

btRigidBody *playerState::getPhysBody()	  // returns physBody
{
	return (physBody);
}
void playerState::setPhysBody(btRigidBody *body)  	// sets physBody
{
	physBody = body;
}

playerSteer *playerState::getSteer() // retrieves the steering instance
{
	return (steer);
}
void playerState::setSteer(playerSteer *instance) // sets the steering instance
{
	steer = instance;
}

bool playerState::getMovement()	// returns movement
{
	return (movement);
}
void playerState::setMovement(bool move)	// sets movement
{
	movement = move;
}

directions playerState::getDirection()	// retrieves the value of direction
{
	return (direction);
}
void playerState::setDirection(directions direct)	// sets direction
{
	direction = direct;
}

directions playerState::getOldDirection()	// retrieves the value of the oldDirection
{
	return (oldDirection);
}
void playerState::setOldDirection(directions direct)	// sets the value of the oldDirection
{
	oldDirection = direct;
}

Ogre::Vector3 playerState::getPosChange()  // retrieves the value of posChange
{
    return (posChange);
}
void playerState::setPosChange(Ogre::Vector3 change)  // sets the value of posChange
{
    posChange = change;
}

bool playerState::getShootBlock()  // retrieves the value of shootBlock
{
    return (shootBlock);
}
void playerState::setShootBlock(bool set)   // sets the value of shootBlock
{
    shootBlock = set;
}

bool playerState::getPassSteal()  // retrieves the value of passSteal
{
    return (passSteal);
}
void playerState::setPassSteal(bool set) // sets the value of passSteal
{
    passSteal = set;
}

bool playerState::getPassBall()	// retrieves the value of the passBall
{
	return (passBall);
}
void playerState::setPassBall(bool ball)	// sets the value of the passBall
{
	passBall = ball;
}

bool playerState::getPassCalculated()	// retrieves the value of the passCalculated
{
	return (passCalculated);
}
void playerState::setPassCalculated(bool calc)  	// sets the value of the passCalculated
{
	passCalculated = calc;
}

bool playerState::getPassCompleted()	// retrieves the value of the passCompleted
{
	return (passCompleted);
}
void playerState::setPassCompleted(bool completed)	// sets the value of the passCompleted
{
	passCompleted = completed;
}

int playerState::getPassToPlayer()	// retrieves the value of the passToPlayer
{
	return (passToPlayer);
}
void playerState::setPassToPlayer(int player)	// sets the value of the passToPlayer
{
	passToPlayer = player;
}

bool playerState::getShotTaken(void)  // retrieves the value of shotTaken
{
    return (shotTaken);
}
void playerState::setShotTaken(bool taken)  // sets the value of shotTaken
{
    shotTaken = taken;
}

bool playerState::getShotSet() // retrieves the value of shotSet
{
    return (shotSet);
}
void playerState::setShotSet(bool set)  // sets the value of shotSet
{
    shotSet = set;
}

bool playerState::getShotComplete(void) // retrieves the value of shotComplete
{
    return (shotComplete);
}
void playerState::setShotComplete(bool complete)  // sets the value of shotComplete
{
    shotComplete = complete;
}

Ogre::Vector3 playerState::getJumpBeginPos()  // retrieves the value of playerJumpBeginPos
{
    return (jumpBeginPos);
}
void playerState::setJumpBeginPos(Ogre::Vector3 set)  // sets the value of playerJumpBeginPos
{
    jumpBeginPos = set;
}

Ogre::Vector3 playerState::getJumpEndPos()  // retrieves the value of playerJumpEndPos
{
    return (jumpEndPos);
}
void playerState::setJumpEndPos(Ogre::Vector3 set)  // sets the value of playerJumpEndPos
{
    jumpEndPos = set;
}

bool playerState::getJumpSet()  // retrieves the value of jumpSet
{
    return (jumpSet);
}
void playerState::setJumpSet(bool set)  // sets the value of jumpSet
{
    jumpSet = set;
}

bool playerState::getJumpComplete()  // retrieves the value of jumpComplete
{
    return (jumpComplete);
}
void playerState::setJumpComplete(bool set)  // sets the value of jumpComplete
{
    jumpComplete = set;
}

bool playerState::getOffenseSet(void) // retrieves the value of offenseState
{
	return (offenseSet);
}
void playerState::setOffenseSet(bool set)  // sets the value of offenseState
{
	offenseSet = set;
}

bool playerState::getDefenseSet(void) // retrieves the value of defenseState
{
	return (defenseSet);
}
void playerState::setDefenseSet(bool set)  // sets the value of defenseState
{
	defenseSet = set;
}

bool playerState::getInitialized(void) // retreives the value of initialized
{
    return (initialized);
}

void playerState::setInitialized(bool set) // sets the value of initialized
{
    initialized = set;
}

bool playerState::loadModel()   // loads the player's 3D model from the file specified in modelName
{

    renderEngine *render = renderEngine::Instance();
//    playerName += firstName;    // adds the first name to playerName string
//    playerName += lastName;     // adds the last name to the playerName string

//        playerName += toString(playerNum);
    logMsg("playerName == " +playerName);
    // creates and instantiates the playerNode object
    node = render->getMSceneMgr()->getRootSceneNode()->createChildSceneNode(playerName);
    // sets the player model
    logMsg("modelName = " + modelName);
    model = render->getMSceneMgr()->createEntity(playerName, modelName);

    // attaches the model to the playerNode
    node->attachObject(model);
    // sets the size of playerNode
    node->setScale(0.28f,0.28f,0.28f);
    // sets the direction of playerNode
    node->yaw ( Degree (-270));

    initialized = true;
    return true;
}

void playerState::updateState()
{
    gameState *gameS = gameState::Instance();
    physicsEngine *physEngine = physicsEngine::Instance();
	Ogre::Vector3 playerPos;
 //   exit(0);
//    if (shotTaken && !shotComplete)	// checks if a player takes a shot

    
    if (shootBlock)
    {
        if (teamNumber == gameS->getTeamWithBall())
        {
//            shotLogic(playerPos);
//            exit(0);
            if (!shotTaken)
            {
                shotTaken = true;
            }
            physEngine->shootBasketball(teamNumber, playerID);

        }
        else
        {
            physEngine->playerJump(teamNumber, playerID);
        }
        
    }

}

bool playerState::updatePosition()  // updates the XYZ coordinates of the 3D model
{
	physicsEngine *physEngine = physicsEngine::Instance();
	logMsg("posChange = " +Ogre::StringConverter::toString(posChange));
//	cout << "posChange = " << posChange << endl;
    node->translate(posChange);
	btVector3 change = btVector3(0,0,0);
	change = BtOgre::Convert::toBullet(posChange); // converts from Ogre::Vector3 to btVector3
//	logMsg("playerPhysicsSetup = " +Ogre::StringConverter::toString(physEngine->getPlayerPhysicsSetup()));

	physBody->translate(change); // moves physics body in unison with the model
//	exit(0);
//	physBody->translate(btVector3(0,0,0));
//	logMsg("player position updated.");
	return true;
}

void playerState::calculatePass()	// calculates which player to pass the ball to
{
//	exit(0);
	logMsg("In calculatePass function");

	gameState *gameS = gameState::Instance();
	std::vector<teamState> teamInstance = gameS->getTeamInstance();
	int teamWithBall = gameS->getTeamWithBall();
	int playerWithBall = teamInstance[teamWithBall].getPlayerWithBall();
//	if (playerWithBall < 5)	// checks if the player belongs to the first team
//	{
		if (playerWithBall +1 < 5)	// checks if the player + 1 is still on the first team
		{
			passToPlayer = playerWithBall +1;
		}
		else
		{
			passToPlayer = 0;
		}
//	}
/*
	else if (playerWithBall > 4)	// checks if the player belongs to the second team
	{
		if (playerWithBall + 1 < 10)	// checks if the player + 1 is still on the second team
		{
			passToPlayer = playerWithBall +1;
		}
		else
		{
			passToPlayer = 5;
		}
	}
	else
	{
	}
*/

    logMsg("Pass to player is now = " +Ogre::StringConverter::toString(passToPlayer));


	passCalculated = true;
//	logMsg("Player to pass to =   " +Ogre::StringConverter::toString(passToPlayer));

//	exit(0);
}

void playerState::shotLogic(Ogre::Vector3 playerPos)
{
	/*S
    players *player = players::Instance();
//    Ogre::Vector3 playerPos;
    std::vector<basketballs> basketballInstance = getBasketballInstance();
    std::vector<playerState> pInstance = getPlayerInstance();

    // checks if a player has taken a shot
    if (getShotTaken())
    {

        basketballInstance[0].setDribbling(false);
//    		basketballInstance[0].getNode()->setParent(mSceneMgr->getRootSceneNode());
        Ogre::Vector3 pos = basketballInstance[0].getNode()->getPosition();
        basketballInstance[0].setMaxHeight(pos[1] + 10.0f);
        basketballInstance[0].setMinHeight(pos[1] - 10.0f);
        Ogre::Vector3 velocity;
        Ogre::Vector3 startCoords;
        startCoords[0] = playerPos[0] + 1.0f;
        startCoords[1] = playerPos[1] + 1.0f;
        startCoords[2] = playerPos[2] + 1.0f;
        velocity[0] = 0.90f;
        velocity[1] = 0.80f;
        velocity[2] = 0.0f;
        basketballInstance[0].setVelocity(velocity);
        basketballInstance[0].setStartCoords(startCoords);
        basketballInstance[0].getNode()->setPosition(startCoords);
        setShotTaken(false);
        setShotComplete(false);
        basketballInstance[0].setMaxHeightReached(false);
        basketballInstance[0].setMinHeightReached(false);
    //		basketballInstance[0].setPlayer(-1);
    }

    if (getShotComplete())
    {

        basketballInstance[0].setPlayer(5);
        basketballInstance[0].setDribblingStart(true);
        playerPos = pInstance[basketballInstance[0].getPlayer()].getNode()->getPosition();
        basketballInstance[0].getNode()->setPosition(playerPos[0] +2.0f, playerPos[1] + 4.0f, playerPos[2] - 1.0f);
        setShotComplete(false);
    }
*/
}
