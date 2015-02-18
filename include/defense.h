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

#ifndef _DEFENSE_H_
#define _DEFENSE_H_

#include "enums.h"

class defenses
{
public:

    int getTeamOnDefense();					// returns teamOnDefense variable
    void setTeamOnDefense(int team);		// sets teamOnDefense variable

    defenseTypes getDefenseType();			// returns defenseType variable
    void setDefenseType(defenseTypes type);	// sets defenseType variable;

    bool getSetupDefense();					// returns setupDefense variable
    void setSetupDefense(bool defense);		// sets setupDefense variable

    bool getDefenseSet();					// returns defenseSet variable
    void setDefenseSet(bool set);			// sets defenseSet variable


    bool getManToManSet();
    void setManToManSet(bool set);

    bool getZoneSet();
    void setZoneSet(bool set);

    // sets up defense
    bool setupTeamDefense();				// sets up the team's defense
    bool setupManToManDefense();			// sets up man to man defense
    bool setupZoneDefense();			// sets up zone defense

    // executes defense
    bool executeDefense();	// executes defense routines
    bool executeManToManDefense();	// executes man to man defense routines
    bool executeZoneDefense();	// executes zone defense routines



    static defenses *Instance();
protected:
    defenses();
    defenses(const defenses&);
    defenses& operator= (const defenses&);
    ~defenses();
private:
    static defenses *pInstance;

    defenseTypes defenseType;	// stores type of defense being played

    int teamOnDefense;

    bool setupDefense;	// Determines whether to execute the defensive setup code
    bool defenseSet;	// Determines wether the defense has been setup

    bool manToMan;
    bool zone;

    bool manToManSet;
    bool zoneSet;

    // holds approx X Y coordinates a defender should be at
    int defenderXCoord[5];
    int defenderYCoord[5];
};

#endif

