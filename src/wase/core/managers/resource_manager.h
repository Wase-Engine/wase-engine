#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <memory>
#include <string>
#include <map>
#include <any>

namespace wase
{
	class ResourceManager
	{
	public:
		ResourceManager(const ResourceManager&) = delete;

		static SDL_Texture* getTexture(const std::string& name);
		static Mix_Chunk* getAudio(const std::string& name);
		static TTF_Font* getFont(const std::string& name);

		static void loadTexture(const std::string& name, const char* path);
		static void loadAudio(const std::string& name, const char* path);
		static void loadFont(const std::string& name, const char* path, unsigned int fontSize);

	private:
		std::map<std::string, std::any> m_Resources;

	private:
		ResourceManager() {}

		SDL_Texture* iGetTexture(const std::string& name);
		Mix_Chunk* iGetAudio(const std::string& name);
		TTF_Font* iGetFont(const std::string& name);

		void iLoadTexture(const std::string& name, const char* path);
		void iLoadAudio(const std::string& name, const char* path);
		void iLoadFont(const std::string& name, const char* path, unsigned int fontSize);

		static ResourceManager& get();
	};
}