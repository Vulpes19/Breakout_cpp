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
 * ParticlesManager.cpp by Vulpes19
 * 
 * =========================================================
 */
#include "ParticlesManager.hpp"

ParticlesManager::ParticlesManager( size_t size ) : size(size)
{
	particles.reserve(10);
}

ParticlesManager::~ParticlesManager( void )
{
    particles.clear();
}

void    ParticlesManager::initParticles( float x, float y, int w, int h )
{
    for( size_t i = 0; i < size; i++ )
	    particles[i].init( x + w / 2, y + h );
}

void    ParticlesManager::updateParticles( void )
{
    for ( size_t i = 0; i < size; i++ )
    {
        particles[i].update();
        if ( particles[i].getLife() <= 0 )
            particles.pop_back();
    }
}

size_t    ParticlesManager::getSize( void ) const
{
    return ( particles.size() );
}

void    ParticlesManager::renderParticles( SDL_Renderer *renderer )
{
    for ( size_t i = 0; i < size; i++ )
        particles[i].render( renderer );
}

void    ParticlesManager::killParticles( void )
{
    for ( size_t i = 0; i < size; i++ )
        particles[i].kill();
}
