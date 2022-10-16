#pragma once

#include <memory>

#include <scene/scene_manager.h>

namespace wase::scene
{
	class SceneManager;
	
	struct SceneContext
	{
		std::shared_ptr<SceneManager> sceneManager;
	};
}