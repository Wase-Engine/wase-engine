#include <engine.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <debugging/log_manager.h>
#include <debugging/log.h>
#include <time/time.h>
#include <input/input.h>

namespace wase
{
	Engine& Engine::get()
	{
		static Engine engine;

		return engine;
	}

	void Engine::initialize(const wase::system::Configuration& config)
	{
		m_Config = config;

		this->initializeLogger();

		if (!this->initializeGLFW())
			return;
		if (!this->initializeWindow())
			return;
		if (!this->initializeGLEW())
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
			wase::time::Time::update();
			// Logic here
			m_SceneManager->update();
			wase::input::Input::update();
			m_Window->update();
		}
	}

	void Engine::shutdown()
	{
		WASE_CORE_INFO("Shutting down Wase Engine");

		if (m_Window)
			m_Window->shutdown();

		glfwTerminate();
		wase::debugging::LogManager::shutdown();
	}

	std::shared_ptr<wase::scene::SceneManager> Engine::getSceneManager() const
	{
		return m_SceneManager;
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
		wase::debugging::LogManager::initialize();
		WASE_CORE_INFO("Started initializing Wase Engine");
	}

	bool Engine::initializeWindow()
	{
		m_Window = std::make_unique<wase::system::Window>();
		if (!m_Window->initialize(m_Config))
		{
			WASE_CORE_CRITICAL("Failed to initialize window");

			return false;
		}
		
		wase::input::Input::initialize(m_Window->getGLFWWindow());

		return true;
	}

	bool Engine::initializeSceneManager()
	{
		m_SceneManager = std::make_unique<wase::scene::SceneManager>();

		m_SceneManager->addScenes(m_Config.scenes);

		if (!m_SceneManager->hasScene(m_Config.startScene))
		{
			WASE_CORE_CRITICAL("Failed to find start scene");
			
			return false;
		}

		m_SceneManager->setActiveScene(m_Config.startScene);

		return true;
	}
}