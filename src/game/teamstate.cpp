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

#include "teamstate.h"

teamState::teamState()
{
	playerType = ' ';
    assists = 0;
    blocks = 0;
    fouls = 0;
    rebounds = 0;
    steals = 0;
    technicals = 0;
    timeouts = 0;

    offenseInstance = new offenseState;
    defenseInstance = new defenseState;
}

teamState::~teamState()
{
}

Ogre::String teamState::getPlayerType()	// retrieves playerType variable
{
	return (playerType);
}
void teamState::setPlayerType(Ogre::String type)	// sets playerType variable
{
	playerType = type;
}
int teamState::getAssists(void)   // retrieves assists
{
    return (assists);
}
void teamState::setAssists(int assist)    // sets assists
{
    assists = assist;
}

int teamState::getBlocks(void)    // retrieves blocks
{
    return (blocks);
}
void teamState::setBlocks(int block)   // sets blocks
{
    blocks = block;
}

int teamState::getFouls(void) // retrieves fouls
{
    return (fouls);
}
void teamState::setFouls(int foul)    // sets fouls
{
    fouls = foul;
}

int teamState::getRebounds(void)  // retrieves rebounds
{
    return (rebounds);
}
void teamState::setRebounds(int rebound)  // sets rebounds
{
    rebounds = rebound;
}

int teamState::getOffensiveRebounds(void) // retrieves offensiveRebounds
{
    return (offensiveRebounds);
}
void teamState::setOffensiveRebounds(int rebounds)    // sets offensiveRebounds
{
    offensiveRebounds = rebounds;
}
int teamState::getDefensiveRebounds(void) // retrieves defensiveRebounds
{
    return (defensiveRebounds);
}
void teamState::setDefensiveRebounds(int rebounds)    // sets defensiveRebounds
{
    defensiveRebounds = rebounds;
}

int teamState::getSteals(void)    // retrieves steals
{
    return (steals);
}
void teamState::setSteals(int steal)    // sets steals
{
    steals = steal;
}

int teamState::getTechnicals(void)    // retrieves technicals
{
    return (technicals);
}
void teamState::setTechnicals(int technical)  // sets technicals
{
    technicals = technical;
}

int teamState::getTimeouts(void)  // retrieves timeouts
{
    return (timeouts);
}
void teamState::setTimeouts(int timeout)  // sets timeouts
{
    timeouts = timeout;
}

int teamState::getTurnovers() // retrieves turnovers variable
{
	return (turnovers);
}
void teamState::setTurnovers(int turnover)    // sets turnovers variable
{
	turnovers = turnover;
}

int teamState::getFieldGoalsAttempted(void)   // retrieves fieldGoalsAttempted
{
    return (fieldGoalsAttempted);
}
void teamState::setFieldGoalsAttempted(int fieldGoals)    // sets fieldGoalsAttempted
{
    fieldGoalsAttempted = fieldGoals;
}

int teamState::getFieldGoalsMade(void)   // retrieves fieldGoalsMade
{
    return (fieldGoalsMade);
}
void teamState::setFieldGoalsMade(int fieldGoals)    // sets fieldGoalsMade
{
    fieldGoalsMade = fieldGoals;
}

int teamState::getThreePointersAttempted(void)   // retrieves threePointersAttempted
{
    return (threePointersAttempted);
}
void teamState::setThreePointersAttempted(int threePointers)  // sets threePointersAttempted
{
    threePointersAttempted = threePointers;
}

int teamState::getThreePointersMade(void)   // retrieves threePointersMade
{
    return (threePointersMade);
}
void teamState::setThreePointersMade(int threePointers)  // sets threePointersMade
{
    threePointersMade = threePointers;
}

int teamState::getFreeThrowsAttempted(void)   // retrieves freeThrowsAttempted
{
    return (freeThrowsAttempted);
}
void teamState::setFreeThrowsAttempted(int freeThrows)    // sets freeThrowsAttempted
{
    freeThrowsAttempted = freeThrows;
}

int teamState::getFreeThrowsMade(void)   // retrieves freeThrowsMade
{
    return (freeThrowsMade);
}
void teamState::setFreeThrowsMade(int freeThrows)    // sets freeThrowsMade
{
    freeThrowsMade = freeThrows;
}

vector<int> teamState::getPlayerID()  // retrieves playerID
{
    return (playerID);
}
void teamState::setPlayerID(std::vector<int> ID)   // sets playerID
{
    playerID = ID;
}
vector<int> teamState::getStarterID() // retrieves starterID
{
    return (starterID);
}
void teamState::setStarterID(std::vector<int> ID)  // sets starterID
{
    starterID = ID;
}

bool teamState::getOffense()	// returns offense variable
{
	return (offense);
}
void teamState::setOffense(bool set)	// sets offense variable
{
	offense = set;
}
bool teamState::getDefense()	// returns defense variable
{
	return (defense);
}
void teamState::setDefense(bool set)	// sets defense variable
{
	defense = set;
}


void teamState::updateState()	// updates the state of the object
{
	// checks whether to execute offense or defense logic
	if (offense == true && defense == false)
	{
		offenseInstance->setExecute(true);
		defenseInstance->setExecute(false);
	}
	else if (defense == true && offense == false)
	{
		offenseInstance->setExecute(true);
		defenseInstance->setExecute(false);
	}
	else
	{

	}

//	offenseInstance->updateState();	// updates the state of the offenseInstance object
//	defenseInstance->updateState(); // updates the state of the defenseInstance object
}
