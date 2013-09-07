#include "BaseSound.h"

BaseSound::BaseSound()
{
    SoundFile = NULL;
    //ctor
}

BaseSound::BaseSound(char* File)
{
    SoundFile = NULL;

    Load(File);
    //ctor
}

bool BaseSound::Load(char* File)
{
    if((SoundFile = Mix_LoadWAV(File)) == NULL)
    {
        return false;
    }

    return true;

}

void BaseSound::OnCleanup()
{
    Mix_FreeChunk(SoundFile);
}

void BaseSound::Play()
{
    Mix_PlayChannel(-1, SoundFile, 0);
}

BaseSound::~BaseSound()
{
    //dtor
}
