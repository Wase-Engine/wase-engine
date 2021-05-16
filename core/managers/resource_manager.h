#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <memory>
#include <string>
#include <map>
#include <any>

class ResourceManager
{
public:
	static SDL_Texture* getTexture(const std::string& name);
	static Mix_Chunk* getAudio(const std::string& name);

	static void loadTexture(const std::string& name, const char* path);
	static void loadAudio(const std::string& name, const char* path);

private:
	static std::shared_ptr<ResourceManager> instance;
	
	std::map<std::string, std::any> resources;

private:
	static std::shared_ptr<ResourceManager> getInstance();
};