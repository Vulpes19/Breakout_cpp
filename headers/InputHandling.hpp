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
 * InputHandling.hpp by Vulpes19
 * 
 * =========================================================
 */


#pragma once

#include <SDL.h>
#include <vector>
#include "Vector.hpp"

enum mouseButtons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

class InputHandler
{
    public:
        static  InputHandler    &getInstance( void );
        bool    isKeyPressed( SDL_Scancode key );
        Vector  getCursorPosition( void ) const;
        void    setCursorPosition( int x, int y );
        bool    getMouseButton( int button );
        void    setMouseButtons( int button, bool state );
        void    update( void );
        void    clean( void );
    private:
        InputHandler( void );
        ~InputHandler( void ) {};
        static  InputHandler    *instancePtr;
        const Uint8   *keyboardState = SDL_GetKeyboardState(0);
        std::vector<bool>   mouseButtonStates;
        Vector  cursorPosition;
};