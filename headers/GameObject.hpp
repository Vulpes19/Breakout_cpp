/*
 * =========================================================
 *____   ____     ___   ____  __  _   ___   __ __  ______  
 *|    \ |    \   /  _] /    ||  |/ ] /   \ |  |  ||      |
 *|  o  )|  D  ) /  [_ |  o  ||  ' / |     ||  |  ||      |
 *|     ||    / |    _]|     ||    \ |  O  ||  |  ||_|  |_|
 *|  O  ||    \ |   [_ |  _  ||     \|     ||  :  |  |  |  
 *|     ||  .  \|     ||  |  ||  .  ||     ||     |  |  |  
 *|_____||__|\_||_____||__|__||__|\_| \___/  \__,_|  |__|  
 * 
 * GameObject.hpp by Vulpes19
 * 
 * =========================================================
 */


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