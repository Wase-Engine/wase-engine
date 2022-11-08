#include "sound_source.h"
#include <iostream>

namespace wase::sound
{
    SoundSource::SoundSource(math::Vector3 position, math::Vector3 velocity, float pitch, float gain, bool looping)
    {
        alGenSources(1, &m_Source);
        alSource3f(m_Source, AL_POSITION, position.x, position.y, position.z);
        alSource3f(m_Source, AL_VELOCITY, velocity.x, velocity.y, velocity.z);
        alSourcef(m_Source, AL_PITCH, pitch);
        alSourcef(m_Source, AL_GAIN, gain);
        alSourcei(m_Source, AL_LOOPING, looping);
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