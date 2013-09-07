#include "PongLevel.h"

PongLevel::PongLevel()
{
    //ctor
}

bool PongLevel::LoadLevel()
{
    SDL_Color Player1Color = {255,0,0};
    SDL_Color Player2Color = {0,0,255};

    Player1.Load(Player1Color, 250, 50, 25, 100);
    Player2.Load(Player2Color, 250, 725, 25, 100);

    Ball.CreateAnimatedSprite("Assets/skullPowerUp.png", 1,1, 1, false);

    Ball.SetPosition(400,300);

    Ball.setVelocity(1, 2);

    return true;
}

void PongLevel::OnEvent(SDL_Event* Event)
{
    Events::OnEvent(Event);
}

void PongLevel::OnLoop()
{
    OnWindowBoundsCheck();

    Player1.OnLoop();
    Player2.OnLoop();
    Ball.OnLoop();

    CollisionChecks();
}

void PongLevel::OnRender(MainRender	&theRenderer)
{
    Player1.OnRender(theRenderer);
    Player2.OnRender(theRenderer);
    Ball.OnRender(theRenderer);
}

void PongLevel::OnCleanup()
{
    Player1.OnCleanup();
    Player2.OnCleanup();
    Ball.OnCleanup();
}

void PongLevel::OnMouseWheel(int XWheel, int YWheel)
{
    if(YWheel > 0)
    {
        Player1.SetY(Player1.GetY() + WHEEL_MOVE_RES);
    }
    else if(YWheel < 0)
    {
        Player1.SetY(Player1.GetY() - WHEEL_MOVE_RES);
    }

}

void PongLevel::OnKeyDown(SDL_Keycode  sym,  SDL_Keymod mod, Uint16 unicode)
{
    if(sym == SDLK_DOWN)
    {
        Player2.SetY(Player2.GetY() + 25);
    }
    else if(sym == SDLK_UP)
    {
        Player2.SetY(Player2.GetY() - 25);
    }
}

void PongLevel::OnKeyUp(SDL_Keycode  sym,  SDL_Keymod mod, Uint16 unicode)
{

}

void PongLevel::OnWindowBoundsCheck()
{

    if(Player1.GetY() < 0)
    {
        Player1.SetY(0);
    }
    if (Player1.GetY()> (WHEIGHT - Player1.GetHeight()))
    {
        Player1.SetY(WHEIGHT - Player1.GetHeight());
    }


    if(Player2.GetY() < 0)
    {
        Player2.SetY(0);
    }
    if (Player2.GetY()> (WHEIGHT - Player1.GetHeight()))
    {
        Player2.SetY(WHEIGHT - Player1.GetHeight());

    }


    if(Ball.GetY() < 0 || (Ball.GetY()> (WHEIGHT - Ball.GetHeight())))
    {
       Ball.getVelocity()[1] *= -1 ;
    }
    if(Ball.GetX() < 0 || (Ball.GetX()> (WWIDTH - Ball.GetWidth())))
    {
       Ball.getVelocity()[0] *= -1 ;
    }

}

void PongLevel::CollisionChecks ()
{

    if(SDL_HasIntersection(Player1.GetCollisionRect(), Ball.GetCollisionRect()) || SDL_HasIntersection(Player2.GetCollisionRect(), Ball.GetCollisionRect()))
    {
        Ball.getVelocity()[0] *= -1;
    }

}

PongLevel::~PongLevel()
{
    //dtor
}
