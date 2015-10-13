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

#include "physicsengine.h"
#include "gamestate.h"

bool physicsEngine::setupBasketballPhysics()
{
//    basketballs *bball = basketballs::Instance();
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();

    std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();
    int activeBBallInstance = gameS->getActiveBBallInstance();

    btRigidBody *bballBody;

    //Create the basketball shape.
    BtOgre::StaticMeshToShapeConverter converter(basketballInstance.at(0).getModel());
    basketballShape = converter.createSphere();


    btScalar mass = 0.62f;
    btVector3 inertia, inertia2;
    inertia = btVector3(0,0,0);
    basketballShape->calculateLocalInertia(mass, inertia);

    basketballBodyState = new BtOgre::RigidBodyState(basketballInstance.at(0).getNode());

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
    basketballInstance[activeBBallInstance].setPhysBody(bballBody);

    world->addRigidBody(basketballInstance[activeBBallInstance].getPhysBody(), COL_BBALL, bballCollidesWith);
//    world->addRigidBody(basketballInstance[activeBBallInstance].getPhysBody());

    gameS->setBasketballInstance(basketballInstance);

    return true;
}
