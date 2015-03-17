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

#ifndef _USERINPUT_H_
#define _USERINPUT_H_

#include <string>

class userInput
{
    public:
    
        std::string getKeyUp();  // retrieves the value of keyUp
        void setKeyUp(std::string set);  // sets the value of keyUp

        std::string getKeyDown();  // retrieves the value of keyDown
        void setKeyDown(std::string set);  // sets the value of keyDown
        
        std::string getKeyLeft();  // retrieves the value of keyLeft
        void setKeyLeft(std::string set);  // sets the value of keyLeft

        std::string getKeyRight();  // retrieves the value of keyRight
        void setKeyRight(std::string set);  // sets the value of keyRight

        std::string getKeyUpLeft();  // retrieves the value of keyUpLeft
        void setKeyUpLeft(std::string set);  // sets the value of keyUpLeft

        std::string getKeyUpRight();  // retrieves the value of keyUpRight
        void setKeyUpRight(std::string set);  // sets the value of keyUpRight

        std::string getKeyDownLeft();  // retrieves the value of keyDownLeft
        void setKeyDownLeft(std::string set);  // sets the value of keyDownLeft

        std::string getKeyDownRight();  // retrieves the value of keyDownRight
        void setKeyDownRight(std::string set);  // sets the value of keyRight

    private:
    
    // key input strings
    std::string keyUp;
    std::string keyDown;
    std::string keyLeft;
    std::string keyRight;
    std::string keyUpLeft;
    std::string keyUpRight;
    std::string keyDownLeft;
    std::string keyDownRight;
    std::string keyShootBlock;
    std::string keyPassSteal;
};

#endif
