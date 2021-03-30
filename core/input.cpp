#include "input.h"
#include "engine.h"

#include <map>

namespace input 
{
	std::map<int, bool> keys, keysPressed, mouseButtons, mouseButtonsPressed;

	namespace events
	{
		void keyDownEvent(int keyCode)
		{
			keys[keyCode] = true;
		}

		void keyUpEvent(int keyCode)
		{
			keys[keyCode] = false;
			keysPressed[keyCode] = false;
		}

		void mouseButtonDownEvent(int button)
		{
			mouseButtons[button - 1] = true;
		}

		void mouseButtonUpEvent(int button)
		{
			button--;
			mouseButtons[button] = false;
			mouseButtonsPressed[button] = false;
		}
	}

	bool keyPressed(int keyCode)
	{
		if (!keysPressed[keyCode] && keys[keyCode])
		{
			keysPressed[keyCode] = true;
			return true;
		}

		return false;
	}

	bool keyDown(int keyCode)
	{
		return keys[keyCode];
	}

	bool mouseButtonPressed(int button)
	{
		if (!mouseButtonsPressed[button] && mouseButtons[button])
		{
			mouseButtonsPressed[button] = true;
			return true;
		}

		return false;
	}

	bool mouseButtonDown(int button)
	{
		return mouseButtons[button];
	}
}