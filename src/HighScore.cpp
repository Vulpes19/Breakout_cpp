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
 * HighScore.cpp: 
 * 
 * =========================================================
 */

#include "HighScore.hpp"

HighScore::HighScore( void )
{}

HighScore::~HighScore( void )
{
    file.close();
}

void    HighScore::openFile( void )
{
    file.open("assets/save.txt", std::ios::out | std::ios::in );
    if ( !file )
    {
        std::cerr << "can't open save file\n";
        return ;
    }
}


void    HighScore::checkScore( int score )
{
    if ( !file )
     {
        std::cerr << "can't open save file\n";
        return ;
    }
    std::string highestScore;
    if ( !std::getline( file, highestScore ) )
        return ;
    int intHighestScore = std::stoi(highestScore);
    highScore = intHighestScore;
    if ( score > intHighestScore)
    {
        file.seekg(std::ios::beg); 
        file << score;
        highScore = score;
    }
    file.close();
}

int HighScore::getHighScore( void ) const
{
    return (highScore);
}