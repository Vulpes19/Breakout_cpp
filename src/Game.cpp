#include <iostream>
#include "Game.hpp"
#include "TextManager.hpp"

Game::Game( void )
{
    running = false;
    window = nullptr;
    renderer = nullptr;
    states = new StateControl();
    // states->pushState( play );
    states->pushState( new MainMenu() ); 
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
    Texture::getInstance().loadImage("assets/ball.png", "ball", renderer );
    player.loadTexture( 0, HEIGHT - 20, 100, 20, "paddle" );
    ball.loadTexture( WIDTH / 2, HEIGHT / 2 + 5, 20, 20, "ball" );
    // ball.loadTexture( 0, 0, 20, 20, "ball" );
    LevelManager::getInstance().readFile("1");
    LevelManager::getInstance().getTexture(renderer);
    Text::getInstance().loadFont("assets/regular.ttf", "regular");
    return (true);
}

void    Game::render( void )
{
    SDL_SetRenderDrawColor( renderer, 11, 32, 39, 0 );
    SDL_RenderClear( renderer );
    if ( states->getState() == "Main Menu")
        states->render( renderer );
    else if ( states->getState() == "Play")
    {
        states->render( renderer );
        player.draw( renderer );
        ball.draw( renderer );
        LevelManager::getInstance().render( renderer );
    }
    SDL_RenderPresent( renderer );
}

void    Game::handleEvents( void )
{
    while ( SDL_PollEvent(&event))
    {
        if ( event.type == SDL_QUIT )
            running = false;
        if ( event.type == SDL_MOUSEMOTION )
            InputHandler::getInstance().setCursorPosition(event.motion.x, event.motion.y);
        if ( event.type == SDL_MOUSEBUTTONDOWN )
        {
            if ( event.button.button == SDL_BUTTON_LEFT )
            {
                InputHandler::getInstance().setMouseButtons(LEFT, true);
                   Vector cursor = InputHandler::getInstance().getCursorPosition();
                if ( cursor.getX() >= WIDTH / 2 - 80 && cursor.getX() <= WIDTH / 2 - 80 + 140 && cursor.getY() >= HEIGHT / 2 - 80 && cursor.getY() <= HEIGHT / 2 - 80 + 70)
                    states->changeState(new PlayState());
            }
            if ( event.button.button == SDL_BUTTON_RIGHT )
                InputHandler::getInstance().setMouseButtons(RIGHT, true);
            if ( event.button.button == SDL_BUTTON_MIDDLE )
                InputHandler::getInstance().setMouseButtons(MIDDLE, true);
        }
        if ( event.type == SDL_MOUSEBUTTONUP )
        {
            if ( event.button.button == SDL_BUTTON_LEFT )
                InputHandler::getInstance().setMouseButtons(LEFT, false);
            if ( event.button.button == SDL_BUTTON_RIGHT )
                InputHandler::getInstance().setMouseButtons(RIGHT, false);
            if ( event.button.button == SDL_BUTTON_MIDDLE )
                InputHandler::getInstance().setMouseButtons(MIDDLE, false);
        }
        if ( InputHandler::getInstance().isKeyPressed(SDL_SCANCODE_RETURN) )
            states->changeState( new PlayState() );
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
    states->update();
    if ( states->getState() == "Play")
    {
        player.update();
        ball.update(player);
    }
}