#include "input.h"

#include "engine.h"

namespace input 
{
	bool keys[263], keysNoRepeat[263], keysUp[263] = { false };

	namespace events
	{
		void keyDown(const SDL_KeyboardEvent* event);
		void keyUp(const SDL_KeyboardEvent* event);

		void update()
		{
			SDL_Event event;

			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_QUIT:
					Engine::getInstance()->quit();
					break;
				case SDL_KEYDOWN:
				case SDL_KEYUP:
					input::events::keyEvent(&event.key);
					break;
				}
			}
		}

		void keyEvent(const SDL_KeyboardEvent* event)
		{
			const int keycode = event->keysym.scancode;

			if (sizeof(keys) / sizeof(keys[0]) - 1 < keycode)
				return;

			if (event->type == SDL_KEYDOWN)
			{
				keyDown(event);
			}
			else if (event->type == SDL_KEYUP)
			{
				keyUp(event);
			}
		}

		void keyDown(const SDL_KeyboardEvent* event)
		{
			const int keycode = event->keysym.scancode;

			keys[keycode] = true;

			if (!event->repeat)
			{
				keysNoRepeat[keycode] = true;
			}
		}

		void keyUp(const SDL_KeyboardEvent* event)
		{
			const int keycode = event->keysym.scancode;

			keys[keycode] = false;
			keysUp[keycode] = true;
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
}