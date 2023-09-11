#pragma once

#include <AL/al.h>

namespace wase::audio
{
	class SoundSource
	{
	public:
		~SoundSource();

		/**
		 * Play a sound
		 * 
		 * @param buffer The buffer to play
		 */
		void play(const ALuint buffer);
		
		float m_Pitch = 1.0f;
		float m_Gain = 1.0f;
		bool m_Loop = false;

	private:
		ALuint m_Source;
		ALuint m_Buffer;
	};
}