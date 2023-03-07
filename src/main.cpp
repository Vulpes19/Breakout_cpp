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
 * main.cpp: 
 * 
 * =========================================================
 */

#include <SDL.h>
#include <iostream>
#include <memory>
#include "Game.hpp"

const   int FPS = 60;
const   int DELAY = 1000.0f / FPS;

int main( int ac, char **av )
{
    Uint32 frameStart;
    Uint32 frameTime;

    srand(time(0));
    frameStart = SDL_GetTicks();
    (void)ac;
    (void)av;
    Game *theGame = new Game();

    if ( !theGame->init( "Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 704, 1088 ))
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