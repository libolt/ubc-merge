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

#include "playerdata.h"

using namespace std;

//playerData subclass
playerData::playerData()
{
//      totalPlayers = 0;

    firstName = '\0';
    lastName = '\0';
    age = 0;
    height = 0;
    weight = 0;
    ID = 0;
    teamID = -1;
    shooting = 0; 
    freeThrow = 0;
    layup = 0;
    dunk = 0;
    inside = 0;
    midRange = 0;
    threePoint = 0;
    ballHandling = 0;
    ballSecurity = 0;
    passing = 0;
    pickSetting = 0;
    offenseAwareness = 0;
    defenseAwareness = 0;
    offenseRebound = 0;
    defenseRebound = 0;
    blocking = 0;
    stealing = 0;
    interiorDefense = 0;
    midRangeDefense = 0;
    perimeterDefense = 0;
    hustle = 0;
    speed = 0;
    quickness = 0;
    fatigue = 0;
    durability = 0;
    demeanor = 0;
    improvability = 0;
    
    active = false;
    


}

playerData::~playerData()
{
}

string playerData::getFirstName(void)
{
    return(firstName);
}

void playerData::setFirstName(string first)
{
    firstName = first;
}

string playerData::getLastName(void)
{
    return(lastName);
}

void playerData::setLastName(string last)
{
    lastName = last;
}

int playerData::getAge(void)
{
    return(age);
}

void playerData::setAge(int playerAge)
{
    age = playerAge;
}

int playerData::getHeight(void)
{
    return(height);
}

void playerData::setHeight(int playerHeight)
{
    height = playerHeight;
}

int playerData::getWeight(void)
{
    return(weight);
}

void playerData::setWeight(int playerWeight)
{
    weight = playerWeight;
}

int playerData::getID(void)
{
    return(ID);
}

void playerData::setID(int playerID)
{
    ID = playerID;
}

int playerData::getTeamID(void)	// retrieves the value for the teamID variable
{
	return (teamID);
}
void playerData::setTeamID(int id)	// sets the value for the teamID variable
{
	teamID = id;
}
bool playerData::getActive(void)
{
    return(active);
}

void playerData::setActive(bool playerActive)
{
    active = playerActive;
}

string playerData::getModel()
{
    return (model);
}
void playerData::setModel(string Model)
{
    model = Model;
}

string playerData::getTeamInits(void)
{
    return (teamInits);
}

void playerData::setTeamInits(string inits)
{
    teamInits = inits;
}

string playerData::getPosition()   // gets the vlaue of position
{
    return (position);
}
void playerData::setPosition(string Position) // sets the value of position
{
    position = Position;
}


