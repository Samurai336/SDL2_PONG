#include "FrameRateController.h"


FrameRateController::FrameRateController(void)
{

	TargetHertz = 60;
	OldTime = 0;
	LastTime = 0;

	NumFrames =0 ;
	Frames = 0 ;

	maxHzHit = false;



}

FrameRateController::FrameRateController(unsigned int TargetHz)
{
	TargetHertz = TargetHz;
	OldTime = 0;
	LastTime = 0;

	NumFrames =0 ;
	Frames = 0 ;

	maxHzHit = false;
}


FrameRateController::~FrameRateController(void)
{

}


void FrameRateController::OnLoop()
{
    uint32_t currentTime = SDL_GetTicks();
    if( (currentTime-OldTime) > (1000/TargetHertz))
    {
        OldTime = SDL_GetTicks();
        Frames++;
        maxHzHit = false;
    }
    else
    {

        maxHzHit = true;
    }

    if((currentTime - FPSTime) > 1000)
    {
        FPSTime= SDL_GetTicks();
        NumFrames = Frames ;
        Frames = 0;
    }


	LastTime = SDL_GetTicks();

}

bool FrameRateController::TargetRateHit()
{
	OnLoop();

	return maxHzHit;
}

int FrameRateController::GetFPS()
{
    if(NumFrames == 0)
    {
        return 0;
    }
    else
    {
        return   (NumFrames);
    }

}

int	FrameRateController::GetTargetHerz()
{
	return TargetHertz;
}

void FrameRateController::SetTargetHz(unsigned int targetRate)
{
	TargetHertz = targetRate;
}

void FrameRateController::Render()
{

}
