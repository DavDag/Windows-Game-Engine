#pragma once

#ifndef UTILS_HPP
#define UTILS_HPP

#include <algorithm>
#include <utility>

#define BYTE			unsigned char		// Useful macro for 8-bit
#define KEYS_BUFFER 	0xFF				// Keys buffer size

// KeyState
struct KeyState { bool pressed, released, held, toggled; };

#endif //UTILS_HPP
