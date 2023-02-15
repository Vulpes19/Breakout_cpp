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
        void    draw( SDL_Renderer *renderer );
        void    update( Player &player, int &score, int &lives, std::vector<Particles> &particles, bool &hit, SDL_Renderer *renderer );
        void    wallCollision( Player &player, int &lives, int &score );
        void    bricksCollision( int &score, std::vector<Particles> &particles, bool &hit, SDL_Renderer *renderer );
    private:
        double  radius;
};
