#include "Ball.hpp"
#include "Game.hpp"

void    Ball::loadTexture( int x, int y, int width, int height, std::string ID )
{
    GameObject::loadTexture( x, y, width, height, ID );
}

void    Ball::draw( SDL_Renderer *renderer )
{
    // this->position.setX(WIDTH / 2);
    // this->position.setY(HEIGHT / 2);
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
    // GameObject::update();
    wallCollision();
    velocity += acceleration;
    position += velocity;
    std::cout << "vel.x = " << velocity.getX() << std::endl;
    std::cout << "vel.y = " << velocity.getY() << std::endl;
    // velocity.setX(0);
}

void    Ball::wallCollision( void )
{
    if ( position.getX() - radius < 0 || position.getX() + radius > WIDTH )
        velocity.setX( -velocity.getX() );
    if ( position.getY() - radius < 0 || position.getY() + radius > HEIGHT )
        velocity.setY( -velocity.getY() );
}