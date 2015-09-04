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

#include "comparison.h"

comparison::comparison()
{
    
}

Ogre::Vector3 comparison::OgreVector3ToOgreVector3(Ogre::Vector3 currentValue,Ogre::Vector3 newValue)  // compares two Ogre::Vector3 objects and returns their differences
{
    Ogre::Vector3 change = Ogre::Vector3(0,0,0);
    
    if (currentValue.x > 0)
    {
        if (newValue.x >= 0)
        {
            if (newValue.x > currentValue.x)
            {
                change.x = newValue.x - currentValue.x;
            }
            else if (newValue.x < currentValue.x)
            {
                change.x = currentValue.x - newValue.x;
            }
            else
            {
                
            }
        }
        else if (newValue.x < 0)
        {
            change.x = currentValue.x + newValue.x;
        }
    }
    else if (currentValue.x < 0)
    {
        if (newValue.x >= 0)
        {
            change = currentValue.x + newValue.x;
        }
        else if (newValue.x < 0)
        {
            if (newValue.x > currentValue.x)
            {
                change.x = currentValue.x - newValue.x;
            }
            else if (newValue.x < currentValue.x)
            {
                change.x = newValue.x - currentValue.x;
            }
        }
        else
        {
            
        }
    }
    else if (currentValue.x == 0)
    {
        if (newValue.x >= 0)
        {
            change = newValue.x - currentValue.x;
        }
        else if (newValue.x < 0)
        {
            change = currentValue.x - newValue.x;
        }
    }
    else
    {
        
    }
    
    return (change);
}
