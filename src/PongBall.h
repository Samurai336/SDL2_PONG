
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


//Games ball

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

        void OnCleanup();

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

    private:
};

#endif // PONGBALL_H
