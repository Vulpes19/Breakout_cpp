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
 * Ball.cpp by Vulpes19
 * 
 * =========================================================
 */


#include "Ball.hpp"
#include "Game.hpp"
#include "ParticlesManager.hpp"

// #define BRICK_TYPE LevelManager::getInstance().mapGrid[r][c]
#define RED '4'
#define ORANGE '3'
#define GREEN '2'
#define YELLOW '1'

Ball::Ball( void ) : GameObject()
{
	radius = 10;
	velocity.setX(0.5f);
	velocity.setY(0.5f);
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

void    Ball::update( Player &player, int &score, int &lives, ParticlesManager *particles, bool &hit, SDL_Renderer *renderer )
{
	this->frame = int(((SDL_GetTicks() / 100) % 6));
	wallCollision( player, lives, score );
	bricksCollision( score, particles, hit, renderer );
	velocity += acceleration;
	position += velocity;
}

void    Ball::wallCollision( Player &player, int &lives, int &score )
{
	(void)score;
	if ( position.getY() + radius * 2 >= player.getPosition().getY() &&
		position.getX() + radius >= player.getPosition().getX() &&
		position.getX() <= player.getPosition().getX() + player.getDimensions().first )
		velocity.setY(-velocity.getY() );
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
	else if ( position.getY() <= 22 )
	{
		player.loadTexture( player.getPosition().getX(), HEIGHT - 20, 50, 20, "paddle" );
		position.setY( position.getY() );
		velocity.setX( velocity.getX() + 0.2 );
		velocity.setY( -velocity.getY() + 0.2 );
	}
	else if ( position.getY() + radius * 2 >= HEIGHT )
	{
		this->position.setX(40);
		this->position.setY(HEIGHT / 2 + 5);
		velocity.setX(0.7f);
		velocity.setY(0.7f);
		player.loadTexture( player.getPosition().getX(), HEIGHT - 20, 100, 20, "paddle" );
		lives--;
	}

}

void    Ball::bricksCollision( int &score, ParticlesManager *particles, bool &hit, SDL_Renderer *renderer )
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
				float brickX = c * TILE_SIZE_W;
				float brickY = r * TILE_SIZE_H;
				if ( position.getX() + radius >= brickX &&
					position.getX() + radius <= brickX + TILE_SIZE_W && 
					position.getY() + radius >= brickY && 
					position.getY() + radius <= brickY + TILE_SIZE_H)
				{
					hit = true;
					AudioManager::getInstance().playSound("hit");
					// particles.reserve(10);
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
						velocity.setX(0.7f);
						velocity.setY(0.7f);
						Texture::getInstance().loadImage("assets/orange_brick.png", "effect", renderer );
						score += 5;
					}
					else if ( LevelManager::getInstance().mapGrid[r][c] == RED )
					{
						velocity.setX(0.7f);
						velocity.setY(0.7f);
						Texture::getInstance().loadImage("assets/red_brick.png", "effect", renderer );
						score += 7;
					}
					particles->initParticles( brickX, brickY, TILE_SIZE_W, TILE_SIZE_H);
					LevelManager::getInstance().mapGrid[r][c] = '0';
					velocity.setY( -velocity.getY() );
				}
			}
		}
	}
}

void	Ball::setVelocity( void )
{
	velocity.setX(0.5f);
	velocity.setY(0.5f);
}