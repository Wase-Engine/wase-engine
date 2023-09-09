#include <system/window.h>

#include <debugging/log.h>
#include <input/input.h>

namespace wase::system
{
	bool Window::initialize(const Configuration& config)
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

		m_Window = glfwCreateWindow(config.windowWidth, config.windowHeight, config.name, nullptr, nullptr);
		if (!m_Window)
			return false;

		glfwMakeContextCurrent(m_Window);
		glfwSwapInterval(config.vsync);

		return true;
	}
	
	void Window::shutdown()
	{
		if (m_Window != nullptr)
			glfwDestroyWindow(m_Window);
	}

	void Window::update()
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	bool Window::isOpen() const
	{
		return glfwWindowShouldClose(m_Window) == 0;
	}

	GLFWwindow* Window::getGLFWWindow() const
	{
		return m_Window;
	}
}