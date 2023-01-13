#include "Ball.hpp"

void    Ball::loadTexture( int x, int y, int width, int height, std::string ID )
{
    GameObject::loadTexture( x, y, width, height, ID );
}

void    Ball::draw( SDL_Renderer *renderer )
{
    GameObject::draw( renderer );
}

void    Player::update( void )
{
    this->frame = int(((SDL_GetTicks() / 100) % 6));
    // acceleration.setX(1);
    GameObject::update();
    velocity.setX(0);
}