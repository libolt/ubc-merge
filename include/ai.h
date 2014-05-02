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

#ifndef _AI_H_
#define _AI_H_

#include "steering.h"

#include "playersteerplugin.h"

class AISystem
{
public:

	~AISystem();

	OpenSteer::AbstractVehicle* getSelectedVehicle(); // retrieves the value of selectedVehicle
	void setSelectedVehicle(OpenSteer::AbstractVehicle* vehicle);  // sets the value of selectedVehicle

	std::vector<playerSteer> getAllPlayerSteers();	// retrieves the value of allPlayerSteers
	void setAllPlayerSteers(std::vector<playerSteer> steers);	// sets the value of allPlayerSteers

    // initial setup of AI state
    bool setup(void);

	// updates AI state
	void update(const float currentTime, const float elapsedTime);

	void printPlugIn (OpenSteer::PlugIn& pi);

	// select the default PlugIn
    void selectDefaultPlugIn (void);

	// select the "next" plug-in, cycling through "plug-in selection order"
    void selectNextPlugIn (void);

	// return name of currently selected plug-in
    const char* nameOfSelectedPlugIn (void);

	// open the currently selected plug-in
    void openSelectedPlugIn (void);

	// do a simulation update for the currently selected plug-in
    void updateSelectedPlugIn (const float currentTime, const float elapsedTime);

	// close the currently selected plug-in
    void closeSelectedPlugIn (void);

    // reset the currently selected plug-in
    void resetSelectedPlugIn (void);

	// select the "next" vehicle: cycle through the registry
    void selectNextVehicle (void);

	const OpenSteer::AVGroup& allVehiclesOfSelectedPlugIn(void);

	playerSteerPlugin playerSteerPluginInstance;

    static AISystem *Instance();
protected:
    AISystem();
    AISystem(const AISystem&);
    AISystem& operator= (const AISystem&);
private:
    static AISystem *pInstance;

	// currently selected plug-in (user can choose or cycle through them)
    OpenSteer::PlugIn* selectedPlugIn;

	// currently selected vehicle
	OpenSteer::AbstractVehicle* selectedVehicle;

	std::vector<playerSteer> allPlayerSteers;

};

 #endif

