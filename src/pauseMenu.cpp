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
 * PauseMenu.cpp by Vulpes19
 * 
 * =========================================================
 */


#include "PauseMenu.hpp"
#include "TextManager.hpp"
#include "TextureManager.hpp"

const   std::string PauseMenu::state = "Pause Menu";

PauseMenu::PauseMenu( void )
{
    textColor = { 165, 145, 50, 255 };
    changedColor = { 165, 145, 50, 255 };
}

int    PauseMenu::update( void )
{
    Vector cursor = InputHandler::getInstance().getCursorPosition();
    if ( InputHandler::getInstance().getMouseButton( LEFT ) )
    {
        if ( cursor.getX() >= WIDTH - 50 && cursor.getX() <= WIDTH - 10 &&
                cursor.getY() >= HEIGHT - 50 && cursor.getY() <= HEIGHT - 10 )
            return (QUIT_BUTTON);
        if ( cursor.getX() >= WIDTH - 100 && cursor.getX() <= WIDTH - 60 &&
                cursor.getY() >= HEIGHT - 50 && cursor.getY() <= HEIGHT - 10 )
        {
            return (REPLAY_BUTTON);
        }
    }
    return (NO_BUTTON);
}

void    PauseMenu::render( SDL_Renderer *renderer )
{
    Text::getInstance().writeText( "regular", WIDTH / 2 - 150, HEIGHT - 400, 300, 150, renderer, "PAUSED", textColor, state );
    Text::getInstance().writeText( "regular", WIDTH / 2 - 200, HEIGHT - 250, 400, 100, renderer, "press enter to continue", textColor, state );
    Texture::getInstance().draw( "quit_icon", WIDTH - 50, HEIGHT - 50, 40, 40, renderer, false );
    Texture::getInstance().draw( "restart_icon", WIDTH - 100, HEIGHT - 50, 40, 40, renderer, false );
}

bool    PauseMenu::onEnter( void )
{
    return (true);
}

bool    PauseMenu::onExit( void )
{
    return (true);
}

std::string PauseMenu::getState( void ) const
{
    return (state);
}