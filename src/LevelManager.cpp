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
		std::vector<std::string> row;
		if ( !std::getline( levelFile, fileContent ) )
			break ;
		row.push_back( fileContent );
		mapGrid.push_back( row );
		index++;
	}
	for (const auto& row : mapGrid)
	{
		for (const auto& item : row)
		{
			std::cout << item << " ";
		}
		std::cout << std::endl;
	}
	levelFile.close();
}

// bool	LevelManager::loadLevel( void )
// {
// 	return true;
// }

// void	LevelManager::render( SDL_Renderer *renderer )
// {

// }

// void	LevelManager::update( void )
// {

// }
