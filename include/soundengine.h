#ifndef SOUND_H_
#define SOUND_H_

//#include "OgreAL.h"

class SoundSystem
{
    public:

        virtual ~SoundSystem();

        static SoundSystem *Instance();

    virtual bool setup();   // sets up the sound system
    protected:

        SoundSystem();
        SoundSystem(const SoundSystem&);
        SoundSystem& operator= (const SoundSystem&);

    private:

        static SoundSystem *pInstance;
 //       OgreAL::SoundManager *soundMgr;
};

#endif // SOUND_H_
