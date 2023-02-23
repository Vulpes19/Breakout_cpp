#include "levelMenu.hpp"
#include "TextManager.hpp"

levelMenu::levelMenu( void )
{
    color_title = {64, 121, 140, 255};
	color_button1 = {165, 145, 50, 255};
    color_button2 = {165, 145, 50, 255};
}

int	levelMenu::update( void )
{

}

void	levelMenu::render( SDL_Renderer *renderer )
{
    Text::getInstance().writeText("regular", WIDTH / 2 - 280, HEIGHT / 2 - 400, 600, 300, renderer, "BREAKOUT", color_title, state);
	Text::getInstance().writeText("pixelated", WIDTH / 2 - 80, HEIGHT / 2 - 80, 140, 70, renderer, "Standard", color_button1, state);
    Text::getInstance().writeText("pixelated", WIDTH / 2 - 80, HEIGHT / 2 + 5, 140, 70, renderer, "1337", color_button2, state);
    Text::getInstance().writeText("pixelated", WIDTH / 2 - 80, HEIGHT / 2 + 5, 140, 70, renderer, "Pyramid", color_button2, state);
    Text::getInstance().writeText("pixelated", WIDTH / 2 - 80, HEIGHT / 2 + 5, 140, 70, renderer, "Crazy", color_button2, state);
    // Text::getInstance().writeText("pixelated", WIDTH / 2 - 80, HEIGHT / 2 + 5, 140, 70, renderer, "", color_button2, state);
    Texture::getInstance().draw( "quit_icon", WIDTH - 50, HEIGHT - 50, 40, 40, renderer, false );
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