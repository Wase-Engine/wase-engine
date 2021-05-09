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
	for (const auto&[sceneName, scenePtr] : scenes)
	{
		delete scenePtr;
	}
}

SceneManager* SceneManager::getInstance()
{
	return instance = (instance != nullptr) ? instance : new SceneManager;
}