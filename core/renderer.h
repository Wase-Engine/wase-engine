#pragma once

#include <SDL.h>

class Renderer
{
private:
	static Renderer* instance;

	SDL_Renderer* renderer;

	Renderer();

public:
	static SDL_Renderer* getRenderer();
	static Renderer* getInstance();
};