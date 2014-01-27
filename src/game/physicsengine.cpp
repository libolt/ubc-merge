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

#include "gameengine.h"
#include "gamestate.h"
#include "input.h"
#include "players.h"
#include "playerstate.h"
#include "physicsengine.h"
#include "renderengine.h"


physicsEngine* physicsEngine::pInstance = 0;
physicsEngine* physicsEngine::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new physicsEngine; // create sole instance
    }
    return pInstance; // address of sole instance
}


//-------------------------------------------------------------------------------------
physicsEngine::physicsEngine()
{
	    //Bullet initialisation.
//	    broadPhase = new btAxisSweep3(btVector3(-10000,-10000,-10000), btVector3(10000,10000,10000), 1024);
	broadPhase = new btDbvtBroadphase();
	collisionConfig = new btDefaultCollisionConfiguration();
	dispatcher = new btCollisionDispatcher(collisionConfig);
	solver = new btSequentialImpulseConstraintSolver();

	world = new btDiscreteDynamicsWorld(dispatcher, broadPhase, solver, collisionConfig);
    world->setGravity(btVector3(0,-9.8,0));

    contactInfo = world->getSolverInfo();
    contactInfo.m_restingContactRestitutionThreshold = 1e30;
    contactInfo.m_restitution = 1.3f;
    contactInfo.m_friction = 1.5f;
    //FIXME: Hack to set total number of players for physics to 10, set this to be dynamic
//    btRigidBody *body;
    changeInTime = 0;
    oldTime = 0;

    btCollisionShape *shape;
    BtOgre::RigidBodyState *state;

    pairCollided = false;

}
//-------------------------------------------------------------------------------------
physicsEngine::~physicsEngine()
{
    //Free rigid bodies

    // FIXME!: Fix this so that it relies on a variable that stores total number of players
    for (int i=0; i<10; ++i)
    {
//        world->removeRigidBody(*playerBody[i]);
    }
//    delete playerBody->getMotionState();
//    delete playerBody;
//    delete playerShape;

    world->removeRigidBody(courtBody);
    delete courtBody->getMotionState();
    delete courtBody;
//    delete courtShape->getMeshInterface();
    delete courtShape;

    //Free Bullet stuff.
    delete debugDraw;
    delete world;

    delete solver;
    delete dispatcher;
    delete collisionConfig;
    delete broadPhase;

}

bool physicsEngine::getPairCollided()	// retrieves value of pairCollided variable
{
	return (pairCollided);
}
void physicsEngine::setPairCollided(bool collided)	// sets value of pairCollided variable
{
	pairCollided = collided;
}
void physicsEngine::setupState(void)
{

    renderEngine *render = renderEngine::Instance();

    // Debug drawing!
    debugDraw = new BtOgre::DebugDrawer(render->getMSceneMgr()->getRootSceneNode(), world);
    world->setDebugDrawer(debugDraw);



}

void physicsEngine::setupPlayerPhysics()
{
//   exit(0);
    gameState *gameS = gameState::Instance();
    players *player = players::Instance();

    std::vector<playerState> pInstance = gameS->getPlayerInstance();

    btRigidBody *playerBody;
    btCollisionShape *playerShape;
    BtOgre::RigidBodyState *playerBodyState;

    // loops through physics objects for all players
    for (int i=0; i<10; ++i)
    {

        // create shape
        BtOgre::StaticMeshToShapeConverter converter(pInstance[i].getModel());

        playerShape = converter.createCapsule();

        // calculates inertia
        btScalar mass = 1;
        btVector3 inertia, inertia2;
        inertia = btVector3(0,0,0);
        playerShape->calculateLocalInertia(mass, inertia);

        //Create BtOgre MotionState (connects Ogre and Bullet).
    //    BtOgre::RigidBodyState *bodyState = new BtOgre::RigidBodyState(pInstance[2].getNode());
        playerBodyState = new BtOgre::RigidBodyState(pInstance[i].getNode());
//        playerBodyState.at(i) = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(10.0f,-13.5f,380.0f)));
        //Create the Body.
//        playerBody.at(i) = new btRigidBody(mass, playerBodyState.at(i), playerShape.at(i), inertia);
        playerBody = new btRigidBody(mass, playerBodyState, playerShape, inertia);
 //       playerBody->setActivationState(DISABLE_DEACTIVATION);

        pInstance[i].setPhysBody(playerBody);
//        world->addRigidBody(playerBody.at(i));
        if (i <= 4)
        {
            pInstance[i].getPhysBody()->setActivationState(DISABLE_SIMULATION);

//            world->addRigidBody(pInstance[i].getPhysBody(), COL_TEAM1, team1CollidesWith);
        	world->addRigidBody(pInstance[i].getPhysBody());
        }
        else if (i >= 5)
        {
            pInstance[i].getPhysBody()->setActivationState(DISABLE_SIMULATION);

//            world->addRigidBody(pInstance[i].getPhysBody(), COL_TEAM2, team2CollidesWith);
        	world->addRigidBody(pInstance[i].getPhysBody());

        }
        else
        {
        }
    }

    gameS->setPlayerInstance(pInstance);
    pInstance[0].getPhysBody()->translate(btVector3 (0,1,0));
//    playerShape.push_back(*shape);
}

void physicsEngine::setupCourtPhysics()
{
//    courtState *courtS = courtState::Instance();
    gameState *gameS = gameState::Instance();

    std::vector<courtState> cInstance = gameS->getCourtInstance();

    btScalar mass = 0;
    btVector3 inertia, inertia2;
    inertia = btVector3(0,0,0);


    //Create the ground shape.
    BtOgre::StaticMeshToShapeConverter converter(cInstance.at(0).getModel());
//    courtShape = converter.createTrimesh();
//    courtShape = converter.createBox();
    courtShape = new btStaticPlaneShape(btVector3(0,1,0),1);


    //Create MotionState (no need for BtOgre here, you can use it if you want to though).
    courtBodyState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,-25,0)));

    btRigidBody::btRigidBodyConstructionInfo info(mass,courtBodyState,courtShape,inertia); //motion state would actually be non-null in most real usages
    info.m_restitution = 1.0f;
    info.m_friction = 15.5f;

    //Create the Body.
//    courtBody = new btRigidBody(0, courtBodyState, courtShape, btVector3(0,0,0));
    courtBody = new btRigidBody(info);

//    world->addRigidBody(courtBody, COL_COURT, courtCollidesWith);
    world->addRigidBody(courtBody);
}

void physicsEngine::setupBasketballPhysics()
{
//    basketballs *bball = basketballs::Instance();
    gameState *gameS = gameState::Instance();

    std::vector<basketballs> bInstance = gameS->getBasketballInstance();
    btRigidBody *bballBody;

    //Create the basketball shape.
    BtOgre::StaticMeshToShapeConverter converter(bInstance.at(0).getModel());
    basketballShape = converter.createSphere();


    btScalar mass = 0.05f;
    btVector3 inertia, inertia2;
    inertia = btVector3(0,0,0);
    basketballShape->calculateLocalInertia(mass, inertia);

    basketballBodyState= new BtOgre::RigidBodyState(bInstance.at(0).getNode());

    btRigidBody::btRigidBodyConstructionInfo info(mass,basketballBodyState,basketballShape,inertia); //motion state would actually be non-null in most real usages
    info.m_restitution = 0.85f;
//    info.m_friction = 2.0f;

    //Create MotionState (no need for BtOgre here, you can use it if you want to though).
//    basketballBodyState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,0,0)));

    //Create BtOgre MotionState (connects Ogre and Bullet).

    //Create the Body.
//    bballBody = new btRigidBody(mass, basketballBodyState, basketballShape, inertia);
    bballBody = new btRigidBody(info);
//    bballBody->setActivationState(DISABLE_DEACTIVATION);
//    bballBody->setCollisionFlags(bballBody->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);
    bInstance[0].setPhysBody(bballBody);

//    world->addRigidBody(bInstance[0].getPhysBody(), COL_BBALL, bballCollidesWith);
    world->addRigidBody(bInstance[0].getPhysBody());

    gameS->setBasketballInstance(bInstance);
}

void physicsEngine::updateState()
{
	gameEngine *gameE = gameEngine::Instance();
	gameState *gameS = gameState::Instance();
    inputSystem *input = inputSystem::Instance();

    btScalar currentTime;
//    unsigned long loopChangeInTime;	// stores change in time.

    currentTime = gameE->getLoopTime().getMilliseconds();

    if (currentTime - oldTime >= 1000 && currentTime - oldTime <= 1200)
    {
    	changeInTime = currentTime - oldTime;
    	oldTime = currentTime;
    }
//    loopChangeInTime = gameE->getChangeInTime();

    String CIT = StringConverter::toString(changeInTime);

    //Update Bullet world. Don't forget the debugDrawWorld() part!
//    world->stepSimulation(evt.timeSinceLastFrame, 10);
//    playerBodyState.at(0)->setWorldTransForm(btTransform *transform)
//    playerBody.at(2)->translate( btVector3( 0.0f, 10.0f, 0.0f ) );
//    world->stepSimulation(changeInTime, 10);
    world->stepSimulation(1.f,1);
//    if (changeInTime >= 1000)
//    {
        Ogre::LogManager::getSingletonPtr()->logMessage("Physics changeInTime = " + CIT);
//		world->stepSimulation(changeInTime/1000, 1);
//		world->debugDrawWorld();

		if (!gameS->getTipOffComplete())
		{
	//    	if (!gameS->getBallTipped())
	//    	{
				tipOffCollisionCheck();
	//    	}
	//    	else
	//    	{

	//    	}
		}
//    }

    // FIX FOR SDL!!
    //Shows debug if F3 key down.
//    debugDraw->setDebugMode(input->getMKeyboard()->isKeyDown(OIS::KC_F3));
    debugDraw->step();
//exit(0);

}

void physicsEngine::tipOffCollisionCheck()	// checks whether team 1 or team 2's center has made contact with the ball
{
	gameState *gameS = gameState::Instance();

    std::vector<playerState> pInstance = gameS->getPlayerInstance();
    std::vector<basketballs> bInstance = gameS->getBasketballInstance();

	MyContactResultCallback tipOffResult;

	if (gameS->getBallTipped())
	{
//		exit(0);
		pairCollided = false;
		world->contactPairTest(bInstance[0].getPhysBody(), pInstance[gameS->getBallTippedToPlayer()].getPhysBody(), tipOffResult);
		if (pairCollided)
		{
			gameS->setPlayerWithBall(gameS->getBallTippedToPlayer());
    	    gameS->setTipOffComplete(true);

			exit(0);
		}
	}
	else
	{

	}
    // checks if player 4 touched the basketball
	if (!gameS->getBallTipped())
	{
		pairCollided = false;
		world->contactPairTest(bInstance[0].getPhysBody(), pInstance[4].getPhysBody(), tipOffResult);
		if (pairCollided)
		{
			gameS->setBallTipped(true);
			gameS->setBallTippedToPlayer(0);
			bInstance[0].getPhysBody()->forceActivationState(DISABLE_SIMULATION);
			bInstance[0].getPhysBody()->forceActivationState(DISABLE_DEACTIVATION);
			bInstance[0].getPhysBody()->applyForce(btVector3(-5.0f,-5.0f,0.0f),btVector3(10.0f,0.0f,0.0f));
			pInstance[4].getPhysBody()->forceActivationState(DISABLE_SIMULATION);
//			Ogre::LogManager::getSingletonPtr()->logMessage("Player tipped to = 0");
//			Ogre::LogManager::getSingletonPtr()->logMessage(Ogre::StringConverter::toString(gameS->getBallTipped()));
			//    	gameS->setTipOffComplete(true);
//         	exit(0);
		}
	}
	else
	{

	}


    // checks if player 9 touched the basketball
	if (!gameS->getBallTipped())
	{
		pairCollided = false;
		world->contactPairTest(bInstance[0].getPhysBody(), pInstance[9].getPhysBody(), tipOffResult);
		if (pairCollided)
		{
			bInstance[0].getPhysBody()->setActivationState(DISABLE_SIMULATION);

			gameS->setBallTipped(true);
			gameS->setBallTippedToPlayer(5);
			bInstance[0].getPhysBody()->forceActivationState(DISABLE_SIMULATION);
			Ogre::LogManager::getSingletonPtr()->logMessage("Player tipped to = 5");

	//    	gameS->setTipOffComplete(true);
//			exit(0);
		}
	}

	else
	{

	}

}
