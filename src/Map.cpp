#include "Map.hpp"

Map::Map( const std::string &level )
{
	map = nullptr;
	std::string filename = "/Users/asus/Documents/Breakout/assets/levels/lvl";
	filename.append(level);
	filename.append(".txt");

	if ( openFile( filename ) )
		return ;
	createMap();
}

Map::~Map( void )
{
	freeMap();
	if (file.is_open())
		file.close();
}

int	Map::openFile( const std::string &filename )
{
	file.open( filename );

	if ( file.is_open() )
		return (EXIT_SUCCESS);
	else
	{
		std::cerr << "Error opening the file" << std::endl;
		return (EXIT_FAILURE);
	}
}

void	Map::createMap( void )
{
	int 		y;
	std::string line;
	const char 	*tmp;

	y = 0;
	map = (char **)malloc(sizeof(char *) * 19);
	while ( file )
	{
		std::getline( file, line );
		std::cout << line << std::endl;
		tmp = line.c_str();
		map[y] = (char *)malloc(32);
		for (int x = 0; x < 32; x++)
		{
			map[y][x] = tmp[x];
		}
		map[y][32] = '\0';
		y++;
	}
	map[y] = NULL;
}

void	Map::freeMap( void )
{
	for(int i = 0; i < 18; i++)
		free(map[i]);
	free(map);
}