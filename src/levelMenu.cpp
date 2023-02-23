#include "LevelMenu.hpp"
#include "TextManager.hpp"

const   std::string LevelMenu::state = "Level";

LevelMenu::LevelMenu( void )
{
    color_title = {64, 121, 140, 255};
	color_button1 = {165, 145, 50, 255};
    color_button2 = {165, 145, 50, 255};
}

int	LevelMenu::update( void )
{
    Vector cursor = InputHandler::getInstance().getCursorPosition();
	if ( InputHandler::getInstance().getMouseButton( LEFT ) )
    {
        if ( cursor.getX() >= 20 && cursor.getX() <= 160 &&
                cursor.getY() >= HEIGHT / 2 - 80 && cursor.getY() <= HEIGHT / 2 - 80 + 70 )
            return (PLAY_BUTTON);
        if ( cursor.getX() >= WIDTH - 160 && cursor.getX() <= WIDTH - 20 &&
				cursor.getY() >= HEIGHT / 2 - 80 && cursor.getY() <= HEIGHT / 2 - 80 + 70 )
            return (PLAY_BUTTON);
		if ( cursor.getX() >= 20 && cursor.getX() <= 160 &&
                cursor.getY() >= HEIGHT / 2 + 20 && cursor.getY() <= HEIGHT / 2 + 20 + 70 )
            return (PLAY_BUTTON);
        if ( cursor.getX() >= WIDTH - 160 && cursor.getX() <= WIDTH - 20 &&
				cursor.getY() >= HEIGHT / 2 + 20 && cursor.getY() <= HEIGHT / 2 - 20 + 70 )
            return (PLAY_BUTTON);
    }
	if ( cursor.getX() >= 20 && cursor.getX() <= 160 &&
			cursor.getY() >= HEIGHT / 2 - 80 && cursor.getY() <= HEIGHT / 2 - 80 + 70 )
		color_button1 = {249, 235, 224, 255};
	else
        color_button1 = {165, 145, 50, 255};
	if ( cursor.getX() >= WIDTH - 160 && cursor.getX() <= WIDTH - 20 &&
			cursor.getY() >= HEIGHT / 2 - 80 && cursor.getY() <= HEIGHT / 2 - 80 + 70 )
		color_button2 = {249, 235, 224, 255};
	if ( cursor.getX() >= 20 && cursor.getX() <= 160 &&
			cursor.getY() >= HEIGHT / 2 + 20 && cursor.getY() <= HEIGHT / 2 + 20 + 70 )
		return (PLAY_BUTTON);
	if ( cursor.getX() >= WIDTH - 160 && cursor.getX() <= WIDTH - 20 &&
			cursor.getY() >= HEIGHT / 2 + 20 && cursor.getY() <= HEIGHT / 2 - 20 + 70 )
		return (PLAY_BUTTON);
	return ( NO_BUTTON );
}

void	LevelMenu::render( SDL_Renderer *renderer )
{
    Text::getInstance().writeText("regular", WIDTH / 2 - 280, HEIGHT / 2 - 400, 600, 300, renderer, "BREAKOUT", color_title, state);
	Text::getInstance().writeText("pixelated", 20, HEIGHT / 2 - 80, 140, 70, renderer, "Standard", color_button1, state);
    Text::getInstance().writeText("pixelated", WIDTH - 160, HEIGHT / 2 - 80, 140, 70, renderer, "1337", color_button2, state);
    Text::getInstance().writeText("pixelated", 20, HEIGHT / 2 + 20, 140, 70, renderer, "Pyramid", color_button2, state);
    Text::getInstance().writeText("pixelated", WIDTH - 160, HEIGHT / 2 + 20, 140, 70, renderer, "Crazy", color_button2, state);
    // Text::getInstance().writeText("pixelated", WIDTH / 2 - 80, HEIGHT / 2 + 5, 140, 70, renderer, "", color_button2, state);
    Texture::getInstance().draw( "quit_icon", WIDTH - 50, HEIGHT - 50, 40, 40, renderer, false );
}

bool    LevelMenu::onEnter( void )
{
    std::cout << "entering " << state << " state" << std::endl;
    return (true);
}

bool    LevelMenu::onExit( void )
{
    std::cout << "exiting " << state << " state" << std::endl;
    return (true);
}

std::string LevelMenu::getState( void ) const
{
    return (state);
}