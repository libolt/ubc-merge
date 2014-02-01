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


    virtual bool setupState();   // sets up the game condition
    virtual bool logic();   // carries out in game logic
    virtual void shotLogic(Ogre::Vector3 playerPos);   // carries out basketball shot logic
    virtual void processNetworkEvents();	// processes events received from network connection.
    virtual void processNetworkPlayerEvents();	// processes player evernts received from network connection
    virtual void updatePlayerDirections(Ogre::Vector3 playerPos);  // updates the direction players are facing
    virtual void updatePlayerMovements();	// updates the movement status of players
    virtual void updateBasketballMovements();	// updates the movement of basketball(s)
    virtual bool assignTeams(); // assigns the teams which are playing
    virtual bool assignPlayers();   // assigns the players that are playing.
    virtual bool setupEnvironment();    // sets up the 3D environment for the game
    virtual void setPlayerStartPositions();	// sets the initial coordinates for the players.
    virtual void setBasketballStartPositions();	// sets the initial coordinates for the basketball(s).

    virtual gameTypes getGameType(); // retrieves the value of gameType
    virtual void setGameType(gameTypes type);	  // sets the value of gameType
    virtual bool getTipOffComplete();	// retrieves tipOffComplete value
    virtual void setTipOffComplete(bool complete);	// sets tipOffComplete value
    virtual bool getBallTipped();	// retrieves the value of the ballTipped variable
    virtual void setBallTipped(bool tipped);	// sets the value of the ballTipped variable
    virtual int getBallTippedToPlayer();	// retrieves the value of the ballTippedToPlayer variable
    virtual void setBallTippedToPlayer(int player);	// sets the value of the ballTippedToPlayer variable
    virtual bool getBallTipForceApplied();	// retrieves the value of ballTipForceApplied
    virtual void setBallTipForceApplied(bool tip);	// sets the value of ballTipForceApplied
    virtual bool getGameStarted(void);	// retrieves the gameStarted value
    virtual void setGameStarted(bool started);	// sets gameStarted value
    virtual bool getShotTaken(void);		// retrieves shotTaken value
    virtual void setShotTaken(bool taken);	// sets shotTaken value
    virtual bool getShotComplete(void);	// retrieves shotComplete value
    virtual void setShotComplete(bool complete);	// sets shotComplete value
    virtual int getTeamWithBall(void);		// retrieves teamWithBall value
    virtual void setTeamWithBall(int ball);	// sets teamWithBall value
    virtual int getPlayerWithBall();	// retrives the value of playerWithBall
    virtual void setPlayerWithBall(int ball);	// sets the value of playerWithBall
    virtual bool getPlayerWithBallDribbling();	// retrieves the value of playerWithBallDribbling
    virtual void setPlayerWithBallDribbling(bool dribbling);	// sets the value of playerWithBallDribbling
    virtual int getBballBounce();	// retrieves the value of bballBounce
    virtual void setBballBounce(int bounce);	// sets the value of bballBounce

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

    gameTypes gameType;	// Indicates whether a single or multi player game is being played.
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

    std::vector <Ogre::String> playerModelsLoaded; // creates a vector of strings that holds the models which are loaded
    bool basketballModelLoaded;	// stores whether basketball model has been loaded
    bool courtModelLoaded;	// stores whether court model has been loaded

    bool setupEnvironmentCompleted;	// stores whether environment has been setup
    bool teamInstancesCreated;		// stores whether team instances have been created
    bool playerInstancesCreated;	// stores whether player instances have been created
    bool sceneCreated;				// stores whether the scene has been created
    bool gameStarted;   // Determines whether or not a basketball game has been started
    bool shotTaken;	// Determines whether or not a player has shot the ball
    bool shotComplete;	// Determine whether or not a player's shot is complete

    // Tip Off variables
    bool tipOffComplete;	// Determines whether or not game Tip Off has completed
    bool ballTipped;	//	stores whether or not the ball has been tipped
    bool ballTipForceApplied;	// stores whether or not force has been applied to tipped ball
    int ballTippedToPlayer;	// stores which player the ball has been tipped to

    int teamWithBall; // stores which team has control of the basketball, valid values are 0 or 1
    int playerWithBall;	// stores which player has control of the basketball, valid values are 0 - 9
    bool playerWithBallDribbling;	// stores whether the player with the ball is dribbling

    int bballBounce;	// stores which direction the ball is bouncing;
};


#endif // _GAMESTATE_H_
