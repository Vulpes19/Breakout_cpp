#include "AudioManager.hpp"
#include <string>

AudioManager *AudioManager::instancePtr = nullptr;

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
    SDL_AudioSpec audioSpec;
    Uint32 audioLength;
    Uint8 *audioBuffer;

    if ( SDL_LoadWAV( fileName.c_str(), &audioSpec, &audioBuffer, &audioLength) == nullptr )
        std::cerr << "failed to load sound file: " << SDL_GetError() << std::endl;
    sounds[ID] = std::make_pair(audioSpec, audioBuffer);
}

void    AudioManager::playSound( std::string ID )
{
    if ( sounds.count( ID ) > 0 )
    {
        std::pair< SDL_AudioSpec, Uint8 * > data = sounds[ID];
        SDL_QueueAudio(1, data.second, data.first.size );
        SDL_PauseAudio(0);
    }
}