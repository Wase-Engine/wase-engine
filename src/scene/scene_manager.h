#pragma once

#include <unordered_map>
#include <memory>
#include <string>

#include <scene/scene.h>
#include <system/configuration.h>
#include <scene/scene_context.h>

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
		bool initialize(wase::system::Configuration& config, const SceneContext& context);

		/**
		 * Update the scene manager
		 */
		void update();

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
		
		/**
		 * Add multiple scenes at once to the scene manager
		 *
		 * @param scenes: a map with scenes(with string name) to add
		 */
		void addScenes(std::unordered_map<std::string, std::shared_ptr<Scene>>& scenes);

		std::unordered_map<std::string, std::shared_ptr<Scene>> m_Scenes;
		std::shared_ptr<Scene> m_CurrentScene;
		bool m_NewCurrentScene = true;
	};
}