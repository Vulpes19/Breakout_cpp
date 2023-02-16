#pragma once

#include "GameStates.hpp"

class PopUp : public GameState
{
    public:
        PopUp( void );
        void    update( void );
        void    render( SDL_Renderer *renderer );
        bool    onEnter( void );
        bool    onExit( void );
        std::string getState( void ) const;
    private:
        static  const   std::string state;
};