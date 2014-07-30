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

	bool getMenuActive(); // retrieves the value of menuActive
	void setMenuActive(bool active); // sets the value of menuActive

	activeMenus getActiveMenu(); // retrieves the value of activeMenu
	void setActiveMenu(activeMenus menu); // sets the value of activeMenu

    bool initMyGUI();	// Initializes MyGUI
    bool createMainMenuButtons(); // creates a MyGUI button
    bool createNetworkSetupGUI();	// creates GUI for network setup screen.
    void menuReceiveKeyPress(std::string keyPressed); // processes key input
	void processMainMenuKeyPress(std::string keyPressed); // processes main menu key input
    void processNetworkMenuKeyPress(std::string keyPressed); // processes network menu key input
    void processNetworkClientMenuKeyPress(std::string keyPressed); // process network client menu key input
    void processOptionsMenuKeyPress(std::string keyPressed); // processes options menu key input

	void startSinglePlayerGame(); // starts single player game
	void startMultiPlayerGame(); // starts multiplayer game
    void optionsMenu(); // displays options menu
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

    void hideMainMenuWidgets();			// hides all widgets tied to the Main Menu
    void showMainMenuWidgets();         // shows all widgets tied to the Main Menu

    void hideNetworkSetupWidgets();		// hides all widgets tied to the Network Setup Menu
    void showNetworkSetupWidgets();     // shows all widgets tied to the Network Setup Menu

    void hideNetworkClientSetupWidgets();     // hides all widgets tied to the Network Setup Menu
    void showNetworkClientSetupWidgets();     // shows all widgets tied to the Network Setup Menu

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

    // text widgets
    MyGUI::EditBox *ipAddressBox;

	// booleans
    bool menuActive; // stores whether a menu is being diplayed

	activeMenus activeMenu; // stores which menu is being displayed
};

#endif // GUI_H_INCLUDED
