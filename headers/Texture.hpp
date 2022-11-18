#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#define printOut(input) std::cout << input << std::endl
#define printErr(input, func) std::cerr << input << func << std::endl

class Texture
{
    public:
        Texture( const char * );
        ~Texture( void );
        SDL_Texture *getTexture( void ) const { return (texture); };
        void    createTexture( SDL_Renderer *renderer );
    private:
        SDL_Texture *texture;
        SDL_Surface *surface;
};