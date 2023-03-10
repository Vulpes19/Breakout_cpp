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
 * MainMenu.cpp by Vulpes19
 * 
 * =========================================================
 */


#include "MainMenu.hpp"
#include "TextManager.hpp"
#include "TextureManager.hpp"
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
    //   Vector cursor = InputHandler::getInstance().getCursorPosition();
    if ( InputHandler::getInstance().getMouseButton( LEFT ) )
    {
        if ( cursor.getX() >= WIDTH - 50 && cursor.getX() <= WIDTH - 10 &&
                cursor.getY() >= HEIGHT - 50 && cursor.getY() <= HEIGHT - 10 )
            return (QUIT_BUTTON);
        if ( cursor.getX() >= WIDTH / 2 - 80 && cursor.getX() <= WIDTH / 2 - 80 + 140 && cursor.getY() >= HEIGHT / 2 + 5 && cursor.getY() <= HEIGHT / 2 + 75 )
            return (SETTINGS_BUTTON);
        if ( cursor.getX() >= WIDTH / 2 - 80 && cursor.getX() <= WIDTH / 2 - 80 + 140 && cursor.getY() >= HEIGHT / 2 - 80 && cursor.getY() <= HEIGHT / 2 - 80 + 70 )
            return (MODE_BUTTON);
    }
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
    Text::getInstance().writeText("pixelated", WIDTH / 2 - 80, HEIGHT / 2 - 80, 140, 70, renderer, "Play", color_button1, state);
    Text::getInstance().writeText("pixelated", WIDTH / 2 - 80, HEIGHT / 2 + 5, 140, 70, renderer, "Settings", color_button2, state);
    Texture::getInstance().draw( "quit_icon", WIDTH - 50, HEIGHT - 50, 40, 40, renderer, false );
}

bool    MainMenu::onEnter( void )
{
    return (true);
}

bool    MainMenu::onExit( void )
{
    return (true);
}

std::string MainMenu::getState( void ) const
{
    return (state);
}