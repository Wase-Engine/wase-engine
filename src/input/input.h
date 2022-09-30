#pragma once

#include <unordered_map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <input/key_state.h>

namespace wase::input
{
	class Input final
	{
	public:
		/**
		 * Initializes the input system.
		 * 
		 * @param window The window to initialize the input system for
		 */
		static void initialize(GLFWwindow* window);

		/**
		 * Update the input system
		 */
		static void update();

		/**
		 * Check if a key is being held down
		 * 
		 * @param key: The key that is being checked
		 * @return true if the key is held down
		 */
		static bool getKey(const int key);
		
		/**
		 * Check if a key is pressed down once
		 *
		 * @param key: The key that is being checked
		 * @return true if the key is pressed down
		 */
		static bool getKeyDown(const int key);

		/**
		 * Check if a key is released
		 * 
		 * @param key: The key that is being checked
		 * @return true if the key is released
		 */
		static bool getKeyUp(const int key);

		/**
		 * Check if a mouse button is being held down
		 *
		 * @param button: The button that is being checked
		 * @return true if the button is held down
		 */
		static bool getMouseButton(const int button);

		/**
		 * Check if a mouse button is pressed down once
		 *
		 * @param button: The button that is being checked
		 * @return true if the button is pressed down
		 */
		static bool getMouseButtonDown(const int button);

		/**
		 * Check if a mouse button is released
		 *
		 * @param button: The button that is being checked
		 * @return true if the button is released
		 */
		static bool getMouseButtonUp(const int button);

	private:
		static GLFWwindow* m_Window;
		static std::unordered_map<int, KeyState> m_Keys;
		static std::unordered_map<int, KeyState> m_MouseButtons;

		/**
		 * GLFW key callback
		 */
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

		/**
		 * GLFW mouse callback
		 */
		static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	};
}