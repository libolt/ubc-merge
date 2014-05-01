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
 
#ifndef _PLAYERSTEERPLUGIN_H_
#define _PLAYERSTEERPLUGIN_H_

#include "steering.h"
#include "playersteer.h"

// PlugIn for OpenSteerDemo
class playerSteerPlugin : public OpenSteer::PlugIn
{
    public:
        
    const char* name (void) {return "Player plugin";}

    // float selectionOrderSortKey (void) {return 0.06f;}

    // bool requestInitialSelection() { return true;}

    // be more "nice" to avoid a compiler warning
    virtual ~playerSteerPlugin() {}

    void open(void);

    void update (const float currentTime, const float elapsedTime);

    void redraw (const float currentTime, const float elapsedTime);

    void close (void);

    void reset (void);


    /* const*/ OpenSteer::AVGroup& allVehicles (void) {return (/*const*/ OpenSteer::AVGroup&) TeamA;}

    unsigned int	m_PlayerCountA;
    unsigned int	m_PlayerCountB;
    std::vector<playerSteer*> TeamA;
    std::vector<playerSteer*> TeamB;
    std::vector<playerSteer*> m_AllPlayers;

/*        Ball	*m_Ball;
        AABBox	*m_bbox;
        AABBox	*m_TeamAGoal;
        AABBox	*m_TeamBGoal;
*/
    int junk;
    int	 m_redScore;
    int	 m_blueScore;
};
 
 #endif
