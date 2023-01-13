#include "PlayState.hpp"

const   std::string PlayState::state = "Play";

void    PlayState::update( void )
{

}

void    PlayState::render( void )
{

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