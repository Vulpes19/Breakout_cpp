#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

class   Score
{
	public:
		Score( void );
		~Score( void );
		void	increment( void );
		bool	decrementLives( void );
		void	displayScore( void );
	private:
		int	score;
		int	lives;
};