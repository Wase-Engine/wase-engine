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
		
		if (config.windowMode == WindowMode::WINDOWED || config.windowMode == WindowMode::WINDOWED_FULLSCREEN)
		{
			if (config.windowMode == WindowMode::WINDOWED_FULLSCREEN)
				glfwWindowHint(GLFW_MAXIMIZED, GL_TRUE);
			
			m_Window = glfwCreateWindow(config.windowWidth, config.windowHeight, config.name, nullptr, nullptr);
		}
		else if (config.windowMode == WindowMode::FULLSCREEN)
		{
			GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
			const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);
			m_Window = glfwCreateWindow(mode->width, mode->height, config.name, primaryMonitor, nullptr);
		}

		if (!m_Window)
			return false;

		glfwMakeContextCurrent(m_Window);
		glfwSwapInterval(config.vsync);

		glfwSetFramebufferSizeCallback(m_Window, framebufferSizeCallback);

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

	math::Vector2 Window::getWindowSize() const
	{
		int width, height;
		
		glfwGetWindowSize(m_Window, &width, &height);

		return math::Vector2(static_cast<float>(width), static_cast<float>(height));
	}

	GLFWwindow* Window::getGLFWWindow() const
	{
		return m_Window;
	}
	
	void framebufferSizeCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}