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
            //  LevelManager::getInstance().readFile("1");
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