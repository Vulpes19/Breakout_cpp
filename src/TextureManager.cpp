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
    darkTexture = nullptr;
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

void    Texture::draw( std::string ID, int x, int y, int width, int height, SDL_Renderer *renderer, bool brightness )
{
    SDL_Rect    src;
    SDL_Rect    dest;
    SDL_Texture *copy = nullptr;

        copy = textures[ID];
    if ( brightness )
    {
        SDL_Surface *surface = SDL_CreateRGBSurface( 0, width, height, 32, 0, 0, 0, 0 );
        SDL_LockTexture( textures[ID], NULL, &surface->pixels, &surface->pitch );
        for ( int y = 0; y < height; y++ )
        {
            for ( int x = 0; x < width; x++ )
            {
                Uint32 pixel = ((Uint32*)surface->pixels)[y * width + x];
                Uint8 red, green, blue, alpha;
                SDL_GetRGBA( pixel, surface->format, &red, &green, &blue, &alpha );

                red *= 0.5;
                green *= 0.5;
                blue *= 0.5;

                pixel = SDL_MapRGBA( surface->format, red, green, blue, alpha );
                ((Uint32*)surface->pixels)[y * width + x] = pixel;
            }
        }
        SDL_UnlockTexture(textures[ID]);
        textures[ID] = SDL_CreateTextureFromSurface( renderer, surface );
        SDL_FreeSurface(surface);
    }
    else if ( darkTexture )
    {
        SDL_DestroyTexture( darkTexture );
        darkTexture = nullptr;
    }
    src.x = 0;
    src.y = 0;
    src.w = dest.w = width;
    src.h = dest.h = height;
    dest.x = x;
    dest.y = y;

    if ( brightness )
        SDL_RenderCopyEx( renderer, darkTexture, &src, &dest, 0, 0, SDL_FLIP_NONE );
    else
        SDL_RenderCopyEx( renderer, copy, &src, &dest, 0, 0, SDL_FLIP_NONE );

}

// void    Texture::drawFrame( std::string ID, int x, int y, int width, int height, int row, int frame, SDL_Renderer *renderer )
// {
//     SDL_Rect    src;
//     SDL_Rect    dest;
    
//     src.x = width * frame;
//     src.y = height * (frame - 1);
//     src.w = dest.w = width;
//     src.h = dest.h = height;
//     dest.x = x;
//     dest.y = y;

//     row += 1;
//     SDL_RenderCopyEx( renderer, textures[ID], &src, &dest, 0, 0, SDL_FLIP_NONE );
// }