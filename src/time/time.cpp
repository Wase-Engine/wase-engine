#include <time/time.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace wase::time
{
	void Time::update()
	{
		const float timeSinceStart = (float)glfwGetTime();
		const float time = timeSinceStart - m_LastFrameTime;

		if (time < 1)
			m_DeltaTime = time;

		m_LastFrameTime = timeSinceStart;
	}

	float Time::getDeltaTime()
	{
		return m_DeltaTime;
	}
}