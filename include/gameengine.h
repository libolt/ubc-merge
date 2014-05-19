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

#ifndef _GAMEENGINE_H_
#define _GAMEENGINE_H_

#include "OgreTimer.h"
#include "OgreVector3.h"

#include "players.h"

class gameEngine : public players
{

public:
    virtual ~gameEngine();

    static gameEngine *Instance();

    virtual bool getMenuActive();					// retrieves menuActive variable
    virtual void setMenuActive(bool active);		// sets menuActive variable

    virtual bool getQuitGame();						// retrieves quitGame variable
    virtual void setQuitGame(bool quit);			// sets quitGame variable

    virtual bool getServerRunning();				// retrieves serverRunning variable
    virtual void setServerRunning(bool server);		// sets serverRunning variable

    virtual bool getClientRunning();				// retrieves clientRunning variable
    virtual void setClientRunning(bool client);		// sets clientRunning variable

    virtual bool getCreateScene();					// retrieves createScene variable
    virtual void setCreateScene(bool scene);		// sets createScene variable

    virtual bool getSceneCreated();					// returns sceneCreated variable
    virtual void setSceneCreated(bool created);		// sets sceneCreated variable

    virtual bool getRenderScene();					// retrieves renderScene variable
    virtual void setRenderScene(bool scene);		// sets renderScene variable

    virtual bool getMovePlayer();					// retrieves movePlayer variable
    virtual void setMovePlayer(bool player);		    // sets movePlayer variable

    virtual Ogre::Timer getLoopTime();				// retrieves loopTime variable
    virtual void setLoopTIme(Ogre::Timer time);		// sets loopTime variable

    virtual unsigned long getOldTime();				// retrieves oldTime variable
    virtual void setOldTime(unsigned long time);	// sets oldTime variable

    virtual unsigned long getChangeInTime();			// retrieves changeInTime variable
    virtual void setChangeInTime(unsigned long change);	// sets changeInTime variable

    virtual void updateChangeInTime();					// updates the game timer variables

    // starts a game
    virtual bool startGame();

    // quits entire game
    virtual void quit();

    virtual void gameLoop();	// runs the Main loop for the game

protected:
    gameEngine();
    gameEngine(const gameEngine&);
    gameEngine& operator= (const gameEngine&);

private:
    int x;
    int y;
    int i;
    int j;
    Ogre::Vector3 courtTranslateVector;

    // time variables
    Ogre::Timer loopTime;	// loop Timer
    unsigned long oldTime;	// stores the last reading of the timer.
    unsigned long changeInTime; // stores the difference between current reading of the timer and the previous reading.

    static gameEngine *pInstance;

    // Flags
    bool menuActive;	// determines whether or not a menu is active
    bool start;			// if set then starts running game logic
    bool quitGame;		// if set then triggers the shutdown process for the game
    bool serverRunning;	// if set triggers the network server code
    bool clientRunning;	// if set triggers the network client code
    bool createScene;	// if set triggers the render system's createScene function
    bool sceneCreated;	// stores whether scene has been created
    bool renderScene;	// if set triggers the render system's scene rendering function
    bool movePlayer;	// if set triggers movement of a player for testing netwoirk code
};

#endif // _GAMEENGINE_H_
