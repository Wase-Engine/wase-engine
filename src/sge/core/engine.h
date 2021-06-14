#pragma once

#include <memory>
#include <SDL.h>

class Engine
{
public:
	static std::shared_ptr<Engine> getInstance();

	void init(const char* title, const int x, const int y, const unsigned int w, const unsigned int h, const Uint32 flags);
	void run(const char* sceneName);
	void quit();

private:
	static std::shared_ptr<Engine> instance;

	bool isRunning = false;

private:
	void events();
	void update(float dt);
	void render();
	void destroy();
};