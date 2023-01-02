#pragma once

#include <SDL.h>
#include <iostream>

class GameObject
{
    public:
        GameObject( void ) : x(0), y(0), w(0), h(0), row(0), frame(0), texture("") {};
        ~GameObject( void );
        void    loadTexture( int x, int y, int width, int height, std::string ID );
        void    draw( SDL_Renderer *renderer );
        void    update( void );
    protected:
        std::string texture;
        int frame;
        int row;
        int x;
        int y;
        int w;
        int h;
};