/***************************************************************************
 *   Copyright (C) 2014 by Mike McLean   *
 *   libolt@libolt.net   *
 *         ?
 *
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
//    #define OGRE_STATIC_ParticleFX
//    #define OGRE_STATIC_OctreeSceneManager
    #include "OgreStaticPluginLoader.h"


    #include <EGL/egl.h>
    #include <android/log.h>
    #include <android_native_app_glue.h>
    #include <android/native_window.h> 
	#include <android/native_window_jni.h>
    #include <android/asset_manager.h>
    #include <android/asset_manager_jni.h>

    #include "RTShaderHelper.h"
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

    Root *getMRoot();
    void setMRoot(Root *root);

    Camera *getMCamera();
    void setMCamera(Camera *camera);

    SceneManager *getMSceneMgr();
    void setMSceneMgr(SceneManager *sceneMgr);

    RenderWindow *getMWindow();
    void setMWindow(RenderWindow *window);

	Ogre::Viewport *getViewPort(); // retrieves the value of viewPort
	void setViewPort(Ogre::Viewport *vp); // sets the value of viewPort
	
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	Ogre::DataStreamPtr openAPKFile(const Ogre::String& fileName);

    AAssetManager* getMAssetMgr();
    void setMAssetMgr(AAssetManager* asset);
	
    android_app *getApp();
    void setApp(android_app *ap);
#endif

    Ogre::Vector3 getMTranslateVector();
    void setMTranslateVector(Ogre::Vector3 vector);

    Radian getMRotX();
    void setMRotX(Radian rotX);

    Radian getMRotY();
    void setMRotY(Radian rotY);

    Real getMMoveSpeed();
    void setMMoveSpeed(Real speed);

    Degree getMRotateSpeed();
    void setMRotateSpeed(Degree speed);

    float getMMoveScale();
    void setMMoveScale(float scale);

    Degree getMRotScale();
    void setMRotScale(Degree scale);

    String getMResourceGroup();
    void setMResourceGroup(String resource);

	SDL_Window *getSDLWindow();
	void setSDLWindow(SDL_Window *window);

    uint32_t getWindowWidth();  // retrieves the value of windowWidth
    void setWindowWidth(uint32_t set);  // sets the value of windowWidth
    
    uint32_t getWindowHeight();  // retrieves the value of windowHeight
    void setWindowHeight(uint32_t set);  // sets the value of windowHeight
    
    ~renderEngine();

    static renderEngine *Instance();

    bool initSDL();
    bool initOgre();

    bool createWindow();
    bool createScene();
    bool frameStarted();
    bool frameEnded();
    void createSceneManager();

	protected:
    renderEngine();
    renderEngine(const renderEngine&);
    renderEngine& operator= (const renderEngine&);

    #if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        android_app* app;
        //static
        Ogre::StaticPluginLoader* gStaticPluginLoader;
        AConfiguration* config;

    #endif
    
    // SDL code
    SDL_Window *sdlWindow;
	SDL_GLContext sdlGLContext;
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

    // general
    uint32_t windowWidth;  // stores the width of the window
    uint32_t windowHeight;  // stores the height of the window
	// Android support
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	AAssetManager* mAssetMgr;
	Ogre::ShaderGeneratorTechniqueResolverListener* mMatListener;
#endif
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
