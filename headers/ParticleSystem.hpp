#pragma once

#include <iostream>
#include <SDL.h>
#include "Vector.hpp"

class Particles
{
    public:
        void    init( float x, float y, int w, int h, char brick );
        void    update( void );
        void    render( SDL_Renderer *renderer );
        int     getLife( void ) const { return (life); };
    private:
        // std::string ID;
        Vector position;
        Vector velocity;
        int life;
};