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

#include "games.h"
#include "ubcapp.h"
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

//	SDL_Rect basketballCoords;

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

}

basketballs::~basketballs()
{
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

// loads the 3D model
bool basketballs::loadModel()
{
    renderSystems *render = renderSystems::Instance();

    model = render->getMSceneMgr()->createEntity("basketball", modelName);	// loads the basketball model

    // creates and instantiates the node object
    node = render->getMSceneMgr()->getRootSceneNode()->createChildSceneNode("basketball");

    // attaches 3D model to the node
    node->attachObject(model);
    // sets the size of the bball node
    node->setScale(0.25f,0.25f,0.25f);

   return true;
}

// calculates change in position along the x,y,z axes
Ogre::Vector3 basketballs::calculatePositionChange()
{

    UBC *ubc = UBC::Instance();
    games *game = games::Instance();

    Ogre::Vector3 changeInPosition;	// stores the calculated change in position
    Ogre::Vector3 pos = node->getPosition();	// stores the basketball nodes position

    // initializes the variable
    changeInPosition[0] = 0.0f;
    changeInPosition[1] = 0.0f;
    changeInPosition[2] = 0.0f;

    // sets up the Tip Off animation if true
    if (tipOffStart)
    {
        minHeight = pos[1] - 8.0f;
        minHeightReached = false;
        velocity[1] = 0.90f;	// sets the y velocity of the ball
        tipOffStart = false;	// sets tipOffStart to false since everything is setup
        tipOff = true;	// sets tipOff to true so that it will be executed
    }

    // animates the basketball for Tip OFf while true
    if (tipOff)
    {
        // executes if min height has not been reached
        if (!minHeightReached)
        {
            changeInPosition[1] -= velocity[1];	// decreases the vertical position of the ball
        }

        // checks if the ball is below the mimum height
        if (pos[1] <= minHeight && !minHeightReached)
        {
            minHeightReached = true;
            tipOff = false;
            tipOffStart = true;
            node->setPosition(1.25f,-20.0f,350.0f);
    	}

    }

    if(game->getTipOffComplete())
    {
    	tipOff = false;
    }
    // sets up the dribbling animation if true
    if (dribblingStart)
    {
//		exit(0);
        maxHeight = pos[1] - 5.0f;	// sets the maximum height the ball will travel
        minHeight = pos[1] - 8.0f;	// sets the minimum height the ball will travel
        maxHeightReached = false;
        minHeightReached = true;
        velocity[1] = 0.480f;	// sets the y velocity of the ball
        dribblingStart = false;
        dribbling = true;
    }



    // animates the basketball up and down if dribbling = true
    if (dribbling)
    {
        // executes if max height has not been reached
        if (!maxHeightReached)
        {
            changeInPosition[1] += velocity[1];	// increases the vertical position of the ball
        }

    	// executes if min height has not been reached
    	if (!minHeightReached)
    	{
    	    changeInPosition[1] -= velocity[1];	// decreases the vertical position of the ball
    	}

    	// checks if the ball is above the maximum height
    	if (pos[1] >= maxHeight && !maxHeightReached)
    	{
    	    maxHeightReached = true;
    	    minHeightReached = false;
    	}

    	// checks if the ball is below the mimum height
    	if (pos[1] <= minHeight && !minHeightReached)
    	{
    	    minHeightReached = true;
    	    maxHeightReached = false;
    	}
    }
    else
    {
        if (!dribbling && !tipOff)
        {
            if (!game->getShotComplete())
            {
                // checks if minHeightReached is true
                if (!minHeightReached)
                {
                    changeInPosition[1] = velocity[1];	// increases the Y coordinate by .20
                    velocity[1] -= 0.016f;
                }

                // checks if Y coordinate is less than minHeight
                if (pos[1] <= minHeight)
                {
                    minHeightReached = true;	// sets minHeightReached to true
                }

                // checks if maximum distance on the shot is reached
                if (pos[0] >= startCoords[0] - 50)
                {
                    changeInPosition[0] -= velocity[0];	// substracts the X velocity from the X Coordinate
                }

                if (minHeightReached && pos[0] <= startCoords[0] - 50)
                {
                    game->setShotComplete(true);
                }
        	}
        }
    }

    return(changeInPosition);
}

void basketballs::nodeChangePosition(Ogre::Vector3 pos) // changes the position of the Node
{
    node->translate(pos);
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
