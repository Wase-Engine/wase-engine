#include "timer.h"

#include <SDL.h>

void Timer::tick()
{
	deltaTime = ((float) SDL_GetTicks() - lastTime) * (TARGET_FPS / 1000.0f);

	if (deltaTime > MAX_DELTA_TIME)
		deltaTime = MAX_DELTA_TIME;

	lastTime = (float) SDL_GetTicks();
}

float Timer::getDeltaTime()
{
	return deltaTime;
}
