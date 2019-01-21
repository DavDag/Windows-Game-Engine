#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include "Utils.hpp"
#include "Keys.hpp"

/**
  *  This class manage KeyBoard's inputs inheriting from Keys.
  *  It has Static Const variables useful to call GetKeyState().
  * 
  *  Example
  *  if( KeyBoard::GetKeyState( KeyBoard::K_W ).held )
  *  	//do something if button W is held
  *
  *  This line of code demostrate the use of KeyBoard class.
  **/

// Keyboard
class KeyBoard: public Keys
{
	public:
		// Useful
		static const BYTE K_BACKSPACE		= 0x08;
		static const BYTE K_TAB				= 0x09;
		static const BYTE K_CLEAR			= 0x0C;
		static const BYTE K_ENTER			= 0x0D;
		static const BYTE K_SHIFT			= 0x10;
		static const BYTE K_CONTROL			= 0x11;
		static const BYTE K_ALT				= 0x12;
		static const BYTE K_CAPSLOCK		= 0x14;
		static const BYTE K_ESCAPE			= 0x1B;
		static const BYTE K_SPACE			= 0x20;
		static const BYTE K_END				= 0x23;
		static const BYTE K_HOME			= 0x24;
		static const BYTE K_LEFT			= 0x25;
		static const BYTE K_UP				= 0x26;
		static const BYTE K_RIGHT			= 0x27;
		static const BYTE K_DOWN			= 0x28;
		static const BYTE K_SELECT			= 0x29;
		static const BYTE K_INS				= 0x2D;
		static const BYTE K_DEL				= 0x2E;
		static const BYTE K_MULTIPLY		= 0x6A;
		static const BYTE K_ADD				= 0x6B;
		static const BYTE K_SEPARATOR		= 0x6C;
		static const BYTE K_SUBTRACT		= 0x6D;
		static const BYTE K_DECIMAL			= 0x6E;
		static const BYTE K_DIVIDE			= 0x6F;
		static const BYTE K_NUMLOCK			= 0x90;
		static const BYTE K_SCROLLOCK		= 0x91;
		static const BYTE K_LSHIFT			= 0xA0;
		static const BYTE K_RSHIFT			= 0xA1;
		static const BYTE K_LCONTROL		= 0xA2;
		static const BYTE K_RCONTROL		= 0xA3;
		static const BYTE K_LMENU			= 0xA4;
		static const BYTE K_RMENU			= 0xA5;
		static const BYTE K_VOLMUTE			= 0xAD;
		static const BYTE K_VOLDOWN			= 0xAE;
		static const BYTE K_VOLUP			= 0xAF;
		static const BYTE K_PLUS			= 0xBB;
		static const BYTE K_COMMA			= 0xBC;
		static const BYTE K_MINUS			= 0xBD;
		static const BYTE K_DOT				= 0xBE;
		
		// Numbers
		static const BYTE K_0				= 0x30;
		static const BYTE K_1				= 0x31;
		static const BYTE K_2				= 0x32;
		static const BYTE K_3				= 0x33;
		static const BYTE K_4				= 0x34;
		static const BYTE K_5				= 0x35;
		static const BYTE K_6				= 0x36;
		static const BYTE K_7				= 0x37;
		static const BYTE K_8				= 0x38;
		static const BYTE K_9				= 0x39;
		static const BYTE K_NUMPAD0			= 0x60;
		static const BYTE K_NUMPAD1			= 0x61;
		static const BYTE K_NUMPAD2			= 0x62;
		static const BYTE K_NUMPAD3			= 0x63;
		static const BYTE K_NUMPAD4			= 0x64;
		static const BYTE K_NUMPAD5			= 0x65;
		static const BYTE K_NUMPAD6			= 0x66;
		static const BYTE K_NUMPAD7			= 0x67;
		static const BYTE K_NUMPAD8			= 0x68;
		static const BYTE K_NUMPAD9			= 0x69;
		
		// Alphabet letters
		static const BYTE K_A				= 0x41;
		static const BYTE K_B				= 0x42;
		static const BYTE K_C				= 0x43;
		static const BYTE K_D				= 0x44;
		static const BYTE K_E				= 0x45;
		static const BYTE K_F				= 0x46;
		static const BYTE K_G				= 0x47;
		static const BYTE K_H				= 0x48;
		static const BYTE K_I				= 0x49;
		static const BYTE K_J				= 0x4A;
		static const BYTE K_K				= 0x4B;
		static const BYTE K_L				= 0x4C;
		static const BYTE K_M				= 0x4D;
		static const BYTE K_N				= 0x4E;
		static const BYTE K_O				= 0x4F;
		static const BYTE K_P				= 0x50;
		static const BYTE K_Q				= 0x51;
		static const BYTE K_R				= 0x52;
		static const BYTE K_S				= 0x53;
		static const BYTE K_T				= 0x54;
		static const BYTE K_U				= 0x55;
		static const BYTE K_V				= 0x56;
		static const BYTE K_W				= 0x57;
		static const BYTE K_X				= 0x58;
		static const BYTE K_Y				= 0x59;
		static const BYTE K_Z				= 0x5A;
		
		// Functions
		static const BYTE K_F1				= 0x70;
		static const BYTE K_F2				= 0x71;
		static const BYTE K_F3				= 0x72;
		static const BYTE K_F4				= 0x73;
		static const BYTE K_F5				= 0x74;
		static const BYTE K_F6				= 0x75;
		static const BYTE K_F7				= 0x76;
		static const BYTE K_F8				= 0x77;
		static const BYTE K_F9				= 0x78;
		static const BYTE K_F10				= 0x79;
		static const BYTE K_F11				= 0x7A;
		static const BYTE K_F12				= 0x7B;
		static const BYTE K_F13				= 0x7C;
		static const BYTE K_F14				= 0x7D;
		static const BYTE K_F15				= 0x7E;
		static const BYTE K_F16				= 0x7F;
		static const BYTE K_F17				= 0x80;
		static const BYTE K_F18				= 0x81;
		static const BYTE K_F19				= 0x82;
		static const BYTE K_F20				= 0x83;
		static const BYTE K_F21				= 0x84;
		static const BYTE K_F22				= 0x85;
		static const BYTE K_F23				= 0x86;
		static const BYTE K_F24				= 0x87;
		
	public:
		// Get Key State
		static KeyState GetKeyState(BYTE key);
		
	protected:
		// Constructor
		KeyBoard();
		
		// Destructor
		~KeyBoard();
};

#endif //KEYBOARD_HPP
