#pragma once

#include <SDL.h>
#include "TextureManager.hpp"
#include <iostream>
#include "Vector.hpp"

class GameObject
{
    public:
        GameObject( void ) : w(0), h(0), row(0), frame(0), texture("") {};
        virtual ~GameObject( void ) {};
        virtual void    loadTexture( int x, int y, int width, int height, std::string ID );
        virtual void    draw( SDL_Renderer *renderer, bool brightness );
        virtual void    update( void );
    protected:
        Vector  position;
        Vector  velocity;
        Vector  acceleration;
        int w;
        int h;
        int row;
        int frame;
        std::string texture;
};