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
    protected:
        std::vector<std::string> mapGrid;
        std::ifstream levelFile;
};
