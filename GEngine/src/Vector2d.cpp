#include "Vector2d.hpp"

#include <math.h>

// Constructors
Vector2d::Vector2d()
{
	x = y = 0;
}

Vector2d::Vector2d(float tx, float ty)
{
	x = tx;
	y = ty;
}

// Operators
// equal-to
bool Vector2d::operator==(const Vector2d& v) const
{
	// Check for x and y components
	return (v.x == x && v.y == y);
}

// Addition
Vector2d Vector2d::operator+(const Vector2d& v) const
{
	// Add each components
	return Vector2d(v.x + x, v.y + y);
}

// Subtraction
Vector2d Vector2d::operator-(const Vector2d& v) const
{
	// Sub each components
	return Vector2d(v.x - x, v.y - y);
}

// Multiply
Vector2d Vector2d::operator*(const float& f) const
{
	// Mulltiply each components
	return Vector2d(x * f, y * f);
}

// Divide
Vector2d Vector2d::operator/(const float& f) const
{
	// Divide each components
	return Vector2d(x / f, y / f);
}

// Useful
// Get magnitude or lenght
float Vector2d::getLenght()
{
	// lenght = sqrt( x * x  + y * y)
	return sqrt(x * x + y * y);
}

// Normalize
float Vector2d::normalize()
{
	// Get lenght
	float lenght = getLenght();
	
	// Divide each component by lenght
	x /= lenght;
	y /= lenght;
	
	// return the lenght
	return lenght;
}

// Scale
void Vector2d::scale(float f)
{
	// Multiply each component by factor <f>
	x *= f;
	y *= f;
}

// Destructors
Vector2d::~Vector2d() { }
