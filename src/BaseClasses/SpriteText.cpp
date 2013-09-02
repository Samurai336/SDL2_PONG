#include "SpriteText.h"

struct something 
{
	int i,j,k; 
};

SpriteText::SpriteText() :theText(""), textSprite(NULL), fontFile(NULL)
{
	//TextColor =  {255, 255, 255}; // This does no work on windows wtf

	TextColor = TextColor; 

	//something mine = {1,2,3}; 

    TextDisplayRect.x = TextDisplayRect.y = TextDisplayRect.h = TextDisplayRect.w  = 0;

    needsUpdate = false;

    currentFontFile= "";


    //ctor
}

SpriteText::SpriteText(char* fontTTFFile, char* StartText, unsigned int fontSize, int positionX , int positionY, SDL_Color Color)
{
    LoadSpriteText(fontTTFFile, StartText, fontSize, positionX, positionY, Color);


}

bool SpriteText::LoadSpriteText(char* fontTTFFile, char* StartText, unsigned int fontSize, int positionX, int positionY, SDL_Color Color)
{
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

void SpriteText::operator=(const char*newText)
{
    theText = newText;
	needsUpdate = true;
}

void SpriteText::setX(int X)
{

    TextDisplayRect.x = X;

}

void SpriteText::setY(int Y)
{

    TextDisplayRect.y = Y;
}

void SpriteText::setPosition(int x, int y)
{
    setX(x);
    setY(y);
}


void SpriteText::setColor(SDL_Color newFontColor)
{
    TextColor=newFontColor;
    needsUpdate = true;
}

bool SpriteText::setFont(char* fontPath)
{

    if((fontFile = TTF_OpenFont( fontPath, textFontSize ))==NULL)
    {
        return false;
    }

    currentFontFile = fontPath;

    return true;

}

void SpriteText::setFontSize(unsigned int newSize)
{
    textFontSize = newSize;

    fontFile = TTF_OpenFont( currentFontFile.c_str(), textFontSize );

    needsUpdate = true;

}


void SpriteText::UpDateText(char* newText)
{
    theText = newText;
    needsUpdate = true;


}
void SpriteText::UpdateSpriteTexture(MainRender &theRenderer)
{


    SDL_Surface *surfSpriteText = TTF_RenderText_Solid(fontFile, theText.c_str(), TextColor);
    SDL_DestroyTexture(textSprite);
    textSprite = theRenderer.CreateTextureFromSurface(surfSpriteText );

    SDL_QueryTexture(textSprite, NULL, NULL, &width, &height);

}


void SpriteText::OnRender(MainRender &theRenderer)
{
    if(needsUpdate == true)
    {
        UpdateSpriteTexture(theRenderer);
        needsUpdate = false;
    }

    theRenderer.Draw(textSprite, TextDisplayRect.x-(width/2), TextDisplayRect.y - (height/ 2 ));

}

void SpriteText::OnCleanup()
{
    SDL_DestroyTexture(textSprite);
    TTF_CloseFont( fontFile );
}

SpriteText::~SpriteText()
{
    //dtor
}
