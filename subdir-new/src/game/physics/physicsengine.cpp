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
#include "playerstate.h"
#include "physicsengine.h"
#include "renderengine.h"
#include "comparison.h"
#include "jumpballs.h"


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
//    bballCollidesWith = COL_COURT; // | COL_TEAM1 | COL_TEAM2;  // determines what the basketball collides with
    team1CollidesWith = COL_COURT; // | COL_BBALL | COL_TEAM2;  // determines what team1 collides with
    team2CollidesWith = COL_COURT; // | COL_BBALL | COL_TEAM1;  // determiens what team2 collides with

    basketballPhysicsSetup = false;
    courtPhysicsSetup = false;
    hoopPhysicsSetup = false;

    pairCollided = false;
    passCollision = false;

    basketballVelocitySet = false;
    basketballVelocity = btVector3(0,0,0);

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

btVector3 physicsEngine::getBasketballVelocity()  // retrieves the value of basketballVelocity
{
    return (basketballVelocity);
}
void physicsEngine::setBasketballVelocity(const btVector3 &set)  // sets the value of basketballVelocity
{
    basketballVelocity = set;
}


bool physicsEngine::getBasketballVelocitySet()  // retrieves the value of basketballVelocitySet
{
    return (true);
}

void physicsEngine::setBasketballVelocitySet(bool set)  // sets the value of basketballVelocitySet
{
    basketballVelocitySet = set;
}

btDynamicsWorld *physicsEngine::getWorld()  // retrieves the value of world
{
    return (world);
}
void physicsEngine::setWorld(btDynamicsWorld *set)  // sets the value of world
{
    world = set;
}

size_t physicsEngine::getTeam1CollidesWith()  // retrieves the value of team1CollidesWith
{
    return (team1CollidesWith);
}
void physicsEngine::setTeam1CollidesWith(size_t set) // sets the vslue of team1CollidesWith
{
    team1CollidesWith = set;
}

size_t physicsEngine::getTeam2CollidesWith()  // retrieves the value of team2CollidesWith
{
    return (team2CollidesWith);
}
void physicsEngine::setTeam2CollidesWith(size_t set) // k the vslue of team2CollidesWith
{
    team2CollidesWith = set;
}

void physicsEngine::setupState(void)
{

    boost::shared_ptr<renderEngine> render = renderEngine::Instance();

    // Debug drawing!
    debugDraw = new BtOgre::DebugDrawer(render->getMSceneMgr()->getRootSceneNode(), world);
    world->setDebugDrawer(debugDraw);

/*    if (!playerPhysicsSetup)
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
    */
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

/*    if (!basketballPhysicsSetup)
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
*/

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
    
    size_t activeBBallInstance = gameS->getActiveBBallInstance();

    jumpBalls jumpBall = gameS->getJumpBall();  // gets the jumpBall instance

    teamTypes teamWithBall = gameS->getTeamWithBall();
    size_t playerWithBallID;
    logMsg("Updating Physics Engine State");

    std::vector<teamState> teamInstance = gameS->getTeamInstance();
    std::vector <std::vector<playerState> > activePlayerInstance;
    std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();

//    exit(0);
    if (gameS->getBasketballInstancesCreated())
    {
//        exit(0);
        basketballInstance[activeBBallInstance].getPhysics().updateState();
    }
    else
    {
    }

    size_t z = 0;
    while (z < teamInstance.size())
    {
        activePlayerInstance.push_back(teamInstance[z].getActivePlayerInstance());
        ++z;
    }

/*    if (jumpBall.getExecuteJumpBall())    // checks if jump ball needs to be executed
    {
        logMsg("physics jump ball execution!");
//        exit(0);
        if (executeJumpBall())  // executes jump ball code until it returns true
        {
           exit(0);
            jumpBall.setExecuteJumpBall(false);
            gameS->setJumpBall(jumpBall);
        }            
    }
*/

/*    else //if (!jumpBall.getExecuteJumpBall())
    {
*/
        if (teamWithBall != NOTEAM)
        {
            logMsg("physics teamWithBall  == " +convert->toString(teamWithBall));
            //exit(0);
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
                    if (activePlayerInstance[z][y].getCourtPositionChangedType() == NOCHANGE)
                    {
                        if (!compare.OgreVector3ToBTVector3(courtPos, physPos))
                        {
                            activePlayerInstance[z][y].setCourtPositionChanged(true);
                            activePlayerInstance[z][y].setCourtPositionChangedType(PHYSICSCHANGE);
                            //exit(0);
                        }
                    }
                    ++y;
                }
                ++z;
            }

    //      exit(0);
            if (teamInstance[teamWithBall].getPlayerWithBallDribbling()) // checks if the player with ball is dribbling and updates accordingly
            {
//              exit(0);
//              logMsg("Dribbling!!");
                ballDribbling();
//              logMsg("Human Player = " +convert->toString(teamInstance[1].getHumanPlayer()));

            }
/*          else if (!teamInstance[teamWithBall].getPlayerWithBallDribbling()) // checks if the player with ball is dribbling and updates accordingly
            {
                exit(0);
                cout << "dah" << endl;
            }*/
            else
            {
//              logMsg("Not Dribbling");
            }
//              logMsg("A Team Has Ball");

           // activePlayerInstance = teamInstance[teamWithBall].getActivePlayerInstance();
            playerWithBallID = teamInstance[teamWithBall].getPlayerWithBallID();
            logMsg("Player with ball ID ==" +convert->toString(playerWithBallID));
            size_t x = 0;
            size_t playerWithBallInstance = -1;
            while (x < activePlayerInstance[teamWithBall].size())
            {
                if (activePlayerInstance[teamWithBall][x].getPlayerID() == playerWithBallID)
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
            logMsg("execJump teamWithBall == "+convert->toString(teamWithBall));
        }

/*        for (unsigned int x=0;x<teamInstance.size();++x)    // saves changes made to the activePlayerInstance objects
        {
//          teamInstance[x].setActivePlayerInstance(activePlayerInstance);
            std::string X = convert->toString(x);
            std::string size = convert->toString(activePlayerInstance.size());
//          logMsg("Team " +X +" PlayerInstance Size = " +size);

        }
*/
        gameS->setTeamInstance(teamInstance);
//    }

    updatePositions();  // updates the positions of game objects

}

void physicsEngine::updatePositions()  // updates thr position of objects
{
    updateBasketballPosition();  // updates the position of the basketball on the court
    updatePlayerPositions();  // updates the position of the players on the court
}

void physicsEngine::updateBasketballPosition()  // updates the position of basketball object(s)
{
    boost::shared_ptr<gameState> gameS = gameState::Instance();

    size_t activeBBallInstance = gameS->getActiveBBallInstance();
    std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();

    if (basketballVelocitySet)
    {
//        exit(0);
        basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(basketballVelocity);
    }
    else
    {
//        basketballInstance[activeBBallInstance].getPhysBody()->setLinearVelocity(btVector3(0,0,0));

    }
}

void physicsEngine::updatePlayerPositions()  // updates the position of player objecgts
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
  int numManifolds = world->getDispatcher()->getNumManifolds();
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
                    logMsg("ball collided with court!");
                   // exit(0);
                    // myRigidBodyPtrA totally just collided with something ... if I care what then I have to code more
                }
            }
        }
    }
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


bool physicsEngine::collisionCheck(btRigidBody *objectA, btRigidBody *objectB)  // tests whther or not two objects have collided
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    MyContactResultCallback collisionResult;

    world->contactPairTest(objectA, objectB, collisionResult);
    logMsg("collisionResult = " +convert->toString(collisionResult.m_connected));
    if (collisionResult.m_connected)
    {
        logMsg("Collided!");
        return (true);
    }
    return (false);
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

    size_t playerWithBallInstance = teamInstance[teamWithBall].getPlayerWithBallInstance();
    size_t passToPlayer = activePlayerInstance[playerWithBallInstance].getPassToPlayer();
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
    std::vector<size_t> activePlayerID = teamInstance[teamType].getActivePlayerID();
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

