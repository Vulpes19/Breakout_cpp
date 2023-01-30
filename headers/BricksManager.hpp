#pragma once

#include <SDL.h>
#include "LevelManager.hpp"
#include "TextureManager.hpp"
#include <iostream>

class BricksManager : public LevelManager
{
    public:
        void    getTexture( SDL_Renderer *renderer );
        void    render( SDL_Renderer *renderer );
        // void    update( void );
};
