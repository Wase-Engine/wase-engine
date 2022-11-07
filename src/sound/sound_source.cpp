#include "sound_source.h"
#include <iostream>

namespace wase::sound
{
    SoundSource::SoundSource()
    {
        alGenSources(1, &m_Source);
        alSourcei(m_Source, AL_BUFFER, m_Buffer);
    }

    void SoundSource::play(const ALuint buffer_to_play)
    {
        if (buffer_to_play != m_Buffer)
        {
            m_Buffer = buffer_to_play;
            alSourcei(m_Source, AL_BUFFER, (ALint)m_Buffer);
        }

        alSourcePlay(m_Source);
    }

    void SoundSource::stop()
    {
        alSourceStop(m_Source);
    }

    void SoundSource::pause()
    {
        alSourcePause(m_Source);
    }

    void SoundSource::resume()
    {
        alSourcePlay(m_Source);
    }

    void SoundSource::setLooping(const bool& loop)
    {
        alSourcei(m_Source, AL_LOOPING, (ALint)loop);
    }

    bool SoundSource::isPlaying()
    {
        ALint playState;
        alGetSourcei(m_Source, AL_SOURCE_STATE, &playState);
        return (playState == AL_PLAYING);
    }

    void SoundSource::cleanUp()
    {
        alDeleteSources(1, &m_Source);
    }
}