#include "Texture.hpp"

Texture::Texture( const char *path )
{
    texture = nullptr;
    surface = nullptr;
    if ( !(IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ))
    {
        printErr("Failed to initialize SDL_image: ", IMG_GetError());
        return ;
    }
    surface = IMG_Load( path );
    if ( !surface )
    {
        printErr("Failed to load surface from path: ", IMG_GetError());
        return ;
    }
}

Texture::~Texture( void )
{
    SDL_FreeSurface( surface );
    SDL_DestroyTexture( texture );
    IMG_Quit();
}

void Texture::createTexture( SDL_Renderer *renderer )
{
    if ( texture )
        SDL_DestroyTexture( texture );
    texture = SDL_CreateTextureFromSurface( renderer, surface );
    if ( !texture )
    {
        printErr("Failed to create texture from surface: ", IMG_GetError());
        SDL_FreeSurface( surface );
        return ;
    }
}