#ifndef PONGBALL_H
#define PONGBALL_H

#include "BaseClasses/SpriteAnimation.h"


class PongBall: public SpriteAnimation
{
    public:
        PongBall();

        void OnLoop();

        int* getVelocity();

        void setVelocity(int newVx, int newVy);

        SDL_Rect* GetCollisionRect();

        virtual ~PongBall();
    protected:
        SDL_Rect collisionRect;
        int velocity[2];
    private:
};

#endif // PONGBALL_H
