#pragma once

#include <SDL.h>

class InputHandler
{
    public:
        static  InputHandler    &getInstance( void );
        bool    isKeyPressed( SDL_Scancode key );
        void    update( void );
        void    clean( void );
    private:
        InputHandler( void );
        ~InputHandler( void ) {};
        static  InputHandler    *instancePtr;
        const Uint8   *keyboardState = SDL_GetKeyboardState(0);
};