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


#include "BaseUnit.h"

//This is here due to circulalr dependency.
#include "../MainApp.h"



//Default constructor sets base valuse to null or zero
BaseUnit::BaseUnit(void)
{

	X = Y = 0.0f;
	unitTexture = NULL;
	rotation = 0.0;
	renderOrder = 1;
	width = 0;
	height =0;

}


BaseUnit::~BaseUnit(void)
{

}

//Load Image asset
bool BaseUnit::Load(char* File)
{
    //return true the Load Faild
	 if((unitTexture = MainApp::Instance()->GetMainRenderTarget()->LoadTexture(File)) == NULL)
     {
         return true;
     }

    //get width and height infor of the texture.
     SDL_QueryTexture(unitTexture, NULL, NULL, &width, &height);

     return false;
}

//This should be overided by a child class
//Based on gameplay or logic
void BaseUnit::OnLoop()
{

}


//Returns X Position
float  BaseUnit::GetX()
{

    return X;

}

//Returns Y Position.
float  BaseUnit::GetY()
{

    return Y;

}

//sets units x Position
void  BaseUnit::SetX(float newX)
{
    X = newX;

}

//Sets units Y position
void  BaseUnit::SetY(float newY)
{

    Y = newY;
}

//Render call to draw the unit.
void BaseUnit::OnRender(MainRender	&theRenderer)
{
	theRenderer.Draw(unitTexture, X,Y, rotation);
}

//DIstroys used texture.
void BaseUnit::OnCleanup()
{
	 if(unitTexture)
	 {
        SDL_DestroyTexture(unitTexture);
	 }

    unitTexture = NULL;
}

//sets positon based on center point.
void BaseUnit::SetPosition(float MoveX, float MoveY)
{
	X = MoveX - (width/2);
	Y = MoveY - (height/2);
}
