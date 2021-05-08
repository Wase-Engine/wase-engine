#include "scene_manager.h"

SceneManager* SceneManager::instance = nullptr;

void SceneManager::addScene(const std::string& name, Scene* scene)
{
	getInstance()->scenes[name] = scene;
}

Scene* SceneManager::getActiveScene()
{
	return getInstance()->activeScene;
}

void SceneManager::setActiveScene(const std::string& name)
{
	getInstance()->activeScene = getInstance()->scenes[name];
	getInstance()->activeScene->startScene();
}

SceneManager::~SceneManager()
{
	for (std::pair<std::string, Scene*> scene : scenes)
	{
		delete scene.second;
	}
}

SceneManager* SceneManager::getInstance()
{
	return instance = (instance != nullptr) ? instance : new SceneManager;
}