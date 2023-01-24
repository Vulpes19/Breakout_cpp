#include "TextureManager.hpp"

Texture *Texture::instancePtr = nullptr;

Texture  &Texture::getInstance( void )
{
    if ( instancePtr == nullptr )
    {
        instancePtr = new Texture();
        return (*instancePtr);
    }
    
    return (*instancePtr);
}

Texture::Texture( void )
{
    if ( IMG_Init( IMG_INIT_PNG ) < 0 )
    {
        std::cerr << "Unable to initialize SDL image: " << IMG_GetError() << std::endl;
        return ;
    }

}

bool Texture::loadImage( std::string fileName, std::string ID, SDL_Renderer *renderer )
{
    SDL_Surface *tmp = IMG_Load(fileName.c_str());
    if ( !tmp )
    {
        std::cerr << "Unable to load image from file " << fileName << " " << IMG_GetError() << std::endl;
        return (false);
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface( renderer, tmp );
    if ( !tmp )
    {
        std::cerr << "Unable to create Texture from Surface: " << IMG_GetError() << std::endl;
        SDL_FreeSurface(tmp);
        return (false);
    }
    SDL_FreeSurface(tmp);
    textures[ID] = texture;
    return (true);
}

void    Texture::draw( std::string ID, int x, int y, int width, int height, SDL_Renderer *renderer )
{
    SDL_Rect    src;
    SDL_Rect    dest;

    src.x = 0;
    src.y = 0;
    src.w = dest.w = width;
    src.h = dest.h = height;
    dest.x = x;
    dest.y = y;

    SDL_RenderCopyEx( renderer, textures[ID], &src, &dest, 0, 0, SDL_FLIP_NONE );

}

void    Texture::drawFrame( std::string ID, int x, int y, int width, int height, int row, int frame, SDL_Renderer *renderer )
{
    SDL_Rect    src;
    SDL_Rect    dest;
    
    src.x = width * frame;
    src.y = height * (frame - 1);
    src.w = dest.w = width;
    src.h = dest.h = height;
    dest.x = x;
    dest.y = y;

    row += 1;
    SDL_RenderCopyEx( renderer, textures[ID], &src, &dest, 0, 0, SDL_FLIP_NONE );
}