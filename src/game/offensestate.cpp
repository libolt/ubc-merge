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

#include "offensestate.h"

offenseState::offenseState()
{
	startPositions = new Ogre::Vector3[5];
}


Ogre::Vector3 *offenseState::getStartPositions()	// retrieves startPositions variable
{
	return (startPositions);
}

void offenseState::setStartPositions(Ogre::Vector3 *positions)	// sets startPositions
{
	startPositions = positions;
}

void offenseState::setupState()
{
	startPositions[0] = Ogre::Vector3(5.0f,-13.5f,380.0f);
}
