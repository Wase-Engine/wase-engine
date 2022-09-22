#pragma once

#include <memory>

#include <system/configuration.h>
#include <system/window.h>

namespace wase
{
	class Engine
	{
	public:
		Engine(const Engine&) = delete;
		Engine& operator=(const Engine&) = delete;
		Engine(Engine&&) = default;
		Engine& operator=(Engine&&) = default;

		/**
		 * Get the instance of the engine.
		 * 
		 * @return The engine instance
		 */
		static Engine& get();

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

	private:		
		Engine() = default;
		~Engine() = default;

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

		wase::system::Configuration m_Config;

		std::unique_ptr<wase::system::Window> m_Window = nullptr;

		bool m_Initialized = false;
		float m_LastFrameTime = 0.0f;
	};
}