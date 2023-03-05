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
 * GameStates.hpp: 
 * 
 * =========================================================
 */

#pragma once

#define HEIGHT 704
#define WIDTH 1088
#include <SDL.h>
#include <iostream>
// #include "Game.hpp"

enum MODES
{
	REPLAY_BUTTON = 0,
	QUIT_BUTTON = 1,
	NO_BUTTON = 2,
	MODE_BUTTON = 3,
	SETTINGS_BUTTON = 4,
	SOUND = 5
};
class GameState
{
	public:
		virtual ~GameState( void ) {};
		virtual int		update( void ) = 0;
		virtual void    render( SDL_Renderer *renderer ) = 0;
		virtual bool    onEnter( void ) = 0;
		virtual bool    onExit( void ) = 0;
		virtual std::string getState( void ) const = 0;
		virtual	std::string getMode( void ) const { return (currentMode); };
		virtual	void		setMode( std::string s ) { currentMode = s; };
		virtual	void	setSound( bool ifon )
		{
			if ( ifon )
				sound = "on";
			else
				sound = "off";
		};
	protected:
		std::string currentMode;
		std::string	sound;
};
