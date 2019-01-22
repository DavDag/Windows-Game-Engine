#pragma once

#ifndef SURFACE_HPP
#define SURFACE_HPP

#include <windows.h>

#include "Utils.hpp"
#include "Colors.hpp"
#include "Vector2d.hpp"

class Surface
{
	public:
		// Constructor
		Surface();
		Surface(int width, int height, int layers = 1, int bits = 32);
		
		// Destructor
		~Surface();
		
		// Get Size
		Vector2d getSize();
		
		/**
		  *  DRAWING FUNCTIONS
		  **/
		
		// Clear Background
		void clear(Color color = Color::Black);
		
		// Draw a rectangle
		void drawRect(Vector2d pos, Vector2d size, Color color = Color::White);
		
		// Cirlce
		void drawCircle(Vector2d pos, float radius, Color color = Color::White);
		
		// Polygon
		void drawPolygon(Vector2d xy[], int n, Color color = Color::White);
		
		// Ellipse
		void drawEllipse(Vector2d pos, Vector2d size, Color color = Color::White);
		
		// Rectangle
		void drawRect(int x, int y, float width, float height, Color color = Color::White);
		
		// Cirlce
		void drawCircle(int x, int y, float radius, Color color = Color::White);
		
		// Polygon
		void drawPolygon(int x[], int y[], int n, Color color = Color::White);
		
		// Ellipse
		void drawEllipse(int x, int y, float width, float height, Color color = Color::White);
		
		// Draw into another surface
		void draw(Vector2d srcPos, Surface& s, Vector2d destPos);
		void draw(Vector2d srcPos, HDC& hdc, Vector2d destPos);
	
	private:
		// Set brush
		void setBrush(Color color = Color::White);
	
	public:
		// Handle to device content
		HDC m_hdc;
	
	private:
		
		// Handle to brush
		HBRUSH m_brush;
		
		// Handle to pen
		HPEN m_pen;
		
		// Handle to bitmap
		HBITMAP m_bitmap;
		
		// Size of bitmap
		Vector2d m_size;
};

#endif // SURFACE_HPP

