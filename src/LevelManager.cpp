#include "levelManager.hpp"

LevelManager *LevelManager::instancePtr = nullptr;

LevelManager  &LevelManager::getInstance( void )
{
    if ( instancePtr == nullptr )
    {
        instancePtr = new LevelManager();
        return (*instancePtr);
    }
    
    return (*instancePtr);
}

LevelManager::LevelManager( void )
{}

void	LevelManager::readFile( std::string level )
{
	std::string levelName = "./assets/levels/lvl";
	std::string fileContent;
	int	index = 0;

	levelName.append(level.c_str());
	levelName.append(".txt");
	levelFile.open(levelName);
	if ( !levelFile )
	{
		std::cerr << "can't open level file" << std::endl;
		exit( EXIT_FAILURE );
	}
	while ( levelFile && index < GRID_HEIGHT )
	{
		if ( !std::getline( levelFile, fileContent ) )
			break ;
		mapGrid.push_back( fileContent );
		index++;
	}
	levelFile.close();
}

void    LevelManager::getTexture( SDL_Renderer *renderer )
{
    Texture::getInstance().loadImage("assets/red_brick.png", "red_brick", renderer );
    Texture::getInstance().loadImage("assets/orange_brick.png", "orange_brick", renderer );
    Texture::getInstance().loadImage("assets/green_brick.png", "green_brick", renderer );
    Texture::getInstance().loadImage("assets/yellow_brick.png", "yellow_brick", renderer );
}

void    LevelManager::render( SDL_Renderer *renderer, bool brightness )
{
	for ( auto row = 0; row < GRID_HEIGHT; row++ )
	{
		for ( auto col = 0; col < GRID_WIDTH; col++ )
		{
            char oneTile = mapGrid[row][col];
            int tilePos = oneTile - '0';
			if ( tilePos == 4 )
                Texture::getInstance().draw("red_brick", col * TILE_SIZE_W, row * TILE_SIZE_H, TILE_SIZE_W, TILE_SIZE_H, renderer, brightness);
			else if ( tilePos == 3 )
                Texture::getInstance().draw("orange_brick", col * TILE_SIZE_W, row * TILE_SIZE_H, TILE_SIZE_W, TILE_SIZE_H, renderer, brightness);
			else if ( tilePos == 2 )
                Texture::getInstance().draw("green_brick", col * TILE_SIZE_W, row * TILE_SIZE_H, TILE_SIZE_W, TILE_SIZE_H, renderer, brightness);
			else if ( tilePos == 1 )
                Texture::getInstance().draw("yellow_brick", col * TILE_SIZE_W, row * TILE_SIZE_H, TILE_SIZE_W, TILE_SIZE_H, renderer, brightness);
		}
	}
}
