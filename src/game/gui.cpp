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
#include "logging.h"
#include "network.h"

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

}

GUISystem::~GUISystem()
{

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

bool GUISystem::createMainMenuButtons()
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
	ipAddressBox->setVisible(true);

	serverButton = mGUI->findWidget<MyGUI::Button>("serverButton"); // loads Server Button
	serverButton->setVisible(true);
	serverButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::serverButtonClicked);

	clientButton = mGUI->findWidget<MyGUI::Button>("clientButton"); // loads Client Button
	clientButton->setVisible(true);
	clientButton->eventMouseButtonClick += MyGUI::newDelegate(this, &GUISystem::clientButtonClicked);


	return true;
}


void GUISystem::startSingleGameButtonClicked(MyGUI::Widget *_sender)	// handles startSingleGameButton click event
{
    renderEngine * render = renderEngine::Instance();
    gameState *gameS = gameState::Instance();

    gameS->setGameType(SINGLE);
	hideMainMenuWidgets();	// Hides the widgets from the main menu
//	createNetworkSetupGUI();	// creates the GUI for the Network Setup Screen

//    render->createScene();	// creates rendering scene.
}

void GUISystem::startMultiGameButtonClicked(MyGUI::Widget *_sender)	// handles startMultiGameButton click event
{
    renderEngine * render = renderEngine::Instance();
    gameState *gameS = gameState::Instance();

    gameS->setGameType(MULTI);
	hideMainMenuWidgets();	// Hides the widgets from the main menu
	createNetworkSetupGUI();	// creates the GUI for the Network Setup Screen

//    render->createScene();	// creates rendering scene.
}

void GUISystem::optionsButtonClicked(MyGUI::Widget *_sender)	// handles optionsButton click event
{
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
    networkEngine * network = networkEngine::Instance();
    gameEngine * gameE = gameEngine::Instance();

    hideNetworkSetupWidgets();	// Hides Network Setup Menu widgets
    network->setIPAddress(ipAddressBox->getCaption());	// sets the neworkEngine's ipAddress string to that of the caption
//    network->networkServer();
    network->serverSetup();
//    gameE->setCreateScene(true); // sets variable true that tells gameEngine to start rendering the scene

}

void GUISystem::clientButtonClicked(MyGUI::Widget *_sender)	// handles clientButton click event
{
    networkEngine * network = networkEngine::Instance();
    gameEngine * gameE = gameEngine::Instance();

    hideNetworkSetupWidgets();	// Hides Network Setup Menu widgets
    network->setIPAddress(ipAddressBox->getCaption());	// sets the neworkEngine's ipAddress string to that of the caption
//    network->networkClient();
    network->clientConnect();
//    gameE->setCreateScene(true); // sets variable true that tells gameEngine to start rendering the scenetop

}

void GUISystem::hideMainMenuWidgets()	// hides the widgets tied to the Main Menu
{
	startSingleGameButton->setVisible(false);
	startMultiGameButton->setVisible(false);
	optionsButton->setVisible(false);
	exitButton->setVisible(false);
}

void GUISystem::hideNetworkSetupWidgets()	// hides the widgets tied to the Network Setup Menu
{
	ipAddressBox->setVisible(false);
	serverButton->setVisible(false);
	clientButton->setVisible(false);
}
