#pragma once

class Engine
{
private:
	static Engine* instance;

	Engine();
	void init();
	void events();
	void update();
	void render();
	void destroy();

public:
	static Engine* getInstance();

	bool isRunning = false;
};