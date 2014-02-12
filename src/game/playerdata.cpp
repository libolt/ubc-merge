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

int playerData::getFieldGoalRating(void)
{
    return(fieldGoalRating);
}
void playerData::setFieldGoalRating(int rating)
{
    fieldGoalRating = rating;
}

int playerData::getThreePointRating(void)
{
    return(threePointRating);
}

void playerData::setThreePointRating(int rating)
{
    threePointRating = rating;
}

int playerData::getDunkRating(void)
{
    return(dunkRating);
}

void playerData::setDunkGoalRating(int rating)
{
    dunkRating = rating;
}

int playerData::getFreeThrowRating(void)
{
    return(freeThrowRating);
}

void playerData::setFreeThrowRating(int rating)
{
    freeThrowRating = rating;
}

int playerData::getPassRating(void)
{
    return(passRating);
}

void playerData::setPassRating(int rating)
{
    passRating = rating;
}

int playerData::getStealRating(void)
{
    return(stealRating);
}

void playerData::setStealRating(int rating)
{
    stealRating = rating;
}

int playerData::getOffensiveReboundRating(void)
{
    return(offensiveReboundRating);
}

void playerData::setOffensiveReboundRating(int rating)
{
    offensiveReboundRating = rating;
}

int playerData::getDefensiveReboundRating(void)
{
    return(defensiveReboundRating);
}

void playerData::setDefensiveReboundRating(int rating)
{
    defensiveReboundRating = rating;
}

int playerData::getBlockRating(void)
{
    return(blockRating);
}

void playerData::setBlockRating(int rating)
{
    blockRating = rating;
}

int playerData::getStaminaRating(void)
{
    return(staminaRating);
}

void playerData::setStaminaRating(int rating)
{
    staminaRating = rating;
}

int playerData::getClutchRating(void)
{
    return(clutchRating);
}

void playerData::setClutchRating(int rating)
{
    clutchRating = rating;
}

int playerData::getSpeedRating(void)
{
    return(speedRating);
}

void playerData::setSpeedRating(int rating)
{
    speedRating = rating;
}

int playerData::getQuicknessRating(void)
{
    return(quicknessRating);
}

void playerData::setQuicknessRating(int rating)
{
    quicknessRating = rating;
}

int playerData::getInjuryRating(void)
{
    return(injuryRating);
}

void playerData::setInjuryRating(int rating)
{
    injuryRating = rating;
}

