#include "input.h"

#include <map>

namespace wase
{
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

			void end()
			{
				buttonsNoRepeat = buttons;
				keysNoRepeat = keys;

				for (const auto& [button, boolean] : buttonsUp)
				{
					buttonsUp[button] = false;
				}

				for (const auto& [key, boolean] : keysUp)
				{
					keysUp[key] = false;
				}
			}

			void keyEvent(const SDL_KeyboardEvent* event)
			{
				const int keyCode = event->keysym.sym;

				if (event->type == SDL_KEYDOWN)
				{
					keys[keyCode] = true;
				}
				else if (event->type == SDL_KEYUP)
				{
					keys[keyCode] = false;
					keysUp[keyCode] = true;
					keysNoRepeat[keyCode] = false;
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

		bool getKey(const int keyCode)
		{
			return keys[keyCode];
		}

		bool getKeyDown(const int keyCode)
		{
			return !keysNoRepeat[keyCode] && keys[keyCode];
		}

		bool getKeyUp(const int keyCode)
		{
			return keysUp[keyCode];
		}

		bool getMouseButton(const int button)
		{
			return buttons[button];
		}

		bool getMouseButtonDown(const int button)
		{
			return !buttonsNoRepeat[button] && buttons[button];
		}

		bool getMouseButtonUp(const int button)
		{
			return buttonsUp[button];
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
}