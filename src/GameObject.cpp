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
 * GameObject.cpp: 
 * 
 * =========================================================
 */

#include "GameObject.hpp"

void    GameObject::loadTexture( int x, int y, int width, int height, std::string ID )
{
    position.setX(x);
    position.setY(y);
    this->w = width;
    this->h = height;
    this->texture = ID;
    frame = 1;
    row = 1;
}

void    GameObject::draw( SDL_Renderer *renderer, bool brightness )
{
    Texture::getInstance().draw( texture, (int)position.getX(), (int)position.getY(), w, h, renderer, brightness );
}

void    GameObject::update( void )
{
    position += acceleration;
    position += velocity;
}
