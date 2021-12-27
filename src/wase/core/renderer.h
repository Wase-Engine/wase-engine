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
		SDL_Renderer* m_Renderer = nullptr;
		SDL_Color m_DrawColor = { 0, 0, 0, 1 };
		int m_MonitorWidth, m_MonitorHeight, m_WindowWidth, m_WindowHeight;

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