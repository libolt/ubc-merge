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

#ifndef _TEAMSATE_H_
#define _TEAMSATE_H_

#include "defensestate.h"

#include <vector>
#include "OgreString.h"

#include "offensestate.h"

#include "basketballs.h"
#include "playerstate.h"

using namespace std;

class teamState
{
public:

    teamState();
    ~teamState();

    int getTeamNumber();	// retrieves the value of teamNumber
    void setTeamNumber(int number);	// sets the value of teamNumber

    std::string getPlayerType();	// retrieves the value of playerType
    void setPlayerType(std::string type);	// sets the value of playerType

    int getAssists();   // retrieves the value of assists
    void setAssists(int assist);    // sets the value of assists

    int getBlocks();    // retrieves the value of blocks
    void setBlocks(int block);  // sets the value of blocks

    int getFouls(); // retrieves the value of fouls
    void setFouls(int foul);    // sets the value of fouls

    int getRebounds();  // retrieves the value of rebounds
    void setRebounds(int rebound);  // sets the value of rebounds

    int getOffensiveRebounds(); // retrieves the value of offensiveRebounds
    void setOffensiveRebounds(int rebounds);    // sets the value of offensiveRebounds

    int getDefensiveRebounds(); // retrieves the value of defensiveRebounds
    void setDefensiveRebounds(int rebounds);    // sets the value of defensiveRebounds

    int getSteals();    // retrieves the value of steals
    void setSteals(int steal);  // sets the value of steals

    int getTechnicals();    // retrieves the value of technicals
    void setTechnicals(int technical);  // sets the value of technicals

    int getTimeouts();  // retrieves the value of timeouts
    void setTimeouts(int timeout);  // sets the value of timeouts

    int getTurnovers(); // retrieves the value of turnovers
    void setTurnovers(int turnover);    // sets the value of turnovers

    int getFieldGoalsAttempted();   // retrieves the value of fieldGoalsAttempted
    void setFieldGoalsAttempted(int fieldGoals);    // sets the value of fieldGoalsAttempted

    int getFieldGoalsMade();    // retrieves the value of fieldGoalsMade
    void setFieldGoalsMade(int fieldGoals); // sets the value of fieldGoalsMade

    int getThreePointersAttempted();   // retrieves the value of threePointersAttempted
    void setThreePointersAttempted(int threePointers);  // sets the value of threePointersAttempted

    int getThreePointersMade();    // retrieves the value of threePointersMade
    void setThreePointersMade(int threePointers);   // sets the value of threePointersMade

    int getFreeThrowsAttempted();   // retrieves the value of freeThrowsAttempted
    void setFreeThrowsAttempted(int freeThrows);    // sets the value of freeThrowsAttempted

    int getFreeThrowsMade();    // retrieves the value of freeThrowsMade
    void setFreeThrowsMade(int freeThrows); // sets the value of freeThrowsMade

    std::vector<int> getPlayerID();  // retrieves the value of playerID
    void setPlayerID(std::vector<int> ID);   // sets the value of playerID

    std::vector<int> getActivePlayerID();  // retrieves the value of activePlayerID
    void setActivePlayerID(std::vector<int> ID);   // sets the value of activePlayerID

    std::vector<int> getStarterID(); // retrieves the value of starterID
    void setStarterID(std::vector<int> ID);  // sets the value of starterID

    bool getOffense();	// retrieves the value of offense
    void setOffense(bool set);	// sets the value of offense

    bool getDefense();	// retrieves the value of defense
    void setDefense(bool set);	// sets the value of defense

    std::vector <playerState> getPlayerInstance();  // retrieves the value of playerInstance
    void setPlayerInstance(std::vector<playerState> pInstance); // sets the value of  playerInstance

    std::vector <playerState> getActivePlayerInstance();  // retrieves the value of activePlayerInstance
    void setActivePlayerInstance(std::vector<playerState> pInstance); // sets the value of activePlayerInstance

    bool getPlayerInstancesCreated();	// retrieves the value of the playerInstancesCreated
    void setPlayerInstancesCreated(bool created);	// sets the value of the playerInstancesCreated

    int getPlayerWithBallID();    // retrieves the value of the playerWithBallID
    void setPlayerWithBallID(int ball);   // sets the value of the playerWithBallID

    int getPlayerWithBall();	// retrieves the value of the playerWithBall
    void setPlayerWithBall(int ball);	// sets the value of the playerWithBall

    bool getPlayerWithBallDribbling();	// retrieves the value of the playerWithBallDribbling
    void setPlayerWithBallDribbling(bool dribbling);	// sets the value of the playerWithBallDribbling

    bool getHumanControlled();		// retrieves the value of the humanControlled
    void setHumanControlled(bool controlled);		// sets the value of the humanControlled

    int getHumanPlayer();		// retrieves the value of the humanPlayer
    void setHumanPlayer(int player);	// sets the value of the human player

    int getHoop();  // retrieves the value of hoop
    void setHoop(int set); // sets the value of hoop

    offenseState *getOffenseInstance();	// retrievers the value of offenseInstance
    void setOffenseInstance(offenseState *instance);	// sets the value of offenseInstance

    defenseState *getDefenseInstance();	// retrieves the value of defenseInstance
    void setDefenseInstance(defenseState *instance);	// sets the value of defenseInstance

    bool getStateSet(); // retrieves the value of stateSet
    void setStateSet(bool set); // sets the value of stateSet

    // creates player Instances
    bool createPlayerInstances();

    void setPlayerStartPositions();	// sets the initial coordinates for the players.
    void setPlayerStartActivePositions(); // sets the position the players will play at the start of the game

    void updatePlayerStates();  // updates the states of active players
    void updatePlayerDirections();  // updates the direction players are facing
    void updatePlayerMovements();	// updates the movement status of players

    void executePass();		// executes the pass between players

    void updatePositions();	// updates the positions of game world objects

    void setupState();		// sets up the state for teamState object
    void updateState();	// updates the state of the teamState object
        
        
protected:
private:

    int teamNumber;	// stores which team number the object is
    std::string playerType;	// stores the type of player in control of the team (human,network,ai) are valid values
    int assists;    // stores number of assists team has.
    int blocks; // stores the total number of blocks.
    int fouls;  // stores the total number of fouls.
    int rebounds; // stores the total number of rebounds.
    int offensiveRebounds;  // stores the total number of offensive rebounds.
    int defensiveRebounds;   // stores the total number of defensive rebounds.
    int steals; // stores the total number of steals.
    int technicals; // stores the total number of technical fouls commited.
    int timeouts;   // stores the total number of timeouts available.
    int turnovers;  // stores the total number turnovers.
    int fieldGoalsAttempted; // stores the total number of field goals attempted.
    int fieldGoalsMade; // stores the total number of field goals made.
    int threePointersAttempted; // stores the total number of 3 pointers attempted.
    int threePointersMade;  // stores the total number of 3 pointers made.
    int freeThrowsAttempted;    // stores the total number of free throws attempted.
    int freeThrowsMade; // stores the total number of free throws made.

    std::vector<int> playerID;    // stores the player IDs from the teams class
    std::vector<int> activePlayerID; // stores which players are currently on the court.
//        std::vector<int> activeID;
    std::vector<int> starterID;  // stores the IDs of which players are listed as starters.

    bool offense;	// if set then the team is on offense
    bool defense;	// if set then the team is on defense

    std::vector <playerState> playerInstance;    // stores instance of the playerState class containing all team players
    std::vector <playerState> activePlayerInstance;    // stores instance of the playerState class containing the active players

    std::vector <std::string> playerModelsLoaded; // creates a vector of strings that holds the models which are loaded
    bool playerInstancesCreated;	// stores whether player instances have been created
    int playerWithBallID; // stores the ID of the player that has the ball
    int playerWithBall;	// stores which player has control of the basketball, valid values are 0 - 4
    bool playerWithBallDribbling;	// stores whether the player with the ball is dribbling

    bool humanControlled;	// stores whether the team object is controlled by a human player;
    int humanPlayer;	// stores which player is human controlled

    int hoop;  // holds which hoop the team is shooting on
    offenseState *offenseInstance;
    defenseState *defenseInstance;


    bool stateSet; // stores whether or not the class state has been setup correctly
};

#endif // _TEAMSATE_H_
