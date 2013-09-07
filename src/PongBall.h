#ifndef PONGBALL_H
#define PONGBALL_H

#include "BaseClasses/SpriteAnimation.h"

#define DISPLAY_FRAME_FOR 500


class PongBall: public SpriteAnimation
{
    public:
        PongBall();

        void OnLoop();

        void OnRender(MainRender	&theRenderer);

        void ResetRotation();

        int* getVelocity();

        void setVelocity(int newVx, int newVy);

        SDL_Rect* GetCollisionRect();

        void PongBallWasHit();

        virtual ~PongBall();
    protected:
        bool frameChange;
        uint32_t frameShowCount;
        SDL_Rect collisionRect;
        int velocity[2];
        int roatationRate;
        int currentRotation;
    private:
};

#endif // PONGBALL_H
