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
 * GameOver.cpp: 
 * 
 * =========================================================
 */

#include "GameOver.hpp"
#include "TextManager.hpp"

const   std::string GameOver::state = "Game Over";

GameOver::GameOver( void )
{
	color = {165, 145, 50, 255};
}

int    GameOver::update( void )
{
	color = {249, 235, 224, 255};
	return (NO_BUTTON);
}

void    GameOver::render( SDL_Renderer *renderer )
{
	Text::getInstance().writeText("regular", 250, 50, 600, 300, renderer, "Game Over", color, state);
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