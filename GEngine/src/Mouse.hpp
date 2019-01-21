#ifndef MOUSE_HPP
#define MOUSE_HPP

#include "Utils.hpp"
#include "Keys.hpp"

/**
  *  This class manage Mouse's inputs inheriting from Keys.
  *  It has Static Const variables useful to call GetKeyState().
  * 
  *  Example
  *  if( Mouse::GetKeyState( Mouse::K_LEFBUTTON ).held )
  *  	//do something if left button of the mouse is held
  *
  *  This line of code demostrate the use of Mouse class.
  **/
class Mouse: public Keys
{
	public:
		// Muse Button
		static const BYTE K_LEFTBUTTON			= 0x01;
		static const BYTE K_RIGHTBUTTON			= 0x02;
		static const BYTE K_MIDDLEBUTTON		= 0x04;
		static const BYTE K_XBUTTON1			= 0x05;
		static const BYTE K_XBUTTON2			= 0x06;
		
		// Get Mouse Position
		static std::pair<long long, long long> getMousePos();
		
		// Get Mouse Position
		static void setMousePos(std::pair<long long, long long> pos);
		
		// Get Key State
		static KeyState getKeyState(BYTE key);
		
	protected:
		// Constructor
		Mouse();
		
		// Destructor
		~Mouse();
		
	private:
		// Mouse position
		static std::pair<long long, long long> m_mouseCoords;
};

#endif //MOUSE_HPP
