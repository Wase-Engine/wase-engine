#include "draw.h"

#include "renderer.h"

namespace wase
{
	void Draw::render()
	{
		get().iRender();
	}

	Rectangle* Draw::rectangle(const SDL_Rect& rect, const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a, const bool fill)
	{
		return get().iRectangle(rect, r, g, b, a, fill);
	}

	void Draw::iRender()
	{
		SDL_Color previousColor = Renderer::getDrawColor();

		for (std::shared_ptr<Rectangle>& rectangle : rectangles)
		{
			Renderer::setDrawColor(rectangle->r, rectangle->g, rectangle->b, rectangle->a);

			if (rectangle->fill)
			{
				SDL_RenderFillRect(Renderer::getRenderer(), &rectangle->rect);
			}

			SDL_RenderDrawRect(Renderer::getRenderer(), &rectangle->rect);
		}

		Renderer::setDrawColor(previousColor.r, previousColor.g, previousColor.b, previousColor.a);
	}

	Rectangle* Draw::iRectangle(const SDL_Rect& rect, const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a, const bool fill)
	{
		std::shared_ptr<Rectangle> rectangle = std::make_shared<Rectangle>();
		rectangle->rect = rect;
		rectangle->fill = fill;
		rectangle->r = r;
		rectangle->g = g;
		rectangle->b = b;
		rectangle->a = a;

		rectangles.push_back(rectangle);

		return rectangle.get();
	}

	Draw& Draw::get()
	{
		static Draw instance;

		return instance;
	}
}