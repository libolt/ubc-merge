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


#include "gui.h"
#include "gameengine.h"
#include "gamestate.h"
#include "load.h"
#include "logging.h"
#include "network.h"
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
	optionsMenuCreated = false;
	displaySetupMenuCreated = false;
	inputSetupMenuCreated = false;
	audioSetupMenuCreated = false;
	gameSetupMenuCreated = false;
    gameSetupMenuAwaySelected = false;
	gameSetupMenuHomeSelected = false;
    playerStartSelectionMenuCreated = false;
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

bool GUISystem::createMainMenuGUI()
{
    renderEngine *renderE = renderEngine::Instance();
	Ogre::Viewport *viewPort = renderE->getViewPort();

    if (viewPort->getActualHeight() >= 1000)
    {
        MyGUI::FontManager::getInstance().setDefaultFont("LuxiBoldFont_18");
    }
    else
    {
        MyGUI::FontManager::getInstance().setDefaultFont("LuxiBoldFont_16");

    }
	logMsg("Loading MainMenu layout");
	MyGUI::LayoutManager::getInstance().loadLayout("MainMenu.layout");

	logMsg("MainMenu layout loaded");
//	startGameButton = mGUI->createWidget<MyGUI::Button>("Button", 362, 100, 300, 26, MyGUI::Align::Default, "Main");
//	startGameButton->setCaption("Start Game");
	startSingleGameButton = mGUI->findWidget<MyGUI::Button>("startSingleGameButton");
	startSingleGameButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::startSingleGameButtonClicked);
    startSingleGameButton->setStateSelected(true);
	MyGUI::InputManager::getInstance().setKeyFocusWidget(startSingleGameButton);
    startSingleGameButton->setPosition((0.3 *viewPort->getActualWidth() ), (0.1 *viewPort->getActualHeight()) );
	startSingleGameButton->setSize((0.4 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

	startMultiGameButton = mGUI->findWidget<MyGUI::Button>("startMultiGameButton");
	startMultiGameButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::startMultiGameButtonClicked);
    startMultiGameButton->setPosition((0.3 *viewPort->getActualWidth() ), (0.14 *viewPort->getActualHeight()) );
	startMultiGameButton->setSize((0.4 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

//	optionsButton = mGUI->createWidget<MyGUI::Button>("Button", 362, 125, 300, 26, MyGUI::Align::Default, "Main");
//	optionsButton->setCaption("Options");
	optionsButton = mGUI->findWidget<MyGUI::Button>("optionsButton");
	optionsButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::optionsButtonClicked);
    optionsButton->setPosition((0.3 *viewPort->getActualWidth() ), (0.18 *viewPort->getActualHeight()) );
	optionsButton->setSize((0.4 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

//	exitButton = mGUI->createWidget<MyGUI::Button>("Button", 362, 150, 300, 26, MyGUI::Align::Default, "Main");
//	exitButton->setCaption("Exit");
	exitButton = mGUI->findWidget<MyGUI::Button>("exitButton");
	exitButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::exitButtonClicked);
    exitButton->setPosition((0.3 *viewPort->getActualWidth() ), (0.22 *viewPort->getActualHeight()) );
	exitButton->setSize((0.4 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

	mainMenuCreated = true;
	menuActive = true;
	activeMenu = MAIN;
	// set callback
	//button->eventMouseButtonClick += MyGUI::newDelegate(CLASS_POINTER, &CLASS_NAME::METHOD_NAME); // CLASS_POINTER is pointer to instance of a CLASS_NAME (usually '''this''')
	// or
	//button->eventMouseButtonClick += MyGUI::newDelegate(STATIC_METHOD_NAME);
	//button->eventMouseButtonClick += MyGUI::newDelegate(GLOBAL_FUNC_NAME);

	return true;
}

bool GUISystem::createNetworkSetupGUI() // loads the GUI for the network setup screen
{
	renderEngine *renderE = renderEngine::Instance();
	Ogre::Viewport *viewPort = renderE->getViewPort();

	MyGUI::LayoutManager::getInstance().loadLayout("NetworkSetupMenu.layout");

	ipAddressBox = mGUI->findWidget<MyGUI::EditBox>("ipAddressBox"); // loads IP Address EditBox
	ipAddressBox->setVisible(false);
    ipAddressBox->setPosition((0.3 *viewPort->getActualWidth() ), (0.10 *viewPort->getActualHeight()) );
	ipAddressBox->setSize((0.4 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

	serverButton = mGUI->findWidget<MyGUI::Button>("serverButton"); // loads Server Button
	serverButton->setVisible(false);
	serverButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::serverButtonClicked);
    serverButton->setPosition((0.3 *viewPort->getActualWidth() ), (0.14 *viewPort->getActualHeight()) );
	serverButton->setSize((0.4 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

	clientButton = mGUI->findWidget<MyGUI::Button>("clientButton"); // loads Client Button
	clientButton->setVisible(false);
	clientButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::clientButtonClicked);
    clientButton->setPosition((0.3 *viewPort->getActualWidth() ), (0.18 *viewPort->getActualHeight()) );
	clientButton->setSize((0.4 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    connectButton = mGUI->findWidget<MyGUI::Button>("connectButton"); // loads Connect Button
    connectButton->setVisible(false);
    connectButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::connectButtonClicked);
    connectButton->setPosition((0.3 *viewPort->getActualWidth() ), (0.22 *viewPort->getActualHeight()) );
	connectButton->setSize((0.4 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    networkSetupMenuCreated = true;
/*    menuActive = true;
	previousActiveMenu = activeMenu;
	activeMenu = NETWORK;
*/
	return true;
}

bool GUISystem::createOptionsMenuGUI()	// creates GUI for options menu screen.
{
	renderEngine *renderE = renderEngine::Instance();
	Ogre::Viewport *viewPort = renderE->getViewPort();

	MyGUI::LayoutManager::getInstance().loadLayout("OptionsMenu.layout");

	displayButton = mGUI->findWidget<MyGUI::Button>("displayButton"); // loads Display Settings Button
	displayButton->setVisible(false);
	displayButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::displayButtonClicked);

	inputButton = mGUI->findWidget<MyGUI::Button>("inputButton"); // loads Input Settings Button
	inputButton->setVisible(false);
	inputButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::inputButtonClicked);

    audioButton = mGUI->findWidget<MyGUI::Button>("audioButton"); // loads Audio Settongs Button
    audioButton->setVisible(false);
    audioButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::audioButtonClicked);

    optionsMenuCreated = true;
/*    menuActive = true;
	previousActiveMenu = activeMenu;
	activeMenu = OPTIONS;
*/
	return (true);
}

bool GUISystem::createBackButtons() // creates the back buttons for the menus
{
	renderEngine *renderE = renderEngine::Instance();
	Ogre::Viewport *viewPort = renderE->getViewPort();

	MyGUI::LayoutManager::getInstance().loadLayout("BackButtons.layout");

	backMainMenuButton = mGUI->findWidget<MyGUI::Button>("backMainMenuButton"); // loads Back to Main Menu Button
    backMainMenuButton->setVisible(false);
    backMainMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backMainMenuButtonClicked);
    backMainMenuButton->setSize((0.4 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

	backNetworkSetupButton = mGUI->findWidget<MyGUI::Button>("backNetworkSetupButton"); // loads Back to Network Setup Button
    backNetworkSetupButton->setVisible(false);
    backNetworkSetupButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backNetworkSetupButtonClicked);
    backNetworkSetupButton->setSize((0.4 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

	backNetworkClientButton = mGUI->findWidget<MyGUI::Button>("backNetworkClientButton"); // loads Back to Network Client Button
	backNetworkClientButton->setVisible(false);
	backNetworkClientButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backNetworkClientButtonClicked);
    backNetworkClientButton->setSize((0.4 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

	backOptionsMenuButton = mGUI->findWidget<MyGUI::Button>("backOptionsMenuButton"); // loads Back to Options Menu Button
	backOptionsMenuButton->setVisible(false);
	backOptionsMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backOptionsMenuButtonClicked);
    backOptionsMenuButton->setSize((0.4 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

	backGameSetupMenuButton = mGUI->findWidget<MyGUI::Button>("backGameSetupMenuButton"); // loads Back to Options Menu Button
	backGameSetupMenuButton->setVisible(false);
	backGameSetupMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backOptionsMenuButtonClicked);
    backGameSetupMenuButton->setSize((0.4 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

	backButtonsCreated = true;

	return (true);
}

bool GUISystem::createDisplaySetupGUI()	// creates GUI for display settings screen.
{
	renderEngine *renderE = renderEngine::Instance();
	Ogre::Viewport *viewPort = renderE->getViewPort();

	MyGUI::LayoutManager::getInstance().loadLayout("DispkaySetupMenu.layout");

	changeResolutionButton = mGUI->findWidget<MyGUI::Button>("changeResolutionButton"); // loads team 1 Button
	changeResolutionButton->setVisible(false);
	changeResolutionButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);

	displaySetupMenuCreated = true;

	return (true);
}

bool GUISystem::createInputSetupGUI()	// creates GUI for input settings screen.
{
	renderEngine *renderE = renderEngine::Instance();
	Ogre::Viewport *viewPort = renderE->getViewPort();

	MyGUI::LayoutManager::getInstance().loadLayout("InputSetupMenu.layout");

	changeInputTypeButton = mGUI->findWidget<MyGUI::Button>("changeInputTypeButton"); // loads team 1 Button
	changeInputTypeButton->setVisible(false);
	changeInputTypeButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeInputTypeButtonClicked);

	inputSetupMenuCreated = true;

	return (true);
}

bool GUISystem::createAudioSetupGUI()	// creates GUI for audo settings screen.
{
	renderEngine *renderE = renderEngine::Instance();
	Ogre::Viewport *viewPort = renderE->getViewPort();

	MyGUI::LayoutManager::getInstance().loadLayout("AudioSetupMenu.layout");

	enableAudioButton = mGUI->findWidget<MyGUI::Button>("enableAudioButton"); // loads team 1 Button
	enableAudioButton->setVisible(false);
	enableAudioButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::enableAudioButtonClicked);

	disableAudioButton = mGUI->findWidget<MyGUI::Button>("disableAudioButton"); // loads team 1 Button
	disableAudioButton->setVisible(false);
	disableAudioButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::disableAudioButtonClicked);

	audioSetupMenuCreated = true;

	return (true);
}


bool GUISystem::createGameSetupMenuGUI()	// creates GUI for game setup menu screen.
{
    gameState *gameS = gameState::Instance();
    loader *load = loader::Instance();
    renderEngine *renderE = renderEngine::Instance();
	Ogre::Viewport *viewPort = renderE->getViewPort();

    load->loadTeams();
    std::vector<teamData> teamDataInstance = gameS->getTeamDataInstance();

	MyGUI::LayoutManager::getInstance().loadLayout("GameSetupMenu.layout");

	team0SelectBox = mGUI->findWidget<MyGUI::ListBox>("team0SelectBox"); // loads team 0 ListBox
	team0SelectBox->setVisible(false);
	team0SelectBox->setSize((0.4 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    team1SelectBox = mGUI->findWidget<MyGUI::ListBox>("team1SelectBox"); // loads team 1 ListBox
    team1SelectBox->setVisible(false);
    team1SelectBox->setSize((0.4 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

	logMsg(Ogre::StringConverter::toString(teamDataInstance.size()));

	for (size_t x=0;x<teamDataInstance.size(); ++x)
	{
	    std::string teamName = teamDataInstance[x].getCity() + " " +teamDataInstance[x].getName();

	    team0SelectBox->addItem(teamName);
	    team1SelectBox->addItem(teamName);
	}
    team0SelectBox->setIndexSelected(0);
	team1SelectBox->setIndexSelected(1);

	team0SelectButton = mGUI->findWidget<MyGUI::Button>("team0SelectButton"); // loads team 0 Select Button
	team0SelectButton->setVisible(false);
	team0SelectButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::team0SelectButtonClicked);
	team0SelectButton->setSize((0.4 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

	team1SelectButton = mGUI->findWidget<MyGUI::Button>("team1SelectButton"); // loads team 1 Button
	team1SelectButton->setVisible(false);
	team1SelectButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::team1SelectButtonClicked);
	team1SelectButton->setSize((0.4 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

	teamsSelectedButton = mGUI->findWidget<MyGUI::Button>("teamsSelectedButton"); // loads team 1 Button
	teamsSelectedButton->setVisible(false);
	teamsSelectedButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::teamsSelectedButtonClicked);
	teamsSelectedButton->setSize((0.4 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

	gameSetupMenuCreated = true;

	return (true);
}

bool GUISystem::createPlayerStartSelectionMenuGUI()  // creates GUI for player selection menu screen.
{
    renderEngine *renderE = renderEngine::Instance();
    Ogre::Viewport *viewPort = renderE->getViewPort();

//    load->loadTeams();
//    std::vector<teamData> teamDataInstance = gameS->getTeamDataInstance();

    MyGUI::LayoutManager::getInstance().loadLayout("PlayerStartSelection.layout");

    team0PGSelectBox = mGUI->findWidget<MyGUI::ListBox>("team0PGSelectBox"); // loads team0PGSelectBox
    team0PGSelectBox->setVisible(false);
//    team0PGSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team0PGSelectBox->setSize((0.3 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );
    team0SGSelectBox = mGUI->findWidget<MyGUI::ListBox>("team0SGSelectBox"); // loads team0SGSelectBox
    team0SGSelectBox->setVisible(false);
//    team0SGSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team0SGSelectBox->setSize((0.3 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    team0SFSelectBox = mGUI->findWidget<MyGUI::ListBox>("team0SFSelectBox"); // loads team0SFSelectBox
    team0SFSelectBox->setVisible(false);
//    team0SFSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team0SFSelectBox->setSize((0.3 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    team0PFSelectBox = mGUI->findWidget<MyGUI::ListBox>("team0PFSelectBox"); // loads team0PFSelectBox
    team0PFSelectBox->setVisible(false);
//    team0PFSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team0PFSelectBox->setSize((0.3 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    team0CSelectBox = mGUI->findWidget<MyGUI::ListBox>("team0CSelectBox"); // loads team0CSelectBox
    team0CSelectBox->setVisible(false);
//    team0CSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team0CSelectBox->setSize((0.3 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    team1PGSelectBox = mGUI->findWidget<MyGUI::ListBox>("team1PGSelectBox"); // loads team1PGSelectBox
    team1PGSelectBox->setVisible(false);
//    team1PGSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team1PGSelectBox->setSize((0.3 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    team1SGSelectBox = mGUI->findWidget<MyGUI::ListBox>("team1SGSelectBox"); // loads team1SGSelectBox
    team1SGSelectBox->setVisible(false);
//    team1SGSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team1SGSelectBox->setSize((0.3 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    team1SFSelectBox = mGUI->findWidget<MyGUI::ListBox>("team1SFSelectBox"); // loads team1SFSelectBox
    team1SFSelectBox->setVisible(false);
//    team1SFSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team1SFSelectBox->setSize((0.3 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    team1PFSelectBox = mGUI->findWidget<MyGUI::ListBox>("team1PFSelectBox"); // loads team0PFSelectBox
    team1PFSelectBox->setVisible(false);
//    team1PFSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team1PFSelectBox->setSize((0.3 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    team1CSelectBox = mGUI->findWidget<MyGUI::ListBox>("team1CSelectBox"); // loads team1CSelectBox
    team1CSelectBox->setVisible(false);
//    team1CSelectBox->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team1CSelectBox->setSize((0.3 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    team0PGRating = mGUI->findWidget<MyGUI::TextBox>("team0PGRating"); // loads team0PGRatimg
    team0PGRating->setVisible(false);
//    team0PGRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team0PGRating->setSize((0.1 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    team0SGRating = mGUI->findWidget<MyGUI::TextBox>("team0SGRating"); // loads team0SGRatimg
    team0SGRating->setVisible(false);
//    team0SGRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team0SGRating->setSize((0.1 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    team0SFRating = mGUI->findWidget<MyGUI::TextBox>("team0SFRating"); // loads team0SFRatimg
    team0SFRating->setVisible(false);
//    team0SFRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team0SFRating->setSize((0.1 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    team0PFRating = mGUI->findWidget<MyGUI::TextBox>("team0PFRating"); // loads team0PFRatimg
    team0PFRating->setVisible(false);
//    team0PFRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team0PFRating->setSize((0.1 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    team0CRating = mGUI->findWidget<MyGUI::TextBox>("team0CRating"); // loads team0CRatimg
    team0CRating->setVisible(false);
//    team0CRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team0CRating->setSize((0.1 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    team1PGRating = mGUI->findWidget<MyGUI::TextBox>("team1PGRating"); // loads team1PGRatimg
    team1PGRating->setVisible(false);
//    team1PGRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team1PGRating->setSize((0.1 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    team1SGRating = mGUI->findWidget<MyGUI::TextBox>("team1SGRating"); // loads team1SGRatimg
    team1SGRating->setVisible(false);
//    team1SGRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team1SGRating->setSize((0.1 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    team1SFRating = mGUI->findWidget<MyGUI::TextBox>("team1SFRating"); // loads team1SFRatimg
    team1SFRating->setVisible(false);
//    team1SFRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team1SFRating->setSize((0.1 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    team1PFRating = mGUI->findWidget<MyGUI::TextBox>("team1PFRating"); // loads team1PFRatimg
    team1PFRating->setVisible(false);
//    team1PFRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team1PFRating->setSize((0.1 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    team1CRating = mGUI->findWidget<MyGUI::TextBox>("team1CRating"); // loads team1CRatimg
    team1CRating->setVisible(false);
//    team1CRating->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team1CRating->setSize((0.1 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );


    team0StartingLineupSetButton = mGUI->findWidget<MyGUI::Button>("team0StartingLineupSetButton"); // loads team0StartingLineupSetButton
    team0StartingLineupSetButton->setVisible(false);
//    team0StartingLineupSetButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team0StartingLineupSetButton->setSize((0.4 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    team1StartingLineupSetButton = mGUI->findWidget<MyGUI::Button>("team1StartinglineupSetButton"); // loads team1StartingLineupSetButton
    team1StartingLineupSetButton->setVisible(false);
//    team0StartingLineupSetButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	team1StartingLineupSetButton->setSize((0.4 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

    startingLineupsSetButton = mGUI->findWidget<MyGUI::Button>("startingLineupsSetButton"); // loads team1StartingLineupSetButton
    startingLineupsSetButton->setVisible(false);
//    team0StartingLineupSetButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
	startingLineupsSetButton->setSize((0.4 *viewPort->getActualWidth() ), (0.04 *viewPort->getActualHeight()) );

/*
    changeResolutionButton = mGUI->findWidget<MyGUI::Button>("changeResolutionButton"); // loads team 1 Button
    changeResolutionButton->setVisible(false);
    changeResolutionButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);
*/

    playerStartSelectionMenuCreated = true;

    return (true);
}

void GUISystem::startSingleGameButtonClicked(MyGUI::Widget *_sender)	// handles startSingleGameButton click event
{
	startSinglePlayerGame();
//    renderEngine * render = renderEngine::Instance();

//	createNetworkSetupGUI();	// creates the GUI for the Network Setup Screen

//    render->createScene();	// creates rendering scene.
}

void GUISystem::startMultiGameButtonClicked(MyGUI::Widget *_sender)	// handles startMultiGameButton click event
{
	startMultiPlayerGame();
//    renderEngine * render = renderEngine::Instance();

//    render->createScene();	// creates rendering scene.
}

void GUISystem::optionsButtonClicked(MyGUI::Widget *_sender)	// handles optionsButton click event
{
    optionsMenu();

//	MyGUI::Widget *widget = MyGUI::InputManager::getInstance().getMouseFocusWidget();
//	_sender->_get
//	std::cout << "Button clicked is " << widget-> << std::endl;
}
void GUISystem::exitButtonClicked(MyGUI::Widget *_sender)	// handles exitButton click event
{
//	MyGUI::Widget *widget = MyGUI::InputManager::getInstance().getMouseFocusWidget();
//	_sender->_get
//	std::cout << "Button clicked is " << widget-> << std::endl;
	exit(0);
}

void GUISystem::serverButtonClicked(MyGUI::Widget *_sender)	// handles serverButton click event
{
    networkServer();
}

void GUISystem::clientButtonClicked(MyGUI::Widget *_sender)	// handles clientButton click event
{
//    networkClient();
    serverButton->setVisible(false);
    ipAddressBox->setVisible(true);
	MyGUI::InputManager::getInstance().setKeyFocusWidget(ipAddressBox);
	previousActiveMenu = activeMenu;
    activeMenu = NETWORKCLIENT;
}

void GUISystem::connectButtonClicked(MyGUI::Widget *_sender) // handles connectButton click event
{
    networkClient();
}

void GUISystem::backMainMenuButtonClicked(MyGUI::Widget *_sender) // handles backMainMenuButton click event
{
	hideNetworkSetupWidgets();
	if (mainMenuCreated)
	{
	    showMainMenuWidgets();
	}
	else
	{
	    createMainMenuGUI();
	}
	menuActive = true;
	previousActiveMenu = activeMenu;
	activeMenu = MAIN;
}

void GUISystem::backNetworkSetupButtonClicked(MyGUI::Widget *_sender) // handles backNetworkSetupButton click event
{
	hideNetworkClientSetupWidgets();
	showNetworkSetupWidgets();
	menuActive = true;
	previousActiveMenu = activeMenu;
	activeMenu = NETWORK;
}

void GUISystem::displayButtonClicked(MyGUI::Widget *_sender) // handles didplayButton click event
{

}

void GUISystem::inputButtonClicked(MyGUI::Widget *_sender) // handles inputButton click event
{

}

void GUISystem::audioButtonClicked(MyGUI::Widget *_sender) // handles audioButton click event
{

}

void GUISystem::changeResolutionButtonClicked(MyGUI::Widget *_sender) // handles changeResolutionButton click event
{

}

void GUISystem::changeInputTypeButtonClicked(MyGUI::Widget *_sender) // handles changeInputTypeButton click event
{

}

void GUISystem::enableAudioButtonClicked(MyGUI::Widget *_sender) // handles eneableAudioButton click event
{

}

void GUISystem::disableAudioButtonClicked(MyGUI::Widget *_sender) // handles eneableAudioButton click event
{

}

void GUISystem::team0SelectButtonClicked(MyGUI::Widget *_sender) // handles team0SelectButton click event
{

}

void GUISystem::team1SelectButtonClicked(MyGUI::Widget *_sender) // handles team1SelectButton click event
{

}

void GUISystem::teamsSelectedButtonClicked(MyGUI::Widget *_sender) // handles teamsSelectButton click event
{

}

void GUISystem::backNetworkClientButtonClicked(MyGUI::Widget *_sender) // handles backNetworkClientButton click event
{
	hideGameSetupMenuWidgets();
	showNetworkClientSetupWidgets();
	previousActiveMenu = activeMenu;
	activeMenu = NETWORKCLIENT;
}

void GUISystem::backOptionsMenuButtonClicked(MyGUI::Widget *_sender) // handles backOptionsMenuButton click event
{

}

void GUISystem::hideMainMenuWidgets()	// hides the widgets tied to the Main Menu
{
	startSingleGameButton->setVisible(false);
	startMultiGameButton->setVisible(false);
	optionsButton->setVisible(false);
	exitButton->setVisible(false);
	startSingleGameButton->setStateSelected(false);
}
void GUISystem::showMainMenuWidgets()         // shows all widgets tied to the Main Menu
{
    startSingleGameButton->setVisible(true);
    startMultiGameButton->setVisible(true);
    optionsButton->setVisible(true);
    exitButton->setVisible(true);
    startSingleGameButton->setStateSelected(true);
    MyGUI::InputManager::getInstance().setKeyFocusWidget(startSingleGameButton);
}
void GUISystem::hideNetworkSetupWidgets()	// hides the widgets tied to the Network Setup Menu
{
//	ipAddressBox->setVisible(false);
	serverButton->setVisible(false);
	clientButton->setVisible(false);
	backMainMenuButton->setVisible(false);
}
void GUISystem::showNetworkSetupWidgets()     // shows all widgets tied to the Network Setup Menu
{
	renderEngine *renderE = renderEngine::Instance();
	Ogre::Viewport *viewPort = renderE->getViewPort();

//    ipAddressBox->setVisible(true);
    serverButton->setVisible(true);
    clientButton->setVisible(true);

	backMainMenuButton->setVisible(true);
	backMainMenuButton->setPosition((0.3 *viewPort->getActualWidth() ), (0.22 *viewPort->getActualHeight()) );

}

void GUISystem::hideNetworkClientSetupWidgets()   // hides the widgets tied to the Network Setup Menu
{
    ipAddressBox->setVisible(false);
    connectButton->setVisible(false);
	backNetworkSetupButton->setVisible(false);
}
void GUISystem::showNetworkClientSetupWidgets()     // shows all widgets tied to the Network Setup Menu
{
    renderEngine *renderE = renderEngine::Instance();
    Ogre::Viewport *viewPort = renderE->getViewPort();

    ipAddressBox->setVisible(true);
    ipAddressBox->setPosition((0.3 *viewPort->getActualWidth() ), (0.10 *viewPort->getActualHeight()) );

    connectButton->setVisible(true);
    connectButton->setPosition((0.3 *viewPort->getActualWidth() ), (0.14 *viewPort->getActualHeight()) );

	backNetworkSetupButton->setVisible(true);
    backNetworkSetupButton->setPosition((0.3 *viewPort->getActualWidth() ), (0.18 *viewPort->getActualHeight()) );

}

void GUISystem::hideOptionsMenuWidgets()	// hides all widgets tied to the Options Menu
{
	displayButton->setVisible(false);
	inputButton->setVisible(false);
	audioButton->setVisible(false);
	backMainMenuButton->setVisible(false);
}
void GUISystem::showOptionsMenuWidgets()  // shows all widgets tied to the Options Menu
{
	renderEngine *renderE = renderEngine::Instance();
	Ogre::Viewport *viewPort = renderE->getViewPort();

	displayButton->setVisible(true);
	inputButton->setVisible(true);
	audioButton->setVisible(true);
	backMainMenuButton->setPosition(362, 275);
	backMainMenuButton->setVisible(true);

}

void GUISystem::hideDisplayMenuWidgets()	// hides all widgets tied to the Display Menu
{
    changeResolutionButton->setVisible(false);

}
void GUISystem::showDisplayMenuWidgets()  // shows all widgets tied to the Display Menu
{
    changeResolutionButton->setVisible(true);
}

void GUISystem::hideInputMenuWidgets()  // hides all widgets tied to the Input Menu
{
    changeInputTypeButton->setVisible(false);
}
void GUISystem::showInputMenuWidgets()  // shows all widgets tied to the Input Menu
{
    changeInputTypeButton->setVisible(true);
}

void GUISystem::hideAudioMenuWidgets()  // hides all widgets tied to the Audio Menu
{
    enableAudioButton->setVisible(false);
    disableAudioButton->setVisible(false);
}
void GUISystem::showAudioMenuWidgets()  // shows all widgets tied to the Main Menu
{
    enableAudioButton->setVisible(true);
    disableAudioButton->setVisible(true);
}

void GUISystem::hideGameSetupMenuWidgets()  // hides all widgets tied to the Game Setup Menu
{
	team0SelectBox->setVisible(false);
	team1SelectBox->setVisible(false);
	team0SelectButton->setVisible(false);
	team1SelectButton->setVisible(false);
	teamsSelectedButton->setVisible(false);
	logMsg("previousActiveMenu = " +Ogre::StringConverter::toString(previousActiveMenu));

	if (previousActiveMenu == MAIN)
	{
        backMainMenuButton->setVisible(false);
	}
	else if (previousActiveMenu == NETWORKCLIENT)
	{
        backNetworkClientButton->setVisible(false);
	}
	else if (previousActiveMenu == NETWORK)
	{
	    backNetworkSetupButton->setVisible(false);

	}
}
void GUISystem::showGameSetupMenuWidgets()  // shows all widgets tied to the Game Setup Menu
{
	renderEngine *renderE = renderEngine::Instance();
	Ogre::Viewport *viewPort = renderE->getViewPort();

	team0SelectBox->setVisible(true);
	team0SelectBox->setPosition((0.1 *viewPort->getActualWidth() ), (0.10 *viewPort->getActualHeight()) );

	team1SelectBox->setVisible(true);
    team1SelectBox->setPosition((0.5*viewPort->getActualWidth() ), (0.10 *viewPort->getActualHeight()) );

    team0SelectButton->setVisible(true);
    team0SelectButton->setPosition((0.1 *viewPort->getActualWidth() ), (0.14 *viewPort->getActualHeight()) );

    team1SelectButton->setVisible(true);
    team1SelectButton->setPosition((0.5 *viewPort->getActualWidth() ), (0.14 *viewPort->getActualHeight()) );

    teamsSelectedButton->setVisible(true);
    teamsSelectedButton->setPosition((0.3 *viewPort->getActualWidth() ), (0.18 *viewPort->getActualHeight()) );
	if (previousActiveMenu == MAIN)
	{
	    backMainMenuButton->setVisible(true);
	    backMainMenuButton->setPosition((0.3 *viewPort->getActualWidth() ), (0.22 *viewPort->getActualHeight()) );

    }
	else if (previousActiveMenu == NETWORKCLIENT)
	{
        backNetworkClientButton->setVisible(true);
        backNetworkClientButton->setPosition((0.3 *viewPort->getActualWidth() ), (0.22 *viewPort->getActualHeight()) );
	}
	else if (previousActiveMenu == NETWORK)
	{
	    backNetworkSetupButton->setVisible(true);
	    backNetworkSetupButton->setPosition((0.3 *viewPort->getActualWidth() ), (0.22 *viewPort->getActualHeight()) );
	}
}

void GUISystem::hidePlayerStartSelectionMenuWidgets() // hides all widgets tied to the Player Start Selection Menu
{

    // Team 0 widgets
    team0PGSelectBox->setVisible(false);
    team0SGSelectBox->setVisible(false);
    team0SFSelectBox->setVisible(false);
    team0PFSelectBox->setVisible(false);
    team0CSelectBox->setVisible(false);

    team0PGRating->setVisible(false);
    team0SGRating->setVisible(false);
    team0SFRating->setVisible(false);
    team0PFRating->setVisible(false);
    team0CRating->setVisible(false);

// FIXME! need to fix image loading
//    team0Logo->setVisible(false);

    team0StartingLineupSetButton->setVisible(false);

    // Team 1 widgets
    team1PGSelectBox->setVisible(false);
    team1SGSelectBox->setVisible(false);
    team1SFSelectBox->setVisible(false);
    team1PFSelectBox->setVisible(false);
    team1CSelectBox->setVisible(false);

    team1PGRating->setVisible(false);
    team1SGRating->setVisible(false);
    team1SFRating->setVisible(false);
    team1PFRating->setVisible(false);
    team1CRating->setVisible(false);

// FIXME! need to fix image loading
//    team1Logo->setVisible(false);

    team1StartingLineupSetButton->setVisible(false);

    startingLineupsSetButton->setVisible(false);
    backGameSetupMenuButton->setVisible(false);

}
void GUISystem::showPlayerStartSelectionMenuWidgets() // shows all widgets tied to the Player Start Selection Menu
{

    renderEngine *renderE = renderEngine::Instance();
    Ogre::Viewport *viewPort = renderE->getViewPort();

    // Team 0 widgets
    team0PGSelectBox->setVisible(true);
    team0PGSelectBox->setPosition((0.1 *viewPort->getActualWidth() ), (0.05 *viewPort->getActualHeight()) );

    team0SGSelectBox->setVisible(true);
    team0SGSelectBox->setPosition((0.1 *viewPort->getActualWidth() ), (0.09 *viewPort->getActualHeight()) );

    team0SFSelectBox->setVisible(true);
    team0SFSelectBox->setPosition((0.1 *viewPort->getActualWidth() ), (0.13 *viewPort->getActualHeight()) );

    team0PFSelectBox->setVisible(true);
    team0PFSelectBox->setPosition((0.1 *viewPort->getActualWidth() ), (0.17 *viewPort->getActualHeight()) );

    team0CSelectBox->setVisible(true);
    team0CSelectBox->setPosition((0.1 *viewPort->getActualWidth() ), (0.21 *viewPort->getActualHeight()) );

    team0PGRating->setVisible(true);
    team0PGRating->setPosition((0.3 *viewPort->getActualWidth() ), (0.05 *viewPort->getActualHeight()) );
    team0PGRating->setTextColour(MyGUI::Colour("Red"));
	team0PGRating->setCaption("99");

    team0SGRating->setVisible(true);
    team0SGRating->setPosition((0.3 *viewPort->getActualWidth() ), (0.21 *viewPort->getActualHeight()) );

    team0SFRating->setVisible(true);
    team0SFRating->setPosition((0.3 *viewPort->getActualWidth() ), (0.21 *viewPort->getActualHeight()) );

    team0PFRating->setVisible(true);
    team0PFRating->setPosition((0.3 *viewPort->getActualWidth() ), (0.21 *viewPort->getActualHeight()) );

    team0CRating->setVisible(true);
    team0CRating->setPosition((0.3 *viewPort->getActualWidth() ), (0.21 *viewPort->getActualHeight()) );


// FIXME! needs image loaded to work
//    team0Logo->setVisible(true);

    team0StartingLineupSetButton->setVisible(true);
    team0StartingLineupSetButton->setPosition((0.1 *viewPort->getActualWidth() ), (0.31 *viewPort->getActualHeight()) );

    // Team 1 widgets
    team1PGSelectBox->setVisible(true);
    team1PGSelectBox->setPosition((0.5 *viewPort->getActualWidth() ), (0.05 *viewPort->getActualHeight()) );

    team1SGSelectBox->setVisible(true);
    team1SGSelectBox->setPosition((0.5 *viewPort->getActualWidth() ), (0.09 *viewPort->getActualHeight()) );

    team1SFSelectBox->setVisible(true);
    team1SFSelectBox->setPosition((0.5 *viewPort->getActualWidth() ), (0.13 *viewPort->getActualHeight()) );

    team1PFSelectBox->setVisible(true);
    team1PFSelectBox->setPosition((0.5 *viewPort->getActualWidth() ), (0.17 *viewPort->getActualHeight()) );

    team1CSelectBox->setVisible(true);
    team1CSelectBox->setPosition((0.5 *viewPort->getActualWidth() ), (0.21 *viewPort->getActualHeight()) );

    team1PGRating->setVisible(true);
    team1PGRating->setPosition((0.8 *viewPort->getActualWidth() ), (0.21 *viewPort->getActualHeight()) );

    team1SGRating->setVisible(true);
    team1SGRating->setPosition((0.8 *viewPort->getActualWidth() ), (0.21 *viewPort->getActualHeight()) );

    team1SFRating->setVisible(true);
    team1SFRating->setPosition((0.8 *viewPort->getActualWidth() ), (0.21 *viewPort->getActualHeight()) );

    team1PFRating->setVisible(true);
    team1PFRating->setPosition((0.8 *viewPort->getActualWidth() ), (0.21 *viewPort->getActualHeight()) );

    team1CRating->setVisible(true);
    team1CRating->setPosition((0.8 *viewPort->getActualWidth() ), (0.21 *viewPort->getActualHeight()) );

// FIXME! needs image loaded to work
//    team1Logo->setVisible(true);

    team1StartingLineupSetButton->setVisible(true);
    team1StartingLineupSetButton->setPosition((0.5 *viewPort->getActualWidth() ), (0.31 *viewPort->getActualHeight()) );


    startingLineupsSetButton->setVisible(true);
    startingLineupsSetButton->setPosition((0.25 *viewPort->getActualWidth() ), (0.35 *viewPort->getActualHeight()) );

    backGameSetupMenuButton->setVisible(true);
    backGameSetupMenuButton->setPosition((0.25 *viewPort->getActualWidth() ), (0.4 *viewPort->getActualHeight()) );

}

void GUISystem::menuReceiveKeyPress(std::string keyPressed) // processes key input
{
	switch (activeMenu)
	{
		case MAIN:
	        processMainMenuKeyPress(keyPressed);
			break;
		case NETWORK:
			processNetworkMenuKeyPress(keyPressed);
			break;
		case NETWORKCLIENT:
            processNetworkClientMenuKeyPress(keyPressed);
            break;
		case OPTIONS:
			processOptionsMenuKeyPress(keyPressed);
			break;
		case DISPLAY:
		    processDisplayMenuKeyPress(keyPressed);
		    break;
		case INPUTMENU:
		    processInputMenuKeyPress(keyPressed);
		    break;
		case AUDIO:
		    processAudioMenuKeyPress(keyPressed);
		case GAMESETUP:
			processGameSetupMenuKeyPress(keyPressed);
        case PLAYERSTART:
            processPlayerStartSelectionMenuKeyPress(keyPressed);
		default:
		    break;
	}
}

void GUISystem::processMainMenuKeyPress(std::string keyPressed) // processes main menu key input
{
	if (keyPressed == "s")
	{
		hideMainMenuWidgets();	// Hides the widgets from the main menu
		startSinglePlayerGame();
	}
	else if (keyPressed == "m")
	{
		hideMainMenuWidgets();	// Hides the widgets from the main menu
		startMultiPlayerGame();
	}
	else if (keyPressed == "o")
	{
		hideMainMenuWidgets();	// Hides the widgets from the main menu
        optionsMenu();
	}
	else if (keyPressed == "e")
	{
		exit(0);
	}
	else
	{

	}
}
void GUISystem::processNetworkMenuKeyPress(std::string keyPressed) // processes network menu key input
{
   if (keyPressed == "c")
    {
       hideNetworkSetupWidgets();
       showNetworkClientSetupWidgets();
	   previousActiveMenu = activeMenu;
       activeMenu = NETWORKCLIENT;
    }
    else if (keyPressed == "b")
    {
        hideNetworkSetupWidgets();
        showMainMenuWidgets();
		previousActiveMenu = activeMenu;
        activeMenu = MAIN;
    }
    else if (keyPressed == "s")
    {
	    hideNetworkSetupWidgets();
		gameSetupMenu();
		previousActiveMenu = activeMenu;
		activeMenu = GAMESETUP;
 //       networkServer();
    }
    else
    {

    }
}

void GUISystem::processNetworkClientMenuKeyPress(std::string keyPressed) // processes network menu key input
{
    if (keyPressed == "0")
    {
        ipAddressBox->addText("0");
    }
    else if (keyPressed == "1")
    {
        ipAddressBox->addText("1");
    }
    else if (keyPressed == "2")
    {
        ipAddressBox->addText("2");
    }
    else if (keyPressed == "3")
    {
        ipAddressBox->addText("3");
    }
    else if (keyPressed == "4")
    {
        ipAddressBox->addText("4");
    }
    else if (keyPressed == "5")
    {
        ipAddressBox->addText("5");
    }
    else if (keyPressed == "6")
    {
        ipAddressBox->addText("6");
    }
    else if (keyPressed == "7")
    {
        ipAddressBox->addText("7");
    }
    else if (keyPressed == "8")
    {
        ipAddressBox->addText("8");
    }
    else if (keyPressed == "9")
    {
        ipAddressBox->addText("9");
    }
    else if (keyPressed == ".")
    {
        ipAddressBox->addText(".");
    }
    else if (keyPressed == "c")
    {
        hideNetworkClientSetupWidgets();
        networkClient();
    }
	else if (keyPressed == "b")
    {
        hideNetworkClientSetupWidgets();
        showNetworkSetupWidgets();
		previousActiveMenu = activeMenu;
		activeMenu = NETWORK;
        startMultiPlayerGame();
    }

}

void GUISystem::processOptionsMenuKeyPress(std::string keyPressed) // processes options menu key input
{
    if (keyPressed == "d")
    {
       hideOptionsMenuWidgets();
       showDisplayMenuWidgets();
	   previousActiveMenu = activeMenu;
       activeMenu = DISPLAY;
    }
    else if (keyPressed == "b")
    {
        hideOptionsMenuWidgets();
        showMainMenuWidgets();
		previousActiveMenu = activeMenu;
        activeMenu = MAIN;
    }
    else if (keyPressed == "i")
    {
        hideOptionsMenuWidgets();
        showInputMenuWidgets();
		previousActiveMenu = activeMenu;
        activeMenu = INPUTMENU;
    }
	else if (keyPressed == "a")
    {
        hideOptionsMenuWidgets();
        showAudioMenuWidgets();
		previousActiveMenu = activeMenu;
        activeMenu = AUDIO;
    }
    else
    {

    }
}

void GUISystem::processDisplayMenuKeyPress(std::string keyPressed) // processes display settings menu key input
{

	if (keyPressed == "c")
    {
		// placeholder
	}
	else if (keyPressed == "b")
	{
		hideDisplayMenuWidgets();
		optionsMenu();
	}

}

void GUISystem::processInputMenuKeyPress(std::string keyPressed) // processes input settings menu key input
{

}

void GUISystem::processAudioMenuKeyPress(std::string keyPressed) // processes audio settings menu key input
{

}

void GUISystem::processGameSetupMenuKeyPress(std::string keyPressed) // processes game setup menu key input
{
    gameState *gameS = gameState::Instance();
	std::vector<teamData> teamDataInstance = gameS->getTeamDataInstance();
	if (keyPressed == "a" && !gameSetupMenuAwaySelected)
    {
		MyGUI::InputManager::getInstance().setKeyFocusWidget(team1SelectBox);
		gameSetupMenuAwaySelected = true;
		gameSetupMenuHomeSelected = false;
/*		logMsg(Ogre::StringConverter::toString(team1SelectBox->getIndexSelected()));

		logMsg(team1SelectBox->getItemNameAt(team1SelectBox->getIndexSelected()));
        team1SelectBox->setIndexSelected(0);
	team1SelectBox->beginToItemAt(1);
		exit(0);
*/
	}
	else if (keyPressed == "h" && !gameSetupMenuHomeSelected)
    {
		MyGUI::InputManager::getInstance().setKeyFocusWidget(team0SelectBox);
        gameSetupMenuHomeSelected = true;
		gameSetupMenuAwaySelected = false;
	}
	else if (keyPressed == "b")
    {
	    hideGameSetupMenuWidgets();
		if (previousActiveMenu == MAIN)
		{
		    backMainMenuButton->setVisible(false);
			showMainMenuWidgets();
			previousActiveMenu = activeMenu;
	        activeMenu = MAIN;
		}
		else if (previousActiveMenu == NETWORKCLIENT)
		{
	        showNetworkClientSetupWidgets();
			previousActiveMenu = activeMenu;
	        activeMenu = NETWORKCLIENT;
		}
		else if (previousActiveMenu == NETWORK)
		{
		    showNetworkSetupWidgets();
		    previousActiveMenu = activeMenu;
		    activeMenu = NETWORK;
		}

//	    previousActiveMenu = activeMenu;
//	    activeMenu = NETWORKCLIENT;
	}
	else if (keyPressed == "t")
	{
	    hideGameSetupMenuWidgets();
//		menuActive = false;
        previousActiveMenu = activeMenu;
	    activeMenu = PLAYERSTART;
        std::vector<int> teamID;
        teamID.push_back(team0SelectBox->getIndexSelected());
        teamID.push_back(team1SelectBox->getIndexSelected());
        gameS->setTeamID(teamID);
        playerStartSelectionMenu();
//        gameS->setGameSetupComplete(true);
//	    networkServer();
	}
	else if (keyPressed == "x")
	{
		if (gameSetupMenuAwaySelected)
		{
			int x = team1SelectBox->getIndexSelected() +1;
			if (x < teamDataInstance.size())
			{
			    team1SelectBox->setIndexSelected(x);
	            team1SelectBox->beginToItemAt(x);
			}
			else
			{
				team1SelectBox->setIndexSelected(0);
	            team1SelectBox->beginToItemAt(0);
			}
		}
		else if (gameSetupMenuHomeSelected)
		{
			int x = team0SelectBox->getIndexSelected() +1;
			if (x < teamDataInstance.size())
			{
			    team0SelectBox->setIndexSelected(x);
	            team0SelectBox->beginToItemAt(x);
			}
			else
			{
				team0SelectBox->setIndexSelected(0);
	            team0SelectBox->beginToItemAt(0);
			}
		}
		else
		{

		}
	}
	else if (keyPressed == "z")
	{
		if (gameSetupMenuAwaySelected)
		{
			int x = team1SelectBox->getIndexSelected() -1;
			if (x < 0)
			{
			    team1SelectBox->setIndexSelected(teamDataInstance.size() -1);
	            team1SelectBox->beginToItemAt(teamDataInstance.size() -1);
			}
			else
			{
				//exit(0);
				team1SelectBox->setIndexSelected(x);
	            team1SelectBox->beginToItemAt(x);
			}
		}
		else if (gameSetupMenuHomeSelected)
		{
			int x = team0SelectBox->getIndexSelected() -1;
			if (x < 0)
			{
			    team0SelectBox->setIndexSelected(teamDataInstance.size() -1);
	            team0SelectBox->beginToItemAt(teamDataInstance.size() -1);
			}
			else
			{
				team0SelectBox->setIndexSelected(x);
	            team0SelectBox->beginToItemAt(x);
			}
		}
		else
		{

		}
	}
}

void GUISystem::processPlayerStartSelectionMenuKeyPress(std::string keyPressed)   // process player start selection menu key input
{
    gameState *gameS = gameState::Instance();


    if (keyPressed == "s")
    {
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
        
        logMsg("team 0 C selectbox id = " +Ogre::StringConverter::toString(teamStarterID[0][1]));
        logMsg("team 0 starter 0 = " +Ogre::StringConverter::toString(teamStarterID[0][0]));
        logMsg("team  0 starter 0 = " +team0Starters[0]);
//        exit(0);
        hidePlayerStartSelectionMenuWidgets();
    	menuActive = false;
        gameS->setGameSetupComplete(true);
    }
    else if (keyPressed == "b")
    {
    	hidePlayerStartSelectionMenuWidgets();
    	previousActiveMenu = activeMenu;
    	activeMenu = GAMESETUP;
    	gameSetupMenu();
    }
}

void GUISystem::startSinglePlayerGame() // starts single player game
{
	gameState *gameS = gameState::Instance();

    gameS->setGameType(SINGLE);
	hideMainMenuWidgets();	// Hides the widgets from the main menu
	previousActiveMenu = activeMenu;
	activeMenu = GAMESETUP;
    gameSetupMenu();
//	menuActive = false;
}

void GUISystem::startMultiPlayerGame() // starts multiplayer game
{
    menuActive = true;
	previousActiveMenu = activeMenu;
    activeMenu = NETWORK;

	if (networkSetupMenuCreated)
	{
	    showNetworkSetupWidgets();
	}
	else
	{
	    createNetworkSetupGUI();	// creates the GUI for the Network Setup Screen
	    showNetworkSetupWidgets();
	}

}

void GUISystem::optionsMenu() // displays options menu
{


	if (!optionsMenuCreated)
	{
		createOptionsMenuGUI();
	}

	showOptionsMenuWidgets();
    menuActive = true;
	previousActiveMenu = activeMenu;
	activeMenu = OPTIONS;

}

void GUISystem::gameSetupMenu() // displays game setup menu
{
	if (!gameSetupMenuCreated)
	{
		createGameSetupMenuGUI();
		gameSetupMenuCreated = true;
	}

	showGameSetupMenuWidgets();
	menuActive = true;
//	previousActiveMenu = activeMenu;
//	activeMenu = GAMESETUP;

}

void GUISystem::playerStartSelectionMenu() // displays player start selection menu
{
    if (!playerStartSelectionMenuCreated)
    {
        createPlayerStartSelectionMenuGUI();
        addPlayerStartSelectionMenuData();
        playerStartSelectionMenuCreated = true;
    }

    showPlayerStartSelectionMenuWidgets();
    menuActive = true;
//  previousActiveMenu = activeMenu;
//  activeMenu = GAMESETUP;
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

    team0PGSelectBox->setIndexSelected(0);
    team0SGSelectBox->setIndexSelected(0);
    team0SFSelectBox->setIndexSelected(0);
    team0PFSelectBox->setIndexSelected(0);
    team0CSelectBox->setIndexSelected(0);
    team1PGSelectBox->setIndexSelected(0);
    team1SGSelectBox->setIndexSelected(0);
    team1SFSelectBox->setIndexSelected(0);
    team1PFSelectBox->setIndexSelected(0);
    team1CSelectBox->setIndexSelected(1);

}

void GUISystem::clientSetup() // sets up the client connection
{

}

void GUISystem::networkServer()  // sets up  game as a network server
{
    networkEngine * network = networkEngine::Instance();
    gameEngine * gameE = gameEngine::Instance();
    gameState *gameS = gameState::Instance();

    gameS->setGameType(MULTI);
 //   hideNetworkSetupWidgets();  // Hides Network Setup Menu widgets
    menuActive = false;
    network->setIPAddress(ipAddressBox->getCaption());  // sets the neworkEngine's ipAddress string to that of the caption
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
    network->setIPAddress(ipAddressBox->getCaption());  // sets the neworkEngine's ipAddress string to that of the caption
//    network->networkClient();
    network->clientConnect();
//    gameE->setCreateScene(true); // sets variable true that tells gameEngine to start rendering the scenetop

}
