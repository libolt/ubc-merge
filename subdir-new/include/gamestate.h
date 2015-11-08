/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean   *
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
#include "jumpballs.h"

//using namespace std;
class gameState
{
public:

    //static gameState *Instance();
    static boost::shared_ptr<gameState> Instance();

    ~gameState();

    gameTypes getGameType();  // retrieves the value of gameType
    void setGameType(gameTypes set);  // sets the value of gameType

    quarters getQuarter();  // retrieves the value of quarter
    void setQuarters(quarters set);  // sets he value of quarter

    bool getGameSetupComplete();  // retrieves the value of gameSetupComplete
    void setGameSetupComplete(bool set);  // sets the value of gameSetupComplete


    bool getPlayerHasBasketball();  // retrieves the value of playerHasBasketball
    void setPlayerHasBasketball(bool set);  // setd the value of playerHasBasketball
    
    bool getGameStarted(void);  // retrieves the gameStarted value
    void setGameStarted(bool set);  // sets gameStarted value

    jumpBalls getJumpBall();  // retrieves the value of jumpBall
    void setJumpBall(jumpBalls &set);  // sets the value of jumpBall

    teamTypes getTeamWithBall(void);  // retrieves teamWithBall value
    void setTeamWithBall(teamTypes set);	 // sets teamWithBall value

    size_t getBballBounce();  // retrieves the value of bballBounce
    void setBballBounce(size_t set);  // sets the value of bballBounce

    bool getCourtDataLoaded();  // retrieves the value of courtDataLoaded
    void setCourtDataLoaded(bool set);  // sets the value of courtDataLoaded

    size_t getSelectedCourtDataInstance();  // retrieves the value of selectedCourtDataInstance
    void setSelectedCourtDataInstance(size_t set);  // sets the value of selectedCourtDataInstance

    bool getCourtInstanceCreated();  // retrieves the value of courtInstanceCreated
    void setCourtInstanceCreated(bool created);  // sets the value of courtInstanceCreated

    bool getCourtModelLoaded();  // retrieves the value of courtModelLoaded
    void setCourdModelLoaded(bool set);  // sets the value of courtModelLoaded

    bool getTeamInstancesCreated();	 // retrieves the value of teamInstancesCreated
    void setTeamInstancesCreated(bool set);	 // sets the value of teamInstancesCreated

    bool getBasketballInstancesCreated();  // retrieves the value of basketballInstancesCreated
    void setBasketballInstancesCreated(bool set);   // sets the value of basketballInstancesCreated

    std::vector<teamData> getTeamDataInstance();  // retrieves the value of teamDataInstance
    void setTeamDataInstance(std::vector<teamData> set);  // sets the value of teamDataInstance;

    std::vector<playerData> getPlayerDataInstance();  // retrieves the value of playerDataInstance
    void setPlayerDataInstances(std::vector<playerData> set);  // sets the value of playerDataInstance;

    std::vector<courtData> getCourtDataInstance();  // retrieves the value of courtDataInstance
    void setCourtDataInstance(std::vector<courtData> set);  // sets the value of courtDataInstance

    size_t getActiveBBallInstance();  // retrieves the value of activeBBallInstance
    void setActiveBBallInstance(size_t set);  // sets the value of activeBBallInstance

    std::vector<size_t> getTeamID(void);  // retrieves the value of teamID
    void setTeamID(std::vector<size_t> set);  // sets the value of teamID

    std::vector<size_t> getPlayerID(void);  // retrieves the value of playerID
    void setPlayerID(std::vector<size_t> set);  // sets the value of playerID

    std::vector< std::vector<size_t> > getTeamStarterID();  // retrieves value of teamStarterID
    void setTeamStarterID(std::vector< std::vector<size_t> > set);  // sets the value of teamStarterID

    std::vector <basketballs> getBasketballInstance();  // retrieves the value of basketballInstance
    void setBasketballInstance(std::vector<basketballs> set);  // sets the value of basketballInstance

    std::vector <teamState> getTeamInstance();  // retireves the value of teamInstance
    void setTeamInstance(std::vector<teamState> set);  // sets the value of teamInstance

    std::vector <courtState> getCourtInstance();  // retrieves the value of courtInstance
    void setCourtInstance(std::vector<courtState> set);  // sets the value of courtInstance

    std::vector <hoopState> getHoopInstance();  // retrieves the value of hoopInstance
    void setHoopInstance(std::vector<hoopState> set);  // sets the value of hoopInstance

    bool getTipOffSetupComplete();  // retrieves the value of tipOffSetupComplete
    void setTipOffSetupComplete(bool set);  // sets the value of tipOffSetupComplete

    bool getTipOffComplete();  // retrieves the value of tipOffComplete
    void setTipOffComplete(bool set);  // sets the value of tipOffComplete

    bool getStateSet();  // retrieves the value of stateSet
    void setStateSet(bool set);  // sets the value of stateSet

    void processNetworkEvents();  // processes events received from network connection.
    void processNetworkPlayerEvents();  // processes player evernts received from network connection
    void updateDirectionsAndMovements();  // updates the movement and directions of game world objecxts
//    void updatePlayerDirections();  // updates the direction players are facing
    bool assignHoopToTeams();  // assigns which hoop belongs to each team
    bool setupEnvironment();  // sets up the 3D environment for the game
    void setBasketballStartPositions();  // sets the initial coordinates for the basketball(s).
    void setCourtStartPositions();  // sets the initial coordinates for the court(s).
    void setHoopStartPositions();  // sets the initial coordinates for the hoop(s).

    // Tip Off execution code.  // Move to proper class
    bool setupTipOff();  // sets up Tip Off conditions
    bool executeTipOff();  // executes the game tip off

    bool createBasketballInstances();  // creates the instances of the basketballs

    bool createTeamInstances();  // creates the instances of the teams

    bool createCourtDataInstances();  // creates instances of court data

    bool createCourtInstances();  // creates court Instances

    bool createHoopInstances();  // creates hoop Instances

    bool setupState();  // sets up the game condition
    bool updateState();  // updates the state of the game

protected:
    gameState();
    gameState(const gameState&);
    gameState &operator = (const gameState&);

private:
    //static gameState *pInstance;
    static boost::shared_ptr<gameState> pInstance;

    gameTypes gameType;  // Indicates whether a single or multi player game is being played.
    quarters quarter;  // stores the quarter currently being played

    bool gameSetupComplete;  // indicates whether initial game setup is complete.

    float gameTimeLeft;  // Indicates the time left in the game
    float quarterTimeLeft;  // incates the time left in the current quarter

    bool finished;  // indicates whether a game is finished.

    std::vector<teamData> teamDataInstance;	 // stores the vector of teams loaded from the xml files
    std::vector<playerData> playerDataInstance;  // stores the vector of the players loaded from the xml files
    std::vector<courtData> courtDataInstance;  // stores the vector the courts loaded from the xml files

    size_t selectedCourtDataInstance;  // stores which court should be loaded by courtInstance
    
    std::vector<size_t> teamID;  // std::vector that stores the IDs of the 2 teams currently playing
    std::vector<size_t> playerID;  // std::vector that stores the IDs of the players currently being used.

    std::vector< std::vector<size_t> > teamStarterID;  // stores the selected starters for each team


    std::vector <basketballs> basketballInstance;  // creates instance of the basketballs class
    std::vector <courtState> courtInstance;  // creates instance of the courtState class
    std::vector <hoopState> hoopInstance;  // creates instance of the hoop class

    std::vector <teamState>  teamInstance;  // creates instance of the teamState class

    size_t activeBBallInstance;  // stores which instance of the baskteball class is active

    bool basketballInstancesCreated;  // stores whether basketball instance(s) have been created
 
    bool courtModelLoaded;  // stores whether court model has been loaded
    bool hoopModelLoaded;  // stores whether the hoop model has been loaded
    bool setupEnvironmentCompleted;  // stores whether environment has been setup
    bool courtDataLoaded;  // stores whether or not the court data has been loaded from file
    bool courtInstanceCreated;  // stores whether team instances have been created
    bool teamInstancesCreated;  // stores whether team instances have been created
    bool sceneCreated;  // stores whether the scene has been created
    bool gameStarted;  // Determines whether or not a basketball game has been started
    bool tipOffSetupComplete;  // Determines whether or not game Tip Off has been setup
    bool tipOffComplete;  // Determines whether or not game Tip Off has completed

    jumpBalls jumpBall; // instance that is used for jumpBall functions.

    teamTypes teamWithBall;  // stores which team has control of the basketball, valid values are 0 or 1

    size_t bballBounce;  // stores which direction the ball is bouncing;

    bool stateSet;  // if true then the game state has been set

};


#endif // _GAMESTATE_H_
