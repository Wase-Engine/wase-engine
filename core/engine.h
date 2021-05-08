#pragma once

#include "scene.h"

class Engine
{
public:
	static Engine* getInstance();

	void run(const char* sceneName);
	void quit();

private:
	static Engine* instance;

	bool isRunning = false;

private:
	Engine();
	void init();
	void events();
	void update();
	void render();
	void destroy();
};