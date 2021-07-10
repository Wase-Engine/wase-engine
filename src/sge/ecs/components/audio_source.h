#pragma once

#include "../component.h"
#include "../../core/utils/log_utils.h"
#include "../../core/managers/resource_manager.h"

#include <SDL.h>
#include <SDL_mixer.h>
#include <map>
#include <string>

class AudioSource : public Component
{
public:
	bool playing = false;
	bool loop;

public:
	AudioSource(const std::string& name, const Uint8 volume = 100, const bool loop = false, const bool playOnAwake = false);
	void play();
	void onStateChange(const bool state);
	void setVolume(float volume);
	void destroy();

private:
	Mix_Chunk* audioClip = nullptr;
	int channel = -1;
};