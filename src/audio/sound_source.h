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
		void play(const ALuint buffer, const bool loop = false);

		/**
		 * Get the pitch of the sound
		 * 
		 * @return The pitch of the sound
		 */
		float getPitch() const;

		/**
		 * Get the gain of the sound
		 * 
		 * @return The gain of the sound
		 */
		float getGain() const;
		
		/**
		 * Set the pitch of the sound
		 * 
		 * @param pitch The pitch of the sound
		 */
		void setPitch(const float pitch);

		/**
		 * Set the gain of the sound
		 * 
		 * @param gain The gain of the sound between 0.0f and 1.0f
		 */
		void setGain(const float gain);

		/**
		 * Stop the playing sound
		 */
		void stop() const;

	private:
		ALuint m_Source;
		ALuint m_Buffer;

		float m_Pitch = 1.0f;
		float m_Gain = 1.0f;
	};
}