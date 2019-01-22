#include "Surface.hpp"

#include <iostream>

// Constructors
Surface::Surface()
{
	// Call constructor with default arguments
	Surface(50, 50, 1, 24);
}

Surface::Surface(int width, int height, int layers /* = 1 */, int bits /* = 32 */)
{	
    // Create Bitmap
    m_bitmap = CreateBitmap(width, height, layers, bits, NULL);
    
    // Create handle to device context
    m_hdc = CreateCompatibleDC(NULL);
    
    // Get Pen
    m_pen = CreatePen(PS_NULL, 0, 0x00000000);
    
    // Select Object
    SelectObject(m_hdc, m_bitmap);
    SelectObject(m_hdc, m_pen);
   
    // Set bitmap size
    m_size = Vector2d(width, height);
}

// Get Size
Vector2d Surface::getSize()
{
	// Return the size
	return m_size;
}
		  
// Set Brush
void Surface::setBrush(Color color)
{
	// Create Brush
	m_brush = CreateSolidBrush(color.GetPreABGR());
	
	// Set Brush
	SelectObject(m_hdc, m_brush);
}

/** 
  *  Drawing Function
  **/

// Clear Background
void Surface::clear(Color color /* = Color::Black */)
{
	// Draw a rectangle that fill the entire bitmap
	drawRect(Vector2d(0, 0), m_size, color);
}

// Draw a rectangle
void Surface::drawRect(Vector2d pos, Vector2d size, Color color /* = Color::White */)
{
	// Set Brush
	setBrush(color);
	
	// Draw a rect
	Rectangle(m_hdc, pos.x, pos.y, pos.x + size.x, pos.y + size.y);
	
	// Release Brush
	DeleteObject(m_brush);
}

// Draw a Circle
void Surface::drawCircle(Vector2d pos, float radius, Color color /* = Color::White */)
{
	// Set Brush
	setBrush(color);
	
	// Draw a Circle
	Ellipse(m_hdc, pos.x - radius, pos.y - radius, pos.x + radius, pos.y + radius);
	
	// Release Brush
	DeleteObject(m_brush);
}

// Draw a Polygon
void Surface::drawPolygon(Vector2d xy[], int n, Color color /* = Color::White */)
{
	// Set Brush
	setBrush(color);
	
	// Draw a Polygon
	POINT points[n];
	for(int i = 0; i < n; ++i) points[i] = {xy[i].x, xy[i].y};
	Polygon(m_hdc, points, n);
	
	// Release Brush
	DeleteObject(m_brush);
}

// Draw a Ellipse
void Surface::drawEllipse(Vector2d pos, Vector2d size, Color color /* = Color::White */)
{
	// Set Brush
	setBrush(color);
	
	// Draw an Ellipse
	Ellipse(m_hdc, pos.x - size.x / 2, pos.y - size.y / 2, pos.x + size.x / 2, pos.y + size.y / 2);
	
	// Release Brush
	DeleteObject(m_brush);
}

// Rectangle
void Surface::drawRect(int x, int y, float width, float height, Color color /* = Color::White */)
{
	// Call the other one
	drawRect(Vector2d(x, y), Vector2d(width, height), color);
}

// Cirlce
void Surface::drawCircle(int x, int y, float radius, Color color /* = Color::White */)
{
	// Call the other one
	drawCircle(Vector2d(x, y), radius, color);
}

// Polygon
void Surface::drawPolygon(int x[], int y[], int n, Color color /* = Color::White */)
{
	// Call the other one
	Vector2d xy[n];
	for(int i = 0; i < n; i++) xy[i] = Vector2d(x[i], y[i]);
	drawPolygon(xy, n, color);
}

// Ellipse
void Surface::drawEllipse(int x, int y, float width, float height, Color color /* = Color::White */)
{
	// Call the other one
	drawEllipse(Vector2d(x, y), Vector2d(width, height), color);
}

// Draw into another surface
void Surface::draw(Vector2d srcPos, Surface& dest, Vector2d destPos)
{
	// Draw this bitmap into destination surface
	BitBlt(dest.m_hdc, destPos.x, destPos.y, m_size.x, m_size.y, m_hdc, srcPos.x, srcPos.y, SRCCOPY);
}

void Surface::draw(Vector2d srcPos, HDC& hdc, Vector2d destPos)
{
	// Draw this bitmap into destination surface
	BitBlt(m_hdc, destPos.x, destPos.y, m_size.x, m_size.y, hdc, srcPos.x, srcPos.y, SRCCOPY);
}

// Destructor
Surface::~Surface()
{
	// Release resources
	DeleteObject(m_bitmap);
	DeleteObject(m_pen);
	DeleteDC(m_hdc);
}
