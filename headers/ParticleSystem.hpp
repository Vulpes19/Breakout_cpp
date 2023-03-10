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
 * ParticleSystem.hpp by Vulpes19
 * 
 * =========================================================
 */


#pragma once

#include <iostream>
#include <SDL.h>
#include "Vector.hpp"

class Particles
{
    public:
        void    init( float x, float y );
        void    update( void );
        void    render( SDL_Renderer *renderer );
        int     getLife( void ) const;
    private:
        // std::string ID;
        Vector position;
        Vector velocity;
        int life;
};