#include "Mouse.hpp"

// Constructor
Mouse::Mouse() { }

// Get Mouse Position
std::pair<long long, long long> Mouse::getMousePos()
{
	return m_mouseCoords;
}

// Set Mouse Position
void Mouse::setMousePos(std::pair<long long, long long> pos)
{
	m_mouseCoords = pos;
}

// Get Button State
KeyState Mouse::getKeyState(BYTE key)
{
	return KeyState { m_bPressed[key], m_bReleased[key], m_bHeld[key], m_bToggled[key] };
}

// Destructor
Mouse::~Mouse() { }

std::pair<long long, long long> Mouse::m_mouseCoords = {0, 0};

