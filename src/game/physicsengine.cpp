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

//    btCollisionShape *shape;
//    BtOgre::RigidBodyState *state;

	courtCollidesWith = COL_BBALL | COL_TEAM1 | COL_TEAM2;	// determines what the court collides with
    bballCollidesWith = COL_COURT; // | COL_TEAM1 | COL_TEAM2;	// determines what the basketball collides with
    team1CollidesWith = COL_COURT; // | COL_BBALL | COL_TEAM2;	// determines what team1 collides with
    team2CollidesWith = COL_COURT; // | COL_BBALL | COL_TEAM1;	// determiens what team2 collides with

    playerPhysicsSetup = false;
    basketballPhysicsSetup = false;
    courtPhysicsSetup = false;

    pairCollided = false;
    passCollision = false;

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
    delete debugDraw;
    delete world;

    delete solver;
    delete dispatcher;
    delete collisionConfig;
    delete broadPhase;

}

bool physicsEngine::getPlayerPhysicsSetup()	// retrieves the value of the playerPhysicsSetup variable
{
	return (playerPhysicsSetup);
}
void physicsEngine::setPlayerPhysicsSetup(bool setup)		// sets the value of the playerPhysicsSetup variable
{
	playerPhysicsSetup = setup;
}

bool physicsEngine::getBasketballlPhysicsSetup()	// retrieves the value of the playerPhysicsSetup variable
{
	return (basketballPhysicsSetup);
}
void physicsEngine::setBasketballPhysicsSetup(bool setup)	// sets the value of the playerPhysicsSetup variable
{
	basketballPhysicsSetup = setup;
}

bool physicsEngine::getCourtPhysicsSetup()	// retrieves the value of the playerPhysicsSetup variable
{
	return (courtPhysicsSetup);
}
void physicsEngine::setCourtPhysicsSetup(bool setup)	// sets the value of the playerPhysicsSetup variable
{
	courtPhysicsSetup = setup;
}

bool physicsEngine::getPairCollided()	// retrieves value of pairCollided variable
{
	return (pairCollided);
}
void physicsEngine::setPairCollided(bool collided)	// sets value of pairCollided variable
{
	pairCollided = collided;
}

bool physicsEngine::getPassCollision()	// retrieves the value of passCollision variable
{
	return(passCollision);
}
void physicsEngine::setPassCollision(bool collision)	// sets the value of passCollision variable
{
	passCollision = collision;
}
void physicsEngine::setupState(void)
{

    renderEngine *render = renderEngine::Instance();

    // Debug drawing!
    debugDraw = new BtOgre::DebugDrawer(render->getMSceneMgr()->getRootSceneNode(), world);
    world->setDebugDrawer(debugDraw);

    if (!playerPhysicsSetup)
    {
    	if (setupPlayerPhysics()) // sets up physics state for players
    	{
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
	gameState *gameS = gameState::Instance();
    players *player = players::Instance();

    std::vector<teamState> teamInstance = gameS->getTeamInstance();

    for (size_t x=0; x<teamInstance.size();++x)
    {
		std::vector<playerState> playerInstance = teamInstance[x].getPlayerInstance();

		btRigidBody *playerBody;
		btCollisionShape *playerShape;
		BtOgre::RigidBodyState *playerBodyState;

		Ogre::LogManager::getSingletonPtr()->logMessage("playerInstance.size = " +Ogre::StringConverter::toString(playerInstance.size()));

		// loops through physics objects for all players
		for (size_t i=0; i<playerInstance.size(); ++i)
		{

			// create shape
			BtOgre::StaticMeshToShapeConverter converter(playerInstance[i].getModel());

			playerShape = converter.createCapsule();

			// calculates inertia
			btScalar mass = 1;
			btVector3 inertia, inertia2;
			inertia = btVector3(0,0,0);
			playerShape->calculateLocalInertia(mass, inertia);

			//Create BtOgre MotionState (connects Ogre and Bullet).
		//    BtOgre::RigidBodyState *bodyState = new BtOgre::RigidBodyState(pInstance[2].getNode());
			playerBodyState = new BtOgre::RigidBodyState(playerInstance[i].getNode());
	//        playerBodyState.at(i) = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(10.0f,-13.5f,380.0f)));
			//Create the Body.
	//        playerBody.at(i) = new btRigidBody(mass, playerBodyState.at(i), playerShape.at(i), inertia);
			playerBody = new btRigidBody(mass, playerBodyState, playerShape, inertia);
	 //       playerBody->setActivationState(DISABLE_DEACTIVATION);

			playerInstance[i].setPhysBody(playerBody);
	//        world->addRigidBody(playerBody.at(i));
			if (x == 0)
			{
				playerInstance[i].getPhysBody()->setActivationState(DISABLE_SIMULATION);
				Ogre::LogManager::getSingletonPtr()->logMessage("team = " + Ogre::StringConverter::toString(x));

				world->addRigidBody(playerInstance[i].getPhysBody(), COL_TEAM1, team1CollidesWith);
	//        	world->addRigidBody(pInstance[i].getPhysBody());
			}
			else if (x == 1)
			{
				playerInstance[i].getPhysBody()->setActivationState(DISABLE_SIMULATION);
				Ogre::LogManager::getSingletonPtr()->logMessage("team = " + Ogre::StringConverter::toString(x));

				world->addRigidBody(playerInstance[i].getPhysBody(), COL_TEAM2, team2CollidesWith);
	//        	world->addRigidBody(pInstance[i].getPhysBody());

			}
			else
			{
			}
		}

		teamInstance[x].setPlayerInstance(playerInstance);
    }
//	playerInstance[0].getPhysBody()->translate(btVector3 (0,1,0));
//    playerShape.push_back(*shape);
    for (int x=0;x<2; ++x)
    {
    	std::vector<playerState> playerInstance = teamInstance[x].getPlayerInstance();

    	Ogre::LogManager::getSingletonPtr()->logMessage("playerInstance.size = " + Ogre::StringConverter::toString(playerInstance.size()));
    }
    gameS->setTeamInstance(teamInstance);	// stores all the changes to the teamInstance
//    exit(0);
return true;
}

bool physicsEngine::setupCourtPhysics()
{
//    courtState *courtS = courtState::Instance();
    gameState *gameS = gameState::Instance();

    std::vector<courtState> cInstance = gameS->getCourtInstance();
    btRigidBody *courtBody;
    btScalar mass = 0;
    btVector3 inertia, inertia2;
    inertia = btVector3(0,0,0);


    //Create the ground shape.
    BtOgre::StaticMeshToShapeConverter converter(cInstance.at(0).getModel());
//    courtShape = converter.createTrimesh();
    courtShape = converter.createBox();
//    courtShape = new btStaticPlaneShape(btVector3(0,1,0),1);
//    courtShape->;
//s    courtShape->
    //Create MotionState (no need for BtOgre here, you can use it if you want to though).
//    courtBodyState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,-25,0)));
    courtBodyState = new BtOgre::RigidBodyState(cInstance[0].getNode());
//    courtBodyState = new BtOgre::RigidBodyState(cInstance.at(0).getNode());
    btRigidBody::btRigidBodyConstructionInfo info(mass,courtBodyState,courtShape,inertia); //motion state would actually be non-null in most real usages
    info.m_restitution = 1.0f;
    info.m_friction = 15.5f;


    //Create the Body.
//    courtBody = new btRigidBody(0, courtBodyState, courtShape, btVector3(0,0,0));
    courtBody = new btRigidBody(info);

    cInstance[0].setPhysBody(courtBody);
//    world->addRigidBody(cInstance[0].getPhysBody(), COL_COURT, courtCollidesWith);
    world->addRigidBody(courtBody);

    gameS->setCourtInstance(cInstance);

    return true;
}

bool physicsEngine::setupBasketballPhysics()
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

    basketballBodyState = new BtOgre::RigidBodyState(bInstance.at(0).getNode());

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

    world->addRigidBody(bInstance[0].getPhysBody(), COL_BBALL, bballCollidesWith);
//    world->addRigidBody(bInstance[0].getPhysBody());

    gameS->setBasketballInstance(bInstance);

    return true;
}

void physicsEngine::updateState()
{
	gameEngine *gameE = gameEngine::Instance();
	gameState *gameS = gameState::Instance();
    inputSystem *input = inputSystem::Instance();
//    teamState *teamS = teamState::Instance();

    int teamWithBall = gameS->getTeamWithBall();
    int playerWithBall;
    Ogre::LogManager::getSingletonPtr()->logMessage("teamWithBall = " + Ogre::StringConverter::toString(teamWithBall));
//    if (teamWithBall >=0)
    {
		std::vector<teamState> teamInstance = gameS->getTeamInstance();
		std::vector<playerState> playerInstance;
		std::vector<basketballs> bInstance = gameS->getBasketballInstance();
//		exit(0);
//		std::vector<playerState> playerInstance = teamInstance[teamWithBall].getPlayerInstance();
//		exit(0);
//		int playerWithBall = teamInstance[teamWithBall].getPlayerWithBall();


		Ogre::LogManager::getSingletonPtr()->logMessage("ballTipped == " + Ogre::StringConverter::toString(gameS->getBallTipped()));
//		exit(0);

		//    if (changeInTime >= 1000)
	//    {
	//    Ogre::LogManager::getSingletonPtr()->logMessage("Physics changeInTime = " + CIT);
	//		world->stepSimulation(changeInTime/1000, 1);
	//		world->debugDrawWorld();

		if (!gameS->getTipOffComplete())	// checks if tip off has finishedd
		{
//			exit(0);
			if(gameS->getTeamInstancesCreated())
			{
				tipOffCollisionCheck();
			}
			if (gameS->getBallTipped() && gameS->getBallTipForceApplied())
			{
				if (gameS->getBallTippedToTeam() == 0)
				{
					if (gameS->getBallTippedToPlayer() == 0)
					{
						//					exit(0);
						//		bInstance[0].getPhysBody()->forceActivationState(ACTIVE_TAG);
						//    	bInstance[0].getPhysBody()->applyForce(btVector3(1.20f, -1.60f, 0.0f),btVector3(0.0f,0.0f,0.0f));
						bInstance[0].getPhysBody()->setLinearVelocity(btVector3(20, 0, 0));
						//					exit(0);
						//    	gameS->setBallTipForceApplied(true);

					}
					//			Ogre::LogManager::getSingletonPtr()->logMessage("player tipped to = " +Ogre::StringConverter::toString(gameS->getBallTippedToPlayer()));
				}
				//			exit(0);
				else if (gameS->getBallTippedToTeam() == 1)
				{
					if (gameS->getBallTippedToPlayer() == 0)
					{
						bInstance[0].getPhysBody()->setLinearVelocity(btVector3(-20, 0, 0));

					}
				}
			}
			else
			{
			}

		}
//		else if (!playerInstance[playerWithBall].getPassBall())
		else if (gameS->getTipOffComplete())
		{
			if (teamWithBall >= 0)
			{
	//			exit(0);
				if (teamInstance[teamWithBall].getPlayerWithBallDribbling()) // checks if the player with ball is dribbling and updates accordingly
				{
//					exit(0);
					Ogre::LogManager::getSingletonPtr()->logMessage("Dribbling!!");
					ballDribbling();
					Ogre::LogManager::getSingletonPtr()->logMessage("Human Player = " +Ogre::StringConverter::toString(teamInstance[1].getHumanPlayer()));

				}
/*				else if (!teamInstance[teamWithBall].getPlayerWithBallDribbling()) // checks if the player with ball is dribbling and updates accordingly
				{
					exit(0);
					cout << "dah" << endl;

				}*/
				else
				{
					Ogre::LogManager::getSingletonPtr()->logMessage("Not Dribbling");

				}
				Ogre::LogManager::getSingletonPtr()->logMessage("A Team Has Ball");

			playerInstance = teamInstance[teamWithBall].getPlayerInstance();
			playerWithBall = teamInstance[teamWithBall].getPlayerWithBall();
			Ogre::LogManager::getSingletonPtr()->logMessage("Player with ball =====" +Ogre::StringConverter::toString(playerWithBall));
			exit(0);
			if (!playerInstance[playerWithBall].getPassBall())
			{
				teamInstance[teamWithBall].setPlayerWithBallDribbling(true);
	//			bInstance[0].getPhysBody()->forceActivationState(ACTIVE_TAG);
	//        	bInstance[0].getPhysBody()->applyForce(btVector3(-0.0f, -31.0f, 0.0f),btVector3(0.0f,0.0f,0.0f));
	//			bInstance[0].getPhysBody()->setLinearVelocity(btVector3(0,-10,0));
			}
			else if (playerInstance[playerWithBall].getPassBall() && playerInstance[playerWithBall].getPassCalculated())
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
    }

			//Update Bullet world. Don't forget the debugDrawWorld() part!
		//    world->stepSimulation(evt.timeSinceLastFrame, 10);
		//    playerBodyState.at(0)->setWorldTransForm(btTransform *transform)
		//    playerBody.at(2)->translate( btVector3( 0.0f, 10.0f, 0.0f ) );
		//    world->stepSimulation(changeInTime, 10);

	//exit(0);

		for (unsigned int x=0;x<teamInstance.size();++x)	// saves changes made to the playerInstance objects
		{
//			teamInstance[x].setPlayerInstance(playerInstance);
			Ogre::String X = Ogre::StringConverter::toString(x);
			Ogre::String size = Ogre::StringConverter::toString(playerInstance.size());
		    Ogre::LogManager::getSingletonPtr()->logMessage("Team " +X +" PlayerInstance Size = " +size);

		}
	    gameS->setTeamInstance(teamInstance);
    }
	
//    else
//    {
//    }

	// FIX FOR SDL!!
	//Shows debug if F3 key down.
	//    debugDraw->setDebugMode(input->getMKeyboard()->isKeyDown(OIS::KC_F3));

}

void physicsEngine::stepWorld()	// steps the world of the physics simulation
{
	gameEngine *gameE = gameEngine::Instance();

	btScalar currentTime;
	btScalar fixedTimeStep;


	Ogre::LogManager::getSingletonPtr()->logMessage("Time");

	//    unsigned long loopChangeInTime;	// stores change in time.

	currentTime = gameE->getLoopTime().getMilliseconds();

	//    if (currentTime - oldTime >= 1000 && currentTime - oldTime <= 1200)
	{
		changeInTime = (currentTime - oldTime) / 1000;
		oldTime = currentTime;
	}
	fixedTimeStep = btScalar(1.) / btScalar(60.);
	//    loopChangeInTime = gameE->getChangeInTime();

	String CIT = StringConverter::toString(changeInTime);
	String currTime = StringConverter::toString(currentTime);

	Ogre::LogManager::getSingletonPtr()->logMessage("Current Time = " + currTime);
	Ogre::LogManager::getSingletonPtr()->logMessage("Change In Time = " + CIT);

	world->stepSimulation(changeInTime, 1, fixedTimeStep);
	Ogre::LogManager::getSingletonPtr()->logMessage("World->Step ");
	debugDraw->step();

}

void physicsEngine::tipOffCollisionCheck()	// checks whether team 1 or team 2's center has made contact with the ball
{
	gameState *gameS = gameState::Instance();

	int ballTippedToTeam = gameS->getBallTippedToTeam();
	std::vector<teamState> teamInstance = gameS->getTeamInstance();

//    std::vector<playerState> teamOnePlayerInstance = teamInstance[0].getPlayerInstance();
//    std::vector<playerState> teamTwoPlayerInstance = teamInstance[1].getPlayerInstance();
    std::vector<basketballs> bInstance = gameS->getBasketballInstance();
    Ogre::LogManager::getSingletonPtr()->logMessage("Crash here?");
	MyContactResultCallback tipOffResult;
    Ogre::LogManager::getSingletonPtr()->logMessage("Crash here??");
	if (gameS->getBallTipped())		// if basketball has been tipped checks for collision between ball and player it was tipped to
	{
//		exit(0);
		Ogre::LogManager::getSingletonPtr()->logMessage("Physics team ball tipped to = " +Ogre::StringConverter::toString(ballTippedToTeam));

		std::vector<playerState> playerInstance = teamInstance[ballTippedToTeam].getPlayerInstance();
		Ogre::LogManager::getSingletonPtr()->logMessage("bInstance size = " +Ogre::StringConverter::toString(bInstance.size()));
		Ogre::LogManager::getSingletonPtr()->logMessage("playerInstance size = " + Ogre::StringConverter::toString(playerInstance.size()));

		world->contactPairTest(bInstance[0].getPhysBody(), playerInstance[gameS->getBallTippedToPlayer()].getPhysBody(), tipOffResult);
//		exit(0);
		if (!tipOffResult.m_connected)
		{
		}
		else
		{
//						exit(0);
			gameS->setBallTipForceApplied(false);
			//        	bInstance[0].getPhysBody()->applyForce(btVector3(-1.0f, 0.50f, 0.0f),btVector3(0.0f,0.0f,0.0f));
			//			bInstance[0].getPhysBody()->forceActivationState(ISLAND_SLEEPING);
			bInstance[0].getPhysBody()->setLinearVelocity(btVector3(0, 0, 0));
			gameS->setTipOffComplete(true);
			gameS->setTeamWithBall(ballTippedToTeam);
			Ogre::LogManager::getSingletonPtr()->logMessage("ballTippedToTeam" + Ogre::StringConverter::toString(ballTippedToTeam));

			Ogre::LogManager::getSingletonPtr()->logMessage("ballTippedToPlayer" + Ogre::StringConverter::toString(gameS->getBallTippedToPlayer()));
//			exit(0);

			teamInstance[ballTippedToTeam].setPlayerWithBall(gameS->getBallTippedToPlayer());
			teamInstance[ballTippedToTeam].setHumanPlayer(gameS->getBallTippedToPlayer());
			teamInstance[ballTippedToTeam].setPlayerWithBallDribbling(true);
			//			gameS->setTeamInstance(teamInstance);

			int humanPlayer = teamInstance[ballTippedToTeam].getHumanPlayer();
			Ogre::LogManager::getSingletonPtr()->logMessage("ballTippedToTeam" + Ogre::StringConverter::toString(ballTippedToTeam));
			Ogre::LogManager::getSingletonPtr()->logMessage("ballTippedToPlayer" + Ogre::StringConverter::toString(teamInstance[ballTippedToTeam].getPlayerWithBall()));

			Ogre::LogManager::getSingletonPtr()->logMessage("human player tipped to = " + Ogre::StringConverter::toString(humanPlayer));
//			exit(0);
			gameS->setTeamInstance(teamInstance);

			//			exit(0);
		}

	}
    // checks if player 4 touched the basketball
	else if (!gameS->getBallTipped())
	{
	    Ogre::LogManager::getSingletonPtr()->logMessage("Crash here???");
		for (unsigned int x=0;x<teamInstance.size();++x)
		{
			if (teamInstance[x].getPlayerInstancesCreated())
			{
				Ogre::LogManager::getSingletonPtr()->logMessage("X = " +Ogre::StringConverter::toString(x));

				Ogre::LogManager::getSingletonPtr()->logMessage("Crash here????");

				Ogre::LogManager::getSingletonPtr()->logMessage("Ball not tipped");
				std::vector<playerState> playerInstance = teamInstance[x].getPlayerInstance();
				Ogre::LogManager::getSingletonPtr()->logMessage("Crash here?????");
				Ogre::LogManager::getSingletonPtr()->logMessage("playerInstance Size = " +Ogre::StringConverter::toString(playerInstance.size()));

				world->contactPairTest(bInstance[0].getPhysBody(), playerInstance[4].getPhysBody(), tipOffResult);
				Ogre::LogManager::getSingletonPtr()->logMessage("tipOffResult.m_connected = " +Ogre::StringConverter::toString(tipOffResult.m_connected));
				bool test = false;
	//			if (tipOffResult.collision)
				if (!tipOffResult.m_connected)
				{
//					exit(0);
					/*
					gameS->setBallTipped(true);
					gameS->setBallTippedToTeam(x);
					gameS->setBallTippedToPlayer(0);
					gameS->setBallTipForceApplied(true);
	*/



					//			bInstance[0].getPhysBody()->forceActivationState(ISLAND_SLEEPING);
		//			bInstance[0].getPhysBody()->forceActivationState(DISABLE_DEACTIVATION);
		/*			for (int x=0;x<10;++x)
					{
						pInstance[x].getPhysBody()->forceActivationState(DISABLE_SIMULATION);
					}
		*/
		//			bInstance[0].getPhysBody()->applyForce(btVector3(5.10f, .20f, 0.0f),btVector3(10.0f,0.0f,0.0f));
		//			Ogre::LogManager::getSingletonPtr()->logMessage("Player tipped to = 0");
					Ogre::LogManager::getSingletonPtr()->logMessage("Ball Not Tipped");
					//    	gameS->setTipOffComplete(true);
	//	         	exit(0);
				}
				else if (tipOffResult.m_connected)
				{
//					exit(0);
					Ogre::LogManager::getSingletonPtr()->logMessage("Ball Tipped");
					gameS->setBallTipped(true);
					gameS->setBallTippedToTeam(x);
					Ogre::LogManager::getSingletonPtr()->logMessage("Tipped X = " +Ogre::StringConverter::toString(x));
	//				exit(0);
					gameS->setBallTippedToPlayer(0);
					gameS->setBallTipForceApplied(true);
//					tipOffResult.m_connected = false;
					gameS->setTeamInstance(teamInstance);

				}
			}
			else
			{

			}
		}
	}
	else
	{

	}



//	exit(0);
	gameS->setTeamInstance(teamInstance);
}

void physicsEngine::ballDribbling()	// simulates basketball dribble
{
	gameState *gameS = gameState::Instance();

//    std::vector<playerState> pInstance = gameS->getPlayerInstance();
    std::vector<basketballs> bInstance = gameS->getBasketballInstance();
    std::vector<courtState> cInstance = gameS->getCourtInstance();

	MyContactResultCallback courtCollisionResult;

	Ogre::Vector3 bballPos = bInstance[0].getNode()->getPosition();
    Ogre::Vector3 courtPos = cInstance[0].getNode()->getPosition();

    if (gameS->getBballBounce() == 0 && bballPos[1] < courtPos[1] + 3)	// checks if the ball is set to bounce up and hasn't reached the max height
    {
    	bInstance[0].getPhysBody()->setLinearVelocity(btVector3(0,15,0));
    }
    else
    {
    	gameS->setBballBounce(1);	// sets the ball to bounce down
    }

    if (gameS->getBballBounce() == 1)		// checks if the ball is set bounce downward
    {
    	bInstance[0].getPhysBody()->setLinearVelocity(btVector3(0,-15,0));
    }
    else
    {

    }

    pairCollided = false;
	Ogre::LogManager::getSingletonPtr()->logMessage("bInstance size = " +Ogre::StringConverter::toString(bInstance.size()));
	Ogre::LogManager::getSingletonPtr()->logMessage("cInstance size = " +Ogre::StringConverter::toString(cInstance.size()));

	Ogre::LogManager::getSingletonPtr()->logMessage("bInstance position = " + Ogre::StringConverter::toString(bInstance[0].getNode()->getPosition()));
	Ogre::LogManager::getSingletonPtr()->logMessage("cInstance position = " + Ogre::StringConverter::toString(cInstance[0].getNode()->getPosition()));

	btRigidBody *bballPhysBody = bInstance[0].getPhysBody();
	btRigidBody *courtPhysBody = cInstance[0].getPhysBody();
//	bballPhysBody->checkCollideWith(courtPhysBody);
	world->contactPairTest(bballPhysBody, courtPhysBody, courtCollisionResult);

/*	int numManifolds = world->getDispatcher()->getNumManifolds();
	for (int i = 0; i<numManifolds; i++)
	{
		btPersistentManifold* contactManifold = world->getDispatcher()->getManifoldByIndexInternal(i);
//		btCollisionObject* obA = static_cast<btCollisionObject*>(contactManifold->getBody0());
//		btCollisionObject* obB = static_cast<btCollisionObject*>(contactManifold->getBody1());
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

	Ogre::LogManager::getSingletonPtr()->logMessage("basketball - court collision tested");
	if (courtCollisionResult.m_connected)
	{
//		gameS->setPlayerWithBall(gameS->getBallTippedToPlayer());
//		gameS->setBallTipForceApplied(false);
//        	bInstance[0].getPhysBody()->applyForce(btVector3(-1.0f, 0.50f, 0.0f),btVector3(0.0f,0.0f,0.0f));
//			bInstance[0].getPhysBody()->forceActivationState(ISLAND_SLEEPING);
//		bInstance[0].getPhysBody()->setLinearVelocity(btVector3(0,10,0));
//	    gameS->setTipOffComplete(true);
//			exit(0);
		gameS->setBballBounce(0);
	}
	else
	{
	}

}

void physicsEngine::passCollisionCheck()	// checks whether the ball has collided with the player being passed to
{
//	exit(0);
	gameState *gameS = gameState::Instance();

	int teamWithBall = gameS->getTeamWithBall();
	std::vector<teamState>	teamInstance = gameS->getTeamInstance();
    std::vector<playerState> playerInstance = teamInstance[teamWithBall].getPlayerInstance();
    std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();

    int playerWithBall = teamInstance[teamWithBall].getPlayerWithBall();
    int passToPlayer = playerInstance[playerWithBall].getPassToPlayer();
	MyContactResultCallback passCollisionResult;
	Ogre::LogManager::getSingletonPtr()->logMessage("Basketball Coords = " +Ogre::StringConverter::toString(basketballInstance[0].getNode()->getPosition()));
	Ogre::LogManager::getSingletonPtr()->logMessage("Player to pass to = " +Ogre::StringConverter::toString(passToPlayer));
	Ogre::LogManager::getSingletonPtr()->logMessage("Player pass to Coords = " +Ogre::StringConverter::toString(playerInstance[passToPlayer].getNode()->getPosition()));

    pairCollided = false;
    world->contactPairTest(basketballInstance[0].getPhysBody(), playerInstance[passToPlayer].getPhysBody(), passCollisionResult);
	if (!passCollisionResult.m_connected)
	{
		Ogre::LogManager::getSingletonPtr()->logMessage("No Pass Collision");

		passCollision = false;
	}
	else
	{
//		exit(0);
		Ogre::LogManager::getSingletonPtr()->logMessage("Pass Collision");
		passCollision = true;
	}
}
