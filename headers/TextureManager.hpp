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
 * TextureManager.hpp by Vulpes19
 * 
 * =========================================================
 */


#pragma once

#include <iostream>
#include <map>
#include <SDL.h>
#include <SDL_image.h>

class Texture
{
    public:
        static Texture   &getInstance( void );
        bool    loadImage( std::string fileName, std::string ID, SDL_Renderer *renderer );
        void    draw( std::string ID, int x, int y, int width, int height, SDL_Renderer *renderer, bool brightness );
        void    getDarkTextures( SDL_Texture *texture, int width, int height, SDL_Renderer *renderer );
        // void    drawFrame( std::string ID, int x, int y, int width, int height, int row, int frame, SDL_Renderer *renderer );
    private:
        Texture( void );
        ~Texture( void ) {};
        static Texture    *instancePtr;
        std::map<std::string, SDL_Texture *> textures;
        SDL_Texture *darkTexture;
};
