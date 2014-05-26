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
std::vector<int> offensePlays::getVariation()	// returns the value of variation
{
	return (variation);
}
void offensePlays::setVariation(std::vector<int> vari)	// sets the value of variation
{
	variation = vari;
}
std::vector<std::string> offensePlays::getTitle()	// returns the value of title
{
	return (title);
}
void offensePlays::setTitle(std::vector<std::string> Title)	// sets the value of title
{
	title = Title;
}
std::vector<std::string> offensePlays::getPlayerName()	// returns the value of playerName
{
	return (playerName);
}
void offensePlays::setPlayerName(std::vector<std::string> name)	// sets the value of playerName
{
	playerName = name;
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

