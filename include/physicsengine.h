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
#include "BulletDynamics/Dynamics/btRigidBody.h"

class physicsEngine
{
public:
    virtual ~physicsEngine();	// destructor
    static physicsEngine *Instance();

    virtual bool getPairCollided();	// retrieves value of pairCollided variable
    virtual void setPairCollided(bool collided);	// sets value of pairCollided variable

    virtual void setupState();  // sets up state of physics engine.

    // sets up object physics
    virtual void setupBasketballPhysics(); // sets up basketball physics
    virtual void setupCourtPhysics();   // sets up court physics
    virtual void setupPlayerPhysics(); // setsup up player physics

    virtual void updateState(); // updates the state of the physics engine.

    virtual void tipOffCollisionCheck();	// checks whether team 1 or team 2's center made contact with ball

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
	btContactSolverInfo contactInfo;

    // players
//	std::vector<btRigidBody *> playerBody;
//	std::vector<btCollisionShape *> playerShape;
//    std::vector<BtOgre::RigidBodyState *> playerBodyState;
//    std::vector<btDefaultMotionState *> playerBodyState;
    // court
	btRigidBody *courtBody;
//	btBvhTriangleMeshShape *courtShape;
	btCollisionShape *courtShape;
	btDefaultMotionState *courtBodyState;

    // basketball
    btRigidBody *basketballBody;
 //   btBvhTriangleMeshShape *basketballShape;
    btCollisionShape *basketballShape;
    BtOgre::RigidBodyState *basketballBodyState;

    bool pairCollided;
    // contact result callback

    // collisions
    int courtCollidesWith = COL_BBALL | COL_TEAM1 | COL_TEAM2;	// determines what the court collides with
    int bballCollidesWith = COL_COURT; // | COL_TEAM1 | COL_TEAM2;	// determines what the basketball collides with
    int team1CollidesWith = COL_COURT; // | COL_BBALL | COL_TEAM2;	// determines what team1 collides with
    int team2CollidesWith = COL_COURT; // | COL_BBALL | COL_TEAM1;	// determiens what team2 collides with

};

    //RESULT CALLBACK FOR DETECTION OF COLLIDING PAIRS; found code here ---> http://www.ogre3d.org/forums/viewtopic.php?f=2&t=64815&p=428681
    struct MyContactResultCallback : public btCollisionWorld::ContactResultCallback
    {
    	physicsEngine *physE = physicsEngine::Instance();
    	bool m_connected = false;
        MyContactResultCallback() :m_connected(false)
    	{
    	}
    //	virtual btScalar addSingleResult(btManifoldPoint& cp,   const btCollisionObject* colObj0,int partId0,int index0,const btCollisionObject* colObj1,int partId1,int index1)
    	virtual btScalar addSingleResult(btManifoldPoint& cp,    const btCollisionObjectWrapper* colObj0Wrap,int partId0,int index0,const btCollisionObjectWrapper* colObj1Wrap,int partId1,int index1)
    	{

    		if (cp.getDistance()<=0)
    		{
   			m_connected = true;
    			physE->setPairCollided(true);
    //		    exit(0);
    		}
    		else
    		{
    			physE->setPairCollided(false);
    		}
    		return 1.f;
    	}
    };


#endif // PHYSICS_H_INCLUDED
