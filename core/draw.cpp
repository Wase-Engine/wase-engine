#include "draw.h"

#include "renderer.h"

std::shared_ptr<Draw> Draw::instance = nullptr;

void Draw::render()
{
	for (std::shared_ptr<Rectangle>& rectangle : getInstance()->rectangles)
	{
		SDL_SetRenderDrawColor(Renderer::getRenderer(), rectangle->r, rectangle->g, rectangle->b, rectangle->a);

		if (rectangle->fill)
		{
			SDL_RenderFillRect(Renderer::getRenderer(), rectangle->rect);
		}

		SDL_RenderDrawRect(Renderer::getRenderer(), rectangle->rect);
	}
}

void Draw::rectangle(SDL_Rect& rect, const int r, const int g, const int b, const int a, bool fill)
{
	std::shared_ptr<Rectangle> rectangle = std::make_shared<Rectangle>();
	rectangle->rect = &rect;
	rectangle->fill = fill;
	rectangle->r = r;
	rectangle->g = g;
	rectangle->b = b;
	rectangle->a = a;

	getInstance()->rectangles.push_back(rectangle);
}

std::shared_ptr<Draw> Draw::getInstance()
{
	return instance = (instance != nullptr) ? instance : std::make_shared<Draw>();
}