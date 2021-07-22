#include "events.h"

#include "input.h"
#include "engine.h"

namespace wase
{
	namespace events
	{
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

				case SDL_MOUSEBUTTONDOWN:
				case SDL_MOUSEBUTTONUP:
					input::events::mouseButtonEvent(&event.button);
					break;

				case SDL_MOUSEWHEEL:
					input::events::mouseScrollWheelEvent(&event.wheel);
					break;

				case SDL_MOUSEMOTION:
					input::events::mouseMotionEvent(&event.motion);
					break;
				}
			}
		}
	}
}