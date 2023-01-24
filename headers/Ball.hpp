#pragma once

#include "GameObject.hpp"
#include "Player.hpp"

class   Ball : public GameObject
{
    public:
        Ball( void ) : GameObject() {};
        virtual ~Ball( void ) {};
        void    loadTexture( int x, int y, int width, int height, std::string ID );
        void    draw( SDL_Renderer *renderer );
        void    update( void );
        // void    handleCollision( Player &player );
    private:
        double  radius;
};
