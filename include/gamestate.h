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

#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include <vector>
#include <boost/shared_ptr.hpp>

#include "basketballs.h"
#include "courtdata.h"
#include "courtstate.h"
#include "hoop.h"
#include "playerstate.h"
#include "teamstate.h"
#include "teamdata.h"
#include "playerdata.h"

//using namespace std;
class gameState
{
public:

    //static gameState *Instance();
    static boost::shared_ptr<gameState> Instance();

    ~gameState();

    gameTypes getGameType(); // retrieves the value of gameType
    void setGameType(gameTypes type);	  // sets the value of gameType

    bool getGameSetupComplete();    // retrieves the value of gameSetupComplete
    void setGameSetupComplete(bool complete);   // sets the value of gameSetupComplete

    bool getTipOffComplete();	// retrieves tipOffComplete value
    void setTipOffComplete(bool complete);	// sets tipOffComplete value

    bool getBallTipped();	// retrieves the value of the ballTipped
    void setBallTipped(bool tipped);	// sets the value of the ballTipped

    int getBallTippedToTeam();	// retrieves the value of the ballTippedToTeam
    void setBallTippedToTeam(int team);	// sets the value of the ballTippedToTeam

    int getBallTippedToPlayerID();	// retrieves the value of the ballTippedToPlayerID
    void setBallTippedToPlayerID(int player);	// sets the value of the ballTippedToPlayerID

    bool getBallTipForceApplied();	// retrieves the value of ballTipForceApplied
    void setBallTipForceApplied(bool tip);	// sets the value of ballTipForceApplied

    bool getPlayerHasBasketball();  // retrieves the value of playerHasBasketball
    void setPlayerHasBasketball(bool set);  // setd the value of playerHasBasketball
    
    bool getGameStarted(void);	// retrieves the gameStarted value
    void setGameStarted(bool started);	// sets gameStarted value

    int getTeamWithBall(void);		// retrieves teamWithBall value
    void setTeamWithBall(int ball);	// sets teamWithBall value

    int getBballBounce();	// retrieves the value of bballBounce
    void setBballBounce(int bounce);	// sets the value of bballBounce

    bool getCourtDataLoaded();  // retrieves the value of courtDataLoaded
    void setCourtDataLoaded(bool loaded);  // sets the value of courtDataLoaded

    int getSelectedCourtDataInstance();  // retrieves the value of selectedCourtDataInstance
    void setSelectedCourtDataInstance(int selected);  // sets the value of selectedCourtDataInstance

    bool getCourtInstanceCreated(); // retrieves the value of courtInstanceCreated
    void setCourtInstanceCreated(bool created); // sets the value of courtInstanceCreated

    bool getCourtModelLoaded();  // retrieves the value of courtModelLoaded
    void setCourdModelLoaded(bool set);  // sets the value of courtModelLoaded

    bool getTeamInstancesCreated();	// retrieves the value of teamInstancesCreated
    void setTeamInstancesCreated(bool created);	// sets the value of teamInstancesCreated

    bool getBasketballModelLoaded();	// retrieves the value of basketballModelLoaded
    void setBasketballModelLoaded(bool loaded);	// sets the value of basketballModelLoaded

    std::vector<teamData> getTeamDataInstance();	// retrieves the value of teamDataInstance
    void setTeamDataInstance(std::vector<teamData> instance);	// sets the value of teamDataInstance;

    std::vector<playerData> getPlayerDataInstance();	// retrieves the value of playerDataInstance
    void setPlayerDataInstances(std::vector<playerData> instance);	// sets the value of playerDataInstance;

    std::vector<courtData>	getCourtDataInstance();	// retrieves the value of courtDataInstance
    void setCourtDataInstance(std::vector<courtData> instance);	// sets the value of courtDataInstance

    std::vector<int> getTeamID(void);  // retrieves the value of teamID
    void setTeamID(std::vector<int> ID);  // sets the value of teamID

    std::vector<int> getPlayerID(void);  // retrieves the value of playerID
    void setPlayerID(std::vector<int> ID);  // sets the value of playerID

    std::vector< std::vector<int> > getTeamStarterID(); // retrieves value of teamStarterID
    void setTeamStarterID(std::vector< std::vector<int> > ID); // sets the value of teamStarterID

    std::vector <basketballs> getBasketballInstance();  // retrieves the value of basketballInstance
    void setBasketballInstance(std::vector<basketballs> bballInstance);  // sets the value of basketballInstance

    std::vector <teamState> getTeamInstance();  // retireves the value of teamInstance
    void setTeamInstance(std::vector<teamState> Instance);  // sets the value of teamInstance

    std::vector <courtState> getCourtInstance();  // retrieves the value of courtInstance
    void setCourtInstance(std::vector<courtState> Instance);  // sets the value of courtInstance

    std::vector <hoopState> getHoopInstance();  // retrieves the value of hoopInstance
    void setHoopInstance(std::vector<hoopState> Instance);  // sets the value of hoopInstance

    void processNetworkEvents();	// processes events received from network connection.
    void processNetworkPlayerEvents();	// processes player evernts received from network connection
    void updateDirectionsAndMovements();	// updates the movement and directions of game world objecxts
//    void updatePlayerDirections();  // updates the direction players are facing
    void updateBasketballMovements();	// updates the movement of basketball(s)
    void updateBasketballDirections();	// updates the direction of basketball(s)
    bool assignHoopToTeams();  // assigns which hoop belongs to each team
    bool assignTeams(); // assigns the teams which are playing
    bool assignPlayers();   // assigns the players that are playing.
    bool setupEnvironment();    // sets up the 3D environment for the game
    void setBasketballStartPositions();	// sets the initial coordinates for the basketball(s).
    void setCourtStartPositions();	// sets the initial coordinates for the court(s).
    void setHoopStartPositions();	// sets the initial coordinates for the hoop(s).

    // Tip Off execution code.  // Move to proper class
    bool setupTipOff();	// sets up Tip Off conditions
    bool executeTipOff();  // executes the game tip off

    bool createBasketballInstances();  // creates the instances of the basketballs

    bool createTeamInstances();  // creates the instances of the teams

    bool createCourtDataInstances();  // creates instances of court data

    bool createCourtInstances();  // creates court Instances

    bool createHoopInstances();  // creates hoop Instances

    bool setupState();   // sets up the game condition
    bool logic();   // carries out in game logic

    // updates positions of gameState objects
    bool updatePositions();

protected:
    gameState();
    gameState(const gameState&);
    gameState &operator = (const gameState&);

private:
    //static gameState *pInstance;
    static boost::shared_ptr<gameState> pInstance;

    gameTypes gameType;	// Indicates whether a single or multi player game is being played.
    bool gameSetupComplete; // indicates whether initial game setup is complete.
    quarters currentQuarter;    // defines which quarter the game is in.

    float gameTimeLeft; // Indicates the time left in the game
    float quarterTimeLeft;  // incates the time left in the current quarter

    bool finished;  // indicates whether a game is finished.

    std::vector<teamData> teamDataInstance;	// stores the vector of teams loaded from the xml files
    std::vector<playerData> playerDataInstance;	// stores the vector of the players loaded from the xml files
    std::vector<courtData> courtDataInstance;	// stores the vector the courts loaded from the xml files

    int selectedCourtDataInstance;  // stores which court should be loaded by courtInstance
    
    std::vector<int> teamID;      // std::vector that stores the IDs of the 2 teams currently playing
    std::vector<int> playerID;       // std::vector that stores the IDs of the players currently being used.

    std::vector< std::vector<int> > teamStarterID; // stores the selected starters for each team


    std::vector <basketballs> basketballInstance;    // creates instance of the basketballs class
    std::vector <courtState> courtInstance;  // creates instance of the courtState class
    std::vector <hoopState> hoopInstance;  // creates instance of the hoop class

//    std::vector <playerState> playerInstance;    // creates instance of the playerState class
    std::vector <teamState>  teamInstance;   // creates instance of the teamState class

    bool basketballModelLoaded;	// stores whether basketball model has been loaded
    bool courtModelLoaded;	// stores whether court model has been loaded
    bool hoopModelLoaded;  // stores whether the hoop model has been loaded
    bool setupEnvironmentCompleted;	// stores whether environment has been setup
    bool courtDataLoaded;  // stores whether or not the court data has been loaded from file
    bool courtInstanceCreated;  // stores whether team instances have been created
    bool teamInstancesCreated;  // stores whether team instances have been created
    bool sceneCreated;				// stores whether the scene has been created
    bool gameStarted;   // Determines whether or not a basketball game has been started

    // Tip Offs
    bool tipOffComplete;	// Determines whether or not game Tip Off has completed
    bool ballTipped;	//	stores whether or not the ball has been tipped
    bool ballTipForceApplied;	// stores whether or not force has been applied to tipped ball
    bool playerHasBasketball;  // stores whether or not a player has control of the basketball
    int ballTippedToTeam;	//  stores which team the ball has been tipped to
    int ballTippedToPlayerID;	// stores which player ID the ball has been tipped to

    int teamWithBall; // stores which team has control of the basketball, valid values are 0 or 1

    int bballBounce;	// stores which direction the ball is bouncing;

};


#endif // _GAMESTATE_H_
