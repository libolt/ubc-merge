//
// C++ Interface: input
//
// Description:
//
//
// Author: Mike McLean <libolt@libolt.net>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _INPUT_H_
#define _INPUT_H_

#include "OIS/OIS.h"

// input class
class inputSystem
{
public:

	static inputSystem *Instance();

    virtual bool setup();   // sets up and initializes the OIS Input System
    virtual bool destroy(); // destroys the OIS Input system and related objects

    virtual bool processInput();	// processes all input
    virtual bool processUnbufferedKeyInput();	// reads in unbuffered key presses
    virtual bool processUnbufferedMouseInput();	// reads in unbuffered mouse input

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


};


#endif

