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

	virtual Ogre::Vector3 *getStartPositions();	// retrieves the value of the startPositions variable
	virtual void setStartPositions(Ogre::Vector3 *positions);	// sets the value startPositions variable

	virtual std::vector <std::vector<Ogre::Vector3> > getExecutePositions();	// retrieves the value of the executePositions variable
	virtual void setExecutePositions(std::vector< std::vector<Ogre::Vector3> > positions);	// sets the value executePositions variable

	virtual bool *getStartPositionSet();  // returns the value of startPositionSet
	virtual void setStartPositionSet(bool *set); // sets the value of startPositionSet

	virtual std::vector< std::vector<bool> > getExecutePositionReached();  // returns the value of executePositionSet
	virtual void setExecutePositionReached(std::vector< std::vector<bool> > reached); // sets the value of executePositionSet

private:

    Ogre::Vector3 *startPositions;		// stores the positions for players get to in order to execute offense
    std::vector< std::vector<Ogre::Vector3> > executePositions;    // stores the positions where players move when executing offense
    bool *startPositionSet; // stores whether player is at start position

	std::vector< std::vector<bool> > executePositionReached; // stores whether player is at execute position

};
#endif
