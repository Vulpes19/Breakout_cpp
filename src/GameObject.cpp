#include "GameObject.hpp"

void    GameObject::loadTexture( int x, int y, int width, int height, std::string ID )
{
    this->x = x;
    this->y = y;
    this->w = width;
    this->h = height;
    this->texture = ID;
    frame = 1;
    row = 1;
}