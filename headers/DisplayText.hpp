#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

#define printOut(input) std::cout << input << std::endl
#define printErr(input, func) std::cerr << input << func << std::endl

class   DisplayText
{
	public:
		DisplayText( void );
		~DisplayText( void );
		void	writeText( std::string &, SDL_Renderer * );
	private:
		TTF_Font	*font;
		SDL_Color	color;
		SDL_Texture	*texture;
		SDL_Surface	*surface;
		SDL_Rect	dest;
};