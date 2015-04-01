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
//        pInstance = new SoundEngine; // create sole instance
    }
    return pInstance; // address of sole instance
}

SoundEngine::SoundEngine(const std::string & deviceName, bool useThreadUpdate)
{
    this->deviceAL = NULL;
    this->contextAL = NULL;
    this->deviceName = deviceName;
    this->ended = false;
    this->useThreadUpdate = useThreadUpdate;
   // std::pair<std::string,std::string> soundObj ("test","test");

    //this->sounds.insert(soundObj);
    this->masterVolume = 1.0f;
    this->lastVolume = 1.0f;

	this->enabled = true;
//    exit(0);
//    setup();
    Init();
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

    logMsg("Sound Engine Setup!");
    
    alGetError();
    logMsg("open device!");   
    ALCdevice * deviceAL = alcOpenDevice(NULL);
    logMsg("check open device!");
    if (deviceAL == NULL)
    {
        logMsg("Failed to init OpenAL device.");
        return false;
    }
    logMsg("create context");
    ALCcontext * contextAL = alcCreateContext(deviceAL, NULL);
    AL_CHECK( alcMakeContextCurrent(contextAL) );
  
    logMsg("Sound Engine Setup Complete!");
    return true;
}

void SoundEngine::Initialize(const std::string & deviceName, bool useThreadUpdate)
{
    if (pInstance == NULL)
    {
        pInstance = new SoundEngine(deviceName, useThreadUpdate);
    }
}

void SoundEngine::Destroy()
{
//    SAFE_DELETE(instance);
}



std::vector<std::string> SoundEngine::GetAllDevices()
{
    const char * devices = alcGetString(NULL, ALC_DEVICE_SPECIFIER);    
    const char * next = devices + 1;

    size_t len = 0;
    std::vector<std::string> devicesNames; 

    while (devices && *devices != '\0' && next && *next != '\0') 
    {
        std::string d = devices;
        devicesNames.push_back(d);                
        len = strlen(devices);
        devices += (len + 1);
        next += (len + 2);
    }
    return devicesNames;
}

bool SoundEngine::IsEnabled()
{
    return this->enabled;
}

void SoundEngine::Disable()
{
    if (this->enabled == false)
    {
        return;
    }

    this->enabled = false;
    this->lastVolume = this->masterVolume; //store last volume

    this->SetMasterVolume(0.0f);
}

void SoundEngine::Enable()
{
    if (this->enabled)
    {
        return;
    }
    this->enabled = true;

    this->SetMasterVolume(this->lastVolume); //restore volume
}

void SoundEngine::Init()
{
    //reset error stack
    alGetError();

    this->deviceAL = alcOpenDevice(0);

    if (this->deviceAL == NULL)
    {
        logMsg("Failed to init OpenAL device.");
        return;
    }
    

    this->contextAL = alcCreateContext(this->deviceAL, NULL);
    AL_CHECK( alcMakeContextCurrent(this->contextAL) );


    for (int i = 0; i < 512; i++)
    {
        SoundBuffer buffer;
        AL_CHECK( alGenBuffers((ALuint)1, &buffer.refID) );
        this->buffers.push_back(buffer);
    }

    for (int i = 0; i < 16; i++)
    {
        SoundSource source;
        AL_CHECK( alGenSources((ALuint)1, &source.refID)) ;
        this->sources.push_back(source);
    }


    for (uint32_t i = 0; i < this->buffers.size(); i++)
    {
        logMsg("adding freeBuffer");
        this->freeBuffers.push_back(&this->buffers[i]);
    }

    for (uint32_t i = 0; i < this->sources.size(); i++)
    {
        this->freeSources.push_back(&this->sources[i]);
    }

    if (this->useThreadUpdate)
    {
//        this->fakeMutex = PTHREAD_MUTEX_INITIALIZER;
        this->fakeMutex = SDL_CreateMutex();
//        this->fakeCond = PTHREAD_COND_INITIALIZER;
        this->fakeCond = SDL_CreateCond();

//        if(pthread_create(&this->updateThread, NULL, &SoundEngine::UpdateThread, this)) 
        if(updateThread = SDL_CreateThread(&this->UpdateThread,"ThteadUpdate", NULL))

        {   
            logMsg("Error creating thread");
            return;
        }
    }
    


}


int SoundEngine::UpdateThread(void * c)
{
    
    SoundEngine * context = ((SoundEngine *)c);
    while (true)
    {
        logMsg("context->ThreadUpdate()");
        context->ThreadUpdate();
        context->Wait(400);
        
        if (context->ended) 
        {
            break;
        }
    }
    
    return NULL;
}

void SoundEngine::Wait(int timeInMS)
{
    //http://stackoverflow.com/questions/1486833/pthread-cond-timedwait-help
    
    //struct timespec timeToWait;
    uint32_t timeToWait;
//    MyUtils::Utils::WaitTime(timeInMS, &timeToWait.tv_sec, &timeToWait.tv_nsec);
    SDL_Delay(timeInMS);

    //pthread_mutex_lock(&this->fakeMutex);
    SDL_LockMutex(this->fakeMutex);
    //pthread_cond_timedwait(&this->fakeCond, &this->fakeMutex, &timeToWait);
    SDL_CondWaitTimeout(this->fakeCond, this->fakeMutex, timeToWait);
    //pthread_mutex_unlock(&this->fakeMutex);
    SDL_UnlockMutex(this->fakeMutex);
    //printf("\nDone\n");
}


void SoundEngine::SetMasterVolume(float volume)
{
    this->masterVolume = Ogre::Math::Clamp(0.0f, 1.0f, volume);
    AL_CHECK( alListenerf(AL_GAIN, this->masterVolume) );
}

void SoundEngine::VolumeUp(float amount)
{
    this->SetMasterVolume(this->masterVolume + amount);
}

void SoundEngine::VolumeDown(float amount)
{
    this->SetMasterVolume(this->masterVolume - amount);
}


SoundObject * SoundEngine::GetSound(const std::string & name)
{
    if (!this->ExistSound(name))
    {
        return NULL;
    }

    return this->sounds[name];
}

bool SoundEngine::ExistSound(const std::string & name) const
{
    logMsg("Attempting to find sound!");
    logMsg("Name = " +name);
//    logMsg("sounds size = " +Ogre::StringConverter::toString(sounds.size()));
//    if (this->sounds.find(name) == this->sounds.end())
    {
        logMsg("found?");
        return false;
    }

    return true;
}

void SoundEngine::ReleaseSound(const std::string & name)
{
    if (!this->ExistSound(name))
    {
        return;
    }

    this->sounds[name]->Stop();
//    SAFE_DELETE(this->sounds[name]);
    this->sounds.erase(this->sounds.find(name));
}

void SoundEngine::AddSound(const std::string & fileName, const std::string & name)
{
    logMsg("checks if sound exists!");
    if (this->ExistSound(name))
    {
        logMsg("Sound with name %s already exist." + name);
        return;
    }
    logMsg("Creating new sound object!");
    SoundObject * soundObj = new SoundObject(fileName, name);
    logMsg("created new sound object!");
    this->sounds.insert(std::make_pair(name, soundObj));
    logMsg("Inserted new sound object!");
    //sound->Play();
}

void SoundEngine::AddSound(SoundObject * sound)
{

    std::string name = sound->GetSettings().name;
    if (this->ExistSound(name))
    {
        logMsg("Sound with name %s already exist." + name);
        return;
    }

    this->sounds.insert(std::make_pair(name, sound));

    //sound->Play();
}


SoundSource * SoundEngine::GetFreeSource()
{
    if (this->freeSources.size() == 0)
    {
        return NULL;
    }

    SoundSource * source = this->freeSources.front();
    this->freeSources.pop_front();
    source->free = false;

    return source;
}


SoundBuffer * SoundEngine::GetFreeBuffer()
{
    logMsg("GetSoundBuffer()");
    if (this->freeBuffers.size() == 0)
    {
        logMsg("No free buffers!");
        return NULL;
    }

    logMsg("Creating buffer!");
    SoundBuffer * buf = this->freeBuffers.front();
    logMsg("pop nee buffer to the front!");
    this->freeBuffers.pop_front();
    logMsg("buf->free = false!");
    buf->free = false;

    return buf;
}


void SoundEngine::FreeSource(SoundSource * source)
{
    if (source == NULL)
    {
        return;
    }
    source->free = true;
    this->freeSources.push_back(source);
}

void SoundEngine::FreeBuffer(SoundBuffer * buffer)
{
    if (buffer == NULL)
    {
        return;
    }
   
    AL_CHECK( alDeleteBuffers(1, &buffer->refID) );
    AL_CHECK( alGenBuffers(1, &buffer->refID) );
    
    buffer->free = true;
    this->freeBuffers.push_back(buffer);    
}


void SoundEngine::Update()
{
    if (this->useThreadUpdate == false)
    {
        logMsg("this->ThreadUpdate();");
        this->ThreadUpdate();
    }
}

void SoundEngine::ThreadUpdate()
{
    logMsg("ThreadUpdate!");
    if (this->enabled == false)
    {
        //return;
    }

    logMsg("iterator");
    std::unordered_map<std::string, SoundObject *>::iterator it;
    logMsg("for loop");
    for (it = this->sounds.begin(); it != this->sounds.end(); it++)
    {
        logMsg("IsPlaying");
        if (it->second->IsPlaying())
        {
            it->second->Update();
        }
    }
}

