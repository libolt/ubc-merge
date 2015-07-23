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

#include "network.h"

#include "gui.h"
#include "courtdata.h"
#include "gameengine.h"
#include "gamestate.h"
#include "load.h"
#include "logging.h"
#include "renderengine.h"
#include "teamdata.h"

#ifdef __ANDROID__
#include "android-config.h"
#else
#include "config.h"
#endif

GUISystem* GUISystem::pInstance = 0;
GUISystem* GUISystem::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new GUISystem; // create sole instance
    }
    return pInstance; // address of sole instance
}

// Initializes the GUISystem class
GUISystem::GUISystem()
{
//    mGUIRenderer = 0;
//    mGUISystem = 0;
//    mEditorGuiSheet =
//    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
//    QuickGUI::registerScriptParser();
    mainMenuCreated = false;
    networkSetupMenuCreated = false;
    networkServerSetupMenuCreated = false;
    networkClientSetupMenuCreated = false;
	optionsMenuCreated = false;
	displaySetupMenuCreated = false;
	inputSetupMenuCreated = false;
	audioSetupMenuCreated = false;
	gameSetupMenuCreated = false;
    gameSetupMenuAwaySelected = false;
	gameSetupMenuHomeSelected = false;
    playerStartSelectionMenuCreated = false;
    teamSelectionMenuCreated = false;
	courtSelectionMenuCreated = false;
    courtSelectionDataLoaded = false;
    
    menuActive = false;

	//activeMenu = NULL;
	//previousActiveMenu = NULL;

}

GUISystem::~GUISystem()
{

}

bool GUISystem::getMainMenuCreated()   // retrieves the value of mainMenuCreated
{
    return (mainMenuCreated);
}
void GUISystem::setMainMenuCreated(bool created) // sets the value of mainMenuCreated
{
    mainMenuCreated = created;
}

bool GUISystem::getBackButtonsCreated() // retrieves the value of backButtonsCreated
{
	return (backButtonsCreated);
}
void GUISystem::setBackButtonsCreated(bool created) // sets the value of backButtonsCreated
{
	backButtonsCreated = created;
}

bool GUISystem::getNetworkSetupMenuCreated()  // retrieves the value of networkSetupMenuCreated
{
    return (networkSetupMenuCreated);
}
void GUISystem::setNetworkSetupMenuCreated(bool created)  // sets the value of networkSetupMenuCreated
{
    networkSetupMenuCreated = created;
}

bool GUISystem::getOptionsMenuCreated()  // retrieves the value of optionsMenuCreated
{
	return (optionsMenuCreated);
}
void GUISystem::setOptionsMenuCreated(bool created)  // sets the value of optionsMenuCreated
{
	optionsMenuCreated = created;
}

bool GUISystem::getDisplaySetupMenuCreated()  // retrieves the value of displaySettingsMenuCreated
{
	return (displaySetupMenuCreated);
}
void GUISystem::setDisplaySetupMenuCreated(bool created)  // sets the value of displaySettingsMenuCreated
{
	displaySetupMenuCreated = created;
}

bool GUISystem::getInputSetupMenuCreated()  // retrieves the value of inputSettingsMenuCreated
{
	return (inputSetupMenuCreated);
}
void GUISystem::setInputSetupMenuCreated(bool created)  // sets the value of inputSettingsMenuCreated
{
	inputSetupMenuCreated = created;
}

bool GUISystem::getAuduoSetupMenuCreated()  // retrieves the value of audioSettingsMenuCreated
{
	return (audioSetupMenuCreated);
}

void GUISystem::setAudioSetupMenuCreated(bool created)  // sets the value of audioSettingsMenuCreated
{
	audioSetupMenuCreated = created;
}

bool GUISystem::getGameSetupMenuCreated()  // retrieves the value of gameSetupMenuCreated
{
	return (gameSetupMenuCreated);
}
void GUISystem::setGameSetupMenuCreated(bool created)  // sets the value of gameSetupMenuCreated
{
	gameSetupMenuCreated = created;
}

bool GUISystem::getPlayerStartSelectionMenuCreated()  // retrieves the value of playerStartSelectionMenuCreated
{
    return (playerStartSelectionMenuCreated);
}
void GUISystem::setPlayerStartSelectionMenuCreated(bool created)  // sets the value of playerStartSelectionMenuCreated
{
    playerStartSelectionMenuCreated = created;
}

bool GUISystem::getTeamSelectionMenuCreated()  // retrieves the value of teamSelectionMenuCreated
{
    return (teamSelectionMenuCreated);
}
void GUISystem::setTeamSelectionMenuCreated(bool created)  // sets the value of teamSelectionMenuCreated
{
    teamSelectionMenuCreated = created;
}

bool GUISystem::getCourtSelectionMenuCreated()  // retrieves the value of courtSelectionMenuCreated
{
	return (courtSelectionMenuCreated);
}
void GUISystem::setCourtSelectionMenuCreated(bool created)  // sets the value of courtSelectionMenuCreated
{
	courtSelectionMenuCreated = created;
}

bool GUISystem::getCourtSelectionDataLoaded()  // retrieves the value of courtSelectionEntriesLoaded
{
    return (courtSelectionDataLoaded);
}
void GUISystem::setCourtSelectionDataLoaded(bool loaded)  // sets the value of courtSelectionEntriesLoaded
{
    courtSelectionDataLoaded = loaded;
}

bool GUISystem::getMenuActive() // retrieves the value of menuActive
{
	return (menuActive);
}
void GUISystem::setMenuActive(bool active) // sets the value of menuActive
{
	menuActive = active;
}
activeMenus GUISystem::getActiveMenu() // retrieves the value of activeMenu
{
	return (activeMenu);
}
void GUISystem::setActiveMenu(activeMenus menu) // sets the value of activeMenu
{
	activeMenu = menu;
}

activeMenus GUISystem::getPreviousActiveMenu() // retrieves the value of previousActiveMenu
{
	return (previousActiveMenu);
}
void GUISystem::setPreviousActiveMenu(activeMenus menu) // sets the value of previousActiveMenu
{
	previousActiveMenu = menu;
}

// Initializes MyGUI
bool GUISystem::initMyGUI()
{
    renderEngine *render = renderEngine::Instance();
    Ogre::RenderWindow *mWindow = render->getMWindow();
    Ogre::SceneManager *mSceneMgr = render->getMSceneMgr();

	logMsg("*** Initializing MyGUI ***");
	mPlatform = new MyGUI::OgrePlatform();
    logMsg("Crash?");

/*#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    mPlatform->initialise(mWindow, mSceneMgr, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
#else
*/
    mPlatform->initialise(mWindow, mSceneMgr, "UBCData"); // mWindow is Ogre::RenderWindow*, mSceneManager is Ogre::SceneManager*
//#endif

    logMsg("Crash??");
	mGUI = new MyGUI::Gui();
	logMsg("Crash???");
	mGUI->initialise();
    logMsg("*** MyGUI Initialized ***");
	return true;
}



void GUISystem::startSinglePlayerGame() // starts single player game
{
	gameState *gameS = gameState::Instance();

    gameS->setGameType(SINGLE);
//	hideMainMenuWidgets();	// Hides the widgets from the main menu
    courtSelectionMenu();   // displays the menu for selecting which court to use
    //   gameSetupMenu();
//	menuActive = false;
}

void GUISystem::startMultiPlayerGame() // starts multiplayer game
{
	if (!networkSetupMenuCreated)
	{
	    createNetworkSetupGUI();    // creates the GUI for the Network Setup Screen
	}

    hideActiveMenuWidgets();
    menuActive = true;
    previousActiveMenu = activeMenu;
    activeMenu = NETWORK;
    showActiveMenuWidgets();

}

void GUISystem::optionsMenu() // displays options menu
{
	if (!optionsMenuCreated)
	{
		createOptionsMenuGUI();
	}

	hideActiveMenuWidgets();
    menuActive = true;
	previousActiveMenu = activeMenu;
	activeMenu = OPTIONS;
    showActiveMenuWidgets();

}

void GUISystem::displayMenu()  // displays display menu
{
    if (!displaySetupMenuCreated)
    {
        createDisplaySetupGUI();
    }

    hideActiveMenuWidgets();
    menuActive = true;
    previousActiveMenu = activeMenu;
    activeMenu = DISPLAY;
    showActiveMenuWidgets();
}

void GUISystem::inputMenu()  // displays the input menu
{
    if (!inputSetupMenuCreated)
    {
        createInputSetupGUI();
    }

    hideActiveMenuWidgets();
    menuActive = true;
    previousActiveMenu = activeMenu;
    activeMenu = INPUTMENU;
    showActiveMenuWidgets();
}
void GUISystem::audioMenu()  // displays the audio menu
{
    if (!audioSetupMenuCreated)
    {
        createAudioSetupGUI();
    }

    hideActiveMenuWidgets();
    menuActive = true;
    previousActiveMenu = activeMenu;
    activeMenu = AUDIO;
    showActiveMenuWidgets();
}

void GUISystem::gameSetupMenu() // displays game setup menu
{
	if (!gameSetupMenuCreated)
	{
		createGameSetupMenuGUI();
		gameSetupMenuCreated = true;
	}

	hideActiveMenuWidgets();
	menuActive = true;
	previousActiveMenu = activeMenu;
	activeMenu = GAMESETUP;
    showActiveMenuWidgets();
}

void GUISystem::playerStartSelectionMenu() // displays player start selection menu
{
    if (!playerStartSelectionMenuCreated)
    {
        createPlayerStartSelectionMenuGUI();
        addPlayerStartSelectionMenuData();
        playerStartSelectionMenuCreated = true;
    }
    setSelectedIndexes();
    hideActiveMenuWidgets();
    menuActive = true;
    previousActiveMenu = activeMenu;
    activeMenu = PLAYERSTART;
    showActiveMenuWidgets();
}

void GUISystem::teamSelectionMenu() // displays team selection menu
{
    if (!teamSelectionMenuCreated)
    {
        createTeamSelectionMenuGUI();
        teamSelectionMenuCreated = true;
    }

    hideActiveMenuWidgets();
    menuActive = true;
    previousActiveMenu = activeMenu;
    activeMenu = TEAMSELECT;
    showActiveMenuWidgets();
}

void GUISystem::courtSelectionMenu() // displays court selection menu
{
    gameState *gameS = gameState::Instance();
    loader *load = loader::Instance();

    if (!courtSelectionMenuCreated)
    {
        createCourtSelectionMenuGUI();
    }
    
    if (!courtSelectionDataLoaded)
    {
        if (addCourtSelectionMenuData())
        {
            courtSelectBox->setIndexSelected(0);
            courtSelectionDataLoaded = true;
        }
    }
    
    hideActiveMenuWidgets();
    previousActiveMenu = activeMenu;
    activeMenu = COURTSELECT;
    showActiveMenuWidgets();
    
    menuActive = true;
}

bool GUISystem::addCourtSelectionMenuData() // adds data to Player Start Selection Menu widgets
{
    gameState *gameS = gameState::Instance();
    
    std::vector<courtData> courtDataInstance;
    std::vector<std::string> courtName;
    if (!gameS->getCourtDataLoaded())
    {
        if (gameS->createCourtDataInstances())
        {
            gameS->setCourtDataLoaded(true);
        }
        else
        {
        }
    }
    courtDataInstance = gameS->getCourtDataInstance();
    
    for (int x=0;x<courtDataInstance.size();++x)
    {
        courtName.push_back(courtDataInstance[x].getName());
    }
    
    logMsg("courtName = " +courtName[0]);
    int i = 0;
    while (i<courtName.size())
    {
        courtSelectBox->addItem(courtName[i]);
        ++i;
    }
    
    return (true);
}

void GUISystem::addPlayerStartSelectionMenuData() // adds data to Player Start Selection Menu widgets
{
    gameState *gameS = gameState::Instance();
    loader *load = loader::Instance();

    load->loadPlayers();

    std::vector<playerData> playerDataInstance = gameS->getPlayerDataInstance();
    std::vector<int> overAllRatings;
    std::vector<std::string> pNames;
    std::vector<std::string> pPositions;
    std::vector<int> pIDs;
    std::vector< std::vector<int> > overallRatings;
    std::vector<int> overall;

    int overallRatingsSize = 0;
    int flag = 1;
    int temp = 0;
    int tempID = 0;
    string tempName;
    string tempPosition;

    playerNames.push_back(pNames);
    playerNames.push_back(pNames);

    playerPositions.push_back(pPositions);
    playerPositions.push_back(pPositions);

    playerIDs.push_back(pIDs);
    playerIDs.push_back(pIDs);

    overallRatings.push_back(overall);
    overallRatings.push_back(overall);

    for (size_t i = 0;i < playerDataInstance.size(); ++i)
    {
        logMsg("pDTeam = " +Ogre::StringConverter::toString(playerDataInstance[i].getTeamID()));
        logMsg("teamID == " +Ogre::StringConverter::toString(gameS->getTeamID()[1]));
        if (playerDataInstance[i].getTeamID() == gameS->getTeamID()[0])
        {
            int overallRating = playerDataInstance[i].getOverallRating();
            std::string playerOverallRating = Ogre::StringConverter::toString(overallRating);
            std::string playerName = playerDataInstance[i].getFirstName() +" " +playerDataInstance[i].getLastName() +" " +playerDataInstance[i].getPosition(); // +"            "; // +playerOverallRating;
            std::string playerPosition = playerDataInstance[i].getPosition();
            int playerID = playerDataInstance[i].getID();

            playerNames[0].push_back(playerName);
            playerPositions[0].push_back(playerPosition);
            playerIDs[0].push_back(playerID);
            overallRatings[0].push_back(overallRating);
        }

        if (playerDataInstance[i].getTeamID() == gameS->getTeamID()[1])
        {
            int overallRating = playerDataInstance[i].getOverallRating();
            std::string playerOverallRating = Ogre::StringConverter::toString(overallRating);
            std::string playerName = playerDataInstance[i].getFirstName() +" " +playerDataInstance[i].getLastName( ) +" " +playerDataInstance[i].getPosition(); // +"            "; // +playerOverallRating;
            bool playerNameLengthReached = false;
            std::string playerPosition = playerDataInstance[i].getPosition();
            int playerID = playerDataInstance[i].getID();

            playerNames[1].push_back(playerName);
            playerPositions[1].push_back(playerPosition);
            playerIDs[1].push_back(playerID);
            overallRatings[1].push_back(overallRating);
        }
    }



    overallRatingsSize = overallRatings[0].size();
    flag = 1;
    temp = 0;
    tempID = 0;
    tempName.clear();
    tempPosition.clear();
    logMsg("overallRating before = " +Ogre::StringConverter::toString(overallRatings[0][0]));
    for (size_t l=0; l<overallRatingsSize && flag; ++l)
    {
        flag = 0;
        for (size_t j=0; j < (overallRatingsSize -1); ++j)
        {
            if (overallRatings[0][j+1] > overallRatings[0][j])      // ascending order simply changes to <
            {
                temp = overallRatings[0][j];             // swap elements
                tempName = playerNames[0][j];
                tempPosition = playerPositions[0][j];
                tempID = playerIDs[0][j];

                overallRatings[0][j] = overallRatings[0][j+1];
                playerNames[0][j] = playerNames[0][j+1];
                playerPositions[0][j] = playerPositions[0][j+1];
                playerIDs[0][j] = playerIDs[0][j+1];

                overallRatings[0][j+1] = temp;
                playerNames[0][j+1] = tempName;
                playerPositions[0][j+1] = tempPosition;
                playerIDs[0][j+1] = tempID;

                flag = 1;               // indicates that a swap occurred.
            }
        }

    }

    logMsg("overallRating after = " +Ogre::StringConverter::toString(overallRatings[0][0]));

    overallRatingsSize = overallRatings[1].size();
    flag = 1;
    temp = 0;
    tempID = 0;
    tempName.clear();
    tempPosition.clear();
    logMsg("overallRating before = " +Ogre::StringConverter::toString(overallRatings[1][0]));
    for (size_t l=0; l<overallRatingsSize && flag; ++l)
    {
        flag = 0;
        for (size_t j=0; j < (overallRatingsSize -1); ++j)
        {
            if (overallRatings[1][j+1] > overallRatings[1][j])      // ascending order simply changes to <
            {
                temp = overallRatings[1][j];             // swap elements
                tempName = playerNames[1][j];
                tempPosition = playerPositions[1][j];
                tempID = playerIDs[1][j];

                overallRatings[1][j] = overallRatings[1][j+1];
                playerNames[1][j] = playerNames[1][j+1];
                playerPositions[1][j] = playerPositions[1][j+1];
                playerIDs[1][j] = playerIDs[1][j+1];

                overallRatings[1][j+1] = temp;
                playerNames[1][j+1] = tempName;
                playerPositions[1][j+1] = tempPosition;
                playerIDs[1][j+1] = tempID;

                flag = 1;               // indicates that a swap occurred.
            }
        }

    }
    logMsg("overallRating after = " +Ogre::StringConverter::toString(overallRatings[1][0]));

    std::vector<int> starters; // used for initial creatio  of teamStarterID vector
//    starters.push_back(1);
    for (size_t i=0;i<5;++i)
    {
        team0IDs.push_back(starters);
        team1IDs.push_back(starters);
    }

    int startID = 0;
/*    for (size_t i=0;i<5;++i)
    {

        teamStarterID[0].push_back(startID);
//        exit(0);
        teamStarterID[1].push_back(startID);
//        exit(0);
    }
*/
    for (size_t i = 0;i < playerNames[0].size(); ++i)
    {
       bool playerNameLengthReached = false;
        while (!playerNameLengthReached)
        {
            if (playerNames[0][i].length() >= 18)
            {
                playerNameLengthReached = true;
            }
            else
            {
                playerNames[0][i] += " ";
            }
        }
        playerNames[0][i] += " " +Ogre::StringConverter::toString(overallRatings[0][i]);
        logMsg("playerNames[0][i] == " +playerNames[0][i]);

        std::string PName;
        if (playerPositions[0][i] == "PG")
        {
            team0PGSelectBox->addItem(playerNames[0][i]);
            team0IDs[0].push_back(playerIDs[0][i]);
//            exit(0);
        }
        else if (playerPositions[0][i] == "SG")
        {
            team0SGSelectBox->addItem(playerNames[0][i]);
            team0IDs[1].push_back(playerIDs[0][i]);
       }
        else if (playerPositions[0][i] == "SF")
        {
            team0SFSelectBox->addItem(playerNames[0][i]);
            team0IDs[2].push_back(playerIDs[0][i]);
        }
        else if (playerPositions[0][i] == "PF")
        {
            team0PFSelectBox->addItem(playerNames[0][i]);
            team0IDs[3].push_back(playerIDs[0][i]);
       }
        else if (playerPositions[0][i] == "C")
        {
            team0CSelectBox->addItem(playerNames[0][i]);
            team0IDs[4].push_back(playerIDs[0][i]);
       }
        else
        {

        }
    }

    for (size_t i=0;i<playerIDs[0].size();++i)
    {
        logMsg("PlayerIDs == " +Ogre::StringConverter::toString(playerIDs[0][i]));
    }

//    exit(0);

    logMsg("PG == " +team0PGSelectBox->getItemNameAt(0));
    logMsg("PG ID == " +Ogre::StringConverter::toString(team0IDs[0][0]));
//    exit(0);
    logMsg("SG == " +team0SGSelectBox->getItemNameAt(0));
    logMsg("SG ID == " +Ogre::StringConverter::toString(team0IDs[1][0]));
    logMsg("SF == " +team0SFSelectBox->getItemNameAt(0));
    logMsg("SF ID == " +Ogre::StringConverter::toString(team0IDs[2][0]));
    logMsg("PF == " +team0PFSelectBox->getItemNameAt(0));
    logMsg("PF ID == " +Ogre::StringConverter::toString(team0IDs[3][0]));
    logMsg("C == " +team0CSelectBox->getItemNameAt(0));
    logMsg("C ID == " +Ogre::StringConverter::toString(team0IDs[4][0]));
//    exit(0);

    for (size_t i = 0;i < playerNames[1].size(); ++i)
    {
       bool playerNameLengthReached = false;
        while (!playerNameLengthReached)
        {
            if (playerNames[1][i].length() >= 18)
            {
                playerNameLengthReached = true;
            }
            else
            {
                playerNames[1][i] += " ";
            }
        }
        playerNames[1][i] += " " +Ogre::StringConverter::toString(overallRatings[1][i]);
        logMsg("playerNames[1][i] == " +playerNames[1][i]);

        std::string PName;

        if (playerPositions[1][i] == "PG")
        {
            team1PGSelectBox->addItem(playerNames[1][i]);
            team1IDs[0].push_back(playerIDs[1][i]);
            logMsg("Adding PG1");
        }
        else if (playerPositions[1][i] == "SG")
        {
            team1SGSelectBox->addItem(playerNames[1][i]);
            team1IDs[1].push_back(playerIDs[1][i]);
            logMsg("Adding SG1");
        }
        else if (playerPositions[1][i] == "SF")
        {
            team1SFSelectBox->addItem(playerNames[1][i]);
            team1IDs[2].push_back(playerIDs[1][i]);
            logMsg("Adding SF1");
        }
        else if (playerPositions[1][i] == "PF")
        {
            team1PFSelectBox->addItem(playerNames[1][i]);
            team1IDs[3].push_back(playerIDs[1][i]);
            logMsg("Adding PF1");
        }
        else if (playerPositions[1][i] == "C")
        {
            team1CSelectBox->addItem(playerNames[1][i]);
            team1IDs[4].push_back(playerIDs[1][i]);
            logMsg("Adding C1");
        }
        else
        {

        }

    }

    logMsg("PG1 == " +team1PGSelectBox->getItemNameAt(0));
    logMsg("PG1 ID == " +Ogre::StringConverter::toString(team1IDs[0][0]));

    logMsg("SG1 == " +team1SGSelectBox->getItemNameAt(0));
    logMsg("SG1 ID == " +Ogre::StringConverter::toString(team1IDs[1][0]));

    logMsg("SF1 == " +team1SFSelectBox->getItemNameAt(0));
    logMsg("SF1 ID == " +Ogre::StringConverter::toString(team1IDs[2][0]));

    logMsg("PF1 == " +team1PFSelectBox->getItemNameAt(0));
    logMsg("PF1 ID == " +Ogre::StringConverter::toString(team1IDs[3][0]));

    logMsg("C1 == " +team1CSelectBox->getItemNameAt(0));
    logMsg("C1 ID == " +Ogre::StringConverter::toString(team1IDs[4][0]));

//    exit(0);

    
}

void GUISystem::setSelectedIndexes()  // sets all player listbox indexes to zero
{
    team0PGSelectBox->setIndexSelected(0);
    team0SGSelectBox->setIndexSelected(0);
    team0SFSelectBox->setIndexSelected(0);
    team0PFSelectBox->setIndexSelected(0);
    team0CSelectBox->setIndexSelected(0);
    team1PGSelectBox->setIndexSelected(0);
    team1SGSelectBox->setIndexSelected(0);
    team1SFSelectBox->setIndexSelected(0);
    team1PFSelectBox->setIndexSelected(0);
    team1CSelectBox->setIndexSelected(0);
}

void GUISystem::networkClientSetupMenu() // sets up the client connection
{
    if (!networkClientSetupMenuCreated)
    {
        createNetworkClientSetupGUI();
    }
    hideActiveMenuWidgets();
    previousActiveMenu = activeMenu;
    activeMenu = NETWORKCLIENT;
    showActiveMenuWidgets();
    MyGUI::InputManager::getInstance().setKeyFocusWidget(clientIPAddressBox);

}

void GUISystem::networkServerSetupMenu()  // sets up the networkServer instance
{
    if (!networkServerSetupMenuCreated)
    {
        createNetworkServerSetupGUI();
    }
    hideActiveMenuWidgets();
    previousActiveMenu = activeMenu;
    activeMenu = NETWORKSERVER;
    showActiveMenuWidgets();
    MyGUI::InputManager::getInstance().setKeyFocusWidget(serverIPAddressBox);

}

void GUISystem::networkServer()  // sets up  game as a network server
{
    networkEngine * network = networkEngine::Instance();
    gameEngine * gameE = gameEngine::Instance();
    gameState *gameS = gameState::Instance();

    gameS->setGameType(MULTI);
 //   hideNetworkSetupWidgets();  // Hides Network Setup Menu widgets
    menuActive = false;
    network->setIPAddress(serverIPAddressBox->getCaption());  // sets the neworkEngine's ipAddress string to that of the caption
   logMsg("server ip = " +network->getIPAddress());
    network->serverSetup();

//    gameE->setCreateScene(true); // sets variable true that tells gameEngine to start rendering the scene

}
void GUISystem::networkClient()  // sets up game as a network client
{
    networkEngine * network = networkEngine::Instance();
    gameEngine * gameE = gameEngine::Instance();
    gameState *gameS = gameState::Instance();

    gameS->setGameType(MULTI);

//    hideNetworkSetupWidgets();  // Hides Network Setup Menu widgets
    menuActive = false;
    network->setIPAddress(clientIPAddressBox->getCaption());  // sets the neworkEngine's ipAddress string to that of the caption
//    network->networkClient();
    network->clientConnect();
//    gameE->setCreateScene(true); // sets variable true that tells gameEngine to start rendering the scenetop

}

void GUISystem::courtSelected()  // processes court selection
{
    gameState *gameS = gameState::Instance();
    
    logMsg("Selected Court #" +Ogre::StringConverter::toString(courtSelectBox->getIndexSelected()));
    gameS->setSelectedCourtDataInstance(courtSelectBox->getIndexSelected());
    teamSelectionMenu();
}

void GUISystem::teamsSelected()  // processes team selection
{
    gameState *gameS = gameState::Instance();
    std::vector<int> teamID;
    teamID.push_back(team0SelectBox->getIndexSelected());
    teamID.push_back(team1SelectBox->getIndexSelected());
    gameS->setTeamID(teamID);
    logMsg("Teams selected");
}

void GUISystem::playerStartSelected()  // process player start selection
{
    gameState *gameS = gameState::Instance();
    std::vector <teamState>  teamInstance = gameS->getTeamInstance();

    logMsg("S");
//        exit(0);
    std::vector<std::string> team0Starters;
    std::vector<std::string> team1Starters;
    std::vector<int> starters; // used for initial creatio  of teamStarterID vector

    int IDs = 0;
    while (teamStarterID.size() < 2)
    {
        teamStarterID.push_back(starters);
    }
    while (teamStarterID[0].size() <5)
    {
        teamStarterID[0].push_back(IDs);
    }
    while (teamStarterID[1].size() <5)
    {
        teamStarterID[1].push_back(IDs);
    }
    
    // checks to make sure that all player selectBoxes have a valid index value
    if (team0PGSelectBox->getIndexSelected() < 0 || team0PGSelectBox->getIndexSelected() > team0PGSelectBox->getItemCount())
    {
        team0PGSelectBox->setIndexSelected(0);
    }
    if (team0SGSelectBox->getIndexSelected() < 0 || team0SGSelectBox->getIndexSelected() > team0SGSelectBox->getItemCount())
    {
        team0SGSelectBox->setIndexSelected(0);
    }
    if (team0SFSelectBox->getIndexSelected() < 0 || team0SFSelectBox->getIndexSelected() > team0SFSelectBox->getItemCount())
    {
        team0SFSelectBox->setIndexSelected(0);
    }
    if (team0PFSelectBox->getIndexSelected() < 0 || team0PFSelectBox->getIndexSelected() > team0PFSelectBox->getItemCount())
    {
        team0PFSelectBox->setIndexSelected(0);
    }
    if (team0CSelectBox->getIndexSelected() < 0 || team0CSelectBox->getIndexSelected() > team0CSelectBox->getItemCount())
    {
        team0CSelectBox->setIndexSelected(0);
    }
    if (team1PGSelectBox->getIndexSelected() < 0 || team1PGSelectBox->getIndexSelected() > team1PGSelectBox->getItemCount())
    {
        team1PGSelectBox->setIndexSelected(0);
    }
    if (team1SGSelectBox->getIndexSelected() < 0 || team1SGSelectBox->getIndexSelected() > team1SGSelectBox->getItemCount())
    {
        team1SGSelectBox->setIndexSelected(0);
    }
    if (team1SFSelectBox->getIndexSelected() < 0 || team1SFSelectBox->getIndexSelected() > team1SFSelectBox->getItemCount())
    {
        team1SFSelectBox->setIndexSelected(0);
    }
    if (team1PFSelectBox->getIndexSelected() < 0 || team1PFSelectBox->getIndexSelected() > team1PFSelectBox->getItemCount())
    {
        team1PFSelectBox->setIndexSelected(0);
    }
    if (team1CSelectBox->getIndexSelected() < 0 || team1CSelectBox->getIndexSelected() > team1CSelectBox->getItemCount())
    {
        team1CSelectBox->setIndexSelected(0);
    }
    
//    teamStarterID[0][0] = team0IDs[0][team0PGSelectBox->getIndexSelected()];
    team0Starters.push_back(team0PGSelectBox->getItemNameAt(team0PGSelectBox->getIndexSelected()));
    teamStarterID[0][0] = team0IDs[0][team0PGSelectBox->getIndexSelected()];
    logMsg("teamStarterID[0][0] = " +Ogre::StringConverter::toString(teamStarterID[0][0]));
    team0Starters.push_back(team0SGSelectBox->getItemNameAt(team0SGSelectBox->getIndexSelected()));
    teamStarterID[0][1] = team0IDs[1][team0SGSelectBox->getIndexSelected()];
    logMsg("teamStarterID[0][1] = " +Ogre::StringConverter::toString(teamStarterID[0][1]));
    team0Starters.push_back(team0SFSelectBox->getItemNameAt(team0SFSelectBox->getIndexSelected()));
    teamStarterID[0][2] = team0IDs[2][team0SFSelectBox->getIndexSelected()];
    logMsg("teamStarterID[0][2] = " +Ogre::StringConverter::toString(teamStarterID[0][2]));
    team0Starters.push_back(team0PFSelectBox->getItemNameAt(team0PFSelectBox->getIndexSelected()));
    teamStarterID[0][3] = team0IDs[3][team0PFSelectBox->getIndexSelected()];
    logMsg("teamStarterID[0][3] = " +Ogre::StringConverter::toString(teamStarterID[0][3]));
    team0Starters.push_back(team0CSelectBox->getItemNameAt(team0CSelectBox->getIndexSelected()));
    teamStarterID[0][4] = team0IDs[4][team0CSelectBox->getIndexSelected()];
    logMsg("teamStarterID[0][4] = " +Ogre::StringConverter::toString(teamStarterID[0][4]));
    team1Starters.push_back(team1PGSelectBox->getItemNameAt(team1PGSelectBox->getIndexSelected()));
    teamStarterID[1][0] = team1IDs[0][team1PGSelectBox->getIndexSelected()];
    logMsg("teamStarterID[1][0] = " +Ogre::StringConverter::toString(teamStarterID[1][0]));
    team1Starters.push_back(team1SGSelectBox->getItemNameAt(team1SGSelectBox->getIndexSelected()));
    teamStarterID[1][1] = team1IDs[1][team1SGSelectBox->getIndexSelected()];
    logMsg("teamStarterID[1][1] = " +Ogre::StringConverter::toString(teamStarterID[1][1]));
    team1Starters.push_back(team1SFSelectBox->getItemNameAt(team0SFSelectBox->getIndexSelected()));
    teamStarterID[1][2] = team1IDs[2][team1SFSelectBox->getIndexSelected()];
    logMsg("teamStarterID[1][2] = " +Ogre::StringConverter::toString(teamStarterID[1][2]));
    team1Starters.push_back(team1PFSelectBox->getItemNameAt(team1PFSelectBox->getIndexSelected()));
    teamStarterID[1][3] = team1IDs[3][team1PFSelectBox->getIndexSelected()];
    
    logMsg("teamStarterID[1][3] = " +Ogre::StringConverter::toString(teamStarterID[1][3]));
    team1Starters.push_back(team1CSelectBox->getItemNameAt(team1CSelectBox->getIndexSelected()));
    teamStarterID[1][4] = team1IDs[4][team1CSelectBox->getIndexSelected()];
    logMsg("teamStarterID[1][4] = " +Ogre::StringConverter::toString(teamStarterID[1][4]));

    gameS->setTeamStarterID(teamStarterID); // sets the selected starters for both teams in gameState class

    std::vector<int> activeID;

    for (size_t x=0;x<5;++x)
    {
        activeID.push_back(teamStarterID[0][x]);
    }
    teamInstance[0].setActivePlayerID(activeID);
    if (!teamInstance[0].getPlayerInstancesCreated())    // checks if playerInstances have been created
    {
        if (teamInstance[0].createPlayerInstances()) // creates the player instances based on playerIDS
        {
            logMsg("Team 0 Player instances created!");
            teamInstance[0].setPlayerInstancesCreated(true);
//          exit(0);
        }
    }
    teamInstance[0].setPlayerStartPositions();
    logMsg("Team 0 player start positions set");
    size_t i = 0;
    std::vector<playerState> playerInstance;
    playerInstance = teamInstance[0].getPlayerInstance();
    while (i<playerInstance.size())
    {
        if (activeID[4] == playerInstance[i].getPlayerID())
        {
            teamInstance[0].setHumanPlayer(i);
            logMsg("human player set!");
        }
        i++;
    }
    activeID.clear();
    for (size_t x=0;x<5;++x)
    {
        activeID.push_back(teamStarterID[1][x]);
    }
    teamInstance[1].setActivePlayerID(activeID);
    if (!teamInstance[1].getPlayerInstancesCreated())    // checks if playerInstances have been created
    {
        logMsg("Creating team 1 player instances");
//            exit(0);
        if (teamInstance[1].createPlayerInstances()) // creates the player instances based on playerIDS
        {
            logMsg("Player instances created!");
            teamInstance[1].setPlayerInstancesCreated(true);
//          exit(0);
        }
    }
    playerInstance = teamInstance[1].getPlayerInstance();
    while (i<playerInstance.size())
    {
        if (activeID[4] == playerInstance[i].getPlayerID())
        {
            teamInstance[1].setHumanPlayer(i);
            logMsg("human player set!");
        }
        i++;
    }
    teamInstance[1].setPlayerStartPositions();
    logMsg("Team 1 player start positions set");

//        exit(0);
/*
//        teamInstance[0].setupState();
//        exit(0);
    std::vector<int> test;
    test.push_back(3);
    test.push_back(4);
    logMsg("bleep");
//        teamInstance[0].setStarterID(test);
    testState.setStarterID(test);
    logMsg("bloop");
*/
    gameS->setTeamInstance(teamInstance); // sets the teamInstance vector


    logMsg("team 0 C selectbox id = " +Ogre::StringConverter::toString(teamStarterID[0][1]));
    logMsg("team 0 starter 0 = " +Ogre::StringConverter::toString(teamStarterID[0][0]));
    logMsg("team  0 starter 0 = " +team0Starters[0]);
//        exit(0);
    hideActiveMenuWidgets();
    menuActive = false;
    gameS->setGameSetupComplete(true);

}

void GUISystem::gameSetupAwaySelected()  // processes away team selectdion on game setup menu
{
    MyGUI::InputManager::getInstance().setKeyFocusWidget(team1SelectBox);
    gameSetupMenuAwaySelected = true;
    gameSetupMenuHomeSelected = false;
}

void GUISystem::gameSetupHomeSelected()  // process home team selection on game setup menu
{
    MyGUI::InputManager::getInstance().setKeyFocusWidget(team0SelectBox);
    gameSetupMenuHomeSelected = true;
    gameSetupMenuAwaySelected = false;
}

void GUISystem::backNetworkSetupMenuSelected()  // returns back to network setup screen
{
    hideActiveMenuWidgets();
    menuActive = true;
    previousActiveMenu = activeMenu;
    activeMenu = NETWORK;
    showActiveMenuWidgets();
}

void GUISystem::backMainMenuSelected()  // processes back to main menu selection
{
    hideActiveMenuWidgets();  
    previousActiveMenu = activeMenu;
    activeMenu = MAIN;
    showMainMenuWidgets();
}

void GUISystem::backNetworkClientMenuSelected()  // returns back to the network client menu
{
    hideActiveMenuWidgets();
    menuActive = true;
    previousActiveMenu = activeMenu;
    activeMenu = NETWORKCLIENT;
    showActiveMenuWidgets();
}

void GUISystem::hideActiveMenuWidgets()  // hides active menus widgets
{
    switch (activeMenu)
    {
        case MAIN: 
            hideMainMenuWidgets();
            break;
        case NETWORK:
            hideNetworkSetupWidgets();
            break;
        case NETWORKCLIENT:
            hideNetworkClientSetupWidgets();
            break;
            case NETWORKSERVER:
            hideNetworkServerSetupWidgets();
            break;
        case OPTIONS:
            hideOptionsMenuWidgets();
            break;
        case DISPLAY:
            hideDisplayMenuWidgets();
            break;
        case INPUTMENU:
            hideInputMenuWidgets();
            break;
        case AUDIO:
            hideAudioMenuWidgets();
            break;
        case GAMESETUP:
            hideGameSetupMenuWidgets();
            break;
        case PLAYERSTART:
            hidePlayerStartSelectionMenuWidgets();
            break;
        case TEAMSELECT:
            hideTeamSelectionMenuWidgets();
            break;
        case COURTSELECT:
            hideCourtSelectionMenuWidgets();
            break;
        default:
            break;
	}
}

void GUISystem::showActiveMenuWidgets()  // shows active menus widgets
{
    switch (activeMenu)
    {
        case MAIN: 
            showMainMenuWidgets();
            break;
        case NETWORK:
            showNetworkSetupWidgets();
            break;
        case NETWORKCLIENT:
            showNetworkClientSetupWidgets();
            break;
        case NETWORKSERVER:
            showNetworkServerSetupWidgets();
            break;
        case OPTIONS:
            showOptionsMenuWidgets();
            break;
        case DISPLAY:
            showDisplayMenuWidgets();
            break;
        case INPUTMENU:
            showInputMenuWidgets();
            break;
        case AUDIO:
            showAudioMenuWidgets();
            break;
        case GAMESETUP:
            showGameSetupMenuWidgets();
            break;
        case PLAYERSTART:
            showPlayerStartSelectionMenuWidgets();
            break;
        case TEAMSELECT:
            showTeamSelectionMenuWidgets();
            break;
        case COURTSELECT:
            showCourtSelectionMenuWidgets();
            break;
        default:
            break;
	}
}


void GUISystem::checkTeamInstancesCreated()  // Checks if team instances have been created and if not creates them.
{
    gameState *gameS = gameState::Instance();

    if (!gameS->getTeamInstancesCreated())
    {
        logMsg("Creating team instances!");
        gameS->createTeamInstances();
        gameS->setTeamInstancesCreated(true);
        gameS->assignHoopToTeams();
        logMsg("Team instances created!");
    }
}
