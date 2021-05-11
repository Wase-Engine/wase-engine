#pragma once

#include <memory>

class Engine
{
public:
	static std::shared_ptr<Engine> getInstance();

	void run(const char* sceneName);
	void quit();

private:
	static std::shared_ptr<Engine> instance;

	bool isRunning = false;

private:
	void init();
	void events();
	void update(float dt);
	void render();
	void destroy();
};