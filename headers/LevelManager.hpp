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
 * LevelManager.hpp by Vulpes19
 * 
 * =========================================================
 */


#pragma once

#include <SDL.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <utility>
#include "TextureManager.hpp"

#define TILE_SIZE_H 32
#define TILE_SIZE_W 64
#define GRID_WIDTH 17
#define GRID_HEIGHT 22

class LevelManager
{
    public:
        static LevelManager   &getInstance( void );
        void    readFile( std::string level );
        void    getTexture( SDL_Renderer *renderer );
        void    render( SDL_Renderer *renderer, bool brightness );
        std::vector<std::string> mapGrid;
    private:
        LevelManager( void );
        ~LevelManager( void ) {};
        static LevelManager    *instancePtr;
        std::ifstream levelFile;
};
