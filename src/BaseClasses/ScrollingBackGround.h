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



#pragma once


#include "../Define.h"

#include "../BaseClasses/Environment.h"

enum ScrollDirection
{
    Up = 0,
    Down,
    Left,
    Right

};



class ScrollingBackGround :	public Environment
{
	public:



		ScrollingBackGround(void);

		ScrollingBackGround(char* BaseBackGroundFile, char** MovingBackGroundFiles,  int numberOfBackgrounds, ScrollDirection setDirecton, int speed);

		bool LoadEnvirement(char* BaseBackGroundFile, char** MovingBackGroundFiles,  int numberOfBackgrounds, ScrollDirection setDirecton, int speed);

		void UpDate();

		void Render(MainRender	&theRenderer);

		void Cleanup();

		void CheckCollision();

		virtual ~ScrollingBackGround(void);

	protected:
		void ScrollUp();
		void ScrollDown();
		void ScrollLeft();
		void ScrollRight();
		SDL_Texture **BackGroundTextures;
		SDL_Rect *BackGroundRects;
		unsigned int numberOfBackgrounds;
		ScrollDirection Direction;
		int maxSpeed;
		int currentSpeed;

};

