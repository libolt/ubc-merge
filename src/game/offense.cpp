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

#include "offense.h"

offenses::offenses()
{
    playerStartPos = new float[5];

    for (int i = 0; i < 5; i++)
    {
        playerStartPos[i] = 0.0f;
    }


}

offenses::~offenses()
{
}

float *offenses::getPlayerStartPos(void) // retrieves playerStartPos value
{
    return(playerStartPos);
}
void offenses::setPlayerStartPos(float *startPos)    // sets playerStartPos value
{
    playerStartPos = startPos;
}

bool offenses::getPlayerStartPosSet(void)    // retrieves playerStartPosSet value
{
    return(playerStartPosSet);
}
void offenses::setPlayerStartPosSet(bool set)    // sets playerStartPosSet value
{
    playerStartPosSet = set;
}

bool offenses::getPgStartPosSet(void)    // retrieves pgStartPosSet value
{
    return(pgStartPosSet);
}
void offenses::setPgStartPosSet(bool set)    // sets pgStartPosSet value
{
    pgStartPosSet = set;
}

bool offenses::getSgStartPosSet(void)    // retrieves sgStartPosSet value
{
    return(sgStartPosSet);
}
void offenses::setSgStartPosSet(bool set)    // sets sgStartPosSet value
{
    sgStartPosSet = set;
}

bool offenses::getSfStartPosSet(void)    // retrieves sfStartPosSet value
{
    return(sfStartPosSet);
}
void offenses::setSfStartPosSet(bool set)    // sets sfStartPosSet value
{
    sfStartPosSet = set;
}

bool offenses::getPfStartPosSet(void)    // retrieves pfStartPosSet value
{
    return(pfStartPosSet);
}
void offenses::setPfStartPosSet(bool set)    // sets pfStartPosSet value
{
    pfStartPosSet = set;
}

bool offenses::getCStartPosSet(void)    // retrieves cStartPosSet value
{
    return(cStartPosSet);
}
void offenses::setCStartPosSet(bool set)    // sets cStartPosSet value
{
    cStartPosSet = set;
}

int offenses::execute(void)   // executes selected offense
{
    return(0);
}

int offenses::pgExecute(void)
{
    return(0);
}

int offenses::sgExecute(void)
{
    return(0);
}

int offenses::sfExecute(void)
{
    return(0);
}

int offenses::pfExecute(void)
{
    return(0);
}

int offenses::cExecute(void)
{
    return(0);
}

int offenses::checkPlayerPosition(void)
{
    return(0);
}
