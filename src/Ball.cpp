#include "Ball.hpp"

void    Ball::loadTexture( int x, int y, int width, int height, std::string ID )
{
    GameObject::loadTexture( x, y, width, height, ID );
}

void    Ball::draw( SDL_Renderer *renderer )
{
    this->position.setX(10);
    this->position.setY(10);
    radius = 20;
    SDL_Rect rect;

    rect.x = this->position.getX() - radius;
    rect.y = this->position.getY() - radius;
    rect.w = radius * 2;
    rect.h = radius * 2;
    SDL_SetRenderDrawColor( renderer, 255, 0, 0, 0);
    SDL_RenderFillRect( renderer, &rect );
}

void    Ball::update( void )
{
    this->frame = int(((SDL_GetTicks() / 100) % 6));
    // acceleration.setX(1);
    GameObject::update();
    velocity.setX(0);
}