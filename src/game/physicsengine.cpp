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
	    broadPhase = new btAxisSweep3(btVector3(-10000,-10000,-10000), btVector3(10000,10000,10000), 1024);
	    collisionConfig = new btDefaultCollisionConfiguration();
	    dispatcher = new btCollisionDispatcher(collisionConfig);
	    solver = new btSequentialImpulseConstraintSolver();

	    world = new btDiscreteDynamicsWorld(dispatcher, broadPhase, solver, collisionConfig);
        world->setGravity(btVector3(0,-9.8,0));

    //FIXME: Hack to set total number of players for physics to 10, set this to be dynamic
    btRigidBody *body;
    btCollisionShape *shape;
    BtOgre::RigidBodyState *state;
//    btDefaultMotionState *state;
    for (int i=0; i<10; ++i)
    {
        playerBody.push_back(body);
        playerBodyState.push_back(state);
//        playerShape.push_back(new btCollisionShape);
        playerShape.push_back(shape);
    }
//    playerShape = new btCollisionShape[10];
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
    delete courtShape->getMeshInterface();
    delete courtShape;

    //Free Bullet stuff.
    delete debugDraw;
    delete world;

    delete solver;
    delete dispatcher;
    delete collisionConfig;
    delete broadPhase;

}

void physicsEngine::setupState(void)
{

    renderEngine *render = renderEngine::Instance();

    // Debug drawing!
    debugDraw = new BtOgre::DebugDrawer(render->getMSceneMgr()->getRootSceneNode(), world);
    world->setDebugDrawer(debugDraw);



}

void physicsEngine::updateState(float changeInTime)
{
    inputSystem *input = inputSystem::Instance();

    String CIT = StringConverter::toString(changeInTime);

    Ogre::LogManager::getSingletonPtr()->logMessage("Physics changeInTime = " + CIT);
    //Update Bullet world. Don't forget the debugDrawWorld() part!
//    world->stepSimulation(evt.timeSinceLastFrame, 10);
//    playerBodyState.at(0)->setWorldTransForm(btTransform *transform)
    world->stepSimulation(changeInTime, 10);
    world->debugDrawWorld();

    //Shows debug if F3 key down.
    debugDraw->setDebugMode(input->getMKeyboard()->isKeyDown(OIS::KC_F3));
    debugDraw->step();
exit(0);

}

void physicsEngine::setupPlayerPhysics()
{
//   exit(0);
    gameState *gameS = gameState::Instance();
    players *player = players::Instance();

    std::vector<playerState> pInstance = gameS->getPlayerInstance();

    // loops through physics objects for all players
    for (int i=0; i<10; ++i)
    {

        // create shape
        BtOgre::StaticMeshToShapeConverter converter(pInstance[i].getModel());
        playerShape.at(i) = converter.createSphere();

        // calculates inertia
        btScalar mass = 5;
        btVector3 inertia, inertia2;
        playerShape.at(i)->calculateLocalInertia(mass, inertia);

        //Create BtOgre MotionState (connects Ogre and Bullet).
    //    BtOgre::RigidBodyState *bodyState = new BtOgre::RigidBodyState(pInstance[2].getNode());
        playerBodyState.at(i) = new BtOgre::RigidBodyState(pInstance[i].getNode());
//        playerBodyState.at(i) = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,0,0)));
        //Create the Body.
        playerBody.at(i) = new btRigidBody(mass, playerBodyState.at(i), playerShape.at(i), inertia);

        world->addRigidBody(playerBody.at(i));

    }


//    playerShape.push_back(*shape);
}

void physicsEngine::setupCourtPhysics()
{
//    courtState *courtS = courtState::Instance();
    gameState *gameS = gameState::Instance();

    std::vector<courtState> cInstance = gameS->getCourtInstance();

    //Create the ground shape.
    BtOgre::StaticMeshToShapeConverter converter(cInstance.at(0).getModel());
    courtShape = converter.createTrimesh();

    //Create MotionState (no need for BtOgre here, you can use it if you want to though).
    courtBodyState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,0,0)));

    //Create the Body.
    courtBody = new btRigidBody(0, courtBodyState, courtShape, btVector3(0,0,0));
    world->addRigidBody(courtBody);

}

void physicsEngine::setupBasketballPhysics()
{
//    basketballs *bball = basketballs::Instance();
    gameState *gameS = gameState::Instance();

    std::vector<basketballs> bInstance = gameS->getBasketballInstance();

    //Create the ground shape.
    BtOgre::StaticMeshToShapeConverter converter(bInstance.at(0).getModel());
    basketballShape = converter.createTrimesh();

/*
    btScalar mass = 5;
    btVector3 inertia, inertia2;
    basketballShape->calculateLocalInertia(mass, inertia);
*/

    //Create MotionState (no need for BtOgre here, you can use it if you want to though).
//    basketballBodyState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,0,0)));

    //Create BtOgre MotionState (connects Ogre and Bullet).
    basketballBodyState= new BtOgre::RigidBodyState(bInstance.at(0).getNode());

    //Create the Body.
    basketballBody = new btRigidBody(0, basketballBodyState, basketballShape, btVector3(0,0,0));
    world->addRigidBody(basketballBody);

}
