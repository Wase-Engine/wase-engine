#pragma once

#include <memory>

namespace wase
{
	const int TARGET_FPS = 60;
	const float MAX_DELTA_TIME = 1.5f;

	class Timer
	{
	public:
		Timer(const Timer&) = delete;

		static void tick();
		static float getDeltaTime();

	private:
		float deltaTime = 0, lastTime = 0;

	private:
		Timer() {}

		void iTick();
		float iGetDeltaTime();

		static Timer& get();
	};
}