#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <memory>
#include <string>
#include <map>
#include <any>

class ResourceManager
{
public:
	static std::shared_ptr<ResourceManager> getInstance();

	static SDL_Texture* getTexture(const std::string& name);
	static Mix_Chunk* getAudio(const std::string& name);
	static TTF_Font* getFont(const std::string& name);

	static void loadTexture(const std::string& name, const char* path);
	static void loadAudio(const std::string& name, const char* path);
	static void loadFont(const std::string& name, const char* path, unsigned int fontSize);

private:
	static std::shared_ptr<ResourceManager> instance;
	
	std::map<std::string, std::any> resources;
};