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
 * Ball.hpp by Vulpes19
 * 
 * =========================================================
 */


#pragma once

#define HEIGHT 704
#define WIDTH 1088
#include "GameObject.hpp"
#include "Player.hpp"
#include "LevelManager.hpp"
#include "ParticleSystem.hpp"

class   Ball : public GameObject
{
    public:
        Ball( void );
        virtual ~Ball( void ) {};
        void    loadTexture( int x, int y, int width, int height, std::string ID );
        void    draw( SDL_Renderer *renderer, bool brightness );
        void    update( Player &player, int &score, int &lives, std::vector<Particles> &particles, bool &hit, SDL_Renderer *renderer );
        void    wallCollision( Player &player, int &lives, int &score );
        void    bricksCollision( int &score, std::vector<Particles> &particles, bool &hit, SDL_Renderer *renderer );
        void    setVelocity( void );
    private:
        double  radius;
};
