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
		m_WindowWidth = Window::getRect().w;
		m_MonitorWidth = Window::getDisplayBounds().w;
		m_WindowHeight = Window::getRect().h;
		m_MonitorHeight = Window::getDisplayBounds().h;

		SDL_Rect viewport{ 0, 0, m_WindowWidth, m_WindowHeight };

		if (Window::isFullscreen())
		{
			if (m_MonitorWidth - m_WindowWidth > 0)
				viewport.x = (m_MonitorWidth - m_WindowWidth) / 2;

			if (m_MonitorHeight - m_WindowHeight > 0)
				viewport.y = (m_MonitorHeight - m_WindowHeight) / 2;
		}

		SDL_RenderSetViewport(m_Renderer, &viewport);
	}

	void Renderer::iInit()
	{
		m_Renderer = SDL_CreateRenderer(Window::getWindow(), -1, 0);
		if (!m_Renderer)
		{
			log_utils::error("Could not initialize SDL Renderer");
			return;
		}
	
		setupViewport();
	}

	void Renderer::iUpdateViewportRectangle()
	{
		SDL_Rect viewport{ 0, 0, m_WindowWidth, m_WindowHeight };
		SDL_Color color = iGetDrawColor();
		iSetDrawColor(color.r, color.g, color.b, color.a);

		SDL_RenderFillRect(m_Renderer, &viewport);
		SDL_RenderDrawRect(m_Renderer, &viewport);
	}

	SDL_Renderer* Renderer::iGetRenderer()
	{
		return m_Renderer;
	}

	SDL_Color Renderer::iGetDrawColor()
	{
		return m_DrawColor;
	}

	void Renderer::iSetDrawColor(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a)
	{
		SDL_Color color;
		color.r = r;
		color.g = g;
		color.b = b;
		color.a = a;

		m_DrawColor = color;
		SDL_SetRenderDrawColor(m_Renderer, r, g, b, a);
	}

	Renderer& Renderer::get()
	{
		static Renderer instance;

		return instance;
	}
}