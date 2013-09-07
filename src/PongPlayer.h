#ifndef PONGPLAYER_H
#define PONGPLAYER_H

#include "BaseClasses/BaseUnit.h"
#include "BaseClasses/Events.h"


class PongPlayer:public BaseUnit
{
    public:
        PongPlayer();

		bool Load(SDL_Color setColor, int x, int y, unsigned int Width, unsigned int Height);

		void OnLoop();

		void OnRender(MainRender &theRenderer);

        SDL_Rect GetCollisionRect();

		void OnCleanup();

        virtual ~PongPlayer();
    protected:
    private:
        SDL_Color PlayerColor;
        SDL_Rect collisionRect;
};

#endif // PONGPLAYER_H
