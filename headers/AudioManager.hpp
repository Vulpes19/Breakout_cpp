#pragma once

#include <SDL.h>
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
		~AudioManager( void ) {};
		static AudioManager *instancePtr;
		std::map<std::string, std::pair<SDL_AudioSpec, Uint8 *>> sounds;
		SDL_AudioSpec audioSpec;
		Uint32 audioLength;
		Uint8* audioBuffer;
};
