#include "Colors.hpp"

// Contructors
Color::Color()
{
	m_r = m_g = m_b = m_a = 0xFF;
}

Color::Color(BYTE r, BYTE g, BYTE b, BYTE a /* = 0xFF */)
{
	m_r = r;
	m_g = g;
	m_b = b;
	m_a = a;
}

// get ABGR format Premultiplied (0xaabbggrr)
int Color::GetPreABGR()
{
	// Alpha Ratio
	float ratio = (float) m_a / 255.0f;
	
	// Alpha shifted by 24-bit, Blue by 16-bit, Green 8-bit and Red at the end.
	return 00 << 24 | (BYTE)((float)m_b * ratio) << 16 | (BYTE)((float)m_g * ratio) << 8 | (BYTE)((float)m_r * ratio);
}

// Operators
bool Color::operator ==(const Color& c)
{
	// Check every channels
	return (c.m_a == m_a && c.m_b == m_b && c.m_g == m_g && c.m_r == m_r);
}

// Destructor
Color::~Color() { }

// Useful base colors
Color Color::White 			= 	Color(0xFF, 0xFF, 0xFF);
Color Color::Red 			= 	Color(0xFF,    0,    0);
Color Color::Green 			= 	Color(   0, 0xFF,    0);
Color Color::Blue 			= 	Color(   0,    0, 0xFF);
Color Color::Black 			= 	Color(   0,    0,    0);
Color Color::Transparent 	= 	Color(   0,    0,    0,    0);
