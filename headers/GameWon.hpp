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
 * GameWon.hpp: 
 * 
 * =========================================================
 */
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