/***************************************************************************
 *   Copyright (C) 2003 by Mike McLean                                     *
 *   libolt@libolt.net                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef _MAIN_H_
#define _MAIN_H_

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <iostream>
#include <fstream>
#include <cstdlib>

 #include <stdio.h>

#include <string>

#include <vector>

#include <iomanip>

#include <algorithm>

#include <math.h>

// #include "SDL.h"

// #include "SDL_image.h"

// #include "SDL_ttf.h"

// #include "SDL_gfxPrimitives.h"

// #include "SDL_rotozoom.h"

//#include "net2/net2.h"

//#include "net2/SDLUtils.h"

//#include "net2/fastevents.h"

// #include "sdlcode.h"

#include "collision.h"

#include "offense.h"

#include "ai.h"

#include "renderers.h"

#include "basketballs.h"

#include "courts.h"

#include "input.h"

#include "players.h"

#include "teams.h"

#include "load.h"

#include "timers.h"

#include "sprites.h"

#include "defense.h"

#include "menus.h"

#include "games.h"

using namespace std;

// Function Prototypes

// locks a surface so that operations may be performed on it
//void Slock(SDL_Surface *buffer);

//unlocks a surface
//void Sulock(SDL_Surface *buffer);


// MAIN GAME LOOP
//int gameLoop(games *game);

// splits paths into separate strings

//string *pathSplit(const string paths);

//string *pathSplit(const string paths);
//static string *pathArray;

string findFile(string fileName);

//void DrawPixel(SDL_Surface *screen, int x, int y, Uint8 R, Uint8 G, Uint8 B);


#endif


