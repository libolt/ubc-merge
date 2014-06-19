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
//	    bool isTeamA;
	    int id;
	    m_others = others;
	    m_AllPlayers = allplayers;
	    //m_Ball(ball),
//	    b_ImTeamA = isTeamA;
        m_MyID = id;

//    b_ImTeamA = true;
		teamNumber = -1;
	    ID = -1;
	    counter = 0;
		distToPosition = 0.0f;
		
	    m_home = OpenSteer::Vec3::zero;
//	steering::reset (); // reset the vehicle
	    reset();
		setPosition(OpenSteer::Vec3(0,0,0));
		setRadius (0.5f);
		setMass(10.0f);
	/*    setSpeed (0.0f);         // speed along Forward direction.
    setMaxForce (3000.7f);      // steering force is clipped to this magnitude
    setMaxSpeed (10);         // velocity is clipped to this magnitude
    setRadius(1.0f);
    setMass(1.0f);
*/
    }
	~playerSteer();

	int getTeamNumber(); // retrieves the value of team
	void setTeamNumber(int team); // sets the value of team

	int getID(); // retrieves the value of ID
	void setID(int id); // sets the value of ID

	float getDistToPosition(); // retrieves the value of distToPosition
	void setDistToPosition(float dist); // sets value of distToPosition
	
	OpenSteer::Vec3 getSteerCoords();  // retrieves the value of steerCoords
	void setSteerCoords(OpenSteer::Vec3 coords);  // sets the value of steerCoords
	
	void reset(void); // resets the state
	void update (const float currentTime, const float elapsedTime); // update steering sim every frame

	void updateOffense(const float currentTime, const float elapsedTime);	// updates the offense steering sim
	void updateDefense(const float currentTime, const float elapsedTime);	// updates the defense steering sim


	private:
	int counter;
    std::vector<playerSteer*>	m_others;
    std::vector<playerSteer*>	m_AllPlayers;
    OpenSteer::Vec3 m_home;
    //Ball*	m_Ball;
    int teamNumber;  // stores which team the player belongs to
    int		m_MyID;
	int ID; // Stores which player on the team the instance associates with
	
	float distToPosition; // stores the distance player is from target position
	
	OpenSteer::Vec3 steerCoords;
};

#endif
