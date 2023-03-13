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
 * Particle.hpp by Vulpes19
 * 
 * =========================================================
 */


#pragma once

#include <iostream>
#include <SDL.h>
#include "Vector.hpp"

class Particle
{
    public:
        void    init( float x, float y );
        void    update( void );
        void    render( SDL_Renderer *renderer );
        int     getLife( void ) const;
        void    kill( void );
    private:
        Vector position;
        Vector velocity;
        int life;
};