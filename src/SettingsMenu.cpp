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
 * SettingsMenu.cpp by Vulpes19
 * 
 * =========================================================
 */

#include "SettingsMenu.hpp"
#include "TextManager.hpp"

const   std::string SettingsMenu::state = "Settings Menu";

SettingsMenu::SettingsMenu( void )
{
    color_title = {64, 121, 140, 255};
    color_button1 = {165, 145, 50, 255};
    color_button2 = {165, 145, 50, 255};
    color_button3 = {165, 145, 50, 255};
    sound = "";
}
int    SettingsMenu::update( void )
{
    Vector cursor = InputHandler::getInstance().getCursorPosition();

    if ( InputHandler::getInstance().getMouseButton( LEFT ) )
    {
        if ( cursor.getX() >= WIDTH / 2 - 80 && cursor.getX() <= WIDTH / 2 - 80 + 140 && cursor.getY() >= HEIGHT / 2 + 5 && cursor.getY() <= HEIGHT / 2 + 75 )
            return (SOUND);
    }
    if ( cursor.getX() >= WIDTH / 2 - 80 && cursor.getX() <= WIDTH / 2 - 80 + 140 && cursor.getY() >= HEIGHT / 2 + 5 && cursor.getY() <= HEIGHT / 2 + 75)
        color_button2 = {249, 235, 224, 255};
    else
        color_button2 = {165, 145, 50, 255};
    return (NO_BUTTON);
}

void    SettingsMenu::render( SDL_Renderer *renderer )
{
    Text::getInstance().writeText("regular", WIDTH / 2 - 280, HEIGHT / 2 - 400, 600, 300, renderer, "BREAKOUT", color_title, state);
    Text::getInstance().writeText("pixelated", WIDTH / 2 - 80, HEIGHT / 2 - 80, 140, 70, renderer, "Sound", color_button1, state);
    Text::getInstance().writeText("pixelated", WIDTH / 2 - 80, HEIGHT / 2 + 5, 140, 70, renderer, sound.c_str(), color_button2, state);
}

bool    SettingsMenu::onEnter( void )
{
    std::cout << "entering " << state << " state" << std::endl;
    return (true);
}

bool    SettingsMenu::onExit( void )
{
    std::cout << "exiting " << state << " state" << std::endl;
    return (true);
}

std::string SettingsMenu::getState( void ) const
{
    return (state);
}
