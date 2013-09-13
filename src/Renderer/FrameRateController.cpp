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


#include "FrameRateController.h"


//Set default values and set default frame target of 60Hz
FrameRateController::FrameRateController(void)
{

	TargetHertz = 60;
	OldTime = 0;
	LastTime = 0;

	NumFrames =0 ;
	Frames = 0 ;

	maxHzHit = false;



}

//construct with a set target Hz
FrameRateController::FrameRateController(unsigned int TargetHz)
{
	TargetHertz = TargetHz;
	OldTime = 0;
	LastTime = 0;

	NumFrames =0 ;
	Frames = 0 ;

	maxHzHit = false;
}

void FrameRateController::OnLoop()
{

    //Have we hit our rate per second cap yet?
    if( (SDL_GetTicks()-OldTime) > (1000/TargetHertz))
    {
        //if Not update the frame tick
        OldTime = SDL_GetTicks();
        Frames++;
        maxHzHit = false;
    }
    else
    {
        //if we did let others know
        maxHzHit = true;
    }

    //Figure out how many frames got drawn over a second
    if((SDL_GetTicks() - FPSTime) > 1000)
    {
        FPSTime= SDL_GetTicks();
        NumFrames = Frames ;
        Frames = 0;
    }


	LastTime = SDL_GetTicks();

}

//update and find out if we reached our target rate
//Permillisecond
bool FrameRateController::TargetRateHit()
{
	OnLoop();

	return maxHzHit;
}

//Get our FPS count
int FrameRateController::GetFPS()
{
    return  (NumFrames);
}

//Get target Hz
int	FrameRateController::GetTargetHerz()
{
	return TargetHertz;
}

//Set target Hz
void FrameRateController::SetTargetHz(unsigned int targetRate)
{
	TargetHertz = targetRate;
}

void FrameRateController::Render()
{

}

FrameRateController::~FrameRateController(void)
{

}
