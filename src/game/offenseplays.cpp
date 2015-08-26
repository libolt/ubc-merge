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

#include "offenseplays.h"

std::string offensePlays::getPlayName()	// returns the value of playName;
{
	return (playName);
}
void offensePlays::setPlayName(std::string name)	// sets the value of playName
{
	playName = name;
}

int offensePlays::getVariation()	// returns the value of variation
{
	return (variation);
}
void offensePlays::setVariation(int vari)	// sets the value of variation
{
	variation = vari;
}

std::string offensePlays::getTitle()	// returns the value of title
{
	return (title);
}
void offensePlays::setTitle(std::string Title)	// sets the value of title
{
	title = Title;
}

std::vector<playerPositions> offensePlays::getPlayerPosition()	// returns the value of playerPosition
{
	return (playerPosition);
}
void offensePlays::setPlayerPosition(std::vector<playerPositions> position)	// sets the value of playerPosition
{
	playerPosition = position;
}

std::vector<Ogre::Vector3> offensePlays::getStartPositions()	// retrieves startPositions variable
{
	return (startPositions);
}

void offensePlays::setStartPositions(std::vector<Ogre::Vector3> positions)	// sets startPositions
{
	startPositions = positions;
}

std::vector< std::vector<Ogre::Vector3> > offensePlays::getExecutePositions()	// retrieves startPositions variable
{
	return (executePositions);
}

void offensePlays::setExecutePositions(std::vector< std::vector<Ogre::Vector3> > positions)	// sets startPositions
{
	executePositions = positions;
}

std::vector<bool> offensePlays::getStartPositionSet()  // returns the value of startPositionSet
{
	return (startPositionSet);
}
void offensePlays::setStartPositionSet(std::vector<bool> set) // sets the value of startPositionSet
{
	startPositionSet = set;
}

std::vector< std::vector<bool> > offensePlays::getExecutePositionReached()  // returns the value of executePositionSet
{
	return (executePositionReached);
}
void offensePlays::setExecutePositionReached(std::vector< std::vector<bool> > reached) // sets the value of executePositionSet
{
	executePositionReached = reached;
}

std::vector<offensePlays::playerDirectives> offensePlays::getPlayerDirective()  // returns the value of playerDirective
{
	return (playerDirective);
}
void offensePlays::setPlayerDirective(std::vector<offensePlays::playerDirectives> directive)  // sets the value of playerDirective
{
	playerDirective = directive;
}

playerPositions offensePlays::playerDirectives::getPlayerPosition()  // retrieves the value of playerPosition
{
	return (playerPosition);
}
void offensePlays::playerDirectives::setPlayerPosition(playerPositions position)  // sets the value of playerPosition
{
	playerPosition = position;
}

directiveTypes offensePlays::playerDirectives::getType()  // retrieves the value of type
{
	return (type);
}
void offensePlays::playerDirectives::setType(directiveTypes Type)  // sets the value of type
{
	type = Type;
}

offenseWaitFor offensePlays::playerDirectives::getWaitFor()  // retrieves the value of waitFor
{
	return (waitFor);
}
void offensePlays::playerDirectives::setWaitFor(offenseWaitFor wait)  // sets the value of waitFor
{
	waitFor = wait;
}
		
playerPositions offensePlays::playerDirectives::getPlayerSet()  // retrieves the value of playerSet
{
	return (playerSet);
}
void offensePlays::playerDirectives::setPlayerSet(playerPositions set)  // sets the value of playerSet
{
	playerSet = set;
}

positionTypes offensePlays::playerDirectives::getPositionType()  // retrieves the value of positionType
{
	return (positionType);
}
void offensePlays::playerDirectives::setPositionType(positionTypes Type)  // sets the value of positionType 
{
	positionType = Type;
}

int offensePlays::playerDirectives::getPosition()  // retrieves the value of position
{
	return (position);
}
void offensePlays::playerDirectives::setPosition(int pos)  // sets the value of position
{
	position = pos;
}
