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
 * HighScore.cpp by Vulpes19
 * 
 * =========================================================
 */


//this feature is removed for now for some problems with opening the save.txt file after installation

#include "HighScore.hpp"
#include <string>
#include <algorithm>
#include <direct.h>
#include <limits.h>

HighScore::HighScore( void )
{
	highScore = 0;
}

HighScore::~HighScore( void )
{
	file.close();
}

void    HighScore::openFile( void )
{
	std::string path = getCurrentPath();
	std::replace( path.begin(), path.end(), '\\', '/' );
	std::string name = "/assets/save";
	file.open(path + name, std::ios::out | std::ios::in );
	if ( !file )
	{
		name = "/assets/save.txt";
		file.open(path + name, std::ios::out | std::ios::in );
		if ( !file )
		{
			std::cerr << "can't open save file " << path + name << "\n";
			return ;
		}
	}
	// file.close();
}


void    HighScore::checkScore( int score )
{
	if ( !file )
	 {
		std::cerr << "can't open save file\n";
		return ;
	}
	std::string highestScore;
	if ( !std::getline( file, highestScore ) )
		return ;
	int intHighestScore = std::stoi(highestScore);
	highScore = intHighestScore;
	if ( score > intHighestScore)
	{
		file.seekg(std::ios::beg); 
		file << score;
		highScore = score;
	}
	file.close();
}

int HighScore::getHighScore( void ) const
{
	return (highScore);
}

std::string	HighScore::getCurrentPath( void ) const
{
	char buff[_MAX_PATH];
    _getcwd( buff, _MAX_PATH );
	std::string path(buff);
	return (path);
}