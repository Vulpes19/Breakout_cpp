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
 * Game.cpp by Vulpes19
 * 
 * =========================================================
 */


#include <iostream>
#include "Game.hpp"
#include "TextManager.hpp"
#define ESC_KEY_PRESSED  InputHandler::getInstance().isKeyPressed(SDL_SCANCODE_ESCAPE)
#define ENTER_KEY_PRESSED  InputHandler::getInstance().isKeyPressed(SDL_SCANCODE_RETURN)
#define STANDARD_HIGHSCORE 544
#define PYRAMID_HIGHSCORE 291
#define LEET_HIGHSCORE 176
#define CRAZY_HIGHSCORE 1139

Game::Game( void )
{
	running = false;
	window = nullptr;
	renderer = nullptr;
	score = 0;
	lives = 3;
	states = new StateControl();
	particles = new ParticlesManager( 10 );
	states->pushState( new MainMenu() );
	hit = false;
	sound = true;
	gameOver = false;
	gameWon = false;
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
	player.loadTexture( WIDTH / 2 - 50, HEIGHT - 20, 100, 20, "paddle" );
	ball.loadTexture( 40, HEIGHT / 2 + 5, 20, 20, "ball" );
	Texture::getInstance().loadImage( "assets/paddle.png", "paddle", renderer );
	Texture::getInstance().loadImage( "assets/ball.png", "ball", renderer );
	Texture::getInstance().loadImage( "assets/restart_icon.png", "restart_icon", renderer );
	Texture::getInstance().loadImage( "assets/quit_icon.png", "quit_icon", renderer );
	Text::getInstance().loadFont( "assets/regular.ttf", "regular" );
	Text::getInstance().loadFont( "assets/slkscr.ttf", "pixelated" );
	Text::getInstance().loadFont( "assets/slkscrb.ttf", "pixelated_bold" );
	AudioManager::getInstance().loadSound( "hit", "assets/hit.wav" );
	AudioManager::getInstance().setSound( sound );
	LevelManager::getInstance().getTexture( renderer );
	return (true);
}

void    Game::render( void )
{
	bool brightness = false;
	if ( states->getState() == "Pause Menu" ) brightness = true;
	SDL_SetRenderDrawColor( renderer, 11, 32, 39, 255 );
	SDL_RenderClear( renderer );
	if ( states->getState() != "Play" )
		states->render( renderer );
	if ( states->getState() == "Play" || states->getState() == "Pause Menu" )
	{
		player.draw( renderer, brightness );
		ball.draw( renderer, brightness );
		if ( particles->getSize() == 0 )
			hit = false;
		if ( hit )
			particles->renderParticles( renderer );
		LevelManager::getInstance().render( renderer, brightness );
		std::string tmp = "Score: " + std::to_string(score);
		SDL_Color color = {165, 145, 50, 255};
		Text::getInstance().writeText("regular", WIDTH - 100, -7, 90, 45, renderer, tmp.c_str(), color, states->getState());
		tmp = "lives: " + std::to_string(lives);
		Text::getInstance().writeText("regular", 2, -7, 90, 45, renderer, tmp.c_str(), color, states->getState());
		tmp = "Highest score: " + std::to_string( highScore.getHighScore() );
		Text::getInstance().writeText("regular", WIDTH / 2 - 60, -7, 120, 45, renderer, tmp.c_str(), color, states->getState());
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
			else if ( states->getState() == "Settings Menu" )
				states->popState();
			else if ( states->getState() == "Game Over" )
			{
				score = 0;
				gameOver = true;
				states->popState();
				states->popState();
				states->popState();
			}
			else if ( states->getState() == "Game Won")
			{
				score = 0;
				gameWon = false;
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
	delete particles;
	delete states;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::update( void )
{
	highScore.openFile();
	highScore.checkScore(score);
	if ( states->getState() == "Play" )
	{
		player.update();
		particles->updateParticles();
		if ( particles->getSize() == 0 )
			hit = false;
		ball.update(player, score, lives, particles, hit, renderer);
	}
	if ( states->update() == REPLAY_BUTTON )
	{
		score = 0;
		lives = 3;
		states->popState();
		states->popState();
		char mode = 's';
		if ( states->getMode() == "standard" )
		{
			mode = 's';
			LevelManager::getInstance().readFile("standard");
		}
		else if ( states->getMode() == "pyramid" )
		{
			mode = 'p';
			LevelManager::getInstance().readFile("pyramid");
		}
		else if ( states->getMode() == "1337" )
		{
			mode = '1';
			LevelManager::getInstance().readFile("1337");
		}
		else if ( states->getMode() == "crazy" )
		{
			mode = 'c';
			LevelManager::getInstance().readFile("crazy");
		}
		player.loadTexture( WIDTH / 2 - 100, HEIGHT - 20, 100, 20, "paddle" );
		ball.loadTexture( 40, HEIGHT / 2 + 5, 20, 20, "ball" );
		ball.setVelocity();
		states->pushState( new PlayState() );
		switch(mode)
		{
			case 's':
			{
				states->setMode("standard");
				break ;
			}
			case 'p':
				states->setMode("pyramid");
				break ;
			case '1':
				states->setMode("1337");
				break ;
			case 'c':
				states->setMode("crazy");
				break ;
			default:
				break ;
		}
	}
	else if ( states->update() == QUIT_BUTTON )
	{
		states->clear();
		running = false;
	}
	else if ( states->update() == MODE_BUTTON )
		states->pushState( new LevelMenu() );
	else if ( states->update() == SETTINGS_BUTTON )
	{
		states->pushState( new SettingsMenu() );
		states->setSound(sound);
	}
	else if ( states->update() == SOUND )
	{
		if ( sound ) sound = false;
		else sound = true;
		states->setSound(sound);
		AudioManager::getInstance().setSound(sound);
	}
	else if ( states->update() == STANDARD )
	{
		player.loadTexture( WIDTH / 2 - 100, HEIGHT - 20, 100, 20, "paddle" );
		ball.loadTexture( 40, HEIGHT / 2 + 5, 20, 20, "ball" );
		ball.setVelocity();
		LevelManager::getInstance().readFile("standard");
		states->pushState( new PlayState() );
		states->setMode("standard");
	}
	else if ( states->update() == PYRAMID )
	{
		player.loadTexture( WIDTH / 2 - 100, HEIGHT - 20, 100, 20, "paddle" );
		ball.loadTexture( 40, HEIGHT / 2 + 5, 20, 20, "ball" );
		ball.setVelocity();
		LevelManager::getInstance().readFile("pyramid");
		states->pushState( new PlayState() );
		states->setMode("pyramid");
	}
	else if ( states->update() == LEET )
	{
		player.loadTexture( WIDTH / 2 - 100, HEIGHT - 20, 100, 20, "paddle" );
		ball.loadTexture( 40, HEIGHT / 2 + 5, 20, 20, "ball" );
		ball.setVelocity();
		LevelManager::getInstance().readFile("1337");
		states->pushState( new PlayState() );
		states->setMode("1337");
	}
	else if ( states->update() == CRAZY )
	{
		player.loadTexture( WIDTH / 2 - 100, HEIGHT - 20, 100, 20, "paddle" );
		ball.loadTexture( 40, HEIGHT / 2 + 5, 20, 20, "ball" );
		ball.setVelocity();
		LevelManager::getInstance().readFile("crazy");
		states->pushState( new PlayState() );
		states->setMode("crazy");
	}
	if ( lives == 0 && gameOver == false && states->getState() != "Game Over" )
	{
		gameWon = true;
		states->pushState(new GameOver());
	}
	if ( score == STANDARD_HIGHSCORE && states->getMode() == "standard" && gameWon == false && states->getState() != "Game Won" )
	{
		gameWon = true;
		states->pushState(new GameWon());
	}
	if ( score == LEET_HIGHSCORE && states->getMode() == "1337" && gameWon == false && states->getState() != "Game Won" )
	{
		gameWon = true;
		states->pushState(new GameWon());
	}
	if ( score == PYRAMID_HIGHSCORE && states->getMode() == "pyramid" && gameWon == false && states->getState() != "Game Won" )
	{
		gameWon = true;
		states->pushState(new GameWon());
	}
	if ( score == CRAZY_HIGHSCORE && states->getMode() == "crazy" && gameWon == false && states->getState() != "Game Won" )
	{
		gameWon = true;
		states->pushState(new GameWon());
	}
}

bool    Game::getRunning( void ) const { return (running); }