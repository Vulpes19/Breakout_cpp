#pragma once

#include <SDL.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Texture.hpp"

class Map
{
	public:
		Map( const std::string & );
		~Map( void );
		int		openFile( const std::string & );
		void	createMap( void );
		void	freeMap( void );
		char    **map;
		SDL_Rect    pos;
	private:
		std::ifstream	file;
};