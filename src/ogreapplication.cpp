/***************************************************************************
 *   Copyright (C) 2006 by Mike McLean   *
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


#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "ogreapplication.h"


//using namespace ogre;
//-------------------------------------------------------------------------------------
OgreApplication::OgreApplication()
      : mRoot(0)
{
    bufferedKeys = false;
    bufferedMouse = false;
    bufferedJoy = false;

    im = 0;
}

//-------------------------------------------------------------------------------------
OgreApplication::~OgreApplication()
{
    WindowEventUtilities::removeWindowEventListener(mWindow, this);
    windowClosed(mWindow);

//	PlatformManager::getSingleton().destroyInputReader( mInputDevice );
    delete Root::getSingletonPtr();

    delete mRoot;
}

void OgreApplication::windowResized(RenderWindow* rw)
{
    unsigned int width, height, depth;
    int left, top;
    rw->getMetrics(width, height, depth, left, top);

    const OIS::MouseState &ms = mMouse->getMouseState();
    ms.width = width;
    ms.height = height;
}

//Unattach OIS before window shutdown (very important under Linux)
void OgreApplication::windowClosed(RenderWindow* rw)
{
    using namespace OIS;
    //Only close for window that created OIS (mWindow)
    if( rw == mWindow )
    {
//		InputManager* im = 0;//::getSingletonPtr();
        if( im )
        {
            im->destroyInputObject( mMouse );
            im->destroyInputObject( mKeyboard );
            im->destroyInputObject( mJoy );
            im->destroyInputSystem(im);
        }
    }
}


//-------------------------------------------------------------------------------------
void OgreApplication::go()
{

    if (!initialise())
        return;
    mRoot->startRendering();

//	PlatformManager::messagePump(mAutoWindow);
    // clean up
    destroyScene();
}
/*
void Root::startRendering(void)
{
    assert(mActiveRenderer != 0);

    mActiveRenderer->_initRenderTargets();

    // Clear event times
    for(int i=0; i!=3; ++i)
    mEventTimes[i].clear();

    // Infinite loop, until broken out of by frame listeners
    // or break out by calling queueEndRendering()
    mQueuedEnd = false;

    while( !mQueuedEnd )
    {
    	//Allow platform to pump/create/etc messages/events once per frame
//      mPlatformManager->messagePump(mAutoWindow);
        mPlatformManager->messagePump(window);
        if (!renderOneFrame())
        break;
//		mActiveRenderer->
    }
}
*/
//-------------------------------------------------------------------------------------
bool OgreApplication::initialise()
{
    mRoot = new Root();
    // add resource locations
    addResourceLocations();

    bool carryOn = initOgreCore();
    if (!carryOn) return false;

    createSceneManager();
    createCamera();
 //   createViewports();

    // Set default mipmap level (NB some APIs ignore this)
    TextureManager::getSingleton().setDefaultNumMipmaps(5);

    // Create any resource listeners (for loading screens)
    createResourceListener();

    // Initialise resources
    initResources();

    // Create the scene
    createScene();

    createFrameListener();


    return true;
};

// gets and sets mSceneMgr
SceneManager *OgreApplication::getMSceneMgr()
{
    return (mSceneMgr);
}

void OgreApplication::setMSceneMgr(SceneManager *mgr)
{
    mSceneMgr = mgr;
}

// gets and sets mWindow
RenderWindow *OgreApplication::getMWindow()
{
    return(mWindow);
}
void OgreApplication::setMWindow(RenderWindow *window)
{
    mWindow = window;
}

//-------------------------------------------------------------------------------------
void OgreApplication::addResourceLocations()
{
    // Load resource paths from config file
    ConfigFile cf;
    cf.load("resources.cfg");

    // Go through all sections & settings in the file
    ConfigFile::SectionIterator seci = cf.getSectionIterator();

    String secName, typeName, archName;
    while (seci.hasMoreElements())
    {
        secName = seci.peekNextKey();
        ConfigFile::SettingsMultiMap *settings = seci.getNext();
        ConfigFile::SettingsMultiMap::iterator i;
        for (i = settings->begin(); i != settings->end(); ++i)
        {
            typeName = i->first;
            archName = i->second;
            ResourceGroupManager::getSingleton().addResourceLocation(archName, typeName, secName);
        }
    }
}

//-------------------------------------------------------------------------------------
bool OgreApplication::initOgreCore()
{
    // Show the configuration dialog and initialise the system
    // You can skip this and use root.restoreConfig() to load configuration
    // settings if you were sure there are valid ones saved in ogre.cfg
    if(mRoot->restoreConfig() || mRoot->showConfigDialog())
    {
        // If returned true, user clicked OK so initialise
        // Here we choose to let the system create a default rendering window by passing 'true'
        mWindow = mRoot->initialise(true);
        return true;
    }
    else
    {
        return false;
    }
}

//-------------------------------------------------------------------------------------
void OgreApplication::createSceneManager()
{
    // Create the SceneManager, in this case a generic one
    mSceneMgr = mRoot->createSceneManager(ST_GENERIC);
}

//-------------------------------------------------------------------------------------
void OgreApplication::createCamera()
{
    // Create the camera
    mCamera = mSceneMgr->createCamera("PlayerCam");

    // Position it at 500 in Z direction
    mCamera->setPosition(Vector3(0,0,500));
    // Look back along -Z
    mCamera->lookAt(Vector3(0,0,-300));
    mCamera->setNearClipDistance(5);
}

//-------------------------------------------------------------------------------------
void OgreApplication::createViewports()
{
    // Create one viewport, entire window
  /*  Viewport* vp = mWindow->addViewport(mCamera);
    vp->setBackgroundColour(ColourValue(0,0,0));

    // Alter the camera aspect ratio to match the viewport
    mCamera->setAspectRatio(Real(vp->getActualWidth()) / Real(vp->getActualHeight()));
*/
}

//-------------------------------------------------------------------------------------
void OgreApplication::createResourceListener()
{

}

//-------------------------------------------------------------------------------------
void OgreApplication::initResources()
{
    // Initialise, parse scripts etc
    ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}

//-------------------------------------------------------------------------------------
void OgreApplication::destroyScene()
{
}

//-------------------------------------------------------------------------------------
bool OgreApplication::frameStarted(const FrameEvent& evt)
{
    // If this is the first frame, pick a speed
    if (evt.timeSinceLastFrame == 0)
    {
        mMoveScale = 1;
        mRotScale = 0.1;
    }
    // Otherwise scale movement units by time passed since last frame
    else
    {
        // Move about 100 units per second,
        mMoveScale = mMoveSpeed * evt.timeSinceLastFrame;
        // Take about 10 seconds for full rotation
        mRotScale = mRotateSpeed * evt.timeSinceLastFrame;
    }


//	mInputDevice->capture();

    mRotX = 0;
    mRotY = 0;
    mTranslateVector = Ogre::Vector3::ZERO;
    using namespace OIS;

    if(mWindow->isClosed())	return false;

    //Need to capture/update each device
    mKeyboard->capture();
    mMouse->capture();
    if( mJoy ) mJoy->capture();

    bool buffJ = (mJoy) ? mJoy->buffered() : true;

    //Check if one of the devices is not buffered
    if( !mMouse->buffered() || !mKeyboard->buffered() || !buffJ )
    {
        // one of the input modes is immediate, so setup what is needed for immediate movement
        if (mTimeUntilNextToggle >= 0)
            mTimeUntilNextToggle -= evt.timeSinceLastFrame;

        // If this is the first frame, pick a speed
        if (evt.timeSinceLastFrame == 0)
        {
            mMoveScale = 1;
            mRotScale = 0.1;
        }

        // Otherwise scale movement units by time passed since last frame
        else
        {
            // Move about 100 units per second,
            mMoveScale = mMoveSpeed * evt.timeSinceLastFrame;
            // Take about 10 seconds for full rotation
            mRotScale = mRotateSpeed * evt.timeSinceLastFrame;
        }
            mRotX = 0;
            mRotY = 0;
            mTranslateVector = Ogre::Vector3::ZERO;
    }

    //Check to see which device is not buffered, and handle it
    if( !mKeyboard->buffered() )
        if( processUnbufferedKeyInput(evt) == false )
            return false;
        if( !mMouse->buffered() )
            if( processUnbufferedMouseInput(evt) == false )
                return false;

        if( !mMouse->buffered() || !mKeyboard->buffered() || !buffJ )
//			moveCamera();

/*
    if (processUnbufferedKeyInput(evt) == false)
    {
        return false;
    }

    if (processUnbufferedMouseInput(evt) == false)
    {
        return false;
    }*/

            moveCamera();

        return true;
}

//-------------------------------------------------------------------------------------
bool OgreApplication::frameEnded(const FrameEvent& evt)
{

//	mRoot->renderOneFrame();

    return true;
}

//-------------------------------------------------------------------------------------
void OgreApplication::createFrameListener()
{
    mRotateSpeed = 36;
    mMoveSpeed = 100;
    mMoveScale = 0.0f;
    mRotScale = 0.0f;
    mRoot->addFrameListener(this);

    using namespace OIS;

//		mDebugOverlay = OverlayManager::getSingleton().getByName("Core/DebugOverlay");

    LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
    ParamList pl;
    size_t windowHnd = 0;
    std::ostringstream windowHndStr;
    mWindow->getCustomAttribute("WINDOW", &windowHnd);
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
    windowResized(mWindow);
    //Register as a Window listener
    WindowEventUtilities::addWindowEventListener(mWindow, this);

//	mInputDevice = PlatformManager::getSingleton().createInputReader();
//	mInputDevice->initialise(mWindow,true, true);

}

//-------------------------------------------------------------------------------------
bool OgreApplication::processUnbufferedKeyInput(const FrameEvent& evt)
{
    using namespace OIS;

    if(mKeyboard->isKeyDown(KC_Q))
    {
    //	exit(0);
        return false;
    }

/*
    if( mInputDevice->isKeyDown( KC_ESCAPE) )
    {
        return false;
    }

    if (mInputDevice->isKeyDown(KC_A))
    {
        // Move camera left
	mTranslateVector.x = -mMoveScale;
    }

    if (mInputDevice->isKeyDown(KC_D))
    {
        // Move camera RIGHT
        mTranslateVector.x = mMoveScale;
    }

    // Move camera forward by keypress.
    if (mInputDevice->isKeyDown(KC_UP) || mInputDevice->isKeyDown(KC_W) )
    {
        mTranslateVector.z = -mMoveScale;
    }

    // Move camera backward by keypress.
    if (mInputDevice->isKeyDown(KC_DOWN) || mInputDevice->isKeyDown(KC_S) )
    {
        mTranslateVector.z = mMoveScale;
    }

    if (mInputDevice->isKeyDown(KC_PGUP))
    {
        // Move camera up
        mTranslateVector.y = mMoveScale;
    }

    if (mInputDevice->isKeyDown(KC_PGDOWN))
    {
        // Move camera down
        mTranslateVector.y = -mMoveScale;
    }

    if (mInputDevice->isKeyDown(KC_RIGHT))
    {
	mCamera->yaw(-mRotScale);
    }

    if (mInputDevice->isKeyDown(KC_LEFT))
    {
        mCamera->yaw(mRotScale);
    }
*/
    // Return true to continue rendering
    return true;
}

//-------------------------------------------------------------------------------------
bool OgreApplication::processUnbufferedMouseInput(const FrameEvent& evt)
{

    using namespace OIS;

    const MouseState &ms = mMouse->getMouseState();
/*

    if( ms.buttonDown( MB_Right ) )
    {
        mTranslateVector.x += ms.X.rel * 0.13;
        mTranslateVector.y -= ms.Y.rel * 0.13;
    }
    else
    {
        mRotX = Degree(-ms.X.rel * 0.13);
        mRotY = Degree(-ms.Y.rel * 0.13);
    }


    CEGUI::System::getSingleton().injectMouseMove(ms.X.rel,ms.Y.rel);
    if ( ms.buttonDown( MB_Left) )
    {
        CEGUI::System::getSingleton().injectMouseButtonDown(convertOgreButtonToCegui(mMouse->getID()));
    }

    else
    {
        CEGUI::System::getSingleton().injectMouseButtonUp(convertOgreButtonToCegui(mMouse->getID()));
    }
*/
    return true;
}

void OgreApplication::moveCamera()
{
    // Make all the changes to the camera
    // Note that YAW direction is around a fixed axis (freelook style) rather than a natural YAW (e.g. airplane)
    mCamera->yaw(mRotX);
    mCamera->pitch(mRotY);
    mCamera->moveRelative(mTranslateVector);
}

