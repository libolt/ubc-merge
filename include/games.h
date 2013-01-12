//
// C++ Interface: games
//
// Description:
//
//
// Author: Mike McLean <libolt@libolt.net>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _GAMES_H_
#define _GAMES_H_

#include "Ogre.h"
#include "playerstate.h"
#include "teamstate.h"


// handles the in-game portion
class games
{
public:
	virtual ~games();	// destructor
    static games *Instance();

    virtual bool setupState();   // sets up the game condition
    virtual bool logic();   // carries out in game logic
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

    // Tip Off execution code.  // Move to proper class
    virtual bool setupTipOff();	// sets up Tip Off conditions
    virtual bool executeTipOff();



protected:
    games();
    games(const games&);
    games &operator= (const games&);
private:
    static games *pInstance;

    int x;
    int y;
    int i;
    int j;

    bool gameStarted;   // Determines whether or not a basketball game has been started
    bool shotTaken;	// Determines whether or not a player has shot the ball
    bool shotComplete;	// Determine whether or not a player's shot is complete
    bool tipOffComplete;	// Determines whether or not game Tip Off has completed

};

#endif

