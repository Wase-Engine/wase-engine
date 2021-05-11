#pragma once

const int TARGET_FPS = 60;
const float MAX_DELTA_TIME = 1.5f;

class Timer
{
public:
	void tick();
	float getDeltaTime();

private:
	float deltaTime = 0, lastTime = 0;
};