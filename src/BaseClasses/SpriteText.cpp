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


#include "SpriteText.h"


//Default constructor
SpriteText::SpriteText() :theText(""), textSprite(NULL), fontFile(NULL)
{
	TextColor = TextColor;

    TextDisplayRect.x = TextDisplayRect.y = TextDisplayRect.h = TextDisplayRect.w  = 0;

    needsUpdate = false;

    currentFontFile= "";


    //ctor
}

//Construtor with what we want
SpriteText::SpriteText( char* fontTTFFile, char* StartText, unsigned int fontSize, int positionX , int positionY, SDL_Color Color)
{
    LoadSpriteText(fontTTFFile, StartText, fontSize, positionX, positionY, Color);


}

//Load information to create our Sprite Text information
bool SpriteText::LoadSpriteText( char* fontTTFFile, char* StartText, unsigned int fontSize, int positionX, int positionY, SDL_Color Color)
{
    //Check if loading our TTF font file.
    if((fontFile = TTF_OpenFont( fontTTFFile, fontSize ))==NULL)
    {
        return false;
    }

    currentFontFile = fontTTFFile;

    theText = StartText;
    textFontSize = fontSize;
    TextDisplayRect.x = positionX;
    TextDisplayRect.y = positionY;
    TextColor = Color;

    needsUpdate = true;

    return true;
}

//Over loaded equals for setting the text value
void SpriteText::operator=(const char*newText)
{
    theText = newText;
	needsUpdate = true; // when we render we now know we need to create a new texture
}

void SpriteText::setX(int X)
{

    TextDisplayRect.x = X;//set text X position

}

void SpriteText::setY(int Y)
{

    TextDisplayRect.y = Y;//setX Y positon
}

//sets both X and Y
void SpriteText::setPosition(int x, int y)
{
    setX(x);
    setY(y);
}

//Set Font color
//
void SpriteText::setColor(SDL_Color newFontColor)
{
    TextColor=newFontColor;
    needsUpdate = true;
}

//chang font
bool SpriteText::setFont(char* fontPath)
{

    if((fontFile = TTF_OpenFont( fontPath, textFontSize )) == NULL)
    {
        return false;
    }

    TTF_CloseFont( fontFile );
    currentFontFile = fontPath;
    needsUpdate = true;

    return true;

}

//set font size.
void SpriteText::setFontSize(unsigned int newSize)
{
    textFontSize = newSize;

    fontFile = TTF_OpenFont( currentFontFile.c_str(), textFontSize );

    needsUpdate = true;

}

//change the font text.
void SpriteText::UpDateText(char* newText)
{
    theText = newText;
    needsUpdate = true;


}

//Creates new texture to display
void SpriteText::UpdateSpriteTexture(MainRender &theRenderer)
{

    //create a surface with you text font and cont color
    SDL_Surface *surfSpriteText = TTF_RenderText_Solid(fontFile, theText.c_str(), TextColor);

    // DIstroy the old one
    SDL_DestroyTexture(textSprite);

    //create a new Texture from the serface
    textSprite = theRenderer.CreateTextureFromSurface(surfSpriteText );

    //Get its new wigth and Height
    SDL_QueryTexture(textSprite, NULL, NULL, &width, &height);

}

//When we want to draw it.
void SpriteText::OnRender(MainRender &theRenderer)
{
    //Do we need to update the texter we are drawing
    if(needsUpdate == true)
    {
        UpdateSpriteTexture(theRenderer);
        needsUpdate = false;
    }

    //Draw the texture.
    theRenderer.Draw(textSprite, TextDisplayRect.x-(width/2), TextDisplayRect.y - (height/ 2 ));

}

//close the font file  and delete display
void SpriteText::OnCleanup()
{
    SDL_DestroyTexture(textSprite);
    TTF_CloseFont( fontFile );
}

SpriteText::~SpriteText()
{
    //dtor
}
