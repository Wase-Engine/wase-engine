#include "resource_manager.h"

#include "../renderer.h"
#include "../utils/log_utils.h"

#include <SDL_image.h>

std::shared_ptr<ResourceManager> ResourceManager::instance = nullptr;

SDL_Texture* ResourceManager::getTexture(const std::string& name)
{
	try
	{
		return std::any_cast<SDL_Texture*>(getInstance()->resources[name]);
	}
	catch (std::exception)
	{
		log_utils::error("Texture " + name + " not found.");
		return nullptr;
	}
}

Mix_Chunk* ResourceManager::getAudio(const std::string& name)
{
	try
	{
		return std::any_cast<Mix_Chunk*>(getInstance()->resources[name]);
	}
	catch (std::exception)
	{
		log_utils::error("Audio " + name + " not found.");
		return nullptr;
	}
}

void ResourceManager::loadTexture(const std::string& name, const char* path)
{
	SDL_Texture* texture = IMG_LoadTexture(Renderer::getRenderer(), path);

	if (!texture)
	{
		log_utils::error(IMG_GetError());
		return;
	}

	getInstance()->resources[name] = texture;
}

void ResourceManager::loadAudio(const std::string& name, const char* path)
{
	Mix_Chunk* audio = Mix_LoadWAV(path);

	if (!audio)
	{
		log_utils::error(Mix_GetError());
		return;
	}

	getInstance()->resources[name] = audio;
}

std::shared_ptr<ResourceManager> ResourceManager::getInstance()
{
	return instance = (instance != nullptr) ? instance : std::make_shared<ResourceManager>();
}