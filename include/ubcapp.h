/***************************************************************************
 *   Copyright (C) 2006 by Mike McLean   *
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

//#include "ogreapplication.h"
#include "config.h"
#include "gui.h"
#include "basketballs.h"
#include "input.h"
#include "load.h"
#include "players.h"
#include "rendersystems.h"
#include "sound.h"
#include "teams.h"
#include "tinyxml.h"

#ifdef __APPLE__
#include <Ogre/OgreStringConverter.h>
#else
#include <OgreStringConverter.h>
#endif
//#include <OgreOde_Core.h>
#define OIS_DYNAMIC_LIB
#include <OIS/OIS.h>
#include "OgreTimer.h"
#include "OgreVector3.h"

class gameObjects
{

public:
    gameObjects(void);
    virtual ~gameObjects();

//protected:



    // Variables;
    int playerHasBasketball;	// value of the player who has the basketball [0-9];
};

class UBC : public players, gameObjects //, inputSystem, gameObjects, players
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

#endif

