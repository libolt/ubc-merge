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

#include "basketballsteer.h"
#include "gamestate.h"
#include "playerstate.h"
#include "teamstate.h"

basketballSteer::basketballSteer()
{
	ID = -1;

}

basketballSteer::~basketballSteer()
{

}

int basketballSteer::getID() // retrieves the value of ID
{
	return (ID);
}
void basketballSteer::setID(int id) // sets the value of ID
{
	ID = id;
}

// reset state
void basketballSteer::reset(void)
{
    steering::reset (); // reset the vehicle
    setSpeed (0.0f);         // speed along Forward direction.
    setMaxForce (3000.7f);      // steering force is clipped to this magnitude
    setMaxSpeed (10);         // velocity is clipped to this magnitude

	gameState *gameS = gameState::Instance();
	std::vector<teamState> teamInstance = gameS->getTeamInstance();
	std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();

	OpenSteer::Vec3 basketballSteerPos = convertToOpenSteerVec3(basketballInstance[0].getNodePosition());
    // Place me on my part of the field, looking at oponnents goal
//    setPosition(b_ImTeamA ? OpenSteer::frandom01()*20 : -OpenSteer::frandom01()*20, 0, (OpenSteer::frandom01()-0.5f)*20);

    setPosition(basketballSteerPos);

//    setPosition(OpenSteer::Vec3(-playerSteerPos.x, playerSteerPos.y, playerSteerPos.z));


	OpenSteer::Vec3 m_home = basketballSteerPos;
//    m_home = position();
//    OpenSteer::AnnotationMixin< Super >::clearTrailHistory ();    // prevent long streaks due to teleportation
//    OpenSteer::clearTrailHistory ();
//    setTrailParameters (10, 60);
}

void basketballSteer::update (const float /*currentTime*/, float elapsedTime)
{
/*
	gameState *gameS = gameState::Instance();
	std::vector<basketballs> basketball = gameS->getBasketballInstance();
	std::vector<teamState> teamInstance = gameS->getTeamInstance();
	const std::vector<playerState> playerInstance = teamInstance[0].getPlayerInstance();
	const std::vector<playerSteer> playerSteerInstance;
    for (int x=0;x<playerInstance.size();++x)
	{
		playerSteerInstance.push_back(playerInstance[x].getSteer());
	}
	// if I hit the ball, kick it.
Ogre::LogManager::getSingletonPtr()->logMessage("playerSteerInstane size = " +toString(playerSteerInstance.size()));

	OpenSteer::Vec3 playerSteerPos = convertToOpenSteerVec3(playerInstance[ID].getNodePosition());
	OpenSteer::Vec3 m_home = playerSteerPos;
	OpenSteer::Vec3 bballSteerPos = convertToOpenSteerVec3(basketball[0].getNodePosition());

	const float distToBall = OpenSteer::Vec3::distance (playerSteerPos, bballSteerPos);
//            const float sumOfRadii = radius() + m_Ball->radius();
//            if (distToBall < sumOfRadii)
	if (distToBall < 2.0f)
	{
//                m_Ball->kick((bballSteerPos-playerSteerPos)*50, elapsedTime);
	}

	// otherwise consider avoiding collisions with others
	OpenSteer::Vec3 collisionAvoidance = steerToAvoidNeighbors(1.0f, (OpenSteer::AVGroup&)playerSteerInstance);
*/

/*	if(collisionAvoidance != OpenSteer::Vec3::zero)
		applySteeringForce (collisionAvoidance, elapsedTime);
	else
		{
		float distHomeToBall = OpenSteer::Vec3::distance (m_home, bballSteerPos);
		if( distHomeToBall < 12.0f)
			{
			// go for ball if I'm on the 'right' side of the ball
				if( b_ImTeamA ? playerSteerPos.x > bballSteerPos.x : playerSteerPos.x < bballSteerPos.x)
				{
				OpenSteer::Vec3 seekTarget = xxxsteerForSeek(bballSteerPos);
				applySteeringForce (seekTarget, elapsedTime);
				}
			else
				{
				if( distHomeToBall < 12.0f)
					{
					float Z = bballSteerPos.z - playerSteerPos.z > 0 ? -1.0f : 1.0f;
					OpenSteer::Vec3 behindBall = bballSteerPos + (b_ImTeamA ? OpenSteer::Vec3(2.0f,0.0f,Z) : OpenSteer::Vec3(-2.0f,0.0f,Z));
					OpenSteer::Vec3 behindBallForce = xxxsteerForSeek(behindBall);
//FIXME					annotationLine (playerSteerPos, behindBall , OpenSteer::Color(0.0f,1.0f,0.0f));
					OpenSteer::Vec3 evadeTarget = xxxsteerForFlee(bballSteerPos);
					applySteeringForce (behindBallForce*10.0f + evadeTarget, elapsedTime);
					}
				}
			}
		else	// Go home
			{
			OpenSteer::Vec3 seekTarget = xxxsteerForSeek(m_home);
			OpenSteer::Vec3 seekHome = xxxsteerForSeek(m_home);
			applySteeringForce (seekTarget+seekHome, elapsedTime);
			}

		}
*/
}
