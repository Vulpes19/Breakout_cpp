#pragma once

#include "GameObject.hpp"

class Player : public GameObject
{
    public:
        Player( void ) : GameObject() {};
        ~Player( void ) {};
        Vector  &getPosition() { return (position); };
        void    loadTexture( int x, int y, int width, int height, std::string ID );
        void    draw( SDL_Renderer *renderer);
        void    handleInput( void );
        void    update( void );
};