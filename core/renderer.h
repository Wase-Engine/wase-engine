#pragma once

#include <SDL.h>

class Renderer
{
public:
	static SDL_Renderer* getRenderer();
	static Renderer* getInstance();

private:
	static Renderer* instance;

	SDL_Renderer* renderer;

private:
	Renderer();
};