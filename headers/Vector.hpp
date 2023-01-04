#pragma once

#include <math.h>

class Vector
{
    public:
        Vector( float x, float y ) : x(x), y(y) {};
        float   getX( void ) const { return (x); };
        float   getY( void ) const { return (y); };

        void    setX( float x ) { this->x = x; };
        void    setY( float y ) { this->y = y; };

        float   getLength( void ) const { return (sqrt( x * x + y * y )); };

    //addition of two vectors
        Vector  operator+ ( const Vector &vec ) const
        {
            return (Vector( x + vec.x, y + vec.y ));
        };
        friend Vector  operator+= ( Vector &vec1, const Vector &vec2 )
        {
            vec1.x += vec2.x;
            vec1.y += vec2.y;
            return (vec1);
        };

    //multiply by scalar number
        Vector  operator* ( float scalar ) { return ( Vector(x * scalar, y * scalar)); };
        Vector  &operator*= ( float scalar )
        {
            x *= scalar;
            y *= scalar;
            return (*this);
        };

    //subtraction of two vectors
        Vector  operator- ( const Vector &vec ) { return ( Vector( x - vec.x, y - vec.y )); };
        friend Vector  operator-= ( Vector &vec1, const Vector &vec2 )
        {
            vec1.x -= vec2.x;
            vec1.y -= vec2.y;
            return (vec1);
        };

    //divide by a scalar number
        Vector  operator/ ( float scalar ) { return ( Vector(x / scalar, y / scalar)); };
        Vector  &operator/= ( float scalar )
        {
            x /= scalar;
            y /= scalar;
            return (*this);
        };

    //normalizing a vector
        void    normalize( void )
        {
            float len = getLength();
            if ( len > 0 )
                *this *= 1 / len;
        };
    private:
        float x;
        float y;
};