#include "InputHandling.hpp"

InputHandler *InputHandler::instancePtr = nullptr;

InputHandler::InputHandler( void )
{}

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