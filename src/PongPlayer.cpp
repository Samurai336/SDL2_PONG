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


#include "PongPlayer.h"

PongPlayer::PongPlayer()
{
    //ctor
}

//Load out player and set his default location
bool PongPlayer::Load(SDL_Color setColor, int x, int y, unsigned int Width, unsigned int Height)
{

    PlayerColor = setColor;
    collisionRect.x = X = y;
    collisionRect.y = Y = x;
    collisionRect.w = width  = Width;
    collisionRect.h = height = Height;

    score = 0;
	

	return true; 
}


//Update the collision rects position
void PongPlayer::OnLoop()
{
    collisionRect.x = X;
    collisionRect.y = Y;
}

//Return the address of the collision rect
SDL_Rect *PongPlayer::GetCollisionRect()
{
    return &collisionRect;
}

//Draw out player
void PongPlayer::OnRender(MainRender	&theRenderer)
{

    theRenderer.Draw(X,Y,width,height,PlayerColor);
}

//Increase his score
void PongPlayer::IncreaseScore()
{
    score++;
}


//return pplayers current score
int PongPlayer::GetCurrentScore()
{

    return score;
}

void PongPlayer::OnCleanup()
{

}

PongPlayer::~PongPlayer()
{
    //dtor
}
