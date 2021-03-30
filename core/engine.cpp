#include "engine.h"
#include "window.h"
#include "renderer.h"
#include "../ecs/entity_manager.h"
#include "input.h"

#include "../ecs/components/transform.h"
#include "../ecs/components/sprite_renderer.h"
#include "../ecs/components/audio_source.h"

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
		case SDL_KEYDOWN:
			input::events::keyDownEvent(event.key.keysym.sym);
			break;
		case SDL_KEYUP:
			input::events::keyUpEvent(event.key.keysym.sym);
			break;
		case SDL_MOUSEBUTTONDOWN:
			input::events::mouseButtonDownEvent(event.button.button);
			break;
		case SDL_MOUSEBUTTONUP:
			input::events::mouseButtonUpEvent(event.button.button);
			break;
		default:
			break;
		}
	}
}

void Engine::update()
{
	EntityManager::getInstance()->update();
}

void Engine::render()
{
	SDL_SetRenderDrawColor(Renderer::getRenderer(), 21, 21, 21, 255);
	SDL_RenderClear(Renderer::getRenderer());

	EntityManager::getInstance()->render();

	SDL_RenderPresent(Renderer::getRenderer());
}

void Engine::destroy()
{
	SDL_DestroyRenderer(Renderer::getRenderer());
	SDL_DestroyWindow(Window::getWindow());
	SDL_Quit();
	Mix_Quit();
	IMG_Quit();

	delete EntityManager::getInstance();
	delete Window::getInstance();
	delete Renderer::getInstance();
	delete this;
}

Engine* Engine::getInstance()
{
	return instance = (instance != nullptr) ? instance : new Engine();
}
