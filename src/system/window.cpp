#include <system/window.h>

namespace wase::system
{
	bool Window::initialize(const Configuration& config)
	{
		m_Window = glfwCreateWindow(config.m_WindowWidth, config.m_WindowHeight, config.m_Name, nullptr, nullptr);
		if (!m_Window)
			return false;

		glfwMakeContextCurrent(m_Window);
		glfwSwapInterval(config.m_Vsync);

		return true;
	}
	
	void Window::shutdown()
	{
		if (m_Window != nullptr)
			glfwDestroyWindow(m_Window);
	}

	void Window::update()
	{
		if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(m_Window, GLFW_TRUE);

		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	bool Window::isOpen()
	{
		return glfwWindowShouldClose(m_Window) == 0;
	}
}