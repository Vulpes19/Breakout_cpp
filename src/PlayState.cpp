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
 * PlayState.cpp by Vulpes19
 * 
 * =========================================================
 */


#include "PlayState.hpp"
#include "TextManager.hpp"
#include "LevelManager.hpp"
#include <string>

const   std::string PlayState::state = "Play";

PlayState::PlayState( void )
{}

int    PlayState::update( void )
{
    return (NO_BUTTON);
}

void    PlayState::render( SDL_Renderer *renderer )
{
    (void)renderer;
}

bool    PlayState::onEnter( void )
{
    return (true);
}

bool    PlayState::onExit( void )
{
    return (true);
}

std::string PlayState::getState( void ) const
{
    return (state);
}