#pragma once

#include <SDL.h>
#include <memory>
#include <vector>

struct Rectangle
{
	int r, g, b, a;
	SDL_Rect* rect;
};

class DebugDraw
{
public:
	static void render();
	static void rectangle(SDL_Rect& rect, const int r, const int g, const int b, const int a);

private:
	static std::shared_ptr<DebugDraw> instance;

	std::vector<std::shared_ptr<Rectangle>> rectangles;

private:
	static std::shared_ptr<DebugDraw> getInstance();
};