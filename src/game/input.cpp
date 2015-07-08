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
 
// Input

#include "MyGUI.h"
#include "MyGUI_OgrePlatform.h"


#include "input.h"
#include "gameengine.h"
#include "gamestate.h"
#include "gui.h"
#include "renderengine.h"
#include "logging.h"
#include "load.h"

//static int32_t handleInput(struct android_app* app, AInputEvent* event);


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

inputMaps inputSystem::getInputMap()  // retrieves the value of the inputMap variable
{
//	return(inputMap);
}
void inputSystem::setInputMap(inputMaps map)  // sets the value of the inputMap variable
{
//	inputMap = map;
}

inputWorkQueues inputSystem::getInputWorkQueue()  // retrieves the value of inputWorkQueue
{
    return (inputWorkQueue);
}
void inputSystem::setInputWorkQueue(inputWorkQueues set)  // sets the value of inputWorkQueue
{
    inputWorkQueue = set;
}

std::vector<userInput> inputSystem::getUInput()  // retrieves the value of uInput
{
    return (uInput);
}
void inputSystem::setUInput(std::vector<userInput> set)  // sets the value of uInput
{
    uInput = set;
}

bool inputSystem::setup()   // sets up and initializes the OIS Input System
{
//    UBC *ubc = UBC::Instance();
//    renderEngine * render = renderEngine::Instance();
//              mDebugOverlay = OverlayManager::getSingleton().getByName("Core/DebugOverlay");

    loader *load = loader::Instance();

    uInput = load->loadUserInputs();    // loads user defined input from file.
    
    uInput[0].setActive(true);
    logMsg("*** Initializing SDL Input System ***");
    SDL_ShowCursor(0); // Hides the SDL Cursor in favor of the MyGUI Cursor

    return true;
}

bool inputSystem::destroy() // destroys the OIS Input System and related objects
{

    return true;
}

inputMaps inputSystem::keyMap()  // maps value of keyPressed string to inputMap
{
//    exit(0);
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    if (keyPressed == uInput[0].getKeyUp())
	{
//        exit(0);
		return(INUP);
	}
	else if (keyPressed == uInput[0].getKeyDown())
	{
		return(INDOWN);
	}
	else if (keyPressed == uInput[0].getKeyLeft())
	{
		return(INLEFT);
	}
	else if (keyPressed == uInput[0].getKeyRight())
	{
		return(INRIGHT);
	}
	else if (keyPressed == uInput[0].getKeyUpLeft())
	{
		return(INUPLEFT);
	}
	else if (keyPressed == uInput[0].getKeyUpRight())
	{
		return(INUPRIGHT);
	}
	else if (keyPressed == uInput[0].getKeyDownLeft())
	{
		return(INDOWNLEFT);
	}
	else if (keyPressed == uInput[0].getKeyDownRight())
	{
		return(INDOWNRIGHT);
	}
	else if (keyPressed == uInput[0].getKeyPassSteal())
	{
		return(INPASSSTEAL);
	}
	else if (keyPressed == uInput[0].getKeyShootBlock())
	{
		return(INSHOOTBLOCK);
	}
    else if (keyPressed == uInput[0].getKeyPause())
    {
        return(INPAUSE);
    }
    else if (keyPressed == uInput[0].getKeyStartSelect())
    {
        return(INSTARTSELECT);
	}
	else if (keyPressed == uInput[0].getKeyQuit())
	{
		return(INQUIT);
	}
	else
	{
		return(INNO);
	}

//#else
//#endif
}

bool inputSystem::processInput()	// processes all input
{
    
    renderEngine *render = renderEngine::Instance();

    keyPressed = "";  // resets value of keyPressed
//	Ogre::LogManager::getSingletonPtr()->logMessage("Processing input");

//	SDL_StartTextInput();
    // processes keyboard input
/*    if (processUnbufferedKeyInput() == false)
    {
        return false;
    }
//    SDL_StopTextInput();
*/

//    logMsg("sdl grab = " +Ogre::StringConverter::toString(SDL_GetWindowGrab(renderE->getSDLWindow())));
/*#ifndef __ANDROID__
    logMsg("input!");
    struct android_app *state = renderE->getApp();
//	state->onInputEvent = &handleInput;
    logMsg("input??");
	AInputEvent* event;
	struct android_poll_source* source;
    int ident;
    int fdesc;
    int events;

      while((ident = ALooper_pollAll(0, &fdesc, &events, (void**)&source)) >= 0)
      {
         // process this event

         if (source)
            source->process(state, source);
      }

#else
*/
//    SDL_PumpEvents();
    int motion = SDL_EventState(SDL_FINGERMOTION, SDL_QUERY);
	logMsg ("motion = " +Ogre::StringConverter::toString(motion));
//    exit(0);
    SDL_StartTextInput();
    while (SDL_PollEvent(&inputEvent))
    {
        
//        exit(0);
        int numTouch = SDL_GetNumTouchDevices();
        logMsg ("numTouch = " +Ogre::StringConverter::toString(numTouch));
        // exit(0);

//          Ogre::LogManager::getSingletonPtr()->logMessage("Crash??");

        switch (inputEvent.type)
        {
           /* case SDL_WINDOWEVENT:
                logMsg("windowevent!");
//                exit(0);
                break;*/
            case SDL_FINGERMOTION:
                logMsg("Motion!");
                exit(0);
                // processes touch input
                if (processUnbufferedTouchInput() == false)
                {
                    return false;
                }
                break;
            case SDL_FINGERDOWN:
                logMsg("Finger Down!");
                
                logMsg("tfinger.x = " +Ogre::StringConverter::toString(inputEvent.tfinger.x*render->getWindowWidth()));
                logMsg("tfinger.y = " +Ogre::StringConverter::toString(inputEvent.tfinger.y));
                
//                exit(0);
                // processes touch input
                if (processUnbufferedTouchInput() == false)
                {
                    return false;
                }
                break;
            case SDL_FINGERUP:
                logMsg("Finger Up!");
//                exit(0);
                // processes touch input
                if (processUnbufferedTouchInput() == false)
                {
                    return false;
                }
                break;
            case SDL_MULTIGESTURE:
                logMsg("Multigesture!");
            //    exit(0);
                // processes touch input
                if (processUnbufferedTouchInput() == false)
                {
                    return false;
                }
                break;
           
            case SDL_TEXTINPUT:
                keyPressed = "";
                if (processUnbufferedKeyInput(true) == false)
                {
                    return false;
                }
                logMsg("Key Pressed!");
                if (keyPressed != "")
                {
                //    exit(0);
                    inputMaps inputMap = keyMap();
                    internalInputWorkQueue.push_back(inputMap);
                }
          //      exit(0); 
                break;
                /*
            case SDL_KEYDOWN:
				logMsg("Keydown!");
                if (processUnbufferedKeyInput(false) == false)
                {
                    return false;
                }
                break;
                
            case SDL_KEYUP:
                keyPressed = "";
                break;
                */
            case SDL_MOUSEMOTION:
            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
            case SDL_MOUSEWHEEL:
				logMsg("Mouse!");
                // processes mouse input
                if (processUnbufferedMouseInput() == false)
                {
                    return false;
                }
               // exit(0);
                break;
            case SDL_CONTROLLERAXISMOTION:
            case SDL_CONTROLLERBUTTONDOWN:
            case SDL_CONTROLLERBUTTONUP:
            case SDL_CONTROLLERDEVICEADDED:
            case SDL_CONTROLLERDEVICEREMOVED:
            case SDL_CONTROLLERDEVICEREMAPPED:
				logMsg("Controller!");
                // processes gamepad input
                if (processUnbufferedGamepadInput() == false)
                {
                    return false;
                }
                exit(0);
               break;
            case SDL_QUIT:
                break;
            default:
                break;
        }

    }

    processUnbufferedMouseInput();
	return true;
}

bool inputSystem::processUnbufferedKeyInput(bool textInput)
{
	GUISystem *gui = GUISystem::Instance();
//	logMsg("Processing keyboard input");

	logMsg("key == " +Ogre::StringConverter::toString(inputEvent.key.keysym.sym));
    keyPressed = inputEvent.text.text;
    logMsg("key = " +keyPressed);

	if (gui->getMenuActive()) // checks if a menu is displayed
	{
        logMsg("keyPressed == " +keyPressed);
		gui->menuReceiveKeyPress(keyPressed); // sends input to menu key input processing function
	}
	else
	{
		return (true);
	}
/*
	if (MyGUI::InputManager::getInstance().isFocusKey())	// checks if a MyGUI widget has key focus
	{

		logMsg("Crash?");
//		exit(0);
		keyPressed = "";
        switch (inputEvent.key.keysym.sym)
        {
            case SDLK_RETURN:
//			case SDLK_AC_BACK:
				logMsg("Return!");
				exit(0);
                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Return, MyGUI::KeyCode::Return);

            break;
            case SDLK_BACKSPACE:
				logMsg("Backspace!");
				exit(0);
                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Backspace, 0);
            break;
            case SDLK_ESCAPE:
				logMsg("Escape!");
				exit(0);
                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Escape, 0);
            break;
            case SDLK_TAB:
				logMsg("Tab!");
				exit(0);
                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Tab, 0);
            break;
            case SDLK_SPACE:
				logMsg("Space!");
				exit(0);
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
				logMsg("Up!");
				exit(0);
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
*/
/*		if (SDL_PollEvent(&inputEvent))
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
        keyPressed = "";    // resets keyPressed so that we don't get repeats
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
        case SDLK_LALT:
            keyPressed = "leftAlt";
            break;
        case SDLK_RALT:
            keyPressed = "rightAlt";
            break;
        case SDLK_a:
            keyPressed = "a";
            break;
        case SDLK_d:
            keyPressed = "d";
            break;
        case SDLK_s:
            keyPressed = "s";
            break;
        case SDLK_w:
            keyPressed = "w";
            break;
        case SDLK_q:
            keyPressed = "q";
            break;
        default:
            keyPressed = "";
            break;
        }
*/
/*		if (SDL_PollEvent(&inputEvent))
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
				case SDLK_LALT:
					keyPressed = "leftAlt";
					break;
				case SDLK_RALT:
					keyPressed = "rightAlt";
					break;
				case SDLK_a:
					keyPressed = "a";
					break;
				case SDLK_d:
					keyPressed = "d";
					break;
				case SDLK_s:
					keyPressed = "s";
					break;
				case SDLK_w:
					keyPressed = "w";
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
	*/
//	logMsg("Keyboard Input Processed");
    // Return true to continue rendering
    return true;

}

bool inputSystem::processUnbufferedMouseInput()
{
	renderEngine *render = renderEngine::Instance();

	int x, y;
	int state = -1;
	SDL_MouseMotionEvent motion;

	SDL_PumpEvents();
	SDL_GetMouseState(&x,&y);

//	logMsg("Processing mouse input");

    //FIXME Need to get MyGUI working on android
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//#else
    int w, h;
    //SDL_Window *sdlWindow = SDL_GetMouseFocus();
	SDL_Window *sdlWindow = render->getSDLWindow();
	
    SDL_GetWindowMaximumSize(sdlWindow,&w,&h);
	logMsg("sdlWindow width = " +Ogre::StringConverter::toString(w));
	logMsg("sdlWindow height = " +Ogre::StringConverter::toString(h));
    //SDL_GetGlobalMouseState(&x, &y);
	logMsg("mouse x = " +Ogre::StringConverter::toString(x));
	logMsg("mouse y = " +Ogre::StringConverter::toString(y));

//	state = SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(0);
    state = SDL_GetMouseState(NULL, NULL)&SDL_TOUCH_MOUSEID;
    logMsg("Mouse state = " +Ogre::StringConverter::toString(state));
//	std::cout << "Mouse State = " << state << std::endl;
    if (state == 1)
	{
//	    exit(0);
	}
	if (MyGUI::InputManager::getInstance().isFocusMouse())
	{
//		exit(0);
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


    logMsg("Mouse x = " +Ogre::StringConverter::toString(x) + " y = " +Ogre::StringConverter::toString(y));
//    Ogre::LogManager::getSingletonPtr()->logMessage("Mouse X = "  +toString(x));
	if (mouseX != x || mouseY != y)
	{
		MyGUI::InputManager::getInstance().injectMouseMove(x,y,0);
	}
//#endif
//    logMsg("Mouse input processed");
    return true;
}

bool inputSystem::processUnbufferedTouchInput() // reads in unbuffered touch input
{
	renderEngine *render = renderEngine::Instance();

	int state = -1;
	SDL_TouchFingerEvent touchMotion;
	//SDL_Event evt;

//    SDL_SetWindowGrab(renderE->getSDLWindow(), SDL_TRUE);
//	logMsg("sdl grab = " +Ogre::StringConverter::toString(SDL_GetWindowGrab(renderE->getSDLWindow())));
	SDL_PumpEvents();
	int numDevs = SDL_GetNumTouchDevices();
	logMsg("numTouchDevices = " +Ogre::StringConverter::toString(numDevs));

    int evtState = 0;
    evtState = SDL_EventState(SDL_FINGERMOTION, SDL_QUERY);
    logMsg("evtState FINGERMOTION = " +Ogre::StringConverter::toString(evtState));
    evtState = 0;
    evtState = SDL_EventState(SDL_FINGERDOWN, SDL_QUERY);
    logMsg("evtState FINGERDOWN = " +Ogre::StringConverter::toString(evtState));
    SDL_Finger *finger = SDL_GetTouchFinger(0,0);
	logMsg("Finger = " +Ogre::StringConverter::toString(finger));

    evtState = 0;
    evtState = SDL_EventState(SDL_FINGERUP, SDL_QUERY);
    if (evtState > 0)
    {
        logMsg("evtState FINGERUP = " +Ogre::StringConverter::toString(evtState));
    //    exit(0);
    }
    int x = inputEvent.tfinger.x*render->getWindowWidth();
    int y = inputEvent.tfinger.y*render->getWindowHeight();
//    if (MyGUI::InputManager::getInstance().isFocusMouse())
//    {
//      exit(0);
//      std::cout << "focused" << std::endl;
        if(SDL_EventState(SDL_FINGERDOWN, SDL_QUERY) == 1)
        {
            mouseLeftClick = 1;
//            exit(0);
             MyGUI::InputManager::getInstance().injectMousePress(x, y, MyGUI::MouseButton::Enum(0));

    //      exit(0);
        }
        if (SDL_EventState(SDL_FINGERUP, SDL_QUERY) == 1) //if (SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1) == 0)
        {
//            exit(0);
            mouseLeftClick = 0;
             MyGUI::InputManager::getInstance().injectMouseRelease(x, y, MyGUI::MouseButton::Enum(0));

        }
        
//    }
    //	SDL_GetWindowSize(
/*    while (SDL_PollEvent(&inputEvent) > 0)
    {
	    switch (inputEvent.type)
		{
			case SDL_FINGERMOTION:
				logMsg("Motion!");
				exit(0);
				break;
			case SDL_FINGERDOWN:
				logMsg("Finger Down!");
				exit(0);
				break;
            case SDL_FINGERUP:
			    logMsg("Finger Up!");
				exit(0);
				break;
			case SDL_MULTIGESTURE:
				logMsg("Multigesture!");
				exit(0);
				break;
			case SDL_KEYDOWN:
				logMsg("Keydown!");
				exit(0);
				break;
			case SDL_MOUSEBUTTONDOWN:
				logMsg("MouseButtondown!");
				exit(0);
				break;
			case SDL_MOUSEMOTION:
				logMsg("MouseMotion!");
				exit(0);
				break;
			case SDL_MOUSEWHEEL:
				logMsg("MouseWheel!");
				exit(0);
				break;
			case SDL_JOYAXISMOTION:
			case SDL_JOYBALLMOTION:
			case SDL_JOYHATMOTION:
			case SDL_JOYBUTTONDOWN:
			case SDL_JOYBUTTONUP:
			    logMsg("Joystick!");
				exit(0);
				break;
			case SDL_WINDOWEVENT:
				logMsg("Window!");
				exit(0);
				break;
			default:
			break;
		}
    }
*/
//	state =

	return true;
}

bool inputSystem::processUnbufferedGamepadInput() // reads in unbuffered mouse input
{
	return true;
}
