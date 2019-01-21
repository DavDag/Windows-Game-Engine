#pragma once

#ifndef COLORS_HPP
#define COLORS_HPP

#include "Utils.hpp"

/**
  *  COLOR CLASS
  *  It has RGBA channels.
  *  (Alpha is not currently supported v0.0.1).
  **/

// Color class
class Color
{
	public:
		// Red Green Blue Alpha
		BYTE m_r, m_g, m_b, m_a;
		
		// Contructors
		Color();
		Color(BYTE r, BYTE g, BYTE b, BYTE a = 0xFF);
		
		// Destructor
		~Color();

		/**
		  *  This function return a 32-bit number that represent the color in four channels 8 bit each.
		  *  The format is 0xaabbggrr and its PREMULTIPLIED.
		  *  (Alpha is not currently supported so it returns 0x00 instead of alpha value).
		  *  
		  *  THE FUNCTION FOR STRAIGHT ALPHA IS
		  *	 result = (source.RGB * source.A) + (dest.RGB * (1 - source.A))
		  *  -RGB values specify the color of the thing being drawn
		  *  -The alpha value specifies how solid it is
		  *
		  *  WITH PREMULTIPLIED ALPHA
		  *  result = source.RGB + (dest.RGB * (1 - source.A))
		  *  -RGB specifies how much color the thing being drawn contributes to the output
		  *  -The alpha value specifies how much it obscures whatever is behind it
		  * 
		  *  [https://microsoft.github.io/Win2D/html/PremultipliedAlpha.htm]
		  **/
		int GetPreABGR();
		
		// Operators
		// Equality (Check if every channels is equal-to the same channel in the other Color)
		bool operator ==(const Color& c);
		
		// Useful Color
		static Color White, Black, Blue, Red, Green, Transparent;
};

#endif //COLORS_HPP
