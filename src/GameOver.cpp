#include "GameOver.hpp"
#include "TextManager.hpp"

const   std::string GameOver::state = "Game Over";

GameOver::GameOver( void )
{
	color = {165, 145, 50, 255};
}

void    GameOver::update( void )
{
	// SDL_Delay(3);
	color = {249, 235, 224, 255};
}

void    GameOver::render( SDL_Renderer *renderer )
{
	Text::getInstance().writeText("regular", 250, 50, 600, 300, renderer, "Game Over", color, state);
	// SDL_Delay(3);
	color = {165, 145, 50, 255};
}

bool	GameOver::onEnter( void )
{
	std::cout << "entering " << state << " state" << std::endl;
	return (true);
}

bool	GameOver::onExit( void )
{
	std::cout << "exiting " << state << " state" << std::endl;
	return (true);
}

std::string GameOver::getState( void ) const
{
	return (state);
}