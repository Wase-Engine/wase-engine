#pragma once

#include "SDL.h"
#include "vector2.h"

namespace wase
{
	namespace input
	{
		namespace events
		{
			void update();
			void end();
			void keyEvent(const SDL_KeyboardEvent* event);
			void mouseButtonEvent(const SDL_MouseButtonEvent* event);
			void mouseScrollWheelEvent(const SDL_MouseWheelEvent* event);
			void mouseMotionEvent(const SDL_MouseMotionEvent* event);
		}

		bool getKey(const int keyCode);
		bool getKeyDown(const int keyCode);
		bool getKeyUp(const int keyCode);

		bool getMouseButton(const int button);
		bool getMouseButtonDown(const int button);
		bool getMouseButtonUp(const int button);

		short getMouseScrollWheel();

		Vector2 getMousePos();
	}
}