
#include "sound_device.h"
#include "sound_buffer.h"
#include "sound_source.h"
#include "music_player.h"
#include <system/configuration.h>
#include <engine.h>
#include <iostream>

namespace wase::sound
{
    void SoundExample()
    {
        // put sounds in your build folder.
        wase::sound::SoundDevice::init();
        SoundBuffer::init();
        uint32_t sound1 = SoundBuffer::load("1.wav");
        uint32_t sound2 = SoundBuffer::load("2.wav");
        uint32_t sound3 = SoundBuffer::load("3.wav");

        wase::sound::SoundSource mySpeaker;
        wase::sound::SoundSource mySpeaker2;
        wase::sound::SoundSource mySpeaker3;

        mySpeaker.play(sound1);
        mySpeaker2.play(sound2);
        mySpeaker3.play(sound3);

        MusicPlayer::loadMusic("date a live.wav");
        MusicPlayer::play();

        std::cout << "while\n";

        while (1)
        {
            MusicPlayer::updateBufferStream();
        }

        MusicPlayer::cleanUp();
        SoundBuffer::cleanUp();
        mySpeaker.cleanUp();
        mySpeaker2.cleanUp();
        mySpeaker3.cleanUp();
        SoundDevice::cleanUp();
    }
}