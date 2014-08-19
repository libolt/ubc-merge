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


#include "gui.h"a
#include "gameengine.h"
#include "gamestate.h"
#include "load.h"
#include "logging.h"
#include "network.h"
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

	logMsg("Loading MainMenu layout");
	MyGUI::LayoutManager::getInstance().loadLayout("MainMenu.layout");
	logMsg("MainMenu layout loaded");
//	startGameButton = mGUI->createWidget<MyGUI::Button>("Button", 362, 100, 300, 26, MyGUI::Align::Default, "Main");
//	startGameButton->setCaption("Start Game");
	startSingleGameButton = mGUI->findWidget<MyGUI::Button>("startSingleGameButton");
	startSingleGameButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::startSingleGameButtonClicked);
    startSingleGameButton->setStateSelected(true);
	MyGUI::InputManager::getInstance().setKeyFocusWidget(startSingleGameButton);

	startMultiGameButton = mGUI->findWidget<MyGUI::Button>("startMultiGameButton");
	startMultiGameButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::startMultiGameButtonClicked);

//	optionsButton = mGUI->createWidget<MyGUI::Button>("Button", 362, 125, 300, 26, MyGUI::Align::Default, "Main");
//	optionsButton->setCaption("Options");
	optionsButton = mGUI->findWidget<MyGUI::Button>("optionsButton");
	optionsButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::optionsButtonClicked);

//	exitButton = mGUI->createWidget<MyGUI::Button>("Button", 362, 150, 300, 26, MyGUI::Align::Default, "Main");
//	exitButton->setCaption("Exit");
	exitButton = mGUI->findWidget<MyGUI::Button>("exitButton");
	exitButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::exitButtonClicked);

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
	MyGUI::LayoutManager::getInstance().loadLayout("NetworkSetupMenu.layout");

	ipAddressBox = mGUI->findWidget<MyGUI::EditBox>("ipAddressBox"); // loads IP Address EditBox
	ipAddressBox->setVisible(false);

	serverButton = mGUI->findWidget<MyGUI::Button>("serverButton"); // loads Server Button
	serverButton->setVisible(false);
	serverButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::serverButtonClicked);

	clientButton = mGUI->findWidget<MyGUI::Button>("clientButton"); // loads Client Button
	clientButton->setVisible(false);
	clientButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::clientButtonClicked);

    connectButton = mGUI->findWidget<MyGUI::Button>("connectButton"); // loads Connect Button
    connectButton->setVisible(false);
    connectButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::connectButtonClicked);

    networkSetupMenuCreated = true;
/*    menuActive = true;
	previousActiveMenu = activeMenu;
	activeMenu = NETWORK;
*/
	return true;
}

bool GUISystem::createOptionsMenuGUI()	// creates GUI for options menu screen.
{
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
	MyGUI::LayoutManager::getInstance().loadLayout("BackButtons.layout");

	backMainMenuButton = mGUI->findWidget<MyGUI::Button>("backMainMenuButton"); // loads Back to Main Menu Button
    backMainMenuButton->setVisible(false);
    backMainMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backMainMenuButtonClicked);

	backNetworkSetupButton = mGUI->findWidget<MyGUI::Button>("backNetworkSetupButton"); // loads Back to Network Setup Button
    backNetworkSetupButton->setVisible(false);
    backNetworkSetupButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backNetworkSetupButtonClicked);

	backNetworkClientButton = mGUI->findWidget<MyGUI::Button>("backNetworkClientButton"); // loads Back to Network Client Button
	backNetworkClientButton->setVisible(false);
	backNetworkClientButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backNetworkClientButtonClicked);

	backOptionsMenuButton = mGUI->findWidget<MyGUI::Button>("backOptionsMenuButton"); // loads Back to Options Menu Button
	backOptionsMenuButton->setVisible(false);
	backOptionsMenuButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::backOptionsMenuButtonClicked);

	backButtonsCreated = true;

	return (true);
}

bool GUISystem::createDisplaySetupGUI()	// creates GUI for display settings screen.
{
	MyGUI::LayoutManager::getInstance().loadLayout("DispkaySetupMenu.layout");

	changeResolutionButton = mGUI->findWidget<MyGUI::Button>("changeResolutionButton"); // loads team 1 Button
	changeResolutionButton->setVisible(false);
	changeResolutionButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeResolutionButtonClicked);

	displaySetupMenuCreated = true;

	return (true);
}

bool GUISystem::createInputSetupGUI()	// creates GUI for input settings screen.
{
	MyGUI::LayoutManager::getInstance().loadLayout("InputSetupMenu.layout");

	changeInputTypeButton = mGUI->findWidget<MyGUI::Button>("changeInputTypeButton"); // loads team 1 Button
	changeInputTypeButton->setVisible(false);
	changeInputTypeButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::changeInputTypeButtonClicked);

	inputSetupMenuCreated = true;

	return (true);
}

bool GUISystem::createAudioSetupGUI()	// creates GUI for audo settings screen.
{
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

    load->loadTeams();
    std::vector<teamData> teamDataInstance = gameS->getTeamDataInstance();

	MyGUI::LayoutManager::getInstance().loadLayout("GameSetupMenu.layout");

	team0SelectBox = mGUI->findWidget<MyGUI::ListBox>("team0SelectBox"); // loads team 0 ListBox
	team0SelectBox->setVisible(false);

    team1SelectBox = mGUI->findWidget<MyGUI::ListBox>("team1SelectBox"); // loads team 1 ListBox
    team1SelectBox->setVisible(false);

	logMsg(Ogre::StringConverter::toString(teamDataInstance.size()));

	for (int x=0;x<teamDataInstance.size(); ++x)
	{
	    std::string teamName = teamDataInstance[x].getCity() + " " +teamDataInstance[x].getName();

	    team0SelectBox->addItem(teamName);
	    team1SelectBox->addItem(teamName);
	}
    team0SelectBox->setIndexSelected(0);
	team1SelectBox->setIndexSelected(0);
	team1SelectBox->beginToItemAt(1);
	team0SelectButton = mGUI->findWidget<MyGUI::Button>("team0SelectButton"); // loads team 0 Select Button
	team0SelectButton->setVisible(false);
	team0SelectButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::team0SelectButtonClicked);

	team1SelectButton = mGUI->findWidget<MyGUI::Button>("team1SelectButton"); // loads team 1 Button
	team1SelectButton->setVisible(false);
	team1SelectButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::team1SelectButtonClicked);

	startGameButton = mGUI->findWidget<MyGUI::Button>("startGameButton"); // loads team 1 Button
	startGameButton->setVisible(false);
	startGameButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::team1SelectButtonClicked);

	gameSetupMenuCreated = true;

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
//    ipAddressBox->setVisible(true);
    serverButton->setVisible(true);
    clientButton->setVisible(true);
    backMainMenuButton->setPosition(362, 250);
	backMainMenuButton->setVisible(true);
}

void GUISystem::hideNetworkClientSetupWidgets()   // hides the widgets tied to the Network Setup Menu
{
    ipAddressBox->setVisible(false);
    connectButton->setVisible(false);
	backNetworkSetupButton->setVisible(false);
}
void GUISystem::showNetworkClientSetupWidgets()     // shows all widgets tied to the Network Setup Menu
{
    ipAddressBox->setVisible(true);
    connectButton->setVisible(true);
	backNetworkSetupButton->setVisible(true);
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
	startGameButton->setVisible(false);
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
	team0SelectBox->setVisible(true);
	team1SelectBox->setVisible(true);
	team0SelectButton->setVisible(true);
	team1SelectButton->setVisible(true);
    startGameButton->setVisible(true);
	if (previousActiveMenu == MAIN)
	{
	    backMainMenuButton->setPosition(362, 250);
	    backMainMenuButton->setVisible(true);
    }
	else if (previousActiveMenu == NETWORKCLIENT)
	{
        backNetworkClientButton->setVisible(true);
	}
	else if (previousActiveMenu == NETWORK)
	{
	    backNetworkSetupButton->setVisible(true);
	}
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
	else if (keyPressed == "s")
	{
	    hideGameSetupMenuWidgets();
		menuActive = false;
		gameS->setGameSetupComplete(true);
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

void GUISystem::startSinglePlayerGame() // starts single player game
{
	gameState *gameS = gameState::Instance();

    gameS->setGameType(SINGLE);
	hideMainMenuWidgets();	// Hides the widgets from the main menu
	previousActiveMenu = activeMenu;
	activeMenu = GAMESETUP,
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
