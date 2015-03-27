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

#include "soundobject.h"

class SoundObject;

typedef struct ALCdevice_struct ALCdevice;
typedef struct ALCcontext_struct ALCcontext;

#include <cstddef>

#include <pthread.h>

#include <unordered_map>
#include <vector>
#include <list>
#include "al.h"
#include "alc.h"
#include "OgreMath.h"

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

        static std::vector<std::string> GetAllDevices();
        static void Initialize(const std::string & deviceName = "", bool useThreadUpdate = true);
        static void Destroy();          
//        static SoundManager * GetInstance();            
            
        bool ExistSound(const std::string & name) const;
        void ReleaseSound(const std::string & name);
        void AddSound(const std::string & fileName, const std::string & name);
        void AddSound(SoundObject * sound);
    
        SoundObject * GetSound(const std::string & name);

        void Update();
            
        void SetMasterVolume(float volume);
        void VolumeUp(float amount = 0.1f);
        void VolumeDown(float amount = 0.1f);

        bool IsEnabled();
        void Disable();
        void Enable();

        friend class SoundObject;           

        bool setup();   // sets up the sound system
    protected:

        SoundEngine(const std::string & deviceName, bool useThreadUpdate);
        SoundEngine(const SoundEngine&);
        SoundEngine& operator= (const SoundEngine&);
        
        
        ALCdevice * deviceAL;
        ALCcontext * contextAL;
        std::string deviceName;

        pthread_t updateThread;
        pthread_mutex_t fakeMutex;
        pthread_cond_t fakeCond;
        bool useThreadUpdate;
        bool ended;

        bool enabled;
        float lastVolume;

        float masterVolume;

        std::unordered_map<std::string, SoundObject *> sounds;

        std::vector<SoundSource> sources;
        std::vector<SoundBuffer> buffers;

        std::list<SoundSource *> freeSources;
        std::list<SoundBuffer *> freeBuffers;

        void Init();
            
        SoundSource * GetFreeSource();
        SoundBuffer * GetFreeBuffer();
    
        void FreeSource(SoundSource * source);
        void FreeBuffer(SoundBuffer * buffer);

        static void * UpdateThread(void * c);
        void Wait(int timeInMS);
        void ThreadUpdate();
            
    private:

        static SoundEngine *pInstance;
        bool setupComplrte;
 };

#endif // SOUNDENGINE_H_
