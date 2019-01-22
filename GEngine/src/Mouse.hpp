#ifndef MOUSE_HPP
#define MOUSE_HPP

#include "Utils.hpp"
#include "Keys.hpp"
#include "Vector2d.hpp"

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
		static Vector2d getMousePos();
		
		// Get Mouse Position
		static void setMousePos(Vector2d v);
		
		// Get Key State
		static KeyState GetKeyState(BYTE key);
		
	protected:
		// Constructor
		Mouse();
		
		// Destructor
		~Mouse();
		
	private:
		// Mouse position
		static Vector2d m_mouseCoords;
};

#endif //MOUSE_HPP
