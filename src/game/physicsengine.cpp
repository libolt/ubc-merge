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
#include "gameengine.h"
#include "gamestate.h"
#include "input.h"
#include "logging.h"
#include "players.h"
#include "playerstate.h"
#include "physicsengine.h"
#include "renderengine.h"
#include "comparison.h"


//physicsEngine* physicsEngine::pInstance = 0;
boost::shared_ptr<physicsEngine> physicsEngine::pInstance;


//physicsEngine* physicsEngine::Instance()
boost::shared_ptr<physicsEngine> physicsEngine::Instance()

{
    if (pInstance == 0)  // is it the first call?
    {
        //pInstance = new physicsEngine; // create sole instance
        boost::shared_ptr<physicsEngine> tInstance(new physicsEngine);
        pInstance = tInstance;
    }
    return pInstance; // address of sole instance
}


//-------------------------------------------------------------------------------------
physicsEngine::physicsEngine()
{
        //Bullet initialisation.
//      broadPhase = new btAxisSweep3(btVector3(-10000,-10000,-10000), btVector3(10000,10000,10000), 1024);
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

//    btCollisionShape *shape;
//    BtOgre::RigidBodyState *state;

    courtCollidesWith = COL_BBALL | COL_TEAM1 | COL_TEAM2;  // determines what the court collides with
    bballCollidesWith = COL_COURT; // | COL_TEAM1 | COL_TEAM2;  // determines what the basketball collides with
    team1CollidesWith = COL_COURT; // | COL_BBALL | COL_TEAM2;  // determines what team1 collides with
    team2CollidesWith = COL_COURT; // | COL_BBALL | COL_TEAM1;  // determiens what team2 collides with

    playerPhysicsSetup = false;
    basketballPhysicsSetup = false;
    courtPhysicsSetup = false;
    hoopPhysicsSetup = false;

    pairCollided = false;
    passCollision = false;

    beginShotPos = btVector3(0,0,0);
    beginShotDistance = btVector3(0,0,0);
    beginShotForce = btVector3(0,0,0);
    midShotPos = btVector3(0,0,0);
    endShotPos = btVector3(0,0,0);

    maxShotHeight = 0.0f;

    shotSet = false;
    shotComplete = false;
    maxShotHeightReached = false;
    forceToApplyXSet = false;
    beginShotPosSet = false;
    midShotPosSet = false;
    midShotPosReached = false;
    midShotXPosReached = false;
    endShotPosSet = false;
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

//    world->removeRigidBody(courtBody);
//    delete courtBody->getMotionState();
//    delete courtBody;
//    delete courtShape->getMeshInterface();
    delete courtShape;

    //Free Bullet stuff.
    //delete debugDraw;
    delete world;

    delete solver;
    delete dispatcher;
    delete collisionConfig;
    delete broadPhase;

}

bool physicsEngine::getPlayerPhysicsSetup() // retrieves the value of the playerPhysicsSetup variable
{
    return (playerPhysicsSetup);
}
void physicsEngine::setPlayerPhysicsSetup(bool setup)       // sets the value of the playerPhysicsSetup variable
{
    playerPhysicsSetup = setup;
}

bool physicsEngine::getBasketballlPhysicsSetup()    // retrieves the value of the playerPhysicsSetup variable
{
    return (basketballPhysicsSetup);
}
void physicsEngine::setBasketballPhysicsSetup(bool setup)   // sets the value of the playerPhysicsSetup variable
{
    basketballPhysicsSetup = setup;
}

bool physicsEngine::getCourtPhysicsSetup()  // retrieves the value of the courtPhysicsSetup variable
{
    return (courtPhysicsSetup);
}
void physicsEngine::setCourtPhysicsSetup(bool setup)    // sets the value of the courtPhysicsSetup variable
{
    courtPhysicsSetup = setup;
}

bool physicsEngine::getHoopPhysicsSetup()   // retrieves the value of the hoopPhysicsSetup variable
{
    return (hoopPhysicsSetup);
}
void physicsEngine::setHoopPhysicsSetup(bool setup) // sets the value of the hoopPhysicsSetup variable
{
    hoopPhysicsSetup = setup;
}

bool physicsEngine::getPairCollided()   // retrieves value of pairCollided variable
{
    return (pairCollided);
}
void physicsEngine::setPairCollided(bool collided)  // sets value of pairCollided variable
{
    pairCollided = collided;
}

bool physicsEngine::getPassCollision()  // retrieves the value of passCollision variable
{
    return(passCollision);
}
void physicsEngine::setPassCollision(bool collision)    // sets the value of passCollision variable
{
    passCollision = collision;
}
void physicsEngine::setupState(void)
{

    boost::shared_ptr<renderEngine> render = renderEngine::Instance();

    // Debug drawing!
    debugDraw = new BtOgre::DebugDrawer(render->getMSceneMgr()->getRootSceneNode(), world);
    world->setDebugDrawer(debugDraw);

    if (!playerPhysicsSetup)
    {
        if (setupPlayerPhysics()) // sets up physics state for players
        {
//            exit(0);
            playerPhysicsSetup = true;
        }
        else
        {
        }
    }
    else
    {
    }

    if (!courtPhysicsSetup)
    {
        if (setupCourtPhysics()) // sets up physics state for court
        {
            courtPhysicsSetup = true;
        }
        else
        {
        }
    }
    else
    {
    }

    if (!hoopPhysicsSetup)
    {
        if (setupHoopPhysics()) // sets up physics state for hoop
        {
            hoopPhysicsSetup = true;
        }
        else
        {
        }
    }
    else
    {
    }

    if (!basketballPhysicsSetup)
    {
        if (setupBasketballPhysics()) // sets up physics state for basketball
        {
            basketballPhysicsSetup = true;
        }
        else
        {
        }
    }
    else
    {
    }

}

bool physicsEngine::setupPlayerPhysics()
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    players *player = players::Instance();

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
        std::vector<int> activeID = teamInstance[x].getActivePlayerID();

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

bool physicsEngine::setupCourtPhysics()
{
//    courtState *courtS = courtState::Instance();
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();

    std::vector<courtState> courtInstance = gameS->getCourtInstance();
    btRigidBody *courtBody;
    btScalar mass = 0;
    btVector3 inertia, inertia2;
    inertia = btVector3(0,0,0);


    //Create the ground shape.
    BtOgre::StaticMeshToShapeConverter converter(courtInstance.at(0).getModel());
//    courtShape = converter.createTrimesh();
    courtShape = converter.createBox();
//    courtShape = new btStaticPlaneShape(btVector3(0,1,0),1);
//    courtShape->;
//s    courtShape->
    //Create MotionState (no need for BtOgre here, you can use it if you want to though).
//    courtBodyState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,-25,0)));
    courtBodyState = new BtOgre::RigidBodyState(courtInstance[0].getNode());
//    courtBodyState = new BtOgre::RigidBodyState(courtInstance.at(0).getNode());
    btRigidBody::btRigidBodyConstructionInfo info(mass,courtBodyState,courtShape,inertia); //motion state would actually be non-null in most real usages
    info.m_restitution = 1.0f;
    info.m_friction = 15.5f;


    //Create the Body.
//    courtBody = new btRigidBody(0, courtBodyState, courtShape, btVector3(0,0,0));
    courtBody = new btRigidBody(info);

    courtInstance[0].setPhysBody(courtBody);
    world->addRigidBody(courtInstance[0].getPhysBody(), COL_COURT, courtCollidesWith);
//    world->addRigidBody(courtBody);
//    courtInstance[0].getPhysBody()->setActivationState(ACTIVE_TAG);
               
    gameS->setCourtInstance(courtInstance);

    return true;
}

bool physicsEngine::setupHoopPhysics()
{
//    courtState *courtS = courtState::Instance();
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();

    std::vector<hoopState> hoopInstance = gameS->getHoopInstance();
    btRigidBody *hoopBody;
    btScalar mass = 0;
    btVector3 inertia, inertia2;
    inertia = btVector3(0,0,0);

    size_t x = 0;
    while (x<hoopInstance.size())
    {
        btCollisionShape *hoopShape;
        BtOgre::RigidBodyState *hoopBodyState;

        //Create the ground shape.
        BtOgre::StaticMeshToShapeConverter converter(hoopInstance.at(x).getModel());
    //    courtShape = converter.createTrimesh();
        hoopShape = converter.createBox();
    //    courtShape = new btStaticPlaneShape(btVector3(0,1,0),1);
    //    courtShape->;
    //s    courtShape->
        //Create MotionState (no need for BtOgre here, you can use it if you want to though).
    //    courtBodyState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,-25,0)));
        hoopBodyState = new BtOgre::RigidBodyState(hoopInstance[x].getNode());
    //    courtBodyState = new BtOgre::RigidBodyState(courtInstance.at(0).getNode());
        btRigidBody::btRigidBodyConstructionInfo info(mass,hoopBodyState,hoopShape,inertia); //motion state would actually be non-null in most real usages
        info.m_restitution = 1.0f;
        info.m_friction = 15.5f;


        //Create the Body.
    //    courtBody = new btRigidBody(0, courtBodyState, courtShape, btVector3(0,0,0));
        hoopBody = new btRigidBody(info);

        hoopInstance[x].setPhysBody(hoopBody);
    //    world->addRigiBody(courtInstance[0].getPhysBody(), COL_COURT, courtCollidesWith);
        world->addRigidBody(hoopBody, COL_HOOP, hoopCollidesWith);
        ++x;
    }
    gameS->setHoopInstance(hoopInstance);

    return (true);
}

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

void physicsEngine::updateState()
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //gameEngine *gameE = gameEngine::Instance();
    boost::shared_ptr<gameEngine> gameE = gameEngine::Instance();
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    //inputSystem *input = inputSystem::Instance();
    boost::shared_ptr<inputSystem> input = inputSystem::Instance();
//    teamState *teamS = teamState::Instance();

    comparison compare;
    
    int activeBBallInstance = gameS->getActiveBBallInstance();

    teamTypes teamWithBall = gameS->getTeamWithBall();
    int playerWithBall;
  logMsg("Updating Physics Engine State");
//    logMsg("teamWithBall = " + convert->toString(teamWithBall));
//    if (teamWithBall >=0)
//    {
        std::vector<teamState> teamInstance = gameS->getTeamInstance();
        std::vector <std::vector<playerState> > activePlayerInstance;
        std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();

        size_t z = 0;
        while (z < teamInstance.size())
        {
            activePlayerInstance.push_back(teamInstance[z].getActivePlayerInstance());
            ++z;
        }
//      exit(0);
//      std::vector<playerState> activePlayerInstance = teamInstance[teamWithBall].getPlayerInstance();
//      exit(0);
//      int playerWithBall = teamInstance[teamWithBall].getPlayerWithBall();


//      logMsg("ballTipped == " + convert->toString(gameS->getBallTipped()));
//      exit(0);

        //    if (changeInTime >= 1000)
    //    {
    //    Ogre::LogManager::getSingletonPtr()->logMessage("Physics changeInTime = " + CIT);
    //      world->stepSimulation(changeInTime/1000, 1);
    //      world->debugDrawWorld();

        if (!gameS->getTipOffComplete())    // checks if tip off has finishedd
        {
//          exit(0);
            logMsg("tipOff not complete!");
            if(gameS->getTeamInstancesCreated())
            {
                logMsg("team instances created!");
                tipOffCollisionCheck();
                logMsg("tipOff collision checked!");
//s                exit(0);
            }
            if (gameS->getBallTipped() && gameS->getBallTipForceApplied())
            {
                if (gameS->getBallTippedToTeam() == HOMETEAM)
                {
                    if (gameS->getBallTippedToPosition() != NONE)
                    {
                        //                  exit(0);
                        //      basketballInstance[activeBBallInstance].getPhysBody()->forceActivationState(ACTIVE_TAG);
                        //      basketballInstance[activeBBallInstance].getPhysBody()->applyForce(btVector3(1.20f, -1.60f, 0.0f),btVector3(0.0f,0.0f,0.0f));
                        basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(20, -5, 0));
                        //                  exit(0);
                        //      gameS->setBallTipForceApplied(true);

                    }
                    //          logMsg("player tipped to = " +toString(gameS->getBallTippedToPlayer()));
                }
                //          exit(0);
                else if (gameS->getBallTippedToTeam() == AWAYTEAM)
                {
                    if (gameS->getBallTippedToPosition() != NONE)
                    {
                        basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(-20, -5, 0));

                    }
                }
            }
            else
            {
            }

        }
//      else if (!activePlayerInstance[playerWithBall].getPassBall())
        else if (gameS->getTipOffComplete())
        {
            if (teamWithBall != NOTEAM)
            {
                z = 0;
                while (z < teamInstance.size())
                {
                    size_t y = 0;
                    while (y < activePlayerInstance[z].size())
                    {
                        btTransform transform = activePlayerInstance[z][y].getPhysBody()->getWorldTransform();
                        btVector3 physPos = transform.getOrigin();
                        Ogre::Vector3 courtPos = activePlayerInstance[z][y].getCourtPosition();
                        OpenSteer::Vec3 steerPos = activePlayerInstance[z][y].getSteer()->position();
                        logMsg("Team " +convert->toString(z) +" player " +convert->toString(y) +" pActivePhys == " +convert->toString(physPos));
                        logMsg("Team " +convert->toString(z) +" player " +convert->toString(y) +" pActiveCourt == " +convert->toString(courtPos));
                        logMsg("Team " +convert->toString(z) +" player " +convert->toString(y) +" pActiveSteer == " +convert->toString(steerPos));
                        /*if (activePlayerInstance[z][y].getCourtPositionChangedType() == NOCHANGE)
                        {
                            if (!compare.OgreVector3ToBTVector3(courtPos, physPos))
                            {
                                activePlayerInstance[z][y].setCourtPositionChanged(true);
                                activePlayerInstance[z][y].setCourtPositionChangedType(PHYSICSCHANGE);
                                //exit(0);
                            }
                        }*/
                        ++y;
                    }
                    ++z;
                }
    //          exit(0);
                if (teamInstance[teamWithBall].getPlayerWithBallDribbling()) // checks if the player with ball is dribbling and updates accordingly
                {
//                  exit(0);
//                  logMsg("Dribbling!!");
                    ballDribbling();
//                  logMsg("Human Player = " +convert->toString(teamInstance[1].getHumanPlayer()));

                }
/*              else if (!teamInstance[teamWithBall].getPlayerWithBallDribbling()) // checks if the player with ball is dribbling and updates accordingly
                {
                    exit(0);
                    cout << "dah" << endl;
                }*/
                else
                {
//                  logMsg("Not Dribbling");

                }
//              logMsg("A Team Has Ball");

           // activePlayerInstance = teamInstance[teamWithBall].getActivePlayerInstance();
            playerWithBall = teamInstance[teamWithBall].getPlayerWithBall();
            logMsg("Player with ball =====" +convert->toString(playerWithBall));
            size_t x = 0;
            size_t playerWithBallInstance = -1;
            while (x < activePlayerInstance[teamWithBall].size())
            {
                if (activePlayerInstance[teamWithBall][x].getPlayerID() == playerWithBall)
                {
                    playerWithBallInstance = x;
                    break;
                }
                ++x;
            }

            if (!activePlayerInstance[teamWithBall][playerWithBallInstance].getPassBall())
            {
                teamInstance[teamWithBall].setPlayerWithBallDribbling(true);
    //          basketballInstance[activeBBallInstance].getPhysBody()->forceActivationState(ACTIVE_TAG);
    //          basketballInstance[activeBBallInstance].getPhysBody()->applyForce(btVector3(-0.0f, -31.0f, 0.0f),btVector3(0.0f,0.0f,0.0f));
    //          basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(0,-10,0));
            }
            else if (activePlayerInstance[teamWithBall][playerWithBallInstance].getPassBall() && activePlayerInstance[teamWithBall][playerWithBallInstance].getPassCalculated())
            {
                passCollisionCheck();
            }
            else
            {
            }
        }
        else
        {
        }
//    }

            //Update Bullet world. Don't forget the debugDrawWorld() part!
        //    world->stepSimulation(evt.timeSinceLastFrame, 10);
        //    playerBodyState.at(0)->setWorldTransForm(btTransform *transform)
        //    playerBody.at(2)->translate( btVector3( 0.0f, 10.0f, 0.0f ) );
        //    world->stepSimulation(changeInTime, 10);

    //exit(0);

/*        for (unsigned int x=0;x<teamInstance.size();++x)    // saves changes made to the activePlayerInstance objects
        {
//          teamInstance[x].setActivePlayerInstance(activePlayerInstance);
            std::string X = convert->toString(x);
            std::string size = convert->toString(activePlayerInstance.size());
//          logMsg("Team " +X +" PlayerInstance Size = " +size);

        }
*/
        gameS->setTeamInstance(teamInstance);
    }
    updatePositions();  // updates the positions of game objects

}

void physicsEngine::updatePositions()  // updates thr position of objects
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //gameEngine *gameE = gameEngine::Instance();
    //boost::shared_ptr<gameEngine> gameE = gameEngine::Instance();
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    //inputSystem *input = inputSystem::Instance();
    //boost::shared_ptr<inputSystem> input = inputSystem::Instance();
//    teamState *teamS = teamState::Instance();

    comparison compare;
    
    int activeBBallInstance = gameS->getActiveBBallInstance();

    teamTypes teamWithBall = gameS->getTeamWithBall();
    int playerWithBall;

    std::vector<teamState> teamInstance = gameS->getTeamInstance();
    std::vector <std::vector<playerState> > activePlayerInstance;
    std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();

    // checks to see if player positions need updated
    size_t z = 0;
    while (z < teamInstance.size())
    {
        activePlayerInstance.push_back(teamInstance[z].getActivePlayerInstance());
        size_t y = 0;
        while (y < activePlayerInstance[z].size())
        {
            int humanInstance = -1;
            if (teamInstance[z].getHumanControlled())
            {
                logMsg("phys update human == " +convert->toString(teamInstance[z].getHumanPlayer()));
                humanInstance = teamInstance[z].getHumanPlayer();
                
            }
            if (y != humanInstance && !activePlayerInstance[z][y].getCourtPositionChanged())
            {
                btTransform transform = activePlayerInstance[z][y].getPhysBody()->getWorldTransform();
                btVector3 physPos = transform.getOrigin();
            
                Ogre::Vector3 courtPosition = activePlayerInstance[z][y].getCourtPosition();
                Ogre::Vector3 newCourtPosition;
                logMsg("comparing court position");
                if (!compare.OgreVector3ToBTVector3(courtPosition,physPos))
                {
                    newCourtPosition = compare.OgreVector3ToBTVector3Result(courtPosition,physPos);
                }
            
                logMsg("court position = " +convert->toString(courtPosition));
                logMsg("new court position = " +convert->toString(newCourtPosition));
                if (activePlayerInstance[z][y].getStartPosReached())
                {
                    if (newCourtPosition.x != 0 && newCourtPosition.y != 0 && newCourtPosition.z != 0)
                    {
                        activePlayerInstance[z][y].setCourtPositionChanged(true);
                        activePlayerInstance[z][y].setCourtPositionChangedType(PHYSICSCHANGE);
                        activePlayerInstance[z][y].setNewCourtPosition(newCourtPosition);
                    }
                }
            }
            ++y;
        }
        teamInstance[z].setActivePlayerInstance(activePlayerInstance[z]);
    ++z;
    }
    gameS->setTeamInstance(teamInstance);
    
}

void physicsEngine::stepWorld() // steps the world of the physics simulation
{
    //gameEngine *gameE = gameEngine::Instance();
    boost::shared_ptr<gameEngine> gameE = gameEngine::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();

    btScalar currentTime;
    btScalar fixedTimeStep;


    logMsg("Time");

    //    unsigned long loopChangeInTime;   // stores change in time.

    currentTime = gameE->getTimer().getLoopTimeMill().count();
    logMsg("Current time = " +convert->toString(currentTime));
    
    //    if (currentTime - oldTime >= 1000 && currentTime - oldTime <= 1200)
    //{
        changeInTime = (currentTime - oldTime) / 1000;
        oldTime = currentTime;
    //}
    fixedTimeStep = btScalar(1.) / btScalar(60.);
    //    loopChangeInTime = gameE->getChangeInTime();

    std::string CIT = convert->toString(changeInTime);
    std::string currTime = convert->toString(currentTime);

//  logMsg("Current Time = " + currTime);
    logMsg("Change In Time = " + CIT);

    world->stepSimulation(changeInTime, 1, fixedTimeStep);
    logMsg("crash at stepSimulation?");
//  logMsg("World->Step ");
    debugDraw->step();

}

void physicsEngine::tipOffCollisionCheck()  // checks whether team 1 or team 2's center has made contact with the ball
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();

    teamTypes ballTippedToTeam = gameS->getBallTippedToTeam();
    std::vector<teamState> teamInstance = gameS->getTeamInstance();

//    std::vector<playerState> teamOnePlayerInstance = teamInstance[0].getPlayerInstance();
//    std::vector<playerState> teamTwoPlayerInstance = teamInstance[1].getPlayerInstance();
    std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();
//    logMsg("Crash here?");

    int activeBBallInstance = gameS->getActiveBBallInstance();

    MyContactResultCallback tipOffResult;
//    logMsg("Crash here??");
    if (gameS->getBallTipped() && ballTippedToTeam != NOTEAM)     // if basketball has been tipped checks for collision between ball and player it was tipped to
    {
//      exit(0);
//      logMsg("Physics team ball tipped to = " +convert->toString(ballTippedToTeam));
        logMsg("ballTippedToTeam == " +convert->toString(ballTippedToTeam));

        std::vector<playerState> activePlayerInstance = teamInstance[ballTippedToTeam].getActivePlayerInstance();
//        exit(0);
//      logMsg("basketballInstance size = " +convert->toString(basketballInstance.size()));
//      logMsg("activePlayerInstance size = " + convert->toString(activePlayerInstance.size()));

        logMsg("basketballInstance z pos = " +convert->toString(basketballInstance[activeBBallInstance].getNode()->getPosition().z));
        logMsg("basketballInstance x pos = " +convert->toString(basketballInstance[activeBBallInstance].getNode()->getPosition().x));
        logMsg("team == " +convert->toString(ballTippedToTeam));
        logMsg("player == " +convert->toString(gameS->getBallTippedToPlayerID()));
        size_t ballTippedToPlayerID = gameS->getBallTippedToPlayerID();
        //size_t ballTippedToPlayerID = -1;
        playerPositions ballTippedToPosition = NONE;
        std::vector<int> activePlayerID = teamInstance[ballTippedToTeam].getActivePlayerID();
        
/*        while (x < activePlayerID.size())
        {
            if (activePlayerID[x] == ballTippedToPlayerID)
            {
                ballTippedToPlayer = x;
            }
            ++x;
        }
*/
        //logMsg("team " +convert->toString(ballTippedToTeam) +" activePlayerInstance z pos = " +convert->toString(activePlayerInstance[ballTippedToPlayer].getNode()->getPosition().z));
        //logMsg("team " +convert->toString(ballTippedToTeam) +" activePlayerInstance x pos = " +convert->toString(activePlayerInstance[ballTippedToPlayer].getNode()->getPosition().x));
        
        
/*      size_t playerWithBallID = gameS->getBallTippedToPlayer();  // teamInstance[ballTippedToTeam].getPlayerWithBall();
        
        size_t ballTippedToPlayer = -1;
        size_t x = 0;
        while (x < activePlayerInstance.size())
        {
            size_t y = 0;
            while (y < activePlayerID.size())
            {
                if (activePlayerID[y] == activePlayerInstance[x].getPlayerID())
                {
                    if (activePlayerInstance[x].getPlayerID() == gameS->getBallTippedToPlayer())
                    {
                        ballTippedToPlayer = x;
                    }
                }
                ++y;
            }
            ++x;
        }
        */
        logMsg("gameS->getBallTippedToPlayerID() == " +convert->toString(gameS->getBallTippedToPlayerID()));
//        logMsg("ballTippedToPlayer == " +convert->toString(ballTippedToPlayer));
        size_t x = 0;
        while (x < activePlayerInstance.size())
        {
            if (activePlayerInstance[x].getPlayerID() == ballTippedToPlayerID)
            {
                //exit(0);
                world->contactPairTest(basketballInstance[activeBBallInstance].getPhysBody(), activePlayerInstance[x].getPhysBody(), tipOffResult);
                break;
            }
            ++x;
        }
        
//        world->contactPairTest(basketballInstance[activeBBallInstance].getPhysBody(), activePlayerInstance[ballTippedToPlayer].getPhysBody(), tipOffResult);
//      exit(0);
        if (!tipOffResult.m_connected)
        {
        }
        else
        {
//                      exit(0);
            gameS->setBallTipForceApplied(false);
            //          basketballInstance[activeBBallInstance].getPhysBody()->applyForce(btVector3(-1.0f, 0.50f, 0.0f),btVector3(0.0f,0.0f,0.0f));
            //          basketballInstance[activeBBallInstance].getPhysBody()->forceActivationState(ISLAND_SLEEPING);
            basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(0, 0, 0));
           // exit(0);
            gameS->setTipOffComplete(true);
            gameS->setBallTipped(false);
            gameS->setTeamWithBall(ballTippedToTeam);
            
            logMsg("ballTippedToTeam ======>" + convert->toString(ballTippedToTeam));

            logMsg("ballTippedToPlayerID =======>" + convert->toString(gameS->getBallTippedToPlayerID()));
//          exit(0);

           // teamInstance[ballTippedToTeam].setPlayerWithBall(activePlayerInstance[gameS->getBallTippedToPlayer()].getPlayerID());
            teamInstance[ballTippedToTeam].setPlayerWithBall(gameS->getBallTippedToPlayerID());
            teamInstance[ballTippedToTeam].setHumanPlayer(gameS->getBallTippedToPlayerID());
            teamInstance[ballTippedToTeam].setPlayerWithBallDribbling(true);
            logMsg("gameS->getBallTippedToPlayer() = " +convert->toString(gameS->getBallTippedToPlayerID()));
            logMsg("playerWithBallTipped == " +convert->toString(teamInstance[ballTippedToTeam].getPlayerWithBall()));
            //exit(0);
            int activeDefensivePlayer = -1;
            switch (ballTippedToTeam)
            {
                case 0:
                    activeDefensivePlayer = teamInstance[1].getActivePlayerID()[0];
                    teamInstance[AWAYTEAM].setHumanPlayer(activeDefensivePlayer);
                    break;
                case 1:
                    activeDefensivePlayer = teamInstance[0].getActivePlayerID()[0];
                    teamInstance[HOMETEAM].setHumanPlayer(activeDefensivePlayer);
                    break;
                default:
                break;
            }
            //          gameS->setTeamInstance(teamInstance);

            int humanPlayer = teamInstance[ballTippedToTeam].getHumanPlayer();
            teamTypes teamWithBall = gameS->getBallTippedToTeam();
            logMsg("teamWithBall === " + convert->toString(teamWithBall));
            logMsg("playerWithBall === " + convert->toString(teamInstance[teamWithBall].getPlayerWithBall()));

            logMsg("human player tipped to = " + convert->toString(humanPlayer));
//          exit(0);
            gameS->setTeamInstance(teamInstance);

            //          exit(0);
        }

    }
    // checks if player 4 touched the basketball
    else if (!gameS->getBallTipped())
    {
        logMsg("Crash here???");
//        exit(0);
        size_t x = 0;
        while (x < teamInstance.size())
        {
            if (teamInstance[x].getPlayerInstancesCreated())
            {
                logMsg("X = " +convert->toString(x));

//              logMsg("Crash here????");

                logMsg("Ball not tipped");
                std::vector<playerState> activePlayerInstance = teamInstance[x].getActivePlayerInstance();
                logMsg("Crash here?????");
                logMsg("activePlayerInstance Size = " +convert->toString(activePlayerInstance.size()));

                int centerID = -1;
                int i = 0;
                std::vector<int> activeID = teamInstance[x].getActivePlayerID();

                while (i < activePlayerInstance.size()) // loops until the activePlayerInstance is found that is currently playing center
                {
/*                    logMsg("i = " +convert->toString(i));
                    logMsg("player ID = " +convert->toString(activePlayerInstance[i].getPlayerID()));
                    logMsg("player position = " +activePlayerInstance[i].getPosition());
                    logMsg("activeID[4] = " +convert->toString(activeID[4]));
*/
                    if (activePlayerInstance[i].getActivePosition())
                    {
                        centerID = i;
                        logMsg("centerID = " +convert->toString(centerID));
                        logMsg("PlayerName = " +activePlayerInstance[i].getPlayerName());
                        logMsg("ModelLoaded = " +convert->toString(activePlayerInstance[i].getModelLoaded()));
                    }
                    i++;
                }
                logMsg("centerID == " +convert->toString(centerID));
                if (!gameS->getBallTipped())
                {
                    world->contactPairTest(basketballInstance[activeBBallInstance].getPhysBody(), activePlayerInstance[centerID].getPhysBody(), tipOffResult);
                    logMsg("tipOffResult.m_connected = " +convert->toString(tipOffResult.m_connected));
                }
                bool test = false;
    //          if (tipOffResult.collision)
                if (!tipOffResult.m_connected)
                {
//                  exit(0);
                    /*
                    gameS->setBallTipped(true);
                    gameS->setBallTippedToTeam(x);
                    gameS->setBallTippedToPlayer(0);
                    gameS->setBallTipForceApplied(true);
    */



                    //          basketballInstance[activeBBallInstance].getPhysBody()->forceActivationState(ISLAND_SLEEPING);
        //          basketballInstance[activeBBallInstance].getPhysBody()->forceActivationState(DISABLE_DEACTIVATION);
        /*          for (int x=0;x<10;++x)
                    {
                        pInstance[x].getPhysBody()->forceActivationState(DISABLE_SIMULATION);
                    }
        */
        //          basketballInstance[activeBBallInstance].getPhysBody()->applyForce(btVector3(5.10f, .20f, 0.0f),btVector3(10.0f,0.0f,0.0f));
        //          logMsg("Player tipped to = 0");
                    logMsg("Ball Not Tipped");
                    //      gameS->setTipOffComplete(true);
    //              exit(0);
                }
                else if (tipOffResult.m_connected)
                {
//                  exit(0);
                    logMsg("Ball Tipped");
                    gameS->setBallTipped(true);
                    teamTypes currentTeam = NOTEAM;
                    switch (x)  // sets the appropriate team to tip the ball to.
                    {
                        case 0:
                            ballTippedToTeam = HOMETEAM;
                        break;
                        case 1:
                            ballTippedToTeam = AWAYTEAM;
                        break;
                        default:
                        break;
                    }

                    gameS->setBallTippedToTeam(ballTippedToTeam);
                    logMsg("Tipped X = " +convert->toString(x));
    //              exit(0);
                    i = 0;
                    /*while (i < activePlayerInstance.size()) // loops until the activePlayerInstance is found that is currently playing center
                    {
                        size_t j = 0;
                        while(j < activeID.size())
                        { 
                            if (activeID[j] == activePlayerInstance[i].getPlayerID())
                            {
                                if (activePlayerInstance[i].getPosition() == "PG")
                                {
                                    gameS->setBallTippedToPlayer(activeID[j]);
                                    logMsg("gameS->setBallTippedToPlayer(i) == " +convert->toString(gameS->getBallTippedToPlayer()));
                                }
                            }
                            ++j;
                        }
                        ++i;
                    }*/
                    logMsg("gameS->getBallTippedToTeam == " +convert->toString(gameS->getBallTippedToTeam()));
                   // logMsg("teamInstance[currentTeam.getTeamType == " +convert->toString(teamInstance[currentTeam].getTeamType()));
                    teamTypes ballTippedToTeam = gameS->getBallTippedToTeam();
                    //if (teamInstance[x].getTeamType() == gameS->getBallTippedToTeam())
                    //{
                        std::vector<int> activePlayerID = teamInstance[ballTippedToTeam].getActivePlayerID();
                        std::vector<playerState> activePlayerInstance = teamInstance[ballTippedToTeam].getActivePlayerInstance();
                        
                        gameS->setBallTippedToPosition(PG);
                        
                        size_t y = 0;
                        while (y < activePlayerInstance.size())
                        {
                            if (activePlayerInstance[y].getActivePosition() == gameS->getBallTippedToPosition())
                            {
                            //    gameS->set
                                gameS->setBallTippedToPlayerID(activePlayerInstance[y].getPlayerID());

                            }
                            ++y;
                        }
                        
                        logMsg("activeID[0] == " +convert->toString(activeID[0]));
                        logMsg("gameS->setBallTippedToPosition == " +convert->toString(gameS->getBallTippedToPosition()));
                        gameS->setBallTipForceApplied(true);
                    //}
//                  tipOffResult.m_connected = false;
                    gameS->setTeamInstance(teamInstance);

                }
            }
            else
            {

            }
            ++x;
        }
    }
    else
    {

    }



//  exit(0);
    gameS->setTeamInstance(teamInstance);
}

void physicsEngine::ballDribbling() // simulates basketball dribble
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();

//    std::vector<playerState> pInstance = gameS->getPlayerInstance();
    std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();
    std::vector<courtState> courtInstance = gameS->getCourtInstance();

    int activeBBallInstance = gameS->getActiveBBallInstance();

    MyContactResultCallback courtCollisionResult;

    Ogre::Vector3 bballPos = basketballInstance[activeBBallInstance].getNode()->getPosition();
    Ogre::Vector3 courtPos = courtInstance[0].getNode()->getPosition();

    if (gameS->getBballBounce() == 0 && bballPos[1] < courtPos[1] + 5)  // checks if the ball is set to bounce up and hasn't reached the max height
    {
        basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(0,10,0));
    }
    else
    {
        gameS->setBballBounce(1);   // sets the ball to bounce down
    }

    if (gameS->getBballBounce() == 1)       // checks if the ball is set bounce downward
    {
        basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(0,-10,0));
    }
    else
    {

    }

    pairCollided = false;
//  logMsg("basketballInstance size = " +convert->toString(basketballInstance.size()));
//  logMsg("courtInstance size = " +convert->toString(courtInstance.size()));

//  logMsg("basketballInstance position = " + convert->toString(basketballInstance[activeBBallInstance].getNode()->getPosition()));
//  logMsg("courtInstance position = " + convert->toString(courtInstance[0].getNode()->getPosition()));

    btRigidBody *bballPhysBody = basketballInstance[activeBBallInstance].getPhysBody();
    btRigidBody *courtPhysBody = courtInstance[0].getPhysBody();
//  bballPhysBody->checkCollideWith(courtPhysBody);
    world->contactPairTest(bballPhysBody, courtPhysBody, courtCollisionResult);
//    logMsg("court collision " +convert->toString(courtCollisionResult));
/*  int numManifolds = world->getDispatcher()->getNumManifolds();
    for (int i = 0; i<numManifolds; i++)
    {
        btPersistentManifold* contactManifold = world->getDispatcher()->getManifoldByIndexInternal(i);
//      btCollisionObject* obA = static_cast<btCollisionObject*>(contactManifold->getBody0());
//      btCollisionObject* obB = static_cast<btCollisionObject*>(contactManifold->getBody1());
        #if BT_BULLET_VERSION>=281
        btCollisionObject* obA = const_cast<btCollisionObject*>(contactManifold->getBody0());; // For newer Bullet versions
        btCollisionObject* obB = const_cast<btCollisionObject*>(contactManifold->getBody1()); // For newer Bullet versions
        #else
        btCollisionObject* obA = static_cast<btCollisionObject*>(contactManifold->getBody0()); // For older Bullet versions (original code)
        btCollisionObject* obB = static_cast<btCollisionObject*>(contactManifold->getBody1()); // For older Bullet versions (original code)
        #endif
        int numContacts = contactManifold->getNumContacts();
        for (int j = 0; j<numContacts; j++)
        {
            btManifoldPoint& pt = contactManifold->getContactPoint(j);
            if (pt.getDistance()<0.f)
            {
                const btVector3& ptA = pt.getPositionWorldOnA();
                const btVector3& ptB = pt.getPositionWorldOnB();
                const btVector3& normalOnB = pt.m_normalWorldOnB;
                // ZOMG A COLLISIONNNNNNNNNNN ...
                if ((btRigidBody*)obA == bballPhysBody || (btRigidBody*)obB == courtPhysBody)
                {
                    exit(0);
                    // myRigidBodyPtrA totally just collided with something ... if I care what then I have to code more
                }
            }
        }
    }*/
    int dee = 0;

    logMsg("basketball - court collision tested");
    if (courtCollisionResult.m_connected)
    {
//      gameS->setPlayerWithBall(gameS->getBallTippedToPlayer());
//      gameS->setBallTipForceApplied(false);
//          basketballInstance[activeBBallInstance].getPhysBody()->applyForce(btVector3(-1.0f, 0.50f, 0.0f),btVector3(0.0f,0.0f,0.0f));
//          basketballInstance[activeBBallInstance].getPhysBody()->forceActivationState(ISLAND_SLEEPING);
//      basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(0,10,0));
//      gameS->setTipOffComplete(true);
//          exit(0);
        gameS->setBballBounce(0);
    }
    else
    {
    }

}

void physicsEngine::passCollisionCheck()    // checks whether the ball has collided with the player being passed to
{
//  exit(0);
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();

    teamTypes teamWithBall = gameS->getTeamWithBall();
    std::vector<teamState>  teamInstance = gameS->getTeamInstance();
    std::vector<playerState> activePlayerInstance = teamInstance[teamWithBall].getActivePlayerInstance();
    std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();

    int activeBBallInstance = gameS->getActiveBBallInstance();

    int playerWithBall = teamInstance[teamWithBall].getPlayerWithBall();
    int passToPlayer = activePlayerInstance[playerWithBall].getPassToPlayer();
    MyContactResultCallback passCollisionResult;
    logMsg("Basketball Coords = " +convert->toString(basketballInstance[activeBBallInstance].getNode()->getPosition()));
    logMsg("Player to pass to = " +convert->toString(passToPlayer));
    logMsg("Player pass to Coords = " +convert->toString(activePlayerInstance[passToPlayer].getNode()->getPosition()));

    pairCollided = false;
    world->contactPairTest(basketballInstance[activeBBallInstance].getPhysBody(), activePlayerInstance[passToPlayer].getPhysBody(), passCollisionResult);
    if (!passCollisionResult.m_connected)
    {
        logMsg("No Pass Collision");

        passCollision = false;
    }
    else
    {
//      exit(0);
        logMsg("Pass Collision");
        passCollision = true;
    }
}

bool physicsEngine::playerJump(teamTypes teamType, int playerID)  // calculates and executes player jumping in the air
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();

    std::vector<courtState> courtInstance = gameS->getCourtInstance();
    std::vector<teamState> teamInstance = gameS->getTeamInstance();
    std::vector<playerState> activePlayerInstance = teamInstance[teamType].getActivePlayerInstance();
    std::vector<int> activePlayerID = teamInstance[teamType].getActivePlayerID();
    btVector3 playerJumpBeginPos;
    btVector3 playerJumpEndPos;
    size_t x = 0;
    size_t y = 0;
    while (x<activePlayerInstance.size())
    {
//        while (y<activePlayerID.size())
//        {
//        if (activePlayerInstance[x].getPlayerID() == activePlayerID[y])
        if (activePlayerInstance[x].getPlayerID() == playerID)
        {
            bool jumpSet = activePlayerInstance[x].getJumpSet();
            bool jumpComplete = activePlayerInstance[x].getJumpComplete();
            if (!jumpComplete)
            {
                if (!jumpSet)
                {
                    playerJumpBeginPos = BtOgre::Convert::toBullet(activePlayerInstance[x].getNode()->getPosition());
                    playerJumpEndPos = playerJumpBeginPos;
                    playerJumpEndPos.setY(playerJumpEndPos.getY() + 5);
                    jumpSet = true;
                }
                else
                {
                    playerJumpBeginPos = BtOgre::Convert::toBullet(activePlayerInstance[x].getJumpBeginPos());
                    playerJumpEndPos = BtOgre::Convert::toBullet(activePlayerInstance[x].getJumpEndPos());
                // activePlayerInstance[x].getPhysBody()->setLinearVelocity(btVector3(-35,0,0));
                    activePlayerInstance[x].getPhysBody()->forceActivationState(ACTIVE_TAG);
                    activePlayerInstance[x].getPhysBody()->translate(btVector3(0,0.5,0)/*, btVector3(-35,0,0)*/);
                }
                btTransform transform = activePlayerInstance[x].getPhysBody()->getWorldTransform();
                btVector3 playerCurrentPos = transform.getOrigin();
                if (playerCurrentPos.getY() >= playerJumpEndPos.getY())
                {
                    jumpComplete = true;
                }
            }
            else
            {
                btTransform courtTransform = courtInstance[0].getPhysBody()->getWorldTransform();
                btVector3 courtPos = courtTransform.getOrigin();
                btTransform playerTransform = activePlayerInstance[x].getPhysBody()->getWorldTransform();
                btVector3 playerPos = playerTransform.getOrigin();
                logMsg("playerPos.getY = " +convert->toString(playerPos.getY()));
                logMsg("courtPos.getY = " +convert->toString(courtPos.getY()));
                if (playerPos.getY() > courtPos.getY() + 3.0)
                {
                    activePlayerInstance[x].getPhysBody()->forceActivationState(ACTIVE_TAG);
                }
                else
                {
//                    exit(0);
                    activePlayerInstance[x].getPhysBody()->setLinearVelocity(btVector3(0,0,0));
                    activePlayerInstance[x].getPhysBody()->setActivationState(ISLAND_SLEEPING);
                    activePlayerInstance[x].setShootBlock(false);
                    jumpSet = false;
                    jumpComplete = false;
                }
//                activePlayerInstance[x].getPhysBody()->setGravity(btVector3(0,-9.8,0));
//                activePlayerInstance[x].getPhysBody()->applyGravity();
//                activePlayerInstance[x].getPhysBody()->setLinearVelocity(btVector3(0,-.5,0));
//                activePlayerInstance[x].setShootBlock(false);
 //               exit(0);
            }
            activePlayerInstance[x].setJumpSet(jumpSet);
            activePlayerInstance[x].setJumpComplete(jumpComplete);
            activePlayerInstance[x].setJumpBeginPos(BtOgre::Convert::toOgre(playerJumpBeginPos));
            activePlayerInstance[x].setJumpEndPos(BtOgre::Convert::toOgre(playerJumpEndPos));

             logMsg("JUMP!");
          //  exit(0);
        }
//            ++y;
//        }
        ++x;
    }
    teamInstance[teamType].setActivePlayerInstance(activePlayerInstance);
    gameS->setTeamInstance(teamInstance);
    gameS->getTeamInstance()[teamType].getActivePlayerInstance()[playerID].getPhysBody()->setLinearVelocity(btVector3(15,-15,0));
    return (true);
}

bool physicsEngine::shootBasketball(teamTypes teamType, int playerID)  // calculates and executes basketball being shot
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();

    comparison compare;
    std::vector<courtState> courtInstance = gameS->getCourtInstance();
    std::vector<hoopState> hoopInstance = gameS->getHoopInstance();
    std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();
    std::vector<teamState> teamInstance = gameS->getTeamInstance();
    std::vector<playerState> activePlayerInstance = teamInstance[teamType].getActivePlayerInstance();

    int activeBBallInstance = gameS->getActiveBBallInstance();

//    Ogre::Vector3 playerPos = activePlayerInstance[x].getNode()->getPosition();
//    Ogre::Vector3 basketballPos = basketballInstance[activeBBallInstance].getNode()->getPosition();

             
    size_t x = 0;
    while (x<activePlayerInstance.size())
    {
        
        if (activePlayerInstance[x].getPlayerID() == playerID)
        {
            shotSet = activePlayerInstance[x].getShotSet();
            shotComplete = activePlayerInstance[x].getShotComplete();
            if (!shotComplete)
            {
                int hoop = teamInstance[teamType].getHoop();
                logMsg("Hoop number = " +convert->toString(hoop));
                btTransform hoopTransform = hoopInstance[hoop].getPhysBody()->getWorldTransform();
                btVector3 hoopPos = hoopTransform.getOrigin();

                btTransform basketballTransform = basketballInstance[activeBBallInstance].getPhysBody()->getWorldTransform();
                btVector3 basketballPos = basketballTransform.getOrigin();

                btTransform playerTransform = activePlayerInstance[x].getPhysBody()->getWorldTransform();
                btVector3 playerPos = playerTransform.getOrigin();
                float hoopBasketballDistanceX = 0;
                float hoopBasketballDistanceY = 0;
                float hoopBasketballDistanceZ = 0;

                if (teamInstance[teamType].getPlayerWithBallDribbling())
                {
                    teamInstance[teamType].setPlayerWithBallDribbling(false);
                   // exit(0);
                    gameS->setTeamInstance(teamInstance);
                }       

                if (!shotSet)
                {
                    
                    if (!beginShotPosSet)
                    {
                        if (activePlayerInstance[x].getDirection() == RIGHT)
                        {
                            basketballPos.setX(playerPos.getX() + 3);
                            basketballPos.setY(playerPos.getY() + 5);
                            basketballPos.setZ(playerPos.getZ());
                        }
                        else if (activePlayerInstance[x].getDirection() == LEFT)
                        {
                            basketballPos.setX(playerPos.getX() - 3);
                            basketballPos.setY(playerPos.getY() + 5);
                            basketballPos.setZ(playerPos.getZ());

                        }
                        else if (activePlayerInstance[x].getDirection() == UP)
                        {
                            basketballPos.setX(playerPos.getX() - 3);
                            basketballPos.setY(playerPos.getY() + 5);
                            basketballPos.setZ(playerPos.getZ() + 3);

                        }
                        else if (activePlayerInstance[x].getDirection() == DOWN)
                        {
                            basketballPos.setX(playerPos.getX() - 3);
                            basketballPos.setY(playerPos.getY() + 5);
                            basketballPos.setZ(playerPos.getZ() - 3);

                        }
                        else
                        {
                        }
                        beginShotPos = basketballPos;
                        beginShotPosSet = true;
                        logMsg("beginShotPosSet");
                    }

                    // sets end position of the shot
                    if (!endShotPosSet)
                    {
                        if (hoopPos.getX() < 0)
                        {
                            endShotPos.setX(hoopPos.getX() - 35);
                        }
                        else
                        {
                            endShotPos.setX(hoopPos.getX());
                            float hoopPosX = hoopPos.getX();
                            logMsg("hoopPosX = " +convert->toString(hoopPosX));
                        }

                        endShotPos.setY(hoopPos.getY() + 5);
                        endShotPos.setZ(hoopPos.getZ() - 2);
                        endShotPos.setX(hoopPos.getX() - 5);
                        endShotPosSet = true;
                        logMsg("endShotPosSet");
                    }
                    // sets the midPoint of the shot
                    if (!midShotPosSet)
                    {
                        midShotPos.setY(endShotPos.getY() +8);
                      /*  if (midShotPos.getY() < 0)
                        {
                            midShotPos.setY(-1 * (midShotPos.getY()));
                        }*/
                        midShotPosSet = true;
                        logMsg("midShotPos y = " +convert->toString(midShotPos.getY()));
                        logMsg("midShotPosSet");
                    }

                    if (beginShotPosSet && midShotPosSet && endShotPosSet)
                    {
                        hoopBasketballDistanceX = endShotPos.getX() - basketballPos.getX();
                        hoopBasketballDistanceY = endShotPos.getY() - basketballPos.getY();
                        hoopBasketballDistanceZ = endShotPos.getZ() - basketballPos.getZ();
                        logMsg("X distance between hoop and basketball" +convert->toString(hoopBasketballDistanceX));
    //                    exit(0);
                        beginShotDistance.setX(hoopBasketballDistanceX);
                        beginShotDistance.setY(hoopBasketballDistanceY);
                        beginShotDistance.setZ(hoopBasketballDistanceZ);
//                        exit(0);

                        midShotPos.setX(beginShotDistance.getX()/2);
    //                    maxShotHeight = basketballPos.getY() + 15;
                        
                    }
                    shotSet = true;
                }
                else
                {
                //    exit(0);
                    
                }
                
                if (hoopBasketballDistanceX > -1 && hoopBasketballDistanceX < 1 && shotSet)
                {
                    shotComplete = true;
                    logMsg("hoopBasketballDistanceX = " +convert->toString(hoopBasketballDistanceX));
//                    exit(0);
                }
            }
            else
            {
                if ( shotSet)
                {
                    float hoopBasketballDistanceX = 0;
                    float hoopBasketballDistanceZ = 0;
                    float beginXPoint = 0;
                    float midXPoint = 0;
                    float endXPoint = 0;
                    float basketballMidXDistance = 0;
                    float force = 0;
                    float yForce = 0;
                    float zForce = 0;
                    float maxForce = 0;
                    float maxYForce = 1750;
                    float maxZForce = 1700;
                    btVector3 hoopDimMin;
                    btVector3 hoopDimMax;
                    float hoopXMin = 0;
                    float hoopXMax = 0;
                    float vecX =  36*(cos(138));
                    int hoop = teamInstance[teamType].getHoop();
                    hoopInstance[hoop].getPhysBody()->getAabb(hoopDimMin,hoopDimMax);
                    hoopXMin = hoopDimMin.getX();
                    hoopXMax = hoopDimMax.getX();
                    logMsg("hoop dimensions XMin = " +convert->toString(hoopXMin) +" XMax = " +convert->toString(hoopXMax));
                    btTransform basketballTransform = basketballInstance[activeBBallInstance].getPhysBody()->getWorldTransform();
                    btVector3 basketballPos = basketballTransform.getOrigin();
                    beginXPoint = beginShotPos.getX();
                    midXPoint = beginShotPos.getX() + ((endShotPos.getX() - beginShotPos.getX())/2);
                    endXPoint = endShotPos.getX();
                    hoopBasketballDistanceX = endShotPos.getX() - basketballPos.getX();
                    hoopBasketballDistanceZ = endShotPos.getZ() - basketballPos.getZ();
                    basketballMidXDistance = midXPoint - basketballPos.getX();
                    // if (hoopBasketballDistanceX > 0)
                    maxForce = beginShotDistance.getX()*10;
                    if (basketballMidXDistance > 0)
                    {
                        //yForce = ((maxYForce / 50) *(100 - hoopBasketballDistanceX))*3.5;
                        //yForce = ((maxYForce / 50) *(midXPoint))*(hoopBasketballDistanceX/1.0);
                        //yForce = (beginShotDistance.getX())/2.0;
                        force = hoopBasketballDistanceX*(100 - hoopBasketballDistanceX);
                        //yForce = force/1.5;
                        yForce = maxYForce*(hoopBasketballDistanceX/beginShotDistance.getX());
                    }
                    else
                    {
                        
                        force = hoopBasketballDistanceX*(100 - hoopBasketballDistanceX);
                        //yForce = force/1.5;
                        //yForce = force/2;
                        yForce = maxYForce*(hoopBasketballDistanceX/beginShotDistance.getX());

                    //    exit(0);
                      //  yForce = -20;
                    }
                    if (hoopBasketballDistanceZ > 1)
                    {
                        zForce = maxZForce*(hoopBasketballDistanceZ/beginShotDistance.getZ());
                    }
                    else if (hoopBasketballDistanceZ < 1)
                    {
                        zForce = (maxZForce*(hoopBasketballDistanceZ/beginShotDistance.getZ()))*(-1);
                    }
                    else
                    {
                        zForce = 0;
                    }
                    logMsg("hoopBasketballDistanceX = " +convert->toString(hoopBasketballDistanceX));
                    logMsg("hoopBasketballDistanceZ = " +convert->toString(hoopBasketballDistanceZ));
                    logMsg("beginShotDistance.getX() = " +convert->toString(beginShotDistance.getX()));
                    logMsg("beginShotDistance.getZ() = " +convert->toString(beginShotDistance.getZ()));
                    logMsg("yDistanceForce = " +convert->toString(yForce));
                    logMsg("zDistanceForce = " +convert->toString(zForce));
                    logMsg("beginXPointDistance = " +convert->toString(beginXPoint));
                    logMsg("midXPointDistance = " +convert->toString(midXPoint));
                    logMsg("endXPointDistance = " +convert->toString(endXPoint));
                    logMsg("basketballMidXDistance = " +convert->toString(basketballMidXDistance));
                    logMsg("vecX = " +convert->toString(vecX));
                    logMsg("forceDistance = " +convert->toString(force));


                    
                    forceToApply.setX(30);
                    //basketballInstance[activeBBallInstance].getPhysBody()->applyForce(forceToApply,btVector3(1,1,1));
                  //  basketballInstance[activeBBallInstance].getPhysBody()->applyForce(btVector3(beginShotDistance.getX()*2.5,yForce,0.0),btVector3(1,1,1));
                   
                    basketballInstance[activeBBallInstance].getPhysBody()->applyForce(btVector3(force,yForce,zForce),btVector3(1,1,1));
                    
                  //basketballInstance[activeBBallInstance].getPhysBody()-> setAngularVelocity(btVector3(3.0,5.0,0));
                    basketballInstance[activeBBallInstance].getPhysBody()->setGravity(btVector3(-9.8,0,0));
                    basketballInstance[activeBBallInstance].getPhysBody()->applyGravity();
                    logMsg("bballForce");
                    logMsg("player dribbling == " +convert->toString(teamInstance[teamType].getPlayerWithBallDribbling()));

                }
            }

           activePlayerInstance[x].setShotSet(shotSet);
           activePlayerInstance[x].setShotComplete(shotComplete);
        }
        
        ++x;
    }
    logMsg("playerdribble = " +convert->toString(teamInstance[teamType].getPlayerWithBallDribbling()));
    teamInstance[teamType].setActivePlayerInstance(activePlayerInstance);
    gameS->setTeamInstance(teamInstance);
   // gameS->getTeamInstance()[teamType].getPlayerInstance()[playerID].getPhysBody()->setLinearVelocity(btVector3(15,-15,0));
  //  exit(0);
    gameS->setBasketballInstance(basketballInstance);
    return (true);
}

