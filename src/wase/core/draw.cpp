#include "draw.h"

#include "renderer.h"

std::shared_ptr<Draw> Draw::instance = nullptr;

void Draw::render()
{
	SDL_Color previousColor = Renderer::getDrawColor();

	for (std::shared_ptr<Rectangle>& rectangle : getInstance()->rectangles)
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

Rectangle* Draw::rectangle(const SDL_Rect& rect, const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a, const bool fill)
{
	std::shared_ptr<Rectangle> rectangle = std::make_shared<Rectangle>();
	rectangle->rect = rect;
	rectangle->fill = fill;
	rectangle->r = r;
	rectangle->g = g;
	rectangle->b = b;
	rectangle->a = a;

	getInstance()->rectangles.push_back(rectangle);

	return rectangle.get();
}

std::shared_ptr<Draw> Draw::getInstance()
{
	return instance = (instance != nullptr) ? instance : std::make_shared<Draw>();
}