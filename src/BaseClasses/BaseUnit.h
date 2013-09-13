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


//Base class for textured units.

#ifndef BASEUNIT_H
#define BASEUNIT_H





#include <SDL2/SDL.h>
#include "../Renderer/MainRender.h"




class MainRender;


class BaseUnit
{
		public:
			BaseUnit(void);

			virtual bool Load(char* File);

			virtual void OnLoop();

			virtual void OnRender(MainRender &theRenderer);

			virtual void OnCleanup();

			void  SetPosition(float MoveX, float MoveY);

			float  GetX();
			float  GetY();

            void  SetX(float newX);
			void  SetY(float newY);

			void setRenderOrder(int newRenderOrder) { renderOrder = newRenderOrder; };

			int GetWidth(){return width;}

			int GetHeight(){return height;}

			~BaseUnit(void);

		protected:

			SDL_Texture* unitTexture;

			float X,Y;

			int width, height;

			double rotation;

			int renderOrder;








};

#endif
