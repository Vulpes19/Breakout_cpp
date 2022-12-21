#pragma once

#include <SDL.h>

class Game
{
    public:
        Game( void );
        ~Game( void );
        bool    init( const char *, int, int, int, int );
        void    render( void );
        void    handleEvents( void );
        void    clean( void );
        bool    getRunning( void ) { return (running); };
    private:
        bool running;
        SDL_Event   event;
        SDL_Window  *window;
        SDL_Renderer    *renderer;
};
