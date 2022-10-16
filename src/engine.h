#pragma once

#include <memory>

#include <system/configuration.h>
#include <system/window.h>
#include <scene/scene_manager.h>

namespace wase
{
	class Engine
	{
	public:
		/**
		 * Initialize the engine.
		 * 
		 * @param config: the configuration to use
		 */
		void initialize(const wase::system::Configuration& config);

		/**
		 * Start the engine loop
		 */
		void run();

		/**
		 * Shut down the engine and all running processes
		 */
		void shutdown();

		/**
		 * Get the scene manager
		 * 
		 * @return the scene manager
		 */
		std::shared_ptr<wase::scene::SceneManager> getSceneManager() const;

	private:
		/**
		 * Initialize GLFW
		 * 
		 * @return if GLFW was initialized successfully
		 */
		bool initializeGLFW();

		/**
		 * Initialize GLEW
		 * 
		 * @return if GLEW was initialized successfully
		 */
		bool initializeGLEW();
		
		/**
		 * Initialize the logger
		 */
		void initializeLogger();

		/**
		 * Initialize the window
		 * 
		 * @return if the window was initialized successfully
		 */
		bool initializeWindow();
		
		/**
		 * Initialize the scene manager
		 * 
		 * @return if the scene manager was initialized successfully
		 */
		bool initializeSceneManager();

		wase::system::Configuration m_Config;

		std::unique_ptr<wase::system::Window> m_Window = nullptr;
		std::shared_ptr<wase::scene::SceneManager> m_SceneManager = nullptr;

		bool m_Initialized = false;
	};
}