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

#ifndef _BASKETBALLS_H_
#define _BASKETBALLS_H_

#ifdef __APPLE__
#include <Ogre/Ogre.h>
#include <Ogre/OgreVector3.h>
#else
#include "Ogre.h"
#include "OgreVector3.h"
#endif

#include <string>

#include "BtOgrePG.h"
#include "BtOgreGP.h"
#include "BtOgreExtras.h"


class basketballs
{
public:

    basketballs();
    virtual ~basketballs();	// destructor


// declaration of functions which access/modify private variables in the class

    Ogre::Vector3 getNodePosition(); // retrieves position of basketball node

    float getXCoord(void);		// retrieves xCoord value
    virtual void setXCoord(float XCoords);		// sets xCoord value

    float getYCoord(void);		// retrieves yCoord value
    virtual void setYCoord(float YCoords);		// sets yCoord value

    float getZCoord(void);	// retrieves zCoord value
    virtual void setZCoord(float ZCoords);	// sets zCoord value

    float getMaxHeight(void);		//	retrieves maxHeight value
    virtual void setMaxHeight(float maxHeight);	//	sets maxHeight	 value

    bool getMaxHeightReached(void);	// retrieves maxHeightReached value
    virtual void setMaxHeightReached(bool maxHeightReached);	//	sets maxHeightReached value

    float getMinHeight(void);	// retrieves minHeight value
    virtual void setMinHeight(float minHeight);	//	sets minHeight value

    bool getMinHeightReached(void);	// retrieves minHeightReached value
    virtual void setMinHeightReached(bool minHeightReached);	// sets minHeightReached value

    int getDirection(void);	// retrieves motion value
    virtual void setDirection(int motion);	// sets motion value

    int getRotate(void);	// retrieves rotate value
    virtual void setRotate(int rotate);	// sets rotate value

    int getTeam(void);	// retrieves team value
    virtual void setTeam(int team);	// sets team value

    int getPlayer(void);	// retrieves player value
    virtual void setPlayer(int player);	// sets player value

    Ogre::Vector3 getVelocity(void);	// retrieves xVelocity value
    virtual void setVelocity(Ogre::Vector3 velocity);	// sets xVelocity value

/*      float getXStartCoord(void);	// retrives xStartCoord value
    void setXStartCoord(float startX);	// sets xStartCoord value

    float getYStartCoord(void);	// retrieves yStartCoord value
    void setYStartCoord(float startY);	// sets yStartCoord value

    float getZStartCoord(void);	// retrieves zStartCoord value
    void setZStartCoord(float startZ);	// sets zStartCoord value
*/

    Ogre::Vector3 getStartCoords();	// retreives startCoords value
    virtual void setStartCoords(Ogre::Vector3 start);	// sets startCoords value

    bool getMaxYReached();
    virtual void setMaxYReached(bool maxY);

    bool getTipOffStart();	// retrieves tipOffStart value
    virtual void setTipOffStart(bool start);	// sets tipOFfStart

    bool getTipOff();	// retrieves tipOff value
    virtual void setTipOff(bool TipOff);	// sets tipOff value

    bool getDribblingStart();	// retrieves dribblingStart value
    virtual void setDribblingStart(bool start);	// sets dribblingStart value

    bool getDribbling();	// retrieves dribbling value
    virtual void setDribbling(bool Dribbling);	// sets dribbling value

    // gets and sets modelName string
    std::string getModelName();
    virtual void setModelName(std::string name);

    // gets and sets model entity
    Ogre::Entity *getModel();
    virtual void setModel(Ogre::Entity *Model);

    // gets and sets node
    Ogre::SceneNode *getNode();
    virtual void setNode(Ogre::SceneNode *node);

    virtual btRigidBody *getPhysBody();	// retrieves physBody variable
    virtual void setPhysBody(btRigidBody *body);	// sets physBody variable

    virtual Ogre::Vector3 getPosChange();	// retrieves the value of posChange
    virtual void setPosChange(Ogre::Vector3 change);	// sets the value of posChange

    bool loadModel();   // loads the 3D model from file specified in modelName

    virtual void updatePosition(); // updates the position of the basketball

    Ogre::Vector3 calculatePositionChange();	// calculates the change in position of the basketball model in x,y,z coordinates

//	int basketballXCoords;	// defines basketball's x coordinate on the screen
//	int basketballYCoords;	// defines basketball's y coordinate on the screen

    virtual bool calculateShot();   // calculates the trajectory the basketball travels when shot
    virtual bool shotLogic();   // handles the shot logic as the ball travels towards the hoop


//    static basketballs *Instance();

protected:
//    basketballs(const basketballs&);
//    basketballs& operator= (const basketballs&);
private:
//    static basketballs *pInstance;

    std::string modelName;   // stores the file name of the 3d model

    Ogre::Entity *model;    // stores 3d model

    Ogre::SceneNode *node;  // stores node 3d model is attached to

    // stores the physics object that represents the player
    btRigidBody *physBody;

    Ogre::Vector3 posChange;

    float maxHeight;
    bool maxHeightReached;

    float minHeight;
    bool minHeightReached;

    int direction;	// 0 = stopped 1 = up 2 = down 3 = left 4 = right

    int rotate;	// defines which way the basketball is rotated

    float xCoord;	// defines basketball's x coordinate on the screen
    float yCoord;	// defines basketball's y coordinate on the screen
    float zCoord;

    int team;	// defines which team has the basketball
    int player;	// defines which player has the basketball

    Ogre::Vector3 velocity;	// speed at which the ball travels on x,y,z axes
//	float xVelocity;	// speed at which the ball travels on the X axis
//	float yVelocity;	// speed at which the ball travels on the Y axis
//	float zVelocity;	// speed at which the ball travels on the Z axis;

    Ogre::Vector3 startCoords;
//	float xStartCoord;	// starting coordinate on the X axis
//	float yStartCoord;	// starting coordinate on the Y axis
//	float zStartCoord;	// starting coordinate on the z axis;

    bool maxYReached;

    bool tipOffStart;	// defines whether or not to setup ball position for tip off
    bool tipOff	;	// defines whether or not tip off is executing
    bool dribblingStart;	// defines whether or not to start the dribbling animation
    bool dribbling;	// defines whether or not the ball is being dribbled
};

#endif

