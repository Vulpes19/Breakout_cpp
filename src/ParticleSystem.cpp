#include "ParticleSystem.hpp"
#include "TextureManager.hpp"

void    Particles::init( float x, float y, int w, int h )
{
    position.setX(x + (rand() % w));
    position.setY(y + (rand() % h));
    velocity.setX( rand() % 4 - 2 );
    velocity.setY( rand() % 4 - 2);
    life = rand() % 3;
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