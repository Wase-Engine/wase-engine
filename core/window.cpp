#include "window.h"

#include <iostream>

Window* Window::instance = nullptr;

Window::Window()
{
	window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, NULL);
	if (!window)
	{
		std::cerr << "Could not initialize SDL Window\n";
		return;
	}
}

SDL_Window* Window::getWindow()
{
	return getInstance()->window;
}

Window* Window::getInstance()
{
	return instance = (instance != nullptr) ? instance : new Window;
}