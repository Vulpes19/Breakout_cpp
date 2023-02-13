#include "ParticleSystem.hpp"
#include "TextureManager.hpp"

void    Particles::init( float x, float y )
{
    position.setX(x);
    position.setY(y);
    velocity.setX( 0.2f );
    velocity.setY( 0.2f );
    life = rand() % 5;
}

void    Particles::update( void )
{
    position.setX(position.getX() + velocity.getX());
    position.setY(position.getY() + velocity.getY());
    life--;
}

void    Particles::render( SDL_Renderer *renderer )
{
    Texture::getInstance().draw("effect", position.getX(), position.getY(), 5, 5, renderer);
    // SDL_RenderDrawPoint(renderer, position.getX(), position.getY());
}