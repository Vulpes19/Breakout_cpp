#include "StateControl.hpp"

void    StateControl::update( void )
{
    if ( !gameStates.empty() )
    {
        gameStates.back()->update();
    }
}

void    StateControl::render( void )
{
    if ( !gameStates.empty() )
    {
        gameStates.back()->render();
    }
}

void    StateControl::pushState( GameState *state )
{
    gameStates.push_back(state);
    gameStates.back()->onEnter();
}

void    StateControl::popState( void )
{
    if ( !gameStates.empty() )
    {
        if ( gameStates.back()->onExit() )
        {
            delete gameStates.back();
            gameStates.pop_back();
        }
    }
}

void    StateControl::changeState( GameState *state )
{
    if ( !gameStates.empty() )
    {
        if ( gameStates.back()->getState() == state->getState() )
            return ;
        if ( gameStates.back()->onExit() )
        {
            delete gameStates.back();
            gameStates.pop_back();
        }
    }
    gameStates.push_back(state);
    gameStates.back()->onEnter();
}