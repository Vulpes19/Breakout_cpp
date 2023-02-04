#pragma once

#include "GameStates.hpp"
#include <iostream>
#include <vector>

class   StateControl
{
    public:
        void    update( void );
        void    render( SDL_Renderer *renderer );
        void    pushState( GameState *state );
        void    changeState( GameState *state );
        void    popState( void );
        std::string getState( void ) const;
    private:
        std::vector<GameState *> gameStates;
};