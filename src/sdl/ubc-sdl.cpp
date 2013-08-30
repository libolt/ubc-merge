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

#include "ubc-sdl.h"

// main

int main(int argc, char *argv[])
{

    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0) {
        fprintf(stderr,
                "\nUnable to initialize SDL:  %s\n",
                SDL_GetError()
               );
        return 1;
    }


	SDL_Window *sdlWindow = SDL_CreateWindow("MainRenderWindow",
	                             SDL_WINDOWPOS_UNDEFINED,
	                             SDL_WINDOWPOS_UNDEFINED,
	                             1024, 768, 0);

    SDL_SysWMinfo sysInfo;
    SDL_VERSION( &sysInfo.version );

    SDLTest_CommonState *state;

    #if defined(WIN32) && !defined(__linux__)
		HWND hWnd;
        hWnd = sysInfo.info.win.window;
    #elif defined(__linux__) && !defined(WIN32)
       unsigned long hWnd = 0;
       hWnd = sysInfo.info.x11.window;
    #else
    /* Error, both can't be defined or undefined same time */
    #endif

    Ogre::Root *mRoot;
    Ogre::Camera *mCamera;
    Ogre::SceneManager *mSceneMgr;
    Ogre::RenderWindow *mWindow;
   //	InputReader* mInputDevice;

    Ogre::NameValuePairList misc;

    mRoot = new Ogre::Root("", "", "Ogre.log");

    const Ogre::String pluginDir = OGRE_PLUGIN_DIR;

//    string pluginDir;
//    const char pluginDir = OGRE_PLUGIN_DIR;

    #if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    const String buildType = BUILD_TYPE;

    if (buildType == "Debug")
    {
        mRoot->loadPlugin(pluginDir + "/RenderSystem_Direct3D9_d");
        mRoot->loadPlugin(pluginDir + "/Plugin_CgProgramManager_d");
    }
    else
    {
        mRoot->loadPlugin(pluginDir + "/RenderSystem_Direct3D9");
        mRoot->loadPlugin(pluginDir + "/Plugin_CgProgramManager");
    }
    #elif OGRE_PLATFORM == OGRE_PLATFORM_APPLE
    mRoot->loadPlugin("RenderSystem_GL");
    #else
    mRoot->loadPlugin(pluginDir + "/RenderSystem_GL");
    mRoot->loadPlugin(pluginDir + "/Plugin_CgProgramManager");
    #endif

    Ogre::RenderSystemList rsList = mRoot->getAvailableRenderers();

/*	r_it = renderEngine->begin();
    	mRoot->setRenderSystem(*r_it);
	mWindow = mRoot->initialise(false);
//	exit(0);
*/
	int c=0;
	bool foundit = false;
	Ogre::RenderSystem *selectedRenderSystem=0;
	while(c < (int) rsList.size())
	{
		selectedRenderSystem = rsList.at(c);
   		Ogre::String rname = selectedRenderSystem->getName();
   		if(rname.compare("OpenGL Rendering Subsystem")==0)
		{
     			foundit=true;
     			break;
   		}
   		c++; // <-- oh how clever
 	}
// 	if(!foundit) exit(1); //we didn't find it...

 	//we found it, we might as well use it!
 	mRoot->setRenderSystem(selectedRenderSystem);


    Ogre::String strWindowHandle = Ogre::StringConverter::toString((unsigned long)(sysInfo.info.x11.window));
//    Ogre::String strWidth = Ogre::StringConverter::toString(state->window_w);
    misc["parentWindowHandle"] = strWindowHandle;
//    std::cout << strWidth << std::endl;
//    exit(0);
    mWindow = mRoot->createRenderWindow("MainRenderWindow", 1024, 768, false, &misc);
    mWindow->setVisible( true );

    atexit(SDL_Quit);

}
