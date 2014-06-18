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

	enum inputMaps { INNO, INUP, INDOWN, INLEFT, INRIGHT, INUPLEFT, INUPRIGHT, INDOWNLEFT, INDOWNRIGHT, INSHOOTBLOCK, INPASSSTEAL, INQUIT }; // map of human player input
	enum directions { UP, DOWN, LEFT, RIGHT, UPLEFT, UPRIGHT, DOWNLEFT, DOWNRIGHT };	// direction objects are moving
	enum gameTypes { NOGAME, SINGLE, MULTI }; // defines whether a game is single or multi player
	enum quarters { FIRST, SECOND, THIRD, FOURTH }; // defines the quarters within the game
	enum courtSide_t {RIGHTSIDE, LEFTSIDE};	// defines which side of the court the offensive team is on

	enum directiveTypes { WAIT, FREELANCE}; // defines the type of directive a player has
    enum offenseWaitFor { PLAYERPOSITIONSET, TIME }; // defines what an offensive player is waiting for

	// Physics bit masks
	#define BIT(x) (1<<(x))

    enum collisiontypes
    {
        COL_NOTHING = 0, //<Collide with nothing
        COL_COURT = BIT(0), // Collide with court
        COL_BBALL = BIT(1), // Collide with basketball
        COL_PLAYER0 = BIT(2), // Collides with player 0
        COL_PLAYER1 = BIT(3), // Collides with player 1
        COL_PLAYER2 = BIT(4), // Collides with player 2
        COL_PLAYER3 = BIT(5), // Collides with player 3
        COL_PLAYER4 = BIT(6), // Collides with player 4
        COL_PLAYER5 = BIT(7), // Collides with player 5
        COL_PLAYER6 = BIT(8), // Collides with player 6
        COL_PLAYER7 = BIT(9), // Collides with player 7
        COL_PLAYER8 = BIT(10), // Collides with player 8
        COL_PLAYER9 = BIT(11), // Collides with player 9
        COL_TEAM1 = COL_PLAYER0 | COL_PLAYER1 | COL_PLAYER2 | COL_PLAYER3 | COL_PLAYER4, //<Collide with team1
        COL_TEAM2 = COL_PLAYER5 | COL_PLAYER6 | COL_PLAYER7 | COL_PLAYER8 | COL_PLAYER9  //<Collide with team2

    };

#endif /* ENUMS_H_ */
