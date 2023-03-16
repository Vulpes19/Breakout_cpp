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
 * Game.hpp by Vulpes19
 * 
 * =========================================================
 */


#pragma once

#define HEIGHT 704
#define WIDTH 1088
#define STANDARD 7
#define LEET 8
#define PYRAMID 9
#define CRAZY 10
#include <SDL.h>
#include <vector>
#include "TextureManager.hpp"
#include "Player.hpp"
#include "Ball.hpp"
#include "InputHandling.hpp"
#include "StateControl.hpp"
#include "GameStates.hpp"
#include "MainMenu.hpp"
#include "PlayState.hpp"
#include "PauseMenu.hpp"
#include "GameOver.hpp"
#include "LevelManager.hpp"
#include "ParticlesManager.hpp"
#include "AudioManager.hpp"
#include "LevelMenu.hpp"
// #include "HighScore.hpp"
#include "SettingsMenu.hpp"
#include "GameWon.hpp"

class Game
{
	public:
		Game( void );
		~Game( void );
		bool    init( const char *, int, int, int, int );
		void    render( void );
		void    handleEvents( void );
		void    clean( void );
		bool    getRunning( void ) const;
		void    update( void );
	private:
		bool running;
		SDL_Event   event;
		SDL_Window  *window;
		SDL_Renderer    *renderer;
		int         currentFrame;
		int score;
		int lives;
		bool    hit;
		bool	sound;
		bool	gameOver;
		bool	gameWon;
		Player  player;
		Ball    ball;
		// HighScore highScore;
		StateControl   *states;
		ParticlesManager *particles;
};
