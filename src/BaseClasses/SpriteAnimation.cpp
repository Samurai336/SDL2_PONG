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







#include "SpriteAnimation.h"




//Default all things to 0;
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

//Constructor with information.
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

    //if the load was sucessfull
    bool loadStatus = BaseUnit::Load(File);

    if(loadStatus);
    {
        //set all the other data
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

    //send back the load status
    return loadStatus;



}

//set animation rate
void SpriteAnimation::SetRate(Uint32 newRate)
{
    Rate = newRate;
}

//Set whether we want it to loop or not
void SpriteAnimation::SetLoop(bool Loop)
{
    this->loop = Loop;
}

//set what Animaiton row we want to be
void SpriteAnimation::SetNumberRow(unsigned int rowNumber)
{
    numberOfRows = rowNumber;
    CalculateSpriteSize();
}

//set what column we want the animaton to be on
void SpriteAnimation::SetNumberColumn(unsigned int columnNumber)
{
    numberOfColumns = columnNumber;

    CalculateSpriteSize();
}

//figure out the size of our displaying sprite
void SpriteAnimation::CalculateSpriteSize()
{
    Sprite_Rect.x = Sprite_Rect.y = Sprite_Rect.h = Sprite_Rect.w = 0;

    Sprite_Rect.w = width/numberOfColumns;
    Sprite_Rect.h = height/ numberOfRows;

}

void SpriteAnimation::OnLoop()
{

    //if rate it not 0;
    if(Rate != 0)
    {
        //check if its time to update the frame
        if(SDL_GetTicks() > (LastUpDate + Rate))
        {
            //up date time check counter
            LastUpDate = SDL_GetTicks();

            //set the sprite rect to where it should be
            //based on how many columns and rows we have
            Sprite_Rect.x = (currentColumn-1) * Sprite_Rect.w;
            Sprite_Rect.y = (currrentRow-1) * Sprite_Rect.h;

            //if its on a loop
            if(loop)
            {
                //if where past the max number
                //Go back to column one
                if(currentColumn >= numberOfColumns)
                {
                    currentColumn = 1;
                }//other wise just go to the nex frame
                else
                {
                    currentColumn++;
                }
            }
            else
            {
                //if where not looping
                //and where not on the last frame
                //go to the next frame
                if(currentColumn != numberOfColumns)
                {
                    currentColumn++;
                }
            }
        }
    }


}

void SpriteAnimation::SetPosition(float MoveX, float MoveY)
{
    //sets centered positon based on where the
    //display rect should be
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
