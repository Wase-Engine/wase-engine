
#include "sound_device.h"
#include "sound_buffer.h"
#include "sound_source.h"
#include "music_player.h"
#include <system/configuration.h>
#include <engine.h>
#include "math/vector3.h"

namespace wase::sound
{
    void SoundExample()
    {
        // put sounds in your build folder.
        // only mono sounds are affected by position
        wase::sound::SoundDevice::init();
        SoundBuffer::init();
        uint32_t sound1 = SoundBuffer::load("mono.wav");
        uint32_t sound2 = SoundBuffer::load("stereo.wav");

        // try changing the position of both of these.
        wase::sound::SoundSource mySpeaker(math::Vector3(0.0f, 0.0f, 0.0f));
        wase::sound::SoundSource mySpeaker2(math::Vector3(0.0f, 0.0f, 0.0f)); 

        mySpeaker.play(sound1);
        mySpeaker2.play(sound2);

        MusicPlayer::loadMusic("music.wav");
        MusicPlayer::play();

        while (1)
        {
            MusicPlayer::updateBufferStream();
        }

        MusicPlayer::cleanUp();
        SoundBuffer::cleanUp();
        mySpeaker.cleanUp();
        mySpeaker2.cleanUp();
        SoundDevice::cleanUp();
    }
}