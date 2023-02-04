#include "MainMenu.hpp"
#include "TextManager.hpp"
#include "InputHandling.hpp"

const   std::string MainMenu::state = "Main Menu";

MainMenu::MainMenu( void )
{
    color_title = {64, 121, 140, 0};
    color_button = {165, 145, 50, 0};
}
void    MainMenu::update( void )
{
    Vector cursor = InputHandler::getInstance().getCursorPosition();
    if ( cursor.getX() >= WIDTH / 2 - 90 && cursor.getX() <= WIDTH / 2 - 90 + 150 && cursor.getY() >= HEIGHT / 2 - 80 && cursor.getY() <= HEIGHT / 2 - 80 + 150)
        color_button = {249, 235, 224, 0};
    else
        color_button = {165, 145, 50, 0};
}

void    MainMenu::render( SDL_Renderer *renderer )
{
    Text::getInstance().writeText("regular", WIDTH / 2 - 280, HEIGHT / 2 - 400, 600, 300, renderer, "BREAKOUT", color_title);
    Text::getInstance().writeText("regular", WIDTH / 2 - 80, HEIGHT / 2 - 80, 140, 70, renderer, "Play", color_button);
    Text::getInstance().writeText("regular", WIDTH / 2 - 80, HEIGHT / 2 + 5, 140, 70, renderer, "Options", color_button);
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