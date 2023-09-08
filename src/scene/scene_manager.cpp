#include <scene/scene_manager.h>
#include <debugging/log.h>

namespace wase::scene
{
	bool SceneManager::initialize(system::Configuration& config, const SceneContext& context)
	{
		this->addScenes(config.scenes);

		if (!this->hasScene(config.startScene))
		{
			WASE_CORE_CRITICAL("Failed to find start scene");

			return false;
		}

		this->setActiveScene(config.startScene);
		
		for (auto& [name, scene] : m_Scenes)
			scene->initialize(context);

		return true;
	}
	
	void SceneManager::update(const float deltaTime)
	{
		if (m_NewCurrentScene)
		{
			m_CurrentScene->start();
			m_NewCurrentScene = false;
		}
		
		m_CurrentScene->update(deltaTime);
		m_CurrentScene->updateWorld(deltaTime);
	}

	void SceneManager::addScenes(std::unordered_map<std::string, std::shared_ptr<Scene>>& scenes)
	{
		m_Scenes = std::move(scenes);
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