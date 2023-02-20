#include "MainMenu.hpp"
#include "TextManager.hpp"
#include "InputHandling.hpp"

const   std::string MainMenu::state = "Main Menu";

MainMenu::MainMenu( void )
{
    color_title = {64, 121, 140, 255};
    color_button1 = {165, 145, 50, 255};
    color_button2 = {165, 145, 50, 255};
    color_button3 = {165, 145, 50, 255};
}
int    MainMenu::update( void )
{
    Vector cursor = InputHandler::getInstance().getCursorPosition();
    if ( cursor.getX() >= WIDTH / 2 - 80 && cursor.getX() <= WIDTH / 2 - 80 + 140 && cursor.getY() >= HEIGHT / 2 - 80 && cursor.getY() <= HEIGHT / 2 - 80 + 70)
        color_button1 = {249, 235, 224, 255};
    else
        color_button1 = {165, 145, 50, 255};
    if ( cursor.getX() >= WIDTH / 2 - 80 && cursor.getX() <= WIDTH / 2 - 80 + 140 && cursor.getY() >= HEIGHT / 2 + 5 && cursor.getY() <= HEIGHT / 2 + 75)
        color_button2 = {249, 235, 224, 255};
    else
        color_button2 = {165, 145, 50, 255};
    return (NO_BUTTON);
}

void    MainMenu::render( SDL_Renderer *renderer )
{
    Text::getInstance().writeText("regular", WIDTH / 2 - 280, HEIGHT / 2 - 400, 600, 300, renderer, "BREAKOUT", color_title, state);
    Text::getInstance().writeText("regular", WIDTH / 2 - 80, HEIGHT / 2 - 80, 140, 70, renderer, "Play", color_button1, state);
    Text::getInstance().writeText("regular", WIDTH / 2 - 80, HEIGHT / 2 + 5, 140, 70, renderer, "Options", color_button2, state);
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