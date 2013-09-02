/*********************************************************************************
**  Copyright 2013 Eric Basile 												  	**
**  																			**
**  This file is part of Henry Hudson's Revenge. A Cross Platform project,      **
**  also Known as HHR_X and referd to as such thoughout.						**
**  																			**
**  HHR_X is free software: you can redistribute it and/or modify			  	**
**  it under the terms of the GNU General Public License as published by		**
**  the Free Software Foundation, either version 3 of the License, or		  	**
**  (at your option) any later version.										  	**
**  																			**
**  HHR_X is distributed in the hope that it will be useful,					**
**  but WITHOUT ANY WARRANTY; without even the implied warranty of			  	**
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the			  	**
**  GNU General Public License for more details.								**
**  																			**
**  You should have received a copy of the GNU General Public License		  	**
**  along with HHR_X.  If not, see <http://www.gnu.org/licenses/>.			  	**
**  																			**
**********************************************************************************/






#include "SpriteAnimation.h"





SpriteAnimation::SpriteAnimation(void)
{
    BaseUnit();

    numberOfColumns = 0;
    numberOfRows = 0;
    Rate = 0;
    currrentRow = 1;
    currentColumn = 1;
    loop = false;


    Sprite_Rect.x = Sprite_Rect.y = Sprite_Rect.h = Sprite_Rect.w = 0;

    //ctor
}


SpriteAnimation::SpriteAnimation(char* File, unsigned int Columns, unsigned int Rows, Uint32 rate, bool Loop):
    numberOfColumns(Columns), numberOfRows(Rows), Rate(rate)
{
    BaseUnit();

    BaseUnit::Load(File);


    currrentRow = 0;
    currentColumn = 0;
    loop = Loop;

    CalculateSpriteSize();
}

bool SpriteAnimation::CreateAnimatedSprite(char* File, unsigned int Columns, unsigned int Rows, unsigned int rate, bool Loop)
{

    bool loadStatus = BaseUnit::Load(File);
    if(loadStatus);
    {

        numberOfColumns = Columns;
        numberOfRows = Rows;
        Rate = rate;
        currrentRow = 1;
        currentColumn = 1;
        loop = Loop;

        CalculateSpriteSize();

        LastUpDate = SDL_GetTicks();

        return loadStatus;
    }

    return loadStatus;



}

void SpriteAnimation::SetRate(Uint32 newRate)
{
    Rate = newRate;
}

void SpriteAnimation::SetLoop(bool Loop)
{
    this->loop = Loop;
}

void SpriteAnimation::SetNumberRow(unsigned int rowNumber)
{
    numberOfRows = rowNumber;
    CalculateSpriteSize();
}

void SpriteAnimation::SetNumberColumn(unsigned int columnNumber)
{
    numberOfColumns = columnNumber;

    CalculateSpriteSize();
}

void SpriteAnimation::CalculateSpriteSize()
{
    Sprite_Rect.x = Sprite_Rect.y = Sprite_Rect.h = Sprite_Rect.w = 0;

    Sprite_Rect.w = width/numberOfColumns;
    Sprite_Rect.h = height/ numberOfRows;

}

void SpriteAnimation::OnLoop()
{



    if(SDL_GetTicks() > (LastUpDate + Rate))
    {
        LastUpDate = SDL_GetTicks();

        Sprite_Rect.x = (currentColumn-1) * Sprite_Rect.w;
        Sprite_Rect.y = (currrentRow-1) * Sprite_Rect.h;

        printf("Sprite Update!\n");

        if(loop)
        {
            if(currentColumn >= numberOfColumns)
            {
                currentColumn = 1;
            }
            else
            {
                currentColumn++;
            }
        }
        else
        {
            if(currentColumn != numberOfColumns)
            {
                currentColumn++;
            }
        }
    }


}

void SpriteAnimation::SetPosition(float MoveX, float MoveY)
{
    X = MoveX - (Sprite_Rect.w/2);
	Y = MoveY - (Sprite_Rect.h/2);
}

void SpriteAnimation::OnRender(MainRender	&theRenderer)
{
    theRenderer.Draw(this->unitTexture, X, Y, Sprite_Rect);
}

void SpriteAnimation::OnCleanup()
{

    BaseUnit::OnCleanup();

}



SpriteAnimation::~SpriteAnimation()
{
    //dtor
}
