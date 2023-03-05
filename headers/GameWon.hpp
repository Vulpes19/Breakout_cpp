#pragma once

#include "Game.hpp"
#include "GameStates.hpp"

class GameWon : public GameState
{
	public:
		GameWon( void );
		int	update( void );
		void	render( SDL_Renderer *renderer );
		bool    onEnter( void );
		bool    onExit( void );
		std::string getState( void ) const;
	private:
		static const	std::string state;
		SDL_Color		color;
};