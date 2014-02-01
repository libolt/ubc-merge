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

// Input

#include "gameengine.h"
#include "gamestate.h"
#include "ubcapp.h"

using namespace OIS;

inputSystem* inputSystem::pInstance = 0;

inputSystem* inputSystem::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new inputSystem; // create sole instance
    }
    return pInstance; // address of sole instance
}

// inputSystem constructor
inputSystem::inputSystem()
{
	mouseX = 0;
	mouseY = 0;
	mouseLeftClick = -1;
	mouseRightClick = -1;
    setup();
}

inputSystem::~inputSystem()
{
}

SDL_Event inputSystem::getInputEvent()
{
	return (inputEvent);
}

void inputSystem::setInputEvent(SDL_Event input)
{
	inputEvent = input;
}


Ogre::String inputSystem::getKeyPressed() // retrieves keyPressed
{
	return(keyPressed);
}

void inputSystem::setKeyPressed(Ogre::String key)
{
	keyPressed = key;
}

OIS::InputManager *inputSystem::getIM() // retrieves the im input manager
{
    return (im);
}

void inputSystem::setIM(OIS::InputManager *IM)  // sets the im input manager
{
    im = IM;
}

OIS::Mouse *inputSystem::getMMouse()    // retrieves mMouse
{
    return (mMouse);
}
void inputSystem::setMMouse(OIS::Mouse *mouse)  // sets mMouse
{
    mMouse = mouse;
}

OIS::Keyboard *inputSystem::getMKeyboard()    // retrieves mKeyboard
{
    return (mKeyboard);
}
void inputSystem::setMKeyboard(OIS::Keyboard *keyboard)  // sets mKeyboard
{
    mKeyboard = keyboard;
}

OIS::JoyStick *inputSystem::getMJoy()    // retrieves mJoy
{
    return (mJoy);
}
void inputSystem::setMJoy(OIS::JoyStick *joystick)  // sets mJoy
{
    mJoy = joystick;
}

bool inputSystem::getBufferedKeys()    // retrieves bufferedKeys
{
    return (bufferedKeys);
}
void inputSystem::setBufferedKeys(bool keys)  // sets bufferedKeys
{
    bufferedKeys = keys;
}

bool inputSystem::getBufferedMouse()    // retrieves bufferedMouse
{
    return (bufferedMouse);
}
void inputSystem::setBufferedMouse(bool mouse)  // sets bufferedMouse
{
    bufferedMouse = mouse;
}

bool inputSystem::getBufferedJoy()    // retrieves bufferedJoy
{
    return (bufferedJoy);
}
void inputSystem::setBufferedJoy(bool joy)  // sets bufferedJoy
{
    bufferedJoy = joy;
}

OIS::MouseEvent *inputSystem::getMouseEvent()   // retrieves mouseEvent
{
        return (mouseEvent);
}
void inputSystem::seMouseEvent(OIS::MouseEvent *event)  // sets mouseEvent
{
    mouseEvent = event;

}
OIS::MouseButtonID inputSystem::getMouseButtonID()   // retrieves mouseEvent
{
    return (mouseButtonID);
}
void inputSystem::seMouseButtonID(OIS::MouseButtonID buttonID)  // sets mouseEvent
{
    mouseButtonID = buttonID;
}


bool inputSystem::setup()   // sets up and initializes the OIS Input System
{
//    UBC *ubc = UBC::Instance();
//    renderEngine * render = renderEngine::Instance();
//              mDebugOverlay = OverlayManager::getSingleton().getByName("Core/DebugOverlay");

    Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing SDL Input System ***");
    SDL_ShowCursor(0); // Hides the SDL Cursor in favor of the MyGUI Cursor

    /* Old OIS Code
    ParamList pl;
    size_t windowHnd = 0;
    std::ostringstream windowHndStr;
    render->getMWindow()->getCustomAttribute("WINDOW", &windowHnd);
    windowHndStr << windowHnd;
    pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

    im = InputManager::createInputSystem( pl );

    //Create all devices (We only catch joystick exceptions here, as, most people have Key/Mouse)
    mKeyboard = static_cast<Keyboard*>(im->createInputObject( OISKeyboard, bufferedKeys ));
    mMouse = static_cast<Mouse*>(im->createInputObject( OISMouse, bufferedMouse ));
    try
    {
        mJoy = static_cast<JoyStick*>(im->createInputObject( OISJoyStick, bufferedJoy ));
    }
    catch(...)
    {
        mJoy = 0;
    }
    //Set initial mouse clipping size
//    windowResized(ubc->getMWindow());
    //Register as a Window listener
//    WindowEventUtilities::addWindowEventListener(ubc->getMWindow(), this);
  */

    return true;
}

bool inputSystem::destroy() // destroys the OIS Input System and related objects
{
/* Old OIS Code
    if(im)
    {
        im->destroyInputObject(mMouse);
        im->destroyInputObject(mKeyboard);
        im->destroyInputObject(mJoy);
        im->destroyInputSystem(im);
    }
*/
    return true;
}

bool inputSystem::processInput()	// processes all input
{

    // processes keyboard input
    if (processUnbufferedKeyInput() == false)
    {
        return false;
    }

    // processes mouse input
    if (processUnbufferedMouseInput() == false)
    {
        return false;
    }
    return true;
}

bool inputSystem::processUnbufferedKeyInput()
{

	if (MyGUI::InputManager::getInstance().isFocusKey())	// checks if a MyGUI widget has key focus
	{
		if (SDL_PollEvent(&inputEvent))
		{
	        switch (inputEvent.type)
	        {
	        case SDL_KEYDOWN:
				switch (inputEvent.key.keysym.sym)
				{
					case SDLK_RETURN:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Return, MyGUI::KeyCode::Return);
					break;
					case SDLK_BACKSPACE:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Backspace, 0);
					break;
					case SDLK_ESCAPE:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Escape, 0);
					break;
					case SDLK_TAB:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Tab, 0);
					break;
					case SDLK_SPACE:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Space, ' ');
					break;
					case SDLK_LSHIFT:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::LeftShift, 0);
					break;
					case SDLK_LCTRL:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::LeftControl, 0);
					break;
					case SDLK_LALT:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::LeftAlt, 0);
					break;
					case SDLK_LGUI:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::LeftWindows, 0);
					break;
					case SDLK_RSHIFT:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightShift, 0);
					break;
					case SDLK_RCTRL:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightControl, 0);
					break;
					case SDLK_RALT:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightAlt, 0);
					break;
					case SDLK_RGUI:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightWindows, 0);
					break;
					case SDLK_MENU:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightWindow, 0);
					break;
					case SDLK_CAPSLOCK:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Capital, 0);
					break;
					case SDLK_F1:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F1, 0);
					break;
					case SDLK_F2:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F2, 0);
					break;
					case SDLK_F3:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F3, 0);
					break;
					case SDLK_F4:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F4, 0);
					break;
					case SDLK_F5:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F5, 0);
					break;
					case SDLK_F6:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F6, 0);
					break;
					case SDLK_F7:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F7, 0);
					break;
					case SDLK_F8:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F8, 0);
					break;
					case SDLK_F9:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F9, 0);
					break;
					case SDLK_F10:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F10, 0);
					break;
					case SDLK_F11:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F11, 0);
					break;
					case SDLK_F12:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F12, 0);
					break;
					case SDLK_UP:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ArrowUp, 0);
					break;
					case SDLK_DOWN:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ArrowDown, 0);
					break;
					case SDLK_LEFT:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ArrowLeft, 0);
					break;
					case SDLK_RIGHT:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ArrowRight, 0);
					break;
					case SDLK_SCROLLLOCK:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ScrollLock, 0);
					break;
					case SDLK_HOME:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Home, 0);
					break;
					case SDLK_PAUSE:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Pause, 0);
					break;
					case SDLK_INSERT:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Insert, 0);
					break;
					case SDLK_PAGEUP:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::PageUp, 0);
					break;
					case SDLK_DELETE:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Delete, 0);
					break;
					case SDLK_END:
					MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::End, 0);
					break;
					case SDLK_PAGEDOWN:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::PageDown, 0);
					break;
					case SDLK_NUMLOCKCLEAR:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::NumLock, 0);
					break;
					case SDLK_KP_DIVIDE:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Divide, 0);
					break;
					case SDLK_KP_MULTIPLY:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Multiply, 0);
					break;
					case SDLK_KP_MINUS:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Minus, 0);
					break;
					case SDLK_KP_ENTER:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::NumpadEnter, 0);
					break;
					case SDLK_KP_0:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad0, '0');
					break;
					case SDLK_KP_1:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad1, '1');
					break;
					case SDLK_KP_2:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad2, '2');
					break;
					case SDLK_KP_3:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad3, '3');
					break;
					case SDLK_KP_4:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad4, '4');
					break;
					case SDLK_KP_5:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad5, '5');
					break;
					case SDLK_KP_6:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad6, '6');
					break;
					case SDLK_KP_7:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad7, '7');
					break;
					case SDLK_KP_8:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad8, '8');
					break;
					case SDLK_KP_9:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad9, '9');
					break;
					case SDLK_6:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Enum(6), '6');
					break;
					default:
						MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Enum(inputEvent.key.keysym.sym), inputEvent.key.keysym.sym);
					break;
				}
	            break;
	        case SDL_KEYUP:
				switch (inputEvent.key.keysym.sym)
				{
					case SDLK_RETURN:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Return);
					break;
					case SDLK_BACKSPACE:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Backspace);
					break;
					case SDLK_ESCAPE:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Escape);
					break;
					case SDLK_TAB:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Tab);
					break;
					case SDLK_SPACE:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Space);
					break;
					case SDLK_LSHIFT:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::LeftShift);
					break;
					case SDLK_LCTRL:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::LeftControl);
					break;
					case SDLK_LALT:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::LeftAlt);
					break;
					case SDLK_LGUI:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::LeftWindows);
					break;
					case SDLK_RSHIFT:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::RightShift);
					break;
					case SDLK_RCTRL:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::RightControl);
					break;
					case SDLK_RALT:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::RightAlt);
					break;
					case SDLK_RGUI:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::RightWindows);
					break;
					case SDLK_MENU:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::RightWindow);
					break;
					case SDLK_CAPSLOCK:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Capital);
					break;
					case SDLK_F1:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::F1);
					break;
					case SDLK_F2:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::F2);
					break;
					case SDLK_F3:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::F3);
					break;
					case SDLK_F4:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::F4);
					break;
					case SDLK_F5:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::F5);
					break;
					case SDLK_F6:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::F6);
					break;
					case SDLK_F7:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::F7);
					break;
					case SDLK_F8:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::F8);
					break;
					case SDLK_F9:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::F9);
					break;
					case SDLK_F10:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::F10);
					break;
					case SDLK_F11:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::F11);
					break;
					case SDLK_F12:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::F12);
					break;
					case SDLK_UP:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::ArrowUp);
					break;
					case SDLK_DOWN:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::ArrowDown);
					break;
					case SDLK_LEFT:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::ArrowLeft);
					break;
					case SDLK_RIGHT:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::ArrowRight);
					break;
					case SDLK_SCROLLLOCK:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::ScrollLock);
					break;
					case SDLK_HOME:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Home);
					break;
					case SDLK_PAUSE:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Pause);
					break;
					case SDLK_INSERT:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Insert);
					break;
					case SDLK_PAGEUP:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::PageUp);
					break;
					case SDLK_DELETE:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Delete);
					break;
					case SDLK_END:
					MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::End);
					break;
					case SDLK_PAGEDOWN:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::PageDown);
					break;
					case SDLK_NUMLOCKCLEAR:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::NumLock);
					break;
					case SDLK_KP_DIVIDE:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Divide);
					break;
					case SDLK_KP_MULTIPLY:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Multiply);
					break;
					case SDLK_KP_MINUS:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Minus);
					break;
					case SDLK_KP_ENTER:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::NumpadEnter);
					break;
					case SDLK_KP_0:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Numpad0);
					break;
					case SDLK_KP_1:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Numpad1);
					break;
					case SDLK_KP_2:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Numpad2);
					break;
					case SDLK_KP_3:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Numpad3);
					break;
					case SDLK_KP_4:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Numpad4);
					break;
					case SDLK_KP_5:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Numpad5);
					break;
					case SDLK_KP_6:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Numpad6);
					break;
					case SDLK_KP_7:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Numpad7);
					break;
					case SDLK_KP_8:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Numpad8);
					break;
					case SDLK_KP_9:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Numpad9);
					break;
					case SDLK_6:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Enum(6));
					break;
					default:
						MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Enum(inputEvent.key.keysym.sym));
					break;
				}
	            break;
	        case SDL_QUIT:
	 //           status = 1;
	            break;
	        }
		}
//		exit(0);

	}
	else	// Processes input normally when MyGUI Widget not focused
	{
		keyPressed = "";	// resets keyPressed so that we don't get repeats
		if (SDL_PollEvent(&inputEvent))
		{
			switch (inputEvent.type)
			{
			case SDL_KEYDOWN:
				switch (inputEvent.key.keysym.sym)
				{
				case SDLK_UP:
					keyPressed = "up";
					break;
				case SDLK_DOWN:
					keyPressed = "down";
					break;
				case SDLK_LEFT:
					keyPressed = "left";
					break;
				case SDLK_RIGHT:
					keyPressed = "right";
					break;
				case SDLK_q:
					keyPressed = "q";
					break;
				}
				break;
			case SDL_KEYUP:
				keyPressed = "";
				// if escape is pressed, quit
	 //               status = 1; // set status to 1 to exit main loop
				break;
			case SDL_QUIT:
	 //           status = 1;
				break;
			}

		}
	}

    // Return true to continue rendering
    return true;

}

bool inputSystem::processUnbufferedMouseInput()
{
	int x, y;
	int state = -1;
	SDL_MouseMotionEvent motion;
	SDL_GetMouseState(&x,&y);

	SDL_PumpEvents();
	state = SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1);
//	std::cout << "Mouse State = " << state << std::endl;

	if (MyGUI::InputManager::getInstance().isFocusMouse())
	{
//		std::cout << "focused" << std::endl;
		if(state == 1)
		{
			mouseLeftClick = 1;
	   	 MyGUI::InputManager::getInstance().injectMousePress(x, y, MyGUI::MouseButton::Enum(0));

	//		exit(0);
		}
		else if (state == 0 && mouseLeftClick == 1) //if (SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1) == 0)
		{
			mouseLeftClick = 0;
		   	 MyGUI::InputManager::getInstance().injectMouseRelease(x, y, MyGUI::MouseButton::Enum(0));

		}
	}

/*	if (SDL_PollEvent(&inputEvent))
	{
        switch (inputEvent.type)
        {
        case SDL_MOUSEMOTION:
     //   	exit(1);
            break;
        case SDL_MOUSEBUTTONDOWN:
        	switch (inputEvent.button.button)
        	case SDL_BUTTON_LEFT:
        	//	exit(0);
        	break;
        	//	exit(0);
        	 MyGUI::InputManager::getInstance().injectMousePress(x, y, MyGUI::MouseButton::Enum(inputEvent.button.button));
        	break;
        case SDL_MOUSEBUTTONUP:
       	    MyGUI::InputManager::getInstance().injectMousePress(x, y, MyGUI::MouseButton::Enum(inputEvent.button.button));
       	 //   exit(2);
       	    break;
        case SDL_QUIT:
 //           status = 1;
            break;
        }

    }
*/

//    Ogre::LogManager::getSingletonPtr()->logMessage("Mouse X = "  +Ogre::StringConverter::toString(x));
	if (mouseX != x || mouseY != y)
	{
		MyGUI::InputManager::getInstance().injectMouseMove(x,y,0);
	}

	/* Old OIS Code
    using namespace OIS;

//    UBC *ubc = UBC::Instance();
    gameEngine *gameE = gameEngine::Instance();
    renderEngine *render = renderEngine::Instance();

    Ogre::Vector3 mTranslateVector = render->getMTranslateVector();
    Radian mRotX = render->getMRotX();
    Radian mRotY = render->getMRotY();

    mMouse->capture();

    const MouseState &ms = mMouse->getMouseState();

//    CEGUI::System::getSingleton().injectMouseMove(ms.X.rel,ms.Y.rel);

    if (gameE->getMenuActive())
    {
        if ( ms.buttonDown( MB_Left) )
        {
 //           CEGUI::System::getSingleton().injectMouseButtonDown(convertOgreButtonToCegui(mMouse->getID()));
    	}

        else
        {
 //           CEGUI::System::getSingleton().injectMouseButtonUp(convertOgreButtonToCegui(mMouse->getID()));
        }
    }

    else
    {
//        if( ms.buttonDown( MB_Right ) )
//        {
//            mTranslateVector.x += ms.X.rel * 0.13;
//            mTranslateVector.y -= ms.Y.rel * 0.13;
//        }
//        else
//        {
//            mRotX = Degree(-ms.X.rel * 0.13);
//            mRotY = Degree(-ms.Y.rel * 0.13);
//        }

    }

    render->setMTranslateVector(mTranslateVector);
    render->setMRotX(mRotX);
    render->setMRotY(mRotY);
*/
    return true;
}
