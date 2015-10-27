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

#include "conversion.h"
#include "gamestate.h"
#include "physicsengine.h"
#include "logging.h"

playerPhysics::playerPhysics()  // constructor
{
    
}

bool playerPhysics::setupState()  // sets up state of player physics
{
    return (false);
}

void playerPhysics::updateState()  // updates the state of player physics
{
    if (!physicsSetup)
    {
        if (setupPhysics()) // sets up physics state for players
        {
//            exit(0);
            physicsSetup = true;
        }
        else
        {
        }
    }
    else
    {
    }
}

bool playerPhysics::setupPhysics()  // sets up playerPhysics
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();

    std::vector<teamState> teamInstance = gameS->getTeamInstance();

    for (size_t x=0; x<teamInstance.size();++x)
    {
        std::vector<playerState> activePlayerInstance = teamInstance[x].getActivePlayerInstance();

        btRigidBody *playerBody;
        btCollisionShape *playerShape;
        BtOgre::RigidBodyState *playerBodyState;

        logMsg("activePlayerInstance.size = " +convert->toString(activePlayerInstance.size()));

        // loops through physics objects for all players
        size_t i = 0;
        size_t j = 0;
        std::vector<size_t> activeID = teamInstance[x].getActivePlayerID();

//      for (size_t i=0; i<activePlayerInstance.size(); ++i)
        while (i<activePlayerInstance.size())
        {
            logMsg("Converting Mesh to Shape");
//                    exit(0);
            // create shape
            logMsg("Converting " +activePlayerInstance[i].getPlayerName() +"'s Mesh");
            BtOgre::StaticMeshToShapeConverter converter(activePlayerInstance[i].getModel());

            logMsg("Creating capsule");
            playerShape = converter.createCapsule();

            // calculates inertia
            btScalar mass = 1;
            btVector3 inertia, inertia2;
            inertia = btVector3(0,0,0);
            logMsg("Calculating local inertia");
            playerShape->calculateLocalInertia(mass, inertia);

            //Create BtOgre MotionState (connects Ogre and Bullet).
        //    BtOgre::RigidBodyState *bodyState = new BtOgre::RigidBodyState(pInstance[2].getNode());

            logMsg("Creating Body State");
            playerBodyState = new BtOgre::RigidBodyState(activePlayerInstance[i].getNode());
//        playerBodyState.at(i) = new btDefaultMotionState(btform(btQuaternion(0,0,0,1),btVector3(10.0f,-13.5f,380.0f)));
            //Create the Body.
    //        playerBody.at(i) = new btRigidBody(mass, playerBodyState.at(i), playerShape.at(i), inertia);
            logMsg("Creating Rigid Body");
            playerBody = new btRigidBody(mass, playerBodyState, playerShape, inertia);
     //       playerBody->setActivationState(DISABLE_DEACTIVATION);

            logMsg("Setting PhysBody");
            activePlayerInstance[i].setPhysBody(playerBody);
    //        world->addRigidBody(playerBody.at(i));
            if (x == 0)
            {
                logMsg("Setting Team 0 Player  Activation State");
                //activePlayerInstance[i].getPhysBody()->setActivationState(DISABLE_SIMULATION);
                logMsg("team = " + convert->toString(x));

                logMsg("Adding Rigid Body to world");
                world->addRigidBody(activePlayerInstance[i].getPhysBody(), COL_TEAM1, team1CollidesWith);
    //          world->addRigidBody(pInstance[i].getPhysBody());
            }
            else if (x == 1)
            {
                logMsg("Setting Team 1 Player  Activation State");
             //   activePlayerInstance[i].getPhysBody()->setActivationState(DISABLE_SIMULATION);
                logMsg("team = " + convert->toString(x));

                logMsg("Adding Rigid Body to world");
                world->addRigidBody(activePlayerInstance[i].getPhysBody(), COL_TEAM2, team2CollidesWith);
    //          world->addRigidBody(pInstance[i].getPhysBody());

            }
            else
            {
            }
            i++;
        }
//        exit(0);
        teamInstance[x].setActivePlayerInstance(activePlayerInstance);
    }
//  activePlayerInstance[0].getPhysBody()->translate(btVector3 (0,1,0));
//    playerShape.push_back(*shape);
    for (int x=0;x<2; ++x)
    {
        std::vector<playerState> activePlayerInstance = teamInstance[x].getActivePlayerInstance();

        logMsg("activePlayerInstance.size = " + convert->toString(activePlayerInstance.size()));
    }
    gameS->setTeamInstance(teamInstance);   // stores all the changes to the teamInstance
//    exit(0);
return true;
}
