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
 * Player.hpp by Vulpes19
 * 
 * =========================================================
 */


#pragma once

#include "GameObject.hpp"
// #include <pair>

class Player : public GameObject
{
	public:
		Player( void ) : GameObject() {};
		~Player( void ) {};
		Vector  &getPosition() { return (position); };
		void    setPosition( float x, float y ) { position.setX(x); position.setY(y); };
		void    loadTexture( int x, int y, int width, int height, std::string ID );
		void    draw( SDL_Renderer *renderer, bool brightness);
		void    handleInput( void );
		void    update( void );
		std::pair<int, int>    getDimensions( void );
	private:
		int	width;
		int	height;
};