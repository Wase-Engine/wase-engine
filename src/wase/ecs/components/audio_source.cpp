#include "audio_source.h"

AudioSource::AudioSource(const std::string& name, const Uint8 volume, const bool loop, const bool playOnAwake)
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

void AudioSource::play()
{
	channel = Mix_PlayChannel(-1, audioClip, loop);
}

void AudioSource::onStateChange(const bool state)
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

void AudioSource::setVolume(float volume)
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

void AudioSource::destroy()
{
	Mix_FreeChunk(audioClip);
}