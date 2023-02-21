#include "ParticleSystem.hpp"
#include "TextureManager.hpp"

void    Particles::init( float x, float y, int w, int h, char brick )
{
	(void)w;
	(void)h;
	(void)brick;	
	// if ( brick == '4') ID = "red_brick";
	// if ( brick == '3') ID = "orange_brick";
	// if ( brick == '2') ID = "green_brick";
	// if ( brick == '1') ID = "yellow_brick";
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
	// SDL_RenderDrawPoint(renderer, position.getX(), position.getY());
}