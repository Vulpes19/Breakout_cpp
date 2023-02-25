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
