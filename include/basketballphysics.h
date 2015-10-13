/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean   *
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

#ifndef _BASKETBALLPHYSICS_H_
#define _BASKETBALLPHYSICS_H_

#include "BtOgrePG.h"
#include "BtOgreGP.h"
#include "BtOgreExtras.h"
#include "BulletDynamics/Dynamics/btRigidBody.h"


class basketballPhysics
{
    public:
        btCollisionShape *getBasketballShape();  // retrieves the value of basketballShape
        void setBasketballShape(btCollisionShape *set);  // sets the value of basketballShape

        BtOgre::RigidBodyState *getBasketballBodyState();  // retrieves the value of basketballBodyState
        void setBasketBallBodyState(BtOgre::RigidBodyState *set);  // sets the value of basketballBodyState

        bool setupPhysics();  // sets up basketball physics

    private:
        btCollisionShape *basketballShape;  // stores the shape of the basketball shape
        BtOgre::RigidBodyState *basketballBodyState;  // stores the state of the basketball

        int bballCollidesWith;	// determines what the basketball collides with

};

#endif // BASKETBALLPHYSICS_H

