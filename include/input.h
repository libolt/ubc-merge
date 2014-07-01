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

#ifndef _INPUT_H_
#define _INPUT_H_

#include "OIS/OIS.h"
#include "SDL.h"
#include "SDL_syswm.h"
#include "Ogre.h"

#include "enums.h"

// input class
class inputSystem
{
public:

	static inputSystem *Instance();

    virtual bool setup();   // sets up and initializes the  Input System
    virtual bool destroy(); // destroys the Input system and related objects

	virtual inputMaps keyMap();  // maps value of keyPressed string to inputMap
	
    virtual bool processInput();	// processes all input
    virtual bool processUnbufferedKeyInput();	// reads in unbuffered key presses
    virtual bool processUnbufferedMouseInput();	// reads in unbuffered mouse input

    // SDL Input functions
    virtual SDL_Event getInputEvent();   // retrieves the value of the inputEvent variable
    void setInputEvent(SDL_Event input); // sets the value of the inputEvent variable

    virtual Ogre::String getKeyPressed(); // retrieves the value of the keyPressed pressed variable
    void setKeyPressed(Ogre::String key); // sets the value of the keyPressed variable

	virtual inputMaps getInputMap();  // retrieves the value of the inputMap variable
	void setInputMap(inputMaps map);  // sets the value of the inputMap variable

protected:
	inputSystem();
	inputSystem(const inputSystem&);
	inputSystem& operator= (const inputSystem&);

    virtual ~inputSystem();
    // SDL Input
    SDL_Event inputEvent;

    int mouseX; // stores the X coordinate of the mouse.
    int mouseY; // stores the Y coordinate of the mouse.
    int mouseLeftClick;	// stores state of Left mouse button
    int mouseRightClick; // stores state of Right mouse button;

private:
	static inputSystem *pInstance;

	Ogre::String keyPressed; // stores which key was pressed
	
	inputMaps inputMap; // stores user input

};


#endif

