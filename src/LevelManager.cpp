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
    Texture::getInstance().loadImage("assets/brick.png", "brick", renderer );
    Texture::getInstance().loadImage("assets/brick2.png", "brick2", renderer );
    Texture::getInstance().loadImage("assets/brick3.png", "brick3", renderer );
}

void    LevelManager::render( SDL_Renderer *renderer )
{
	for ( auto row = 0; row < GRID_HEIGHT; row++ )
	{
		for ( auto col = 0; col < GRID_WIDTH; col++ )
		{
            char oneTile = mapGrid[row][col];
            int tilePos = oneTile - '0';
			if ( tilePos == 3 )
                Texture::getInstance().draw("brick3", col * TILE_SIZE, row * TILE_SIZE, TILE_SIZE, TILE_SIZE, renderer);
			else if ( tilePos == 2 )
                Texture::getInstance().draw("brick2", col * TILE_SIZE, row * TILE_SIZE, TILE_SIZE, TILE_SIZE, renderer);
			else if ( tilePos == 1 )
                Texture::getInstance().draw("brick", col * TILE_SIZE, row * TILE_SIZE, TILE_SIZE, TILE_SIZE, renderer);
        }
	}
}
