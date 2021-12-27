#pragma once

#include <SDL.h>
#include <memory>

namespace wase
{
	class Renderer
	{
	public:
		Renderer(const Renderer&) = delete;

		static void init();
		static void updateViewportRectangle();

		static SDL_Renderer* getRenderer();
		static SDL_Color getDrawColor();
		static void setDrawColor(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a);

	private:
		SDL_Renderer* renderer = nullptr;
		SDL_Color drawColor = { 0, 0, 0, 1 };
		int monitorWidth, monitorHeight, windowWidth, windowHeight;

	private:
		Renderer() {}

		void setupViewport();

		void iInit();
		void iUpdateViewportRectangle();

		SDL_Renderer* iGetRenderer();
		SDL_Color iGetDrawColor();
		void iSetDrawColor(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a);

		static Renderer& get();
	};
}