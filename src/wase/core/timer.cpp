#include "timer.h"

#include <SDL.h>

namespace wase
{
	void Timer::tick()
	{
		get().iTick();
	}

	float Timer::getDeltaTime()
	{
		return get().iGetDeltaTime();
	}

	void Timer::iTick()
	{
		deltaTime = ((float)SDL_GetTicks() - lastTime) * (TARGET_FPS / 1000.0f);

		if (deltaTime > MAX_DELTA_TIME)
			deltaTime = MAX_DELTA_TIME;

		lastTime = (float)SDL_GetTicks();
	}

	float Timer::iGetDeltaTime()
	{
		return deltaTime;
	}

	Timer& Timer::get()
	{
		static Timer instance;

		return instance;
	}
}