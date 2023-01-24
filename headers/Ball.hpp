#pragma once

#define HEIGHT 1080
#define WIDTH 720
#include "GameObject.hpp"
#include "Player.hpp"

class   Ball : public GameObject
{
    public:
        Ball( void ) : GameObject()
        {
            radius = 15;
            velocity.setX(1.0f);
            velocity.setY(1.0f);
            this->position.setX(WIDTH / 2);
            this->position.setY(HEIGHT / 2);
            acceleration.setX(1.0f);
            acceleration.setY(1.0f);
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
