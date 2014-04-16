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

#ifndef _UBCAPP_H_
#define _UBCAPP_H_

#ifdef __ANDROID__
#include "android-config.h"
#else
#include "config.h"
#endif

#include "gui.h"
#include "SDL.h"
#include "SDL_syswm.h"
#include "SDL_test_common.h"
#include "Ogre.h"
#include "OgreStringConverter.h" 
#include "OgreString.h"
#include "renderengine.h"
#include "gameengine.h"
#include "gamestate.h"
#include "input.h"
#include "network.h"
#include "players.h"
#include "playerdata.h"
#include "playerstate.h"

class UBC
{
public:
	virtual ~UBC();	// destructor

	virtual bool getQuitGame();
	void setQuitGame(bool quit);
protected:
    UBC();
//    UBC(const UBC&);
//    UBC &operator= (const UBC&);
private:
//    static UBC *pInstance;

    bool quitGame;
};

/* class UBC : public players, gameObjects //, inputSystem, gameObjects, players
{
public:
//	UBC(void);
    virtual ~UBC();

    static UBC *Instance();

    virtual bool getMenuActive();
    virtual void setMenuActive(bool active);

    // starts a game
    virtual bool startGame();

    // quits entire game
    virtual void quit();

    virtual void createScene();
    virtual bool frameStarted();
    virtual bool frameEnded();
    virtual void createSceneManager();

    bool quitGame;

protected:
    UBC();
    UBC(const UBC&);
    UBC& operator= (const UBC&);


//    virtual void loads(string pFilename);	// loads data from XML files

    int x;
    int y;
    int i;
    int j;
    Ogre::Vector3 courtTranslateVector;
    Ogre::Timer loopTime;
    unsigned long oldTime;
private:

    static UBC *pInstance;

    // Flags
    bool menuActive;	// determines whether or not a menu is active


};
*/

#endif

