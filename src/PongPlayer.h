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


//Pong player

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

        SDL_Rect* GetCollisionRect();

        void IncreaseScore();

        int GetCurrentScore();

		void OnCleanup();

        virtual ~PongPlayer();
    protected:
    private:
        SDL_Color PlayerColor;
        SDL_Rect collisionRect;
        unsigned int score;
};

#endif // PONGPLAYER_H
