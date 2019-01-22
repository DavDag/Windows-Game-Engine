#pragma once

#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include "Utils.hpp"

/**
  *  This class reduce your effort bringing a confortable 2-dimensional vector
  *  class with a bunch of already-implemented functions.
  *  You can add or subtract Vector2d by another Vector2d or multiply and divide by a factor.
  *  You can scale or normalize them.
  **/

// Vector2d Class
class Vector2d
{
	public:
		// Attributes
		float x, y;
	
	public:
		// Constructor
		Vector2d();
		Vector2d(float tx, float ty);
		
		// Destructor
		~Vector2d();
		
		// Operators
		bool operator==(const Vector2d& v) const;
		Vector2d operator+(const Vector2d& v) const;
		Vector2d operator-(const Vector2d& v) const;
		Vector2d operator*(const float& f) const;
		Vector2d operator/(const float& f) const;
		
		/**
		  *  Useful function to work with two-dimensional vectors.
		  *  To get the magnitude of a vector ( or get lenght ) there's a formula
		  *  that use x and y components. ( The Pythagorean Theorem ).
		  *  -> lenght = sqrt( x * x  + y * y)
		  *
		  *  To normalize a vector you need to divide his components by lenght.
		  * 
		  *  [ https://www.khanacademy.org/computing/computer-programming/
		  *    programming-natural-simulations/programming-vectors/a/vector-magnitude-normalization ]
		  **/
		
		// Get vector's Magnitude
		float getLenght();
		
		// Scale the vector
		void scale(float f);
		
		// Normalize the vector. It returns the lenght
		float normalize();
};

#endif //VECTOR2D_HPP
