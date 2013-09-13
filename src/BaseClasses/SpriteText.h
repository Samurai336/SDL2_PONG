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

//Wraper for SDL ttf for drawing on screen text

#ifndef SPRITETEXT_H
#define SPRITETEXT_H

#ifdef APPLE
#include <SDL2_ttf/SDL_ttf.h>
#else
#include <SDL2/SDL_ttf.h>
#endif

#include <string>
#include "../Renderer/MainRender.h"

const SDL_Color DefualtColor = {255,255,255};

class SpriteText
{
    public:
        SpriteText();
        SpriteText( char* fontTTFFile, char* StartText = "", unsigned int fontSize = 12, int positionX = 0, int positionY =0, SDL_Color Color = DefualtColor);
        bool LoadSpriteText( char* fontTTFFile, char* StartText = "", unsigned int fontSize = 12, int positionX = 0, int positionY =0, SDL_Color Color = DefualtColor);
        virtual void UpDateText(char* newText);
        void operator=(const char*);
        virtual void OnRender(MainRender &theRenderer);
        void setX(int);
        void setY(int);
        void setPosition(int x, int y);
        void setColor(SDL_Color);
        bool setFont(char* fontPath);
        void setFontSize(unsigned int);
        virtual void OnCleanup();

        virtual ~SpriteText();
    protected:

        void UpdateSpriteTexture(MainRender &theRenderer);
        bool needsUpdate;
        SDL_Texture* textSprite;
        TTF_Font*    fontFile;
        SDL_Rect    TextDisplayRect;
        int         height, width;
        SDL_Color   TextColor;
        std::string currentFontFile;
        unsigned int textFontSize;
        std::string  theText;


    private:
};

#endif // SPRITETEXT_H

