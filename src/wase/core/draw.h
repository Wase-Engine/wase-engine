#pragma once

#include <SDL.h>
#include <memory>
#include <vector>

namespace wase
{
	struct Rectangle
	{
		int r, g, b, a;
		bool fill;
		SDL_Rect rect;
	};

	class Draw
	{
	public:
		Draw(const Draw&) = delete;

		static void render();
		static Rectangle* rectangle(const SDL_Rect& rect, const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a, const bool fill = true);

	private:
		std::vector<std::shared_ptr<Rectangle>> rectangles;

	private:
		Draw() {}

		void iRender();
		Rectangle* iRectangle(const SDL_Rect& rect, const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a, const bool fill = true);
	
		static Draw& get();
	};
}