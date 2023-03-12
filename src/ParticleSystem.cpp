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
 * ParticleSystem.cpp by Vulpes19
 * 
 * =========================================================
 */


#include "ParticleSystem.hpp"
#include "TextureManager.hpp"

void    Particles::init( float x, float y )
{
	position.setX(x);
	position.setY(y);
	velocity.setX(((float)rand() / RAND_MAX) * (1.0f - (-1.0f)) + (-1.0f));
	velocity.setY( 1.0f );
	life = 2;
}

void    Particles::update( void )
{
	position.setX(position.getX() + velocity.getX());
	position.setY(position.getY() + velocity.getY());
	life--;
}

void    Particles::render( SDL_Renderer *renderer )
{
	Texture::getInstance().draw("effect", position.getX(), position.getY(), 5, 5, renderer, false);
}

int     Particles::getLife( void ) const { return (life); }

void	Particles::killParticles( void ) { life = 0; };