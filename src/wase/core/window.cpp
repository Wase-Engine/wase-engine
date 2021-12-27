#include "window.h"

#include "utils/log_utils.h"

namespace wase
{
	void Window::init(const char* title, const int x, const int y, const unsigned int w, const unsigned int h, const Uint32 flags)
	{
		get().iInit(title, x, y, w, h, flags);
	}

	SDL_Window* Window::getWindow()
	{
		return get().iGetWindow();
	}

	SDL_Rect Window::getRect()
	{
		return get().iGetRect();
	}

	SDL_Rect Window::getDisplayBounds()
	{
		return get().iGetDisplayBounds();
	}

	bool Window::isFullscreen()
	{
		return get().iIsFullscreen();
	}

	void Window::iInit(const char* title, const int x, const int y, const unsigned int w, const unsigned int h, const Uint32 flags)
	{
		m_Window = SDL_CreateWindow(title, x, y, w, h, flags);
		if (!m_Window)
		{
			log_utils::error("Could not initialize SDL Window");
			return;
		}

		m_Rect.x = x;
		m_Rect.y = y;
		m_Rect.w = w;
		m_Rect.h = h;
	}

	SDL_Window* Window::iGetWindow()
	{
		return m_Window;
	}

	SDL_Rect Window::iGetRect()
	{
		return m_Rect;
	}

	SDL_Rect Window::iGetDisplayBounds()
	{
		SDL_Rect rect;
		if (SDL_GetDisplayBounds(0, &rect) != 0)
		{
			log_utils::error("Couldn't get the display bounds");
		}

		return rect;
	}

	bool Window::iIsFullscreen()
	{
		Uint32 flags = SDL_GetWindowFlags(m_Window);

		return flags & SDL_WINDOW_FULLSCREEN || flags & SDL_WINDOW_FULLSCREEN_DESKTOP;
	}

	Window& Window::get()
	{
		static Window instance;

		return instance;
	}
}