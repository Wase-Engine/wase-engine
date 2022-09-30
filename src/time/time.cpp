#include <time/time.h>

namespace wase::time
{
	float Time::m_DeltaTime = 0.0f;

	void Time::setDeltaTime(const float time)
	{
		// Set a cap in case of freezes like a breakpoint that has been hit
		if (time < 1)
			m_DeltaTime = time;
	}

	float Time::getDeltaTime()
	{
		return m_DeltaTime;
	}
}