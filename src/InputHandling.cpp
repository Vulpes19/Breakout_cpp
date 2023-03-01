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
 * InputHandling.cpp: 
 * 
 * =========================================================
 */

#include "InputHandling.hpp"

InputHandler *InputHandler::instancePtr = nullptr;

InputHandler::InputHandler( void )
{
    // cursorPosition.setX(-1);
    // cursorPosition.setY(-1);
    for ( int i = 0; i < 3; i++ )
        mouseButtonStates.push_back(false);
}

InputHandler  &InputHandler::getInstance( void )
{
    if ( instancePtr == nullptr )
    {
        instancePtr = new InputHandler();
        return (*instancePtr);
    }
    
    return (*instancePtr);
}

bool    InputHandler::isKeyPressed( SDL_Scancode key )
{
    if ( key != 0 )
    {
        if (keyboardState[key] == 1)
            return (true);
        else
            return (false);
    }
    return (false);
}

Vector  InputHandler::getCursorPosition( void ) const
{
    return (cursorPosition);
}

void    InputHandler::setCursorPosition( int x, int y )
{
    cursorPosition.setX(x);
    cursorPosition.setY(y);
}

void    InputHandler::setMouseButtons( int button, bool state )
{
    mouseButtonStates[button] = state;
}

bool    InputHandler::getMouseButton( int button )
{
    return ( mouseButtonStates[button] );
}