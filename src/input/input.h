#pragma once

#include <unordered_map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <input/key_state.h>
#include <math/vector2.h>

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
		static bool isKeyDown(const int key);
		
		/**
		 * Check if a key is pressed down once
		 *
		 * @param key: The key that is being checked
		 * @return true if the key is pressed down
		 */
		static bool isKeyPressed(const int key);

		/**
		 * Check if a key is released
		 * 
		 * @param key: The key that is being checked
		 * @return true if the key is released
		 */
		static bool isKeyReleased(const int key);

		/**
		 * Check if a mouse button is being held down
		 *
		 * @param button: The button that is being checked
		 * @return true if the button is held down
		 */
		static bool isMouseButtonDown(const int button);

		/**
		 * Check if a mouse button is pressed down once
		 *
		 * @param button: The button that is being checked
		 * @return true if the button is pressed down
		 */
		static bool isMouseButtonPressed(const int button);

		/**
		 * Check if a mouse button is released
		 *
		 * @param button: The button that is being checked
		 * @return true if the button is released
		 */
		static bool isMouseButtonReleased(const int button);

		/**
		 * Get the mouse x position
		 * 
		 * @return The mouse x position
		 */
		static float getMouseX();
		
		/**
		 * Get the mouse y position
		 *
		 * @return The mouse y position
		 */
		static float getMouseY();

		/**
		 * Get the mouse position
		 * 
		 * @return The mouse position
		 */
		static wase::math::Vector2 getMousePosition();

		/**
		 * Get the amount the mouse moved in the x axis since the last frame
		 *
		 * @return the amount the mouse moved in the x axis since the last frame
		 */
		static float getMouseMovedX();

		/**
		 * Get the amount the mouse moved in the y axis since the last frame
		 *
		 * @return the amount the mouse moved in the y axis since the last frame
		 */
		static float getMouseMovedY();

	private:
		static GLFWwindow* m_Window;
		static std::unordered_map<int, KeyState> m_Keys;
		static std::unordered_map<int, KeyState> m_MouseButtons;
		
		static float m_MouseX, m_MouseMovedX;
		static float m_MouseY, m_MouseMovedY;

		/**
		 * GLFW key callback
		 */
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

		/**
		 * GLFW mouse callback
		 */
		static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

		/**
		 * GLFW cursor position callback
		 */
		static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
	};
}