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

#include "BaseUnit.h"

//This is here due to circulalr dependency issue.
#include "../MainApp.h"



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


bool BaseUnit::Load(char* File)
{
	 if((unitTexture = MainApp::Instance()->GetMainRenderTarget()->LoadTexture(File)) == NULL)
     {
         return true;
     }

     SDL_QueryTexture(unitTexture, NULL, NULL, &width, &height);

     return false;
}


void BaseUnit::OnLoop()
{

}

float  BaseUnit::GetX()
{

    return X;

}

float  BaseUnit::GetY()
{

    return Y;

}

void  BaseUnit::SetX(float newX)
{
    X = newX;

}

void  BaseUnit::SetY(float newY)
{

    Y = newY;
}

void BaseUnit::OnRender(MainRender	&theRenderer)
{
	theRenderer.Draw(unitTexture, X,Y, rotation);
}

void BaseUnit::OnCleanup()
{
	 if(unitTexture)
	 {
        SDL_DestroyTexture(unitTexture);
	 }

    unitTexture = NULL;
}

void BaseUnit::SetPosition(float MoveX, float MoveY)
{
	X = MoveX - (width/2);
	Y = MoveY - (height/2);
}
