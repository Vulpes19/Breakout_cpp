#pragma once

#include <iostream>
#include <fstream>

class HighScore
{
    public:
        openFile( void );
        saveScore( int score );
        getScore( void );
    private:
        std::fstream file;
};