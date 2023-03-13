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
 * Particle.cpp by Vulpes19
 * 
 * =========================================================
 */


#include "Particle.hpp"
#include "TextureManager.hpp"

void    Particle::init( float x, float y )
{
	position.setX(x);
	position.setY(y);
	velocity.setX(((float)rand() / RAND_MAX) * (1.0f - (-1.0f)) + (-1.0f));
	velocity.setY( 1.0f );
	life = 2;
}

void    Particle::update( void )
{
	position.setX(position.getX() + velocity.getX());
	position.setY(position.getY() + velocity.getY());
	life--;
}

void    Particle::render( SDL_Renderer *renderer )
{
	Texture::getInstance().draw("effect", position.getX(), position.getY(), 5, 5, renderer, false);
}

int     Particle::getLife( void ) const { return (life); }

void	Particle::kill( void ) { life = 0; };