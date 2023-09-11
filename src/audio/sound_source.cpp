#include <audio/sound_source.h>
#include <debugging/open_al_check.h>

namespace wase::audio
{
	SoundSource::~SoundSource()
	{
		OPEN_AL_CHECK(alDeleteSources(1, &m_Source));
	}

	void SoundSource::play(const ALuint buffer)
	{
		OPEN_AL_CHECK(alGenSources(1, &m_Source));
		OPEN_AL_CHECK(alSourcef(m_Source, AL_PITCH, m_Pitch));
		OPEN_AL_CHECK(alSourcef(m_Source, AL_GAIN, m_Gain)); // 0.0f - 1.0f
		OPEN_AL_CHECK(alSourcei(m_Source, AL_LOOPING, m_Loop));
		OPEN_AL_CHECK(alSourcei(m_Source, AL_BUFFER, m_Buffer));

		if (buffer != m_Buffer)
		{
			m_Buffer = buffer;
			OPEN_AL_CHECK(alSourcei(m_Source, AL_BUFFER, m_Buffer));
		}
		
		OPEN_AL_CHECK(alSourcePlay(m_Source));
	}
}