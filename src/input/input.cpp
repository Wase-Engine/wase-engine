#include <input/input.h>

namespace wase::input
{
	GLFWwindow* Input::m_Window = nullptr;
	std::unordered_map<int, KeyState> Input::m_Keys;

	void Input::initialize(GLFWwindow* window)
	{
		m_Window = window;
		
		glfwSetKeyCallback(window, key_callback);
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
	}

	void Input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (action == GLFW_PRESS)
			m_Keys[key] = KeyState::DOWN;
		else if (action == GLFW_RELEASE)
			m_Keys[key] = KeyState::RELEASED;
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
}