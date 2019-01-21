#pragma once

#ifndef KEYS_HPP
#define KEYS_HPP

#include "Utils.hpp"

/**
  *  This class manage inputs and contains keys' states.
  *  Its inherited by KeyBoard and Mouse to manage inputs.
  **/

// Keys Class
class Keys
{
	protected:
		// Update keys state
		void update();
		
		// Constructor
		Keys();
		
		// Destructor
		~Keys();
		
	protected:
		// keys buffer
		static BYTE m_buffer[KEYS_BUFFER];
		
		// pressed array
		static bool m_bPressed[KEYS_BUFFER];
		
		// released array
		static bool m_bReleased[KEYS_BUFFER];
		
		// held array
		static bool m_bHeld[KEYS_BUFFER];
		
		// toggled array
		static bool m_bToggled[KEYS_BUFFER];
};

#endif //KEYS_HPP
