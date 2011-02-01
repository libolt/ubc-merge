//
// C++ Interface: teams
//
// Description:
//
//
// Author: Mike McLean <libolt@libolt.net>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _TEAMS_H_
#define _TEAMS_H_

#include <string>

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
    // adds to array of player;
    virtual void setTeamArray(teamData data);

protected:
    teams();
    teams(const teams&);
    teams& operator= (const teams&);
private:
    static teams *pInstance;

    std::vector<teamData> teamArray;
    int teamOne;
    int teamTwo;
    int totalTeams;	// stores the total number of teams

};


#endif

