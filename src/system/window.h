#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <system/configuration.h>
#include <math/vector2.h>

namespace wase::system
{
	struct Configuration;

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
		bool isOpen() const;

		/**
		 * Get the width and height of the window
		 * 
		 * @return the width and height of the window
		 */
		math::Vector2 getWindowSize() const;

		/**
		 * Get the GLFWwindow
		 * 
		 * @return the GLFWwindow
		 */
		GLFWwindow* getGLFWWindow() const;
			
	private:		
		GLFWwindow* m_Window = nullptr;
	};

	void framebufferSizeCallback(GLFWwindow* window, int width, int height);
}