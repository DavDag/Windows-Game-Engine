#include "Keys.hpp"

#include <algorithm>

// Constructor
Keys::Keys()
{
	// Fill datas with false
	std::fill(m_bPressed, 	m_bPressed 	+ KEYS_BUFFER, false);
	std::fill(m_bReleased, 	m_bReleased + KEYS_BUFFER, false);
	std::fill(m_bHeld, 		m_bHeld 	+ KEYS_BUFFER, false);
	std::fill(m_bToggled, 	m_bToggled 	+ KEYS_BUFFER, false);
}

// Update keys state
void Keys::update()
{
	// Check for each key and update its state
	for(BYTE i = 0; i < KEYS_BUFFER; ++i)
	{
		// To debug
		m_buffer[i] &= 0x00FF;
		
		// Check first bit for pressed 	0x8000 = 1000 0000 0000 0000
		if(m_buffer[i] & 0x80)
		{
			// Key up
			if(m_bPressed[i])
			{
				m_bHeld[i] = true;
				m_bPressed[i] = false;
			}
			else if(!m_bHeld[i])
			{
				m_bPressed[i] = true;
			}
		}
		else
		{
			// Key down
			if(m_bReleased[i])
			{
				m_bReleased[i] = false;
			}
			else if(m_bHeld[i])
			{
				m_bHeld[i] = false;
				m_bReleased[i] = true;
			}
		}
		
		// Check last bit for toggled 	0x0001 = 0000 0000 0000 0001
		m_bToggled[i] = ( m_buffer[i] & 0x01 );
	}
}

// Destructor
Keys::~Keys() { }

// Declaration of static variables
bool Keys::m_bPressed[KEYS_BUFFER];
bool Keys::m_bReleased[KEYS_BUFFER];
bool Keys::m_bHeld[KEYS_BUFFER];
bool Keys::m_bToggled[KEYS_BUFFER];
BYTE Keys::m_buffer[KEYS_BUFFER];
