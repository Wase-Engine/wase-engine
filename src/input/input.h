#pragma once

#include <unordered_map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <input/key_state.h>
#include <math/vector2.h>

namespace wase::input
{
	class Input
	{
	public:
		/**
		 * Initializes the input system.
		 * 
		 * @param window The window to initialize the input system for
		 */
		void initialize(GLFWwindow* window);

		/**
		 * Update the input system
		 */
		void update();

		/**
		 * Check if a key is being held down
		 * 
		 * @param key: The key that is being checked
		 * @return true if the key is held down
		 */
		bool isKeyDown(const int key);
		
		/**
		 * Check if a key is pressed down once
		 *
		 * @param key: The key that is being checked
		 * @return true if the key is pressed down
		 */
		bool isKeyPressed(const int key);

		/**
		 * Check if a key is released
		 * 
		 * @param key: The key that is being checked
		 * @return true if the key is released
		 */
		bool isKeyReleased(const int key);

		/**
		 * Check if a mouse button is being held down
		 *
		 * @param button: The button that is being checked
		 * @return true if the button is held down
		 */
		bool isMouseButtonDown(const int button);

		/**
		 * Check if a mouse button is pressed down once
		 *
		 * @param button: The button that is being checked
		 * @return true if the button is pressed down
		 */
		bool isMouseButtonPressed(const int button);

		/**
		 * Check if a mouse button is released
		 *
		 * @param button: The button that is being checked
		 * @return true if the button is released
		 */
		bool isMouseButtonReleased(const int button);

		/**
		 * Get the mouse x position
		 * 
		 * @return The mouse x position
		 */
		float getMouseX();
		
		/**
		 * Get the mouse y position
		 *
		 * @return The mouse y position
		 */
		float getMouseY();

		/**
		 * Get the mouse position
		 * 
		 * @return The mouse position
		 */
		wase::math::Vector2 getMousePosition();

		/**
		 * Get the amount the mouse moved in the x axis since the last frame
		 *
		 * @return the amount the mouse moved in the x axis since the last frame
		 */
		float getMouseMovedX();

		/**
		 * Get the amount the mouse moved in the y axis since the last frame
		 *
		 * @return the amount the mouse moved in the y axis since the last frame
		 */
		float getMouseMovedY();

		/**
		 * Get the amount the y axis of the scrollwheel has moved since last frame
		 * 
		 * @return the amount the y axis of the scrollwheel has moved since last frame
		 */
		float getMouseScroll();

		/**
		 * GLFW key callback
		 */
		void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

		/**
		 * GLFW mouse callback
		 */
		void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

		/**
		 * GLFW cursor position callback
		 */
		void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);

		/**
		 * GLFW scroll callback
		 */
		void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);

	private:		
		std::unordered_map<int, KeyState> m_Keys;
		std::unordered_map<int, KeyState> m_MouseButtons;

		float m_MouseX, m_MouseMovedX;
		float m_MouseY, m_MouseMovedY;
		float m_MouseScroll;
	};

	static void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void glfwMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static void glfwCursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
	static void glfwScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
}