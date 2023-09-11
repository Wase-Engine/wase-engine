#pragma once

#include <AL/al.h>

namespace wase::audio
{
	class SoundBuffer
	{
	public:
		SoundBuffer(const char* path);
		~SoundBuffer();

		ALuint getID() const;
		
	private:
		ALuint m_Buffer;
	};
}