#include <engine.h>

#include <debugging/log_manager.h>
#include <debugging/log.h>

namespace wase
{
	Engine& Engine::get()
	{
		static Engine engine;
		
		return engine;
	}

	void Engine::initialize()
	{
		wase::debugging::LogManager::initialize();
		WASE_CORE_INFO("Started initializing Wase Engine");
	}

	void Engine::shutdown()
	{
		WASE_CORE_INFO("Shutting down Wase Engine");
		wase::debugging::LogManager::shutdown();
	}
}