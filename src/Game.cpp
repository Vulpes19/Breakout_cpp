#include <iostream>
#include "Game.hpp"

Game::Game( void )
{
    running = false;
    window = nullptr;
    renderer = nullptr;
}

Game::~Game( void )
{
    clean();
}

bool    Game::init( const char *windowTitle, int xpos, int ypos, int height, int width )
{
    if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        std::cerr << "Unable to initialize SDL subsystems: " << SDL_GetError() << std::endl;
        return (false);
    }
    window = SDL_CreateWindow( windowTitle, xpos, ypos, width, height, SDL_WINDOW_SHOWN );
    if ( !window )
    {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        return (false);
    }
    renderer = SDL_CreateRenderer( window, -1, 0 );
     if ( !renderer )
    {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        return (false);
    }
    running = true;
    Texture::getInstance().loadImage("assets/paddle.png", "paddle", renderer );
    player.loadTexture( 0, 0, 80, 20, "paddle" );
    return (true);
}

void    Game::render( void )
{
    SDL_SetRenderDrawColor( renderer, 255, 255, 0, 0 );
    SDL_RenderClear( renderer );
    player.draw( renderer );
    player.update();
    //Texture::getInstance().draw( "paddle", 0, 0, 80, 20, renderer );
    SDL_RenderPresent( renderer );
}

void    Game::handleEvents( void )
{
    while ( SDL_PollEvent(&event))
    {
        if ( event.type == SDL_QUIT )
            running = false;
        player.handleInput();
    }
}

void    Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Game::update( void )
{
    currentFrame = int(((SDL_GetTicks() / 100) % 6));
}