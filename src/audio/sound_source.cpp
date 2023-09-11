#include <audio/sound_source.h>
#include <debugging/open_al_check.h>

namespace wase::audio
{
	SoundSource::~SoundSource()
	{
		OPEN_AL_CHECK(alDeleteSources(1, &m_Source));
	}

	void SoundSource::play(const ALuint buffer, const bool loop)
	{
		OPEN_AL_CHECK(alGenSources(1, &m_Source));
		OPEN_AL_CHECK(alSourcei(m_Source, AL_LOOPING, loop));

		if (buffer != m_Buffer)
		{
			m_Buffer = buffer;
			OPEN_AL_CHECK(alSourcei(m_Source, AL_BUFFER, m_Buffer));
		}
		
		OPEN_AL_CHECK(alSourcePlay(m_Source));
	}

	float SoundSource::getPitch() const
	{
		return m_Pitch;
	}

	float SoundSource::getGain() const
	{
		return m_Gain;
	}

	void SoundSource::setPitch(const float pitch)
	{
		m_Pitch = pitch;
		OPEN_AL_CHECK(alSourcef(m_Source, AL_PITCH, m_Pitch));
	}

	void SoundSource::setGain(const float gain)
	{
		m_Gain = gain;
		OPEN_AL_CHECK(alSourcef(m_Source, AL_GAIN, m_Gain));
	}

	void SoundSource::stop() const
	{
		if (m_Source == NULL)
		{
			WASE_CORE_WARN("SoundSource::stop() called on a sound that is not playing");
			return;
		}
		
		ALint sourceState;
		OPEN_AL_CHECK(alGetSourcei(m_Source, AL_SOURCE_STATE, &sourceState));

		if (sourceState != AL_PLAYING)
		{
			WASE_CORE_WARN("SoundSource::stop() called on a sound that is not playing");
			return;
		}

		OPEN_AL_CHECK(alSourceStop(m_Source));
	}
}