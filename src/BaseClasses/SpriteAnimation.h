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


//Base animated sprite class

#ifndef SPRITEANIMATION_H
#define SPRITEANIMATION_H
#pragma once

#include "BaseUnit.h"

class SpriteAnimation: public BaseUnit
{
    public:
        SpriteAnimation(void);
        SpriteAnimation(char* File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop);
        bool CreateAnimatedSprite(char* File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop);
        void SetLoop(bool);
        void SetNumberRow(unsigned int);
        void SetNumberColumn(unsigned int);
        void SetRate(Uint32);
        void OnLoop();
		void OnRender(MainRender	&theRenderer);
		void OnCleanup();
		void  SetPosition(float MoveX, float MoveY);


        virtual ~SpriteAnimation();

    protected:
        SDL_Rect Sprite_Rect;
        unsigned int currrentRow;
        unsigned int currentColumn;
        uint32_t LastUpDate;
        uint32_t Rate;
    private:
        void CalculateSpriteSize();
        unsigned int numberOfColumns;
        unsigned int numberOfRows;

        bool loop;




};

#endif // SPRITEANIMATION_H
