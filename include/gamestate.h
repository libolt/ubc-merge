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

    // Import from games class
    virtual bool setupState();   // sets up the game condition
    virtual bool logic();   // carries out in game logic
    virtual void shotLogic(Ogre::Vector3 playerPos);   // carries out basketball shot logic
    virtual void processNetworkEvents();	// processes events received from network connection.
    virtual void processNetworkPlayerEvents();	// processes player evernts received from network connection
    virtual void updatePlayerDirections(Ogre::Vector3 playerPos);  // updates the direction players are facing
    virtual void updatePlayerMovements();	// updates the movement status of players
    virtual bool assignTeams(); // assigns the teams which are playing
    virtual bool assignPlayers();   // assigns the players that are playing.

    virtual bool setupEnvironment();    // sets up the 3D environment for the game

    virtual bool getTipOffComplete();	// retrieves tipOffComplete value
    virtual void setTipOffComplete(bool complete);	// sets tipOffComplete value
    virtual bool getGameStarted(void);
    virtual void setGameStarted(bool started);
    virtual bool getShotTaken(void);
    virtual void setShotTaken(bool taken);
    virtual bool getShotComplete(void);
    virtual void setShotComplete(bool complete);
    // end import


    // Tip Off execution code.  // Move to proper class
    virtual bool setupTipOff();	// sets up Tip Off conditions
    virtual bool executeTipOff();


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
        virtual bool updatePositions();

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

// Import from former games class
    int x;
    int y;
    int i;
    int j;

    bool gameStarted;   // Determines whether or not a basketball game has been started
    bool shotTaken;	// Determines whether or not a player has shot the ball
    bool shotComplete;	// Determine whether or not a player's shot is complete
    bool tipOffComplete;	// Determines whether or not game Tip Off has completed

};


#endif // _GAMESTATE_H_
