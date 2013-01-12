#ifndef _TEAMSATE_H_
#define _TEAMSATE_H_

#include <vector>

using namespace std;

class teamState
{
    public:

        teamState();
        ~teamState();

        int getAssists(void);   // retrieves assists
        void setAssists(int assist);    // sets assists

        int getBlocks(void);    // retrieves blocks
        void setBlocks(int block);  // sets blocks

        int getFouls(void); // retrieves fouls
        void setFouls(int foul);    // sets fouls

        int getRebounds(void);  // retrieves rebounds
        void setRebounds(int rebound);  // sets rebounds

        int getOffensiveRebounds(void); // retrieves offensiveRebounds
        void setOffensiveRebounds(int rebounds);    // sets offensiveRebounds

        int getDefensiveRebounds(void); // retrieves defensiveRebounds
        void setDefensiveRebounds(int rebounds);    // sets defensiveRebounds

        int getSteals(void);    // retrieves steals
        void setSteals(int steal);  // sets steals

        int getTechnicals(void);    // retrieves technicals
        void setTechnicals(int technical);  // sets technicals

        int getTimeouts(void);  // retrieves timeouts
        void setTimeouts(int timeout);  // sets timeouts

        int getTurnovers(void); // retrieves turnovers
        void setTurnovers(int turnover);    // sets turnovers

        int getFieldGoalsAttempted(void);   // retrieves fieldGoalsAttempted
        void setFieldGoalsAttempted(int fieldGoals);    // sets fieldGoalsAttempted

        int getFieldGoalsMade(void);    // retrieves fieldGoalsMade
        void setFieldGoalsMade(int fieldGoals); // sets fieldGoalsMade

        int getThreePointersAttempted(void);   // retrieves threePointersAttempted
        void setThreePointersAttempted(int threePointers);  // sets threePointersAttempted

        int getThreePointersMade(void);    // retrieves threePointersMade
        void setThreePointersMade(int threePointers);   // sets threePointersMade

        int getFreeThrowsAttempted();   // retrieves freeThrowsAttempted
        void setFreeThrowsAttempted(int freeThrows);    // sets freeThrowsAttempted

        int getFreeThrowsMade();    // retrieves freeThrowsMade
        void setFreeThrowsMade(int freeThrows); // sets freeThrowsMade

        std::vector<int> getPlayerID();  // retrieves playerID
        void setPlayerID(std::vector<int> ID);   // sets playerID

        std::vector<int> getStarterID(); // retrieves starterID
        void setStarterID(std::vector<int> ID);  // sets starterID

    protected:
    private:

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

};

#endif // _TEAMSATE_H_
