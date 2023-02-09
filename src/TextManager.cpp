#include <TextManager.hpp>

Text    *Text::instancePtr = nullptr;

Text    &Text::getInstance( void )
{
    if ( instancePtr == nullptr )
    {
        instancePtr = new Text();
        return (*instancePtr);
    }
    return (*instancePtr);
}

Text::Text( void )
{
    if ( TTF_Init() < 0 )
    {
        std::cerr << "Unable to initialize SDL TTF" << TTF_GetError() << std::endl;
        return ;
    }
}

Text::~Text( void )
{
    TTF_Quit();
}

bool    Text::loadFont( const char *fontPath, std::string ID )
{
    TTF_Font    *font = nullptr;

    font = TTF_OpenFont(fontPath, 32);
    if ( !font )
    {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        return (false);
    }
    fonts[ID] = font;
    return (true);
}

void    Text::writeText( std::string ID, int x, int y, int width, int height, SDL_Renderer *renderer, const char *toDisplay, SDL_Color color, std::string state )
{
    static std::map<std::pair<std::string, std::string>, SDL_Texture *> cache; 
    SDL_Surface *text = nullptr;
    SDL_Texture *textTexture = nullptr;
    SDL_Rect    pos;

    pos.x = x;
    pos.y = y;
    pos.w = width;
    pos.h = height;
    auto key = std::make_pair(ID, toDisplay);
    auto it = cache.find(key);
    if ( it != cache.end() && state == "Play")
        textTexture = it->second;
    else
    {
        text = TTF_RenderText_Solid( fonts[ID], toDisplay, color);
        if ( !text )
        {
            std::cerr << "failed render text: " << TTF_GetError() << std::endl;
            return ;
        }
        textTexture = SDL_CreateTextureFromSurface( renderer, text );
        SDL_FreeSurface( text );
        if ( state == "Play" ) cache[key] = textTexture;
    }
    SDL_RenderCopy( renderer, textTexture, NULL, &pos );
    if ( state != "Play") SDL_DestroyTexture( textTexture );
}
