#include <engine.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <debugging/log_manager.h>
#include <debugging/log.h>

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

		WASE_CORE_INFO("Successfully initialized Wase Engine");

		m_Initialized = true;
	}

	void Engine::run()
	{
		if (!m_Initialized)
			return;

		while (m_Window->isOpen())
		{
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

	bool Engine::initializeGLFW()
	{
		if (!glfwInit())
		{
			WASE_CORE_CRITICAL("Failed to initialize GLFW");
			
			return false;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
		
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

		return true;
	}
}