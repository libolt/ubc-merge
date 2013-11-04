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

#ifndef _PHYSICSENGINE_H_
#define _PHYSICSENGINE_H_

#include <vector>

#include "BtOgrePG.h"
#include "BtOgreGP.h"
#include "BtOgreExtras.h"


class physicsEngine
{
public:
    virtual ~physicsEngine();	// destructor
    static physicsEngine *Instance();

    virtual void setupState();  // sets up state of physics engine.
    virtual void updateState(); // updates the state of the physics engine.

    // sets up object physics
    virtual void setupPlayerPhysics(); // setsup up player physics
    virtual void setupCourtPhysics();   // sets up court physics
    virtual void setupBasketballPhysics(); // sets up basketball physics

protected:
    physicsEngine();
    physicsEngine(const physicsEngine&);
    physicsEngine &operator = (const physicsEngine&);

private:

    static physicsEngine *pInstance;
    btDynamicsWorld *world;
    BtOgre::DebugDrawer *debugDraw;
//    btAxisSweep3 *broadPhase;
    btBroadphaseInterface *broadPhase;
    btDefaultCollisionConfiguration *collisionConfig;
	btCollisionDispatcher *dispatcher;
	btSequentialImpulseConstraintSolver *solver;

    // players
	std::vector<btRigidBody *> playerBody;
	std::vector<btCollisionShape *> playerShape;
    std::vector<BtOgre::RigidBodyState *> playerBodyState;
//    std::vector<btDefaultMotionState *> playerBodyState;
    // court
	btRigidBody *courtBody;
//	btBvhTriangleMeshShape *courtShape;
	btCollisionShape *courtShape;
	btDefaultMotionState *courtBodyState;

    // basketball
    btRigidBody *basketballBody;
    btBvhTriangleMeshShape *basketballShape;
    BtOgre::RigidBodyState *basketballBodyState;
};

#endif // PHYSICS_H_INCLUDED
