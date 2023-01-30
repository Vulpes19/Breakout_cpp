#pragma once

#include <SDL.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "TextureManager.hpp"

#define TILE_SIZE 32
#define GRID_WIDTH 34
#define GRID_HEIGHT 22

class LevelManager
{
    public:
        static LevelManager   &getInstance( void );
        void    readFile( std::string level );
        void    getTexture( SDL_Renderer *renderer );
        void    render( SDL_Renderer *renderer );
        std::vector<std::string> mapGrid;
    private:
        LevelManager( void );
        ~LevelManager( void ) {};
        static LevelManager    *instancePtr;
        std::ifstream levelFile;
};
