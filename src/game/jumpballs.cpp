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

#include "jumpballs.h"

jumpballs::jumpballs()
{
    tipOffComplete = false;
    ballTipped = false;
    ballTippedToTeam = NOTEAM;
    ballTippedToPlayerID = -1;
    ballTippedToPosition = NONE;
    ballTipForceApplied = false;
}

jumpBallLocations_t jumpBalls::getJumpBallLocation()  // retrieves teh value of jumpBallLocation
{
    return (jumpBallLocation);
}
void jumpBalls::setJumpBallLocation(jumpBallLocations_t set)  // sets the value of jumpBallLocation
{
    jumpBallLocation = set;
}

std::vector<playerPositions> jumpBalls::getJumpBallPlayer()  // retrieves the value of jumpBallPlayer
{
    return (jumpBallPlayer);
}
void jumpBalls::setJumpBallPlayer(std::vector<playerPositions> set)  // sets the value of jumpBallPlayer
{
    jumpBallPlayer = set;
}

void jumpBalls::executeJumpBall()  // handles jump ball from any of the jump ball locations.
{

}
