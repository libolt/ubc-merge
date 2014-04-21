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

 #include "steering.h"
 
OpenSteer::Vec3 steering::convertToOpenSteerVec3(Ogre::Vector3 vect)  // converts from Ogre::Vector3 to OpenSteer::Vec3
{
	OpenSteer::Vec3 vec3;
	vec3.x = vect[0];
	vec3.y = vect[1];
	vec3.z = vect[2];
	
	return (vec3);
}
Ogre::Vector3 steering::convertToOgreVector3(OpenSteer::Vec3 vect) // converts from OpenSteer::Vec3 to Ogre::Vector3
{
	Ogre::Vector3 vector3;
	vector3[0] = vect.x;
	vector3[1] = vect.y;
	vector3[2] = vect.z;
	
	return (vector3);
}
