#include "levelManager.hpp"

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

// void	LevelManager::render( SDL_Renderer *renderer )
// {
// 	SDL_Rect tile;

// 	tile.h = TILE_SIZE;
// 	tile.w = TILE_SIZE;
// 	for ( auto row = 0; row < GRID_HEIGHT; row++ )
// 	{
// 		for ( auto col = 0; col < GRID_WIDTH; col++ )
// 		{
// 			if ( mapGrid[row][col] > 0 )
// 			{
// 				tile.x = col;
// 				tile.y = row;
// 			}
// 		}
// 	}
// }
