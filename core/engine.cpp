#include "engine.h"
#include "window.h"
#include "renderer.h"

#include <iostream>

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>

Engine* Engine::instance = nullptr;

Engine::Engine()
{
	init();

	while (isRunning)
	{
		events();
		update();
		render();
	}

	destroy();
}

void Engine::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cerr << "Could not initialize SDL\n";
		return;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cerr << "Could not initialize SDL Mixer\n";
		return;
	}

	Window::getInstance();
	Renderer::getInstance();

	isRunning = true;
}

void Engine::events()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
		}
	}
}

void Engine::update()
{

}

void Engine::render()
{
	SDL_SetRenderDrawColor(Renderer::getRenderer(), 21, 21, 21, 255);
	SDL_RenderClear(Renderer::getRenderer());

	SDL_RenderPresent(Renderer::getRenderer());
}

void Engine::destroy()
{
	SDL_DestroyRenderer(Renderer::getRenderer());
	SDL_DestroyWindow(Window::getWindow());
	SDL_Quit();
	Mix_Quit();
	IMG_Quit();

	delete Window::getInstance();
	delete Renderer::getInstance();
	delete this;
}

Engine* Engine::getInstance()
{
	return instance = (instance != nullptr) ? instance : new Engine();
}
