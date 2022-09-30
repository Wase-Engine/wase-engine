#include <input/input.h>

namespace wase::input
{
	GLFWwindow* Input::m_Window = nullptr;
	std::unordered_map<int, KeyState> Input::m_Keys;
	std::unordered_map<int, KeyState> Input::m_MouseButtons;

	void Input::initialize(GLFWwindow* window)
	{
		m_Window = window;
		
		glfwSetKeyCallback(window, keyCallback);
		glfwSetMouseButtonCallback(window, mouseButtonCallback);
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

	bool Input::getKey(const int key)
	{
		if (!m_Keys.count(key))
			return false;

		return m_Keys[key] > 0;
	}

	bool Input::getKeyDown(const int key)
	{
		if (!m_Keys.count(key))
			return false;

		return m_Keys[key] == KeyState::DOWN;
	}
	
	bool Input::getKeyUp(const int key)
	{
		if (!m_Keys.count(key))
			return false;

		return m_Keys[key] == KeyState::RELEASED;
	}

	bool Input::getMouseButton(const int button)
	{
		if (!m_MouseButtons.count(button))
			return false;

		return m_MouseButtons[button] > 0;
	}

	bool Input::getMouseButtonDown(const int button)
	{
		if (!m_MouseButtons.count(button))
			return false;

		return m_MouseButtons[button] == KeyState::DOWN;
	}

	bool Input::getMouseButtonUp(const int button)
	{
		if (!m_MouseButtons.count(button))
			return false;

		return m_MouseButtons[button] == KeyState::RELEASED;
	}
}