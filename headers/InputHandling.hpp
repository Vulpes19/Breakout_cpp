#pragma once

#include <SDL.h>
#include "Vector.hpp"

class InputHandler
{
    public:
        static  InputHandler    &getInstance( void );
        bool    isKeyPressed( SDL_Scancode key );
        Vector  getCursorPosition( void ) const;
        void    setCursorPosition( int x, int y );
        void    update( void );
        void    clean( void );
    private:
        InputHandler( void );
        ~InputHandler( void ) {};
        static  InputHandler    *instancePtr;
        const Uint8   *keyboardState = SDL_GetKeyboardState(0);
        Vector  cursorPosition;
};