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

#ifndef _PLAYERSTEER_H_
#define _PLAYERSTEER_H_

#include "steering.h"

class playerSteer : public steering
{
    public:

//	playerSteer(std::vector<playerSteer*> others, std::vector<playerSteer*> allplayers, /*Ball* ball,*/ bool isTeamA, int id);
	playerSteer()
    {
	    std::vector<playerSteer*> others;
	    std::vector<playerSteer*> allplayers;
	    bool isTeamA;
	    int id;
	    m_others = others;
	    m_AllPlayers = allplayers;
	    //m_Ball(ball),
	    b_ImTeamA = isTeamA; 
        m_MyID = id;

//    b_ImTeamA = true;
	    ID = -1;
	    counter = 0;
//	steering::reset (); // reset the vehicle
	    reset();
		setPosition(OpenSteer::Vec3(0,0,0));
		
	/*    setSpeed (0.0f);         // speed along Forward direction.
    setMaxForce (3000.7f);      // steering force is clipped to this magnitude
    setMaxSpeed (10);         // velocity is clipped to this magnitude
    setRadius(1.0f);
    setMass(1.0f);
*/
    }
	~playerSteer();

	int getID(); // retrieves the value of ID
	void setID(int id); // sets the value of ID

	void reset(void); // resets the state
	void update (const float currentTime, const float elapsedTime); // update steering sim every frame

	private:
	int counter;
    std::vector<playerSteer*>	m_others;
    std::vector<playerSteer*>	m_AllPlayers;
    //Ball*	m_Ball;
    bool	b_ImTeamA;
    int		m_MyID;
	int ID; // Stores which player on the team the instance associates with
};

#endif
