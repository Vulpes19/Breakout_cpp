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
	private:
		AudioManager( void );
		~AudioManager( void );
		static AudioManager *instancePtr;
		std::map<std::string, Mix_Chunk *> sounds;
};
