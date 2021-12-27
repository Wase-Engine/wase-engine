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
		scenes[name] = scene;
	}

	Scene* SceneManager::iGetActiveScene()
	{
		return activeScene.get();
	}

	void SceneManager::iSetActiveScene(const std::string& name)
	{
		activeScene = scenes[name];
		activeScene->startScene();
	}

	SceneManager& SceneManager::get()
	{
		static SceneManager instance;

		return instance;
	}
}