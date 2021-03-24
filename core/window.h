#pragma once

#include <SDL.h>

class Window
{
private:
	static Window* instance;

	SDL_Window* window = nullptr;

	Window();

public:
	static Window* getInstance();
	static SDL_Window* getWindow();
};