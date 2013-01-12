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

#ifndef __OgreApplication_h__
#define __OgreApplication_h__
//regular mem handler
#include <OgreMemoryMacros.h>
#include <Ogre.h>
//Use this define to signify OIS will be used as a DLL
//(so that dll import/export macros are in effect)
#define OIS_DYNAMIC_LIB
#include <OIS/OIS.h>


using namespace Ogre;


class OgreApplication : public FrameListener, public WindowEventListener
{
public:
    OgreApplication(void);
    virtual ~OgreApplication(void);
    
    virtual void go(void);
    
    SceneManager *getMSceneMgr();	// returns mSceneMgr value
    void setMSceneMgr(SceneManager *mgr);	// sets mSceneManager value
    
    RenderWindow *getMWindow();	// returns mWindow value
    void setMWindow(RenderWindow *window);	// sets mWindow value

protected:
    virtual bool initialise();
    virtual bool initOgreCore();
    
    virtual void createSceneManager();
    virtual void createCamera();
    virtual void createViewports();
    virtual void createResourceListener();
    virtual void createFrameListener();
    
    virtual void addResourceLocations();
    virtual void initResources();

    virtual void createScene() = 0; // I am pure virtual, override me!
    virtual void destroyScene();
    
    virtual bool processUnbufferedKeyInput(const FrameEvent& evt);
    virtual bool processUnbufferedMouseInput(const FrameEvent& evt);
    
    // FrameListener overrides
    virtual bool frameStarted(const FrameEvent& evt);
    virtual bool frameEnded(const FrameEvent& evt);
    
    virtual void moveCamera();
    virtual void windowClosed(RenderWindow* rw);
    virtual void windowResized(RenderWindow* rw);
    
    Root *mRoot;
    Camera* mCamera;
    SceneManager *mSceneMgr;
    RenderWindow *mWindow;
//	InputReader* mInputDevice;
    Vector3 mTranslateVector;
    Radian mRotX, mRotY;
    Real mMoveSpeed;
    Degree mRotateSpeed;
    float mMoveScale;
    Degree mRotScale;
    //OIS Input devices
    OIS::Mouse*    mMouse;
    OIS::Keyboard* mKeyboard;
    OIS::JoyStick* mJoy;
    OIS::InputManager* im;
    bool bufferedKeys;
    bool bufferedMouse;
    bool bufferedJoy;
    Real mTimeUntilNextToggle ;

private:
};

#endif // __OgreApplication_h__

