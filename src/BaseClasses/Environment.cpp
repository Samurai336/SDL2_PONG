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

//This is the base class for seting up and interactive envirement

#include "Environment.h"

#include "../MainApp.h"

//set values to null or 0 for default
Environment::Environment()
{
	BackGroundImage = NULL;
    //ctor
}

//Load Base background Image constructor
Environment::Environment(char *File)
{
     if((BackGroundImage = MainApp::Instance()->GetMainRenderTarget()->LoadTexture(File)) == NULL)
     {
         return;
     }
}

//Seprate loading for enviremnt components
bool Environment::LoadEnvirement(char *File)
{
	 if((BackGroundImage = MainApp::Instance()->GetMainRenderTarget()->LoadTexture(File)) == NULL)
     {
         return true;
     }

     return false;
}

//Call to render the envirement
void Environment::Render(MainRender	&theRenderer)
{
	if(BackGroundImage == NULL)
	{
		return;
	}

	theRenderer.Draw(BackGroundImage,0,0);
}

void Environment::Cleanup()
{
    SDL_DestroyTexture(BackGroundImage);
}

Environment::~Environment()
{
    //dtor
}
