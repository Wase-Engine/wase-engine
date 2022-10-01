#include <scene/scene_manager.h>

namespace wase::scene
{
	void SceneManager::update()
	{
		if (m_NewCurrentScene)
		{
			m_CurrentScene->start();
			m_NewCurrentScene = false;
		}
		
		m_CurrentScene->update();
	}

	void SceneManager::addScene(const std::string& name, const std::shared_ptr<Scene>& scene)
	{
		m_Scenes[name] = scene;
	}

	void SceneManager::addScenes(const std::unordered_map<std::string, std::shared_ptr<Scene>>& scenes)
	{
		for (const auto& [name, scene] : scenes)
			m_Scenes[name] = scene;
	}

	void SceneManager::setActiveScene(const std::string& name)
	{
		m_CurrentScene = m_Scenes[name];
		m_NewCurrentScene = true;
	}

	bool SceneManager::hasScene(const std::string& name) const
	{
		return m_Scenes.count(name);
	}
}