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

#include "OgrePrerequisites.h"
#include "gameengine.h"
#include "gamestate.h"
#include "ubcapp.h"

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
#include "android.h"
#endif

UBC::UBC()
{
	quitGame = false;
}

UBC::~UBC()
{

}

bool UBC::getQuitGame()
{
	return (quitGame);
}

void UBC::setQuitGame(bool quit)
{
    quitGame = quit;
}

# if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
void android_main(struct android_app* state)
{
    app_dummy();
    
	if(gRoot == NULL)
	{
		gRoot = new Ogre::Root();
#ifdef OGRE_STATIC_LIB
        gStaticPluginLoader = new Ogre::StaticPluginLoader();
        gStaticPluginLoader->load();
#endif
        gRoot->setRenderSystem(gRoot->getAvailableRenderers().at(0));
        gRoot->initialise(false);	
	}			
			
    state->onAppCmd = &handleCmd;
    state->onInputEvent = &handleInput;
    
    int ident, events;
    struct android_poll_source* source;
    
    while (true)
    {
        while ((ident = ALooper_pollAll(0, NULL, &events, (void**)&source)) >= 0)
        {
            if (source != NULL)
                source->process(state, source);
            
            if (state->destroyRequested != 0)
                return;
        }
        
		if(gRenderWnd != NULL && gRenderWnd->isActive())
		{
			gRenderWnd->windowMovedOrResized();
			gRoot->renderOneFrame();
		}
    }
}

#else

int main(int argc, char *argv[])
{
    renderEngine * render = renderEngine::Instance();

    gameEngine *gameE = gameEngine::Instance();
//    gameState *gameS = gameState::Instance();
    GUISystem *gui = GUISystem::Instance();
//    networkEngine *network = networkEngine::Instance();
//    players *player = players::Instance();


    render->initSDL(); // Initializes the SDL Subsystem
    render->initOgre(); // Initializes the Ogre Subsystem
//    render->createScene(); // creates rendering scene.
    gui->initMyGUI(); // Initializes MyGUI
    gui->createMainMenuButtons(); // creates a MyGUI button.

    inputSystem *input = inputSystem::Instance();

    gameE->gameLoop();

    atexit(SDL_Quit);

	return (0);
}

#endif
