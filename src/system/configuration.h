#pragma once

#include <string>
#include <unordered_map>
#include <functional>
#include <memory>
#include <vector>

#include <scene/scene.h>
#include <system/window_mode.h>
#include <resources/resource.h>

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
		WindowMode windowMode = WindowMode::WINDOWED;
		bool vsync = true;
		std::unordered_map<std::string, std::function<std::shared_ptr<scene::Scene>()>> scenes;
		std::string startScene;
		std::vector<wase::resources::Resource> resources;
	};
}