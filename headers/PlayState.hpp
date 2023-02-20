#pragma once

#include "GameStates.hpp"


class   PlayState : public GameState
{
   public:
        bool    update( void );
        void    render( SDL_Renderer *renderer );
        bool    onEnter( void );
        bool    onExit( void );
        std::string getState( void ) const;
    private:
        static  const   std::string state;
};