#pragma once

#include <SDL.h>
#include <vector>
#include <string>
#include <fstream>

class BricksManager
{
    public:
        BricksManager( void );
        ~BricksManager( void );
        bool    loadLevel( int level );
    private:

};