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

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <SDL2/SDL.h> 
#include "../Renderer/MainRender.h"



class Environment
{
    public:
        Environment();
        Environment(char *File);
        ~Environment();

        
		virtual bool LoadEnvirement(char *File); 

		virtual void UpDate(){};

		virtual void Render(MainRender	&theRenderer);

		virtual void Cleanup(){};

		virtual void CheckCollision(){};


    protected:
        SDL_Texture* BackGroundImage;

    private:
};

#endif // ENVIRONMENT_H
