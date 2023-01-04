#pragma once

#include <SDL.h>
#include "TextureManager.hpp"
#include <iostream>

class GameObject
{
    public:
        GameObject( void ) : x(0), y(0), w(0), h(0), row(0), frame(0), texture("") {};
        virtual ~GameObject( void ) {};
        virtual void    loadTexture( int x, int y, int width, int height, std::string ID );
        virtual void    draw( SDL_Renderer *renderer );
        virtual void    update( void ) {};
    protected:
        int x;
        int y;
        int w;
        int h;
        int row;
        int frame;
        std::string texture;
};