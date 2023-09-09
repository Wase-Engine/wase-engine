#pragma once

#include <unordered_map>
#include <memory>
#include <functional>
#include <string>

#include <system/configuration.h>
#include <scene/scene_context.h>
#include <scene/scene.h>

namespace wase::system
{
	struct Configuration;
}

namespace wase::scene
{
	class Scene;
	struct SceneContext;

	class SceneManager
	{
	public:
		/**
		 * Initializes the scene manager
		 * 
		 * @param config: the configuration to use
		 * @return if the scene manager was initialized successfully
		 */
		bool initialize(system::Configuration& config, const std::shared_ptr<SceneContext> context);

		/**
		 * Update the scene manager
		 */
		void update(const float deltaTime);

		/**
		 * Set the current scene
		 *
		 * @param name: the name of the scene
		 */
		void setActiveScene(const std::string& name);
		
		/**
		 * Checks if the scene manager has a scene with the given name
		 * 
		 * @param name: the name of the scene
		 * @return if the scene manager has a scene with the given name
		 */
		bool hasScene(const std::string& name) const;

	private:
		std::unordered_map<std::string, std::function<std::shared_ptr<Scene>()>> m_SceneFunctions;
		std::shared_ptr<Scene> m_NextScene;
		std::shared_ptr<Scene> m_CurrentScene;
		bool m_NewCurrentScene = true;
		std::shared_ptr<SceneContext> m_Context;
	};
}