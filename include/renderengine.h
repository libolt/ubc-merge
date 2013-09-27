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

#ifndef _RENDERENGINE_H_
#define _RENDERENGINE_H_

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    #define OGRE_STATIC_GLES2
    #define OGRE_STATIC_ParticleFX
//    #define OGRE_STATIC_OctreeSceneManager
    #include "OgreStaticPluginLoader.h"
    

    #include <EGL/egl.h>
    #include <android/log.h>
    #include <android_native_app_glue.h>
  
//    #include "RTShaderHelper.h"
    #include "Android/OgreAndroidEGLWindow.h"
    #include "Android/OgreAPKFileSystemArchive.h"
    #include "Android/OgreAPKZipArchive.h"


#elif OGRE_PLATFORM == OGRE_PLATFORM_APPLE
    #include "Ogre/OgreMemoryMacros.h"
    #include "Ogre/Ogre.h"
#else
    #include "Ogre.h"
#endif

#include "SDL.h"
#include "SDL_syswm.h"
#include "SDL_test_common.h"

using namespace Ogre;
class renderEngine
{
	public:

    virtual Root *getMRoot();
    void setMRoot(Root *root);

    virtual Camera *getMCamera();
    void setMCamera(Camera *camera);

    virtual SceneManager *getMSceneMgr();
    void setMSceneMgr(SceneManager *sceneMgr);

    virtual RenderWindow *getMWindow();
    void setMWindow(RenderWindow *window);

    virtual Ogre::Vector3 getMTranslateVector();
    void setMTranslateVector(Ogre::Vector3 vector);

    virtual Radian getMRotX();
    void setMRotX(Radian rotX);

    virtual Radian getMRotY();
    void setMRotY(Radian rotY);

    virtual Real getMMoveSpeed();
    void setMMoveSpeed(Real speed);

    virtual Degree getMRotateSpeed();
    void setMRotateSpeed(Degree speed);

    virtual float getMMoveScale();
    void setMMoveScale(float scale);

    virtual Degree getMRotScale();
    void setMRotScale(Degree scale);

    virtual String getMResourceGroup();
    void setMResourceGroup(String resource);

    virtual ~renderEngine();

    static renderEngine *Instance();

    virtual bool initSDL();
    virtual bool initOgre();
    virtual bool createScene();
    virtual bool frameStarted();
    virtual bool frameEnded();
    virtual void createSceneManager();

	protected:
    renderEngine();
    renderEngine(const renderEngine&);
    renderEngine& operator= (const renderEngine&);

    #if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID 
        struct android_app* app;
        //static 
        Ogre::StaticPluginLoader* gStaticPluginLoader;
        AConfiguration* config;
        
    #endif 
    // SDL code
    SDL_Window *sdlWindow;
    SDL_SysWMinfo sysInfo;
    SDLTest_CommonState *state;

    // Ogre code
    Root *mRoot;
    Camera *mCamera;
    SceneManager *mSceneMgr;
    RenderWindow *mWindow;
    Ogre::Viewport *viewPort;
    Ogre::String mResourceGroup;  	// stores resource locations
	Ogre::NameValuePairList misc;	// options to pass to mWindow during creation
	Ogre::String winHandle;			// window handle

    //	InputReader* mInputDevice;
    Ogre::Vector3 mTranslateVector;
    Radian mRotX, mRotY;
    Real mMoveSpeed;
    Degree mRotateSpeed;
    float mMoveScale;
    Degree mRotScale;


    Real mTimeUntilNextToggle ;

    private:

    static renderEngine *pInstance;

};

#endif // RENDERSYSTEMS_H_INCLUDED
