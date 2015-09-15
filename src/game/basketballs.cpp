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

#include "gamestate.h"
#include "renderengine.h"
#include "conversion.h"
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

    direction = 0;	// 0 = stopped 1 = up 2 = down 3 = left 4 = right

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


int basketballs::getDirection(void)  // retrieves the value of direction
{
    return(direction);
}
void basketballs::setDirection(int Direction)  // sets the value of direction
{
    direction = Direction;
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
    courtPosition = set;
}

positionChangedTypes basketballs::getCourtPositionChangedType()  // retrieves the value of courtPositionChangedType
{
    return (courtPositionChangedType);
}
void basketballs::setPositionChangedType(positionChangedTypes set)  // sets the value of courtPositionChangedType
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
                exit(0);
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
