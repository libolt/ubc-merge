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

#ifndef _COURTDATA_H_
#define _COURTDATA_H_

#include <string>
#include "OgreVector2.h"

class courtData
{
public:

    courtData();    // constructor
    ~courtData();   // destructor

    std::string getName();  // retrieves the value of name
    void setName(std::string set);  // sets the value of name
    
    std::string getModelName();  // retrieves the value of modelName
    void setModelName(std::string name); // sets the value of modelName

    Ogre::Vector2 getDimensions();  // retrieves the value of dimensions
    void setDimensions(Ogre::Vector2 set);  // sets the value of dimensions
    
    Ogre::Vector2 getBoundary();  // retrieves the value of boundary
    void setBoundary(Ogre::Vector2 set);  // sets the value of boundary
    
    Ogre::Vector2 getBoundaryPos();  // retrieves the value of boundaryPos
    void setBoundaryPos(Ogre::Vector2 set);  // sets the value of boundaryPos

    float getCenterCourt();  // retrieves the value of centerCourt
    void setCenterCourt(float set);  // sets the value of centerCourt
    
    float getCenterJumpRadius();  // retrieves the value of centerJumpRadius
    void setCenterJumpRadius(float set);  // sets the value of centerJumpRadius
    
    Ogre::Vector2 getKeyDimensions();  // retrieves the value of keyDimensions
    void setKeyDimensions(Ogre::Vector2 set);  // sets the value of keyDimensions
    
    float getKeyJumpRadius();  // retrieves the value of keyJumpRadius
    void setKeyJumpRadius(float set);  // sets the value of keyJumpRadius

    float getThreePointSideLength();  // retrieves the value of threePointSideLength
    void setThreePointSideLength(float set);  // sets the value of threePointSideLength
    
    float getThreePointZPos();  // retrieves the value of threePointZPos
    void setThreePointZPos(float set);  // sets the value of threePointZPos
    
    float getThreePointArcRadius();  // retrieves the value of threePointArcRadius
    void setThreePointArcRadius(float set);  // sets the value of threePointArcRadius
    
    Ogre::Vector2 getBaselineInboundPos();  // retrieves the value of baselineInputPos
    void setBaselineInboundPos(Ogre::Vector2 set);  // sets the value of baselineInputPos
    
    Ogre::Vector2 getSidelineInboundPos();  // retrieves the value of sidelineInputPos
    void setSidelineInboundPos(Ogre::Vector2 set);  // sets the value of sidelineInputPos
    
protected:
private:

    std::string name;  // stores the name of the court
    std::string modelName;   // stores the file name of the court 3D model
    Ogre::Vector2 dimensions;  // stores the length and width of the court
    Ogre::Vector2 boundary;  // stores the playable length and width of the court
    Ogre::Vector2 boundaryPos;  // stores the offset of the boundary from the x and y coords of the court
    float centerCourt;  // stores the center court pisition within the boundary
    float centerJumpRadius;  // stores the radius of the center jump ball circle
    Ogre::Vector2 keyDimensions;  // stores the length and width of the key
    float keyJumpRadius;  // stores the radius of key jump ball circle
    float threePointSideLength; // stores length of the straight portion of each side of the 3 pofloat line
    float threePointZPos;  // stores the offset of the sides of the 3 pofloat line from the boundary
    float threePointArcRadius;  // stores the radius of the three pofloat arc
    Ogre::Vector2 baselineInboundPos;  // stores the position a player inbounds the ball from on the baseline
    Ogre::Vector2 sidelineInboundPos;  // stores the position a player inbounds the ball from on the sideline
  
};

#endif

