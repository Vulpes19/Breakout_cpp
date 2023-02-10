#pragma once

#define HEIGHT 704
#define WIDTH 1088
#include "GameObject.hpp"
#include "Player.hpp"
#include "LevelManager.hpp"

class   Ball : public GameObject
{
    public:
        Ball( void );
        virtual ~Ball( void ) {};
        void    loadTexture( int x, int y, int width, int height, std::string ID );
        void    draw( SDL_Renderer *renderer );
        void    update( Player &player, int &score, int &lives );
        void    wallCollision( Player &player, int &lives, int &score );
        void    bricksCollision( int &score );
    private:
        double  radius;
};
