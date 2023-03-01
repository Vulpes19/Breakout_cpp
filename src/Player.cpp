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
 * Player.cpp: 
 * 
 * =========================================================
 */

#include "InputHandling.hpp"
#include "Game.hpp"

void    Player::loadTexture( int x, int y, int width, int height, std::string ID )
{
    GameObject::loadTexture( x, y, width, height, ID );
}

void    Player::draw( SDL_Renderer *renderer, bool brightness )
{
    GameObject::draw( renderer, brightness );
}

void    Player::handleInput( void )
{
    if (InputHandler::getInstance().isKeyPressed(SDL_SCANCODE_RIGHT) || InputHandler::getInstance().isKeyPressed(SDL_SCANCODE_D))
    {
        if ( position.getX() + 100 >= WIDTH )
            return ;
        velocity.setX(14);
    }
    if (InputHandler::getInstance().isKeyPressed(SDL_SCANCODE_LEFT) || InputHandler::getInstance().isKeyPressed(SDL_SCANCODE_A))
    {
        if ( position.getX() <= 0 )
            return ;
        velocity.setX(-14);
    }
}

void    Player::update( void )
{
    // this->frame = int(((SDL_GetTicks() / 100) % 6));
    GameObject::update();
    velocity.setX(0);
}