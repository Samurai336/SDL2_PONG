#ifndef BASESOUND_H
#define BASESOUND_H

#include <SDL2_mixer/SDL_mixer.h>

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
