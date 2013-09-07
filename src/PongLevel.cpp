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

    Ball.CreateAnimatedSprite("Assets/EricHeadSprite64.png", 4,1, 0, false);

    Ball.SetPosition(400,300);

    Ball.setVelocity(0, 0);   //(1, 2);

    Player1Score.LoadSpriteText("Assets/Romanesque_Serif.ttf","0", 75, 300, 50, Player1Color);
    Player2Score.LoadSpriteText("Assets/Romanesque_Serif.ttf","0", 75, 500, 50, Player2Color);

    CountDown.LoadSpriteText("Assets/Romanesque_Serif.ttf","", 120, 400, 300);

    roundXVel = roundYVel = 2;

    Player1Score = "0";
    Player2Score = "0";

    SetCountDowns();

    return true;
}

void PongLevel::SetCountDowns()
{

    CountDown = "Ready!";
    RestTime = SDL_GetTicks() + RESET_TIME;
    CountDownTime = RestTime + COUNT_DOWN_TIME;
    CoundDownDisplay  = 4;
    resetMode = true;

}

void PongLevel::OnEvent(SDL_Event* Event)
{
    Events::OnEvent(Event);
}

void PongLevel::OnLoop()
{
    OnWindowBoundsCheck();

    if(resetMode)
    {
        uint32_t currentTime = SDL_GetTicks();
        if(currentTime > RestTime)
        {
            UpDateCountDown();
        }
    }
    else
    {
        Player1.OnLoop();
        Player2.OnLoop();
        Ball.OnLoop();
    }

    CollisionChecks();
}

void PongLevel::UpDateCountDown()
{
    uint32_t currentTime = SDL_GetTicks();
    if(currentTime > CountDownTime)
    {
        StartNewMatch();
    }
    else
    {
        if(SecondsCheck<currentTime)
        {
            SecondsCheck = currentTime + 1000;
            CoundDownDisplay--;
            char buffer [256];
            int countDownNum = CoundDownDisplay;
            sprintf(buffer,"%d",  countDownNum);
            CountDown =  buffer;

        }
    }



}

void PongLevel::ResetAreina()
{
     Ball.setVelocity(0, 0);
     Ball.SetPosition(400,300);
     SetCountDowns();
}

void PongLevel::StartNewMatch()
{
    srand (time(NULL));

    resetMode = false;

    if((rand() % 10 + 1)%2)
    {
        if(roundXVel>0)
        {
            roundXVel++;
        }
        else
        {
            roundXVel--;
        }

    }
    if((rand() % 10 + 1)%2)
    {
        roundXVel*=-1;
    }
    if((rand() % 10 + 1)%2)
    {
        if(roundYVel>0)
        {
            roundYVel++;
        }
        else
        {
            roundYVel--;
        }
    }
    if((rand() % 10 + 1)%2)
    {
        roundYVel*=-1;
    }


    Ball.setVelocity(roundXVel, roundYVel);

}

void PongLevel::OnRender(MainRender	&theRenderer)
{
    Player1Score.OnRender(theRenderer);
    Player2Score.OnRender(theRenderer);

    Ball.OnRender(theRenderer);

    Player1.OnRender(theRenderer);
    Player2.OnRender(theRenderer);

    if(resetMode)
    {
        CountDown.OnRender(theRenderer);
    }
}

void PongLevel::OnCleanup()
{

    CountDown.OnCleanup();

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
    if((Ball.GetX() + Ball.GetWidth()) < 0)
    {
       Player2.IncreaseScore();
       char buffer[128];
       sprintf(buffer,"%d",Player2.GetCurrentScore());
       Player2Score = buffer;

       ResetAreina();
    }
    else if ((Ball.GetX()> (WWIDTH)))
    {
       Player1.IncreaseScore();
       char buffer[128];
       sprintf(buffer,"%d",Player1.GetCurrentScore());
       Player1Score = buffer;

       ResetAreina();
    }

}

void PongLevel::CollisionChecks ()
{

    if(SDL_HasIntersection(Player1.GetCollisionRect(), Ball.GetCollisionRect()) || SDL_HasIntersection(Player2.GetCollisionRect(), Ball.GetCollisionRect()))
    {
        Ball.PongBallWasHit();
        Ball.getVelocity()[0] *= -1;
    }

}

PongLevel::~PongLevel()
{
    //dtor
}
