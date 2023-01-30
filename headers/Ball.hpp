#pragma once

#define HEIGHT 704
#define WIDTH 1088
#include "GameObject.hpp"
#include "Player.hpp"

class   Ball : public GameObject
{
    public:
        Ball( void );
        virtual ~Ball( void ) {};
        void    draw( SDL_Renderer *renderer );
        void    update( Player &player );
        void    wallCollision( Player &player );
        // void    handleCollision( Player &player );
    private:
        double  radius;
};
