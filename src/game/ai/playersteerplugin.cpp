/***************************************************************************
 *   Copyright (C) 2014 by Mike McLean   *
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

#include "Ogre.h"
#include "playersteerplugin.h"
#include "ai.h"
#include "courtstate.h"
#include "gamestate.h"
#include "logging.h"
#include "teamstate.h"
#include "playerstate.h"

void playerSteerPlugin::open(void)
{
	AISystem *ai = AISystem::Instance();
	gameState *gameS = gameState::Instance();

	std::vector<courtState> courtInstance = gameS->getCourtInstance();
	std::vector<teamState> teamInstance = gameS->getTeamInstance();
	std::vector<playerState> team0PlayerInstance = teamInstance[0].getPlayerInstance();
	std::vector<playerState> team1PlayerInstance = teamInstance[1].getPlayerInstance();
    std::vector<int> team0ActivePlayerID = teamInstance[0].getActivePlayerID();
    std::vector<int> team1ActivePlayerID = teamInstance[1].getActivePlayerID();

	std::vector<playerSteer *> allPlayerSteers = ai->getAllPlayerSteers();

	logMsg("Opening playerSteer plugin");

	// builds team 0 steering instances
//	for (size_t x=0;x<team0PlayerInstance.size();++x)
	size_t x = 0;
    size_t y = 0;
	while (x<team0PlayerInstance.size())
	{
//		logMsg("Alive0");
	    logMsg("team 0 steer!");
        while (y<team0ActivePlayerID.size())
        {
//            if (team0PlayerInstance[x].getIsActive())
            if (team0PlayerInstance[x].getPlayerID() == team0ActivePlayerID[y])
            {
                playerSteer *steer = team0PlayerInstance[x].getSteer();
        //		logMsg("Alive1");
                logMsg("x = " +Ogre::StringConverter::toString(x));
                logMsg("player position = " +Ogre::StringConverter::toString(team0PlayerInstance[x].getNodePosition()));
                steer->setPosition(convertToOpenSteerVec3(team0PlayerInstance[x].getNodePosition()));
        //		steer.setPosition(OpenSteer::Vec3(0,0,0));
        //		logMsg("Alive2");

        //		steer->setID(x);
                ai->selectedVehicle = steer;
                team0PlayerInstance[x].setSteer(steer);
                allPlayerSteers.push_back(team0PlayerInstance[x].getSteer());
    //        logMsg("team 0 playerInstance added =  " +Ogre::StringConverter::toString(x));
            }
         ++y;
        }
        ++x;
	}
//	exit(0);
	// builds team 1 steering instances

	logMsg("team 1 steer!");
	x = 0;
//	for (size_t x=0;x<team1PlayerInstance.size();++x)
	while (x<team1PlayerInstance.size())
	{
        y = 0;
        while (y<team1ActivePlayerID.size())
        {
//        if (team1PlayerInstance[x].getIsActive())
            if (team1PlayerInstance[x].getPlayerID() == team0ActivePlayerID[y])
            {
                playerSteer *steer = team1PlayerInstance[x].getSteer();
                steer->setPosition(convertToOpenSteerVec3(team1PlayerInstance[x].getNodePosition()));
        //		steer->setID(x);
                team1PlayerInstance[x].setSteer(steer);
                allPlayerSteers.push_back(team1PlayerInstance[x].getSteer());
            }
            ++y;
        }
        ++x;
	}

    ai->setAllPlayerSteers(allPlayerSteers);	// stores the instances
//    logMsg("team 0 playerInstance added =  " +Ogre::StringConverter::toString( ai->getAllPlayerSteers().size()));


	// create the court bounding box based off the meshes bbox
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

/*    m_PlayerCountA = 8;
    for(unsigned int i=0; i < m_PlayerCountA ; i++)
    {
        playerSteer *playerSteerTest = new playerSteer;
        ai->setSelectedVehicle(playerSteerTest);
        TeamA.push_back (playerSteerTest);
        m_AllPlayers.push_back(playerSteerTest);
    }
*/
    // Build Team B

/*    m_PlayerCountB = 8;
    for(unsigned int i=0; i < m_PlayerCountB ; i++)
    {
        playerSteer *playerSteerTest = new playerSteer;
        ai->setSelectedVehicle(playerSteerTest);
        TeamB.push_back (playerSteerTest);
        m_AllPlayers.push_back(playerSteerTest);
    }
    */
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
	gameState *gameS = gameState::Instance();
	std::vector<teamState> teamInstance = gameS->getTeamInstance();
	std::vector<playerState> team0PlayerInstance = teamInstance[0].getPlayerInstance();
	std::vector<playerState> team1PlayerInstance = teamInstance[1].getPlayerInstance();
    std::vector<int> team0ActivePlayerID = teamInstance[0].getActivePlayerID();
    std::vector<int> team1ActivePlayerID = teamInstance[1].getActivePlayerID();

//	exit(0);
    // update simulation of test vehicle
//    logMsg("team 0 playerInstance size =  " +Ogre::StringConverter::toString(team0PlayerInstance.size()));

// FIXME testing with one specific player for now

//    team1PlayerInstance[3].getSteer()->update(currentTime, elapsedTime);

    size_t x = 0;
    size_t y = 0;
//    for(unsigned int i=0;i<team0PlayerInstance.size();i++)
    while (x<team0PlayerInstance.size())
    {
        while (y<team0ActivePlayerID.size())
        {
            if (team0PlayerInstance[x].getPlayerID() == team0ActivePlayerID[y])
            {
                if (x != teamInstance[0].getHumanPlayer())
                {
                    team0PlayerInstance[x].getSteer()->update(currentTime, elapsedTime);
                }
            }
            ++y;
        }
        ++x;
    }

    x = 0;
//    for(unsigned int i=0;i<team1PlayerInstance.size();i++)
    while (x<team1PlayerInstance.size())
    {
        y = 0;
        while (y<team1ActivePlayerID.size())
        {
            if (team1PlayerInstance[x].getPlayerID() == team1ActivePlayerID[y])
            {
                if (x != teamInstance[1].getHumanPlayer())
                {
                    team1PlayerInstance[x].getSteer()->update(currentTime, elapsedTime);
                }
            }
            ++y;
        }
        ++x;
    }

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
