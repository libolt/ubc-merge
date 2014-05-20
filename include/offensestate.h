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

#ifndef _OFFENSESTATE_H_
#define _OFFENSESTATE_H_

#include "OgreVector3.h"


class offenseState
{
public:

	offenseState(); // constructor

	virtual bool getExecute();	// retrieves the value of execute variable
	virtual void setExecute(bool ex);	// sets the value of the execute variable

	virtual Ogre::Vector3 *getStartPositions();	// retrieves the value of the startPositions variable
	virtual void setStartPositions(Ogre::Vector3 *positions);	// sets the value startPositions variable

	virtual Ogre::Vector3 *getExecutePositions();	// retrieves the value of the executePositions variable
	virtual void setExecutePositions(Ogre::Vector3 *positions);	// sets the value executePositions variable

	virtual bool getStartXPosSet();  // returns the value of startXPosSet
	virtual void setStartXPosSet(bool *set); // sets the value of startXPosSet

	virtual bool getStartYPosSet();  // returns the value of startYPosSet
	virtual void setStartYPosSet(bool *set); // sets the value of startYPosSet

	virtual bool getStartZPosSet();  // returns the value of startZPosSet
	virtual void setStartZPosSet(bool *set); // sets the value of startZPosSet

	virtual bool *getStartPositionSet();  // returns the value of startPositionSet
	virtual void setStartPositionSet(bool *set); // sets the value of startPositionSet

	virtual void setupState();		// sets up initial state of the object

	virtual void updateState(int teamNumber);	// updates the state of the object


private:

	bool execute;	// If set then execute the offense logic

    Ogre::Vector3 *startPositions;		// stores the positions for players get to in order to execute offense
    Ogre::Vector3 *executePositions;    // stores the positions where players move when executing offense
	bool *startXPosSet; // stores whether player is at start X position
	bool *startYPosSet; // stores whether player is at start Y position
	bool *startZPosSet; // stores whether player is at start Z position
    bool *startPositionSet; // storres whether player is at start position
};

#endif

