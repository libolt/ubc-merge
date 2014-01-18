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

#ifndef _ENUMS_H_
#define _ENUMS_H_

    enum directions { UP, DOWN, LEFT, RIGHT, UPLEFT, UPRIGHT, DOWNLEFT, DOWNRIGHT };	// direction objects are moving
    enum gameTypes { SINGLE, MULTI }; // defines whether a game is single or multi player
    enum quarters { FIRST, SECOND, THIRD, FOURTH }; // defines the quarters within the game
    enum defenseTypes { MANTOMAN, FULLCOURT, HALFCOURT, ZONE };	// type of defense being played
    enum offenseTypes { BOX, PICKANDROLL, MOTION, ISOLATION };	// type of offense being played
    enum courtSide_t {RIGHTSIDE, LEFTSIDE};	// stores which side of the court the offensive team is on

     // Physics bit masks
    #define BIT(x) (1<<(x))

    enum collisiontypes
    {
        COL_NOTHING = 0, //<Collide with nothing
        COL_COURT = BIT(0), // Collide with court
        COL_TEAM1 = BIT(1), //<Collide with teammate
        COL_TEAM2 = BIT(2), //<Collide with walls
        COL_POWERUP = BIT(3) //<Collide with powerups
    };

#endif /* ENUMS_H_ */
