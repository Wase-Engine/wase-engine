#include "window.h"

#include "utils/log_utils.h"

std::shared_ptr<Window> Window::instance = nullptr;

Window::Window()
{
	window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, NULL);
	if (!window)
	{
		log_utils::error("Could not initialize SDL Window");
		return;
	}
}

SDL_Window* Window::getWindow()
{
	return getInstance()->window;
}

std::shared_ptr<Window> Window::getInstance()
{
	return instance = (instance != nullptr) ? instance : std::make_shared<Window>();
}