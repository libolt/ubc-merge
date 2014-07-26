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

#include "networkplayerstateobject.h"

networkPlayerStateObject::networkPlayerStateObject()
{
	teamID = -1;
	playerID = -1;
	packetType = -1;
	movement = false;
	direction = -1;
	shootBlock = false;
	passSteal = false;
	XCoord = 0.0;
	YCoord = 0.0;
	ZCoord = 0.0;
}

int networkPlayerStateObject::getTeamID() // retrieves the value of teamID
{
	return (teamID);
}
void networkPlayerStateObject::setTeamID(int id) // sets the value of teamID
{
	teamID = id;
}

int networkPlayerStateObject::getPlayerID() // retrieves the value of playerID
{
	return (playerID);
}
void networkPlayerStateObject::setPlayerID(int id) // sets the value of playerID
{
	playerID = id;
}

int networkPlayerStateObject::getPacketType() // retrieves the value of packetType
{
	return (packetType);
}
void networkPlayerStateObject::setPacketType(int type) // sets the value of packetType
{
	packetType = type;
}

bool networkPlayerStateObject::getMovement() // retrieves the value of movement
{
	return (movement);
}
void networkPlayerStateObject::setMovement(bool move) // sets the value of movement
{
	movement = move;
}

int networkPlayerStateObject::getDirection() // retrieves the value of direction
{
    return (direction);
}
void networkPlayerStateObject::setDirection(int dir) // sets value of direction
{
    direction = dir;
}

bool networkPlayerStateObject::getShootBlock()  // retrieves the value of shootBlock
{
    return (shootBlock);
}
void networkPlayerStateObject::setShootBlock(bool set)   // sets the value of shootBlock
{
    shootBlock = set;
}
bool networkPlayerStateObject::getPassSteal()    // retrieves the value of passSteal
{
    return (passSteal);
}
void networkPlayerStateObject::setPassSteal(bool set)  // sets the value of passSteal
{
    passSteal = set;
}

float networkPlayerStateObject::getXCoord() // retrieves the value of XCoord
{
	return (XCoord);
}
void networkPlayerStateObject::setXCoord(float coord) // sets the value of XCoord
{
	XCoord = coord;
}

float networkPlayerStateObject::getYCoord() // retrieves the value of YCoord
{
	return (YCoord);
}
void networkPlayerStateObject::setYCoord(float coord) // sets the value of YCoord
{
	YCoord = coord;
}

float networkPlayerStateObject::getZCoord() // retrieves the value of ZCoord
{
	return (ZCoord);
}
void networkPlayerStateObject::setZCoord(float coord) // sets the value of ZCoord
{
	ZCoord = coord;
}
