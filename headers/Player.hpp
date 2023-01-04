#pragma once

#include "GameObject.hpp"

class Player : public GameObject
{
    public:
        Player( void ) : GameObject() {};
        ~Player( void ) {};
        void    loadTexture( int x, int y, int width, int height, std::string ID );
        void    draw( SDL_Renderer *renderer);
        void    update( void ) {};
};