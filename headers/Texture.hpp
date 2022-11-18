#pragma once

#include <SDL.h>
#include <iostream>

class Texture
{
    public:
        Texture( const std::string & );
        ~Texture( void );
    private:
        SDL_Texture *texture;
        SDL_Surface *surface;
};