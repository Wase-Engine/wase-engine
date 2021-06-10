#include "renderer.h"

#include "window.h"
#include "utils/log_utils.h"

std::shared_ptr<Renderer> Renderer::instance = nullptr;

void Renderer::init()
{
	getInstance()->renderer = SDL_CreateRenderer(Window::getWindow(), -1, NULL);
	if (!getInstance()->renderer)
	{
		log_utils::error("Could not initialize SDL Renderer");
		return;
	}
}

SDL_Renderer* Renderer::getRenderer()
{
	return getInstance()->renderer;
}

std::shared_ptr<Renderer> Renderer::getInstance()
{
	return instance = (instance != nullptr) ? instance : std::make_shared<Renderer>();
}