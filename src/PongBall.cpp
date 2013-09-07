#include "PongBall.h"

PongBall::PongBall()
{
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

    }

    SpriteAnimation::OnLoop();
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
