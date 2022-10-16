#pragma once

#include <string>
#include <unordered_map>
#include <memory>

#include <scene/scene.h>

namespace wase::scene
{
	class Scene;
}

namespace wase::system
{
	struct Configuration
	{
		const char* name = "Wase Engine";
		unsigned int windowWidth = 1280, windowHeight = 720;
		bool vsync = true;
		std::unordered_map<std::string, std::shared_ptr<wase::scene::Scene>> scenes;
		std::string startScene;
	};
}