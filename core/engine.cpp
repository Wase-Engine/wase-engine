#include "engine.h"

#include "window.h"
#include "renderer.h"
#include "managers/scene_manager.h"
#include "managers/resource_manager.h"
#include "events.h"
#include "input.h"
#include "utils/log_utils.h"
#include "timer.h"
#include "draw.h"

#include <SDL_mixer.h>
#include <SDL_image.h>

std::shared_ptr<Engine> Engine::instance = nullptr;

void Engine::run(const char* sceneName)
{
	SceneManager::setActiveScene(sceneName);

	Timer timer;

	while (isRunning)
	{
		events();
		update(timer.getDeltaTime());
		render();
		timer.tick();
	}

	destroy();
}

void Engine::init(const char* title, const int x, const int y, const unsigned int w, const unsigned int h, const Uint32 flags)
{
	// Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		log_utils::error("Could not initialize SDL");
		return;
	}

	// Initialize SDL_Mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		log_utils::error("Could not initialize SDL Mixer");
		return;
	}

	if (TTF_Init() < 0)
	{
		log_utils::error("Could not initialize TTF");
		return;
	}

	Window::init(title, x, y, w, h, flags);
	Renderer::init();
	ResourceManager::initEngineResources();

	isRunning = true;
}

void Engine::events()
{
	input::events::update();
	events::update();
}

void Engine::update(float dt)
{
	SceneManager::getActiveScene()->updateScene(dt);
}

void Engine::render()
{
	SDL_RenderClear(Renderer::getRenderer());

	SceneManager::getActiveScene()->renderScene();

	Draw::render();

	SDL_SetRenderDrawColor(Renderer::getRenderer(), 21, 21, 21, 255);

	SDL_RenderPresent(Renderer::getRenderer());
}

void Engine::destroy()
{
	SDL_DestroyRenderer(Renderer::getRenderer());
	SDL_DestroyWindow(Window::getWindow());
	SDL_Quit();
	Mix_Quit();
	IMG_Quit();
}

void Engine::quit()
{
	isRunning = false;
}

std::shared_ptr<Engine> Engine::getInstance()
{
	return instance = (instance != nullptr) ? instance : std::make_shared<Engine>();
}