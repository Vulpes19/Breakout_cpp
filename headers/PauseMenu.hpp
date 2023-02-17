#pragma once

#include "Game.hpp"
#include "GameStates.hpp"

class PauseMenu : public GameState
{
    public:
        PauseMenu( void );
         void    update( void );
        void    render( SDL_Renderer *renderer );
        bool    onEnter( void );
        bool    onExit( void );
        std::string getState( void ) const;
    private:
        static  const   std::string state;
        SDL_Color       textColor;
};