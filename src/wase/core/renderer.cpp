#include "renderer.h"

#include "window.h"
#include "utils/log_utils.h"

namespace wase
{
	std::shared_ptr<Renderer> Renderer::instance = nullptr;

	void Renderer::init()
	{
		getInstance()->renderer = SDL_CreateRenderer(Window::getWindow(), -1, 0);
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

	SDL_Color Renderer::getDrawColor()
	{
		return getInstance()->drawColor;
	}

	void Renderer::setDrawColor(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a)
	{
		SDL_Color color;
		color.r = r;
		color.g = g;
		color.b = b;
		color.a = a;

		getInstance()->drawColor = color;
		SDL_SetRenderDrawColor(getInstance()->renderer, r, g, b, a);
	}

	std::shared_ptr<Renderer> Renderer::getInstance()
	{
		return instance = (instance != nullptr) ? instance : std::make_shared<Renderer>();
	}
}