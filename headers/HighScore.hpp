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
 * HighScore.hpp by Vulpes19
 * 
 * =========================================================
 */


#pragma once

#include <iostream>
#include <fstream>
#include <utility>

class HighScore
{
	public:
		HighScore( void );
		~HighScore( void );
		void    openFile( void );
		void    checkScore( int score );
		int		getHighScore( void ) const;
	private:
		std::fstream file;
		int highScore;
};