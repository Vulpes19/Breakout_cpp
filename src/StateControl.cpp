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
 * StateControl.cpp: 
 * 
 * =========================================================
 */

#include "StateControl.hpp"

int    StateControl::update( void )
{
	if ( !gameStates.empty() )
	{
		return (gameStates.back()->update());
	}
	return (NO_BUTTON);
}

void    StateControl::render( SDL_Renderer *renderer )
{
	if ( !gameStates.empty() )
	{
		gameStates.back()->render(renderer);
	}
}

void    StateControl::pushState( GameState *state )
{
	gameStates.push_back(state);
	gameStates.back()->onEnter();
}

void    StateControl::popState( void )
{
	if ( !gameStates.empty() )
	{
		if ( gameStates.back()->onExit() )
		{
			delete gameStates.back();
			gameStates.pop_back();
		}
	}
}

void    StateControl::changeState( GameState *state )
{
	if ( !gameStates.empty() )
	{
		if ( gameStates.back()->getState() == state->getState() )
			return ;
		if ( gameStates.back()->onExit() )
		{
			delete gameStates.back();
			gameStates.pop_back();
		}
	}
	gameStates.push_back(state);
	gameStates.back()->onEnter();
}

std::string StateControl::getState( void ) const
{
	return (gameStates.back()->getState());
}

std::string StateControl::getMode( void ) const
{
	return (gameStates.back()->getMode());
}

void    StateControl::clear( void )
{
	gameStates.clear();
}

void    StateControl::setSound( bool sound )
{
	gameStates.back()->setSound(sound);
}