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

        virtual int getTeamNumber();	// retrieves the value of the teamNumber variable
        virtual void setTeamNumber(int number);	// sets the value of the teamNumber variable
        virtual Ogre::String getPlayerType();	// retrieves playerType variable
        virtual void setPlayerType(Ogre::String type);	// sets playerType variable

        virtual int getAssists();   // retrieves assists variable
        virtual void setAssists(int assist);    // sets assists variable

        virtual int getBlocks();    // retrieves blocks variable
        virtual void setBlocks(int block);  // sets blocks variable

        virtual int getFouls(); // retrieves fouls variable
        virtual void setFouls(int foul);    // sets fouls variable

        virtual int getRebounds();  // retrieves rebounds variable
        virtual void setRebounds(int rebound);  // sets rebounds variable

        virtual int getOffensiveRebounds(); // retrieves offensiveRebounds variable
        virtual void setOffensiveRebounds(int rebounds);    // sets offensiveRebounds variable

        virtual int getDefensiveRebounds(); // retrieves defensiveRebounds variable
        virtual void setDefensiveRebounds(int rebounds);    // sets defensiveRebounds variable

        virtual int getSteals();    // retrieves steals variable
        virtual void setSteals(int steal);  // sets steals variable

        virtual int getTechnicals();    // retrieves technicals variable
        virtual void setTechnicals(int technical);  // sets technicals variable

        virtual int getTimeouts();  // retrieves timeouts variable
        virtual void setTimeouts(int timeout);  // sets timeouts variable

        virtual int getTurnovers(); // retrieves turnovers variable
        virtual void setTurnovers(int turnover);    // sets turnovers variable

        virtual int getFieldGoalsAttempted();   // retrieves fieldGoalsAttempted variable
        virtual void setFieldGoalsAttempted(int fieldGoals);    // sets fieldGoalsAttempted variable

        virtual int getFieldGoalsMade();    // retrieves fieldGoalsMade variable
        virtual void setFieldGoalsMade(int fieldGoals); // sets fieldGoalsMade variable

        virtual int getThreePointersAttempted();   // retrieves threePointersAttempted variable
        virtual void setThreePointersAttempted(int threePointers);  // sets threePointersAttempted variable

        virtual int getThreePointersMade();    // retrieves threePointersMade variable
        virtual void setThreePointersMade(int threePointers);   // sets threePointersMade variable

        virtual int getFreeThrowsAttempted();   // retrieves freeThrowsAttempted variable
        virtual void setFreeThrowsAttempted(int freeThrows);    // sets freeThrowsAttempted variable

        virtual int getFreeThrowsMade();    // retrieves freeThrowsMade variable
        virtual void setFreeThrowsMade(int freeThrows); // sets freeThrowsMade variable

        virtual std::vector<int> getPlayerID();  // retrieves playerID variable
        virtual void setPlayerID(std::vector<int> ID);   // sets playerID variable

        virtual std::vector<int> getStarterID(); // retrieves starterID variable
        virtual void setStarterID(std::vector<int> ID);  // sets starterID variable

        virtual bool getOffense();	// returns offense variable
        virtual void setOffense(bool set);	// sets offense variable

        virtual bool getDefense();	// returns defense variable
        virtual void setDefense(bool set);	// sets defense variable

        // gets and sets playerInstance std::vector
        virtual std::vector <playerState> getPlayerInstance();
        virtual void setPlayerInstance(std::vector<playerState> pInstance);

        virtual bool getPlayerInstancesCreated();	// retrieves the value of the playerInstancesCreated variable
        virtual void setPlayerInstancesCreated(bool created);	// sets the value of the playerInstancesCreated variable

        virtual int getPlayerWithBall();	// retrieves the value of the playerWithBall variable
        virtual void setPlayerWithBall(int ball);	// sets the value of the playerWithBall variable
        virtual bool getPlayerWithBallDribbling();	// retrieves the value of the playerWithBallDribbling variable
        virtual void setPlayerWithBallDribbling(bool dribbling);	// sets the value of the playerWithBallDribbling variable

        virtual bool getHumanControlled();		// retrieves the value of the humanControlled variable
        virtual void setHumanControlled(bool controlled);		// sets the value of the humanControlled variable

        virtual int getHumanPlayer();		// retrieves the value of the humanPlayer variable
        virtual void setHumanPlayer(int player);	// sets the value of the human player variable

        // creates player Instances
        bool createPlayerInstances();

        virtual void setPlayerStartPositions();	// sets the initial coordinates for the players.

        virtual void updatePlayerDirections();  // updates the direction players are facing
        virtual void updatePlayerMovements();	// updates the movement status of players

        virtual void executePass();		// executes the pass between players

        virtual void updatePositions();	// updates the positions of game world objects

        virtual void setupState();		// sets up the state for teamState object
        virtual void updateState();	// updates the state of the teamState object
    protected:
    private:

        int teamNumber;	// stores which team number the object is
        Ogre::String playerType;	// stores the type of player in control of the team (human,network,ai) are valid values
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
//        std::vector<int> playersOnCourt; // stores which players are currently ont he court.
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

};

#endif // _TEAMSATE_H_
