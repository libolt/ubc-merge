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

#ifndef _INPUT_H_
#define _INPUT_H_

#include "OIS/OIS.h"
#include "SDL.h"
#include "SDL_syswm.h"
#include "Ogre.h"
// input class
class inputSystem
{
public:

	static inputSystem *Instance();

    virtual bool setup();   // sets up and initializes the  Input System
    virtual bool destroy(); // destroys the OIS Input system and related objects

    virtual bool processInput();	// processes all input
    virtual bool processUnbufferedKeyInput();	// reads in unbuffered key presses
    virtual bool processUnbufferedMouseInput();	// reads in unbuffered mouse input

    // SDL Input functions
    virtual SDL_Event getInputEvent();   // retrieves inputEvent
    void setInputEvent(SDL_Event input); // sets inputEvent

    virtual Ogre::String getKeyPressed(); // retrieves keyPressed
    void setKeyPressed(Ogre::String key); // sets keyPressed

    // Old OIS Input code
    virtual OIS::InputManager *getIM(); // retrieves the im input manager
    void setIM(OIS::InputManager *IM);  // sets the im input manager

    virtual OIS::Mouse *getMMouse();    // retrieves mMouse
    void setMMouse(OIS::Mouse *mouse);  // sets mMouse

    virtual OIS::Keyboard *getMKeyboard();    // retrieves mKeyboard
    void setMKeyboard(OIS::Keyboard *keyboard);  // sets mKeyboard

    virtual OIS::JoyStick *getMJoy();    // retrieves mJoy
    void setMJoy(OIS::JoyStick *joystick);  // sets mJoy

    virtual bool getBufferedKeys();    // retrieves bufferedKeys
    void setBufferedKeys(bool keys);  // sets bufferedKeys

    virtual bool getBufferedMouse();    // retrieves bufferedMouse
    void setBufferedMouse(bool mouse);  // sets bufferedMouse

    virtual bool getBufferedJoy();    // retrieves bufferedJoy
    void setBufferedJoy(bool joy);  // sets bufferedJoy

    virtual OIS::MouseEvent *getMouseEvent();   // retrieves mouseEvent
    void seMouseEvent(OIS::MouseEvent *event);  // sets mouseEvent

    virtual OIS::MouseButtonID getMouseButtonID();   // retrieves mouseEvent
    void seMouseButtonID(OIS::MouseButtonID buttonID);  // sets mouseEvent

protected:
	inputSystem();
	inputSystem(const inputSystem&);
	inputSystem& operator= (const inputSystem&);

    virtual ~inputSystem();
    // SDL Input
    SDL_Event inputEvent;

    //OIS Input devices
    OIS::Mouse *mMouse;
    OIS::Keyboard *mKeyboard;
    OIS::JoyStick *mJoy;
    OIS::InputManager *im;
    bool bufferedKeys;
    bool bufferedMouse;
    bool bufferedJoy;
    OIS::MouseEvent *mouseEvent;
    OIS::MouseButtonID mouseButtonID;
private:
	static inputSystem *pInstance;

	Ogre::String keyPressed;

};


#endif

