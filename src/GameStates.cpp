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
 * GameStates.cpp by Vulpes19
 * 
 * =========================================================
 */

#include "GameStates.hpp"

std::string GameState::getMode( void ) const { return (currentMode); }

void		GameState::setMode( std::string s ) { currentMode = s; }

void	GameState::setSound( bool ifon )
{
    if ( ifon )
        sound = "on";
    else
        sound = "off";
};