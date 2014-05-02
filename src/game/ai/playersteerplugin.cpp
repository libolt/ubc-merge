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

#include "ogre.h"
#include "playersteerplugin.h"
#include "ai.h"
#include "courtstate.h"
#include "gamestate.h"
#include "teamstate.h"

void playerSteerPlugin::open(void)
{
	AISystem *ai = AISystem::Instance();
	gameState *gameS = gameState::Instance();
	
	
    // create the court bounding box based off the meshes bbox
	std::vector<courtState> courtInstance = gameS->getCourtInstance();
	Ogre::AxisAlignedBox cbox = courtInstance[0].getModel()->getBoundingBox();
	Ogre::Vector3 cboxMin = cbox.getMinimum();
	Ogre::Vector3 cboxMax = cbox.getMaximum();
	
	OpenSteer::Vec3 courtBoxMin = convertToOpenSteerVec3(cboxMin);
	OpenSteer::Vec3 courtBoxMax = convertToOpenSteerVec3(cboxMax);

    courtBBox = new steering::AABBox( OpenSteer::Vec3(0,0,0), OpenSteer::Vec3(0,0,0));
	courtBBox->setMin(courtBoxMin);
	
 /*           // Red goal
            m_TeamAGoal = new AABBox(Vec3(-21,0,-7), Vec3(-19,0,7));
            // Blue Goal
            m_TeamBGoal = new AABBox(Vec3(19,0,-7), Vec3(21,0,7));
            // Make a ball
            m_Ball = new Ball(m_bbox);
*/
        // Build team A
    m_PlayerCountA = 8;
    for(unsigned int i=0; i < m_PlayerCountA ; i++)
    {
        playerSteer *playerSteerTest = new playerSteer;
        ai->setSelectedVehicle(playerSteerTest);
        TeamA.push_back (playerSteerTest);
        m_AllPlayers.push_back(playerSteerTest);
    }
    // Build Team B
    m_PlayerCountB = 8;
    for(unsigned int i=0; i < m_PlayerCountB ; i++)
    {
        playerSteer *playerSteerTest = new playerSteer;
        ai->setSelectedVehicle(playerSteerTest);
        TeamB.push_back (playerSteerTest);
        m_AllPlayers.push_back(playerSteerTest);
    }
    // initialize camera
/*            OpenSteerDemo::init2dCamera (*m_Ball);
            OpenSteerDemo::camera.setPosition (10, OpenSteerDemo::camera2dElevation, 10);
            OpenSteerDemo::camera.fixedPosition.set (40, 40, 40);
            OpenSteerDemo::camera.mode = Camera::cmFixed;
            m_redScore = 0;
            m_blueScore = 0;
*/
}
	
void playerSteerPlugin::update(const float currentTime, const float elapsedTime)
{
	exit(0);
    // update simulation of test vehicle
    for(unsigned int i=0; i < m_PlayerCountA ; i++)
    TeamA[i]->update (currentTime, elapsedTime);
    for(unsigned int i=0; i < m_PlayerCountB ; i++)
        TeamB[i]->update (currentTime, elapsedTime);
/*            m_Ball->update(currentTime, elapsedTime);

            if(m_TeamAGoal->InsideX(m_Ball->position()) && m_TeamAGoal->InsideZ(m_Ball->position()))
            {
                m_Ball->reset();	// Ball in blue teams goal, red scores
                m_redScore++;
            }
            if(m_TeamBGoal->InsideX(m_Ball->position()) && m_TeamBGoal->InsideZ(m_Ball->position()))
            {
                m_Ball->reset();	// Ball in red teams goal, blue scores
                    m_blueScore++;
            }
*/
}

void playerSteerPlugin::redraw (const float currentTime, const float elapsedTime)
{
/*
            // draw test vehicle
            for(unsigned int i=0; i < m_PlayerCountA ; i++)
                TeamA[i]->draw ();
            for(unsigned int i=0; i < m_PlayerCountB ; i++)
                TeamB[i]->draw ();
            m_Ball->draw();
            m_bbox->draw();
            m_TeamAGoal->draw();
            m_TeamBGoal->draw();
            {
                std::ostringstream annote;
                annote << "Red: "<< m_redScore;
                draw2dTextAt3dLocation (annote, Vec3(23,0,0), Color(1.0f,0.7f,0.7f), drawGetWindowWidth(), drawGetWindowHeight());
            }
            {
                std::ostringstream annote;
                annote << "Blue: "<< m_blueScore;
                draw2dTextAt3dLocation (annote, Vec3(-23,0,0), Color(0.7f,0.7f,1.0f), drawGetWindowWidth(), drawGetWindowHeight());
            }

            // textual annotation (following the test vehicle's screen position)
    if(0)
        for(unsigned int i=0; i < m_PlayerCountA ; i++)
            {
                std::ostringstream annote;
                annote << std::setprecision (2) << std::setiosflags (std::ios::fixed);
                annote << "      speed: " << TeamA[i]->speed() << "ID:" << i << std::ends;
                draw2dTextAt3dLocation (annote, TeamA[i]->position(), gRed, drawGetWindowWidth(), drawGetWindowHeight());
                draw2dTextAt3dLocation (*"start", Vec3::zero, gGreen, drawGetWindowWidth(), drawGetWindowHeight());
            }
            // update camera, tracking test vehicle
            OpenSteerDemo::updateCamera (currentTime, elapsedTime, *OpenSteerDemo::selectedVehicle);

            // draw "ground plane"
            OpenSteerDemo::gridUtility (Vec3(0,0,0));
*/
}

void playerSteerPlugin::close (void)
{
    for(unsigned int i=0; i < m_PlayerCountA ; i++)
        delete TeamA[i];
    TeamA.clear ();
    for(unsigned int i=0; i < m_PlayerCountB ; i++)
        delete TeamB[i];
    TeamB.clear ();
        m_AllPlayers.clear();
}

void playerSteerPlugin::reset (void)
{
    // reset vehicle
    for(unsigned int i=0; i < m_PlayerCountA ; i++)
        TeamA[i]->reset ();
    for(unsigned int i=0; i < m_PlayerCountB ; i++)
        TeamB[i]->reset ();
//            m_Ball->reset();
}
