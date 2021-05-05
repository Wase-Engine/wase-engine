#pragma once

#include "SDL.h"

namespace input 
{
	namespace events
	{
		void update();
		void keyEvent(const SDL_KeyboardEvent* event);
		void mouseButtonEvent(const SDL_MouseButtonEvent* event);
		void mouseScrollWheelEvent(const SDL_MouseWheelEvent* event);
	}

	bool getKey(const int keycode);
	bool getKeyDown(const int keycode);
	bool getKeyUp(const int keycode);

	bool getMouseButton(const int button);
	bool getMouseButtonDown(const int button);
	bool getMouseButtonUp(const int button);

	short getMouseScrollWheel();
}