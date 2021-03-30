#pragma once

#include "../component.h"

#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>
#include <map>

class AudioSource : public Component
{
private:
	Mix_Chunk* audioClip;
	int channel = -1;

public:
	bool playing = false;
	bool loop;

	AudioSource(const char* path, bool loop, Uint8 volume, bool playOnAwake)
	{
		this->loop = loop;

		audioClip = Mix_LoadWAV(path);
		if (!audioClip)
		{
			std::cerr << Mix_GetError() << "\n";
			return;
		}

		setVolume(volume);

		if (playOnAwake)
		{
			play();
		}
	}

	void init() override
	{
	}

	void events() override
	{

	}

	void update() override
	{
	}

	void render() override
	{

	}

	void play()
	{
		channel = Mix_PlayChannel(-1, audioClip, loop);
	}

	void onStateChange(bool state) override
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

		audioClip->volume = (Uint8) volume;
	}

	~AudioSource()
	{
		Mix_FreeChunk(audioClip);
	}
};