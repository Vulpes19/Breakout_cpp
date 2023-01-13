#pragma once

#include <SDL.h>
#include <iostream>

class GameState
{
    public:
        virtual void    update( void ) = 0;
        virtual void    render( void ) = 0;
        virtual bool    onEnter( void ) = 0;
        virtual bool    onExit( void ) = 0;
        virtual std::string getState( void ) const = 0;
};
