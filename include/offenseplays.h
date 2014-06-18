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

#ifndef _OFFENSEPLAYS_H_
#define _OFFENSEPLAYS_H_

#include "Ogre.h"

class offensePlays	// class that contains the information to run each play
{
public:

	std::string getPlayName();	// returns the value of playName;
	void setPlayName(std::string name);	// sets the value of playName

	std::vector<int> getVariation();	// returns the value of variation
	void setVariation(std::vector<int> vari);	// sets the value of variation

	std::vector<std::string> getTitle();	// returns the value of title
	void setTitle(std::vector<std::string> Title);	// sets the value of title

	std::vector<std::string> getPlayerName();	// returns the value of playerName
	void setPlayerName(std::vector<std::string> name);	// sets the value of playerName

	virtual std::vector<Ogre::Vector3> getStartPositions();	// retrieves the value of the startPositions variable
	virtual void setStartPositions(std::vector<Ogre::Vector3> positions);	// sets the value startPositions variable

	virtual std::vector <std::vector<Ogre::Vector3> > getExecutePositions();	// retrieves the value of the executePositions variable
	virtual void setExecutePositions(std::vector< std::vector<Ogre::Vector3> > positions);	// sets the value executePositions variable

	virtual std::vector<bool> getStartPositionSet();  // returns the value of startPositionSet
	virtual void setStartPositionSet(std::vector<bool> set); // sets the value of startPositionSet

	virtual std::vector< std::vector<bool> > getExecutePositionReached();  // returns the value of executePositionSet
	virtual void setExecutePositionReached(std::vector< std::vector<bool> > reached); // sets the value of executePositionSet

private:
	std::string playName;
	std::vector<int> variation;
	std::vector<std::string> title;
	std::vector<std::string> playerName;
    std::vector<Ogre::Vector3> startPositions;		// stores the positions for players get to in order to execute offense
    std::vector< std::vector<Ogre::Vector3> > executePositions;    // stores the positions where players move when executing offense
    std::vector<bool> startPositionSet; // stores whether player is at start position

	std::vector< std::vector<bool> > executePositionReached; // stores whether player is at execute position

	class playerDirectives
	{
	public:
	private:
		directiveTypes type;

	};

};
#endif
