#pragma once

#include <SDL.h>
#include <memory>

namespace wase
{
	class Window
	{
	public:
		Window(const Window&) = delete;

		static void init(const char* title, const int x, const int y, const unsigned int w, const unsigned int h, const Uint32 flags);

		static SDL_Window* getWindow();
		static SDL_Rect getRect();
		static SDL_Rect getDisplayBounds();
		static bool isFullscreen();

	private:
		SDL_Window* m_Window = nullptr;
		SDL_Rect m_Rect;

	private:
		Window() {}

		void iInit(const char* title, const int x, const int y, const unsigned int w, const unsigned int h, const Uint32 flags);

		SDL_Window* iGetWindow();
		SDL_Rect iGetRect();
		SDL_Rect iGetDisplayBounds();
		bool iIsFullscreen();

		static Window& get();
	};
}