#include <SDL.h>
#include <iostream>
#include "Window.hpp"

int main( int ac, char **av )
{
    (void)ac;
    (void)av;
    Window game;

    if ( game.createWindow() )
        return (EXIT_FAILURE);
    game.gameLoop();
    return (EXIT_SUCCESS);
}