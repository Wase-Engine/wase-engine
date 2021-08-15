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
#include "terminate_exception.h"

#include <SDL_mixer.h>
#include <SDL_image.h>

namespace wase
{
	std::shared_ptr<Engine> Engine::instance = nullptr;

	void Engine::run(const char* sceneName)
	{
		try
		{
			SceneManager::setActiveScene(sceneName);

			while (isRunning)
			{
				events();
				update(Timer::getDeltaTime());
				render();
				Timer::tick();
				input::events::end();
			}

			destroy();
		}
		catch (TerminateException& e)
		{
			log_utils::error(e.what());
		}
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

		// Initialize SDL_TTF
		if (TTF_Init() < 0)
		{
			log_utils::error("Could not initialize TTF");
			return;
		}

		Window::init(title, x, y, w, h, flags);
		Renderer::init();

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

		Renderer::updateViewportRectangle();

		SceneManager::getActiveScene()->renderScene();

		Draw::render();

		SDL_SetRenderDrawColor(Renderer::getRenderer(), 0, 0, 0, 255);

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

	void Engine::terminate(const std::string& message)
	{
		throw TerminateException(message);
	}

	std::shared_ptr<Engine> Engine::getInstance()
	{
		return instance = (instance != nullptr) ? instance : std::make_shared<Engine>();
	}
}