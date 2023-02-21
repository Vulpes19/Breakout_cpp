#include "AudioManager.hpp"

AudioManager::instancePtr = nullptr;

AudioManager::AudioManager( void )
{
     SDL_AudioSpec desiredSpec;
    SDL_AudioSpec obtainedSpec;
    desiredSpec.freq = 44100;
    desiredSpec.format = AUDIO_S16SYS;
    desiredSpec.channels = 2;
    desiredSpec.samples = 2048;
    desiredSpec.callback = nullptr;
    desiredSpec.userdata = nullptr;

    if ( SDL_OpenAudio( &desiredSpec, &obtainedSpec ) != 0 )
    {
        std::cerr << "Failed to open audio device: " << SDL_GetError() << std::endl;
        exit( EXIT_FAILURE );
    }
}

AudioManager::~AudioManager( void )
{
    SDL_CloseAudio();
}

AudioManager