/***************************************************************************
 *   Copyright (C) 2006 by Mike McLean   *
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
#include "load.h"
#include "playerdata.h"
#include "players.h"
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
    gameStarted = false;
    shotTaken = false;
    shotComplete = false;
    tipOffComplete = false;

    currentQuarter = FIRST;
    gameTimeLeft = 0.0f;
    quarterTimeLeft = 0.0f;
    finished = false;
}
gameState::~gameState()
{
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


// assigns teams that are playing to the game state machine
bool gameState::assignTeams()
{
    gameState *gameS = gameState::Instance();

    // sets the teams that are playing to teamID
    std::vector<int> teamIDS;
    teamIDS.push_back(1);
    teamIDS.push_back(2);
    gameS->setTeamID(teamIDS);

    return true;
}

// assigns the players that are playing to the game state machine
bool gameState::assignPlayers()
{
    gameState *gameS = gameState::Instance();
    players *player = players::Instance();
    teams *team = teams::Instance();

    std::vector<teamData> teamN = team->getTeamArray(); // stores the contents of teamArray in teamN

    // sets the players used on both teams
    std::vector<int> teamIDS = gameS->getTeamID();  // gets the teamIDs
    std::vector<int> team1Starters;  // stores team 1 starters
    std::vector<int> team2Starters;  // stores team 2 starters

    for (int x = 0; x < teamN.size(); ++x)      // loops through teamN std::vector
    {
        if (teamN[x].getID() == teamIDS[0])     // checks if teamN's ID matches that of teamIDS[0]
        {
            team1Starters = teamN[x].getStarters();     // copies the starters to the team1Starters std::vector
        }
        else if (teamN[x].getID() == teamIDS[1])        // checks if teamN's ID matches taht of teamIDs[1]
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

// sets up tip off conditions
bool gameState::setupTipOff()
{
//    basketballs *basketball = basketballs::Instance();
    gameState *gameS = gameState::Instance();
    players *player = players::Instance();
    teams *team = teams::Instance();

    std::vector<basketballs> bballInstance = gameS->getBasketballInstance();
    SceneNode *bball;
    bball = bballInstance[0].getNode();
    bball->setPosition(0.0f,-20.0f,350.0f);
    bballInstance[0].setNode(bball);
    bballInstance[0].setTipOffStart(true);

    gameS->setBasketballInstance(bballInstance);

    std::vector<int> playerIDS = gameS->getPlayerID();
    std::vector <playerState> pInstance = gameS->getPlayerInstance();
//    std::vector <Ogre::SceneNode*> playerNodes = player->getNode();

    pInstance[0].getNode()->setPosition(0.0f,-23.5f,380.0f);
    // set initial player coordinates for the tipoff
    pInstance[0].getNode()->setPosition(0.0f,-23.5f,380.0f);
    pInstance[1].getNode()->setPosition(5.5f,-23.5f,360.0f);
    pInstance[2].getNode()->setPosition(-3.0f,-23.5f,360.0f);
    pInstance[3].getNode()->setPosition(-6.0f,-23.5f,360.0f);
    pInstance[4].getNode()->setPosition(-0.5f,-23.5f,350.0f);
    pInstance[5].getNode()->setPosition(-12.0f,-23.5f,360.0f);
    pInstance[6].getNode()->setPosition(-15.0f,-23.5f,360.0f);
    pInstance[7].getNode()->setPosition(-6.0f,-23.5f,380.0f);
    pInstance[8].getNode()->setPosition(-3.0f,-23.5f,370.0f);
    pInstance[9].getNode()->setPosition(2.5f,-23.5f,350.0f);

//    player->setNode(playerNodes);   // copies playerNodes std::vector to Node std::vector in players class
    return true;
}

// executes tip off
bool gameState::executeTipOff()
{
    gameState *gameS = gameState::Instance();
    players *player = players::Instance();

    std::vector<basketballs> bballInstance = gameS->getBasketballInstance();

    bballInstance[0].nodeChangePosition(bballInstance[0].calculatePositionChange());

   gameS->setBasketballInstance(bballInstance);
    return true;
}

// sets up the game condition
bool gameState::setupState()
{
    gameState *gameS = gameState::Instance();
    players *player = players::Instance();
    renderEngine *render = renderEngine::Instance();
    teams *team = teams::Instance();
    loader *load = loader::Instance();

    load->loadTeams();  // loads teams from XML files
    load->loadPlayers();    // loads players from XML files

    team->assignPlayers();  // assigns players to teams
    team->assignStarters(); // assigns starting players to teams

    assignTeams();    // assigns teams playing

    assignPlayers();  // assigns players currently playing

    gameS->createPlayerInstances(); // creates the player instances based on playerIDS

    gameS->createBasketballInstances(); // creates the basketball instances

    gameS->createCourtInstances();  // creates the court instances


//        Ogre::Entity *ent;
//        ent = player->getModel(0);
//        player->mAnimationState2 = ent->getAnimationState("Walk");
//        std::vector<Ogre::Entity*> playerModels = player->getModel();
//        std::vector<Ogre::SceneNode*> playerNodes = player->getNode();
        std::vector<playerState> pInstance = gameS->getPlayerInstance();
        player->mAnimationState2 =  pInstance[5].getModel()->getAnimationState("Walk");
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

    setupEnvironment();
//	loads("../../data/players/players.xml");

    setupTipOff();	// sets up tip off conditions

    return true;
}

// carries out in game logic
bool gameState::logic()
{
    gameState *gameS = gameState::Instance();
    players *player = players::Instance();
    Ogre::Vector3 playerPos;

	std::vector<basketballs> bballInstance = gameS->getBasketballInstance();
	// sets up and starts the dribbling animation
//	bballInstance[0].setDribblingStart(true);
    bballInstance[0].setPlayer(5);

    gameS->updatePositions();   // updates positions of game world objects

    std::vector<playerState> pInstance = gameS->getPlayerInstance();

//    LogManager::getSingletonPtr()->logMessage("pInstance pos = " + pInstance[bballInstance[0].getPlayer()].getPosChange());
    bballInstance[0].nodeChangePosition(pInstance[bballInstance[0].getPlayer()].getPosChange());
    if (bballInstance[0].getPlayer() >= 0)
    {
        playerPos = pInstance[bballInstance[0].getPlayer()].getNode()->getPosition();
//        exit(0);
//        playerPos = player->getNode(bballInstance[0].getPlayer())->getPosition();
    }
//    exit(0);
    // checks if a player has taken a shot
    if (getShotTaken())
    {
        bballInstance[0].setDribbling(false);
    //		bballInstance[0].getNode()->setParent(mSceneMgr->getRootSceneNode());
        Ogre::Vector3 pos = bballInstance[0].getNode()->getPosition();
        bballInstance[0].setMaxHeight(pos[1] + 10.0f);
        bballInstance[0].setMinHeight(pos[1] - 10.0f);
        Ogre::Vector3 velocity;
        Ogre::Vector3 startCoords;
        startCoords[0] = playerPos[0] + 1.0f;
        startCoords[1] = playerPos[1] + 1.0f;
        startCoords[2] = playerPos[2] + 1.0f;
        velocity[0] = 0.90f;
        velocity[1] = 0.80f;
        velocity[2] = 0.0f;
        bballInstance[0].setVelocity(velocity);
        bballInstance[0].setStartCoords(startCoords);
        bballInstance[0].getNode()->setPosition(startCoords);
        setShotTaken(false);
        setShotComplete(false);
        bballInstance[0].setMaxHeightReached(false);
        bballInstance[0].setMinHeightReached(false);
    //		bballInstance[0].setPlayer(-1);
    }

    if (getShotComplete())
    {
        bballInstance[0].setPlayer(5);
        bballInstance[0].setDribblingStart(true);
        playerPos = pInstance[bballInstance[0].getPlayer()].getNode()->getPosition();
        bballInstance[0].getNode()->setPosition(playerPos[0] +2.0f, playerPos[1] + 4.0f, playerPos[2] - 1.0f);
        setShotComplete(false);
    }

//    exit(0);
//    renderBall();
//    SceneNode *bball = bballInstance[0].getNode();
//    bball->setPosition(bballInstance[0].calculatePositionChange());
//    bballInstance[0].setNode(bball);

    Ogre::Vector3 change = bballInstance[0].calculatePositionChange();
//    cout << "Calced Pos change = " << bballInstance[0].calculatePositionChange() << endl;
    bballInstance[0].nodeChangePosition(bballInstance[0].calculatePositionChange());

    std::vector<int> playerDirection = player->getPlayerDirection(); // stores contents of playerDirectdion from players class in local variable
    std::vector<int> oldPlayerDirection = player->getOldPlayerDirection();   // stores contents of oldPlayerDirection form players in local variable

    if (i < 200)
    {
        j = 0;
        pInstance[bballInstance[0].getPlayer()].getNode()->translate(0.02f, 0.0f, 0.0f);
        playerDirection[1] = 4;
        i++;
    }
    else
    {
        if (j < 200)
        {
            pInstance[bballInstance[0].getPlayer()].getNode()->translate(-0.02f,0.0f,0.0f);
            playerDirection[1] = 3;
            j++;
    	}
        else
        {
            i = 0;
        }
    }


    std::vector<Ogre::SceneNode>::iterator playersIT;
    // checks if a player's direction has changed and rotates the model accordingly.
//    for(playersIT = playerNodes.begin(); playersIT != playerNodes.end(); ++playersIT)
    for (int i = 0; i < 10; i++)
    {
        if (oldPlayerDirection[i] != playerDirection[i])
        {
            LogManager::getSingletonPtr()->logMessage("oldPlayerDirection = " + oldPlayerDirection[i]);
            LogManager::getSingletonPtr()->logMessage("playerDirection = " + playerDirection[i]);
            pInstance[bballInstance[0].getPlayer()] = pInstance[i];
//            playerNodes.at(bballInstance[0].getPlayer()) = playerNodes.at(i);  // sets the current player node
            switch (playerDirection[i])
            {
                case 1:
                    switch(oldPlayerDirection[i])
                    {
                        case 0:
                            pInstance[i].getNode()->yaw(Degree (90));
                            break;
                        case 2:
                            pInstance[i].getNode()->yaw(Degree (180));
                            break;
                        case 3:
                            pInstance[i].getNode()->yaw(Degree (270));
                            break;
                        case 4:
                            pInstance[i].getNode()->yaw(Degree (90));
                            break;
                        default:
                            break;
                    }
                    if (i == bballInstance[0].getPlayer())
                    {
                        bballInstance[0].getNode()->setPosition(playerPos[0] - 0.0f, playerPos[1] - 1.0f, playerPos[2] - 1.50f);
                    }
                    break;
                case 2:
                    switch(oldPlayerDirection[i])
                    {
                        case 0:
                            pInstance[i].getNode()->yaw(Degree (270));
                            break;
                    	case 1:
                            pInstance[i].getNode()->yaw(Degree (180));
                            break;
                    	case 3:
                            pInstance[i].getNode()->yaw(Degree (90));
                            break;
                    	case 4:
                            pInstance[i].getNode()->yaw(Degree (270));
                            break;
                        default:
                        break;
                    }
                    if (i == bballInstance[0].getPlayer())
                    {
                        bballInstance[0].getNode()->setPosition(playerPos[0] - 0.0f, playerPos[1] - 1.0f, playerPos[2] + 1.50f);
                    }
                    break;
            case 3:
                switch(oldPlayerDirection[i])
                {
                    case 0:
                        pInstance[i].getNode()->yaw(Degree (180));
                        break;
                    case 1:
                        pInstance[i].getNode()->yaw(Degree (90));
            		break;
                    case 2:
                        pInstance[i].getNode()->yaw(Degree (270));
                        break;
                    case 4:
                        pInstance[i].getNode()->yaw(Degree (180));
                        break;
                    default:
                        break;
                }
                if (i == bballInstance[0].getPlayer())
                {
                    bballInstance[0].getNode()->setPosition(playerPos[0] - 2.0f, playerPos[1] - 1.0f, playerPos[2] - 1.50f);
                }
                break;
            case 4:
                switch(oldPlayerDirection[i])
                {
                    case 0:
                        pInstance[i].getNode()->yaw(Degree (0));
                        break;
                    case 1:
                        pInstance[i].getNode()->yaw(Degree (270));
                        break;
                    case 2:
                        pInstance[i].getNode()->yaw(Degree (90));
                        break;
                    case 3:
                        pInstance[i].getNode()->yaw(Degree (180));
                        break;
                    default:
                        break;
                }
                if (i == bballInstance[0].getPlayer())
                {
                    bballInstance[0].getNode()->setPosition(playerPos[0] + 2.0f, playerPos[1] - 1.0f, playerPos[2] - 1.50f);
                }
                break;
            default:
                break;
            }
//      playerNode->yaw(Degree (90));
//      playerNode[0]->rotate(Vector3(0, 0, 1), Degree (90), Node::TS_LOCAL);
//      playerDirection[0] = 0;
//      playerDirectionChanged[i] = false;
        }

        oldPlayerDirection[i] = playerDirection[i];
    }
    player->setPlayerDirection(playerDirection);    // copies contents of playerDirection to similarly named variabl in class
    player->setOldPlayerDirection(oldPlayerDirection);  // copies contents of oldPlayer direction to similarly named variable in class
//    player->setNode(playerNodes);   // sets playerNodes to the node std::vector

    return true;
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

// creates the player Instances for the particular game

bool gameState::createPlayerInstances()
{
    players *player = players::Instance();

    std::vector <playerData> playerN = player->getPlayer(); // copies Player values to playerN
    std::vector <int>::iterator playerIT;
    for (playerIT = playerID.begin(); playerIT != playerID.end(); ++playerIT)   // loops through playerID std::vector
    {
            playerState pInstance;  // creates a new instance of playerState
            pInstance.setModelName(playerN[*playerIT].getModel());  // copies the model name from the playerData std::vector to the pInstance class
            pInstance.setFirstName(playerN[*playerIT].getFirstName());  // copies the first name from the playerData std::vector to the pInstance class
            pInstance.setLastName(playerN[*playerIT].getLastName());    // copies the last name from the playerData std::vector to the pInstance class
            pInstance.setPosChange(Ogre::Vector3(0.0f,0.0f,0.0f));
            playerInstance.push_back(pInstance);    // adds pInstance to the playerInstance std::vector.
    }
//    exit(0);
//    std::vector <playerState>::iterator pInstanceIT;
    int pInstanceIT = 0;
    for (pInstanceIT = 0; pInstanceIT < playerInstance.size(); ++pInstanceIT)
    {
        playerInstance[pInstanceIT].loadModel();
    }
    return true;
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

// creates basketball Instances
bool gameState::createBasketballInstances()
{
    basketballs bballInstance;  // creates an instance of the basketballs class
    bballInstance.setModelName("bball.mesh");
    bballInstance.loadModel();
    basketballInstance.push_back(bballInstance);
    return true;
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

// creates team Instances
bool gameState::createTeamInstances()
{
    return true;
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

// creates court Instances
bool gameState::createCourtInstances()
{
    courtState cInstance;  // creates an instance of the courtState class
    cInstance.setModelName("court.mesh");
    cInstance.loadModel();
    courtInstance.push_back(cInstance);

    return true;
}

// updates positions of gameState objects
bool gameState::updatePositions()
{
    for (int x = 0; x < playerInstance.size(); ++x)
    {
        playerInstance[x].updatePosition();
    }

    return true;
}
