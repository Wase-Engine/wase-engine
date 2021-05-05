#pragma once

#include "SDL.h"

namespace input 
{
	namespace events
	{
		void update();
		void keyEvent(const SDL_KeyboardEvent* event);
	}

	bool getKey(const int keycode);
	bool getKeyDown(const int keycode);
	bool getKeyUp(const int keycode);
}