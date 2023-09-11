#include <engine.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <debugging/log_manager.h>
#include <debugging/log.h>
#include <time/time.h>
#include <input/input.h>

namespace wase
{
	void Engine::initialize(const system::Configuration& config)
	{
		m_Config = config;

		this->initializeLogger();
		this->initializeResourcePool(config.resources);

		if (!this->initializeGLFW())
			return;
		if (!this->initializeWindow())
			return;
		if (!this->initializeGLEW())
			return;
		if (!this->initializeSoundDevice())
			return;
		if (!this->initializeSceneManager())
			return;

		WASE_CORE_INFO("Successfully initialized Wase Engine");

		m_Initialized = true;
	}

	void Engine::run()
	{
		if (!m_Initialized)
			return;

		while (m_Window->isOpen())
		{
			m_Time.update();
			m_SceneManager->update(m_Time.getDeltaTime());
			m_Input->update();
			m_Window->update();
		}
	}

	void Engine::shutdown()
	{
		WASE_CORE_INFO("Shutting down Wase Engine");

		if (m_Window)
			m_Window->shutdown();

		glfwTerminate();
		debugging::LogManager::shutdown();
	}

	bool Engine::initializeGLFW()
	{
		if (!glfwInit())
		{
			WASE_CORE_CRITICAL("Failed to initialize GLFW");

			return false;
		}

		return true;
	}

	bool Engine::initializeGLEW()
	{
		if (glewInit() != GLEW_OK)
		{
			WASE_CORE_CRITICAL("Failed to initialize GLEW");

			return false;
		}

		return true;
	}

	void Engine::initializeLogger()
	{
		debugging::LogManager::initialize();
		WASE_CORE_INFO("Started initializing Wase Engine");
	}

	bool Engine::initializeWindow()
	{
		m_Window = std::make_shared<system::Window>();
		if (!m_Window->initialize(m_Config))
		{
			WASE_CORE_CRITICAL("Failed to initialize window");

			return false;
		}
		
		m_Input = std::make_shared<input::Input>();
		m_Input->initialize(m_Window->getGLFWWindow());

		return true;
	}

	bool Engine::initializeSoundDevice()
	{
		m_SoundDevice = std::make_shared<audio::SoundDevice>();
		if (!m_SoundDevice->initialize())
		{
			WASE_CORE_CRITICAL("Failed to initialize the SoundDevice");

			return false;
		}

		return true;
	}

	bool Engine::initializeSceneManager()
	{
		m_SceneManager = std::make_unique<scene::SceneManager>();
		
		std::shared_ptr<scene::SceneContext> context = std::make_shared<scene::SceneContext>(m_SceneManager, m_Input, m_ResourcePool, m_Window);
		if (!m_SceneManager->initialize(m_Config, context))
		{
			WASE_CORE_CRITICAL("Failed to initialize the SceneManager");
			
			return false;
		}

		return true;
	}

	void Engine::initializeResourcePool(const std::vector<resources::Resource>& resources)
	{
		m_ResourcePool = std::make_shared<resources::ResourcePool>();
		m_ResourcePool->initialize(resources);
	}
}