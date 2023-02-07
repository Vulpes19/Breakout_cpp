#include "Ball.hpp"
#include "Game.hpp"

Ball::Ball( void ) : GameObject()
{
    radius = 10;
    velocity.setX(0.2f);
    velocity.setY(0.2f);
    this->position.setX(WIDTH / 2);
    this->position.setY(HEIGHT / 2 + 5);
    acceleration.setX(0.0f);
    acceleration.setY(0.0f);
}

void    Ball::loadTexture( int x, int y, int width, int height, std::string ID )
{
    GameObject::loadTexture( x, y, width, height, ID );
}

void    Ball::draw( SDL_Renderer *renderer )
{
    GameObject::draw( renderer );
    // this->position.setX(WIDTH / 2);
    // this->position.setY(HEIGHT / 2);
    // SDL_Rect rect;

    // rect.x = this->position.getX() - radius;
    // rect.y = this->position.getY() - radius;
    // rect.w = radius * 2;
    // rect.h = radius * 2;
    // SDL_SetRenderDrawColor( renderer, 255, 0, 0, 0);
    // SDL_RenderFillRect( renderer, &rect );
}

void    Ball::update( Player &player )
{
    this->frame = int(((SDL_GetTicks() / 100) % 6));
    wallCollision( player );
    bricksCollision();
    velocity += acceleration;
    position += velocity;
}

void    Ball::wallCollision( Player &player )
{
    if ( position.getX() <= 0 )
    {
        position.setX( position.getX() );
        velocity.setX( -velocity.getX() );
    }
    else if ( position.getX() + radius * 2 >= WIDTH )
    {
        position.setX( WIDTH - radius * 2 );
        velocity.setX( -velocity.getX() );
    }
    if ( position.getY() <= 0 )
    {
        position.setY( position.getY() );
        velocity.setY( -velocity.getY() );
    }
    else if ( position.getY() + radius * 2 >= HEIGHT )
    {
        position.setY( HEIGHT - radius * 2 );
        velocity.setY( -velocity.getY() );
    }

    if (  position.getY() + radius * 2 >= player.getPosition().getY() && position.getX() >= player.getPosition().getX() && position.getX() + radius * 2 <= player.getPosition().getX() + 100 )
        velocity.setY( -velocity.getY() );
}

void    Ball::bricksCollision( void )
{
    int columns, rows;

    columns = LevelManager::getInstance().mapGrid[0].size();
    rows = LevelManager::getInstance().mapGrid.size();
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            char i = LevelManager::getInstance().mapGrid[r][c];
            if ( i == '3' || i == '4' || i == '1' || i == '2' )
            {
                // std::cout << "I collided !" << std::endl;
                int brickX = c * TILE_SIZE_W;
                int brickY = r * TILE_SIZE_H;
                if ( position.getX() >= brickX && position.getX() + radius * 2 <= brickX + TILE_SIZE_W && position.getY() + radius * 2 >= brickY && position.getY() <= brickY + TILE_SIZE_H)
                {
                    LevelManager::getInstance().mapGrid[r][c] = '0';
                    velocity.setY( -velocity.getY() );
                }
            }
        }
    }
}
