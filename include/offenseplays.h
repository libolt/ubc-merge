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

#ifndef _OFFENSEPLAYS_H_
#define _OFFENSEPLAYS_H_

#include "Ogre.h"

#include "enums.h"l

class offensePlays	// class that contains the information to run each play
{
public:

    class playerDirectives
	{
	public:
	
	    playerDesignations getPlayerDesignation();  // retrieves the value of playerDesignation
		void setPlayerDesignation(playerDesignations designation);  // sets the value of playerDesignation
	    directiveTypes getType();  // retrieves the value of type
		void setType(directiveTypes Type);  // sets the value of type
		
		offenseWaitFor getWaitFor();  // retrieves the value of waitFor
		void setWaitFor(offenseWaitFor wait);  // sets the value of waitFor
		
		playerDesignations getPlayerSet();  // retrieves the value of playerSet
		void setPlayerSet(playerDesignations set);  // sets the value of playerSet
		
		positionTypes getPositionType();  // retrieves the value of positionType
		void setPositionType(positionTypes Type);  // sets the value of positionType 
		
		int getPosition();  // retrieves the value of position
		void setPosition(int pos);  // sets the value of position
		
	private:
	    playerDesignations playerDesignation;
		directiveTypes type;
        offenseWaitFor waitFor;
		playerDesignations playerSet;
		positionTypes positionType;
		int position;
	};
	
	std::string getPlayName();	// returns the value of playName;
	void setPlayName(std::string name);	// sets the value of playName

	int getVariation();	// returns the value of variation
	void setVariation(int vari);	// sets the value of variation

	std::string getTitle();	// returns the value of title
	void setTitle(std::string Title);	// sets the value of title

	std::vector<playerDesignations> getPlayerDesignation();	// returns the value of playerName
	void setPlayerDesignation(std::vector<playerDesignations> designation);	// sets the value of playerName

	virtual std::vector<Ogre::Vector3> getStartPositions();	// retrieves the value of the startPositions variable
	virtual void setStartPositions(std::vector<Ogre::Vector3> positions);	// sets the value startPositions variable

	virtual std::vector <std::vector<Ogre::Vector3> > getExecutePositions();	// retrieves the value of the executePositions variable
	virtual void setExecutePositions(std::vector< std::vector<Ogre::Vector3> > positions);	// sets the value executePositions variable

	virtual std::vector<bool> getStartPositionSet();  // returns the value of startPositionSet
	virtual void setStartPositionSet(std::vector<bool> set); // sets the value of startPositionSet

	virtual std::vector< std::vector<bool> > getExecutePositionReached();  // returns the value of executePositionSet
	virtual void setExecutePositionReached(std::vector< std::vector<bool> > reached); // sets the value of executePositionSet

	std::vector<playerDirectives> getPlayerDirective();  // returns the value of playerDirective
	void setPlayerDirective(std::vector<playerDirectives> directive);  // sets the value of playerDirective
	
private:
	std::string playName;
	int variation;
	std::string title;
	std::vector<playerDesignations> playerDesignation;
    std::vector<Ogre::Vector3> startPositions;		// stores the positions for players get to in order to execute offense
    std::vector< std::vector<Ogre::Vector3> > executePositions;    // stores the positions where players move when executing offense
	std::vector<playerDirectives> playerDirective;
    std::vector<bool> startPositionSet; // stores whether player is at start position

	std::vector< std::vector<bool> > executePositionReached; // stores whether player is at execute position

	

};
#endif
