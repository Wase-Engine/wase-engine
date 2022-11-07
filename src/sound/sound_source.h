#pragma once
#include <AL/al.h>

namespace wase::sound
{
    class SoundSource
    {
    public:
        SoundSource();

        /**
         * Plays the buffer from the argument and sets m_Buffer to the argument (buffer_to_play)
         */
        void play(const ALuint buffer_to_play);

        /**
         * Stops playing
         */
        void stop();

        /**
         * Pauses the sound
         */
	    void pause();

        /**
         * Resumes the sound
         */
	    void resume();

        /**
         * Sets whether or not the sound is looping
         */
        void setLooping(const bool& loop);

        /**
         * Checks if the sound is still playing
         * 
         * @return if the sound is still playing
         */
	    bool isPlaying();

        void cleanUp();

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