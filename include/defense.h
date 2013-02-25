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

#ifndef _DEFENSE_H_
#define _DEFENSE_H_

class defenses
{
public:

    int getTeamOnDefense(void);
    void setTeamOnDefense(int team);

    bool getManToMan(void);
    void setManToMan(bool man);

    bool getZone(void);
    void setZone(bool zone);

    bool getDefenseSet(void);
    void setDefenseSet(bool set);


    bool getManToManSet(void);
    void setManToManSet(bool set);

    bool getZoneSet(void);
    void setZoneSet(bool set);

    // sets up defense
    bool setupDefense(void);
    bool setupManToManDefense(void);
    bool setupZoneDefense(void);

    // executes defense
    int executeDefense(void);
    int executeManToManDefense(void);
    int executeZoneDefense(void);


    static defenses *Instance();
protected:
    defenses();
    defenses(const defenses&);
    defenses& operator= (const defenses&);
private:
    static defenses *pInstance;


    int teamOnDefense;

    bool manToMan;
    bool zone;

    bool defenseSet;
    bool manToManSet;
    bool zoneSet;

    // holds approx X Y coordinates a defender should be at
    int defenderXCoord[5];
    int defenderYCoord[5];
};

#endif

