#include "Window.hpp"

Window::Window( void )
{
	window = nullptr;
	renderer = nullptr;
	running = false;
	level = 1;
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
	lvl = new Map( std::to_string(level) );
	bricks = new Texture( "/Users/asus/Documents/Breakout/assets/bricks.png" );
	empty = new Texture( "/Users/asus/Documents/Breakout/assets/empty.png" );
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
	int	x, y;
	std::string	bricksText = "bricks";
	std::string	emptyText = "empty";
	SDL_Texture	*tmp;
	SDL_RenderClear( renderer );

	x = 0;
	y = 0;
	bricks->createTexture( renderer );
	empty->createTexture( renderer );
	tmp = bricks->getTexture();
	SDL_RenderCopy( renderer, tmp, NULL, &lvl->pos );
	SDL_RenderPresent( renderer );
	SDL_Delay(10);
	exit(1);
	std::cout << "hello" << std::endl;
	while (lvl->map[y])
	{
		x = 0;
		while (lvl->map[y][x])
		{
			std::cout << lvl->map[y][x];
			lvl->pos.x = x * 40;
			lvl->pos.y = y * 40;
			if (lvl->map[y][x] == '1')
				tmp = bricks->getTexture();
			else
				tmp = empty->getTexture();
			SDL_RenderCopy( renderer, tmp, NULL, &lvl->pos );
			SDL_RenderPresent( renderer );
			x++; 
		}
		std::cout << std::endl;
		y++;
	}
	//SDL_SetRenderDrawColor( renderer, 255, 255, 255, SDL_ALPHA_OPAQUE );
	//SDL_RenderPresent( renderer );
}