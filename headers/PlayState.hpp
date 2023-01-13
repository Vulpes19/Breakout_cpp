#pragma once

#include "GameStates.hpp"

class   PlayState : public GameState
{
   public:
        virtual void    update( void );
        virtual void    render( void );
        virtual bool    onEnter( void );
        virtual bool    onExit( void );
        virtual std::string getState( void ) const;
    private:
        static  const   std::string state;
};