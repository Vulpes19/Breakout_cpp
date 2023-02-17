#include "PopUp.hpp"
#include "TextureManager.hpp"

const   std::string PopUp::state = "Pop up state";

PopUp::PopUp( void )
{}

void    PopUp::update( void )
{

}

void    PopUp::render( SDL_Renderer *renderer )
{
    (void)renderer;
    // Texture::draw( "pause", WIDTH - 90, HEIGHT - 90, 80, 80, renderer );
}

bool    PopUp::onEnter( void )
{
    std::cout << "entering " << state << " state" << std::endl;
    return (true);
}

bool    PopUp::onExit( void )
{
    std::cout << "exiting " << state << " state" << std::endl;
    return (true);
}

std::string PopUp::getState( void ) const
{
    return (state);
}