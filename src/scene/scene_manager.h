#pragma once

#include <unordered_map>
#include <memory>
#include <string>

#include <scene/scene.h>

namespace wase::scene
{
	class SceneManager
	{
	public:		
		/**
		 * Update the scene manager
		 */
		void update();

		/**
		 * Add a scene to the scene manager
		 *
		 * @param name: the name of the scene
		 * @param scene: the scene to add
		 */
		void addScene(const std::string& name, const std::shared_ptr<Scene>& scene);

		/**
		 * Add multiple scenes at once to the scene manager
		 * 
		 * @param scenes: a map with scenes(with string name) to add
		 */
		void addScenes(const std::unordered_map<std::string, std::shared_ptr<Scene>>& scenes);

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
		std::unordered_map<std::string, std::shared_ptr<Scene>> m_Scenes;
		std::shared_ptr<Scene> m_CurrentScene;
		bool m_NewCurrentScene = true;
	};
}