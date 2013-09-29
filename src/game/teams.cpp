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

#include "teams.h"
#include "players.h"

using namespace std;

teams* teams::pInstance = 0;
teams* teams::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new teams; // create sole instance
    }
    return pInstance; // address of sole instance
}

// teams class constructor
teams::teams()
{
    teamOne = -1;
    teamTwo = -1;
    totalTeams = 0;

}

teams::~teams()
{
//    delete [] team;
//	delete [] teamGame;
}

// returns array of player
std::vector<teamData> teams::getTeamArray()
{
    return(teamArray);
}

// adds to array of player;
void teams::setTeamArray(teamData data)
{
    teamArray.push_back(data);
}


int teams::getTeamOne(void)
{
    return(teamOne);
}

void teams::setTeamOne(int team)
{
    teamOne = team;
}

int teams::getTeamTwo(void)
{
    return(teamTwo);
}

void teams::setTeamTwo(int team)
{
    teamTwo = team;
}

// gets and sets total number of teams
int teams::getTotalTeams(void)
{
    return(totalTeams);
}

void teams::setTotalTeams(int teams)
{
    totalTeams = teams;
}

void teams::assignPlayers()  // assigns players to the team based on matching Inits
{
    players *playerG = players::Instance();
    std::vector<playerData> player = playerG->getPlayer();

    int totalPlayers = playerG->getTotalPlayers();  // gets total number drop


    std::vector<teamData>::iterator teamIT;
    for (teamIT = teamArray.begin();teamIT != teamArray.end(); ++teamIT)    // iterators through the list of teams
    {
        std::vector<int> roster = teamIT->getRoster();   // retrieves the current teams roster IDs

        std::vector<playerData>::iterator playerIT;
        for (playerIT = player.begin(); playerIT < player.end(); ++playerIT)    // iterators through the list of players
        {
            if (teamIT->getInits() == playerIT->getTeamInits()) // compares team initais to those that are assigned to the player
            {
                roster.push_back(playerIT->getID());    // adds player ID to roster if initials match
            }
        }
        teamIT->setRoster(roster);  // sets the updated team roster
        teamIT->setPlayerNum(teamIT->getRoster().size());   // sets the number of players on the roster
    }

}

void teams::assignStarters(void)    // assigns teams starting players
{
    players *playerG = players::Instance();
    std::vector<playerData> player = playerG->getPlayer();

    std::vector<teamData>::iterator teamIT;
    for (teamIT = teamArray.begin();teamIT != teamArray.end(); ++teamIT)    // iterators through the list of teams
    {
        std::vector<int> roster = teamIT->getRoster();   // retrieves the current teams roster IDs
        std::vector<int> starters = teamIT->getStarters();   // retrieves the current roster starter IDs
        std::vector<int>::iterator rosterIT;

        for (rosterIT = roster.begin(); rosterIT != roster.end(); ++rosterIT)   // iterates through the roster array
        {
            if (starters[0] < 0)    // checks if starting point guard is set
            {
                if (player[*rosterIT].getPosition() == "PG")    // checks if current roster player is a point guard
                {
                    starters[0] = *rosterIT;    // sets starting point guard
                }
            }
            if (starters[1] < 0)    // checks if starting shooting guard is set
            {
                if (player[*rosterIT].getPosition() == "SG")    // checks if current roster player is a shooting guard
                {
                    starters[1] = *rosterIT;    // sets starting shooting guard
                }
            }
            if (starters[2] <0) // checks if starting small forward is set
            {
                if (player[*rosterIT].getPosition() == "SF")    // checks if current roster player is a small forward
                {
                    starters[2] = *rosterIT;    // set starting small forward
                }
            }
            if (starters[3] < 0)    // checks if power forward is set
            {
                if (player[*rosterIT].getPosition() == "PF")    // checks if current roster player is a power forward
                {
                    starters[3] = *rosterIT;    // sets starting power forwrad
                }
            }
            if (starters[4] < 0)    // checks if starting center is set
            {
                if (player[*rosterIT].getPosition() == "C") // checks if current roser player  is a center
                {
                    starters[4] = *rosterIT;    // sets starting center
                }
            }
            else
            {
            }
        }
        teamIT->setStarters(starters);  // sets team's starting players
    }

}

