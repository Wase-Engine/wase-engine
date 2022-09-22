#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <system/configuration.h>

namespace wase::system
{
	class Window
	{
	public:
		/**
		 * Initialize the game window
		 * 
		 * @param config: the configuration to use
		 * @return if the window was initialized successfully
		 */
		bool initialize(const Configuration& config);

		/**
		 * Shut down the game window
		 */
		void shutdown();

		/**
		 * Update the game window
		 */
		void update();

		/**
		 * Check if the window is still open
		 * 
		 * @return if the window is still open
		 */
		bool isOpen();
			
	private:
		GLFWwindow* m_Window = nullptr;
	};
}