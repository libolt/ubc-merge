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

