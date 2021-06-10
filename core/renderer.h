#pragma once

#include <SDL.h>
#include <memory>

class Renderer
{
public:
	static void init();
	static SDL_Renderer* getRenderer();

private:
	static std::shared_ptr<Renderer> getInstance();

private:
	static std::shared_ptr<Renderer> instance;

	SDL_Renderer* renderer;
};