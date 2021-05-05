#include "engine.h"

#include "window.h"
#include "renderer.h"
#include "../ecs/entity_manager.h"
#include "input.h"
#include "utils/log_utils.h"

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>

Engine* Engine::instance = nullptr;

Engine::Engine()
{
	instance = this;

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
		log_utils::error("Could not initialize SDL");
		return;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		log_utils::error("Could not initialize SDL Mixer");
		return;
	}

	Window::getInstance();
	Renderer::getInstance();

	isRunning = true;
}

void Engine::events()
{
	input::events::update();
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
	return instance = (instance != nullptr) ? instance : new Engine;
}

void Engine::quit()
{
	isRunning = false;
}