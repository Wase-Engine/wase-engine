#include "timer.h"

#include <SDL.h>

namespace wase
{
	std::shared_ptr<Timer> Timer::instance = nullptr;

	void Timer::tick()
	{
		getInstance()->deltaTime = ((float)SDL_GetTicks() - getInstance()->lastTime) * (TARGET_FPS / 1000.0f);

		if (getInstance()->deltaTime > MAX_DELTA_TIME)
			getInstance()->deltaTime = MAX_DELTA_TIME;

		getInstance()->lastTime = (float)SDL_GetTicks();
	}

	float Timer::getDeltaTime()
	{
		return getInstance()->deltaTime;
	}

	std::shared_ptr<Timer> Timer::getInstance()
	{
		return instance = (instance != nullptr) ? instance : std::make_shared<Timer>();
	}
}