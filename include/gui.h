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

#include "input.h"
#include "renderengine.h"


class GUISystem //: public renderEngine //, inputSystem
{
public:

    virtual ~GUISystem();

    static GUISystem *Instance();


    virtual bool initMyGUI();	// Initializes MyGUI
    virtual bool createMainMenuButtons(); // creates a MyGUI button
    virtual bool createNetworkSetupGUI();	// creates GUI for network setup screen.

protected:

    GUISystem();
    GUISystem(const GUISystem&);
    GUISystem& operator= (const GUISystem&);

    // MyGUI functions
    virtual void startSingleGameButtonClicked(MyGUI::Widget *_sender);
    virtual void startMultiGameButtonClicked(MyGUI::Widget *_sender);
    virtual void optionsButtonClicked(MyGUI::Widget *_sender);
    virtual void exitButtonClicked(MyGUI::Widget *_sender);
    virtual void serverButtonClicked(MyGUI::Widget *_sender);
    virtual void clientButtonClicked(MyGUI::Widget *_sender);

    virtual void hideMainMenuWidgets();			// hides all widgets tied to the Main Menu
    virtual void hideNetworkSetupWidgets();		// hides all widgets tied to the Network Setup Menu

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

    // text widgets
    MyGUI::EditBox *ipAddressBox;
};

#endif // GUI_H_INCLUDED
