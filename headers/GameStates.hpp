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
#define REPLAY_BUTTON 3
#define QUIT_BUTTON 4
#define NO_BUTTON 5
#include <SDL.h>
#include <iostream>

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
	protected:
		std::string currentMode;
};
