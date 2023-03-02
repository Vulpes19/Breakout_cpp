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
 * Game.cpp: 
 * 
 * =========================================================
 */

#include <iostream>
#include "Game.hpp"
#include "TextManager.hpp"
#define ESC_KEY_PRESSED  InputHandler::getInstance().isKeyPressed(SDL_SCANCODE_ESCAPE)
#define ENTER_KEY_PRESSED  InputHandler::getInstance().isKeyPressed(SDL_SCANCODE_RETURN)

Game::Game( void )
{
    running = false;
    window = nullptr;
    renderer = nullptr;
    score = 0;
    lives = 3;
    states = new StateControl();
    states->pushState( new MainMenu() );
    particles.reserve(10);
    hit = false;
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
    Texture::getInstance().loadImage("assets/restart_icon.png", "restart_icon", renderer );
    Texture::getInstance().loadImage("assets/quit_icon.png", "quit_icon", renderer );
    player.loadTexture( WIDTH / 2 - 100, HEIGHT - 20, 100, 20, "paddle" );
    ball.loadTexture( 40, HEIGHT / 2 + 5, 20, 20, "ball" );
    LevelManager::getInstance().getTexture(renderer);
    Text::getInstance().loadFont("assets/regular.ttf", "regular");
    Text::getInstance().loadFont("assets/slkscr.ttf", "pixelated");
    Text::getInstance().loadFont("assets/slkscrb.ttf", "pixelated_bold");
    AudioManager::getInstance().loadSound( "hit", "assets/hit.wav" );
    // highScore.openFile();
    return (true);
}

void    Game::render( void )
{
    bool brightness = false;
    if ( states->getState() == "Pause Menu" ) brightness = true;
    SDL_SetRenderDrawColor( renderer, 11, 32, 39, 255 );
    SDL_RenderClear( renderer );
    if ( lives == 0 && states->getState() != "Game Over" )
        states->pushState(new GameOver());
    if ( states->getState() != "Play" )
        states->render( renderer );
    if ( states->getState() == "Play" || states->getState() == "Pause Menu" )
    {
        player.draw( renderer, brightness );
        ball.draw( renderer, brightness );
        if ( particles.size() == 0 )
            hit = false;
        if ( hit )
        {
            for ( int i = 0; i < 10; i++ )
                particles[i].render( renderer );
        }
        LevelManager::getInstance().render( renderer, brightness );
        std::string tmp = "Score: " + std::to_string(score);
        SDL_Color color = {165, 145, 50, 255};
        Text::getInstance().writeText("regular", WIDTH - 100, -7, 90, 45, renderer, tmp.c_str(), color, states->getState());
        tmp = "lives: " + std::to_string(lives);
        Text::getInstance().writeText("regular", 2, -7, 90, 45, renderer, tmp.c_str(), color, states->getState());
    }
    SDL_RenderPresent( renderer );
}

void    Game::handleEvents( void )
{
    while ( SDL_PollEvent(&event) )
    {
        if ( event.type == SDL_QUIT )
            running = false;
        if ( event.type == SDL_MOUSEMOTION )
            InputHandler::getInstance().setCursorPosition(event.motion.x, event.motion.y);
        if ( event.type == SDL_MOUSEBUTTONDOWN )
        {
            if ( event.button.button == SDL_BUTTON_LEFT )
                InputHandler::getInstance().setMouseButtons(LEFT, true);
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
        if ( ESC_KEY_PRESSED )
        {
            if ( states->getState() == "Play" )
                states->pushState(new PauseMenu());   
            else if ( states->getState() == "Pause Menu" )
            {
                states->popState();
                states->popState();
                states->popState();
            }
        }
        if ( ENTER_KEY_PRESSED && states->getState() == "Pause Menu" )
            states->popState();
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
    // currentFrame = int(((SDL_GetTicks() / 100) % 6));
    highScore.openFile();
    highScore.checkScore(score);
    if ( states->getState() == "Play" )
    {
        player.update();
        for ( int i = 0; i < 10; i++ )
        {
            particles[i].update();
            if ( particles[i].getLife() <= 0 )
                particles.pop_back();
        }
        if ( particles.size() == 0 )
            hit = false;
        ball.update(player, score, lives, particles, hit, renderer);
    }
    if ( states->update() == REPLAY_BUTTON )
    {
        score = 0;
        lives = 3;
        states->popState();
        states->popState();
        if ( states->getMode() == "standard" ) LevelManager::getInstance().readFile("standard");
        else if ( states->getMode() == "pyramid" ) LevelManager::getInstance().readFile("pyramid");
        else if ( states->getMode() == "1337" ) LevelManager::getInstance().readFile("1337");
        else if ( states->getMode() == "crazy" ) LevelManager::getInstance().readFile("crazy");
        player.loadTexture( WIDTH / 2 - 100, HEIGHT - 20, 100, 20, "paddle" );
        ball.loadTexture( 40, HEIGHT / 2 + 5, 20, 20, "ball" );
        states->pushState( new PlayState() );
    }
    else if ( states->update() == QUIT_BUTTON )
    {
        states->clear();
        running = false;
    }
    else if ( states->update() == MODE_BUTTON )
        states->pushState( new LevelMenu() );
    else if ( states->update() == STANDARD )
    {
        player.loadTexture( WIDTH / 2 - 100, HEIGHT - 20, 100, 20, "paddle" );
        ball.loadTexture( 40, HEIGHT / 2 + 5, 20, 20, "ball" );
        LevelManager::getInstance().readFile("standard");
        states->pushState( new PlayState() );
    }
    else if ( states->update() == PYRAMID )
    {
        player.loadTexture( WIDTH / 2 - 100, HEIGHT - 20, 100, 20, "paddle" );
        ball.loadTexture( 40, HEIGHT / 2 + 5, 20, 20, "ball" );
        LevelManager::getInstance().readFile("pyramid");
        states->pushState( new PlayState() );
    }
    else if ( states->update() == LEET )
    {
        player.loadTexture( WIDTH / 2 - 100, HEIGHT - 20, 100, 20, "paddle" );
        ball.loadTexture( 40, HEIGHT / 2 + 5, 20, 20, "ball" );
        LevelManager::getInstance().readFile("1337");
        states->pushState( new PlayState() );
    }
    else if ( states->update() == CRAZY )
    {
        player.loadTexture( WIDTH / 2 - 100, HEIGHT - 20, 100, 20, "paddle" );
        ball.loadTexture( 40, HEIGHT / 2 + 5, 20, 20, "ball" );
        LevelManager::getInstance().readFile("crazy");
        states->pushState( new PlayState() );
    }
}