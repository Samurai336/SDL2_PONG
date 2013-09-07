#ifndef PONGLEVEL_H
#define PONGLEVEL_H


#include "BaseClasses/Events.h"
#include "BaseClasses/Level.h"
#include "PongPlayer.h"

class PongLevel: public Level
{
    public:
        PongLevel();
        bool LoadLevel();
        void OnEvent(SDL_Event* Event);
        void OnLoop();
        void OnRender(MainRender	&theRenderer);
        void OnCleanup();

       	void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);

       	void OnKeyDown(SDL_Keycode  sym,  SDL_Keymod mod, Uint16 unicode);

		void OnKeyUp(SDL_Keycode  sym,  SDL_Keymod mod, Uint16 unicode);

        virtual ~PongLevel();
    protected:

    private:
        PongPlayer Player1;
        PongPlayer Player2;



};

#endif // PONGLEVEL_H
