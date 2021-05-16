#include "debug_draw.h"

#include "renderer.h"

std::shared_ptr<DebugDraw> DebugDraw::instance = nullptr;

void DebugDraw::render()
{
	for (std::shared_ptr<Rectangle>& rect : getInstance()->rectangles)
	{
		SDL_SetRenderDrawColor(Renderer::getRenderer(), rect->r, rect->g, rect->b, rect->a);
		SDL_RenderDrawRect(Renderer::getRenderer(), rect->rect);
	}
}

void DebugDraw::rectangle(SDL_Rect& rect, const int r, const int g, const int b, const int a)
{
	std::shared_ptr<Rectangle> rectangle = std::make_shared<Rectangle>();
	rectangle->rect = &rect;
	rectangle->r = r;
	rectangle->g = g;
	rectangle->b = b;
	rectangle->a = a;

	getInstance()->rectangles.push_back(rectangle);
}

std::shared_ptr<DebugDraw> DebugDraw::getInstance()
{
	return instance = (instance != nullptr) ? instance : std::make_shared<DebugDraw>();
}