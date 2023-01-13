#pragma once

#include "GameStates.hpp"
#include <iostream>
#include <vector>

class   StateControl
{
    public:
        void    pushState( GameState *state );
        void    changeState( GameState *state );
        void    popState( void );
    private:
        std::vector<GameState *> gameStates;
};