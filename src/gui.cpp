#include "ubcapp.h"
#include "config.h"
//#include "MyGUI.h"
//#include "MyGUI_OgrePlatform.h"

/*
CEGUI::MouseButton convertOgreButtonToCegui(int buttonID)
{
    using namespace OIS;

    switch (buttonID)
    {
        case OIS::MB_Left:
            return CEGUI::LeftButton;
        case OIS::MB_Right:
            return CEGUI::RightButton;
        case OIS::MB_Middle:
            return CEGUI::MiddleButton;
// Not sure what to do with this one...
//   case MouseEvent::BUTTON3_MASK:
//       return CEGUI::X1Button;
        default:
            return CEGUI::LeftButton;
    }
}
*/

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
    setupGUI();
//    mGUIRenderer = 0;
//    mGUISystem = 0;
//    mEditorGuiSheet =
//    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
//    QuickGUI::registerScriptParser();

}

GUISystem::~GUISystem()
{

}

void GUISystem::createScene()
{
//    setupGUI();
 //   loadMainMenu();
 //   setupMainMenuEventHandlers();
}

// sets up the CEGUI Window
bool GUISystem::setupGUI()
{
    UBC *ubc = UBC::Instance();
    renderSystems *render = renderSystems::Instance();


/*    using QuickGUI::Rect;
    using QuickGUI::Point;
    using QuickGUI::Size;

    new QuickGUI::Root;

    String resourcePath = UBC_DATADIR;
    QuickGUI::SkinSetManager::getSingleton().loadSkin("qgui", QuickGUI::SkinSet::IMAGE_TYPE_PNG, render->getMResourceGroup());
//    mGUIManager = new QuickGUI::GUIManager(render->getMCamera()->getViewport());
//    mGUIManager = QuickGUI::Root::getSingletonPtr().createGUIManager(render->getMCamera()->getViewport());
      mGUIManager = QuickGUI::Root::getSingleton().createGUIManager(render->getMCamera()->getViewport(),"qgui");
    mGUIManager->setSceneManager(render->getMSceneMgr());

    mSheet = mGUIManager->getDefaultSheet();
/*		QuickGUI::Image* logoImage = mSheet->createImage();
		//logoImage->setDimensions(Rect(16,42,240,180));
		logoImage->setDimensions(Rect(-240,-180,1,1));

		// appears and slide in
		const QuickGUI::Point screenLeftBottom (16, 42);
		const QuickGUI::Point screenLeftOffBottom (-240, -180);
		mGUIManager->addEffect(new QuickGUI::MoveEffect(logoImage, 3, screenLeftOffBottom, screenLeftBottom, 1));
		const QuickGUI::Size screenSize (240, 180);
		const QuickGUI::Size noSize (1, 1);
		mGUIManager->addEffect(new QuickGUI::SizeEffect(logoImage, 3, noSize, screenSize, 1));

		mGUIManager->addEffect(new QuickGUI::AlphaEffect(logoImage, 3, 0, 1, 3));

    QuickGUI::Label* logoLabel = mSheet->createLabel();
    logoLabel->setPosition(Point(60,240));

    logoLabel->setText("C");
*/

/*
    startButton = mSheet->createButton();
    startButton->setDimensions(Rect(300,150,250,42));
    startButton->setText("Start Game");
    startButton->addEventHandler(QuickGUI::Widget::EVENT_MOUSE_BUTTON_DOWN,&GUISystem::evtHndlr_start,this);

    optionsButton = mSheet->createButton();
    optionsButton->setDimensions(Rect(300,200,250,42));
    optionsButton->setText("Options");
    optionsButton->addEventHandler(QuickGUI::Widget::EVENT_MOUSE_BUTTON_DOWN,&GUISystem::evtHndlr_options,this);

    quitButton = mSheet->createButton();
    quitButton->setDimensions(Rect(300,250,250,42));
    quitButton->setText("Quit");
    quitButton->addEventHandler(QuickGUI::Widget::EVENT_MOUSE_BUTTON_DOWN,&GUISystem::evtHndlr_quit,this);
*/
//    mSheet->setFont("acmesa.10",true);
//    mGUIManager->setActiveSheet(mSheet);

	return true;
}

bool GUISystem::update()
{
/*    inputSystem *input = inputSystem::Instance();
    const OIS::MouseState &ms = input->getMMouse()->getMouseState();
    OIS::MouseButtonID id;
    OIS::Mouse *mouse = input->getMMouse();

    mGUIManager->injectMouseMove( ms.X.rel, ms.Y.rel );


    if ( input->getMMouse()->getMouseState().buttonDown( OIS::MB_Left))
    {

        mGUIManager->injectMouseButtonDown(static_cast<QuickGUI::MouseButtonID>(input->getMMouse()->getID()));
    }
*/
    return true;
}

void GUISystem::updateTime(float time)
{
//    mGUIManager->injectTime(time);
}

/*
bool GUISystem::mouseMoved( const OIS::MouseEvent &arg )
{
    mGUIManager->injectMouseMove( arg.state.X.rel, arg.state.Y.rel );
    return true;
}

bool GUISystem::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
	mGUIManager->injectMouseButtonDown(static_cast<QuickGUI::MouseButtonID>(id));
	return true;
}
void GUISystem::evtHndlr_start(const QuickGUI::EventArgs& args)
{
    UBC *ubc = UBC::Instance();
    startButton->hide();
    optionsButton->hide();
    quitButton->hide();
    ubc->startGame();
}

void GUISystem::evtHndlr_options(const QuickGUI::EventArgs& args)
{
    UBC *ubc = UBC::Instance();

}

void GUISystem::evtHndlr_quit(const QuickGUI::EventArgs& args)
{
    UBC *ubc = UBC::Instance();

    ubc->quit();
}
*/
/*
// Handles a start event
bool handleStart(const CEGUI::EventArgs& e)
{
    UBC *ubc = UBC::Instance();
    GUISystem *gui = GUISystem::Instance();
    teams *team = teams::Instance();
    players *player = players::Instance();
    basketballs *basketball = basketballs::Instance();

    // checks if game has been started
    if (!ubc->getGameStarted())
    {
        if(gui->mEditorGuiSheet)
        {
            // destroys GUI window
            CEGUI::WindowManager::getSingleton().destroyWindow(gui->mEditorGuiSheet);
        }
        ubc->setMenuActive(false);	// sets that the menu is no longer active
        ubc->startGame();
        ubc->setGameStarted(true);	// sets that the game has been started
    }
    return true;
}

// Handles an optoins event
bool handleOptions(const CEGUI::EventArgs& e)
{
    UBC *ubc = UBC::Instance();
    GUISystem *gui = GUISystem::Instance();

//   static_cast<GuiFrameListener*>(OgreApplication)->requestShutdown();
    cout << "Options:" << endl;

    if(gui->mEditorGuiSheet)
    {
        // destroys GUI window
        CEGUI::WindowManager::getSingleton().destroyWindow(gui->mEditorGuiSheet);
    }

    // loads the Options Menu GUI
    gui->loadOptionsMenu();

    // sets up the Options Menu button event handlers
    gui->setupOptionsMenuEventHandlers();

    return true;
}

// Handles a quit event
bool handleQuit(const CEGUI::EventArgs& e)
{
    UBC *ubc = UBC::Instance();
//   static_cast<GuiFrameListener*>(OgreApplication)->requestShutdown();
    cout << "BLAM!" << endl;

    ubc->quit();
    return true;
}

// Handles a GamePlay event
bool handleGamePlay(const CEGUI::EventArgs& e)
{
    UBC *ubc = UBC::Instance();
//   static_cast<GuiFrameListener*>(OgreApplication)->requestShutdown();
    cout << "GamePlay" << endl;

    return true;
}

// Handles an AudioVideo event
bool handleAudioVideo(const CEGUI::EventArgs& e)
{
    UBC *ubc = UBC::Instance();
//   static_cast<GuiFrameListener*>(OgreApplication)->requestShutdown();
    cout << "AudioVideo" << endl;

    return true;
}

// Handles a MainMenu event
bool handleMainMenu(const CEGUI::EventArgs& e)
{
    UBC *ubc = UBC::Instance();
    GUISystem *gui = GUISystem::Instance();

//   static_cast<GuiFrameListener*>(OgreApplication)->requestShutdown();
    cout << "Options:" << endl;

    if(gui->mEditorGuiSheet)
    {
        // destroys GUI window
        CEGUI::WindowManager::getSingleton().destroyWindow(gui->mEditorGuiSheet);
    }

    gui->loadMainMenu();
    gui->setupMainMenuEventHandlers();
    return true;
}

// sets up the Main Menu GUI event handlers
void GUISystem::setupMainMenuEventHandlers(void)
{
    using namespace CEGUI;
    CEGUI::WindowManager& wmgr = CEGUI::WindowManager::getSingleton();

    // sets up Start button Handler
    wmgr.getWindow((CEGUI::utf8*)"Start")->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&handleStart));

    // sets up Start button Handler
    wmgr.getWindow((CEGUI::utf8*)"Options")->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&handleOptions));

    // sets up Quit button handler
    wmgr.getWindow((CEGUI::utf8*)"Quit")->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&handleQuit));

}

// sets up the Options Menu GUI event handlers
void GUISystem::setupOptionsMenuEventHandlers(void)
{
    using namespace CEGUI;
    CEGUI::WindowManager& wmgr = CEGUI::WindowManager::getSingleton();

    // sets up Start button Handler
    wmgr.getWindow((CEGUI::utf8*)"GamePlay")->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&handleGamePlay));

    // sets up Start button Handler
    wmgr.getWindow((CEGUI::utf8*)"AudioVideo")->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&handleAudioVideo));

    // sets up Quit button handler
    wmgr.getWindow((CEGUI::utf8*)"MainMenu")->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&handleMainMenu));

}

// loads the Main Menu GUI and sets up the button event handlers
bool GUISystem::loadMainMenu()
{
    // loads GUI XML file
    mEditorGuiSheet = CEGUI::WindowManager::getSingleton().loadWindowLayout((CEGUI::utf8*)"UBC-GUI.xml");
    mGUISystem->setGUISheet(mEditorGuiSheet);

    // creates the Start Button
    CEGUI::PushButton* startButton = (CEGUI::PushButton*)CEGUI::WindowManager::getSingleton().getWindow((CEGUI::utf8*)"Start");

    // creates the Options Button
    CEGUI::PushButton* optionsButton = (CEGUI::PushButton*)CEGUI::WindowManager::getSingleton().getWindow((CEGUI::utf8*)"Options");

    // creates the Quit Button
    CEGUI::PushButton* quitButton = (CEGUI::PushButton*)CEGUI::WindowManager::getSingleton().getWindow((CEGUI::utf8*)"Quit");

    return true;
}

// loads the Options Menu GUI and sets up the button event handlers
bool GUISystem::loadOptionsMenu()
{
    // loads GUI XML file
    mEditorGuiSheet = CEGUI::WindowManager::getSingleton().loadWindowLayout((CEGUI::utf8*)"UBC-OPTIONS.xml");
    mGUISystem->setGUISheet(mEditorGuiSheet);

    // creates the GamePlay Button
    CEGUI::PushButton* gamePlayButton = (CEGUI::PushButton*)CEGUI::WindowManager::getSingleton().getWindow((CEGUI::utf8*)"GamePlay");

    // creates the AudioVideo Button
    CEGUI::PushButton* audioVideoButton = (CEGUI::PushButton*)CEGUI::WindowManager::getSingleton().getWindow((CEGUI::utf8*)"AudioVideo");

    // creates the MainMenu Button
    CEGUI::PushButton* mainMenuButton = (CEGUI::PushButton*)CEGUI::WindowManager::getSingleton().getWindow((CEGUI::utf8*)"MainMenu");

    return true;
}
*/

bool GUISystem::frameStarted()
{
    return true;
//    return OgreApplication::frameStarted(evt);
}

bool GUISystem::frameEnded()
{
//	mWindow->update();
//	mRoot->renderOneFrame();

    return true;
}
/*
bool GUISystem::processInput()	// processes all input
{
    // processes keyboard input
    if (processUnbufferedKeyInput() == false)
    {
        return false;
    }
    // processes mouse input
    if (processUnbufferedMouseInput() == false)
    {
        return false;
    }
    return true;
}

bool GUISystem::processUnbufferedKeyInput()
{
    return true;
}
bool GUISystem::processUnbufferedMouseInput()
{
    using namespace OIS;

    inputSystem *input = inputSystem::Instance();
    const MouseState &ms = input->getMMouse()->getMouseState();


//	if( ms.buttonDown( MB_Right ) )
//	{
//		mTranslateVector.x += ms.X.rel * 0.13;
//		mTranslateVector.y -= ms.Y.rel * 0.13;
//	}
//	else
//	{
//		mRotX = Degree(-ms.X.rel * 0.13);
//		mRotY = Degree(-ms.Y.rel * 0.13);
//	}



    CEGUI::System::getSingleton().injectMouseMove(ms.X.rel,ms.Y.rel);

    if ( ms.buttonDown( MB_Left) )
    {
        CEGUI::System::getSingleton().injectMouseButtonDown(convertOgreButtonToCegui(input->getMMouse()->getID()));
    }

    else
    {
        CEGUI::System::getSingleton().injectMouseButtonUp(convertOgreButtonToCegui(input->getMMouse()->getID()));
    }

    return true;
}
*/
