#include "Mouse.hpp"

// Constructor
Mouse::Mouse() { }

// Get Mouse Position
Vector2d Mouse::getMousePos()
{
	return m_mouseCoords;
}

// Set Mouse Position
void Mouse::setMousePos(Vector2d pos)
{
	m_mouseCoords = pos;
}

// Get Button State
KeyState Mouse::GetKeyState(BYTE key)
{
	return KeyState { m_bPressed[key], m_bReleased[key], m_bHeld[key], m_bToggled[key] };
}

// Destructor
Mouse::~Mouse() { }

Vector2d Mouse::m_mouseCoords = Vector2d(0, 0);

