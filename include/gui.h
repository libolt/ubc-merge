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

#ifndef _GUI_H_
#define _GUI_H_

//mem probs without this next one
#ifdef __APPLE__
//include <Ogre/OgreNoMemoryMacros.h>
#else
//#include <OgreNoMemoryMacros.h>
#endif
/*#include <CEGUI/CEGUIImageset.h>
#include <CEGUI/CEGUISystem.h>
#include <CEGUI/CEGUILogger.h>
#include <CEGUI/CEGUISchemeManager.h>
#include <CEGUI/CEGUIWindowManager.h>
#include <CEGUI/CEGUIWindow.h>
#include <CEGUI/elements/CEGUIPushButton.h>
#include "OgreCEGUIRenderer.h"
#include "OgreCEGUIResourceProvider.h"
*/

//#include "QuickGUI.h"

#include "MyGUI.h"
#include "MyGUI_OgrePlatform.h"
//#include "MyGUI_OgreRenderManager.h"

#include "input.h"
#include "renderengine.h"


//CEGUI::MouseButton convertOgreButtonToCegui(int buttonID);	// converts OIS button press to CEGUI buton press


class GUISystem //: public renderEngine //, inputSystem
{
public:

    virtual ~GUISystem();

    static GUISystem *Instance();

    // Move to private when code is refactored
//    CEGUI::OgreCEGUIRenderer *mGUIRenderer;
//    CEGUI::System *mGUISystem;
//    CEGUI::Window *mEditorGuiSheet;

        // gets and sets mGUIRenderer
//    CEGUI::OgreCEGUIRenderer *getMGUIRenderer();
//    void setMGUIRenderer(CEGUI::OgreCEGUIRenderer *renderer);

    // gets and sets mGUISystem
//    CEGUI::System *getMGUISystem();
//    void setMGUISystem(CEGUI::System *system);

    // gets and sets mEditorGuiSheet
//    CEGUI::Window *getMEditorGuiSheet();
//    void setMEditorGuiSheet(CEGUI::Window *sheet);

    virtual bool initMyGUI();	// Initializes MyGUI
    virtual bool createButton(); // creates a MyGUI button


    // Old QuickGUI Code
    virtual bool setupGUI();	// sets up the QuickGUI Window
    virtual bool update();   // updates the GUI
    virtual void updateTime(float time);
/*    void evtHndlr_start(const QuickGUI::EventArgs& args);
    void evtHndlr_options(const QuickGUI::EventArgs& args);
    void evtHndlr_quit(const QuickGUI::EventArgs& args);
    bool mouseMoved( const OIS::MouseEvent &arg );
    bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
*/
//    virtual bool loadMainMenu();	// loads the main menu GUI and sets up event handlers

//    virtual bool loadOptionsMenu();	// loads the options menu GUI and sets up event handlers

//    virtual void setupMainMenuEventHandlers();  // sets up Main Menu GUI event handlers

//    virtual void setupOptionsMenuEventHandlers();	// sets up the Options Menu GUI event handlers

/*
    bool handleStart(const CEGUI::EventArgs& e); // handles start button event

    bool handleOptions(const CEGUI::EventArgs& e);   // handles options event

    bool handleQuit(const CEGUI::EventArgs& e);  // handles quit event

    bool handleGamePlay(const CEGUI::EventArgs& e); // handles Game Play button event

    bool handleAudioVideo(const CEGUI::EventArgs& e);   // handles audio video event

    bool handleMainMenu(const CEGUI::EventArgs& e);  // handles main menu event
*/

//    virtual bool processInput();	// processes all input

//    virtual bool processUnbufferedKeyInput();	//  processes unbuffered key input
//    virtual bool processUnbufferedMouseInput();	// processes unbuffered mouse input

protected:

    GUISystem();
    GUISystem(const GUISystem&);
    GUISystem& operator= (const GUISystem&);

    virtual void createScene();
    virtual bool frameStarted();
    virtual bool frameEnded();

/*    QuickGUI::GUIManager *mGUIManager;
    QuickGUI::Sheet *mSheet;

    QuickGUI::Button *startButton;
    QuickGUI::Button *optionsButton;
    QuickGUI::Button *quitButton;
*/
private:

    static GUISystem *pInstance;
    MyGUI::Gui *mGUI;
    MyGUI::OgrePlatform *mPlatform;
    MyGUI::ButtonPtr button;

};

#endif // GUI_H_INCLUDED
