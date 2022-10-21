#include "sound_source.h"
#include <iostream>

namespace wase::sound
{
    SoundSource::SoundSource()
    {
        alGenSources(1, &m_Source);
        alSourcei(m_Source, AL_BUFFER, m_Buffer);
    }

    SoundSource::~SoundSource()
    {
        alDeleteSources(1, &m_Source);
    }

    void SoundSource::Play(const ALuint buffer_to_play)
    {
        if (buffer_to_play != m_Buffer)
        {
            m_Buffer = buffer_to_play;
            alSourcei(m_Source, AL_BUFFER, (ALint)m_Buffer);
        }

        alSourcePlay(m_Source);
    }

    void SoundSource::Stop()
    {
        alSourceStop(m_Source);
    }

    void SoundSource::Pause()
    {
        alSourcePause(m_Source);
    }

    void SoundSource::Resume()
    {
        alSourcePlay(m_Source);
    }

    void SoundSource::SetLooping(const bool& loop)
    {
        alSourcei(m_Source, AL_LOOPING, (ALint)loop);
    }

    bool SoundSource::isPlaying()
    {
        ALint playState;
        alGetSourcei(m_Source, AL_SOURCE_STATE, &playState);
        return (playState == AL_PLAYING);
    }

}