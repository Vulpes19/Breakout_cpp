#pragma once

#define HEIGHT 704
#define WIDTH 1088
#define REPLAY_BUTTON 3
#define QUIT_BUTTON 4
#define NO_BUTTON 5
#define MODE_BUTTON 6
#define PLAY_BUTTON 7
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
#include "ParticleSystem.hpp"
#include "AudioManager.hpp"
#include "LevelMenu.hpp"


class Game
{
    public:
        Game( void );
        ~Game( void );
        bool    init( const char *, int, int, int, int );
        void    render( void );
        void    handleEvents( void );
        void    clean( void );
        bool    getRunning( void ) { return (running); };
        void    update( void );
    private:
        bool running;
        SDL_Event   event;
        SDL_Window  *window;
        SDL_Renderer    *renderer;
        int         currentFrame;
        Player  player;
        Ball    ball;
        StateControl   *states;
        int score;
        int lives;
        std::vector<Particles> particles;
        bool    hit;
};
