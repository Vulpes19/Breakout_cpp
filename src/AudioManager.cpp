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
 * AudioManager.cpp: 
 * 
 * =========================================================
 */

#include "AudioManager.hpp"
#include <string>

AudioManager *AudioManager::instancePtr = nullptr;

AudioManager::AudioManager( void )
{
    if ( Mix_Init( MIX_INIT_MP3 ) < 0 )
    {
        std::cerr << "failed to initialize SDL Mixer: " << Mix_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    if ( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) != 0 )
    {
        std::cerr << "Failed to open audio device: " << SDL_GetError() << std::endl;
        exit( EXIT_FAILURE );
    }
}

AudioManager::~AudioManager( void )
{
    sounds.clear();
    Mix_CloseAudio();
}

AudioManager    &AudioManager::getInstance( void )
{
    if ( instancePtr == nullptr )
    {
        instancePtr = new AudioManager();
        return (*instancePtr);
    }
    return (*instancePtr);
}

void    AudioManager::loadSound( std::string ID, std::string fileName )
{
    Mix_Chunk *sound = Mix_LoadWAV(fileName.c_str());
    if ( sound == nullptr )
        std::cerr << "failed to load sound file: " << SDL_GetError() << std::endl;
    sounds[ID] = sound;
}

void    AudioManager::playSound( std::string ID )
{
    if ( sounds.count( ID ) > 0 && sound )
    {
        Mix_PlayChannel(-1, sounds[ID], 0); 
    }
}

void	AudioManager::setSound( bool s ) { sound = s; }