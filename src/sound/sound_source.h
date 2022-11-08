#pragma once
#include <AL/al.h>
#include "math/vector3.h"

namespace wase::sound
{
    class SoundSource
    {
    public:
        SoundSource(math::Vector3 position = math::Vector3::zero(), math::Vector3 velocity = math::Vector3::zero(), 
        float pitch = 1.0f, float gain = 1.0f, bool looping = false);

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

        /**
         * Deletes m_Source by using the alDeleteSources() function
         */
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