#include "Window.hpp"

Window::Window( void )
{
	window = nullptr;
	renderer = nullptr;
	running = false;
}

Window::~Window( void )
{
	SDL_DestroyWindow( window );
	SDL_DestroyRenderer( renderer );
	SDL_Quit();
}

int    Window::createWindow( void )
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printErr("Error: SDL failed to initialize: ", SDL_GetError());
		return (EXIT_FAILURE);
	}
	window = SDL_CreateWindow("Ayman's BREAKOUT", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
	if(!window)
	{
		printErr("Error: Failed to open window: ", SDL_GetError());
		return (EXIT_FAILURE);
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(!renderer)
	{
		printErr("Error: Failed to create renderer: ", SDL_GetError());
		return (EXIT_FAILURE);
	}
	running = true;
	return (EXIT_SUCCESS);
}

void	Window::gameLoop( void )
{
	while ( running )
	{
		handleEvents();
		render();
	}
}

void	Window::handleEvents( void )
{
	while ( SDL_PollEvent(&event) )
	{
		if ( event.type == SDL_QUIT )
			running = false;
	}
}

void	Window::render( void )
{
	SDL_RenderClear( renderer );
	SDL_SetRenderDrawColor( renderer, 255, 255, 255, SDL_ALPHA_OPAQUE );
	SDL_RenderPresent( renderer );
}