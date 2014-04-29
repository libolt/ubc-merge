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
 
#include "ai.h"

AISystem* AISystem::pInstance = 0;

AISystem* AISystem::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new AISystem; // create sole instance
    }
    return pInstance; // address of sole instance
}

AISystem::AISystem()
{
	selectedVehicle = NULL;
}
AISystem::~AISystem()
{
	
}
  
// initial setup of AI state
bool AISystem::setup(void)
{
	return true;
}

// updates AI state
void AISystem::update(void)
{
	
}

// select the default PlugIn


void AISystem::selectDefaultPlugIn (void)
{
    OpenSteer::PlugIn::sortBySelectionOrder ();
    selectedPlugIn = OpenSteer::PlugIn::findDefault ();
}

// select the "next" plug-in, cycling through "plug-in selection order"


void AISystem::selectNextPlugIn (void)
{
    closeSelectedPlugIn ();
    selectedPlugIn = selectedPlugIn->next ();
    openSelectedPlugIn ();
}

// return name of currently selected plug-in


const char* AISystem::nameOfSelectedPlugIn (void)
{
    return (selectedPlugIn ? selectedPlugIn->name() : "no PlugIn");
}

// open the currently selected plug-in


void AISystem::openSelectedPlugIn (void)
{
//    camera.reset ();
    selectedVehicle = NULL;
    selectedPlugIn->open ();
}

// do a simulation update for the currently selected plug-in


void AISystem::updateSelectedPlugIn (const float currentTime,
                                                const float elapsedTime)
{
    // switch to Update phase
//    pushPhase (updatePhase);

    // service queued reset request, if any
//    doDelayedResetPlugInXXX ();

    // if no vehicle is selected, and some exist, select the first one
    if (selectedVehicle == NULL)
    {
        const OpenSteer::AVGroup& vehicles = allVehiclesOfSelectedPlugIn();
        if (vehicles.size() > 0) selectedVehicle = vehicles.front();
    }

    // invoke selected PlugIn's Update method
    selectedPlugIn->update (currentTime, elapsedTime);

    // return to previous phase
//    popPhase ();
}

// close the currently selected plug-in


void AISystem::closeSelectedPlugIn (void)
{
    selectedPlugIn->close ();
    selectedVehicle = NULL;
}

// reset the currently selected plug-in


void AISystem::resetSelectedPlugIn (void)
{
    selectedPlugIn->reset ();
}

// return a group (an STL vector of AbstractVehicle pointers) of all
// vehicles(/agents/characters) defined by the currently selected PlugIn


const OpenSteer::AVGroup& AISystem::allVehiclesOfSelectedPlugIn (void)
{
    return selectedPlugIn->allVehicles ();
}

// select the "next" vehicle: the one listed after the currently selected one
// in allVehiclesOfSelectedPlugIn


void AISystem::selectNextVehicle (void)
{
    if (selectedVehicle != NULL)
    {
        // get a container of all vehicles
        const OpenSteer::AVGroup& all = allVehiclesOfSelectedPlugIn ();
        const OpenSteer::AVIterator first = all.begin();
        const OpenSteer::AVIterator last = all.end();

        // find selected vehicle in container
        const OpenSteer::AVIterator s = std::find (first, last, selectedVehicle);

        // normally select the next vehicle in container
        selectedVehicle = *(s+1);

        // if we are at the end of the container, select the first vehicle
        if (s == last-1) selectedVehicle = *first;

        // if the search failed, use NULL
        if (s == last) selectedVehicle = NULL;
    }
}

