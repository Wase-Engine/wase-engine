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
	
		getInstance()->setupViewport();
	}

	void Renderer::updateViewportRectangle()
	{
		SDL_Rect viewport{ 0, 0, getInstance()->windowWidth, getInstance()->windowHeight };
		SDL_Color color = Renderer::getDrawColor();
		Renderer::setDrawColor(color.r, color.g, color.b, color.a);

		SDL_RenderFillRect(getInstance()->renderer, &viewport);
		SDL_RenderDrawRect(getInstance()->renderer, &viewport);
	}

	void Renderer::setupViewport()
	{
		windowWidth = Window::getRect()->w;
		monitorWidth = Window::getDisplayBounds()->w;
		windowHeight = Window::getRect()->h;
		monitorHeight = Window::getDisplayBounds()->h;

		SDL_Rect viewport{ 0, 0, windowWidth, windowHeight };

		Uint32 flags = SDL_GetWindowFlags(Window::getWindow());
		if (flags & SDL_WINDOW_FULLSCREEN || flags & SDL_WINDOW_FULLSCREEN_DESKTOP)
		{
			if (monitorWidth - windowWidth > 0)
				viewport.x = (monitorWidth - windowWidth) / 2;

			if (monitorHeight - windowHeight > 0)
				viewport.y = (monitorHeight - windowHeight) / 2;
		}

		SDL_RenderSetViewport(renderer, &viewport);
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