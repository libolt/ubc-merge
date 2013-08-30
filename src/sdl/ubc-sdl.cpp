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


	SDL_Window *sdlWindow = SDL_CreateWindow("title",
	                             SDL_WINDOWPOS_UNDEFINED,
	                             SDL_WINDOWPOS_UNDEFINED,
	                             0, 0,
	                             SDL_WINDOW_FULLSCREEN_DESKTOP);

    SDL_SysWMinfo sysInfo;
    SDL_VERSION( &sysInfo.version );

    SDLTest_CommonState *state;

    #if defined(WIN32) && !defined(UNIX)
		HWND hWnd;
        hWnd = sysInfo.info.win.window;
    #elif defined(UNIX) && !defined(WIN32)
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

    Ogre::String strWindowHandle = Ogre::StringConverter::toString( hWnd);
    misc["parentWindowHandle"] = strWindowHandle;

    mWindow = mRoot->createRenderWindow("MainRenderWindow", state->window_w, state->window_h, false, &misc);
    mWindow->setVisible( true );

    atexit(SDL_Quit);

}
