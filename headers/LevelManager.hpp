#pragma once

#include <SDL.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#define TILE_SIZE 32
#define GRID_WIDTH 34
#define GRID_HEIGHT 22

class LevelManager
{
    public:
        LevelManager( void ) {};
        ~LevelManager( void ) {};
        void    readFile( std::string level );
        // bool    loadLevel( void );
        // void    render( SDL_Renderer *renderer );
        // void    update( void );
    private:
        std::vector<std::vector<std::string>> mapGrid;
        std::ifstream levelFile;
};
