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

//Base class for a scrolling background


#include "ScrollingBackGround.h"
#include "../MainApp.h"

//Default set things to null or 0
ScrollingBackGround::ScrollingBackGround(void)
{
	BackGroundTextures = NULL;
	BackGroundRects = NULL;
	numberOfBackgrounds= 0 ;
	Direction = Right;
	maxSpeed = 0;


}

//Construct with data
ScrollingBackGround::ScrollingBackGround(char* BaseBackGroundFile, char** MovingBackGroundFiles,  int numberOfBackgrounds, ScrollDirection setDirecton, int speed)
{
	LoadEnvirement(BaseBackGroundFile, MovingBackGroundFiles, numberOfBackgrounds, Direction, speed);
}

//use provided paramaters to set up the scrolling background envirement
bool ScrollingBackGround::LoadEnvirement(char* BaseBackGroundFile, char** MovingBackGroundFiles, int numberOfBackgrounds, ScrollDirection setDirecton, int speed)
{
	//Environment(BaseBackGroundFile);

	//Allocate memory for all backGround Pannels;
	BackGroundRects = new SDL_Rect[numberOfBackgrounds];
	BackGroundTextures = new SDL_Texture*[numberOfBackgrounds] ;
	this->Direction = setDirecton;
	this->numberOfBackgrounds = numberOfBackgrounds;
	maxSpeed = currentSpeed = speed;



	for(int i = 0; i < numberOfBackgrounds; ++i)
	{
		if((BackGroundTextures[i] =  MainApp::Instance()->GetMainRenderTarget()->LoadTexture(MovingBackGroundFiles[i])) == NULL)
		{
			return true;
		}

		SDL_QueryTexture(BackGroundTextures[i], NULL,NULL, &BackGroundRects[i].w, &BackGroundRects[i].h);

		switch (Direction)
		{
			case Up:
				BackGroundRects[i].x = 0;
				BackGroundRects[i].y = BackGroundRects[i].h * i;
				break;
			case Down:
				BackGroundRects[i].x = 0;
				BackGroundRects[i].y = BackGroundRects[i].h * -i;
				break;
			case Left:
				BackGroundRects[i].x = BackGroundRects[i].w * -i;
				BackGroundRects[i].y = 0;
				break;
			case Right:
				BackGroundRects[i].x = BackGroundRects[i].w * i;
				BackGroundRects[i].y = 0;
				break;
			default:
				break;
		}

	}

	return false;


}

//based on our scrolling state update appropate scroll
void ScrollingBackGround::UpDate()
{
	switch (Direction)
	{
		case Up:
			ScrollUp();
			break;
		case Down:
			ScrollDown();
			break;
		case Left:
			ScrollLeft();
			break;
		case Right:
			ScrollRight();
			break;
		default:
			break;
	}


}

//Scrolls the background up
void ScrollingBackGround::ScrollUp()
{
	for(int i = 0 ; i< numberOfBackgrounds; ++i)
	{
		BackGroundRects[i].y -= currentSpeed;

        //if a pannel is now off screen above
        //it goes to the end at the bottom.
		if(BackGroundRects[i].y < -WHEIGHT)
		{
			BackGroundRects[i].y = ((numberOfBackgrounds-1) * BackGroundRects[i].h) - currentSpeed;
		}
	}

}

//scrolls background down
void ScrollingBackGround::ScrollDown()
{
	for(int i= 0 ; i< numberOfBackgrounds; ++i)
	{
		BackGroundRects[i].y += currentSpeed;


		if(BackGroundRects[i].y > WHEIGHT)
		{
			BackGroundRects[i].y = (((numberOfBackgrounds-1) * BackGroundRects[i].h) * -1) + currentSpeed;
		}
	}
}

//Scrolls background down
void ScrollingBackGround::ScrollLeft()
{
	for(int i= 0 ; i< numberOfBackgrounds; ++i)
	{
		BackGroundRects[i].x -= currentSpeed;


		if(BackGroundRects[i].x < -WWIDTH)
		{
			BackGroundRects[i].x = ((numberOfBackgrounds-1) * BackGroundRects[i].w) - currentSpeed;
		}
	}

}

//Scrolls background right
void ScrollingBackGround::ScrollRight()
{
	for(int i = 0 ; i< numberOfBackgrounds; ++i)
	{
		BackGroundRects[i].x += currentSpeed;


		if(BackGroundRects[i].x > WWIDTH)
		{
			BackGroundRects[i].x = (((numberOfBackgrounds-1) * BackGroundRects[i].w) * -1) + currentSpeed;
		}
	}

}

//Draws Bakgrounf Pannels.
void ScrollingBackGround::Render(MainRender	&theRenderer)
{
	for(int i= 0 ; i< numberOfBackgrounds; ++i)
    {

        //Checks if any part is visible on screen
        //if it is then we draw it.
		if(((BackGroundRects[i].x > -WWIDTH) && (BackGroundRects[i].x < WWIDTH)) && ((BackGroundRects[i].y > -WHEIGHT)&&(BackGroundRects[i].y < WHEIGHT)) )
		{
			theRenderer.Draw(BackGroundTextures[i],BackGroundRects[i].x,BackGroundRects[i].y);
		}
	}
}

void ScrollingBackGround::Cleanup()
{

	for(int i=0; i<numberOfBackgrounds; ++i)
	{
		if(BackGroundTextures[i])
		{
			SDL_DestroyTexture(BackGroundTextures[i]);
		}
	}

	delete []BackGroundRects;
	delete []BackGroundTextures;
}

//if level has things we need to check if we collide with
//this would be where we do it.
void ScrollingBackGround::CheckCollision()
{

}


ScrollingBackGround::~ScrollingBackGround(void)
{
}
