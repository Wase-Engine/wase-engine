#include "audio_source.h"

namespace wase
{
	AudioSource::AudioSource(const std::string& t_Name, const Uint8 t_Volume, const bool t_Loop, const bool t_PlayOnAwake)
		: loop(t_Loop)
	{
		m_AudioClip = ResourceManager::getAudio(t_Name);
		if (!m_AudioClip)
		{
			return;
		}

		setVolume(t_Volume);

		if (t_PlayOnAwake)
		{
			play();
		}
	}

	void AudioSource::play()
	{
		m_Channel = Mix_PlayChannel(-1, m_AudioClip, loop);
	}

	void AudioSource::onStateChange(const bool state)
	{
		if (m_Channel != -1)
		{
			if (!state)
			{
				Mix_Pause(m_Channel);
			}
			else
			{
				Mix_Resume(m_Channel);
			}
		}
	}

	void AudioSource::setVolume(float volume)
	{
		if (volume > 128)
		{
			volume = 128;
		}
		else if (volume < 0)
		{
			volume = 0;
		}
		else
		{
			volume = (volume / 100) * 128;
		}

		m_AudioClip->volume = (Uint8)volume;
	}

	void AudioSource::destroy()
	{
		Mix_FreeChunk(m_AudioClip);
	}
}