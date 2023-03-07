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
 * AudioManager.hpp: 
 * 
 * =========================================================
 */

#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>
#include <map>

class AudioManager
{
	public:
		static AudioManager    &getInstance( void );
		void	loadSound( std::string ID, std::string fileName );
		void	playSound( std::string key );
		void	setSound( bool s );
	private:
		AudioManager( void );
		~AudioManager( void );
		static AudioManager *instancePtr;
		bool sound;
		std::map<std::string, Mix_Chunk *> sounds;
};
