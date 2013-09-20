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

#include "defense.h"

defenses::defenses() // constructor
{
	teamOnDefense = -1;
}

defenses::~defenses() // destructor
{

}

int defenses::getTeamOnDefense(void)			// returns teamOnDefense variable
{
	return (teamOnDefense);
}
void defenses::setTeamOnDefense(int team)	// sets teamOnDefense variable
{
	teamOnDefense = team;
}
defenseTypes defenses::getDefenseType()	// returns defenseType variable
{
	return (defenseType);
}
void defenses::setDefenseType(defenseTypes type)	// sets defenseType variable;
{
	defenseType = type;
}

bool defenses::getSetupDefense()					// returns setupDefense variable
{
	return (setupDefense);
}
void defenses::setSetupDefense(bool defense)		// sets setupDefense variable
{

}

bool defenses::getDefenseSet()					// returns defenseSet variable
{
	return (defenseSet);
}
void defenses::setDefenseSet(bool set)			// sets defenseSet variable
{
	defenseSet = set;
}

bool defenses::setupTeamDefense()				// sets up the team's defense
{
	return (true);
}

bool defenses::setupManToManDefense()			// sets up man to man defense
{
	return (true);
}

bool defenses::setupZoneDefense()				// sets up zone defense
{
	return (true);
}

bool defenses::executeDefense()					// executes defense routines
{
	return (true);
}

bool defenses::executeManToManDefense()			// executes man to man defense routines
{
	return (true);
}

bool defenses::executeZoneDefense()	// executes zone defense routines
{
	return (true);
}
