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
    if (InputHandler::getInstance().isKeyPressed(SDL_SCANCODE_RIGHT) || InputHandler::getInstance().isKeyPressed(SDL_SCANCODE_D))
        velocity.setX(14);
    if (InputHandler::getInstance().isKeyPressed(SDL_SCANCODE_LEFT) || InputHandler::getInstance().isKeyPressed(SDL_SCANCODE_A))
        velocity.setX(-14);
}

void    Player::update( void )
{
    this->frame = int(((SDL_GetTicks() / 100) % 6));
    // acceleration.setX(1);
    // velocity.setX(1);
    // velocity.setY(1);
    GameObject::update();
    velocity.setX(0);
}