#pragma once

#include <SDL.h>
#include <memory>

class Window
{
public:
	static std::shared_ptr<Window> getInstance();
	static SDL_Window* getWindow();

public:
	Window();

private:
	static std::shared_ptr<Window> instance;

	SDL_Window* window;
};