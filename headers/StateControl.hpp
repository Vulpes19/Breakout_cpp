#pragma once

#include "GameStates.hpp"
#include <iostream>
#include <vector>


class   StateControl
{
    public:
        int     update( void );
        void    render( SDL_Renderer *renderer );
        void    pushState( GameState *state );
        void    changeState( GameState *state );
        void    popState( void );
        void    clear( void );
        std::string getState( void ) const;
    private:
        std::vector<GameState *> gameStates;
};