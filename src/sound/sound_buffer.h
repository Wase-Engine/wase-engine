#pragma once
#include <al.h>
#include <vector>

#define SB_LOAD wase::sound::SoundBuffer::get()->load
#define SB_UNLOAD wase::sound::SoundBuffer::get()->unload

namespace wase::sound
{
    class SoundBuffer
    {
    public:
        static SoundBuffer* get();

        ALuint load(const char* filename);
        bool unload(const ALuint& buffer);
        ~SoundBuffer();
    private:
        SoundBuffer();
        
        
        std::vector<ALuint> m_SoundEffectBuffers;
    };
}