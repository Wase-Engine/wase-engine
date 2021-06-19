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

private:
	Mix_Chunk* audioClip = nullptr;
	int channel = -1;

public:
	AudioSource(const std::string& name, const Uint8 volume = 100, const bool loop = false, const bool playOnAwake = false)
	{
		this->loop = loop;

		audioClip = ResourceManager::getAudio(name);
		if (!audioClip)
		{
			return;
		}

		setVolume(volume);

		if (playOnAwake)
		{
			play();
		}
	}

	void play()
	{
		channel = Mix_PlayChannel(-1, audioClip, loop);
	}

	void onStateChange(const bool state)
	{
		if (channel != -1)
		{
			if (!state)
			{
				Mix_Pause(channel);
			}
			else
			{
				Mix_Resume(channel);
			}
		}
	}

	void setVolume(float volume)
	{
		if (volume > 128)
		{
			volume = 128;
		}
		else if (volume < 0)
		{
			volume = 0;
		}
		else
		{
			volume = (volume / 100) * 128;
		}

		audioClip->volume = (Uint8)volume;
	}

	void destroy()
	{
		Mix_FreeChunk(audioClip);
	}
};