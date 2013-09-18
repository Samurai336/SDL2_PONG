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

#include "PongLevel.h"

PongLevel::PongLevel()
{
    //ctor

	SecondsCheck = 0; 
	CountDownTime = 0; 
	RestTime = 0; 


}

//load out level
bool PongLevel::LoadLevel()
{
    //Our Player colors
    SDL_Color Player1Color = {255,0,0};
    SDL_Color Player2Color = {0,0,255};

    //load our players
    Player1.Load(Player1Color, 250, 50, 25, 100);
    Player2.Load(Player2Color, 250, 725, 25, 100);

    //Load our ball
    Ball.CreateAnimatedSprite("Assets/EricHeadSprite64.png", 4,1, 0, false);

    //Load our sound effects
    Boop.Load("Assets/Sounds/Boop.wav");
    Clap.Load("Assets/Sounds/Clap.wav");
    CountBeep.Load("Assets/Sounds/CountBeep.wav");
    LongBeep.Load("Assets/Sounds/LongBoop.wav");

    //Set ball start position
    Ball.SetPosition(400,300);

    //Set balls start velocity
    Ball.setVelocity(0, 0);   //(1, 2);

    //Load our UI display and text
    Player1Score.LoadSpriteText("Assets/Romanesque_Serif.ttf","0", 75, 300, 50, Player1Color);
    Player2Score.LoadSpriteText("Assets/Romanesque_Serif.ttf","0", 75, 500, 50, Player2Color);
    CountDown.LoadSpriteText("Assets/Romanesque_Serif.ttf","", 120, 400, 300);

    //Round ball valocitys
    roundXVel = roundYVel = 2;

    //Set player start scores
    Player1Score = "0";
    Player2Score = "0";

    //Start our countdown
    SetCountDowns();

    return true;
}

void PongLevel::SetCountDowns()
{
    //Display a message the round will start
    //and set the count down timers
    CountDown = "Ready!";
    RestTime = SDL_GetTicks() + RESET_TIME;
    CountDownTime = RestTime + COUNT_DOWN_TIME;
    CoundDownDisplay  = 4;
    resetMode = true;

}

void PongLevel::OnEvent(SDL_Event* Event)
{
    //Handle events
    Events::OnEvent(Event);
}

void PongLevel::OnLoop()
{
    //Check that nothing left the window bounds
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
            if(CoundDownDisplay == 0)
            {
                LongBeep.Play();
            }
            else
            {
                CountBeep.Play();
            }

        }
    }
}

void PongLevel::ResetAreina()
{
     Clap.Play();
     Ball.ResetRotation();
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
    Clap.OnCleanup();
    CountBeep.OnCleanup();
    LongBeep.OnCleanup();
    Boop.OnCleanup();


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

    //check that player is and stays in screen bounds
    if(Player1.GetY() < 0)
    {
        Player1.SetY(0);
    }
    if (Player1.GetY()> (WHEIGHT - Player1.GetHeight()))
    {
        Player1.SetY(WHEIGHT - Player1.GetHeight());
    }

    //check that player is and stays in screen bounds
    if(Player2.GetY() < 0)
    {
        Player2.SetY(0);
    }
    if (Player2.GetY()> (WHEIGHT - Player1.GetHeight()))
    {
        Player2.SetY(WHEIGHT - Player1.GetHeight());

    }


    //check that ball is in vertical screen bounds
    if(Ball.GetY() < 0 || (Ball.GetY()> (WHEIGHT - Ball.GetHeight())))
    {
       Ball.PongBallWasHit();

       Ball.getVelocity()[1] *= -1 ;
    }

    //if the ball is past a left or right bound award a point and
    //update the display
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
    //Check if the ball has collided with a player.
    if(SDL_HasIntersection(Player1.GetCollisionRect(), Ball.GetCollisionRect()) || SDL_HasIntersection(Player2.GetCollisionRect(), Ball.GetCollisionRect()))
    {
        Boop.Play();
        Ball.PongBallWasHit();
        Ball.getVelocity()[0] *= -1;
    }

}

PongLevel::~PongLevel()
{
    //dtor
}
