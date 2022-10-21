
#include "sound_device.h"
#include "sound_buffer.h"
#include "sound_source.h"
#include "music_buffer.h"
#include <system/configuration.h>
#include <engine.h>

void SoundExample()
{
    std::unordered_map<std::string, std::shared_ptr<wase::scene::Scene>> scenes =
    {
            { "main", std::make_shared<wase::scene::Scene>() },
    };

    wase::system::Configuration config
    { 
            "Wase Engine", 1280, 720, true,
            scenes, "main"
    };

    // put sounds in your build folder.
    wase::sound::SoundDevice* soundDevice = LISTENER;
    uint32_t sound1 = SB_LOAD("1.wav");
    uint32_t sound2 = SB_LOAD("2.wav");
    uint32_t sound3 = SB_LOAD("3.wav");
    
    wase::sound::SoundSource mySpeaker;
    wase::sound::SoundSource mySpeaker2;
    wase::sound::SoundSource mySpeaker3;
    mySpeaker.Play(sound1);
    mySpeaker2.Play(sound2);
    mySpeaker3.Play(sound3);

    wase::sound::MusicBuffer music("africa-toto.wav");

    while (1)
    {
            music.UpdateBufferStream();
    }

    wase::Engine engine;
    engine.initialize(config);
    engine.run();
}