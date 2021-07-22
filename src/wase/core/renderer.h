#pragma once

#include <SDL.h>
#include <memory>

namespace wase
{
	class Renderer
	{
	public:
		static void init();
		static SDL_Renderer* getRenderer();
		static SDL_Color getDrawColor();
		static void setDrawColor(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a);

	private:
		static std::shared_ptr<Renderer> getInstance();

	private:
		static std::shared_ptr<Renderer> instance;

		SDL_Renderer* renderer = nullptr;
		SDL_Color drawColor = { 0, 0, 0, 1 };
	};
}