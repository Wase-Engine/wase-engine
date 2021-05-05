#include "renderer.h"

#include "window.h"
#include "utils/log_utils.h"

Renderer* Renderer::instance = nullptr;

Renderer::Renderer()
{
	renderer = SDL_CreateRenderer(Window::getWindow(), -1, NULL);
	if (!renderer)
	{
		log_utils::error("Could not initialize SDL Renderer");
		return;
	}
}

SDL_Renderer* Renderer::getRenderer()
{
	return getInstance()->renderer;
}

Renderer* Renderer::getInstance()
{
	return instance = (instance != nullptr) ? instance : new Renderer;
}