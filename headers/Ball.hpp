#pragma once

#include "GameObject.hpp"

class   Ball : public GameObject
{
    public:
        Ball( void ) : GameObject() {};
        ~Ball( void );
        virtual void    loadTexture( int x, int y, int width, int height, std::string ID );
        virtual void    draw( SDL_Renderer *renderer );
        virtual void    update( void );
};