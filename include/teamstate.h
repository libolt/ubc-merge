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

        int getTeamNumber();	// retrieves the value of the teamNumber variable
        void setTeamNumber(int number);	// sets the value of the teamNumber variable
        Ogre::String getPlayerType();	// retrieves playerType variable
        void setPlayerType(Ogre::String type);	// sets playerType variable

        int getAssists();   // retrieves assists variable
        void setAssists(int assist);    // sets assists variable

        int getBlocks();    // retrieves blocks variable
        void setBlocks(int block);  // sets blocks variable

        int getFouls(); // retrieves fouls variable
        void setFouls(int foul);    // sets fouls variable

        int getRebounds();  // retrieves rebounds variable
        void setRebounds(int rebound);  // sets rebounds variable

        int getOffensiveRebounds(); // retrieves offensiveRebounds variable
        void setOffensiveRebounds(int rebounds);    // sets offensiveRebounds variable

        int getDefensiveRebounds(); // retrieves defensiveRebounds variable
        void setDefensiveRebounds(int rebounds);    // sets defensiveRebounds variable

        int getSteals();    // retrieves steals variable
        void setSteals(int steal);  // sets steals variable

        int getTechnicals();    // retrieves technicals variable
        void setTechnicals(int technical);  // sets technicals variable

        int getTimeouts();  // retrieves timeouts variable
        void setTimeouts(int timeout);  // sets timeouts variable

        int getTurnovers(); // retrieves turnovers variable
        void setTurnovers(int turnover);    // sets turnovers variable

        int getFieldGoalsAttempted();   // retrieves fieldGoalsAttempted variable
        void setFieldGoalsAttempted(int fieldGoals);    // sets fieldGoalsAttempted variable

        int getFieldGoalsMade();    // retrieves fieldGoalsMade variable
        void setFieldGoalsMade(int fieldGoals); // sets fieldGoalsMade variable

        int getThreePointersAttempted();   // retrieves threePointersAttempted variable
        void setThreePointersAttempted(int threePointers);  // sets threePointersAttempted variable

        int getThreePointersMade();    // retrieves threePointersMade variable
        void setThreePointersMade(int threePointers);   // sets threePointersMade variable

        int getFreeThrowsAttempted();   // retrieves freeThrowsAttempted variable
        void setFreeThrowsAttempted(int freeThrows);    // sets freeThrowsAttempted variable

        int getFreeThrowsMade();    // retrieves freeThrowsMade variable
        void setFreeThrowsMade(int freeThrows); // sets freeThrowsMade variable

        std::vector<int> getPlayerID();  // retrieves playerID variable
        void setPlayerID(std::vector<int> ID);   // sets playerID variable

        std::vector<int> getActivePlayerID();  // retrieves activePlayerID variable
        void setActivePlayerID(std::vector<int> ID);   // sets activePlayerID variable

        std::vector<int> getStarterID(); // retrieves starterID variable
        void setStarterID(std::vector<int> ID);  // sets starterID variable

        bool getOffense();	// returns offense variable
        void setOffense(bool set);	// sets offense variable

        bool getDefense();	// returns defense variable
        void setDefense(bool set);	// sets defense variable

        // gets and sets playerInstance std::vector
        std::vector <playerState> getPlayerInstance();
        void setPlayerInstance(std::vector<playerState> pInstance);

        bool getPlayerInstancesCreated();	// retrieves the value of the playerInstancesCreated variable
        void setPlayerInstancesCreated(bool created);	// sets the value of the playerInstancesCreated variable

        int getPlayerWithBall();	// retrieves the value of the playerWithBall variable
        void setPlayerWithBall(int ball);	// sets the value of the playerWithBall variable
        bool getPlayerWithBallDribbling();	// retrieves the value of the playerWithBallDribbling variable
        void setPlayerWithBallDribbling(bool dribbling);	// sets the value of the playerWithBallDribbling variable

        bool getHumanControlled();		// retrieves the value of the humanControlled variable
        void setHumanControlled(bool controlled);		// sets the value of the humanControlled variable

        int getHumanPlayer();		// retrieves the value of the humanPlayer variable
        void setHumanPlayer(int player);	// sets the value of the human player variable

        offenseState *getOffenseInstance();	// retrievers the value of offenseInstance
        void setOffenseInstance(offenseState *instance);	// sets the value of offenseInstance

        defenseState *getDefenseInstance();	// retrieves the value of defenseInstance
        void setDefenseInstance(defenseState *instance);	// sets the value of defenseInstance

        bool getStateSet(); // retrieves the value of stateSet
        void setStateSet(bool set); // sets the value of stateSet
        // creates player Instances
        bool createPlayerInstances();

        void setPlayerStartPositions();	// sets the initial coordinates for the players.

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

        std::vector <playerState> playerInstance;    // creates instance of the playerState class
        std::vector <Ogre::String> playerModelsLoaded; // creates a vector of strings that holds the models which are loaded
        bool playerInstancesCreated;	// stores whether player instances have been created
        int playerWithBall;	// stores which player has control of the basketball, valid values are 0 - 4
        bool playerWithBallDribbling;	// stores whether the player with the ball is dribbling

        bool humanControlled;	// stores whether the team object is controlled by a human player;
        int humanPlayer;	// stores which player is human controlled

        offenseState *offenseInstance;
        defenseState *defenseInstance;

        
        bool stateSet; // stores whether or not the class state has been setup correctly
};

#endif // _TEAMSATE_H_
