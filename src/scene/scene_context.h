#pragma once

#include <memory>

#include <scene/scene_manager.h>
#include <input/input.h>
#include <resources/resource_pool.h>
#include <system/window.h>

namespace wase::system
{
	class Window;
}

namespace wase::scene
{
	class SceneManager;
	
	struct SceneContext
	{
		std::shared_ptr<SceneManager> sceneManager;
		std::shared_ptr<input::Input> input;
		std::shared_ptr<resources::ResourcePool> resourcePool;
		std::shared_ptr<system::Window> window;
	};
}