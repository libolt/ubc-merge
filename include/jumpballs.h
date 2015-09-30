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

#ifndef _JUMPBALLS_H_
#define _JUMPBALLS_H_

class jumpBalls
{
    public:

    jumpBalls();  // constructor

    jumpBallLocations_t getJumpBallLocation();  // retrieves teh value of jumpBallLocation
    void setJumpBallLocation(jumpBallLocations_t set);  // sets the value of jumpBallLocation

    std::vector<playerPositions> getJumpBallPlayer();  // retrieves the value of jumpBallPlayer
    void setJumpBallPlayer(std::vector<playerPositions> set);  // sets the value of jumpBallPlayer

    bool getTipOffComplete();  // retrieves tipOffComplete value
    void setTipOffComplete(bool complete);	// sets tipOffComplete value

    bool getBallTipped();  // retrieves the value of the ballTipped
    void setBallTipped(bool tipped);  // sets the value of the ballTipped

    teamTypes getBallTippedToTeam();  // retrieves the value of the ballTippedToTeam
    void setBallTippedToTeam(teamTypes set);	 // sets the value of the ballTippedToTeam

    int getBallTippedToPlayerID();  // retrieves the value of the ballTippedToPlayerID
    void setBallTippedToPlayerID(int player);  // sets the value of the ballTippedToPlayerID

    playerPositions getBallTippedToPosition();  // retrieves the value of ballTippedToPosition
    void setBallTippedToPosition(playerPositions set);  // sets the value of ballTippedToPosition

    bool getBallTipForceApplied();  // retrieves the value of ballTipForceApplied
    void setBallTipForceApplied(bool tip);  // sets the value of ballTipForceApplied

    void executeJumpBall();  // handles jump ball from any of the jump ball locations.


    private:

    // Tip Off and jump balls
    jumpBallLocations_t jumpBallLocation;  // sets where the jump ball is to be held
    std::vector<playerPositions> jumpBallPlayer;  // stores which two players will be jumping for the ball
    bool tipOffComplete;  // Determines whether or not game Tip Off has completed
    bool ballTipped;  //	stores whether or not the ball has been tipped
    bool ballTipForceApplied;// stores whether or not force has been applied to tipped ball
    bool playerHasBasketball;  // stores whether or not a player has control of the basketball
    teamTypes ballTippedToTeam;  //  stores which team the ball has been tipped to
    int ballTippedToPlayerID;  // stores which player ID the ball has been tipped to
    playerPositions ballTippedToPosition;  // stores position that the ball is tipped to


};

#endif // _JUMPBALLS_H_
