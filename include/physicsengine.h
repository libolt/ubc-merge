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

    virtual bool getPlayerPhysicsSetup();	// retrieves the value of the playerPhysicsSetup variable
    virtual void setPlayerPhysicsSetup(bool setup);	// sets the value of the playerPhysicsSetup variable

    virtual bool getBasketballlPhysicsSetup();	// retrieves the value of the playerPhysicsSetup variable
    virtual void setBasketballPhysicsSetup(bool setup);	// sets the value of the playerPhysicsSetup variable

    virtual bool getCourtPhysicsSetup();	// retrieves the value of the playerPhysicsSetup variable
    virtual void setCourtPhysicsSetup(bool setup);	// sets the value of the playerPhysicsSetup variable

    virtual bool getPairCollided();	// retrieves value of thepairCollided variable
    virtual void setPairCollided(bool collided);	// sets value of thepairCollided variable

    virtual bool getPassCollision();	// retrieves the value of the passCollision variable
    virtual void setPassCollision(bool collision);	// sets the value of the passCollision variable

    virtual void setupState();  // sets up state of physics engine.

    // sets up object physics
    virtual bool setupBasketballPhysics(); // sets up basketball physics
    virtual bool setupCourtPhysics();   // sets up court physics
    virtual bool setupPlayerPhysics(); // setsup up player physics

    virtual void updateState(); // updates the state of the physics engine.
	virtual void stepWorld();	// steps the physics simulation

    virtual void tipOffCollisionCheck();	// checks whether team 1 or team 2's center made contact with ball
    virtual void ballDribbling();	// simulates basketball dribble
    virtual void passCollisionCheck();	// checks whether the ball has collided with the player being passed to
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
//	btRigidBody *courtBody;
//	btBvhTriangleMeshShape *courtShape;
	btCollisionShape *courtShape;
//	btDefaultMotionState *courtBodyState;
	BtOgre::RigidBodyState *courtBodyState;
    // basketball
//    btRigidBody *basketballBody;
 //   btBvhTriangleMeshShape *basketballShape;
    btCollisionShape *basketballShape;
    BtOgre::RigidBodyState *basketballBodyState;


    // timer variables
    btScalar changeInTime;
    btScalar oldTime;

    bool playerPhysicsSetup;
    bool basketballPhysicsSetup;
    bool courtPhysicsSetup;
    bool pairCollided;

    bool passCollision;	// stores whether a ball has collided with player during a pass
    // contact result callback

    // collisions
    int courtCollidesWith;	// determines what the court collides with
    int bballCollidesWith;	// determines what the basketball collides with
    int team1CollidesWith;	// determines what team1 collides with
    int team2CollidesWith;  // | COL_BBALL | COL_TEAM1;	// determiens what team2 collides with

};

    // Collision Callback
/*    struct MyContactResultCallback : public btCollisionWorld::ContactResultCallback
    {
//    	physicsEngine *physE = physicsEngine::Instance();
    	bool collision;
        MyContactResultCallback() : collision(false)
    	{
    	}
    //	virtual btScalar addSingleResult(btManifoldPoint& cp,   const btCollisionObject* colObj0,int partId0,int index0,const btCollisionObject* colObj1,int partId1,int index1)
    	virtual btScalar addSingleResult(btManifoldPoint& cp,    const btCollisionObjectWrapper* colObj0Wrap,int partId0,int index0,const btCollisionObjectWrapper* colObj1Wrap,int partId1,int index1)
    	{
			
			Ogre::LogManager::getSingletonPtr()->logMessage("Checking Collision!!");

    		if (cp.getDistance()<=0)
    		{
				Ogre::LogManager::getSingletonPtr()->logMessage("Collision!!");
				collision = true;

//    			physE->setPairCollided(true);
    //		    exit(0);
    		}
    		else
    		{
				Ogre::LogManager::getSingletonPtr()->logMessage("No Collision!!");
				collision = false;
//    			physE->setPairCollided(false);
    		}
    		return 1.f;
    	}
    };*/

struct   MyContactResultCallback : public btCollisionWorld::ContactResultCallback
{
	bool m_connected;
	MyContactResultCallback() :m_connected(false)
	{
	}
//	virtual   btScalar   addSingleResult(btManifoldPoint& cp, const btCollisionObject* colObj0, int partId0, int index0, const btCollisionObject* colObj1, int partId1, int index1)
	virtual btScalar addSingleResult(btManifoldPoint& cp, const btCollisionObjectWrapper* colObj0Wrap, int partId0, int index0, const btCollisionObjectWrapper* colObj1Wrap, int partId1, int index1)
	{
		if (cp.getDistance() <= 0)
		{
			m_connected = true;
		}
		return 1.f;
	}
};


#endif // PHYSICS_H_INCLUDED
