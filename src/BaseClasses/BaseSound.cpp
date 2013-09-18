#include "BaseSound.h"
/*********************************************************************************
**  Copyright 2013 Eric Basile 												  	**
**  																			**
**  This file is part of SDL2_Pong.                                    			**
**  																			**
**  SDL2_Pong is free software: you can redistribute it and/or modify			**
**  it under the terms of the GNU General Public License as published by		**
**  the Free Software Foundation, either version 3 of the License, or		  	**
**  (at your option) any later version.										  	**
**  																			**
**  SDL2_Pong is distributed in the hope that it will be useful,			    **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of			  	**
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the			  	**
**  GNU General Public License for more details.								**
**  																			**
**  You should have received a copy of the GNU General Public License		  	**
**  along with SDL2_Pong.  If not, see <http://www.gnu.org/licenses/>.			**
**  																			**
**********************************************************************************/


//Set our varables to default or Null
BaseSound::BaseSound()
{
    SoundFile = NULL;
    //ctor
}

//consrtuctor for loading a sound file
BaseSound::BaseSound(char* File)
{
    SoundFile = NULL;

    Load(File);
    //ctor
}


//Load a sound file.
bool BaseSound::Load(char* File)
{
    //Return false since the load failed
	SoundFile = Mix_LoadWAV(File);
    //if(() == NULL)
    {
       // return false;
    }


    return true;

}

//remove sound file when we are done
void BaseSound::OnCleanup()
{
    Mix_FreeChunk(SoundFile);
}

// use channel
void BaseSound::Play()
{
    //-1 means use any channel
    //sound file to play
    //loop 0 times (-1 means forever);
    Mix_PlayChannel(-1, SoundFile, 0);
}

BaseSound::~BaseSound()
{
    //dtor
}
