#pragma once

#include <SDL.h>
#include <iostream>
#include <string>
#include "Map.hpp"
#include "Texture.hpp"

#define printOut(input) std::cout << input << std::endl
#define printErr(input, func) std::cerr << input << func << std::endl

#define WIDTH 1280
#define HEIGHT 720

class Window
{
	public:
		Window( void );
		~Window( void );
		int	createWindow( void );
		void	handleEvents( void );
		void	gameLoop( void );
		void	render( void );
	private:
		SDL_Window 		*window;
		SDL_Renderer	*renderer;
		SDL_Event		event;
		bool			running;
		int				level;
		Map				*lvl;
		Texture			*bricks;
		Texture			*empty;
};