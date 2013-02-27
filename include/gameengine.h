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

    virtual bool getMenuActive();
    virtual void setMenuActive(bool active);
    virtual bool getQuitGame();
    virtual void setQuitGame(bool quit);
    virtual Ogre::Timer getLoopTime();
    virtual void setLoopTIme(Ogre::Timer time);
    virtual unsigned long getOldTime();
    virtual void setOldTime(unsigned long time);

    // starts a game
    virtual bool startGame();

    // quits entire game
    virtual void quit();
    Ogre::Timer loopTime;

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
    unsigned long oldTime;

    static gameEngine *pInstance;

    // Flags
    bool menuActive;	// determines whether or not a menu is active
    bool quitGame;

};

#endif // _GAMEENGINE_H_
