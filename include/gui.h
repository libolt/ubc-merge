// GUI class definition

#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

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

#include "input.h"
#include "renderengine.h"


//CEGUI::MouseButton convertOgreButtonToCegui(int buttonID);	// converts OIS button press to CEGUI buton press


class GUISystem //: public renderSystems //, inputSystem
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
};

#endif // GUI_H_INCLUDED
