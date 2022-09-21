#include <iostream>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

int main(int argv, const char* argc[])
{
	if (!glfwInit())
	{
		std::cerr << "Failed to initialize GLFW\n";
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "Sample", NULL, NULL);

	if (!window)
	{
		std::cerr << "Failed to create a window\n";
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW\n";
		glfwTerminate();
		return -1;
	}

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		
		glClearColor(1.0f, 0.2f, 0.5f, 1.0f);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}