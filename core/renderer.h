#pragma once

#include <SDL.h>
#include <memory>

class Renderer
{
public:
	static std::shared_ptr<Renderer> getInstance();
	static SDL_Renderer* getRenderer();

public:
	Renderer();

private:
	static std::shared_ptr<Renderer> instance;

	SDL_Renderer* renderer;
};