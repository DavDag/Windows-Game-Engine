#include "KeyBoard.hpp"

// Constructor
KeyBoard::KeyBoard() { }

// Get Key State
KeyState KeyBoard::GetKeyState(BYTE key)
{
	return KeyState { m_bPressed[key], m_bReleased[key], m_bHeld[key], m_bToggled[key] };
}

// Destructor
KeyBoard::~KeyBoard() { }
