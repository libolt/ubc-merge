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

#include "SDL.h"
#include "SDL_syswm.h"
#include "Ogre.h"
#include <boost/thread/thread.hpp>
#include <boost/date_time.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/thread/locks.hpp>

#include "enums.h"
#include "userinput.h"

#define EVENT_BUF_SIZE 256

typedef std::vector<inputMaps>   inputWorkQueues;

// input class
class inputSystem
{
public:

    //static inputSystem *Instance();
    static boost::shared_ptr<inputSystem> Instance();


    bool setup();   // sets up and initializes the  Input System
    bool destroy(); // destroys the Input system and related objects

    inputMaps keyMap();  // maps value of keyPressed string to inputMap
	
    bool processInput();	// processes all input
    bool processUnbufferedKeyInput(bool textInput);	// reads in unbuffered key presses
    bool processUnbufferedMouseInput();	// reads in unbuffered mouse input
    bool processUnbufferedTouchInput(); // reads in unbuffered touch input
    bool processUnbufferedGamepadInput(); // reads in unbuffered mouse input
	
    // SDL Input functions
    SDL_Event getInputEvent();   // retrieves the value of the inputEvent variable
    void setInputEvent(SDL_Event input); // sets the value of the inputEvent variable

    std::string getKeyPressed(); // retrieves the value of the keyPressed pressed variable
    void setKeyPressed(std::string key); // sets the value of the keyPressed variable

    inputMaps getInputMap();  // retrieves the value of the inputMap variable
    void setInputMap(inputMaps map);  // sets the value of the inputMap variable

    inputWorkQueues getInputWorkQueue();  // retrieves the value of inputWorkQueue
    void setInputWorkQueue(inputWorkQueues set);  // sets the value of inputWorkQueue
    
    std::vector<userInput> getUInput();  // retrieves the value of uInput
    void setUInput(std::vector<userInput> set);  // sets the value of uInput
    
protected:
    inputSystem();
    inputSystem(const inputSystem&);
    inputSystem& operator= (const inputSystem&);

    //~inputSystem();
    // SDL Input
    SDL_Event inputEvent;
    SDL_Event events[EVENT_BUF_SIZE];
    int eventWrite;

    int mouseX; // stores the X coordinate of the mouse.
    int mouseY; // stores the Y coordinate of the mouse.
    int mouseLeftClick;	// stores state of Left mouse button
    int mouseRightClick; // stores state of Right mouse button;

private:
    //static inputSystem *pInstance;
    static boost::shared_ptr<inputSystem> pInstance;


    std::string keyPressed; // stores which key was pressed

    inputMaps inputMap; // stores user input
 
    std::vector<userInput> uInput;  // stores user input mapping
 
    inputWorkQueues inputWorkQueue;
    inputWorkQueues internalInputWorkQueue;
    boost::mutex inputWorkQueueMutex;
};


#endif

