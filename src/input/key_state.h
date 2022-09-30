#pragma once

namespace wase::input
{
	enum KeyState
	{
		IDLE = -1, // Key is not being pressed
		RELEASED = 0, // Key is released
		DOWN = 1, // Key is being pressed down
		HELD_DOWN_AFTER = 2 // State after key is pressed down and still being hold down
	};
}