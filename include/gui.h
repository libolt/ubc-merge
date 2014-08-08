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

#ifndef _GUI_H_
#define _GUI_H_

//mem probs without this next one
#ifdef __APPLE__
//include <Ogre/OgreNoMemoryMacros.h>
#else
#endif

#include "MyGUI.h"
#include "MyGUI_OgrePlatform.h"
//#include "MyGUI_OgreRenderManager.h"

#include "enums.h"
#include "input.h"
#include "renderengine.h"


class GUISystem //: public renderEngine //, inputSystem
{
public:

    virtual ~GUISystem();

    static GUISystem *Instance();

    bool getMainMenuCreated();   // retrieves the value of mainMenuCreated
    void setMainMenuCreated(bool created); // sets the value of mainMenuCreated

    bool getNetworkSetupMenuCreated();  // retrieves the value of networkSetupMenuCreated
    void setNetworkSetupMenuCreated(bool created);  // sets the value of networkSetupMenuCreated

	bool getOptionsMenuCreated();  // retrieves the value of optionsMenuCreated
    void setOptionsMenuCreated(bool created);  // sets the value of optionsMenuCreated

	bool getDisplaySettingsMenuCreated();  // retrieves the value of displaySettingsMenuCreated
    void setDisplaySettingsMenuCreated(bool created);  // sets the value of displaySettingsMenuCreated

	bool getInputSettingsMenuCreated();  // retrieves the value of inputSettingsMenuCreated
    void setInputSettingsMenuCreated(bool created);  // sets the value of inputSettingsMenuCreated

	bool getAuduoSettingsMenuCreated();  // retrieves the value of audioSettingsMenuCreated
    void setAudioSettingsMenuCreated(bool created);  // sets the value of audioSettingsMenuCreated

	bool getGameSetupMenuCreated();  // retrieves the value of gameSetupMenuCreated
    void setGameSetupMenuCreated(bool created);  // sets the value of gameSetupMenuCreated

	bool getMenuActive(); // retrieves the value of menuActive
	void setMenuActive(bool active); // sets the value of menuActive

	activeMenus getActiveMenu(); // retrieves the value of activeMenu
	void setActiveMenu(activeMenus menu); // sets the value of activeMenu

	activeMenus getPreviousActiveMenu(); // retrieves the value of previousActiveMenu
	void setPreviousActiveMenu(activeMenus menu); // sets the value of previousActiveMenu

    bool initMyGUI();	// Initializes MyGUI
    bool createMainMenuGUI(); // creates GUI gor main menu screen.
    bool createNetworkSetupGUI();	// creates GUI for network setup screen.
	bool createOptionsMenuGUI();	// creates GUI for options menu screen.
    bool createDisplaySettingsGUI();	// creates GUI for display settings screen.
    bool createInputSettingsGUI();	// creates GUI for input settings screen.
	bool createAudioSettingsGUI();	// creates GUI for audo settings screen.
    bool createGameSetupMenuGUI();	// creates GUI for game setup menu screen.
	bool createBackButtons(); // creates the back buttons for the menus
	
    void menuReceiveKeyPress(std::string keyPressed); // processes key input
	void processMainMenuKeyPress(std::string keyPressed); // processes main menu key input
    void processNetworkMenuKeyPress(std::string keyPressed); // processes network menu key input
    void processNetworkClientMenuKeyPress(std::string keyPressed); // process network client menu key input
    void processOptionsMenuKeyPress(std::string keyPressed); // processes options menu key input
    void processDisplayMenuKeyPress(std::string keyPressed); // processes display settings menu key input
    void processInputMenuKeyPress(std::string keyPressed); // processes input settings menu key input
    void processAudioMenuKeyPress(std::string keyPressed); // processes audio settings menu key input
    void processGameSetupMenuKeyPress(std::string keyPressed); // processes game setup menu key input

	
	void startSinglePlayerGame(); // starts single player game
	void startMultiPlayerGame(); // starts multiplayer game
    void optionsMenu(); // displays options menu
    void gameSetupMenu(); // displays game setup menu
	void clientSetup(); // sets up the client connection

     void networkServer();  // sets up  game as a network server
     void networkClient();  // sets up game as a network client
protected:

    GUISystem();
    GUISystem(const GUISystem&);
    GUISystem& operator= (const GUISystem&);

    // MyGUI functions
    void startSingleGameButtonClicked(MyGUI::Widget *_sender);
    void startMultiGameButtonClicked(MyGUI::Widget *_sender);
    void optionsButtonClicked(MyGUI::Widget *_sender);
    void exitButtonClicked(MyGUI::Widget *_sender);
    void serverButtonClicked(MyGUI::Widget *_sender);
    void clientButtonClicked(MyGUI::Widget *_sender);
    void connectButtonClicked(MyGUI::Widget *_sender); // handles connectButton click event
    void backMainMenuButtonClicked(MyGUI::Widget *_sender); // handles backMainMenuButton click event
    void backNetworkSetupButtonClicked(MyGUI::Widget *_sender); // handles backNetworkSetupButton click event
    void displayButtonClicked(MyGUI::Widget *_sender); // handles didplayButton click event
    void inputButtonClicked(MyGUI::Widget *_sender); // handles inputButton click event
    void audioButtonClicked(MyGUI::Widget *_sender); // handles audioButton click event
    void team0SelectButtonClicked(MyGUI::Widget *_sender); // handles team0SelectButton click event
    void team1SelectButtonClicked(MyGUI::Widget *_sender); // handles team1SelectButton click event
    void backNetworkClientButtonClicked(MyGUI::Widget *_sender); // handles backNetworkClientButton click event

	
    void hideMainMenuWidgets();	// hides all widgets tied to the Main Menu
    void showMainMenuWidgets(); // shows all widgets tied to the Main Menu

    void hideNetworkSetupWidgets();	// hides all widgets tied to the Network Setup Menu
    void showNetworkSetupWidgets(); // shows all widgets tied to the Network Setup Menu

    void hideNetworkClientSetupWidgets();  // hides all widgets tied to the Network Setup Menu
    void showNetworkClientSetupWidgets();  // shows all widgets tied to the Network Setup Menu

	void hideOptionsMenuWidgets();	// hides all widgets tied to the Options Menu
    void showOptionsMenuWidgets();  // shows all widgets tied to the Options Menu

	void hideDisplayMenuWidgets();	// hides all widgets tied to the Display Menu
    void showDisplayMenuWidgets();  // shows all widgets tied to the Display Menu

	void hideInputMenuWidgets();  // hides all widgets tied to the Input Menu
    void showInputMenuWidgets();  // shows all widgets tied to the Input Menu

	void hideAudioMenuWidgets();  // hides all widgets tied to the Audio Menu
    void showAudioMenuWidgets();  // shows all widgets tied to the Audio Menu

	void hideGameSetupMenuWidgets();  // hides all widgets tied to the Game Setup Menu
    void showGameSetupMenuWidgets();  // shows all widgets tied to the Game Setup Menu

private:

    static GUISystem *pInstance;
    MyGUI::Gui *mGUI;
    MyGUI::OgrePlatform *mPlatform;

    // button widgets
    MyGUI::Button *exitButton;
    MyGUI::Button *startSingleGameButton;
    MyGUI::Button *startMultiGameButton;
    MyGUI::Button *optionsButton;
    MyGUI::Button *serverButton;
    MyGUI::Button *clientButton;
    MyGUI::Button *connectButton;
    MyGUI::Button *backMainMenuButton;
	MyGUI::Button *backNetworkSetupButton;
    MyGUI::Button *displayButton;
	MyGUI::Button *inputButton;
	MyGUI::Button *audioButton;
	MyGUI::Button *team0SelectButton;
	MyGUI::Button *team1SelectButton;
	MyGUI::Button *backNetworkClientButton;
    // text widgets
    MyGUI::EditBox *ipAddressBox;

	// listbox widgets
	MyGUI::ListBox *team0SelectBox;
	MyGUI::ListBox *team1SelectBox;
	
	// booleans
    bool mainMenuCreated;   // determines whether the main menu gui has been created
    bool networkSetupMenuCreated;   // determines whether the network setup gui has been created
    bool optionsMenuCreated;   // determines whether the options menu gui has been created
    bool displaySettingsMenuCreated;   // determines whether the display settings menu gui has been created
    bool inputSettingsMenuCreated;   // determines whether the input settings menu gui has been created
    bool audioSettingsMenuCreated;   // determines whether the audio settings menu gui has been created
    bool gameSetupMenuCreated;  // determines whether the game setup menu gui has been created
	bool backButtonsCreated; // determines the back buttons have been created
	bool menuActive; // stores whether a menu is being diplayed

	activeMenus activeMenu; // stores which menu is being displayed
	activeMenus previousActiveMenu; // stores which menu was last displayed
};

#endif // GUI_H_INCLUDED
