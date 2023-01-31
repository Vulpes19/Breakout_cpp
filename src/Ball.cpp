#include "Ball.hpp"
#include "Game.hpp"

Ball::Ball( void ) : GameObject()
{
    radius = 10;
    velocity.setX(0.5f);
    velocity.setY(0.5f);
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
    bricksCollision();
    velocity += acceleration;
    position += velocity * frame;
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
}

void    Ball::bricksCollision( void )
{
    int ball_x, ball_y;

    ball_x = position.getX() + radius * 2;
    ball_y = position.getY() + radius * 2;
    // LevelManager::getInstance().mapGrid.size() / GRID_HEIGHT;
    for ( unsigned int i = 0; i < LevelManager::getInstance().brickPositions.size(); i++)
    {
        int brickCenterX = LevelManager::getInstance().brickPositions[i].first;
        int brickCenterY = LevelManager::getInstance().brickPositions[i].second;
        if ( abs(ball_y - brickCenterY) <= (radius * 2 + TILE_SIZE) / 2)
            velocity.setY( -velocity.getY() );
        if ( abs(ball_x - brickCenterX) <= (radius * 2 + TILE_SIZE) / 2)
            velocity.setX( -velocity.getX() );
    }
    // if ( LevelManager::getInstance().mapGrid[ball_y / TILE_SIZE][ball_x / TILE_SIZE] > 0 && ball_x - ball_x <= (radius * 2 + TILE_SIZE) / 2)
    //     velocity.setY( -velocity.getY());
    // else if (LevelManager::getInstance().mapGrid[ball_y / TILE_SIZE][ball_x / TILE_SIZE] > 0 && ball_y - ball_y <= (radius * 2 + TILE_SIZE) / 2)
    //     velocity.setX( -velocity.getX());
}
