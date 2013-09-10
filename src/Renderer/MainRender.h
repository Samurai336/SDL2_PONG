/*********************************************************************************
**  Copyright 2013 Eric Basile 												  	**
**  																			**
**  This file is part of Henry Hudson's Revenge. A Cross Platform project,      **
**  also Known as HHR_X and referd to as such thoughout.						**
**  																			**
**  HHR_X is free software: you can redistribute it and/or modify			  	**
**  it under the terms of the GNU General Public License as published by		**
**  the Free Software Foundation, either version 3 of the License, or		  	**
**  (at your option) any later version.										  	**
**  																			**
**  HHR_X is distributed in the hope that it will be useful,					**
**  but WITHOUT ANY WARRANTY; without even the implied warranty of			  	**
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the			  	**
**  GNU General Public License for more details.								**
**  																			**
**  You should have received a copy of the GNU General Public License		  	**
**  along with HHR_X.  If not, see <http://www.gnu.org/licenses/>.			  	**
**  																			**
**********************************************************************************/

#pragma once

#include <SDL2/SDL.h>
#ifdef APPLE
#include <SDL2_image/SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif

#include "../Define.h"

#include "FrameRateController.h"



class MainRender
{

	public:

		SDL_Texture* LoadTexture(char* File);
		SDL_Texture* CreateTextureFromSurface(SDL_Surface*);


	public:

		MainRender(void);

		bool InitRenderer(SDL_Window*);

		bool Draw(SDL_Texture* theTexture, int X, int Y, double rotation = 0.0);
		bool Draw(SDL_Texture* theTexture, int X, int Y, int X2, int Y2, int W, int H, double rotation = 0.0);
		bool Draw(SDL_Texture* theTexture, int X, int Y, SDL_Rect &Src_Rect, double rotation = 0.0);
		bool Draw(int X, int Y, int W, int H, SDL_Color &Color, double rotation = 0.0);







		FrameRateController FrameRateControl;


		void CreateDisplayRect();

        void RenderDisplay();

		void Clean();
		//static SDL_Texture *OnLoad(char *filePath, SDL_Renderer *MainRenderer);


	private:
		SDL_Renderer*       Renderer;




};

