/*
 * =========================================================
 *____   ____     ___   ____  __  _   ___   __ __  ______  
 *|    \ |    \   /  _] /    ||  |/ ] /   \ |  |  ||      |
 *|  o  )|  D  ) /  [_ |  o  ||  ' / |     ||  |  ||      |
 *|     ||    / |    _]|     ||    \ |  O  ||  |  ||_|  |_|
 *|  O  ||    \ |   [_ |  _  ||     \|     ||  :  |  |  |  
 *|     ||  .  \|     ||  |  ||  .  ||     ||     |  |  |  
 *|_____||__|\_||_____||__|__||__|\_| \___/  \__,_|  |__|  
 * 
 * TextManager.hpp by Vulpes19
 * 
 * =========================================================
 */


#pragma once

#include <iostream>
#include <map>
#include <deque>
#include <SDL.h>
#include <SDL_ttf.h>

#define MAX_TEXTURES 20
class Text
{
    public:
        static Text &getInstance( void );
        bool    loadFont( const char *fontPath, std::string ID );
        void    writeText( std::string ID, int x, int y, int width,
            int height, SDL_Renderer *renderer, const char *toDisplay, SDL_Color color, std::string state );
    private:
        Text( void );
        ~Text( void );
        static Text  *instancePtr;
        std::map<std::string, TTF_Font *> fonts;
};
