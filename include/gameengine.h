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

#ifndef _GAMEENGINE_H_
#define _GAMEENGINE_H_

#include "OgreTimer.h"
#include "OgreVector3.h"
#include <boost/shared_ptr.hpp>
#include <boost/chrono/system_clocks.hpp>

#include "players.h"
#include "threads.h"
#include "timing.h"

class gameEngine : public players
{

public:
    ~gameEngine();
    
    //static gameEngine *Instance();
    static boost::shared_ptr<gameEngine> Instance();
    
    timing getTimer();  // retrieves the value of timer
    void setTimer(timing time);  // sets the value of timer
    
    bool getMenuActive();					// retrieves menuActive variable
    void setMenuActive(bool active);		// sets menuActive variable

    bool getQuitGame();						// retrieves quitGame variable
    void setQuitGame(bool quit);			// sets quitGame variable

    bool getServerRunning();				// retrieves serverRunning variable
    void setServerRunning(bool server);		// sets serverRunning variable

    bool getClientRunning();				// retrieves clientRunning variable
    void setClientRunning(bool client);		// sets clientRunning variable

    bool getCreateScene();					// retrieves createScene variable
    void setCreateScene(bool scene);		// sets createScene variable

    bool getSceneCreated();					// returns sceneCreated variable
    void setSceneCreated(bool created);		// sets sceneCreated variable

    bool getRenderScene();					// retrieves renderScene variable
    void setRenderScene(bool scene);		// sets renderScene variable

    bool getMovePlayer();					// retrieves movePlayer variable
    void setMovePlayer(bool player);		    // sets movePlayer variable

    float getYOffset(); // returns the value of yOffset
    void setYOffset(float set); // sets the value of yOffset

    // starts a game
    bool startGame();

    // quits entire game
    void quit();

    void gameLoop();	// runs the Main loop for the game

	void processInput();  // processes game input
	
protected:
    gameEngine();
    gameEngine(const gameEngine&);
    gameEngine& operator= (const gameEngine&);

private:

    //static gameEngine *pInstance;
    static boost::shared_ptr<gameEngine> pInstance;

    int x;
    int y;
    int i;
    int j;
    
    float yOffset; // stores the y offset for objects on the screen
    
    Ogre::Vector3 courtTranslateVector;

    // time variables
    //Ogre::Timer loopTime;	// loop Timer
/*    boost::chrono::system_clock::time_point startLoopTime; // start loop Timer
    boost::chrono::system_clock::time_point loopTime; // loop Timer
    boost::chrono::milliseconds oldTime;	// stores the last reading of the timer.
    unsigned long changeInTime; // stores the difference between current reading of the timer and the previous reading.
*/
	timing timer;
    

    // Flags
    bool userInputLoaded; // if set then user input configuration has been loaded from file
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
