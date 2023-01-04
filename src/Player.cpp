#include "Player.hpp"

void    Player::loadTexture( int x, int y, int width, int height, std::string ID )
{
    GameObject::loadTexture( x, y, width, height, ID );
}

void    Player::draw( SDL_Renderer *renderer )
{
    GameObject::draw( renderer );
}

void    Player::update( void )
{
    this->frame = int(((SDL_GetTicks() / 100) % 6));
    velocity.setY(1);
    GameObject::update();
}