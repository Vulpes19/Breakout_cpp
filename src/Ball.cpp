#include "Ball.hpp"
#include "Game.hpp"
#include "ParticleSystem.hpp"

// #define BRICK_TYPE LevelManager::getInstance().mapGrid[r][c]
#define RED '4'
#define ORANGE '3'
#define GREEN '2'
#define YELLOW '1'

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

void    Ball::draw( SDL_Renderer *renderer, bool brightness )
{
    GameObject::draw( renderer, brightness );
}

void    Ball::update( Player &player, int &score, int &lives, std::vector<Particles> &particles, bool &hit, SDL_Renderer *renderer )
{
    this->frame = int(((SDL_GetTicks() / 100) % 6));
    wallCollision( player, lives, score );
    bricksCollision( score, particles, hit, renderer );
    velocity += acceleration;
    position += velocity;
}

void    Ball::wallCollision( Player &player, int &lives, int &score )
{
    if (  position.getY() + radius * 2 >= player.getPosition().getY() && position.getX() + radius >= player.getPosition().getX() && position.getX() + radius <= player.getPosition().getX() + 100 )
        velocity.setY( -velocity.getY() );
    else if ( position.getX() <= 0 )
    {
        position.setX( position.getX() );
        velocity.setX( -velocity.getX() );
    }
    else if ( position.getX() + radius * 2 >= WIDTH )
    {
        position.setX( WIDTH - radius * 2 );
        velocity.setX( -velocity.getX() );
    }
    else if ( position.getY() <= 0 )
    {
        position.setY( position.getY() );
        velocity.setY( -velocity.getY() );
    }
    else if ( position.getY() + radius * 2 >= HEIGHT )
    {
        this->position.setX(WIDTH / 2);
        this->position.setY(HEIGHT / 2 + 5);
        player.loadTexture( WIDTH / 2 - 100, HEIGHT - 20, 100, 20, "paddle" );
        lives--;
        score = 0;
    }

}

void    Ball::bricksCollision( int &score, std::vector<Particles> &particles, bool &hit, SDL_Renderer *renderer )
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
                if ( position.getX() + radius >= brickX && position.getX() + radius <= brickX + TILE_SIZE_W && position.getY() + radius >= brickY && position.getY() + radius <= brickY + TILE_SIZE_H)
                {
                    hit = true;
                    particles.reserve(10);
                    // Particles test;
                    // if ( LevelManager::getInstance().mapGrid[r][c] == '1' ) score += 1;
                    // else if ( LevelManager::getInstance().mapGrid[r][c] == '2' ) score += 3;
                    // else if ( LevelManager::getInstance().mapGrid[r][c] == '3' ) score += 5;
                    // else if ( LevelManager::getInstance().mapGrid[r][c] == '4' ) score += 7;
                    if ( LevelManager::getInstance().mapGrid[r][c] == YELLOW )
                    {
                        Texture::getInstance().loadImage("assets/yellow_brick.png", "effect", renderer );
                        score += 1;
                    }
                    else if ( LevelManager::getInstance().mapGrid[r][c] == GREEN )
                    {
                        Texture::getInstance().loadImage("assets/green_brick.png", "effect", renderer );
                        score += 3;
                    }
                    else if ( LevelManager::getInstance().mapGrid[r][c] == ORANGE )
                    {
                        Texture::getInstance().loadImage("assets/orange_brick.png", "effect", renderer );
                        score += 5;
                    }
                    else if ( LevelManager::getInstance().mapGrid[r][c] == RED )
                    {
                        Texture::getInstance().loadImage("assets/red_brick.png", "effect", renderer );
                        score += 7;
                    }
                    // exit(1);
                    for( int i = 0; i < 10; i++ )
                    {
                        // test.init( brickX + TILE_SIZE_W / 2, brickY + TILE_SIZE_H, TILE_SIZE_W, TILE_SIZE_H, LevelManager::getInstance().mapGrid[r][c] );
                        // particles.push_back(test);
                        particles[i].init( brickX + TILE_SIZE_W / 2, brickY + TILE_SIZE_H, TILE_SIZE_W, TILE_SIZE_H, LevelManager::getInstance().mapGrid[r][c] );
                    }
                    LevelManager::getInstance().mapGrid[r][c] = '0';
                    velocity.setY( -velocity.getY() );
                }
            }
        }
    }
}
