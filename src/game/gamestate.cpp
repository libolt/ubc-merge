/***************************************************************************
 *   Copyright (C) 2014 by Mike McLean   *
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

//#include "boost/shared_array.hpp"
#include "network.h"
#include "networkplayerstateobject.h"
#include "gamestate.h"
#include "gameengine.h"
#include "load.h"
#include "logging.h"
#include "playerdata.h"
#include "players.h"
#include "physicsengine.h"
#include "renderengine.h"
#include "teams.h"
#include "ai.h"

//extern "C"
//{
gameState *gameState::pInstance = 0;

gameState *gameState::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new gameState; // t sole instance
    }
    return pInstance; // address of sole instance
}

gameState::gameState()
{
	basketballModelLoaded = false;
	courtModelLoaded = false;
	hoopModelLoaded = false;
	setupEnvironmentCompleted = false;
    courtDataLoaded = false;
    courtInstanceCreated = false;
	teamInstancesCreated = false;
    gameStarted = false;
    teamWithBall = -1;

    selectedCourtDataInstance = -1;
    
    gameType = NOGAME;
    gameSetupComplete = false;
    tipOffComplete = false;
    ballTipped = false;
    ballTippedToTeam = -1;
    ballTippedToPlayer = -1;
    ballTipForceApplied = false;
    bballBounce = -1;
    currentQuarter = FIRST;
    gameTimeLeft = 0.0f;
    quarterTimeLeft = 0.0f;
    finished = false;

}
gameState::~gameState()
{
}

gameTypes gameState::getGameType() // retrieves the value of gameType
{
	return(gameType);
}
void gameState::setGameType(gameTypes type)	  // sets the value of gameType
{
	gameType = type;
}

bool gameState::getGameSetupComplete()    // retrieves the value of gameSetupComplete
{
    return (gameSetupComplete);
}
void gameState::setGameSetupComplete(bool complete)   // sets the value of gameSetupComplete
{
    gameSetupComplete = complete;
}

std::vector <courtState> gameState::getCourtInstance()  // retrieves the value of courtInstance
{
    return (courtInstance);
}
void gameState::setCourtInstance(std::vector<courtState> Instance)  // sest the value of courtInstance
{
    courtInstance = Instance;
}

std::vector <hoopState> gameState::getHoopInstance()  // retrieves the value of hoopInstance
{
    return (hoopInstance);
}
void gameState::setHoopInstance(std::vector<hoopState> Instance)  // sets the value of hoopInstance
{
    hoopInstance = Instance;
}

std::vector<teamData> gameState::getTeamDataInstance()		// retrieves the value of teamDataInstance
{
	return (teamDataInstance);
}
void gameState::setTeamDataInstances(std::vector<teamData> instance)	// sets the value of teamDataInstance
{
	teamDataInstance = instance;
}
std::vector<playerData> gameState::getPlayerDataInstance()		// retrieves the value of playerDataInstance
{
	return (playerDataInstance);
}

void gameState::setPlayerDataInstances(std::vector<playerData> instance)	// sets the value of playerDataInstance
{
	playerDataInstance = instance;
}

std::vector<courtData>	gameState::getCourtDataInstance()	// retrieves the value of courtDataInstance
{
	return (courtDataInstance);
}
void gameState::setCourtDataInstance(std::vector<courtData> instance)	// sets the value of courtDataInstance
{
	courtDataInstance = instance;
}

int gameState::getSelectedCourtDataInstance()  // retrieves the value of selectedCourtDataInstance
{
    return (selectedCourtDataInstance);
}
void gameState::setSelectedCourtDataInstance(int selected)  // sets the value of selectedCourtDataInstance
{
    selectedCourtDataInstance = selected;
}

std::vector<int> gameState::getTeamID(void)  // retrieves the value of teamID
{
    return (teamID);
}
void gameState::setTeamID(std::vector<int> ID) // sets the value of teamID
{
    teamID = ID;
}

std::vector<int> gameState::getPlayerID(void)  // retrieves the value of playerID
{
    return (playerID);
}
void gameState::setPlayerID(std::vector<int> ID)  // sets the value of playerID
{
    playerID = ID;
}

std::vector< std::vector<int> > gameState::getTeamStarterID() // retrieves value of teamStarterID
{
    return (teamStarterID);
}

void gameState::setTeamStarterID(std::vector< std::vector<int> > ID) // sets the value of teamStarterID
{
    teamStarterID = ID;
}

std::vector <teamState> gameState::getTeamInstance()  // retrieves the value of teamInstance
{
    return (teamInstance);
}
void gameState::setTeamInstance(std::vector<teamState> Instance)  // sets the value of teamInstance
{
    teamInstance = Instance;
}

std::vector <basketballs> gameState::getBasketballInstance()  // retrieves the value of basketballInstance
{
    return (basketballInstance);
}
 void gameState::setBasketballInstance(std::vector<basketballs> bballInstance) // sets the value of basketballInstance
{
    basketballInstance = bballInstance;
}

bool gameState::getTipOffComplete()  // retrieves the value of tipOffComplete
{
    return (tipOffComplete);
}
void gameState::setTipOffComplete(bool complete)  // sets the value of tipOffComplete
{
    tipOffComplete = complete;
}

bool gameState::getBallTipped()	// retrieves the value of ballTipped
{
	return (ballTipped);
}
void gameState::setBallTipped(bool tipped)	// sets the value of ballTipped
{
	ballTipped = tipped;
}

int gameState::getBallTippedToTeam()	// retrieves the value of ballTippedToPlayer
{
	return (ballTippedToTeam);
}
void gameState::setBallTippedToTeam(int team)	// sets the value of ballTippedToPlayer
{
	ballTippedToTeam = team;
}
int gameState::getBallTippedToPlayer()	// retrieves the value of ballTippedToPlayer
{
	return (ballTippedToPlayer);
}
void gameState::setBallTippedToPlayer(int player)	// sets the value of ballTippedToPlayer
{
	ballTippedToPlayer = player;
}

bool gameState::getBallTipForceApplied()	// retrieves the value of ballTipForceApplied
{
	return (ballTipForceApplied);
}
void gameState::setBallTipForceApplied(bool tip)	// sets the value of ballTipForceApplied
{
	ballTipForceApplied = tip;
}

bool gameState::getGameStarted(void)  // retrieves the value of gameStarted
{
    return(gameStarted);
}

void gameState::setGameStarted(bool started)  // sets the value of gameStarted
{
    gameStarted = started;
}

int gameState::getTeamWithBall(void)		// retrieves the value of teamWithBall
{
	return (teamWithBall);
}
void gameState::setTeamWithBall(int ball)	// sets the value of teamWithBall
{
	teamWithBall = ball;
}

int gameState::getBballBounce()	// retrieves the value of bballBounce
{
	return (bballBounce);
}
void gameState::setBballBounce(int bounce)	// sets the value of bballBounce
{
	bballBounce = bounce;
}

bool gameState::getCourtDataLoaded()  // retrieves the value of courtDataLoaded
{
    return (courtDataLoaded);
}
void gameState::setCourtDataLoaded(bool loaded)  // sets the value of courtDataLoaded
{
    courtDataLoaded = loaded;
}

bool gameState::getCourtInstanceCreated() // gets the value of the courtInstanceCreated
{
    return (courtInstanceCreated);
}
void gameState::setCourtInstanceCreated(bool created) // sets the value of the courtInstanceCreated
{
    courtInstanceCreated = created;
}

bool gameState::getTeamInstancesCreated()	// gets the value of teamInstancesCreated
{
	return (teamInstancesCreated);
}
void gameState::setTeamInstancesCreated(bool created)	// sets the value of teamInstancesCreated
{
	teamInstancesCreated = created;
}

bool gameState::getBasketballModelLoaded()	// gets the value of basketballModelLoaded
{
	return (basketballModelLoaded);
}
void gameState::setBasketballModelLoaded(bool loaded)	// sets the value of basketballModelLoaded
{
	basketballModelLoaded = loaded;
}

bool gameState::assignHoopToTeams()  // assigns which hoop belongs to each team
{
    teamInstance[0].setHoop(1);
    teamInstance[1].setHoop(0);
    return (true);
}
// assigns teams that are playing to the game state machine
bool gameState::assignTeams()
{
    logMsg("assigning teams");
    exit(0);
//    gameState *gameS = gameState::Instance();

    // sets the teams that are playing to teamID
    std::vector<int> teamIDS;
    teamID.push_back(1);	// hard codes team with ID = 1 as first team, code needs reworking
    teamID.push_back(2);	// hard codes team with ID = 2 as second team, code needs reworking
//    gameS->setTeamID(teamIDS);

    return true;
}

// assigns the players that are playing to the game state machine
bool gameState::assignPlayers()
{
    logMsg("assigning players");
    exit(0);
    gameState *gameS = gameState::Instance();
    players *player = players::Instance();
    teams *team = teams::Instance();

    std::vector<teamData> teamN = team->getTeamArray(); // stores the contents of teamArray in teamN
//    boost::shared_ptr<teamData> teamN; // = team->getTeamArray(); // stores the contents of teamArray in teamN
    // sets the players used on both teams
    std::vector<int> team1Starters;  // stores team 1 starters
    std::vector<int> team2Starters;  // stores team 2 starters
    for (size_t x = 0; x < teamN.size(); ++x)      // loops through teamN std::vector
    {
        if (teamN[x].getID() == teamID[0])     // checks if teamN's ID matches that of teamIDS[0]
        {

        //    team1Starters = teamN[x].getStarters();     // copies the starters to the team1Starters std::vector
            exit(0);
        }
        else if (teamN[x].getID() == teamID[1])        // checks if teamN's ID matches taht of teamIDs[1]
        {
            team2Starters = teamN[x].getStarters();     // copies the startesr to the team2Starters std::vector
        }
        else
        {
        }

    }

    std::vector <int> playerIDS = gameS->getPlayerID();      // stores the values of playerID in playerIDS std::vector
    std::vector <int>::iterator playersIT;   // iterator for the playerIDS std::vector

    // loops through team 1 starters and assigns them to playerIDS std::vector
    for (playersIT = team1Starters.begin(); playersIT != team1Starters.end(); ++playersIT)
    {
    	logMsg("playersIT == "  +*playersIT);
        playerIDS.push_back(*playersIT);
    }

    // loops through team 2 starters and assigns them to playerIDS std::vector
    for (playersIT = team2Starters.begin(); playersIT != team2Starters.end(); ++playersIT)
    {
        playerIDS.push_back(*playersIT);
    }

    // sets value of playerID in gameState class
    gameS->setPlayerID(playerIDS);


    return true;
}

// creates the player Instances for the particular game


// creates basketball Instances
bool gameState::createBasketballInstances()
{
    basketballs bballInstance;  // creates an instance of the basketballs class
    bballInstance.setModelName("bball.mesh");
    bballInstance.loadModel();
    basketballInstance.push_back(bballInstance);
    return true;
}

// creates team Instances
bool gameState::createTeamInstances()
{
	teamState tInstance;
	teamInstance.push_back(tInstance);	// adds empty teamState to teamInstance vector
	teamInstance.push_back(tInstance);	// adds empty teamState to teamInstance vector

	teamInstance[0].setTeamNumber(teamID[0]);
	teamInstance[1].setTeamNumber(teamID[1]);
    teamInstance[0].setHumanControlled(false);
    teamInstance[1].setHumanControlled(true);
	teamInstance[0].setupState();
	teamInstance[1].setupState();
//	exit(0);
    return true;
}

bool gameState::createCourtDataInstances()  // creates instances of court data
{
    loader *load = loader::Instance();
    
    courtDataInstance = load->loadCourts();
    return (true);
}

// creates court Instances
bool gameState::createCourtInstances()
{
    courtState cInstance;  // creates an instance of the courtState class
//    cInstance.setModelName("court.mesh");
//    cInstance.setModelName("Court.mesh");
    
    logMsg("Model Name = " +courtDataInstance[selectedCourtDataInstance].getModelName());

    cInstance.setModelName(courtDataInstance[selectedCourtDataInstance].getModelName());
//    exit(0);
    cInstance.loadModel();
    courtInstance.push_back(cInstance);

    return true;
}

// creates hoop Instances
bool gameState::createHoopInstances()
{
    hoopState *hInstance = new hoopState[2];  // creates an instance of the hoopState class
//    cInstance.setModelName("court.mesh");
    hInstance[0].setEntityName("hoop1");
    hInstance[0].setModelName("Hoop.mesh");
    hInstance[0].setNodeName("hoopNode1");
    hInstance[0].loadModel();

    hInstance[1].setEntityName("hoop2");
    hInstance[1].setModelName("Hoop.mesh");
    hInstance[1].setNodeName("hoopNode2");
    hInstance[1].loadModel();

    hoopInstance.push_back(hInstance[0]);  // loads the first hoop
	hoopInstance.push_back(hInstance[1]);  // loads the second hoop

    return true;
}

bool gameState::setupEnvironment()
{
    renderEngine *render = renderEngine::Instance();
/*
    // Set ambient light
    render->getMSceneMgr()->setAmbientLight(ColourValue(0.5, 0.5, 0.5));

    // Create a light
    Light* l = render->getMSceneMgr()->createLight("MainLight");
    l->setPosition(20,80,56);
*/

    return true;
}

void gameState::setBasketballStartPositions()  // sets the initial coordinates for the basketball(s)
{
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	basketballInstance[0].getNode()->setPosition(0.8f,10.0f,352.0f);
#else
	basketballInstance[0].getNode()->setPosition(0.8f,-5.0f,352.0f);
#endif
}

void gameState::setCourtStartPositions()  // sets the initial coordinates for the basketball(s)
{
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	courtInstance[0].getNode()->setPosition(0.0f,-6.5f,360.0f);
    logMsg("courtPosition");
//exit(0);
#else
	courtInstance[0].getNode()->setPosition(0.0f,-27.5f,360.0f);
#endif
}

void gameState::setHoopStartPositions()  // sets the initial coordinates for the basketball(s)
{
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	hoopInstance[0].getNode()->setPosition(45.0f,-6.5f,370.0f);
	hoopInstance[1].getNode()->setPosition(-45.0f,-6.5f,370.0f);
#else
	hoopInstance[0].getNode()->setPosition(45.0f,-23.5f,370.0f);
	hoopInstance[1].getNode()->setPosition(-45.0f,-23.5f,370.0f);
#endif

	Quaternion hoop0Rotation(Degree(-90), Vector3::UNIT_Y);
	hoopInstance[0].getNode()->rotate(hoop0Rotation);

	Quaternion hoop1Rotation(Degree(90), Vector3::UNIT_Y);
	hoopInstance[1].getNode()->rotate(hoop1Rotation);
}

// sets up tip off conditions
bool gameState::setupTipOff()
{
//    basketballs *basketball = basketballs::Instance();
//    gameState *gameS = gameState::Instance();
//    players *player = players::Instance();
    teams *team = teams::Instance();

//    std::vector<basketballs> basketballInstance = getBasketballInstance();
//    SceneNode *bball;
/*    bball = basketballInstance[0].getNode();
    bball->setPosition(1.4f,5.0f,352.0f);
    basketballInstance[0].setNode(bball);
    basketballInstance[0].setTipOffStart(true);
    setBasketballInstance(basketballInstance);
*/
//    std::vector<int> playerIDS = getPlayerID();
//    std::vector <playerState> pInstance = getPlayerInstance();
//    std::vector <Ogre::SceneNode*> playerNodes = player->getNode();

//    setPlayerStartPositions();	// sets starting positions for the players

//    player->setNode(playerNodes);   // copies playerNodes std::vector to Node std::vector in players class
    return true;
}

// executes tip off
bool gameState::executeTipOff()
{
 //   gameState *gameS = gameState::Instance();
    players *player = players::Instance();

    std::vector<basketballs> basketballInstance = getBasketballInstance();

//    basketballInstance[0].nodeChangePosition(basketballInstance[0].calculatePositionChange());
//exit(0);
//   setBasketballInstance(basketballInstance);
    return true;
}

// sets up the game condition
bool gameState::setupState()
{
	AISystem *ai = AISystem::Instance();
    players *player = players::Instance();
    renderEngine *render = renderEngine::Instance();
    teams *team = teams::Instance();
    loader *load = loader::Instance();
    physicsEngine *physEngine = physicsEngine::Instance();

//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//	exit(0);
    logMsg("Setting up state!");
 //   load->loadTeams();  // loads teams from XML files
//#else

//    moved to GUI code
//    load->loadPlayers();    // loads players from XML files
/*
    team->assignPlayers();  // assigns players to teams
    team->assignStarters(); // assigns starting players to teams

    assignTeams();    // assigns teams playing

    assignPlayers();  // assigns players currently playing
*/
//    exit(0);
    if (!teamInstancesCreated)	// checks if teamInstances have been created
    {
    	if(createTeamInstances())	// creates the team instances
    	{
            logMsg("TIC!");
            teamInstancesCreated = true;
            assignHoopToTeams();  // assigns proper hoop to the teams that were created.
    	}
    }

/*    if (!playerInstancesCreated)	// checks if playerInstances have been created
    {
    	if (createPlayerInstances()) // creates the player instances based on playerIDS
		{
    		playerInstancesCreated = true;
		}
    } */
    if (!basketballModelLoaded)	// checks if court model has been loaded
    {
    	if (createBasketballInstances()) // creates the basketball instances
    	{
    		basketballModelLoaded = true;
    	}
    }

    if (!courtModelLoaded)
    {
        if (createCourtInstances())  // creates the court instances
        {
        	courtModelLoaded = true;
        }
    }

    if (!hoopModelLoaded)
    {
        if (createHoopInstances())  // creates the hoop instances
        {
        	hoopModelLoaded = true;
        }
    }

    setBasketballStartPositions();	// sets starting positions for all basketballs that are instantiated
    setCourtStartPositions();	// sets starting positions for all courts that are instantiated
    setHoopStartPositions();	// sets starting positions for all hoops that are instantiated

//    basketballInstance[0].getNode()->setPosition(1.4f,5.0f,366.0f);


    physEngine->setupState();  // sets up the Physics Engine state
//    exit(0);
	ai->setup();

//        Ogre::Entity *ent;
//        ent = player->getModel(0);
//        player->mAnimationState2 = ent->getAnimationState("Walk");
//        std::vector<Ogre::Entity*> playerModels = player->getModel();
//        std::vector<Ogre::SceneNode*> playerNodes = player->getNode();
//    std::vector<playerState> pInstance = getPlayerInstance();
//        player->setModel(playerModels);
//    Ogre::Vector3 playerPos = playerNodes.at(0)->getPosition();
//    Ogre::Vector3 offset;
//    offset[0] = 2.0f;
//    offset[1] = 2.0f;
//    offset[2] = 2.0f;
//	bball->setAutoTracking(true,playerNode[0],playerNode[0]->getPosition(),offset);
//	bball->setPosition(playerPos[0] +2.0f, playerPos[1] + 4.0f, playerPos[2] - 1.0f);
//    exit(0);

    if (!setupEnvironmentCompleted)	// checks if environment has been setup
    {
    	if(setupEnvironment())	// sets up environment
    	{
    		setupEnvironmentCompleted = true;
    	}
    }
//	loads("../../data/players/players.xml");

    setupTipOff();	// sets up tip off conditions

/*    teamWithBall = 0;	// FIXME! Temporarily hard code team controlling ball
	teamInstance[0].setPlayerWithBall(0);
	teamInstance[0].setPlayerWithBallDribbling(true);
	tipOffComplete = true;
	teamInstance[0].setHumanPlayer(0);
	*/
    return true;

//#endif
}

// carries out in game logic
bool gameState::logic()
{
//    logMsg("Updating gameState Logic");

    AISystem *ai = AISystem::Instance();
    gameEngine *gameE = gameEngine::Instance();
	networkEngine *network = networkEngine::Instance();
    players *player = players::Instance();
    physicsEngine *physEngine = physicsEngine::Instance();
    Ogre::Vector3 playerPos;

//	std::vector<basketballs> basketballInstance = getBasketballInstance();
	// sets up and starts the dribbling animation
//	basketballInstance[0].setDribblingStart(true);
    basketballInstance[0].setPlayer(5);

    if (network->getPacketReceived())	// checks if a packet was received by network engine
    {
    	processNetworkEvents();	// processes data received from the network
    }
    logMsg("network events processed");
//    Ogre::LogManager::getSingletonPtr()->logMessage(("Player's start position: "  +toString(playerInstance[3].getNode()->getPosition())));
//    Ogre::LogManager::getSingletonPtr()->logMessage(("Court's current position: "  +toString(courtInstance[0].getNode()->getPosition())));
//    Ogre::LogManager::getSingletonPtr()->logMessage(("Basketball's current position: "  +toString(basketballInstance[0].getNode()->getPosition())));

// FIXME! need to update which team and player has ball
/*    if (tipOffComplete)
    {
    	if (playerWithBall >= 0)
    	{
    		if(playerWithBall <5)
    		{
    			teamWithBall = 0;
    		}
    		else if (playerWithBall >4)
    		{
    			teamWithBall = 1;
    		}
    		else
    		{
    		}
    	}
    }
    */
//    physEngine->updateState();
//   playerInstance[0].setMovement(true);
//   playerInstance[0].setDirection(RIGHT);

    for (int x=0; x<5;++x)
    {
//    	logMsg("Player Position " +Ogre::StringConverter::toString(x) +" = " +Ogre::StringConverter::toString(teamInstance[1].getPlayerInstance()[x].getNodePosition()));
    }
/*    
	if (teamWithBall >= 0)
	{
//		logMsg("teamWithBall is " +Ogre::StringConverter::toString(teamWithBall));
//        logMsg("playetWithBall is " +Ogre::StringConverter::toString(teamInstance[teamWithBall].getPlayerWithBall()));
		float currentTime = static_cast<float>(gameE->getLoopTime().getMilliseconds()/100);
        float oldTime = ai->getOldTime();
        float changeInTime = currentTime - oldTime;
   //     ai->update(currentTime, changeInTime);
		logMsg("CHANGE == " +Ogre::StringConverter::toString(changeInTime));

		if (changeInTime >= .5f)
		{
			logMsg("ELAPSED == " +Ogre::StringConverter::toString(changeInTime));
//			exit(0);
//			ai->update(aiTimer.getTotalSimulationTime (), aiTimer.getElapsedSimulationTime ());
			ai->update(currentTime, changeInTime);
			ai->setOldTime(currentTime);
		}

    }
*/
    logMsg("Physics");
    physEngine->updateState();	// updates the state of the physics simulation
//    exit(0);
	physEngine->stepWorld();	// steps the physics simulation
    logMsg("DirectionsAndMovement");
    updateDirectionsAndMovements();
//	exit(0);

    updatePositions();   // updates positions of game world objects



//    exit(0);
//    renderBall();
//    SceneNode *bball = basketballInstance[0].getNode();
//    bball->setPosition(basketballInstance[0].calculatePositionChange());
//    basketballInstance[0].setNode(bball);

//    Ogre::Vector3 change = basketballInstance[0].calculatePositionChange();
//    cout << "Calced Pos change = " << basketballInstance[0].calculatePositionChange() << endl;
//    basketballInstance[0].nodeChangePosition(basketballInstance[0].calculatePositionChange());

    std::vector<int> playerDirection = player->getPlayerDirection(); // stores contents of playerDirectdion from players class in local variable
    std::vector<int> oldPlayerDirection = player->getOldPlayerDirection();   // stores contents of oldPlayerDirection form players in local variable

    // Initiates offense or defense for a team depending on value of teamWithBall
    if (teamWithBall == 0)	// if 0 puts team 0 on offense and team 1 on defense
    {
    	teamInstance[0].setOffense(true);
    	teamInstance[0].setDefense(false);

    	teamInstance[1].setOffense(false);
    	teamInstance[1].setDefense(true);
    }
    else if (teamWithBall == 1)  // if 1 puts team 1 on offense and team 0 on defense
    {
    	teamInstance[0].setOffense(false);
    	teamInstance[0].setDefense(true);

    	teamInstance[1].setOffense(true);
    	teamInstance[1].setDefense(false);
    }
    else
    {
    }

    // updates the state of each team
    if (teamInstancesCreated)
    {
        //FIXME crash in updateState code
    	teamInstance[0].updateState();
    	teamInstance[1].updateState();
//    	exit(0);
    }
    else
    {
    }
//	logMsg("gameState logic updated");
//    exit(0);
    return true;
}

void gameState::processNetworkEvents()	// processes events from network code
{
    networkEngine *network = networkEngine::Instance();

//	std::vector <playerState> playerInstance = gameS->getPlayerInstance();

	if(Ogre::StringUtil::startsWith(network->getReceivedData(), "3" ))
	{
		logMsg("process!ng network player event");

		processNetworkPlayerEvents();

	}

//	std::vector<teamState> teamInstance = teamInstance();
	teamInstance[0].setPlayerType("human");	// sets playerType for teamInstance 0 to human

	// checks if this instance is a server and whether teamInstance 1 is set to be controlled by network player
	if (network->getServerReceivedConnection() && teamInstance[1].getPlayerType() != "network")
	{
		teamInstance[1].setPlayerType("network");	// sets teamInstance 1 playerType to 'network'
	}
	// checks if this instance is a client and whether teamInstance 0 is set to be controlled by network player
	else if (network->getClientEstablishedConnection() && teamInstance[0].getPlayerType() != "network" )
	{
		teamInstance[0].setPlayerType("network");
	}


}

void gameState::processNetworkPlayerEvents()	// processes player events from network code
{
    networkEngine *network = networkEngine::Instance();
	networkPlayerStateObject netPStateObj;
	std::stringstream strStream;
    std::vector<playerState> playerInstance;
	Ogre::String receivedData = network->getReceivedData();	// stores receivedData value
	int playerNumber = -1; // stores which player the data is for
	int iterator;	// iterator for match loop

	logMsg("received Data === " +receivedData);
	strStream << receivedData;
	strStream >> netPStateObj;
	logMsg("received teamID = " +Ogre::StringConverter::toString(netPStateObj.getTeamID()));
	logMsg("received playerID = " +Ogre::StringConverter::toString(netPStateObj.getPlayerID()));

	// sets which team's playerInstance to use
	if (network->getIsClient())
	{
	    logMsg("is client");
		playerInstance = teamInstance[1].getPlayerInstance();
	}
	else if (network->getIsServer())
	{
	    logMsg("is server");
		playerInstance = teamInstance[0].getPlayerInstance();
	}
	else
	{
	}
	logMsg("playerInstance size == " +Ogre::StringConverter::toString(playerInstance.size()));
/*	for (iterator = 0; iterator < 5; ++iterator)
	{
		Ogre::String searchString;	// stores search String
		Ogre::String searchIterator = Ogre::StringConverter::toString(iterator); // converts iterator to a string
		searchString = "*" +searchIterator + "*";	// creates search string
		if (Ogre::StringUtil::match(receivedData,searchString))	// checks for a match
		{
			playerNumber = iterator;	// sets playerNumber to value of iterator
		}
	}
    logMsg("alive????");
*/
    playerNumber = netPStateObj.getPlayerID();
    if (playerInstance.size() > 0)
    {
        if (netPStateObj.getMovement())
        {
            switch (netPStateObj.getDirection())
            {
                case 0: // move player up
                    playerInstance[playerNumber].setMovement(true);
                    playerInstance[playerNumber].setDirection(UP);

                    break;
                case 1: // move player down
                    playerInstance[playerNumber].setMovement(true);
                    playerInstance[playerNumber].setDirection(DOWN);
                    break;
                case 2: // move player left
                    playerInstance[playerNumber].setMovement(true);
                    playerInstance[playerNumber].setDirection(LEFT);
                    break;
                case 3: // move player right
                    playerInstance[playerNumber].setMovement(true);
                    playerInstance[playerNumber].setDirection(RIGHT);
                    break;
                case 4: // move player up and left
                    playerInstance[playerNumber].setMovement(true);
                    playerInstance[playerNumber].setDirection(UPLEFT);
                    break;
                case 5: // move player up aned right
                    playerInstance[playerNumber].setMovement(true);
                    playerInstance[playerNumber].setDirection(UPRIGHT);
                    break;
                case 6: // move player down and left
                    playerInstance[playerNumber].setMovement(true);
                    playerInstance[playerNumber].setDirection(DOWNLEFT);
                    break;
                case 7: // move player down and right
                    playerInstance[playerNumber].setMovement(true);
                    playerInstance[playerNumber].setDirection(DOWNRIGHT);
                    break;
                default:
                	playerInstance[playerNumber].setMovement(false);
                    break;
            }
            if (network->getIsClient())
            {
                teamInstance[1].setPlayerInstance(playerInstance);
            }
            else if (network->getIsServer())
            {
                teamInstance[0].setPlayerInstance(playerInstance);
            }
        }
        else if (netPStateObj.getShootBlock())
        {

        }
        else if (netPStateObj.getPassSteal())
        {

        }
        else
        {
        }
    }
        // FIXME Dead code should be removed eventually
/*        // checks what is at the end of the receivedData string
        if (Ogre::StringUtil::endsWith(receivedData, "up"))	// checks if player moved upward
        {
            logMsg("die0");
            exit(0);
    //		Ogre::Vector3 Pos = Ogre::Vector3(0.0f, 0.400f, 0.0f);
    //		playerInstance[playerNumber].getNode()->translate(Pos);
            playerInstance[playerNumber].setMovement(true);
            playerInstance[playerNumber].setDirection(UP);

        }
        else if (Ogre::StringUtil::endsWith(receivedData, "down"))	// checks if player moved downward
        {
            logMsg("die1");
    //		Ogre::Vector3 Pos = Ogre::Vector3(0.0f, -0.400f, 0.0f);
    //		playerInstance[playerNumber].getNode()->translate(Pos);
            playerInstance[playerNumber].setMovement(true);
            playerInstance[playerNumber].setDirection(DOWN);

        }
        else if (Ogre::StringUtil::endsWith(receivedData, "left")) // checks if player moved left
        {
            logMsg("die2");

    //		Ogre::Vector3 Pos = Ogre::Vector3(-0.400f, 0.0f, 0.0f);
    //		playerInstance[playerNumber].getNode()->translate(Pos);
            playerInstance[playerNumber].setMovement(true);
            playerInstance[playerNumber].setDirection(LEFT);
            logMsg("dead1");

        }
        else if (Ogre::StringUtil::endsWith(receivedData, "right"))	// checks if player moved right
        {
            logMsg("die3");

    //		Ogre::Vector3 Pos = Ogre::Vector3(0.400f, 0.0f, 0.0f);
    //		playerInstance[playerNumber].getNode()->translate(Pos);
            playerInstance[playerNumber].setMovement(true);
            playerInstance[playerNumber].setDirection(RIGHT);

        }
        else if (Ogre::StringUtil::endsWith(receivedData, "shootblock")) // checks if player attempted shot or block
        {
            logMsg("die4");

        }
        else if (Ogre::StringUtil::endsWith(receivedData, "passsteal"))	// checks if player attempted pass or steal
        {
            logMsg("die5");

        }
    }
    */
	logMsg("Survived!");
	network->setReceivedData("");
}


void gameState::updateDirectionsAndMovements()
{
//    directions playerDirection, oldPlayerDirection;
//   logMsg("Updating Directions and Movements");

    if (teamWithBall >= 0)
    {
//		logMsg("teamWithBall is " +Ogre::StringConverter::toString(teamWithBall));
//		logMsg("playetWithBall is " +Ogre::StringConverter::toString(teamInstance[teamWithBall].getPlayerWithBall()));
		updateBasketballMovements();	// updates the movement of basketball objec(s)
		updateBasketballDirections(); // updates direction of basketball object(s)
    }
    else
    {
    }
}

// FIXME! Update for new teamState and playerState organizations

void gameState::updateBasketballMovements()	// updates the basketball(s) movements
{
//	logMsg("Updating basketball movements");

	std::vector<playerState> playerInstance = teamInstance[teamWithBall].getPlayerInstance();
	int playerWithBall = teamInstance[teamWithBall].getPlayerWithBall();
    bool shotTaken = playerInstance[playerWithBall].getShotTaken();
//    logMsg("teamWithBall" + Ogre::StringConverter::toString(teamWithBall));
//	logMsg("playerWithBall" + Ogre::StringConverter::toString(playerWithBall));

//	exit(0);
    if (!shotTaken)
    {
        directions playerDirection = playerInstance[playerWithBall].getDirection();
        directions oldPlayerDirection = playerInstance[playerWithBall].getOldDirection();

        if (playerWithBall >= 0 && tipOffComplete == true)	// verifies that the playerWithBall variable is set to a valid number
        {
    //		exit(0);
            Ogre::Vector3 playerPos= playerInstance[playerWithBall].getNode()->getPosition();	// stores the current position of player with ball

            Ogre::Vector3 bballPos = playerPos;
            Ogre::Vector3 bballCurrentPos = basketballInstance[0].getNode()->getPosition();	// stores the current position of the basketball(s)
            btVector3 change; // = btVector3(0,0,0);
            btTransform transform;



            if (playerInstance[playerWithBall].getMovement())
            {
                if (playerDirection == oldPlayerDirection)
                {
                    switch (playerDirection)
                    {
                        case UP:
                            bballPos[0] += 2;
                            bballPos[1] = bballCurrentPos[1]; // maintains the current height of the basketball on the court as the player and ball moves
                            bballPos[2] -= 2;
                //				basketballInstance[0].setPosChange(bballPosChange);	// sets the posChange for current basketballInstance
                            basketballInstance[0].getNode()->setPosition(bballPos);
                            change = BtOgre::Convert::toBullet(bballPos); // converts from Ogre::Vector3 to btVector3
                            transform.setOrigin(change);
                //				basketballInstance[0].getPhysBody()->translate(change);
                            basketballInstance[0].getPhysBody()->setWorldTransform(transform);
                            break;
                        case DOWN:
                            bballPos[0] -= 2;
                            bballPos[1] = bballCurrentPos[1]; // maintains the current height of the basketball on the court as the player and ball moves
                            bballPos[2] += 2;
                //				basketballInstance[0].setPosChange(bballPosChange);	// sets the posChange for current basketballInstance
                            basketballInstance[0].getNode()->setPosition(bballPos);
                            change = BtOgre::Convert::toBullet(bballPos); // converts from Ogre::Vector3 to btVector3
                            transform.setOrigin(change);
                            basketballInstance[0].getPhysBody()->setWorldTransform(transform);
                            break;
                        case LEFT:
                            bballPos[0] -= 2;
                            bballPos[1] = bballCurrentPos[1];
                //				exit(0);
                //				basketballInstance[0].setPosChange(bballPosChange);	// sets the posChange for current basketballInstance
                            basketballInstance[0].getNode()->setPosition(bballPos);
                            change = BtOgre::Convert::toBullet(bballPos); // converts from Ogre::Vector3 to btVector3
                            transform.setOrigin(change);
                            basketballInstance[0].getPhysBody()->setWorldTransform(transform);
                            break;
                        case RIGHT:
                            bballPos[0] += 2;
                            bballPos[1] = bballCurrentPos[1]; // maintains the current height of the basketball on the court as the player and ball moves
                //				basketballInstance[0].setPosChange(bballPosChange);	// sets the posChange for current basketballInstance
                            basketballInstance[0].getNode()->setPosition(bballPos);
                            change = BtOgre::Convert::toBullet(bballPos); // converts from Ogre::Vector3 to btVector3
                            transform.setOrigin(change);
                            basketballInstance[0].getPhysBody()->setWorldTransform(transform);
                            break;
                        default:
                            break;
                    }
                }
                else
                {
                }
            }
            else
            {
            }
        }
        playerInstance[playerWithBall].setMovement(false);	// sets the movement to false for playerWithBall
    }
    else
    {
        logMsg("shotTaken!");
    }
}


void gameState::updateBasketballDirections()	// updates basketball direction(s)
{
	std::vector<playerState> playerInstance = teamInstance[teamWithBall].getPlayerInstance();
	int playerWithBall = teamInstance[teamWithBall].getPlayerWithBall();
    bool shotTaken = playerInstance[playerWithBall].getShotTaken();

    if (!shotTaken)
    {

        Ogre::Vector3 posChange;
        directions playerDirection = playerInstance[playerWithBall].getDirection();
        directions oldPlayerDirection = playerInstance[playerWithBall].getOldDirection();

        if (playerWithBall >= 0 && tipOffComplete == true)	// verifies that the playerWithBall variable is set to a valid number
        {
            Ogre::Vector3 playerPos= playerInstance[playerWithBall].getNode()->getPosition();
            Ogre::Vector3 bballCurrentPos = basketballInstance[0].getNode()->getPosition();	// stores the current position of the basketball(s)

            Ogre::Vector3 bballPos = playerPos;
            Ogre::Vector3 bballPosChange = Ogre::Vector3(0.0f,0.0f,0.0f);
            btVector3 change; // = btVector3(0,0,0);
            btTransform transform;
    //		basketballInstance[0].getPhysBody()->forceActivationState(ISLAND_SLEEPING);
    //        logMsg("playerDirection = " + Ogre::StringConverter::toString(&playerDirection));
    //        logMsg("oldPlayerDirection = " + Ogre::StringConverter::toString(&oldPlayerDirection));

            logMsg("playerWithBall = " +Ogre::StringConverter::toString(playerWithBall));
            if (playerDirection != oldPlayerDirection)
            {
                switch (playerDirection)
                {
                    case UP:
                        bballPos[0] += 2;
                        bballPos[1] = bballCurrentPos[1]; // maintains the current height of the basketball on the court as the player and ball moves
                        bballPos[2] -= 2;
        //				basketballInstance[0].setPosChange(bballPosChange);	// sets the posChange for current basketballInstance
                        basketballInstance[0].getNode()->setPosition(bballPos);
                        change = BtOgre::Convert::toBullet(bballPos); // converts from Ogre::Vector3 to btVector3
                        transform.setOrigin(change);
                        basketballInstance[0].getPhysBody()->setWorldTransform(transform);
                        break;
                    case DOWN:
                        bballPos[0] -= 2;
                        bballPos[1] = bballCurrentPos[1]; // maintains the current height of the basketball on the court as the player and ball moves
                        bballPos[2] += 2;
        //				basketballInstance[0].setPosChange(bballPosChange);	// sets the posChange for current basketballInstance
                        basketballInstance[0].getNode()->setPosition(bballPos);
                        change = BtOgre::Convert::toBullet(bballPos); // converts from Ogre::Vector3 to btVector3
                        transform.setOrigin(change);
                        basketballInstance[0].getPhysBody()->setWorldTransform(transform);
                        break;
                    case LEFT:
                        bballPos[0] -= 2;
                        bballPos[1] = bballCurrentPos[1]; // maintains the current height of the basketball on the court as the player and ball moves
        //				exit(0);
        //				basketballInstance[0].setPosChange(bballPosChange);	// sets the posChange for current basketballInstance
                        basketballInstance[0].getNode()->setPosition(bballPos);
                        change = BtOgre::Convert::toBullet(bballPos); // converts from Ogre::Vector3 to btVector3
                        transform.setOrigin(change);
                        basketballInstance[0].getPhysBody()->setWorldTransform(transform);
                        break;
                    case RIGHT:
                        bballPos[0] += 2;
                        bballPos[1] = bballCurrentPos[1]; // maintains the current height of the basketball on the court as the player and ball moves
        //				basketballInstance[0].setPosChange(bballPosChange);	// sets the posChange for current basketballInstance
                        basketballInstance[0].getNode()->setPosition(bballPos);
                        change = BtOgre::Convert::toBullet(bballPos); // converts from Ogre::Vector3 to btVector3
                        transform.setOrigin(change);
                        basketballInstance[0].getPhysBody()->setWorldTransform(transform);
                        break;
                    default:
                        break;
                }
    //		basketballInstance[0].getPhysBody()->forceActivationState(ACTIVE_TAG);
            }
            else
            {
            }
        }
        oldPlayerDirection = playerDirection;
        playerInstance[playerWithBall].setOldDirection(oldPlayerDirection);  // copies contents of oldPlayerDirection to the oldDirection variable
    }
    else
    {

    }
}


// updates positions of gameState objects
bool gameState::updatePositions()
{
//	int x = 0;
//	std::vector<playerState>::iterator playerIT;
//	cout << "Size = " << playerInstance.size() << endl;
//	Ogre::LogManager::getSingletonPtr()->logMessage("Size = " +toString(playerInstance.size()));
	//	for (playerIT = playerInstance.begin(); playerIT != playerInstance.end(); ++playerIT)


	// updates the basketball(s) position on the court
	for (size_t x = 0; x < basketballInstance.size(); ++x)
	{
		basketballInstance[x].updatePosition();
	}

    return true;
}

//}
