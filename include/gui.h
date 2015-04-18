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

    ~GUISystem();

    static GUISystem *Instance();

    bool getMainMenuCreated();   // retrieves the value of mainMenuCreated
    void setMainMenuCreated(bool created); // sets the value of mainMenuCreated

	bool getBackButtonsCreated(); // retrieves the value of backButtonsCreated
	void setBackButtonsCreated(bool created); // sets the value of backButtonsCreated

    bool getNetworkSetupMenuCreated();  // retrieves the value of networkSetupMenuCreated
    void setNetworkSetupMenuCreated(bool created);  // sets the value of networkSetupMenuCreated

	bool getOptionsMenuCreated();  // retrieves the value of optionsMenuCreated
    void setOptionsMenuCreated(bool created);  // sets the value of optionsMenuCreated

	bool getDisplaySetupMenuCreated();  // retrieves the value of displaySettingsMenuCreated
    void setDisplaySetupMenuCreated(bool created);  // sets the value of displaySettingsMenuCreated

	bool getInputSetupMenuCreated();  // retrieves the value of inputSettingsMenuCreated
    void setInputSetupMenuCreated(bool created);  // sets the value of inputSettingsMenuCreated

	bool getAuduoSetupMenuCreated();  // retrieves the value of audioSettingsMenuCreated
    void setAudioSetupMenuCreated(bool created);  // sets the value of audioSettingsMenuCreated

	bool getGameSetupMenuCreated();  // retrieves the value of gameSetupMenuCreated
    void setGameSetupMenuCreated(bool created);  // sets the value of gameSetupMenuCreated

    bool getPlayerStartSelectionMenuCreated();  // retrieves the value of playerStartSelectionMenuCreated
    void setPlayerStartSelectionMenuCreated(bool created);  // sets the value of playerStartSelectionMenuCreated

	bool getCourtSelectionMenuCreated();  // retrieves the value of courtSelectionMenuCreated
    void setCourtSelectionMenuCreated(bool created);  // sets the value of courtSelectionMenuCreated
	
    bool getCourtSelectionDataLoaded();  // retrieves the value of courtSelectionEntriesLoaded
    void setCourtSelectionDataLoaded(bool loaded);  // sets the value of courtSelectionEntriesLoaded
	
	bool getMenuActive(); // retrieves the value of menuActive
	void setMenuActive(bool active); // sets the value of menuActive

	activeMenus getActiveMenu(); // retrieves the value of activeMenu
	void setActiveMenu(activeMenus menu); // sets the value of activeMenu

	activeMenus getPreviousActiveMenu(); // retrieves the value of previousActiveMenu
	void setPreviousActiveMenu(activeMenus menu); // sets the value of previousActiveMenu

    bool initMyGUI();	// Initializes MyGUI
    bool createMainMenuGUI(); // creates GUI gor main menu screen.
    bool createNetworkSetupGUI();	// creates GUI for network setup screen.
    bool createNetworkServerSetupGUI();  // creates GUI for network server setup screen.
    bool createOptionsMenuGUI();	// creates GUI for options menu screen.
    bool createDisplaySetupGUI();	// creates GUI for display settings screen.
    bool createInputSetupGUI();	// creates GUI for input settings screen.
	bool createAudioSetupGUI();	// creates GUI for audo settings screen.
    bool createGameSetupMenuGUI();	// creates GUI for game setup menu screen.
    bool createPlayerStartSelectionMenuGUI();  // creates GUI for player start selection menu screen.
    bool createCourtSelectionMenuGUI();  // creates GUI for court selection menu screen.
	bool createBackButtons(); // creates the back buttons for the menus

    void menuReceiveKeyPress(std::string keyPressed); // processes key input
	void processMainMenuKeyPress(std::string keyPressed); // processes main menu key input
    void processNetworkMenuKeyPress(std::string keyPressed); // processes network menu key input
    void processNetworkServerMenuKeyPress(std::string keyPressed); // process network server menu key input
    void processNetworkClientMenuKeyPress(std::string keyPressed); // process network client menu key input
    void processOptionsMenuKeyPress(std::string keyPressed); // processes options menu key input
    void processDisplayMenuKeyPress(std::string keyPressed); // processes display settings menu key input
    void processInputMenuKeyPress(std::string keyPressed); // processes input settings menu key input
    void processAudioMenuKeyPress(std::string keyPressed); // processes audio settings menu key input
    void processGameSetupMenuKeyPress(std::string keyPressed); // processes game setup menu key input
    void processPlayerStartSelectionMenuKeyPress(std::string keyPressed);   // process player start selection menu key input
    void processCourtSelectionMenuKeyPress(std::string keyPressed);   // process court selection menu key input
	
	void startSinglePlayerGame(); // starts single player game
	void startMultiPlayerGame(); // starts multiplayer game
    void optionsMenu(); // displays options menu
    void displayMenu();  // displays display menu
    void inputMenu();  // displays the input menu
    void audioMenu();  // displays the audio menu
    void gameSetupMenu(); // displays game setup menu
    void playerStartSelectionMenu(); // displays player start selection menu
	void courtSelectionMenu(); // displays court selection menu
	void networkClientSetupMenu(); // sets up the network client connection
    void networkServerSetupMenu();  // sets up the networkServer instance
    
    bool addCourtSelectionMenuData(); // adds data to Court Selection Menu widgets

    void addPlayerStartSelectionMenuData(); // adds data to Player Start Selection Menu widgets

    void networkServer();  // sets up  game as a network server
    void networkClient();  // sets up game as a network client

    void courtSelected();  // processes court selection
    void backMainMenuSelected();  // processes back to main menu selection
    void backNetworkSetupMenuSelected();  // returns back to network setup screen
    void backNetworkClientMenuSelected();  // returns back to the network client menu
    
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
    void hostGameButtonClicked(MyGUI::Widget *_sender); // handles hostGameButton click event
    void connectButtonClicked(MyGUI::Widget *_sender); // handles connectButton click event
    void backMainMenuButtonClicked(MyGUI::Widget *_sender); // handles backMainMenuButton click event
    void backNetworkSetupButtonClicked(MyGUI::Widget *_sender); // handles backNetworkSetupButton click event
    void displayButtonClicked(MyGUI::Widget *_sender); // handles didplayButton click event
    void inputButtonClicked(MyGUI::Widget *_sender); // handles inputButton click event
    void audioButtonClicked(MyGUI::Widget *_sender); // handles audioButton click event
    void changeResolutionButtonClicked(MyGUI::Widget *_sender); // handles changeResolutionButton click event
    void changeInputTypeButtonClicked(MyGUI::Widget *_sender); // handles changeInputTypeButton click event
    void enableAudioButtonClicked(MyGUI::Widget *_sender); // handles eneableAudioButton click event
    void disableAudioButtonClicked(MyGUI::Widget *_sender); // handles eneableAudioButton click event
    void team0SelectButtonClicked(MyGUI::Widget *_sender); // handles team0SelectButton click event
    void team1SelectButtonClicked(MyGUI::Widget *_sender); // handles team1SelectButton click event
    void teamsSelectedButtonClicked(MyGUI::Widget *_sender); // handles teamsSelectedButton click event
    void backNetworkClientButtonClicked(MyGUI::Widget *_sender); // handles backNetworkClientButton click event
    void backOptionsMenuButtonClicked(MyGUI::Widget *_sender); // handles backOptionsMenuButton click event
    void backPlayerStartSelectionMenuButtonClicked(MyGUI::Widget *_sender); // handles backPlayerStartSelectionMenuButton click event
    void courtSelectButtonClicked(MyGUI::Widget *_sender); // handles courtSelectButton click event
 

    void hideMainMenuWidgets();	// hides all widgets tied to the Main Menu
    void showMainMenuWidgets(); // shows all widgets tied to the Main Menu

    void hideNetworkSetupWidgets();	// hides all widgets tied to the Network Setup Menu
    void showNetworkSetupWidgets(); // shows all widgets tied to the Network Setup Menu

    void hideNetworkServerSetupWidgets();  // hides all widgets tied to the Network Server Setup Menu
    void showNetworkServerSetupWidgets();  // shows all widgets tied to the Network Server Setup Menu

    void hideNetworkClientSetupWidgets();  // hides all widgets tied to the Network Client Setup Menu
    void showNetworkClientSetupWidgets();  // shows all widgets tied to the Network Client Setup Menu

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

    void hidePlayerStartSelectionMenuWidgets(); // hides all widgets tied to the Player Start Selection Menu
    void showPlayerStartSelectionMenuWidgets(); // shows all widgets tied to the Player Start Selection Menu

	void hideCourtSelectionMenuWidgets(); // hides all widgets tied to the Court Selection Menu
	void showCourtSelectionMenuWidgets(); // show all widgets tied to the Court Selection Menu
	
    void hideActiveMenuWidgets();  // hides active menus widgets
    void showActiveMenuWidgets();  // shows active menus widgets
    
    
    
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
    MyGUI::Button *hostGameButton;
    MyGUI::Button *connectButton;
    MyGUI::Button *backMainMenuButton;
	MyGUI::Button *backNetworkSetupButton;
    MyGUI::Button *displayButton;
	MyGUI::Button *inputButton;
	MyGUI::Button *audioButton;
	MyGUI::Button *team0SelectButton;
	MyGUI::Button *team1SelectButton;
	MyGUI::Button *startGameButton;
	MyGUI::Button *backNetworkClientButton;
	MyGUI::Button *changeResolutionButton;
	MyGUI::Button *changeInputTypeButton;
	MyGUI::Button *enableAudioButton;
	MyGUI::Button *disableAudioButton;
    MyGUI::Button *backOptionsMenuButton;
    MyGUI::Button *backGameSetupMenuButton;
    MyGUI::Button *teamsSelectedButton;
    // Player Start Selection Menu
    MyGUI::Button *team0StartingLineupSetButton;
    MyGUI::Button *team1StartingLineupSetButton;
    MyGUI::Button *startingLineupsSetButton;

    // editbox widgets
    MyGUI::EditBox *ipAddressBox;

	// listbox widgets
	MyGUI::ListBox *team0SelectBox;
	MyGUI::ListBox *team1SelectBox;

    // Network Server Setup Widgets
    MyGUI::ListBox *networkUsersBox;  // allows you to select the number of network players
    MyGUI::ListBox *team0Player1SelectBox;
    MyGUI::ListBox *team0Player2SelectBox;
    MyGUI::ListBox *team0Player3SelectBox;
    MyGUI::ListBox *team0Player4SelectBox;
    MyGUI::ListBox *team0Player5SelectBox;
    MyGUI::ListBox *team1Player1SelectBox;
    MyGUI::ListBox *team1Player2SelectBox;
    MyGUI::ListBox *team1Player3SelectBox;
    MyGUI::ListBox *team1Player4SelectBox;
    MyGUI::ListBox *team1Player5SelectBox;
    
    
    // Player Selection Menu widgets
    MyGUI::ListBox *team0PGSelectBox;
    MyGUI::ListBox *team0SGSelectBox;
    MyGUI::ListBox *team0SFSelectBox;
    MyGUI::ListBox *team0PFSelectBox;
    MyGUI::ListBox *team0CSelectBox;

    MyGUI::ListBox *team1PGSelectBox;
    MyGUI::ListBox *team1SGSelectBox;
    MyGUI::ListBox *team1SFSelectBox;
    MyGUI::ListBox *team1PFSelectBox;
    MyGUI::ListBox *team1CSelectBox;

    MyGUI::TextBox *team0PGRating;
    MyGUI::TextBox *team0SGRating;
    MyGUI::TextBox *team0SFRating;
    MyGUI::TextBox *team0PFRating;
    MyGUI::TextBox *team0CRating;

    MyGUI::TextBox *team1PGRating;
    MyGUI::TextBox *team1SGRating;
    MyGUI::TextBox *team1SFRating;
    MyGUI::TextBox *team1PFRating;
    MyGUI::TextBox *team1CRating;

    MyGUI::ImageBox *team0Logo;
    MyGUI::ImageBox *team1Logo;
	
	// Court selection menu widgets
	MyGUI::Button *backPlayerStartSelectionMenuButton;
	MyGUI::Button *courtSelectButton;
	MyGUI::ListBox *courtSelectBox;  
	MyGUI::ImageBox *courtPreviewImgBox;
    MyGUI::TextBox *courtNameTxtBox;

	// booleans
    bool mainMenuCreated;   // determines whether the main menu gui has been created
    bool networkSetupMenuCreated;   // determines whether the network setup gui has been created
    bool networkServerSetupMenuCreated;   // determines whether the network server setup gui has been created
    bool networkClientSetupMenuCreated;   // determines whether the network client setup gui has been created
    bool optionsMenuCreated;   // determines whether the options menu gui has been created
    bool displaySetupMenuCreated;   // determines whether the display settings menu gui has been created
    bool inputSetupMenuCreated;   // determines whether the input settings menu gui has been created
    bool audioSetupMenuCreated;   // determines whether the audio settings menu gui has been created
    bool gameSetupMenuCreated;  // determines whether the game setup menu gui has been created
    bool playerStartSelectionMenuCreated; // determines whether the player start selection menu gui has been created
	bool courtSelectionMenuCreated;  // deteemines whether the court selection menu has been created;
	bool backButtonsCreated; // determines the back buttons have been created
	bool menuActive; // stores whether a menu is being diplayed
    bool gameSetupMenuAwaySelected; // determines whether the away team listbox is selected;
	bool gameSetupMenuHomeSelected; // determines whether the home team listbox is selected;
    bool courtSelectionDataLoaded;  // determines whether court names have been added to the select box
    
	activeMenus activeMenu; // stores which menu is being displayed
	activeMenus previousActiveMenu; // stores which menu was last displayed

    std::vector< std::vector<std::string> > playerNames;
    std::vector< std::vector<std::string> > playerPositions;
    std::vector< std::vector<int> > playerIDs;  // stores player IDs for each team
    std::vector< std::vector<int> > team0IDs;
    std::vector< std::vector<int> > team1IDs;
    std::vector< std::vector<int> > teamStarterID; // stores the selected starters for each team
};

#endif // GUI_H_INCLUDED
