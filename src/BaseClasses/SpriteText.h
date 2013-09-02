#ifndef SPRITETEXT_H
#define SPRITETEXT_H


#include <SDL2/SDL_ttf.h>
#include <string>
#include "../Renderer/MainRender.h"

const SDL_Color DefualtColor = {255,255,255}; 

class SpriteText
{
    public:
        SpriteText();
        SpriteText(char* fontTTFFile, char* StartText = "", unsigned int fontSize = 12, int positionX = 0, int positionY =0, SDL_Color Color = DefualtColor);
        bool LoadSpriteText(char* fontTTFFile, char* StartText = "", unsigned int fontSize = 12, int positionX = 0, int positionY =0, SDL_Color Color = DefualtColor);
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

