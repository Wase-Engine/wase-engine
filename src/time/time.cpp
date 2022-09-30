#include <time/time.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace wase::time
{
	float Time::m_DeltaTime = 0.0f;
	float Time::m_LastFrameTime = 0.0f;

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