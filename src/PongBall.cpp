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

#include "PongBall.h"

PongBall::PongBall()
{
    SpriteAnimation();
    frameChange = false;
    roatationRate = 1;

    //ctor
}

void PongBall::OnLoop()
{
    //did we hit our update time?
    if((SDL_GetTicks() > (LastUpDate + Rate)))
    {

        //update its positon based on velocity
        X += velocity[0];
        Y += velocity[1];


        //Update our collision rect accordingly
        collisionRect.x = X;
        collisionRect.y = Y;
        collisionRect.w = Sprite_Rect.w;
        collisionRect.h = Sprite_Rect.h;

        //update our sprite rect
        Sprite_Rect.x = (currentColumn-1) * Sprite_Rect.w;
        Sprite_Rect.y = (currrentRow-1) * Sprite_Rect.h;


        //update our toat
        rotation += roatationRate;

        //if where at 361 set it back to 0
        if(rotation > 360)
        {
            rotation -= 360;
        }//if where at 0 set it back to -1
        else if(rotation < 0)
        {
            rotation += 360;
        }

    }

    //if we changed frames
    if(frameChange)
    {
        uint32_t currentTime = SDL_GetTicks();

        //check if it time to set it back to the default
        if(currentTime > frameShowCount)
        {
            frameChange = false;
            currentColumn = 1;
        }
    }

    //call our parents loop
    SpriteAnimation::OnLoop();
}

//Tell the ball it hit something
void PongBall::PongBallWasHit()
{
    //Pick a random frame thats not the default
    currentColumn = (rand() % 3+2);

    //set time to show fram til;
    frameShowCount = SDL_GetTicks() + DISPLAY_FRAME_FOR;
    frameChange = true; //check if we need to go back to default frame sentinal

    //Random rotation rate change
    roatationRate = (rand() % 10);

    //random direction
    if((rand() % 10+1)%2)
    {
        roatationRate *= -1;
    }

}

//Set our velocity
void PongBall::setVelocity(int newVx, int newVy)
{
    velocity[0] = newVx;
    velocity[1] = newVy;

}


//Get out velocity
int* PongBall::getVelocity()
{

    return velocity;

}

//Rest to start roatation
void PongBall::ResetRotation()
{

    rotation = 0;

}

void PongBall::OnCleanup()
{
    SpriteAnimation::OnCleanup();
}

//Draw our sprite frame
void PongBall::OnRender(MainRender	&theRenderer)
{
    theRenderer.Draw(this->unitTexture, X, Y, Sprite_Rect, rotation);
}

//Get our collision rect
SDL_Rect *PongBall::GetCollisionRect()
{
    return &collisionRect;
}

PongBall::~PongBall()
{
    //dtor
}
