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

//#include "boost/shared_array.hpp"
#include "network.h"
#include "gamestate.h"
#include "load.h"
#include "playerdata.h"
#include "players.h"
#include "physicsengine.h"
#include "renderengine.h"
#include "teams.h"


gameState *gameState::pInstance = 0;

gameState *gameState::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new gameState; // create sole instance
    }
    return pInstance; // address of sole instance
}

gameState::gameState()
{
	basketballModelLoaded = false;
	courtModelLoaded = false;
	setupEnvironmentCompleted = false;
	teamInstancesCreated = false;
	playerInstancesCreated = false;
    gameStarted = false;
    shotTaken = false;
    shotComplete = false;
    teamWithBall = -1;
    playerWithBall = 9;


    tipOffComplete = false;
    ballTipped = false;
    ballTippedToPlayer = -1;
    ballTipForceApplied = false;
    playerWithBallDribbling = false;
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

// gets and sets courtInstance std::vector
std::vector <courtState> gameState::getCourtInstance()
{
    return (courtInstance);
}
void gameState::setCourtInstance(std::vector<courtState> Instance)
{
    courtInstance = Instance;
}

// gets and sets teamID
std::vector<int> gameState::getTeamID(void)
{
    return (teamID);
}
void gameState::setTeamID(std::vector<int> ID)
{
    teamID = ID;
}

// gets and sets plaeyrID

std::vector<int> gameState::getPlayerID(void)
{
    return (playerID);
}
void gameState::setPlayerID(std::vector<int> ID)
{
    playerID = ID;
}

// gets and sets playerInstance std::vector
std::vector <playerState> gameState::getPlayerInstance()
{
    return (playerInstance);
}

void gameState::setPlayerInstance(std::vector<playerState> pInstance)
{
    playerInstance = pInstance;
}


// gets and sets teamInstance
std::vector <teamState> gameState::getTeamInstance()
{
    return (teamInstance);
}
void gameState::setTeamInstance(std::vector<teamState> Instance)
{
    teamInstance = Instance;
}

// gets and sets basketballInstance std::vector
std::vector <basketballs> gameState::getBasketballInstance()
{
    return (basketballInstance);
}
 void gameState::setBasketballInstance(std::vector<basketballs> bballInstance)
{
    basketballInstance = bballInstance;
}

// gets and sets tipOffComplete
bool gameState::getTipOffComplete()
{
    return (tipOffComplete);
}
void gameState::setTipOffComplete(bool complete)
{
    tipOffComplete = complete;
}

bool gameState::getBallTipped()	// retrieves the value of the ballTipped variable
{
	return (ballTipped);
}
void gameState::setBallTipped(bool tipped)	// sets the value of the ballTipped variable
{
	ballTipped = tipped;
}

int gameState::getBallTippedToPlayer()	// retrieves the value of the ballTippedToPlayer variable
{
	return (ballTippedToPlayer);
}
void gameState::setBallTippedToPlayer(int player)	// sets the value of the ballTippedToPlayer variable
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

// gets and sets gameStarted
bool gameState::getGameStarted(void)
{
    return(gameStarted);
}
void gameState::setGameStarted(bool started)
{
    gameStarted = started;
}

// gets and sets shotTaken
bool gameState::getShotTaken(void)
{
    return(shotTaken);
}
void gameState::setShotTaken(bool taken)
{
    shotTaken = taken;
}

// gets and sets shotComplete
bool gameState::getShotComplete(void)
{
    return(shotComplete);
}
void gameState::setShotComplete(bool complete)
{
    shotComplete = complete;
}

int gameState::getTeamWithBall(void)		// retrieves teamWithBall value
{
	return (teamWithBall);
}
void gameState::setTeamWithBall(int ball)	// sets teamWithBall value
{
	teamWithBall = ball;
}

int gameState::getPlayerWithBall(void) 	// retrives the value of playerWithBall
{
	return (playerWithBall);
}
void gameState::setPlayerWithBall(int ball)	// sets the value of playerWithBall
{
	playerWithBall = ball;
}

bool gameState::getPlayerWithBallDribbling()	// retrieves the value of playerWithBallDribbling
{
	return (playerWithBallDribbling);
}
void gameState::setPlayerWithBallDribbling(bool dribbling)	// sets the value of playerWithBallDribbling
{
	playerWithBallDribbling = dribbling;
}

int gameState::getBballBounce()	// retrieves the value of bballBounce
{
	return (bballBounce);
}
void gameState::setBballBounce(int bounce)	// sets the value of bballBounce
{
	bballBounce = bounce;
}

// assigns teams that are playing to the game state machine
bool gameState::assignTeams()
{
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
    gameState *gameS = gameState::Instance();
    players *player = players::Instance();
    teams *team = teams::Instance();

    std::vector<teamData> teamN = team->getTeamArray(); // stores the contents of teamArray in teamN
//    boost::shared_ptr<teamData> teamN; // = team->getTeamArray(); // stores the contents of teamArray in teamN
    // sets the players used on both teams
    std::vector<int> team1Starters;  // stores team 1 starters
    std::vector<int> team2Starters;  // stores team 2 starters
    for (int x = 0; x < teamN.size(); ++x)      // loops through teamN std::vector
    {
        if (teamN[x].getID() == teamID[0])     // checks if teamN's ID matches that of teamIDS[0]
        {

            team1Starters = teamN[x].getStarters();     // copies the starters to the team1Starters std::vector
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
    	cout << "playersIT == " << *playersIT << endl;
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

bool gameState::createPlayerInstances()
{
    players *player = players::Instance();

    std::vector <playerData> playerN = player->getPlayer(); // copies Player values to playerN
    std::vector <int>::iterator playerIT;
//    std::vector <playerState>::iterator pInstanceIT;
    int x = 0;
    for (playerIT = playerID.begin(); playerIT != playerID.end(); ++playerIT)   // loops through playerID std::vector
    {
            playerState pInstance;  // creates a new instance of playerState
            pInstance.setModelName(playerN[*playerIT].getModel());  // copies the model name from the playerData std::vector to the pInstance class
            pInstance.setFirstName(playerN[*playerIT].getFirstName());  // copies the first name from the playerData std::vector to the pInstance class
            pInstance.setLastName(playerN[*playerIT].getLastName());    // copies the last name from the playerData std::vector to the pInstance class
            pInstance.setPlayerName(playerN[*playerIT].getFirstName() + playerN[*playerIT].getLastName());
            pInstance.setPosChange(Ogre::Vector3(0.0f,0.0f,0.0f));
            playerInstance.push_back(pInstance);    // adds pInstance to the playerInstance std::vector.
    }
//    std::vector <playerState>::iterator pInstanceIT;

    int pInstanceIT = 0;
    for (pInstanceIT = 0; pInstanceIT < playerInstance.size(); ++pInstanceIT)
    {
    	if (std::find(playerModelsLoaded.begin(), playerModelsLoaded.end(), playerInstance[pInstanceIT].getPlayerName()) != playerModelsLoaded.end())
    	{
//    		cout << "Found Player Name in list of loaded Models, NOT Loading" << endl;
    	    Ogre::LogManager::getSingletonPtr()->logMessage("Found Player Name in list of loaded Models, NOT Loading");

    	}
    	else
    	{
			if (playerInstance[pInstanceIT].loadModel())	// if player model loads successfully add to loaded models vector
			{
				playerModelsLoaded.push_back(playerInstance[pInstanceIT].getPlayerName());
			}
    	}
            x += 1;
            cout << "x = " << x << endl;
    }
    return true;
}

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

    return true;
}

// creates court Instances
bool gameState::createCourtInstances()
{
    courtState cInstance;  // creates an instance of the courtState class
//    cInstance.setModelName("court.mesh");
    cInstance.setModelName("Court.mesh");
    cInstance.loadModel();
    courtInstance.push_back(cInstance);

    return true;
}


bool gameState::setupEnvironment()
{
    renderEngine *render = renderEngine::Instance();

    // Set ambient light
    render->getMSceneMgr()->setAmbientLight(ColourValue(0.5, 0.5, 0.5));

    // Create a light
    Light* l = render->getMSceneMgr()->createLight("MainLight");
    l->setPosition(20,80,56);


    return true;
}

void gameState::setPlayerStartPositions()	// sets the initial coordinates for the players.
{

    // set initial player coordinates for the tipoff

    playerInstance[0].getNode()->setPosition(14.4f,-23.5f,352.0f);
    playerInstance[1].getNode()->setPosition(2.0f,-23.5f,347.6f);
    playerInstance[2].getNode()->setPosition(2.0f,-23.5f,360.0f);
    playerInstance[3].getNode()->setPosition(5.2f,-23.5f,351.6f);
    playerInstance[4].getNode()->setPosition(1.6f,-23.5f,352.0f);
    playerInstance[5].getNode()->setPosition(-12.8f,-23.5f,352.0f);
    playerInstance[6].getNode()->setPosition(-0.8f,-23.5f,347.6f);
    playerInstance[7].getNode()->setPosition(-0.8f,-23.5f,360.8f);
    playerInstance[8].getNode()->setPosition(4.4f,-23.5f,348.8f);
    playerInstance[9].getNode()->setPosition(-0.4f,-23.5f,352.0f);


    // sets starting player Directions
    playerInstance[0].setDirection(RIGHT);
    playerInstance[1].setDirection(RIGHT);
    playerInstance[2].setDirection(RIGHT);
    playerInstance[3].setDirection(RIGHT);
    playerInstance[4].setDirection(RIGHT);
    playerInstance[5].setDirection(RIGHT);
    playerInstance[6].setDirection(RIGHT);
    playerInstance[7].setDirection(RIGHT);
    playerInstance[8].setDirection(RIGHT);
    playerInstance[9].setDirection(RIGHT);

}

void gameState::setBasketballStartPositions()// sets the initial coordinates for the basketball(s)
{
	basketballInstance[0].getNode()->setPosition(0.8f,-5.0f,352.0f);
	courtInstance[0].getNode()->setPosition(0.0f,-27.5,360);
}
// sets up tip off conditions
bool gameState::setupTipOff()
{
//    basketballs *basketball = basketballs::Instance();
//    gameState *gameS = gameState::Instance();
//    players *player = players::Instance();
    teams *team = teams::Instance();

//    std::vector<basketballs> basketballInstance = getBasketballInstance();
    SceneNode *bball;
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
    players *player = players::Instance();
    renderEngine *render = renderEngine::Instance();
    teams *team = teams::Instance();
    loader *load = loader::Instance();
    physicsEngine *physEngine = physicsEngine::Instance();

    Ogre::LogManager::getSingletonPtr()->logMessage("Setting up state!");
    load->loadTeams();  // loads teams from XML files
    load->loadPlayers();    // loads players from XML files

    team->assignPlayers();  // assigns players to teams
    team->assignStarters(); // assigns starting players to teams

    assignTeams();    // assigns teams playing

    assignPlayers();  // assigns players currently playing

    if (!teamInstancesCreated)	// checks if teamInstances have been created
    {
    	if(createTeamInstances())	// creates the team instances
    	{
    		teamInstancesCreated = true;
    	}
    }
    if (!playerInstancesCreated)	// checks if playerInstances have been created
    {
    	if (createPlayerInstances()) // creates the player instances based on playerIDS
		{
    		playerInstancesCreated = true;
		}
    }
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

    setPlayerStartPositions();	// sets starting positions for the players
    setBasketballStartPositions();	// sets starting positions for all basketballs that are instantiated

//    basketballInstance[0].getNode()->setPosition(1.4f,5.0f,366.0f);

    physEngine->setupState();  // sets up the Physics Engine state

    physEngine->setupPlayerPhysics(); // sets up physics state for players

    physEngine->setupCourtPhysics(); // sets up physics state for court

    physEngine->setupBasketballPhysics(); // sets up physics state for basketball

//        Ogre::Entity *ent;
//        ent = player->getModel(0);
//        player->mAnimationState2 = ent->getAnimationState("Walk");
//        std::vector<Ogre::Entity*> playerModels = player->getModel();
//        std::vector<Ogre::SceneNode*> playerNodes = player->getNode();
//    std::vector<playerState> pInstance = getPlayerInstance();
    player->mAnimationState2 =  playerInstance[5].getModel()->getAnimationState("Walk");
    player->mAnimationState2->setLoop(true);
    player->mAnimationState2->setEnabled(true);
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

//    teamWithBall = 0;	// FIXME! Temporarily hard code team controlling ball
    playerWithBall = 9; // FIXME! Temporarily ahrd code player controlling ball

    return true;
}

// carries out in game logic
bool gameState::logic()
{
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

//    Ogre::LogManager::getSingletonPtr()->logMessage(("Player's start position: "  +Ogre::StringConverter::toString(playerInstance[3].getNode()->getPosition())));
    Ogre::LogManager::getSingletonPtr()->logMessage(("Player with ball's current position: "  +Ogre::StringConverter::toString(playerInstance[playerWithBall].getNode()->getPosition())));
    Ogre::LogManager::getSingletonPtr()->logMessage(("Court's current position: "  +Ogre::StringConverter::toString(courtInstance[0].getNode()->getPosition())));
    Ogre::LogManager::getSingletonPtr()->logMessage(("Basketball's current position: "  +Ogre::StringConverter::toString(basketballInstance[0].getNode()->getPosition())));

    if (tipOffComplete)
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

    	    if (playerInstance[playerWithBall].getPassBall())	// checks if the player with ball is passing it.
    	    {
    	    	if (!playerInstance[playerWithBall].getPassCalculated())
    	    	{
    	    		Ogre::Vector3 bballPos;
    	    		Ogre::Vector3 playerPos;
    	    		playerInstance[playerWithBall].calculatePass();

    	    		//sets the basketball Height;
    	    		bballPos = basketballInstance[0].getNode()->getPosition();
    	    		playerPos = playerInstance[playerWithBall].getNode()->getPosition();
    	    		bballPos[1] = playerPos[1];
    	    		basketballInstance[0].getNode()->setPosition(bballPos);
    	    	}
    	    	else if (physEngine->getPassCollision())	// checks if ball has collided with player being passed to.
    	    	{
    	    		playerInstance[playerWithBall].setPassBall(false);	// player is no longer passing the ball
    	    		playerWithBall = playerInstance[playerWithBall].getPassToPlayer(); // playerWithBall has changed
    	    		physEngine->setPassCollision(false);	// resets the pass collision state

    	    	}
    	    	else
    	    	{
    	    		executePass();
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
//    physEngine->updateState();
//   playerInstance[0].setMovement(true);
//   playerInstance[0].setDirection(RIGHT);


    physEngine->updateState();
    updateDirectionsAndMovements();

    updatePositions();   // updates positions of game world objects


    if (getShotTaken() && !getShotComplete())	// checks if a player takes a shot
    {
        shotLogic(playerPos);
    }

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
/*    if (teamWithBall == 0)	// if 0 puts team 0 on offense and team 1 on defense
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
*/
    // updates the state of each team
    teamInstance[0].updateState();
    teamInstance[1].updateState();


    return true;
}

void gameState::shotLogic(Ogre::Vector3 playerPos)
{
    players *player = players::Instance();
//    Ogre::Vector3 playerPos;
    std::vector<basketballs> basketballInstance = getBasketballInstance();
    std::vector<playerState> pInstance = getPlayerInstance();

    // checks if a player has taken a shot
    if (getShotTaken())
    {

        basketballInstance[0].setDribbling(false);
//    		basketballInstance[0].getNode()->setParent(mSceneMgr->getRootSceneNode());
        Ogre::Vector3 pos = basketballInstance[0].getNode()->getPosition();
        basketballInstance[0].setMaxHeight(pos[1] + 10.0f);
        basketballInstance[0].setMinHeight(pos[1] - 10.0f);
        Ogre::Vector3 velocity;
        Ogre::Vector3 startCoords;
        startCoords[0] = playerPos[0] + 1.0f;
        startCoords[1] = playerPos[1] + 1.0f;
        startCoords[2] = playerPos[2] + 1.0f;
        velocity[0] = 0.90f;
        velocity[1] = 0.80f;
        velocity[2] = 0.0f;
        basketballInstance[0].setVelocity(velocity);
        basketballInstance[0].setStartCoords(startCoords);
        basketballInstance[0].getNode()->setPosition(startCoords);
        setShotTaken(false);
        setShotComplete(false);
        basketballInstance[0].setMaxHeightReached(false);
        basketballInstance[0].setMinHeightReached(false);
    //		basketballInstance[0].setPlayer(-1);
    }

    if (getShotComplete())
    {

        basketballInstance[0].setPlayer(5);
        basketballInstance[0].setDribblingStart(true);
        playerPos = pInstance[basketballInstance[0].getPlayer()].getNode()->getPosition();
        basketballInstance[0].getNode()->setPosition(playerPos[0] +2.0f, playerPos[1] + 4.0f, playerPos[2] - 1.0f);
        setShotComplete(false);
    }

}

void gameState::processNetworkEvents()	// processes events from network code
{
    networkEngine *network = networkEngine::Instance();

//	std::vector <playerState> playerInstance = gameS->getPlayerInstance();

	if(Ogre::StringUtil::startsWith(network->getReceivedData(), "player" ))
	{
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

	Ogre::String receivedData = network->getReceivedData();	// stores receivedData value
	int playerNumber = -1; // stores which player the data is for
	int iterator;	// iterator for match loop
	for (iterator = 0; iterator < 10; ++iterator)
	{
		Ogre::String searchString;	// stores search String
		Ogre::String searchIterator = Ogre::StringConverter::toString(iterator); // converts iterator to a string
		searchString = "*" +searchIterator + "*";	// creates search string
		if (Ogre::StringUtil::match(receivedData,searchString))	// checks for a match
		{
			playerNumber = iterator;	// sets playerNumber to value of iterator
		}
	}

	// checks what is at the end of the receivedData string
	if (Ogre::StringUtil::endsWith(receivedData, "up"))	// checks if player moved upward
	{
//		Ogre::Vector3 Pos = Ogre::Vector3(0.0f, 0.400f, 0.0f);
//		playerInstance[playerNumber].getNode()->translate(Pos);
		playerInstance[playerNumber].setMovement(true);
		playerInstance[playerNumber].setDirection(UP);

	}
	else if (Ogre::StringUtil::endsWith(receivedData, "down"))	// checks if player moved downward
	{
//		Ogre::Vector3 Pos = Ogre::Vector3(0.0f, -0.400f, 0.0f);
//		playerInstance[playerNumber].getNode()->translate(Pos);
		playerInstance[playerNumber].setMovement(true);
		playerInstance[playerNumber].setDirection(DOWN);

	}
	else if (Ogre::StringUtil::endsWith(receivedData, "left")) // checks if player moved left
	{
//		Ogre::Vector3 Pos = Ogre::Vector3(-0.400f, 0.0f, 0.0f);
//		playerInstance[playerNumber].getNode()->translate(Pos);
		playerInstance[playerNumber].setMovement(true);
		playerInstance[playerNumber].setDirection(LEFT);

	}
	else if (Ogre::StringUtil::endsWith(receivedData, "right"))	// checks if player moved right
	{
//		Ogre::Vector3 Pos = Ogre::Vector3(0.400f, 0.0f, 0.0f);
//		playerInstance[playerNumber].getNode()->translate(Pos);
		playerInstance[playerNumber].setMovement(true);
		playerInstance[playerNumber].setDirection(RIGHT);

	}
	else if (Ogre::StringUtil::endsWith(receivedData, "shootblock")) // checks if player attempted shot or block
	{

	}
	else if (Ogre::StringUtil::endsWith(receivedData, "passsteal"))	// checks if player attempted pass or steal
	{

	}

	network->setReceivedData("");
}

void gameState::updateDirectionsAndMovements()
{
    directions playerDirection, oldPlayerDirection;

    updatePlayerMovements();	// updates movement of player objects
    updateBasketballMovements();	// updates the movement of basketball objec(s)
    updatePlayerDirections();	// updates the direction the players are facing
    updateBasketballDirections(); // updates direction of basketball object(s)

}
void gameState::updatePlayerDirections()
{
    players *player = players::Instance();

    directions playerDirection, oldPlayerDirection;

//    std::vector<playerState> pInstance = getPlayerInstance();
 //   std::vector<int> playerDirection = player->getPlayerDirection(); // stores contents of playerDirectdion from players class in local variable
//    std::vector<int> oldPlayerDirection = player->getOldPlayerDirection();   // stores contents of oldPlayerDirection form players in local variable
	std::vector<basketballs> basketballInstance = getBasketballInstance();
    std::vector<Ogre::SceneNode>::iterator playersIT;

    Ogre::String playerID = Ogre::StringConverter::toString(playerInstance[4].getPlayerID());
    Ogre::LogManager::getSingletonPtr()->logMessage("playerID == " +playerID);
    // checks if a player's direction has changed and rotates the model accordingly.
//    for(playersIT = playerNodes.begin(); playersIT != playerNodes.end(); ++playersIT)
    for (int i = 0; i < playerInstance.size(); ++i)
    {
    	playerDirection = playerInstance[i].getDirection();
    	oldPlayerDirection = playerInstance[i].getOldDirection();
        if (oldPlayerDirection != playerDirection)
        {
        	/*
        	Ogre::String oldPlayerDirect = Ogre::StringConverter::toString(oldPlayerDirection[i]);
        	Ogre::String playerDirect = Ogre::StringConverter::toString(playerDirection[i]);
        	Ogre::String bballPlayer = Ogre::StringConverter::toString(basketballInstance[0].getPlayer());
            Ogre::LogManager::getSingletonPtr()->logMessage("oldPlayerDirection = " + oldPlayerDirect);
            Ogre::LogManager::getSingletonPtr()->logMessage("playerDirection = " + playerDirect);
            Ogre::LogManager::getSingletonPtr()->logMessage("bball player = " + bballPlayer);
            playerInstance[basketballInstance[0].getPlayer()] = playerInstance[i];
//            playerNodes.at(basketballInstance[0].getPlayer()) = playerNodes.at(i);  // sets the current player node
            */
            switch (oldPlayerDirection)
            {
                case UP:
                 	switch (playerDirection)
                    {
                        case DOWN:
                            playerInstance[i].getNode()->yaw(Degree (180));
                            break;
                        case LEFT:
                            playerInstance[i].getNode()->yaw(Degree (270));
                            break;
                        case RIGHT:
                            playerInstance[i].getNode()->yaw(Degree (90));
                            break;
                        default:
                            break;
                    }
                	break;
                case DOWN:
                	switch (playerDirection)
                    {
                        case UP:
                            playerInstance[i].getNode()->yaw(Degree (180));
                            break;
                        case LEFT:
                            playerInstance[i].getNode()->yaw(Degree (90));
                            break;
                        case RIGHT:
                            playerInstance[i].getNode()->yaw(Degree (270));
                            break;
                        default:
                            break;
                    }
                	break;
                	case LEFT:
                    	switch (playerDirection)
                        {
                            case UP:
                                playerInstance[i].getNode()->yaw(Degree (90));
                                break;
                            case DOWN:
                                playerInstance[i].getNode()->yaw(Degree (270));
                                break;
                            case RIGHT:
                                playerInstance[i].getNode()->yaw(Degree (180));
                                break;
                            default:
                                break;
                        }
                    	break;
					case RIGHT:
						switch (playerDirection)
						{
							case UP:
								playerInstance[i].getNode()->yaw(Degree (270));
								break;
							case DOWN:
								playerInstance[i].getNode()->yaw(Degree (90));
								break;
							case LEFT:
								playerInstance[i].getNode()->yaw(Degree (180));
								break;
							default:
								break;
						}
						break;
                default:
                	break;
            }
        }

        if (i != playerWithBall)
        {
        	oldPlayerDirection = playerDirection;
        	playerInstance[i].setOldDirection(oldPlayerDirection);  // copies contents of oldPlayerDirection to the oldDirection variable
        }
        else
        {
        }
    }
}

void gameState::updatePlayerMovements()	// updates player movements
{
	Ogre::Vector3 posChange;	// stores change in position

	posChange = Ogre::Vector3(0.0f, 0.0f, 0.0f);

	for (int i = 0; i < playerInstance.size(); ++i)
	{
		if (playerInstance[i].getMovement())	// if true sets coordinate change accordingly
		{
			if (playerInstance[i].getDirection() == UP)
			{
				posChange = Ogre::Vector3(0.0f, 0.0f, -0.400f);
			}
			else if (playerInstance[i].getDirection() == DOWN)
			{
				posChange = Ogre::Vector3(0.0f, 0.0f, 0.400f);
			}
			else if (playerInstance[i].getDirection() == LEFT)
			{
				posChange = Ogre::Vector3(-0.400f, 0.0f, 0.0f);
//			    playerInstance[i].getPhysBody()->setLinearVelocity(btVector3(0.4,0,0));
			}
			else if (playerInstance[i].getDirection() == RIGHT)
			{
				posChange = Ogre::Vector3(0.400f, 0.0f, 0.0f);
			}
			else if (playerInstance[i].getDirection() == UPLEFT)
			{
				posChange = Ogre::Vector3(-0.400f, 0.0f, -0.400f);
			}
			else if (playerInstance[i].getDirection() == UPRIGHT)
			{
				posChange = Ogre::Vector3(0.400f, 0.0f, -0.400f);
			}
			else if (playerInstance[i].getDirection() == DOWNLEFT)
			{
				posChange = Ogre::Vector3(-0.400f, 0.0f, 0.400f);
			}
			else if (playerInstance[i].getDirection() == DOWNRIGHT)
			{
				posChange = Ogre::Vector3(0.400f, 0.0f, 0.400f);
			}

		}
		else if (!playerInstance[i].getMovement())	// if false then sets their coordinate changes to 0.0
		{
			posChange = Ogre::Vector3(0.0f, 0.0f, 0.0f);
		}

		playerInstance[i].setPosChange(posChange);	// sets the posChange for current playerInstance
		if (i != playerWithBall)	// only updates movement flag if player doesn't have ball
		{
			playerInstance[i].setMovement(false);
		}
		else
		{
		}
	}
}

void gameState::updateBasketballMovements()	// updates the basketball(s) movements
{
	directions playerDirection = playerInstance[playerWithBall].getDirection();
	directions oldPlayerDirection = playerInstance[playerWithBall].getOldDirection();

	if (playerWithBall >= 0 && tipOffComplete == true)	// verifies that the playerWithBall variable is set to a valid number
	{
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

void gameState::updateBasketballDirections()	// updates basketball direction(s)
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
        Ogre::LogManager::getSingletonPtr()->logMessage("playerDirection = " + Ogre::StringConverter::toString(playerDirection));
        Ogre::LogManager::getSingletonPtr()->logMessage("oldPlayerDirection = " + Ogre::StringConverter::toString(oldPlayerDirection));

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

void gameState::executePass()		// executes the pass between players
{
	int passToPlayer = playerInstance[playerWithBall].getPassToPlayer();

	Ogre::Vector3 playerWithBallCoords = playerInstance[playerWithBall].getNode()->getPosition();
	Ogre::Vector3 passToPlayerCoords = playerInstance[passToPlayer].getNode()->getPosition();
	Ogre::Vector3 bballCoords = basketballInstance[0].getNode()->getPosition();
	btVector3 bballPosChange = btVector3(0,0,0);
	btVector3 bballPhysCoords = btVector3(0,0,0);
	btTransform transform;

    Ogre::LogManager::getSingletonPtr()->logMessage("Basketball = " + Ogre::StringConverter::toString(bballCoords));
    Ogre::LogManager::getSingletonPtr()->logMessage("passToPlayer = " + Ogre::StringConverter::toString(passToPlayerCoords));

    if (bballCoords[1] != passToPlayerCoords[1])
    {
    	bballCoords[1] = passToPlayerCoords[1];
    	basketballInstance[0].getNode()->setPosition(bballCoords);
		bballPhysCoords = BtOgre::Convert::toBullet(bballCoords); // converts from Ogre::Vector3 to btVector3
		transform.setOrigin(bballPhysCoords);
		basketballInstance[0].getPhysBody()->setWorldTransform(transform);


    }
	if (bballCoords[0] < passToPlayerCoords[0])
	{
		if (bballCoords[2] < passToPlayerCoords[2])
		{
//	    	basketballInstance[0].getPhysBody()->setLinearVelocity(btVector3(15,0,15));
			bballPosChange[0] = 15;
			bballPosChange[2] = 15;
		}
		else if (bballCoords[2] > passToPlayerCoords[2])
		{
//	    	basketballInstance[0].getPhysBody()->setLinearVelocity(btVector3(15,0,-15));
			bballPosChange[0] = 15;
			bballPosChange[2] = -15;

		}
		else
		{
		}
	}
	else if (bballCoords[0] > passToPlayerCoords[0])
	{
		if (bballCoords[2] < passToPlayerCoords[2])
		{
//	    	basketballInstance[0].getPhysBody()->setLinearVelocity(btVector3(-15,0,15));
			bballPosChange[0] = -15;
			bballPosChange[2] = 15;

		}
		else if (bballCoords[2] > passToPlayerCoords[2])
		{
//	    	basketballInstance[0].getPhysBody()->setLinearVelocity(btVector3(-15,0,-15));
			bballPosChange[0] = -15;
			bballPosChange[2] = -15;

		}
		else
		{
		}
	}
	else
	{
	}

/*
    if (bballCoords[0] < passToPlayerCoords[0])
    {
    	bballPosChange[0] = 15;
    }
    else if (bballCoords[0] > passToPlayerCoords[0])
    {
    	bballPosChange[0] = -15;
    }
    else
    {
    	bballPosChange[0] = 0;
    }

    if (bballCoords[1] < passToPlayerCoords[1])
    {
    	bballPosChange[1] = 40;
    }
    else if (bballCoords[1] > passToPlayerCoords[1])
    {
    	bballPosChange[1] = -40;
    }
    else
    {
    	bballPosChange[1] = 0;
    }

    if (bballCoords[2] < passToPlayerCoords[2])
    {
    	bballPosChange[2] = 15;
    }
    else if (bballCoords[2] > passToPlayerCoords[2])
    {
    	bballPosChange[2] = -15;
    }
    else
    {
    	bballPosChange[2] = 0;
    }
*/
	basketballInstance[0].getPhysBody()->setLinearVelocity(btVector3(bballPosChange));


}



// updates positions of gameState objects
bool gameState::updatePositions()
{
	int x = 0;
	std::vector<playerState>::iterator playerIT;
//	cout << "Size = " << playerInstance.size() << endl;
	Ogre::LogManager::getSingletonPtr()->logMessage("Size = " +Ogre::StringConverter::toString(playerInstance.size()));
	//	for (playerIT = playerInstance.begin(); playerIT != playerInstance.end(); ++playerIT)

	// updates the player positions on the court
	for (int x = 0; x < playerInstance.size(); ++x)
	{
//		x += 1;
//		cout << "X = " << x << endl;
		Ogre::LogManager::getSingletonPtr()->logMessage("updatePositions X = " +Ogre::StringConverter::toString(x));
        playerInstance[x].updatePosition();
    }

	// updates the basketball(s) position on the court
	for (int x = 0; x < basketballInstance.size(); ++x)
	{
		basketballInstance[x].updatePosition();
	}

    return true;
}
