#pragma once

#include <SDL.h>

class Window
{
public:
	static Window* getInstance();
	static SDL_Window* getWindow();

private:
	static Window* instance;

	SDL_Window* window;

private:
	Window();
};