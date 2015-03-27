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

#include "soundengine.h"

SoundEngine* SoundEngine::pInstance = 0;
SoundEngine* SoundEngine::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new SoundEngine; // create sole instance
    }
    return pInstance; // address of sole instance
}

SoundEngine::SoundEngine()
{
    this->deviceAL = NULL;
    this->contextAL = NULL;
    this->deviceName = deviceName;
    this->ended = false;
    this->useThreadUpdate = useThreadUpdate;

    this->masterVolume = 1.0f;
    this->lastVolume = 1.0f;

	this->enabled = true;
    setup();
}

SoundEngine::~SoundEngine()
{
    std::unordered_map<std::string, SoundObject *>::iterator it;
    for (it = this->sounds.begin(); it != this->sounds.end(); it++)
    {       
        it->second->Stop();
//        SAFE_DELETE(it->second);
    }

    this->sounds.clear();


    for (uint32_t i = 0; i < this->buffers.size(); i++)
    {
        AL_CHECK( alDeleteBuffers(1, &this->buffers[i].refID) );
    }

    for (uint32_t i = 0; i < this->sources.size(); i++)
    {
        AL_CHECK( alDeleteSources(1, &this->sources[i].refID) );
    }

    alcDestroyContext(this->contextAL);
	alcCloseDevice(this->deviceAL);
}

bool SoundEngine::setup()
{
//    soundMgr = new OgreAL::SoundManager();
//    exit(0);
    
    alGetError();

    ALCdevice * deviceAL = alcOpenDevice(NULL);

    if (deviceAL == NULL)
    {
        logMsg("Failed to init OpenAL device.");
        return false;
    }

    ALCcontext * contextAL = alcCreateContext(deviceAL, NULL);
    AL_CHECK( alcMakeContextCurrent(contextAL) );
  
    return true;
}
