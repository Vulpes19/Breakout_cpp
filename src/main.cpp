#include <SDL.h>
#include <iostream>
#include "Game.hpp"

int main( int ac, char **av )
{
    (void)ac;
    (void)av;
    Game *gameObject = new Game();

    if ( !gameObject->init( "Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 720, 1280 ))
        return (EXIT_FAILURE);
    while ( gameObject->getRunning() )
    {
        gameObject->handleEvents();
        //update();
        gameObject->render();
    }
    delete gameObject;
    return (0);
}