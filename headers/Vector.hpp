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
 * Vector.hpp: 
 * 
 * =========================================================
 */

#pragma once

#include <math.h>

class Vector
{
	public:
		Vector( void ) : x(0), y(0) {};
		Vector( float x, float y ) : x(x), y(y) {};
		float   getX( void ) const;
		float   getY( void ) const;

		void    setX( float x );
		void    setY( float y );

		float   getLength( void ) const;

	//addition of two vectors
		Vector  operator+ ( const Vector &vec ) const;
		friend Vector  operator+= ( Vector &vec1, const Vector &vec2 );

	//multiply by scalar number
		Vector  operator* ( float scalar );
		Vector  &operator*= ( float scalar );

	//subtraction of two vectors
		Vector  operator- ( const Vector &vec );
		friend Vector  operator-= ( Vector &vec1, const Vector &vec2 );

	//divide by a scalar number
		Vector  operator/ ( float scalar );
		Vector  &operator/= ( float scalar );

	//normalizing a vector
		void    normalize( void );
	private:
		float x;
		float y;
};