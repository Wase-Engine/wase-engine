#include <audio/sound_device.h>
#include <debugging/log.h>
#include <debugging/open_al_check.h>

namespace wase::audio
{
	SoundDevice::~SoundDevice()
	{
		OPEN_AL_CHECK(alcMakeContextCurrent(nullptr));
		OPEN_AL_CHECK(alcDestroyContext(m_Context));
		OPEN_AL_CHECK(alcCloseDevice(m_Device));
	}

	bool SoundDevice::initialize()
	{
		m_Device = alcOpenDevice(nullptr);
		if (!m_Device)
		{
			WASE_CORE_ERROR("Failed to open sound device");
			return false;
		}

		m_Context = alcCreateContext(m_Device, NULL);
		if (!m_Context)
		{
			WASE_CORE_ERROR("Failed to create sound context");
			return false;
		}
		
		if (!alcMakeContextCurrent(m_Context))
		{
			WASE_CORE_ERROR("Failed to make sound context current");
			return false;
		}

		return true;
	}
}