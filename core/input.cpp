#include "input.h"

#include <map>

namespace input 
{
	std::map<int, bool> keys, keysNoRepeat, keysUp;
	std::map<int, bool> buttons, buttonsNoRepeat, buttonsUp;
	
	short mouseScrollWheel = 0;
	Vector2 mousePos;

	namespace events
	{
		void update()
		{
			for (const auto& [button, pressed] : buttonsUp)
			{
				buttonsUp[button] = false;
			}

			mouseScrollWheel = 0;
		}

		void keyEvent(const SDL_KeyboardEvent* event)
		{
			const int keycode = event->keysym.sym;

			if (event->type == SDL_KEYDOWN)
			{
				keys[keycode] = true;

				if (!event->repeat)
				{
					keysNoRepeat[keycode] = true;
				}
			}
			else if (event->type == SDL_KEYUP)
			{
				keys[keycode] = false;
				keysUp[keycode] = true;
			}
		}

		void mouseButtonEvent(const SDL_MouseButtonEvent* event)
		{
			const int button = event->button;

			if (event->type == SDL_MOUSEBUTTONDOWN)
			{
				buttons[button] = true;
			}
			else if (event->type == SDL_MOUSEBUTTONUP)
			{
				buttons[button] = false;
				buttonsUp[button] = true;
				buttonsNoRepeat[button] = false;
			}
		}

		void mouseScrollWheelEvent(const SDL_MouseWheelEvent* event)
		{
			mouseScrollWheel = event->y;
		}

		void mouseMotionEvent(const SDL_MouseMotionEvent* event)
		{
			mousePos.x = (float)event->x;
			mousePos.y = (float)event->y;
		}
	}

	bool getKey(const int keycode)
	{
		return keys[keycode];
	}

	bool getKeyDown(const int keycode)
	{
		bool keyDown = keysNoRepeat[keycode];

		keysNoRepeat[keycode] = false;

		return keyDown;
	}

	bool getKeyUp(const int keycode)
	{
		bool keyUp = keysUp[keycode];

		keysUp[keycode] = false;

		return keyUp;
	}

	bool getMouseButton(const int button)
	{
		return buttons[button];
	}

	bool getMouseButtonDown(const int button)
	{
		if (!buttonsNoRepeat[button] && buttons[button])
		{
			buttonsNoRepeat[button] = true;

			return true;
		}

		return false;
	}

	bool getMouseButtonUp(const int button)
	{
		bool buttonUp = buttonsUp[button];

		buttonsUp[button] = false;

		return buttonUp;
	}

	short getMouseScrollWheel()
	{
		return mouseScrollWheel;
	}

	Vector2 getMousePos()
	{
		return mousePos;
	}
}