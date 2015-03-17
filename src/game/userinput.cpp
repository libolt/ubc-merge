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

#include "userinput.h"

    std::string userInput::getKeyUp()  // retrieves the value of keyUp
    {
        return (keyUp);
    }
    void userInput::setKeyUp(std::string set)  // sets the value of keyUp
    {
        keyUp = set;
    }
    
    std::string userInput::getKeyDown()  // retrieves the value of keyDown
    {
        return (keyDown);
    }
    void userInput::setKeyDown(std::string set)  // sets the value of keyDown
    {
        keyDown = set;
    }
    std::string userInput::getKeyLeft()  // retrieves the value of keyLeft
    {
        return (keyLeft);
    }
    void userInput::setKeyLeft(std::string set)  // sets the value of keyLeft
    {
        keyLeft = set;
    }
    
    std::string userInput::getKeyRight()  // retrieves the value of keyRight
    {
        return (keyRight);
    }
    void userInput::setKeyRight(std::string set)  // sets the value of keyRight
    {
        keyRight = set;
    }
    
    std::string userInput::getKeyUpLeft()  // retrieves the value of keyUpLeft
    {
        return (keyUpLeft);
    }
    void userInput::setKeyUpLeft(std::string set)  // sets the value of keyUpLeft
    {
        keyUpLeft = set;
    }
    
    std::string userInput::getKeyUpRight()  // retrieves the value of keyUpRight
    {
        return (keyUpRight);
    }
    void userInput::setKeyUpRight(std::string set)  // sets the value of keyUpRight
    {
        keyUpRight = set;
    }
    
    std::string userInput::getKeyDownLeft()  // retrieves the value of keyDownLeft
    {
        return (keyDownLeft);
    }
    void userInput::setKeyDownLeft(std::string set)  // sets the value of keyDownLeft
    {
        keyDownLeft = set;
    } 
    
    std::string userInput::getKeyDownRight()  // retrieves the value of keyDownRight
    {
        return (keyDownRight); 
    }
    void userInput::setKeyDownRight(std::string set)  // sets the value of keyRight
    {
        keyDownRight = set;
    }
    

