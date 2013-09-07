#ifndef PONGLEVEL_H
#define PONGLEVEL_H

#include <time.h>

#include "BaseClasses/Events.h"
#include "BaseClasses/Level.h"
#include "BaseClasses/SpriteText.h"
#include "BaseClasses/BaseSound.h"
#include "PongPlayer.h"
#include "PongBall.h"



#define WHEEL_MOVE_RES 20

#define RESET_TIME 2000

#define COUNT_DOWN_TIME 4000

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

        void UpDateCountDown();

        void StartNewMatch();

        void ResetAreina();

        void SetCountDowns();

        PongBall   Ball;
        PongPlayer Player1;
        PongPlayer Player2;
        SpriteText Player1Score;
        SpriteText Player2Score;

        bool        resetMode;
        unsigned int countDown;
        uint32_t    RestTime;
        uint32_t    CountDownTime;
        uint32_t    SecondsCheck;
        int         CoundDownDisplay;
        int         roundXVel, roundYVel;
        SpriteText CountDown;
        BaseSound Boop;
        BaseSound Clap;
        BaseSound CountBeep;
        BaseSound LongBeep;






};

#endif // PONGLEVEL_H
