#pragma once

#include "../component.h"
#include "../../core/utils/log_utils.h"
#include "../../core/managers/resource_manager.h"

#include <SDL.h>
#include <SDL_mixer.h>
#include <map>
#include <string>

namespace wase
{
	class AudioSource : public Component
	{
	public:
		bool playing = false;
		bool loop;

	public:
		AudioSource(const std::string& t_Name, const Uint8 t_Volume = 100, const bool t_Loop = false, const bool t_PlayOnAwake = false);
		
		void play();
		void onStateChange(const bool state) override;
		void setVolume(float volume);
		void destroy() override;

	private:
		Mix_Chunk* m_AudioClip = nullptr;
		int m_Channel = -1;
	};
}