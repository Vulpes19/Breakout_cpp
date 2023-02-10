#pragma once

#include "Game.hpp"
#include "GameStates.hpp"

class   MainMenu : public GameState
{
    public:
        MainMenu( void );
        void    update( void );
        void    render( SDL_Renderer *renderer );
        bool    onEnter( void );
        bool    onExit( void );
        std::string getState( void ) const;
    private:
        static  const   std::string state;
        SDL_Color   color_title;
        SDL_Color   color_button1;
        SDL_Color   color_button2;
        SDL_Color   color_button3;
};