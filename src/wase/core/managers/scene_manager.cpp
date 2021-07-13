#include "scene_manager.h"

std::shared_ptr<SceneManager> SceneManager::instance = nullptr;

void SceneManager::addScene(const std::string& name, const std::shared_ptr<Scene> scene)
{
	getInstance()->scenes[name] = scene;
}

Scene* SceneManager::getActiveScene()
{
	return getInstance()->activeScene.get();
}

void SceneManager::setActiveScene(const std::string& name)
{
	getInstance()->activeScene = getInstance()->scenes[name];
	getInstance()->activeScene->startScene();
}

std::shared_ptr<SceneManager> SceneManager::getInstance()
{
	return instance = (instance != nullptr) ? instance : std::make_shared<SceneManager>();
}