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
 * ParticlesManager.hpp by Vulpes19
 * 
 * =========================================================
 */
#pragma once

#include "Particle.hpp"
#include <vector>

class ParticlesManager
{
    public:
        ParticlesManager( size_t size );
        ~ParticlesManager( void );
        void    initParticles( float x, float y, int w, int h );
        void    updateParticles( void );
        void    renderParticles( SDL_Renderer *renderer );
        size_t  getSize( void ) const;
        void    killParticles( void );
    private:
        size_t  size;
        std::vector<Particle> particles;
};
