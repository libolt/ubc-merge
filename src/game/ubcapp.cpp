/***************************************************************************
 *   Copyright (C) 2014 by Mike McLean   *
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
#include "logging.h"
#include "ubcapp.h"

#ifdef __ANDROID__
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
#include "android.h"
#include "SDL.h"
#include "SDL_main.h"
#endif

/*#ifdef __cplusplus
extern â€œCâ€�
#endif*/

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


//#ifndef __ANDROID__

int main(int argc, char *argv[])
{

    renderEngine *render = renderEngine::Instance();
    gameEngine *gameE = gameEngine::Instance();
    gameState *gameS = gameState::Instance();

//#ifndef __ANDROID__
    GUISystem *gui = GUISystem::Instance();
//#endif

//    networkEngine *network = networkEngine::Instance();
//    players *player = players::Instance();

//#ifndef __ANDROID__
    //#endif
	render->initSDL(); // Initializes the SDL Subsystem

    render->initOgre(); // Initializes the Ogre Subsystem
    render->createScene(); // creates rendering scene.
    
    
    JNIEnv* env = (JNIEnv*)SDL_AndroidGetJNIEnv();

    jclass class_sdl_activity   = env->FindClass("com/libolt/ubc/UBCActivity");

    jclass class_activity       = env->FindClass("com/libolt/ubc/UBCActivity");
    jclass class_resources      = env->FindClass("android/content/res/Resources");
    jmethodID method_get_resources      = env->GetMethodID(class_activity, "getResources", "()Landroid/content/res/Resources;");
    jmethodID method_get_assets         = env->GetMethodID(class_resources, "getAssets", "()Landroid/content/res/AssetManager;");
    jmethodID method_get_native_surface = env->GetStaticMethodID(class_sdl_activity, "getNativeSurface", "()Landroid/view/Surface;");
  
    jobject raw_activity = (jobject)SDL_AndroidGetActivity();
    jobject raw_resources = env->CallObjectMethod(raw_activity, method_get_resources);
    jobject raw_asset_manager = env->CallObjectMethod(raw_resources, method_get_assets);
    jobject raw_surface = env->CallStaticObjectMethod(class_sdl_activity, method_get_native_surface);

    ANativeWindow* native_window = ANativeWindow_fromSurface(env, raw_surface);
/*
    logMsg("Dead");
    render->setSDLWindow(SDL_CreateWindowFrom(native_window));
    logMsg("window ID = " +Ogre::StringConverter::toString(SDL_GetWindowID(render->getSDLWindow())));
    SDL_ShowWindow(render->getSDLWindow());
    SDL_SetWindowGrab(render->getSDLWindow(),SDL_TRUE);
	SDL_MaximizeWindow(render->getSDLWindow());
    */
//#ifndef __ANDROID__
    gui->initMyGUI(); // Initializes MyGUI
    if (!gui->getMainMenuCreated())
    {
        gui->createMainMenuGUI(); // creates the main menu gui.
		gui->createBackButtons(); // creates the back buttons.
    }
//#endif

	//FIXME hardcoded while working on other bugs
/*#ifdef __ANDROID__
	gameS->setGameType(SINGLE);
#endif
*/
    logMsg("Initializing Input");
    inputSystem *input = inputSystem::Instance();

    gameE->gameLoop();

    atexit(SDL_Quit);

	return (0);
}

