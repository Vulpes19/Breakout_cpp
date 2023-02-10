#include "PauseMenu.hpp"
#include "TextureManager.hpp"

const   std::string PauseMenu::state = "Pause Menu";

PauseMenu::PauseMenu( void )
{}

void    PauseMenu::update( void )
{

}

void    PauseMenu::render( SDL_Renderer *renderer )
{
    (void)renderer;
    // Texture::draw( "pause", WIDTH - 90, HEIGHT - 90, 80, 80, renderer );
}

bool    PauseMenu::onEnter( void )
{
    std::cout << "entering " << state << " state" << std::endl;
    return (true);
}

bool    PauseMenu::onExit( void )
{
    std::cout << "exiting " << state << " state" << std::endl;
    return (true);
}

std::string PauseMenu::getState( void ) const
{
    return (state);
}