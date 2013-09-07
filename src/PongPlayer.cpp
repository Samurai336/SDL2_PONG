#include "PongPlayer.h"

PongPlayer::PongPlayer()
{
    //ctor
}

bool PongPlayer::Load(SDL_Color setColor, int x, int y, unsigned int Width, unsigned int Height)
{

    PlayerColor = setColor;
    collisionRect.x = X = y;
    collisionRect.y = Y = x;
    collisionRect.w = width  = Width;
    collisionRect.h = height = Height;
}



void PongPlayer::OnLoop()
{
    collisionRect.x = X;
    collisionRect.y = Y;
}


SDL_Rect *PongPlayer::GetCollisionRect()
{
    return &collisionRect;
}

void PongPlayer::OnRender(MainRender	&theRenderer)
{

    theRenderer.Draw(X,Y,width,height,PlayerColor);
}

void PongPlayer::OnCleanup()
{

}

PongPlayer::~PongPlayer()
{
    //dtor
}
