#pragma once

#include <SDL.h>
#include <memory>

namespace wase
{
	class Window
	{
	public:
		static void init(const char* title, const int x, const int y, const unsigned int w, const unsigned int h, const Uint32 flags);
		static SDL_Window* getWindow();
		static SDL_Rect* getRect();

	private:
		static std::shared_ptr<Window> instance;

		SDL_Window* window = nullptr;
		SDL_Rect rect;

	private:
		static std::shared_ptr<Window> getInstance();
	};
}