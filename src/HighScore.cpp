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
}

void    HighScore::openFile( void )
{
    file.open("assets/save.txt", std::ios::out | std::ios::in | std::ios::binary );
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
    if ( score > intHighestScore)
    {
        file.seekp(0); 
        file << score;
        file.flush();
    }
    file.close();
    exit(1);
}