#pragma once

class Engine
{
private:
	static Engine* instance;

	bool isRunning = false;

	Engine();
	void init();
	void events();
	void update();
	void render();
	void destroy();

public:
	static Engine* getInstance();
};