#include "DisplayText.hpp"

DisplayText::DisplayText( void )
{
	color = { 255, 255, 255, 255 };
	dest = { 1200, 400, 100, 50 };
	texture = nullptr;
	surface = nullptr;
	if ( TTF_Init() < 0 )
	{
		printErr("Error initializing SDL_ttf: ", TTF_GetError());
		return ;
	}
	font = TTF_OpenFont("/Users/asus/Documents/Breakout/assets/OpenSans-Regular.ttf", 32);
	if ( !font )
	{
		printErr("Failed to load font: ", TTF_GetError());
		return ;
	}
}

DisplayText::~DisplayText( void )
{
	TTF_CloseFont( font );
	TTF_Quit();
}

void	DisplayText::writeText( std::string &text, SDL_Renderer *renderer )
{
	const char *toDisplay = text.c_str();

	surface = TTF_RenderText_Solid( font, toDisplay, color );
	if ( !surface )
	{
		printErr("Failed to render text to surface: ", TTF_GetError());
		return ;
	}
	texture = SDL_CreateTextureFromSurface( renderer, surface );
	SDL_FreeSurface( surface );
	SDL_RenderCopy( renderer, texture, NULL, &dest );
	SDL_DestroyTexture( texture );
	texture = nullptr;
	surface = nullptr;
}