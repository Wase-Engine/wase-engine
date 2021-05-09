#pragma once

#include "scene.h"

#include <map>
#include <string>
#include <memory>

class SceneManager
{
public:
	static std::shared_ptr<SceneManager> getInstance();

	static void addScene(const std::string& name, std::shared_ptr<Scene> scene);

	static std::shared_ptr<Scene> getActiveScene();
	static void setActiveScene(const std::string& name);

private:
	static std::shared_ptr<SceneManager> instance;
	
	std::map<std::string, std::shared_ptr<Scene>> scenes;

	std::shared_ptr<Scene> activeScene;
};