#ifndef BASESOUND_H
#define BASESOUND_H

#ifdef APPLE
#include <SDL2_mixer/SDL_mixer.h>
#else
#include <SDL2/SDL_mixer.h>
#endif

class BaseSound
{
    public:
        BaseSound();

        BaseSound(char* File);

      	virtual bool Load(char* File);

      	virtual void OnCleanup();

      	virtual void Play();

        virtual ~BaseSound();
    protected:

    Mix_Chunk* SoundFile;
    private:
};

#endif // BASESOUND_H
