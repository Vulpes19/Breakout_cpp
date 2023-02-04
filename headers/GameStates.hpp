#pragma once

#include <SDL.h>
#include <iostream>

enum states
{
    MAIN = 0,
    PLAY = 1,
    PAUSE = 2,
    OVER = 3
};
class GameState
{
    public:
        virtual ~GameState( void ) {};
        virtual void    update( void ) = 0;
        virtual void    render( SDL_Renderer *renderer ) = 0;
        virtual bool    onEnter( void ) = 0;
        virtual bool    onExit( void ) = 0;
        virtual std::string getState( void ) const = 0;
};
