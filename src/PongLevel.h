#ifndef PONGLEVEL_H
#define PONGLEVEL_H


#include "BaseClasses/Events.h"
#include "BaseClasses/Level.h"
#include "PongPlayer.h"
#include "PongBall.h"


#define WHEEL_MOVE_RES 20

class PongLevel: public Level
{
    public:
        PongLevel();
        bool LoadLevel();
        void OnEvent(SDL_Event* Event);
        void OnLoop();
        void OnRender(MainRender	&theRenderer);
        void OnCleanup();



       	void OnMouseWheel(int XWheel, int YWheel);

       	void OnKeyDown(SDL_Keycode  sym,  SDL_Keymod mod, Uint16 unicode);

		void OnKeyUp(SDL_Keycode  sym,  SDL_Keymod mod, Uint16 unicode);

        virtual ~PongLevel();
    protected:

    private:

        void OnWindowBoundsCheck();

        void CollisionChecks ();

        PongBall   Ball;
        PongPlayer Player1;
        PongPlayer Player2;



};

#endif // PONGLEVEL_H
