// Input 

#include "games.h"
#include "gamestate.h"
#include "ubcapp.h"

using namespace OIS;

inputSystem* inputSystem::pInstance = 0;

inputSystem* inputSystem::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new inputSystem; // create sole instance
    }
    return pInstance; // address of sole instance
}

// inputSystem constructor
inputSystem::inputSystem()
{
    setup();
}

inputSystem::~inputSystem()
{
}

OIS::InputManager *inputSystem::getIM() // retrieves the im input manager
{
    return (im);
}

void inputSystem::setIM(OIS::InputManager *IM)  // sets the im input manager
{
    im = IM;
}

OIS::Mouse *inputSystem::getMMouse()    // retrieves mMouse
{
    return (mMouse);
}
void inputSystem::setMMouse(OIS::Mouse *mouse)  // sets mMouse
{
    mMouse = mouse;
}

OIS::Keyboard *inputSystem::getMKeyboard()    // retrieves mKeyboard
{
    return (mKeyboard);
}
void inputSystem::setMKeyboard(OIS::Keyboard *keyboard)  // sets mKeyboard
{
    mKeyboard = keyboard;
}

OIS::JoyStick *inputSystem::getMJoy()    // retrieves mJoy
{
    return (mJoy);
}
void inputSystem::setMJoy(OIS::JoyStick *joystick)  // sets mJoy
{
    mJoy = joystick;
}

bool inputSystem::getBufferedKeys()    // retrieves bufferedKeys
{
    return (bufferedKeys);
}
void inputSystem::setBufferedKeys(bool keys)  // sets bufferedKeys
{
    bufferedKeys = keys;
}

bool inputSystem::getBufferedMouse()    // retrieves bufferedMouse
{
    return (bufferedMouse);
}
void inputSystem::setBufferedMouse(bool mouse)  // sets bufferedMouse
{
    bufferedMouse = mouse;
}

bool inputSystem::getBufferedJoy()    // retrieves bufferedJoy
{
    return (bufferedJoy);
}
void inputSystem::setBufferedJoy(bool joy)  // sets bufferedJoy
{
    bufferedJoy = joy;
}

OIS::MouseEvent *inputSystem::getMouseEvent()   // retrieves mouseEvent
{
        return (mouseEvent);
}
void inputSystem::seMouseEvent(OIS::MouseEvent *event)  // sets mouseEvent
{
    mouseEvent = event;

}
OIS::MouseButtonID inputSystem::getMouseButtonID()   // retrieves mouseEvent
{
    return (mouseButtonID);
}
void inputSystem::seMouseButtonID(OIS::MouseButtonID buttonID)  // sets mouseEvent
{
    mouseButtonID = buttonID;
}

bool inputSystem::setup()   // sets up and initializes the OIS Input System
{
    UBC *ubc = UBC::Instance();
    renderSystems * render = renderSystems::Instance();
//              mDebugOverlay = OverlayManager::getSingleton().getByName("Core/DebugOverlay");

    LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
    ParamList pl;
    size_t windowHnd = 0;
    std::ostringstream windowHndStr;
    render->getMWindow()->getCustomAttribute("WINDOW", &windowHnd);
    windowHndStr << windowHnd;
    pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

    im = InputManager::createInputSystem( pl );

    //Create all devices (We only catch joystick exceptions here, as, most people have Key/Mouse)
    mKeyboard = static_cast<Keyboard*>(im->createInputObject( OISKeyboard, bufferedKeys ));
    mMouse = static_cast<Mouse*>(im->createInputObject( OISMouse, bufferedMouse ));
    try
    {
        mJoy = static_cast<JoyStick*>(im->createInputObject( OISJoyStick, bufferedJoy ));
    }
    catch(...)
    {
        mJoy = 0;
    }
    //Set initial mouse clipping size
//    windowResized(ubc->getMWindow());
    //Register as a Window listener
//    WindowEventUtilities::addWindowEventListener(ubc->getMWindow(), this);

    return true;
}

bool inputSystem::destroy() // destroys the OIS Input System and related objects
{
    if(im)
    {
        im->destroyInputObject(mMouse);
        im->destroyInputObject(mKeyboard);
        im->destroyInputObject(mJoy);
        im->destroyInputSystem(im);
    }

    return true;
}

bool inputSystem::processInput()	// processes all input
{
    // processes keyboard input
    if (processUnbufferedKeyInput() == false)
    {
        return false;
    }
    // processes mouse input
/*    if (processUnbufferedMouseInput() == false)
    {
        return false;
    }
*/
    return true;
}

bool inputSystem::processUnbufferedKeyInput()
{
    using namespace OIS;
//    basketballs *basketball = basketballs::Instance();
    games *game = games::Instance();
    gameState *gameS = gameState::Instance();
    players *player = players::Instance();
    UBC *ubc = UBC::Instance();

    std::vector<basketballs> bballInstance = gameS->getBasketballInstance();
    int playerBall = bballInstance[0].getPlayer();
    std::vector<Ogre::Vector3> pos; // = new Ogre::Vector3[10];

    std::vector<int> playerDirection = player->getPlayerDirection(); // stores contents of playerDirection in local variable

    for (int i=0; i<10; i++)
    {
        pos.push_back(Ogre::Vector3(0.0f, 0.0f, 0.0f));
    }

//      pos[0] = 0.0f;
//      pos[1] = 0.0f;
//      pos[2] = 0.0f;

	mKeyboard->capture();

    if(mKeyboard->isKeyDown(KC_ESCAPE))
    {


        //Only close for window that created OIS (mWindow)
        //		InputManager* im = 0;//::getSingletonPtr();
 /*       if( im )
        {
            im->destroyInputObject( mMouse );
            im->destroyInputObject( mKeyboard );
            im->destroyInputObject( mJoy );
            im->destroyInputSystem(im);
        }
*/
        ubc->quitGame = true;
        return false;
    }

    if (playerBall >= 0)
    {
        if(mKeyboard->isKeyDown(KC_A))
        {
            // Move player left
            pos[playerBall] = Ogre::Vector3(-0.150f, 0.0f, 0.0f);
//            player->getNode(basketball->getPlayer())->translate(pos[playerBall]);
//            basketball->nodeChangePosition(pos[playerBall]);
            playerDirection[playerBall] = 3;
 //           player->setPlayerDirection(playerBall, 3);
        }

        if(mKeyboard->isKeyDown(KC_D))
        {
            // Move player RIGHT
            pos[playerBall] = Ogre::Vector3 (0.150f, 0.0f, 0.0f);
//            player->getNode(basketball->getPlayer())->translate(pos[playerBall]);
//            basketball->nodeChangePosition(pos[playerBall]);
            playerDirection[playerBall] = 4;
//            player->setPlayerDirection(playerBall, 4);
        }

        if(mKeyboard->isKeyDown(KC_W))
        {
        	// Move player left
	//     mTranslateVector.x = -mMoveScale;
            pos[playerBall] = Ogre::Vector3 (0.0f, 0.0f, -0.150f);
//			player->getNode(basketball->getPlayer())->translate(pos[playerBall]);
//			basketball->nodeChangePosition(pos[playerBall]);
            playerDirection[playerBall] = 1;
//            player->setPlayerDirection(playerBall, 1);
	}

        if(mKeyboard->isKeyDown(KC_S))
        {
			// Move player RIGHT
	//     mTranslateVector.x = mMoveScale;
            pos[playerBall] = Ogre::Vector3 (0.0f, 0.0f, 0.15f);
//	      player->getNode(basketball->getPlayer())->translate(pos[playerBall]);
//            basketball->nodeChangePosition(pos[playerBall]);
            playerDirection[playerBall] = 2;
//            player->setPlayerDirection(playerBall, 2);
        }
    }

    player->setPlayerDirection(playerDirection);    // copies playerDirection std::vector to that of the one in players class

    std::vector <playerState> pInstance = gameS->getPlayerInstance();

    for (int x = 0; x < pInstance.size(); ++x)
    {
        if (pos[x][0] != 0 || pos[x][1] != 0 || pos[x][2] != 0)
        {
            pInstance[x].setPosChange(pos[x]);
        }
    }
//    exit(0);
    gameS->setPlayerInstance(pInstance);
//    player->setPosChange(pos);

/*
    // Move camera forward by keypress.
    if(mKeyboard->isKeyDown(KC_UP))
    {
        mTranslateVector.z = -mMoveScale;
    }

    // Move camera backward by keypress.
    if(mKeyboard->isKeyDown(KC_DOWN))
    {
        mTranslateVector.z = mMoveScale;
    }

    if(mKeyboard->isKeyDown(KC_PGUP))
    {
        // Move camera up
        mTranslateVector.y = mMoveScale;
    }

    if(mKeyboard->isKeyDown(KC_PGDOWN))
    {
        // Move camera down
        mTranslateVector.y = -mMoveScale;
    }

    if(mKeyboard->isKeyDown(KC_RIGHT))
    {
        mCamera->yaw(-mRotScale);
    }

    if(mKeyboard->isKeyDown(KC_LEFT))
    {
        mCamera->yaw(mRotScale);
    }
*/

// FIXME FIXME FIXME!
    if (mKeyboard->isKeyDown(KC_SPACE))
    {
        game->setShotTaken(true);
        game->setShotComplete(false);
        bballInstance[0].setDribbling(false);
    }
    if (mKeyboard->isKeyDown(KC_J))
    {
        return false;
    }
    // Return true to continue rendering
    return true;

}

bool inputSystem::processUnbufferedMouseInput()
{
    using namespace OIS;

    UBC *ubc = UBC::Instance();
    renderSystems *render = renderSystems::Instance();

    Ogre::Vector3 mTranslateVector = render->getMTranslateVector();
    Radian mRotX = render->getMRotX();
    Radian mRotY = render->getMRotY();

    mMouse->capture();

    const MouseState &ms = mMouse->getMouseState();

//    CEGUI::System::getSingleton().injectMouseMove(ms.X.rel,ms.Y.rel);

    if (ubc->getMenuActive())
    {
        if ( ms.buttonDown( MB_Left) )
        {
 //           CEGUI::System::getSingleton().injectMouseButtonDown(convertOgreButtonToCegui(mMouse->getID()));
    	}

        else
        {
 //           CEGUI::System::getSingleton().injectMouseButtonUp(convertOgreButtonToCegui(mMouse->getID()));
        }
    }

    else
    {
  /*      if( ms.buttonDown( MB_Right ) )
        {
            mTranslateVector.x += ms.X.rel * 0.13;
            mTranslateVector.y -= ms.Y.rel * 0.13;
        }
        else
        {
            mRotX = Degree(-ms.X.rel * 0.13);
            mRotY = Degree(-ms.Y.rel * 0.13);
        }
*/
    }

    render->setMTranslateVector(mTranslateVector);
    render->setMRotX(mRotX);
    render->setMRotY(mRotY);

    return true;
}
