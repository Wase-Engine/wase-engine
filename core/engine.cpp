#include "engine.h"

#include "window.h"
#include "renderer.h"
#include "scene_manager.h"
#include "input.h"
#include "utils/log_utils.h"

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>

Engine* Engine::instance = nullptr;

Engine::Engine()
{
	instance = this;
}

void Engine::run(const char* sceneName)
{
	SceneManager::setActiveScene(sceneName);

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
	SceneManager::getActiveScene()->updateScene();
}

void Engine::render()
{
	SDL_RenderClear(Renderer::getRenderer());

	SceneManager::getActiveScene()->renderScene();

	SDL_RenderPresent(Renderer::getRenderer());
}

void Engine::destroy()
{
	SDL_DestroyRenderer(Renderer::getRenderer());
	SDL_DestroyWindow(Window::getWindow());
	SDL_Quit();
	Mix_Quit();
	IMG_Quit();

	delete SceneManager::getInstance();
	delete Window::getInstance();
	delete Renderer::getInstance();
	delete this;
}

void Engine::quit()
{
	isRunning = false;
}

Engine* Engine::getInstance()
{
	return instance = (instance != nullptr) ? instance : new Engine;
}