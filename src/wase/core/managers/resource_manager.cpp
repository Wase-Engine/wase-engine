#include "resource_manager.h"

#include "../renderer.h"
#include "../utils/log_utils.h"

#include <SDL.h>
#include <SDL_image.h>

namespace wase
{
	SDL_Texture* ResourceManager::getTexture(const std::string& name)
	{
		return get().iGetTexture(name);
	}

	Mix_Chunk* ResourceManager::getAudio(const std::string& name)
	{
		return get().iGetAudio(name);
	}

	TTF_Font* ResourceManager::getFont(const std::string& name)
	{
		return get().iGetFont(name);
	}

	void ResourceManager::loadTexture(const std::string& name, const char* path)
	{
		get().iLoadTexture(name, path);
	}

	void ResourceManager::loadAudio(const std::string& name, const char* path)
	{
		get().iLoadAudio(name, path);
	}

	void ResourceManager::loadFont(const std::string& name, const char* path, unsigned int fontSize)
	{
		get().iLoadFont(name, path, fontSize);
	}

	SDL_Texture* ResourceManager::iGetTexture(const std::string& name)
	{
		try
		{
			return std::any_cast<SDL_Texture*>(m_Resources[name]);
		}
		catch (std::exception)
		{
			log_utils::error("Texture " + name + " not found.");
			return nullptr;
		}
	}

	Mix_Chunk* ResourceManager::iGetAudio(const std::string& name)
	{
		try
		{
			return std::any_cast<Mix_Chunk*>(m_Resources[name]);
		}
		catch (std::exception)
		{
			log_utils::error("Audio " + name + " not found.");
			return nullptr;
		}
	}

	TTF_Font* ResourceManager::iGetFont(const std::string& name)
	{
		try
		{
			return std::any_cast<TTF_Font*>(m_Resources[name]);
		}
		catch (std::exception)
		{
			log_utils::error("Font " + name + " not found.");
			return nullptr;
		}
	}

	void ResourceManager::iLoadTexture(const std::string& name, const char* path)
	{
		SDL_Texture* texture = IMG_LoadTexture(Renderer::getRenderer(), path);

		if (!texture)
		{
			log_utils::error(IMG_GetError());
			return;
		}

		m_Resources[name] = texture;
	}

	void ResourceManager::iLoadAudio(const std::string& name, const char* path)
	{
		Mix_Chunk* audio = Mix_LoadWAV(path);

		if (!audio)
		{
			log_utils::error(Mix_GetError());
			return;
		}

		m_Resources[name] = audio;
	}

	void ResourceManager::iLoadFont(const std::string& name, const char* path, unsigned int fontSize)
	{
		TTF_Font* font = TTF_OpenFont(path, fontSize);

		if (!font)
		{
			log_utils::error(TTF_GetError());
			return;
		}

		m_Resources[name] = font;
	}

	ResourceManager& ResourceManager::get()
	{
		static ResourceManager instance;

		return instance;
	}
}