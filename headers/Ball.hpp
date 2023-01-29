#pragma once

#define HEIGHT 720
#define WIDTH 1080
#include "GameObject.hpp"
#include "Player.hpp"

class   Ball : public GameObject
{
    public:
        Ball( void ) : GameObject()
        {
            radius = 10;
            velocity.setX(0.2f);
            velocity.setY(0.2f);
            this->position.setX(WIDTH / 2);
            this->position.setY(HEIGHT / 2);
            acceleration.setX(0.0f);
            acceleration.setY(0.0f);
        };
        virtual ~Ball( void ) {};
        void    loadTexture( int x, int y, int width, int height, std::string ID );
        void    draw( SDL_Renderer *renderer );
        void    update( void );
        void    wallCollision( void );
        // void    handleCollision( Player &player );
    private:
        double  radius;
};
