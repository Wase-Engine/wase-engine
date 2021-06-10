#pragma once

#include <SDL.h>
#include <memory>
#include <vector>

struct Rectangle
{
	int r, g, b, a;
	bool fill;
	SDL_Rect* rect;
};

class Draw
{
public:
	static void render();
	static void rectangle(SDL_Rect& rect, const int r, const int g, const int b, const int a, bool fill = true);

private:
	static std::shared_ptr<Draw> instance;

	std::vector<std::shared_ptr<Rectangle>> rectangles;

private:
	static std::shared_ptr<Draw> getInstance();
};