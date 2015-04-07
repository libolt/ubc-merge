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

 
#ifndef SOUNDENGINE_H_
#define SOUNDENGINE_H_

//#include "OgreAL.h"

//#include "soundobject.h"
#include "gameengine.h"

#define MAX_SOURCES 16
#include <cstddef>

#include <unordered_map>
#include <vector>
#include <list>
#include "ALmixer.h"
#include "ALmixer_PlatformExtensions.h"
#include "OgreMath.h"
#include "SDL.h"
#include "SDL_thread.h"
#include "SDL_timer.h"

#include "logging.h"

#include "openal.h"

#ifndef AL_CHECK
#ifdef _DEBUG
       #define AL_CHECK(stmt) do { \
            stmt; \
            CheckOpenALError(#stmt, __FILE__, __LINE__); \
        } while (0);
#else
    #define AL_CHECK(stmt) stmt
#endif
#endif



class SoundEngine
{
    public:

        ~SoundEngine();

        static SoundEngine *Instance();
        
        void Internal_SoundFinished_CallbackIntercept(ALint which_channel, ALuint al_source, ALmixer_Data* almixer_data, ALboolean finished_naturally, void* user_data);

        bool loadSound(std::string sound);  // loads sounds from media file
                bool setup();   // sets up the sound system
    protected:

        SoundEngine(const std::string & deviceName, bool useThreadUpdate);
        SoundEngine(const SoundEngine&);
        SoundEngine& operator= (const SoundEngine&);
        
        ALCdevice * deviceAL;
        ALCcontext * contextAL;
        std::string deviceName;

//        pthread_t updateThread;
        SDL_Thread *updateThread;
//        pthread_mutex_t fakeMutex;
        SDL_mutex *fakeMutex;
//        pthread_cond_t fakeCond;
        SDL_cond *fakeCond;

    private:
        
        ALboolean g_PlayingAudio[MAX_SOURCES];
        ALboolean still_playing;

        ALmixer_Data *audio_data;
        
        static SoundEngine *pInstance;
        bool setupComplete;  // determines if setup has completed
 };

#endif // SOUNDENGINE_H_
