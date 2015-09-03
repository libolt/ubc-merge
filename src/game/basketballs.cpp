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
#include <string>
/*
basketballs* basketballs::pInstance = 0;
basketballs* basketballs::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new basketballs; // create sole instance
    }
    return pInstance; // address of sole instance
}
*/

 basketballs::basketballs()
{
//    playerControlBasketball = -1;
     maxHeight = 0;
    maxHeightReached = false;
    minHeight = 0;
    minHeightReached = false;

    direction = 0;	// 0 = stopped 1 = up 2 = down 3 = left 4 = right


    xCoord = 0;
    yCoord = 0;
    zCoord = 0;
    rotate = 0;

    velocity[0] = 0.0f;
    velocity[1] = 0.0f;
    velocity[2] = 0.0f;

    startCoords[0] = 0.0f;
    startCoords[1] = 0.0f;
    startCoords[2] = 0.0f;

    maxYReached = false;

    tipOffStart = false;
    tipOff = false;

    dribblingStart = true;
    dribbling = false;

    team = 0;
    player = 0;

    posChange = Ogre::Vector3(0,0,0);

}

basketballs::~basketballs()
{
}

Ogre::Vector3 basketballs::getNodePosition() // retrieves position of basketball node
{
	return (node->getPosition());
}
// gets and sets xCoord
float basketballs::getXCoord(void)
{
    return(xCoord);
}
void basketballs::setXCoord(float XCoord)
{
    xCoord = XCoord;
}

// gets and sets yCoord
float basketballs::getYCoord(void)
{
    return(yCoord);
}
void basketballs::setYCoord(float YCoord)
{
    yCoord = YCoord;
}

// gets and sets zCoord
float basketballs::getZCoord(void)
{
    return(zCoord);
}
void basketballs::setZCoord(float ZCoord)
{
    zCoord = ZCoord;
}

// gets and sets maxHeight
float basketballs::getMaxHeight(void)
{
    return(maxHeight);
}
void basketballs::setMaxHeight(float MaxHeight)
{
    maxHeight = MaxHeight;
}

// gets and sets MaxHeightReached
bool basketballs::getMaxHeightReached(void)
{
    return(maxHeightReached);
}
void basketballs::setMaxHeightReached(bool reached)
{
    maxHeightReached = reached;
}

// gets and sets minHeight
float basketballs::getMinHeight(void)
{
    return(minHeight);
}
void basketballs::setMinHeight(float MinHeight)
{
    minHeight = MinHeight;
}

// gets and sets maxHeightReached
bool basketballs::getMinHeightReached(void)
{
    return(minHeightReached);
}
void basketballs::setMinHeightReached(bool reached)
{
    minHeightReached = reached;
}

// gets and sets direction
int basketballs::getDirection(void)
{
    return(direction);
}
void basketballs::setDirection(int Direction)
{
    direction = Direction;
}

// gets and sets rotate
int basketballs::getRotate(void)
{
    return (rotate);
}
void basketballs::setRotate(int Rotate)
{
    rotate = Rotate;
}

// gets and sets team
int basketballs::getTeam(void)
{
    return(team);
}
void basketballs::setTeam(int Team)
{
    team = Team;
}

// gets and sets velocity
Ogre::Vector3 basketballs::getVelocity(void)
{
    return(velocity);
}
void basketballs::setVelocity(Ogre::Vector3 Velocity)
{
    velocity = Velocity;
}


// gets and sets startCoords
Ogre::Vector3 basketballs::getStartCoords(void)
{
    return(startCoords);
}

void basketballs::setStartCoords(Ogre::Vector3 start)
{
    startCoords = start;
}

// gets and sets maxYReached
bool basketballs::getMaxYReached(void)
{
    return(maxYReached);
}
void basketballs::setMaxYReached(bool maxY)
{
    maxYReached = maxY;
}

// gets and sets tipOffStart

bool basketballs::getTipOffStart()
{
    return (tipOffStart);
}
void basketballs::setTipOffStart(bool start)
{
    tipOffStart = start;
}

// gets and sets tipOff
bool basketballs::getTipOff()
{
    return (tipOff);
}
void basketballs::setTipOff(bool TipOff)
{
    tipOff = TipOff;
}

// gets and sets dribblingStart
bool basketballs::getDribblingStart(void)
{
    return (dribblingStart);
}
void basketballs::setDribblingStart(bool start)
{
    dribblingStart = start;
}

// gets and sets dribbling
bool basketballs::getDribbling(void)
{
    return (dribbling);
}
void basketballs::setDribbling(bool Dribbling)
{
    dribbling = Dribbling;
}

// gets and sets modelName string
std::string basketballs::getModelName()
{
    return (modelName);
}
 void basketballs::setModelName(string name)
{
    modelName = name;
}

// gets and sets model entity
Ogre::Entity *basketballs::getModel()
{
    return (model);
}
 void basketballs::setModel(Ogre::Entity *Model)
{
    model = Model;
}

// gets and sets node
Ogre::SceneNode *basketballs::getNode()
{
    return (node);
}

void basketballs::setNode(Ogre::SceneNode *Node)
{
    node = Node;
}

btRigidBody *basketballs::getPhysBody()	// retrieves physBody variable
{
	return (physBody);
}

void basketballs::setPhysBody(btRigidBody *body)	// sets physBody variable
{
	physBody = body;
}

Ogre::Vector3 basketballs::getPosChange()	// retrieves the value of posChange
{
	return (posChange);
}
void basketballs::setPosChange(Ogre::Vector3 change)	// sets the value of posChange
{
	posChange = change;
}

// loads the 3D model
bool basketballs::loadModel()
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

void basketballs::updatePosition() // updates the position of the basketball
{
    node->translate(posChange);
	btVector3 change; // = btVector3(0,0,0);
	change = BtOgre::Convert::toBullet(posChange); // converts from Ogre::Vector3 to btVector3
	physBody->translate(change); // moves physics body in unison with the model

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
