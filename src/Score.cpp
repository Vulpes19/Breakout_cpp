#include "Score.hpp"

Score::Score( void )
{
	score = 0;
	lives = 3;
}

Score::~Score( void )
{}

void	Score::increment( void )
{
	score++;
}

bool	Score::decrementLives( void )
{
	if ( lives > 0 )
	{
		lives--;
		return (true);
	}
	else
		return (false);
}

void	Score::displayScore( void )
{
	
}