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
 * PlayState.cpp: 
 * 
 * =========================================================
 */

#include "PlayState.hpp"
#include "TextManager.hpp"
#include "LevelManager.hpp"
#include <string>

const   std::string PlayState::state = "Play";

PlayState::PlayState( void )
{
    // LevelManager::getInstance().readFile("pyramid");
}
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
    std::cout << "entering " << state << " state" << std::endl;
    return (true);
}

bool    PlayState::onExit( void )
{
    std::cout << "exiting " << state << " state" << std::endl;
    return (true);
}

std::string PlayState::getState( void ) const
{
    return (state);
}