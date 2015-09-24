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

#include "conversion.h"
#include "gamestate.h"
#include "renderengine.h"
#include "comparison.h"
#include "logging.h"

#include <string>

 basketballs::basketballs()
{
//    playerControlBasketball = -1;
    maxHeight = 0;
    maxHeightReached = false;
    minHeight = 0;
    minHeightReached = false;

    direction = NODIRECT;	
    oldDirection = NODIRECT;

    rotate = 0;

    velocity[0] = 0.0f;
    velocity[1] = 0.0f;
    velocity[2] = 0.0f;

    startCoords[0] = 0.0f;
    startCoords[1] = 0.0f;
    startCoords[2] = 0.0f;

    tipOffStart = false;
    tipOff = false;

    dribblingStart = true;
    dribbling = false;

    movement = false;
    directChange = false;

    teamNumber = 0;
    player = 0;

    courtPosition = Ogre::Vector3(0,0,0);
    newCourtPosition = Ogre::Vector3(0,0,0);
    courtPositionChanged = false;

}

basketballs::~basketballs()
{
}

Ogre::Vector3 basketballs::getNodePosition()  // retrieves position of basketball node
{
	return (node->getPosition());
}

float basketballs::getMaxHeight(void)  // retrieves the value of maxHeight
{
    return(maxHeight);
}
void basketballs::setMaxHeight(float MaxHeight)  // sets the value og maxHeight
{
    maxHeight = MaxHeight;
}

bool basketballs::getMaxHeightReached(void)  // retrieves the value of maxHeightReached
{
    return(maxHeightReached);
}
void basketballs::setMaxHeightReached(bool reached)  // sets the value of maxHeightReachef
{
    maxHeightReached = reached;
}

float basketballs::getMinHeight(void)  // retrieves the value minHeight
{
    return(minHeight);
}
void basketballs::setMinHeight(float MinHeight)  // sets the value of minHeight
{
    minHeight = MinHeight;
}

bool basketballs::getMinHeightReached(void)  // retrieves the value of minHeightReached
{
    return(minHeightReached);
}
void basketballs::setMinHeightReached(bool reached)  // sets the value of minHeightReached
{
    minHeightReached = reached;
}

int basketballs::getRotate(void)  // retrieves the value of rotate
{
    return (rotate);
}
void basketballs::setRotate(int Rotate)  // sets the value of rotate
{
    rotate = Rotate;
}

int basketballs::getTeamNumber(void)  // retrieves the value of teamNumber
{
    return(teamNumber);
}
void basketballs::setTeamNumber(int set)  // sets the value of teamNumber
{
    teamNumber = set;
}

Ogre::Vector3 basketballs::getVelocity(void)  // retrieves the value of velocity
{
    return(velocity);
}
void basketballs::setVelocity(Ogre::Vector3 Velocity)  // sets the value of velocity
{
    velocity = Velocity;
}

Ogre::Vector3 basketballs::getStartCoords(void)  // retrieves the value of startCoords
{
    return(startCoords);
}
void basketballs::setStartCoords(Ogre::Vector3 start) // sets the value of startCoords
{
    startCoords = start;
}

bool basketballs::getTipOffStart()  // retroeves the value of tipOffStart
{
    return (tipOffStart);
}
void basketballs::setTipOffStart(bool start)  // sets the value of tipOffStart
{
    tipOffStart = start;
}

bool basketballs::getTipOff()  // retrieves the value of tipOff
{
    return (tipOff);
}
void basketballs::setTipOff(bool TipOff)  // sets the value of tipOff
{
    tipOff = TipOff;
}

bool basketballs::getDribblingStart(void)  // retrieves the value of dribblingStart
{
    return (dribblingStart);
}
void basketballs::setDribblingStart(bool start)  // sets the value of dribblingStart
{
    dribblingStart = start;
}

bool basketballs::getDribbling(void)  // retrieves the value of dribbling
{
    return (dribbling);
}
void basketballs::setDribbling(bool Dribbling)  // sets the value of dribbling
{
    dribbling = Dribbling;
}

bool basketballs::getMovement()  // retrieves the value of movement
{
    return (movement);
}
void basketballs::setMovement(bool set)  // sets the value of movement
{
    movement = set;
}

bool basketballs::getDirectChange() // retrieves the value of directChange
{
    return (directChange);
}
void basketballs::setDirectChange(bool set)  // sets the value of directChange
{
    directChange = set;
}
directions basketballs::getDirection()  // retrieves the value of direction
{
    return (direction);
}
void basketballs::setDirection(directions set)  // sets the value of direction 
{
    direction = set;
}

directions basketballs::getOldDirection()  // retrieves the value of oldDirection
{
    return (oldDirection);
}
void basketballs::setOldDirection(directions set)  // sets the value of oldDirection 
{
    oldDirection = set;
}

std::string basketballs::getModelName()  // retrieves the value of modelName
{
    return (modelName);
}
 void basketballs::setModelName(string name)  // sets the value of modelName
{
    modelName = name;
}

Ogre::Entity *basketballs::getModel()  // retrieves the value of model
{
    return (model);
}
 void basketballs::setModel(Ogre::Entity *Model)  // sets the value of model
{
    model = Model;
}

Ogre::SceneNode *basketballs::getNode()  // retrieves the value of node
{
    return (node);
}
void basketballs::setNode(Ogre::SceneNode *Node)  // sets the value of node
{
    node = Node;
}

btRigidBody *basketballs::getPhysBody()	 // retrieves physBody variable
{
    return (physBody);
}

void basketballs::setPhysBody(btRigidBody *body)  // sets physBody variable
{
    physBody = body;
}

basketballSteer *basketballs::getSteer()  // retrieves the value of steer
{
    return (steer);
}
void basketballs::setSteer(basketballSteer *set)  // sets the value of steer
{
    steer = set;
}

Ogre::Vector3 basketballs::getCourtPosition()  // retrieves the value of courtPosition
{
    return (courtPosition);
}
void basketballs::setCourtPosition(Ogre::Vector3 set)  // sets the value of courtPosition
{
    courtPosition = set;
}

Ogre::Vector3 basketballs::getNewCourtPosition()  // retrieves the value of newCourtPosition
{
    return (newCourtPosition);
}
void basketballs::setNewCourtPosition(Ogre::Vector3 set)  // sets the value of newCourtPosition
{
    newCourtPosition = set;
}

bool basketballs::getCourtPositionChanged()  // retrieves the value of courtPositionChanged
{
    return (courtPositionChanged);
}
void basketballs::setCourtPositionChanged(bool set)  // sets the value of courtPositionChanged
{
    courtPositionChanged = set;
}

positionChangedTypes basketballs::getCourtPositionChangedType()  // retrieves the value of courtPositionChangedType
{
    return (courtPositionChangedType);
}
void basketballs::setCourtPositionChangedType(positionChangedTypes set)  // sets the value of courtPositionChangedType
{
    courtPositionChangedType = set;
}


bool basketballs::loadModel()  // loads the 3D model
{
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();

    model = render->getMSceneMgr()->createEntity("basketball", modelName);	// loads the basketball model

    // creates and instantiates the node object
    node = render->getMSceneMgr()->getRootSceneNode()->createChildSceneNode("basketball");

    // attaches 3D model to the node
    node->attachObject(model);
    // sets the size of the bball node
    node->setScale(0.25f,0.25f,0.25f);
    node->setPosition(0.0f,0.0f,0.0f);

   return true;
}

// calculates change in position along the x,y,z axes
Ogre::Vector3 basketballs::calculatePositionChange()
{

	//   UBC *ubc = UBC::Instance();
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();

    Ogre::Vector3 changeInPosition;	// stores the calculated change in position
    Ogre::Vector3 pos = node->getPosition();	// stores the basketball nodes position

    // initializes the variable
    changeInPosition[0] = 0.0f;
    changeInPosition[1] = 0.0f;
    changeInPosition[2] = 0.0f;
    return(changeInPosition);
}

void basketballs::updateState()  // updates the state of the basketball
{
    if (directChange)
    {
        updateDirection();
        directChange = false;
    }

    if (movement)
    {
        updateMovement();
        movement = false;
    }
    updatePosition();
}

void basketballs::updatePosition() // updates the position of the basketball
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //boost::shared_ptr<physicsEngine> physEngine = physicsEngine::Instance();
    comparison compare;
    Ogre::Vector3 changePos;
    btVector3 physChange = btVector3(0,0,0);
    
    if (courtPositionChanged)
    {
        //exit(0);
        switch (courtPositionChangedType)
        {
            case STARTCHANGE:
                logMsg("Updating basketball court position based on start position");
                
                node->translate(newCourtPosition);
                physChange = BtOgre::Convert::toBullet(newCourtPosition); // converts from Ogre::Vector3 to btVector3
                physBody->translate(physChange); // moves physics body in unison with the model
                steer->setPosition(convert->toOpenSteerVec3(newCourtPosition));
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
            break;
            
            case STEERCHANGE:
                logMsg("Updating basketball court position based on steering");
                //logMsg("Team " +convert->toString(teamNumber) + " Player " +convert->toString(playerID));
                changePos = compare.OgreVector3ToOgreVector3Result(courtPosition, newCourtPosition);
                node->translate(changePos);
                physChange = BtOgre::Convert::toBullet(changePos); // converts from Ogre::Vector3 to btVector3
                physBody->translate(physChange); // moves physics body in unison with the model
               
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
            break;   

            case INPUTCHANGE:
                logMsg("Updating court position based on input");
                node->translate(newCourtPosition);
                physChange = BtOgre::Convert::toBullet(newCourtPosition); // converts from Ogre::Vector3 to btVector3
                physBody->translate(physChange); // moves physics body in unison with the model
                steer->setPosition(convert->toOpenSteerVec3(newCourtPosition));
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
                //exit(0);
            break;

            case PHYSICSCHANGE:
                logMsg("Updating basketball court position based on physics");
                //exit(0);
            break;
            case PLAYERMOVECHANGE:
                logMsg("Updating basketball court position based on player movement");
                node->translate(newCourtPosition);
                logMsg("bball newCourtPosition = " +convert->toString(newCourtPosition));
                logMsg("bball node position" +convert->toString((node->getPosition())));
                //exit(0);
                physChange = BtOgre::Convert::toBullet(newCourtPosition); // converts from Ogre::Vector3 to btVector3
                physBody->translate(physChange); // moves physics body in unison with the model
                //steer->setPosition(convert->toOpenSteerVec3(newCourtPosition));
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
//                exit(0);
            break;
            case PLAYERDIRECTCHANGE:
                logMsg("Updating basketball court position based on player movement");
                node->translate(newCourtPosition);
                logMsg("bball newCourtPosition = " +convert->toString(newCourtPosition));
                logMsg("bball node position" +convert->toString((node->getPosition())));
                //exit(0);
                physChange = BtOgre::Convert::toBullet(newCourtPosition); // converts from Ogre::Vector3 to btVector3
                physBody->translate(physChange); // moves physics body in unison with the model
                //steer->setPosition(convert->toOpenSteerVec3(newCourtPosition));
                courtPositionChanged = false;
                courtPositionChangedType = NOCHANGE;
            break;
            default:
            break;
        }
        courtPosition = node->getPosition();
        
    }
    
/*    node->translate(posChange);
	btVector3 change; // = btVector3(0,0,0);
	change = BtOgre::Convert::toBullet(posChange); // converts from Ogre::Vector3 to btVector3
	physBody->translate(change); // moves physics body in unison with the model
*/
}

void basketballs::updateMovement()  // updates the basketball(s) movements
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    std::vector<teamState> teamInstance = gameS->getTeamInstance();
    size_t teamWithBall = gameS->getTeamWithBall();
    std::vector<playerState> activePlayerInstance = teamInstance[teamWithBall].getActivePlayerInstance();
    size_t playerWithBall = -1;
    size_t playerWithBallID = teamInstance[teamWithBall].getPlayerWithBall();
    size_t x = 0;
    
    bool shotTaken = activePlayerInstance[playerWithBall].getShotTaken();
    Ogre::Vector3 bballPos;
    Ogre::Vector3 bballCurrentPos;  // stores the current position of the basketball(s)
    Ogre::Vector3 playerPos;

    logMsg("playerWithBallID == " +convert->toString(playerWithBallID));
    while (x < activePlayerInstance.size())
    {
        if (activePlayerInstance[x].getPlayerID() == playerWithBallID)
        {
            playerWithBall = x;
            break;
        }
        ++x;
    }

    if (courtPosition.x == 0 && courtPosition.y == 0 && courtPosition.z == 0)
    {
        bballCurrentPos = node->getPosition();
    }
    else
    {
        bballCurrentPos = courtPosition;
    }
    playerPos = activePlayerInstance[playerWithBall].getCourtPosition();    // stores the current position of player with ball
    //bballPos = bballCurrentPos;
    bballPos = Ogre::Vector3(0,0,0);
    logMsg("bballHere???");
    switch (direction)
    {
        case UP:
            bballPos.x += 0;
            bballPos.y += 0; // maintains the current height of the basketball on the court as the player and ball moves
            bballPos.z -= 0.400;
        break;
        case DOWN:
            bballPos.x += 0;
            bballPos.y += 0; // maintains the current height of the basketball on the court as the player and ball moves
            bballPos.z += 0.400;
        break;
        case LEFT:
            bballPos.x -= 0.400;
            bballPos.y = 0;
            bballPos.z = 0;
        break;
        case RIGHT:
            bballPos.x += 0.400;
            bballPos.y += 0; // maintains the current height of the basketball on the court as the player and ball moves
            bballPos.z += 0;
        break;
        default:
        break;
    }

        logMsg("bballPos == " +convert->toString(bballPos));
        logMsg("cbballPos == " +convert->toString(bballCurrentPos));
        logMsg("pbballPos == " +convert->toString(activePlayerInstance[x].getCourtPosition()));
        logMsg("new bball court Position == " +convert->toString(bballPos));
        newCourtPosition = bballPos;
        courtPositionChanged = true;
        courtPositionChangedType = PLAYERMOVECHANGE;
        //basketballInstance[activeBBallInstance].setMovement(false);
        //basketballInstance[activeBBallInstance] = bballInstance;

}

void basketballs::updateDirection()  // updates basketball direction(s)
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    std::vector<teamState> teamInstance = gameS->getTeamInstance();
    size_t teamWithBall = gameS->getTeamWithBall();
    std::vector<playerState> activePlayerInstance = teamInstance[teamWithBall].getActivePlayerInstance();
    std::vector<int> activePlayerID = teamInstance[teamWithBall].getActivePlayerID();
    
    size_t playerWithBallID = teamInstance[teamWithBall].getPlayerWithBall();
    size_t playerWithBall = -1;
    logMsg("directplayerwithballID == " +convert->toString(playerWithBallID));
    bool tipOffComplete = gameS->getTipOffComplete();
    size_t x = 0;

    bool shotTaken = activePlayerInstance[playerWithBall].getShotTaken();

    if (!shotTaken)
    {
        
        Ogre::Vector3 posChange;
        while (x < activePlayerInstance.size())
        {
            if (activePlayerInstance[x].getPlayerID() == playerWithBallID)
            {
                playerWithBall = x;
                break;
            }
            ++x;
        }
        
        if (playerWithBall >= 0 && tipOffComplete == true)  // verifies that the playerWithBall variable is set to a valid number
        {
            Ogre::Vector3 playerPos= activePlayerInstance[playerWithBall].getNode()->getPosition();
            Ogre::Vector3 bballCurrentPos;

            Ogre::Vector3 bballPos = playerPos;
            Ogre::Vector3 bballPosChange = Ogre::Vector3(0.0f,0.0f,0.0f);
            btVector3 change; // = btVector3(0,0,0);
            btTransform transform;
    //      basketballInstance[activeBBallInstance].getPhysBody()->forceActivationState(ISLAND_SLEEPING);
    //        logMsg("playerDirection = " + convert->toString(&playerDirection));
    //        logMsg("oldPlayerDirection = " + convert->toString(&oldPlayerDirection));

            logMsg("playerWithBall = " +convert->toString(playerWithBall));
//            exit(0);

            if (courtPosition.x == 0 && courtPosition.y == 0 && courtPosition.z == 0)
            {
                bballCurrentPos = node->getPosition();
            }
            else
            {
                bballCurrentPos = courtPosition;
            }

            if (direction != oldDirection)
            {
                //exit(0);
                bballPos = Ogre::Vector3(0,0,0);
                switch (direction)
                {
                    case UP:
                        bballPos[0] += 0.400;
                        //bballPos[1] = bballCurrentPos[1]; // maintains the current height of the basketball on the court as the player and ball moves
                        bballPos[2] -= 0.400;
        //              basketballInstance[activeBBallInstance].setPosChange(bballPosChange);   // sets the posChange for current basketballInstance                        
                    case DOWN:
                        bballPos[0] -= 0.400;
                        //bballPos[1] = bballCurrentPos[1]; // maintains the current height of the basketball on the court as the player and ball moves
                        bballPos[2] += 0.400;
        //              basketballInstance[activeBBallInstance].setPosChange(bballPosChange);   // sets the posChange for current basketballInstance
                        break;
                    case LEFT:
                        bballPos[0] -= 0.400;
                        //bballPos[1] = bballCurrentPos[1]; // maintains the current height of the basketball on the court as the player and ball moves
//                      exit(0);
        //              basketballInstance[activeBBallInstance].setPosChange(bballPosChange);   // sets the posChange for current basketballInstance
                        break;
                    case RIGHT:
                        bballPos[0] += 0.400;
                        //bballPos[1] = bballCurrentPos[1]; // maintains the current height of the basketball on the court as the player and ball moves
        //              basketballInstance[activeBBallInstance].setPosChange(bballPosChange);   // sets the posChange for current basketballInstance
                        break;
                    default:
                        break;
                }
                
                newCourtPosition = bballPos;
                courtPositionChanged = true;
                courtPositionChangedType = PLAYERDIRECTCHANGE;
//                exit(0);

    //      basketballInstance[activeBBallInstance].getPhysBody()->forceActivationState(ACTIVE_TAG);
            }
            else
            {
            }
        }
        oldDirection = direction;
    }
    else
    {

    }
}

int basketballs::getPlayer()
{
    return (player);
}

void basketballs::setPlayer(int Player)
{
    player = Player;
}

// calculates the trajectory the basketball travels when shot
bool basketballs::calculateShot()
{
    return true;
}

// handles the shot logic as the ball travels towards the hoop
bool basketballs::shotLogic()
{
    return true;
}
