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


#include "MainRender.h"



//Set main renderer to null
MainRender::MainRender(void)
{
	Renderer = NULL;
}

//Creater a render space in the window we where given
bool MainRender::InitRenderer(SDL_Window* windowToRenderTo)
{
    //create the renderer in the window, use first driver to suport flags, use Hardware acceleration
	this->Renderer = SDL_CreateRenderer(windowToRenderTo, -1, SDL_RENDERER_ACCELERATED );






    //if we faild to create the renderer
    //print out why
	if(this->Renderer == NULL)
	{

        printf("SDL Create failed: %s\n", SDL_GetError());


		return false;


	}




#ifdef DEBUG_MODE
        //Display Current render information
        SDL_RendererInfo currentRenderInformation;
        SDL_GetRendererInfo(Renderer, &currentRenderInformation);

        printf("Render Information: name: %s, Flags: %zu \n",currentRenderInformation.name, currentRenderInformation.flags );
#endif // DEBUG_MODE

    	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoothe
        SDL_RenderSetLogicalSize(Renderer,WWIDTH,WHEIGHT );
		SDL_SetRenderDrawBlendMode(Renderer, SDL_BLENDMODE_BLEND);



	return true;
}

//Draw a texture at x,y with a rotation.
bool MainRender::Draw(SDL_Texture* theTexture, int X, int Y, double rotation)
{
	if(theTexture == NULL)
	{
		return false;
	}

	SDL_Rect DestR;

	DestR.x = X;
	DestR.y = Y;


	//should render at default size however will it then
	//tank preformance?
	SDL_QueryTexture(theTexture, NULL,NULL, &DestR.w, &DestR.h);


	SDL_RenderCopyEx(this->Renderer, theTexture, NULL, &DestR, rotation, NULL, SDL_FLIP_NONE);


	return true;

}

//Draw a section of a texture with a rotaton
bool MainRender::Draw(SDL_Texture* theTexture, int X, int Y, int X2, int Y2, int W, int H, double rotation)
{
	if(theTexture == NULL)
	{
		return false;
	}


	SDL_Rect DestR;

	DestR.x = X;
	DestR.y = Y;
	DestR.w = W;
	DestR.h = H;

	SDL_Rect SrcR;

	SrcR.x = X2;
	SrcR.y = Y2;
	SrcR.w = W;
	SrcR.h = H;

	SDL_RenderCopyEx(this->Renderer, theTexture, &SrcR, &DestR, rotation, NULL, SDL_FLIP_NONE);


	return true;

}

//Draw a texture at x,y with a rotation.
bool MainRender::Draw(SDL_Texture* theTexture, int X, int Y, SDL_Rect &Src_Rect, double rotation)
{

    if(theTexture == NULL)
	{
		return false;
	}


	SDL_Rect DestR;

	DestR.x = X;
	DestR.y = Y;
	DestR.w = Src_Rect.w;
	DestR.h = Src_Rect.h;


    SDL_RenderCopyEx(this->Renderer, theTexture, &Src_Rect, &DestR, rotation, NULL, SDL_FLIP_NONE);



	return true;
}

//Draw a filled rect
bool MainRender::Draw(int X, int Y, int W, int H, SDL_Color &Color, double rotation)
{
    SDL_Rect DestR;

	DestR.x = X;
	DestR.y = Y;
	DestR.w = W;
	DestR.h = H;


    SDL_SetRenderDrawColor(this->Renderer, Color.r, Color.g, Color.b, 255);

    SDL_RenderFillRect(this->Renderer, &DestR);

	return true;
}

//Creat our display rect that we will draw too.
//and fill it with what we have been sending to the renderer.
void MainRender::CreateDisplayRect()
{

	SDL_Rect DisplayRect;
	DisplayRect.x = 0;
	DisplayRect.y = 0;
	DisplayRect.w = WWIDTH;
	DisplayRect.h = WHEIGHT;

	//but not above here.
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(Renderer, &DisplayRect);
}

//Display the renderer and then clear it
void MainRender::RenderDisplay()
{

	//rendering can happen here
	SDL_RenderPresent(Renderer);
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
    SDL_RenderClear(Renderer);


	//or it can happen here

}

//Clean up the renderer
void MainRender::Clean()
{
	SDL_DestroyRenderer(this->Renderer);
}

//Load a texture from a file
SDL_Texture* MainRender::LoadTexture(char* File)
{
	return IMG_LoadTexture(Renderer, File);
}

//Create a texture from a surface
SDL_Texture* MainRender::CreateTextureFromSurface(SDL_Surface* surface)
{
    return SDL_CreateTextureFromSurface(Renderer,surface);

}





