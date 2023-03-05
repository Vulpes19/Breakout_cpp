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
 * StateControl.hpp: 
 * 
 * =========================================================
 */

#pragma once

#include "GameStates.hpp"
#include <iostream>
#include <vector>

class   StateControl
{
    public:
        int     update( void );
        void    render( SDL_Renderer *renderer );
        void    pushState( GameState *state );
        void    changeState( GameState *state );
        void    popState( void );
        void    clear( void );
        std::string getState( void ) const;
        std::string getMode( void ) const;
        void    setMode( std::string s );
        void    setSound( bool );
    private:
        std::vector<GameState *> gameStates;
};