#include <SDL.h>
#include <iostream>
#include "Game.hpp"

const   int FPS = 60;
const   int DELAY = 1000.0f / FPS;

int main( int ac, char **av )
{
    Uint32 frameStart;
    Uint32 frameTime;

    frameStart = SDL_GetTicks();
    (void)ac;
    (void)av;
    Game *theGame = new Game();

    if ( !theGame->init( "Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 720, 1080 ))
        return (EXIT_FAILURE);
    while ( theGame->getRunning() )
    {
        theGame->handleEvents();
        theGame->render();
        theGame->update();
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < DELAY)
            SDL_Delay((int)(DELAY - frameTime));
    }
    delete theGame;
    return (0);
}