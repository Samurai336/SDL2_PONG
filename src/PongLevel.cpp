#include "PongLevel.h"

PongLevel::PongLevel()
{
    //ctor
}

bool PongLevel::LoadLevel()
{
    SDL_Color Player1Color = {255,0,0};
    SDL_Color Player2Color = {0,0,255};

    Player1.Load(Player1Color, 300, 50, 25, 100);
    Player2.Load(Player2Color, 300, 550, 25, 100);

    return true;

}

void PongLevel::OnEvent(SDL_Event* Event)
{
    Events::OnEvent(Event);
}

void PongLevel::OnLoop()
{
    Player1.OnLoop();
    Player2.OnLoop();
}

void PongLevel::OnRender(MainRender	&theRenderer)
{
    Player1.OnRender(theRenderer);
    Player2.OnRender(theRenderer);
}

void PongLevel::OnCleanup()
{


}

void PongLevel::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle)
{



}

void PongLevel::OnKeyDown(SDL_Keycode  sym,  SDL_Keymod mod, Uint16 unicode)
{


}

void PongLevel::OnKeyUp(SDL_Keycode  sym,  SDL_Keymod mod, Uint16 unicode)
{


}

PongLevel::~PongLevel()
{
    //dtor
}
