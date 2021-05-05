#include "renderer.h"
#include "window.h"

#include <iostream>

Renderer* Renderer::instance = nullptr;

Renderer::Renderer()
{
	renderer = SDL_CreateRenderer(Window::getWindow(), -1, NULL);
	if (!renderer)
	{
		std::cerr << "Could not initialize SDL Renderer\n";
		return;
	}
}

SDL_Renderer* Renderer::getRenderer()
{
	return getInstance()->renderer;
}

Renderer* Renderer::getInstance()
{
	return instance = (instance != nullptr) ? instance : new Renderer;
}