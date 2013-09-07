#include "PongBall.h"

PongBall::PongBall()
{
    frameChange = false;
    //ctor
}

void PongBall::OnLoop()
{
    if((SDL_GetTicks() > (LastUpDate + Rate)))
    {

        X += velocity[0];
        Y += velocity[1];


        collisionRect.x = X;
        collisionRect.y = Y;
        collisionRect.w = Sprite_Rect.w;
        collisionRect.h = Sprite_Rect.h;

        Sprite_Rect.x = (currentColumn-1) * Sprite_Rect.w;
        Sprite_Rect.y = (currrentRow-1) * Sprite_Rect.h;

    }

    if(frameChange)
    {
        uint32_t currentTime = SDL_GetTicks();

        if(currentTime > frameShowCount)
        {
            frameChange = false;
            currentColumn = 1;
        }
    }

    SpriteAnimation::OnLoop();
}

void PongBall::PongBallWasHit()
{
     currentColumn = (rand() % 3+2);

    frameShowCount = SDL_GetTicks() + DISPLAY_FRAME_FOR;
    frameChange = true;



}

void PongBall::setVelocity(int newVx, int newVy)
{
    velocity[0] = newVx;
    velocity[1] = newVy;

}

int* PongBall::getVelocity()
{

    return velocity;

}


SDL_Rect *PongBall::GetCollisionRect()
{
    return &collisionRect;
}

PongBall::~PongBall()
{
    //dtor
}
