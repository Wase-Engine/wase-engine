#include "scene_manager.h"

namespace wase
{
	void SceneManager::addScene(const std::string& name, const std::shared_ptr<Scene> scene)
	{
		get().iAddScene(name, scene);
	}

	Scene* SceneManager::getActiveScene()
	{
		return get().iGetActiveScene();
	}

	void SceneManager::setActiveScene(const std::string& name)
	{
		get().iSetActiveScene(name);
	}

	void SceneManager::iAddScene(const std::string& name, const std::shared_ptr<Scene> scene)
	{
		m_Scenes[name] = scene;
	}

	Scene* SceneManager::iGetActiveScene()
	{
		return m_ActiveScene.get();
	}

	void SceneManager::iSetActiveScene(const std::string& name)
	{
		m_ActiveScene = m_Scenes[name];
		m_ActiveScene->startScene();
	}

	SceneManager& SceneManager::get()
	{
		static SceneManager instance;

		return instance;
	}
}