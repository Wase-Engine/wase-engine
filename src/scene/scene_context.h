#pragma once

#include <memory>

#include <scene/scene_manager.h>
#include <input/input.h>

namespace wase::scene
{
	class SceneManager;
	
	struct SceneContext
	{
		std::shared_ptr<SceneManager> sceneManager;
		std::shared_ptr<wase::input::Input> input;
	};
}