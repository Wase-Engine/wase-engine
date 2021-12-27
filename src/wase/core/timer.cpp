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
		m_DeltaTime = ((float)SDL_GetTicks() - m_LastTime) * (TARGET_FPS / 1000.0f);

		if (m_DeltaTime > MAX_DELTA_TIME)
			m_DeltaTime = MAX_DELTA_TIME;

		m_LastTime = (float)SDL_GetTicks();
	}

	float Timer::iGetDeltaTime()
	{
		return m_DeltaTime;
	}

	Timer& Timer::get()
	{
		static Timer instance;

		return instance;
	}
}