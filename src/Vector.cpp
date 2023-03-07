#include "Vector.hpp"

float   Vector::getX( void ) const { return (x); }
float   Vector::getY( void ) const { return (y); }

void    Vector::setX( float x ) { this->x = x; }
void    Vector::setY( float y ) { this->y = y; }

float   Vector::getLength( void ) const { return (sqrt( x * x + y * y )); }

//addition of two vectors
Vector  Vector::operator+ ( const Vector &vec ) const
{
    return (Vector( x + vec.x, y + vec.y ));
}

Vector  operator+=( Vector &vec1, const Vector &vec2 )
{
    vec1.x += vec2.x;
    vec1.y += vec2.y;
    return (vec1);
}

//multiply by scalar number
Vector  Vector::operator* ( float scalar ) { return ( Vector(x * scalar, y * scalar)); }
Vector  &Vector::operator*= ( float scalar )
{
    x *= scalar;
    y *= scalar;
    return (*this);
}

//divide by a scalar number
Vector  Vector::operator/ ( float scalar ) { return ( Vector(x / scalar, y / scalar)); };
Vector  &Vector::operator/= ( float scalar )
{
    x /= scalar;
    y /= scalar;
    return (*this);
}

//normalizing a vector
void    Vector::normalize( void )
{
    float len = getLength();
    if ( len > 0 )
        *this *= 1 / len;
}

//subtraction of two vectors
Vector  Vector::operator- ( const Vector &vec ) { return ( Vector( x - vec.x, y - vec.y )); }
Vector  operator-= ( Vector &vec1, const Vector &vec2 )
{
    vec1.x -= vec2.x;
    vec1.y -= vec2.y;
    return (vec1);
}