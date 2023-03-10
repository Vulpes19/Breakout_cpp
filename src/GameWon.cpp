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
 * GameWon.cpp by Vulpes19
 * 
 * =========================================================
 */

#include "GameWon.hpp"
#include "TextManager.hpp"

const   std::string GameWon::state = "Game Won";

GameWon::GameWon( void )
{
	color = {165, 145, 50, 255};
}

int    GameWon::update( void )
{
	color = {249, 235, 224, 255};
	return (NO_BUTTON);
}

void    GameWon::render( SDL_Renderer *renderer )
{
	Text::getInstance().writeText("regular", 250, 50, 600, 300, renderer, "You Won :D", color, state);
	color = {165, 145, 50, 255};
}

bool	GameWon::onEnter( void )
{
	return (true);
}

bool	GameWon::onExit( void )
{
	return (true);
}

std::string GameWon::getState( void ) const
{
	return (state);
}
