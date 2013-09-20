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

#ifndef _TEAMS_H_
#define _TEAMS_H_

#include <string>
//#include "boost/shared_array.hpp"
#include "teamdata.h"

// class representing team data
class teams
{
public:

//	team teamers[2];
    std::vector<teamData> team;

//	teams();
    ~teams();

    int getTeamOne(void);
    void setTeamOne(int team);

    int getTeamTwo(void);
    void setTeamTwo(int team);

    // assigns players to teams based on teamInits
    void assignPlayers(void);

    // assigns which players start the game
    void assignStarters(void);

    // gets and sets total number of teams
    int getTotalTeams(void);
    void setTotalTeams(int teams);

    static teams *Instance();

    // returns array of player
    std::vector<teamData> getTeamArray();
//    boost::shared_array<teamData> getTeamArray();
    // adds to array of player;
    virtual void setTeamArray(teamData data);

protected:
    teams();
    teams(const teams&);
    teams& operator= (const teams&);
private:
    static teams *pInstance;

//    boost::shared_ptr<teamData> teamData_managed;
//    std::vector<boost::shared_ptr<teamData>> teamArray;
//    boost::shared_array<teamData> teamArray;
//    typedef boost::shared_ptr<teamData> teamDataPtr;
    std::vector<teamData> teamArray;
    int teamOne;
    int teamTwo;
    int totalTeams;	// stores the total number of teams

};


#endif

