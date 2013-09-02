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

#include "Environment.h"

#include "../MainApp.h"

Environment::Environment()
{
	BackGroundImage = NULL; 
    //ctor
}

Environment::Environment(char *File)
{
     if((BackGroundImage = MainApp::Instance()->GetMainRenderTarget()->LoadTexture(File)) == NULL)
     {
         return;
     } 
}

bool Environment::LoadEnvirement(char *File)
{
	 if((BackGroundImage = MainApp::Instance()->GetMainRenderTarget()->LoadTexture(File)) == NULL)
     {
         return true;
     }   

     return false;
}

void Environment::Render(MainRender	&theRenderer)
{
	if(BackGroundImage == NULL)
	{
		return; 
	}

	theRenderer.Draw(BackGroundImage,0,0);  
}


Environment::~Environment()
{
    //dtor
}
