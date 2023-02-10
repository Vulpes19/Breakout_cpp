#include "Ball.hpp"
#include "Game.hpp"

Ball::Ball( void ) : GameObject()
{
    radius = 10;
    velocity.setX(0.2f);
    velocity.setY(0.2f);
    // this->position.setX(WIDTH / 2 - 50);
    // this->position.setY(HEIGHT / 2 + 5);
    this->position.setX(0);
    this->position.setY(0);
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

void    Ball::update( Player &player, int &score, int &lives )
{
    this->frame = int(((SDL_GetTicks() / 100) % 6));
    wallCollision( player, lives, score );
    bricksCollision( score );
    velocity += acceleration;
    position += velocity;
}

void    Ball::wallCollision( Player &player, int &lives, int &score )
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
        this->position.setX(WIDTH / 2 - 50);
        this->position.setY(HEIGHT / 2 + 5);
        player.setPosition( 40, HEIGHT - 20);
        lives--;
        score = 0;
        // position.setY( position.getY() );
        // velocity.setY( -velocity.getY() );
    }
    else if ( position.getY() + radius * 2 >= HEIGHT )
    {
        this->position.setX(WIDTH / 2);
        this->position.setY(HEIGHT / 2 + 5);
        player.setPosition( 40, HEIGHT - 20);
        lives--;
        score = 0;
        // position.setY( HEIGHT - radius * 2 );
        // velocity.setY( -velocity.getY() );
    }

    if (  position.getY() + radius * 2 >= player.getPosition().getY() && position.getX() - 0.01 >= player.getPosition().getX() && position.getX() + radius * 2 + 0.01 <= player.getPosition().getX() + 100 )
        velocity.setY( -velocity.getY() );
}

void    Ball::bricksCollision( int &score )
{
    int columns, rows;

    (void)score;
    columns = LevelManager::getInstance().mapGrid[0].size();
    rows = LevelManager::getInstance().mapGrid.size();
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            char i = LevelManager::getInstance().mapGrid[r][c];
            if ( i == '3' || i == '4' || i == '1' || i == '2' )
            {
                float brickX = c * TILE_SIZE_W;
                float brickY = r * TILE_SIZE_H;
                if ( position.getX() >= brickX && position.getX() + radius * 2 <= brickX + TILE_SIZE_W && position.getY() + radius * 2 >= brickY && position.getY() <= brickY + TILE_SIZE_H)
                {
                    if ( LevelManager::getInstance().mapGrid[r][c] == '1' ) score += 1;
                    else if ( LevelManager::getInstance().mapGrid[r][c] == '2' ) score += 3;
                    else if ( LevelManager::getInstance().mapGrid[r][c] == '3' ) score += 5;
                    else if ( LevelManager::getInstance().mapGrid[r][c] == '4' ) score += 7;
                    LevelManager::getInstance().mapGrid[r][c] = '0';
                    velocity.setY( -velocity.getY() );
                }
            }
        }
    }
}
