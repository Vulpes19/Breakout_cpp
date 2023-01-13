#include "MainMenu.hpp"

const   std::string MainMenu::state = "Main Menu";

void    MainMenu::update( void )
{

}

void    MainMenu::render( void )
{

}

bool    MainMenu::onEnter( void )
{
    std::cout << "entering " << state << " state" << std::endl;
    return (true);
}

bool    MainMenu::onExit( void )
{
    std::cout << "exiting " << state << " state" << std::endl;
    return (true);
}

std::string MainMenu::getState( void ) const
{
    return (state);
}