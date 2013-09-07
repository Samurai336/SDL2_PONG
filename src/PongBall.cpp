#include "PongBall.h"

PongBall::PongBall()
{
    frameChange = false;
    roatationRate = 1;
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

        currentRotation += roatationRate;

        if(currentRotation > 360)
        {
            currentRotation -= 360;
        }
        else if(currentRotation < 0)
        {
            currentRotation += 360;
        }

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

    roatationRate = (rand() % 10);

    if((rand() % 10+1)%2)
    {
        roatationRate *= -1;
    }



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

void PongBall::ResetRotation()
{

    currentRotation = 0;

}

void PongBall::OnRender(MainRender	&theRenderer)
{
    theRenderer.Draw(this->unitTexture, X, Y, Sprite_Rect, currentRotation);
}


SDL_Rect *PongBall::GetCollisionRect()
{
    return &collisionRect;
}

PongBall::~PongBall()
{
    //dtor
}
