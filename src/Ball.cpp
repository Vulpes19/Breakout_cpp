#include "Ball.hpp"
#include "Game.hpp"

Ball::Ball( void ) : GameObject()
{
    radius = 10;
    velocity.setX(0.2f);
    velocity.setY(0.2f);
    this->position.setX(WIDTH / 2);
    this->position.setY(HEIGHT / 2);
    acceleration.setX(0.0f);
    acceleration.setY(0.0f);
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

void    Ball::update( Player &player )
{
    this->frame = int(((SDL_GetTicks() / 100) % 6));
    wallCollision( player );
    velocity += acceleration;
    position += velocity;
}

void    Ball::wallCollision( Player &player )
{
    if ( position.getX() - radius <= 0 )
    {
        position.setX( radius );
        velocity.setX( -velocity.getX() );
    }
    else if ( position.getX() + radius >= WIDTH )
    {
        position.setX( WIDTH - radius );
        velocity.setX( -velocity.getX() );
    }
    if ( position.getY() - radius <= 0 )
    {
        position.setY( radius );
        velocity.setY( -velocity.getY() );
    }
    else if ( position.getY() + radius >= HEIGHT )
    {
        position.setY( HEIGHT - radius );
        velocity.setY( -velocity.getY() );
    }

    if (  position.getY() + radius >= player.getPosition().getY() && position.getX() - radius >= player.getPosition().getX() && position.getX() + radius <= player.getPosition().getX() + 80 )
        velocity.setY( -velocity.getY() );
    // if ( position.getX() - radius < 0 || position.getX() + radius > WIDTH )
    // {
    //     // std::cout << "x collision ! position.x = " << position.getX() << std::endl;
    //     velocity.setX( -velocity.getX() );
    // }
    // if ( position.getY() - radius < 0 || position.getY() + radius > HEIGHT )
    //     velocity.setY( -velocity.getY() );
}