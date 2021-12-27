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
		window = SDL_CreateWindow(title, x, y, w, h, flags);
		if (!window)
		{
			log_utils::error("Could not initialize SDL Window");
			return;
		}

		rect.x = x;
		rect.y = y;
		rect.w = w;
		rect.h = h;
	}

	SDL_Window* Window::iGetWindow()
	{
		return window;
	}

	SDL_Rect Window::iGetRect()
	{
		return rect;
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
		Uint32 flags = SDL_GetWindowFlags(window);

		return flags & SDL_WINDOW_FULLSCREEN || flags & SDL_WINDOW_FULLSCREEN_DESKTOP;
	}

	Window& Window::get()
	{
		static Window instance;

		return instance;
	}
}