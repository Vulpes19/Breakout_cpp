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

void    GameObject::draw( SDL_Renderer *renderer )
{
    Texture::getInstance().draw( texture, (int)position.getX(), (int)position.getY(), w, h, renderer );
}

void    GameObject::update( void )
{
    position += acceleration;
    position += velocity;
}
