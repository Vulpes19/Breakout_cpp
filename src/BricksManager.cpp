#include "BricksManager.hpp"

void    BricksManager::getTexture( SDL_Renderer *renderer )
{
    Texture::getInstance().loadImage("assets/brick.png", "brick", renderer );
}

void    BricksManager::render( SDL_Renderer *renderer )
{
	for ( auto row = 0; row < GRID_HEIGHT; row++ )
	{
		for ( auto col = 0; col < GRID_WIDTH; col++ )
		{
            // const char *tile = mapGrid[row].c_str();
            // char *oneTile = (char *)tile[col];
            char oneTile = mapGrid[row][col];
            int tilePos = oneTile - '0';
			if ( tilePos == 3 )
                Texture::getInstance().draw("brick", col * TILE_SIZE, row * TILE_SIZE, TILE_SIZE, TILE_SIZE, renderer);
        }
	}
    // exit(1);
}

// void    BricksManager::update( void )
// {

// }