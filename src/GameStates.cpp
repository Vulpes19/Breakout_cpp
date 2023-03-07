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