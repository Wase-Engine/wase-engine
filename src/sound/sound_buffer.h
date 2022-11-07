#pragma once
#include <al.h>
#include <vector>

#define SB_INIT wase::sound::SoundBuffer::init
#define SB_LOAD wase::sound::SoundBuffer::load
#define SB_UNLOAD wase::sound::SoundBuffer::unload
#define SB_CLEAN wase::sound::SoundBuffer::cleanUp

namespace wase::sound
{
    class SoundBuffer
    {
    public:
        /**
         * Initialize the object by clearing the m_SoundEffectBuffers vector of elements.
         */
        static void init();

        /**
         * Load buffer data, put it in m_SoundEffectBuffers and return the data (not the vector);
         * 
         * @return buffer data from filename
         */
        static ALuint load(const char* filename);

        /**
         * Deletes the buffer in the argument
         * 
         * @return if the buffer could be removed 
         */
        static bool unload(const ALuint& buffer);

        /**
         * Calls the alDeleteBuffers function with two arguments: m_SoundEffectBuffers.size(), m_SoundEffectBuffers.data()
         * This function also calls m_SoundEffectBuffers.clear()
         */
        static void cleanUp();
    private:
        SoundBuffer();
        
        static std::vector<ALuint> m_SoundEffectBuffers;
    };
}