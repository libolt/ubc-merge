#include "sound.h"

SoundSystem* SoundSystem::pInstance = 0;
SoundSystem* SoundSystem::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new SoundSystem; // create sole instance
    }
    return pInstance; // address of sole instance
}

SoundSystem::SoundSystem()
{
    setup();
}

SoundSystem::~SoundSystem()
{
}

bool SoundSystem::setup()
{
//    soundMgr = new OgreAL::SoundManager();
//    exit(0);
    return true;
}
