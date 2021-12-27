#include "renderer.h"

#include "window.h"
#include "utils/log_utils.h"

namespace wase
{
	void Renderer::init()
	{
		get().iInit();
	}

	void Renderer::updateViewportRectangle()
	{
		get().iUpdateViewportRectangle();
	}

	SDL_Renderer* Renderer::getRenderer()
	{
		return get().iGetRenderer();
	}

	SDL_Color Renderer::getDrawColor()
	{
		return get().iGetDrawColor();
	}

	void Renderer::setDrawColor(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a)
	{
		get().iSetDrawColor(r, g, b, a);
	}

	void Renderer::setupViewport()
	{
		windowWidth = Window::getRect().w;
		monitorWidth = Window::getDisplayBounds().w;
		windowHeight = Window::getRect().h;
		monitorHeight = Window::getDisplayBounds().h;

		SDL_Rect viewport{ 0, 0, windowWidth, windowHeight };

		if (Window::isFullscreen())
		{
			if (monitorWidth - windowWidth > 0)
				viewport.x = (monitorWidth - windowWidth) / 2;

			if (monitorHeight - windowHeight > 0)
				viewport.y = (monitorHeight - windowHeight) / 2;
		}

		SDL_RenderSetViewport(renderer, &viewport);
	}

	void Renderer::iInit()
	{
		renderer = SDL_CreateRenderer(Window::getWindow(), -1, 0);
		if (!renderer)
		{
			log_utils::error("Could not initialize SDL Renderer");
			return;
		}
	
		setupViewport();
	}

	void Renderer::iUpdateViewportRectangle()
	{
		SDL_Rect viewport{ 0, 0, windowWidth, windowHeight };
		SDL_Color color = iGetDrawColor();
		iSetDrawColor(color.r, color.g, color.b, color.a);

		SDL_RenderFillRect(renderer, &viewport);
		SDL_RenderDrawRect(renderer, &viewport);
	}

	SDL_Renderer* Renderer::iGetRenderer()
	{
		return renderer;
	}

	SDL_Color Renderer::iGetDrawColor()
	{
		return drawColor;
	}

	void Renderer::iSetDrawColor(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a)
	{
		SDL_Color color;
		color.r = r;
		color.g = g;
		color.b = b;
		color.a = a;

		drawColor = color;
		SDL_SetRenderDrawColor(renderer, r, g, b, a);
	}

	Renderer& Renderer::get()
	{
		static Renderer instance;

		return instance;
	}
}