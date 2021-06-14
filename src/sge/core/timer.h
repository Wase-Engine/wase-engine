#pragma once

#include <memory>

const int TARGET_FPS = 60;
const float MAX_DELTA_TIME = 1.5f;

class Timer
{
public:
	static void tick();
	static float getDeltaTime();

private:
	static std::shared_ptr<Timer> instance;

	float deltaTime = 0, lastTime = 0;

private:
	static std::shared_ptr<Timer> getInstance();
};