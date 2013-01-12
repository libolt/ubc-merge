#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include <vector>

#include "basketballs.h"
#include "courtstate.h"
#include "playerstate.h"
#include "teamstate.h"

//using namespace std;
class gameState
{
    public:
        static gameState *Instance();
        ~gameState();

        // gets and sets teamID
        std::vector<int> getTeamID(void);
        void setTeamID(std::vector<int> ID);

        // gets and sets playerID
        std::vector<int> getPlayerID(void);
        void setPlayerID(std::vector<int> ID);


        // gets and sets playerInstance std::vector
        std::vector <playerState> getPlayerInstance();
        void setPlayerInstance(std::vector<playerState> pInstance);

        // creates player Instances
        bool createPlayerInstances();

        // gets and sets basketballInstance std::vector
        std::vector <basketballs> getBasketballInstance();
        void setBasketballInstance(std::vector<basketballs> bballInstance);

        // creates basketball Instances
        bool createBasketballInstances();

        // gets and sets teamInstance
        std::vector <teamState> getTeamInstance();
        void setTeamInstance(std::vector<teamState> Instance);

        // creates team Instances
        bool createTeamInstances();

        // gets and sets courtInstance std::vector
        std::vector <courtState> getCourtInstance();
        void setCourtInstance(std::vector<courtState> Instance);

        // creates court Instances
        bool createCourtInstances();

        // updates positions of gameState objects
        bool updatePositions();

    protected:
        gameState();
        gameState(const gameState&);
        gameState &operator = (const gameState&);
    private:
    static gameState *pInstance;

    enum quarters { FIRST, SECOND, THIRD, FOURTH }; // defines the quarters within the game
    quarters currentQuarter;    // defines which quarter the game is in.

    float gameTimeLeft; // Indicates the time left in the game
    float quarterTimeLeft;  // incates the time left in the current quarter

    bool finished;  // indicates whether a game is finished.

    std::vector<int> teamID;      // std::vector that stores the IDs of the 2 teams currently playing
    std::vector<int> playerID;       // std::vector that stores the IDs of the players currently being used.

    std::vector <basketballs> basketballInstance;    // creates instance of the basketballs class
    std::vector <courtState> courtInstance;  // creates instance of the courtState class
    std::vector <playerState> playerInstance;    // creates instance of the playerState class
    std::vector <teamState>  teamInstance;   // creates instance of the teamState class
};


#endif // _GAMESTATE_H_
