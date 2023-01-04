#include "Player.hpp"
#include "InputHandling.hpp"

void    Player::loadTexture( int x, int y, int width, int height, std::string ID )
{
    GameObject::loadTexture( x, y, width, height, ID );
}

void    Player::draw( SDL_Renderer *renderer )
{
    GameObject::draw( renderer );
}

void    Player::handleInput( void )
{
    if (InputHandler::getInstance().isKeyPressed(SDL_SCANCODE_RIGHT))
        velocity.setX(10);
    if (InputHandler::getInstance().isKeyPressed(SDL_SCANCODE_LEFT))
        velocity.setX(-10);
}

void    Player::update( void )
{
    this->frame = int(((SDL_GetTicks() / 100) % 6));
    // acceleration.setX(1);
    GameObject::update();
    velocity.setX(0);
}