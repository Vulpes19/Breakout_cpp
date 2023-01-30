#pragma once

#include "GameStates.hpp"

class   MainMenu : public GameState
{
    public:
        void    update( void );
        void    render( void );
        bool    onEnter( void );
        bool    onExit( void );
        std::string getState( void ) const;
    private:
        static  const   std::string state;
};