#include <input/input.h>

namespace wase::input
{
	void Input::initialize(GLFWwindow* window)
	{
		glfwSetWindowUserPointer(window, this);
		glfwSetKeyCallback(window, glfwKeyCallback);
		glfwSetMouseButtonCallback(window, glfwMouseButtonCallback);
		glfwSetCursorPosCallback(window, glfwCursorPositionCallback);
		glfwSetScrollCallback(window, glfwScrollCallback);
	}

	void Input::update()
	{
		for (auto&[key, keyState] : m_Keys)
		{
			if (keyState == KeyState::DOWN)
				keyState = KeyState::HELD_DOWN_AFTER;
			else if (keyState == KeyState::RELEASED)
				keyState = KeyState::IDLE;
		}

		for (auto& [button, buttonState] : m_MouseButtons)
		{
			if (buttonState == KeyState::DOWN)
				buttonState = KeyState::HELD_DOWN_AFTER;
			else if (buttonState == KeyState::RELEASED)
				buttonState = KeyState::IDLE;
		}

		m_MouseMovedX = 0.0f;
		m_MouseMovedY = 0.0f;
		m_MouseScroll = 0.0f;
	}

	void Input::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (action == GLFW_PRESS)
			m_Keys[key] = KeyState::DOWN;
		else if (action == GLFW_RELEASE)
			m_Keys[key] = KeyState::RELEASED;
	}

	void Input::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		if (action == GLFW_PRESS)
			m_MouseButtons[button] = KeyState::DOWN;
		else if (action == GLFW_RELEASE)
			m_MouseButtons[button] = KeyState::RELEASED;
	}
	
	void Input::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
	{
		m_MouseMovedX = static_cast<float>(xpos - m_MouseX);
		m_MouseMovedY = static_cast<float>(ypos - m_MouseY);
		m_MouseX = static_cast<float>(xpos);
		m_MouseY = static_cast<float>(ypos);
	}

	void Input::scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
	{
		m_MouseScroll = static_cast<float>(yoffset);
	}

	bool Input::isKeyDown(const int key)
	{
		if (!m_Keys.count(key))
			return false;

		return m_Keys[key] > 0;
	}

	bool Input::isKeyPressed(const int key)
	{
		if (!m_Keys.count(key))
			return false;

		return m_Keys[key] == KeyState::DOWN;
	}
	
	bool Input::isKeyReleased(const int key)
	{
		if (!m_Keys.count(key))
			return false;

		return m_Keys[key] == KeyState::RELEASED;
	}

	bool Input::isMouseButtonDown(const int button)
	{
		if (!m_MouseButtons.count(button))
			return false;

		return m_MouseButtons[button] > 0;
	}

	bool Input::isMouseButtonPressed(const int button)
	{
		if (!m_MouseButtons.count(button))
			return false;

		return m_MouseButtons[button] == KeyState::DOWN;
	}

	bool Input::isMouseButtonReleased(const int button)
	{
		if (!m_MouseButtons.count(button))
			return false;

		return m_MouseButtons[button] == KeyState::RELEASED;
	}

	float Input::getMouseX()
	{
		return m_MouseX;
	}

	float Input::getMouseY()
	{
		return m_MouseY;
	}

	wase::math::Vector2 Input::getMousePosition()
	{
		return wase::math::Vector2(m_MouseX, m_MouseY);
	}

	float Input::getMouseMovedX()
	{
		return m_MouseMovedX;
	}

	float Input::getMouseMovedY()
	{
		return m_MouseMovedY;
	}

	float Input::getMouseScroll()
	{
		return m_MouseScroll;
	}

	static void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Input* input = reinterpret_cast<Input*>(glfwGetWindowUserPointer(window));

		input->keyCallback(window, key, scancode, action, mods);
	}

	static void glfwMouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		Input* input = reinterpret_cast<Input*>(glfwGetWindowUserPointer(window));

		input->mouseButtonCallback(window, button, action, mods);
	}

	static void glfwCursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
	{
		Input* input = reinterpret_cast<Input*>(glfwGetWindowUserPointer(window));

		input->cursorPositionCallback(window, xpos, ypos);
	}

	static void glfwScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
	{
		Input* input = reinterpret_cast<Input*>(glfwGetWindowUserPointer(window));

		input->scrollCallback(window, xoffset, yoffset);
	}
}