#pragma once

#include <AL/alc.h>

namespace wase::audio
{
	class SoundDevice
	{
	public:
		~SoundDevice();

		/**
		 * Initializes the sound device
		 * 
		 * @return Whether the sound device was successfully initialized
		 */
		bool initialize();

	private:
		ALCdevice* m_Device;
		ALCcontext* m_Context;
	};
}