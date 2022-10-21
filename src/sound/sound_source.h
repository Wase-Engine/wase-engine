#pragma once
#include <AL/al.h>

namespace wase::sound
{
    class SoundSource
    {
    public:
        ~SoundSource();
        SoundSource();
        void Play(const ALuint buffer_to_play);
        void Stop();
	    void Pause();
	    void Resume();

        void SetLooping(const bool& loop);

	    bool isPlaying();


    private:
        ALuint m_Source;
        float m_Pitch = 1.0f;
        float m_Gain = 1.0f;
        float m_Position[3] = { 0, 0, 0, };
        float m_Velocity[3] = { 0, 0, 0, };
        bool m_LoopSound = false;
        ALuint m_Buffer = 0;
    };
}