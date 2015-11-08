/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean   *
 *   libolt@libolt.net   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCH.ANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
 
// Input
#include "conversion.h"

#undef None
#undef Button1
#undef Button2
#undef Button3
#undef Button4
#undef Button5
#undef Button6
#undef Button7
#include "MyGUI.h"
#include "MyGUI_OgrePlatform.h"


#include "input.h"
#include "gameengine.h"
#include "gamestate.h"
#include "gui.h"
#include "load.h"
#include "logging.h"
#include "renderengine.h"

//static int32_t handleInput(struct android_app* app, AInputEvent* event);


//inputSystem* inputSystem::pInstance = 0;
boost::shared_ptr<inputSystem> inputSystem::pInstance;

//inputSystem* inputSystem::Instance()
boost::shared_ptr<inputSystem> inputSystem::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        //pInstance = new inputSystem; // create sole instance
        boost::shared_ptr<inputSystem> tInstance(new inputSystem);
        pInstance = tInstance;
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

/*inputSystem::~inputSystem()
{
}
*/
SDL_Event inputSystem::getInputEvent()
{
	return (inputEvent);
}

void inputSystem::setInputEvent(SDL_Event input)
{
	inputEvent = input;
}


std::string inputSystem::getKeyPressed() // retrieves keyPressed
{
	return(keyPressed);
}

void inputSystem::setKeyPressed(std::string key)
{
	keyPressed = key;
}

inputMaps inputSystem::getInputMap()  // retrieves the value of the inputMap variable
{
	return(inputMap);
}
void inputSystem::setInputMap(inputMaps map)  // sets the value of the inputMap variable
{
	inputMap = map;
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
//    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
//              mDebugOverlay = OverlayManager::getSingleton().getByName("Core/DebugOverlay");

    boost::shared_ptr<loader> load = loader::Instance();

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
        logMsg("keyQuit = " +uInput[0].getKeyQuit());
		return(INQUIT);
	}
    else if (keyPressed == "Backspace")
    {
//        logMsg("keyQuit = " +uInput[0].getKeyQuit());
//        exit(0);
        return(INBACKSPACE);
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
    
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();

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

//    logMsg("sdl grab = " +convert->toString(SDL_GetWindowGrab(render->getSDLWindow())));
/*#ifndef __ANDROID__
    logMsg("input!");
    struct android_app *state = render->getApp();
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
    logMsg ("motion = " +convert->toString(motion));
//    exit(0);
    SDL_StartTextInput();
    while (SDL_PollEvent(&inputEvent))
    {
        
//        exit(0);
        int numTouch = SDL_GetNumTouchDevices();
        logMsg ("numTouch = " +convert->toString(numTouch));
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
                //exit(0);
                // processes touch input
                if (processUnbufferedTouchInput() == false)
                {
                    return false;
                }
                break;
            case SDL_FINGERDOWN:
                logMsg("Finger Down!");
                
                logMsg("tfinger.x = " +convert->toString(inputEvent.tfinger.x*render->getWindowWidth()));
                logMsg("tfinger.y = " +convert->toString(inputEvent.tfinger.y));
                
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
            case SDL_KEYDOWN:
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
                    inputWorkQueue.push_back(inputMap);
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
                //exit(0);
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
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //GUISystem *gui = GUISystem::Instance();
    boost::shared_ptr<GUISystem> gui = GUISystem::Instance();
//	logMsg("Processing keyboard input");

    logMsg("key == " +convert->toString(inputEvent.key.keysym.sym));
    keyPressed = inputEvent.text.text;
    logMsg("key = " +keyPressed);

	if (MyGUI::InputManager::getInstance().isFocusKey())	// checks if a MyGUI widget has key focus
	{

		logMsg("Crash?");
//		exit(0);
//        keyPressed = "";
        switch (inputEvent.key.keysym.sym)
        {
            
            case SDLK_RETURN:
//			case SDLK_AC_BACK:
				logMsg("Return!");
				keyPressed = "Return";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Return, MyGUI::KeyCode::Return);

            break;
            case SDLK_BACKSPACE:
				logMsg("Backspace!");
//				exit(0);
                keyPressed = "Backspace";
//                gui->menuReceiveKeyPress(keyPressed); // sends input to menu key input processing function

//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Backspace, 0);
            break;
            case SDLK_ESCAPE:
				logMsg("Escape!");
                keyPressed = "Escape";
//				exit(0);
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Escape, 0);
            break;
            case SDLK_TAB:
				logMsg("Tab!");
                keyPressed = "Tab";
//				exit(0);
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Tab, 0);
            break;
            case SDLK_SPACE:
				logMsg("Space!");
                keyPressed = "Space";
//				MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Space, ' ');
            break;
            case SDLK_LSHIFT:
                keyPressed = "LeftShift";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::LeftShift, 0);
            break;
            case SDLK_LCTRL:
                keyPressed = "LeftControl";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::LeftControl, 0);
            break;
            case SDLK_LALT:
                keyPressed = "LeftAlt";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::LeftAlt, 0);
            break;
            case SDLK_LGUI:
                keyPressed = "LeftGUI";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::LeftWindows, 0);
            break;
            case SDLK_RSHIFT:
                keyPressed = "RightShift";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightShift, 0);
            break;
            case SDLK_RCTRL:
                keyPressed = "RightControl";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightControl, 0);
            break;
            case SDLK_RALT:
                keyPressed = "RightAlt";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightAlt, 0);
            break;
            case SDLK_RGUI:
                keyPressed = "RightGUI";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightWindows, 0);
            break;
            case SDLK_MENU:
                keyPressed = "Menu";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::RightWindow, 0);
            break;
            case SDLK_CAPSLOCK:
                keyPressed = "CapsLock";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Capital, 0);
            break;
            case SDLK_F1:
                keyPressed = "F1";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F1, 0);
            break;
            case SDLK_F2:
                keyPressed = "F2";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F2, 0);
            break;
            case SDLK_F3:
                keyPressed = "F3";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F3, 0);
            break;
            case SDLK_F4:
                keyPressed = "F4";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F4, 0);
            break;
            case SDLK_F5:
                keyPressed = "F5";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F5, 0);
            break;
            case SDLK_F6:
                keyPressed = "F6";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F6, 0);
            break;
            case SDLK_F7:
                keyPressed = "F7";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F7, 0);
            break;
            case SDLK_F8:
                keyPressed = "F8";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F8, 0);
            break;
            case SDLK_F9:
                keyPressed = "F9";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F9, 0);
            break;
            case SDLK_F10:
                keyPressed = "F10";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F10, 0);
            break;
            case SDLK_F11:
                keyPressed = "F11";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F11, 0);
            break;
            case SDLK_F12:
                keyPressed = "F12";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::F12, 0);
            break;
            case SDLK_UP:
                keyPressed = "Up";
//				logMsg("Up!");
//              MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ArrowUp, 0);
            break;
            case SDLK_DOWN:
                keyPressed = "Down";
//                 MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ArrowDown, 0);
            break;
            case SDLK_LEFT:
                keyPressed = "Left";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ArrowLeft, 0);
            break;
            case SDLK_RIGHT:
                keyPressed = "Right";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ArrowRight, 0);
            break;
            case SDLK_SCROLLLOCK:
                keyPressed = "ScrollLock";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::ScrollLock, 0);
            break;
            case SDLK_HOME:
                keyPressed = "Home";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Home, 0);
            break;
            case SDLK_PAUSE:
                keyPressed = "Pause";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Pause, 0);
            break;
            case SDLK_INSERT:
                keyPressed = "Insert";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Insert, 0);
            break;
            case SDLK_PAGEUP:
                keyPressed = "PageUp";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::PageUp, 0);
            break;
            case SDLK_DELETE:
                keyPressed = "Delete";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Delete, 0);
            break;
            case SDLK_END:
                keyPressed = "End";
//            MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::End, 0);
            break;
            case SDLK_PAGEDOWN:
                keyPressed = "PageDown";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::PageDown, 0);
            break;
            case SDLK_NUMLOCKCLEAR:
                keyPressed = "NumLockClear";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::NumLock, 0);
            break;
            case SDLK_KP_DIVIDE:
                keyPressed = "Divide";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Divide, 0);
            break;
            case SDLK_KP_MULTIPLY:
                keyPressed = "Multiply";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Multiply, 0);
            break;
            case SDLK_KP_MINUS:
                keyPressed = "Minud";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Minus, 0);
            break;
            case SDLK_KP_ENTER:
                keyPressed = "Enter";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::NumpadEnter, 0);
            break;
            case SDLK_KP_0:
                keyPressed = "0";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad0, '0');
            break;
            case SDLK_KP_1:
                keyPressed = "1";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad1, '1');
            break;
            case SDLK_KP_2:
                keyPressed = "2";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad2, '2');
            break;
            case SDLK_KP_3:
                keyPressed = "3";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad3, '3');
            break;
            case SDLK_KP_4:
                keyPressed = "4";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad4, '4');
            break;
            case SDLK_KP_5:
                keyPressed = "5";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad5, '5');
            break;
            case SDLK_KP_6:
                keyPressed = "6";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad6, '6');
            break;
            case SDLK_KP_7:
                keyPressed = "7";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad7, '7');
            break;
            case SDLK_KP_8:
                keyPressed = "8";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad8, '8');
            break;
            case SDLK_KP_9:
                keyPressed = "9";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Numpad9, '9');
            break;
            case SDLK_6:
                keyPressed = "";
//                MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Enum(6), '6');
            break;
            default:
            //    MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Enum(inputEvent.key.keysym.sym), inputEvent.key.keysym.sym);
            break;
            
        }
    }
    if (gui->getMenuActive()) // checks if a menu is displayed
    {
        logMsg("keyPressed == " +keyPressed);
        gui->menuReceiveKeyPress(keyPressed); // sends input to menu key input processing function
//        exit(0);
    }
    else
    {
        return (true);
	}

    keyPressed = "";
//	logMsg("Keyboard Input Processed");
    // Return true to continue rendering
    return true;

}

bool inputSystem::processUnbufferedMouseInput()
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();

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
    logMsg("sdlWindow width = " +convert->toString(w));
    logMsg("sdlWindow height = " +convert->toString(h));
    //SDL_GetGlobalMouseState(&x, &y);
    logMsg("mouse x = " +convert->toString(x));
    logMsg("mouse y = " +convert->toString(y));

//	state = SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(0);
    state = SDL_GetMouseState(NULL, NULL)&SDL_TOUCH_MOUSEID;
    logMsg("Mouse state = " +convert->toString(state));
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


    logMsg("Mouse x = " +convert->toString(x) + " y = " +convert->toString(y));
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
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();

	int state = -1;
	SDL_TouchFingerEvent touchMotion;
	//SDL_Event evt;

//    SDL_SetWindowGrab(render->getSDLWindow(), SDL_TRUE);
//	logMsg("sdl grab = " +convert->toString(SDL_GetWindowGrab(render->getSDLWindow())));
	SDL_PumpEvents();
	int numDevs = SDL_GetNumTouchDevices();
    logMsg("numTouchDevices = " +convert->toString(numDevs));

    int evtState = 0;
    evtState = SDL_EventState(SDL_FINGERMOTION, SDL_QUERY);
    logMsg("evtState FINGERMOTION = " +convert->toString(evtState));
    evtState = 0;
    evtState = SDL_EventState(SDL_FINGERDOWN, SDL_QUERY);
    logMsg("evtState FINGERDOWN = " +convert->toString(evtState));
    SDL_Finger *finger = SDL_GetTouchFinger(0,0);
//    logMsg("Finger = " +convert->toString(finger));

    evtState = 0;
    evtState = SDL_EventState(SDL_FINGERUP, SDL_QUERY);
    if (evtState > 0)
    {
        logMsg("evtState FINGERUP = " +convert->toString(evtState));
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
