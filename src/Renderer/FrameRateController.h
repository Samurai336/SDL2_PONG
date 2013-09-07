#pragma once


#include <SDL2/SDL.h>


class FrameRateController
{
	public:
		FrameRateController(void);
		FrameRateController(unsigned int TargetHz);
		virtual ~FrameRateController(void);

		void    OnLoop();

		int     GetFPS();

		int		GetTargetHerz();

		void	SetTargetHz(unsigned int targetRate);

		bool	TargetRateHit();

		void Render();

	private:
		uint32_t     OldTime;
		uint32_t     LastTime;
		uint32_t     FPSTime;

		unsigned int 	TargetHertz;

		int		NumFrames;
		int     Frames;

		bool maxHzHit;





};
