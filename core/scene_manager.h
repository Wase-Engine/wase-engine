#pragma once

#include "scene.h"

#include <map>
#include <string>

class SceneManager
{
public:
	~SceneManager();

	static SceneManager* getInstance();

	static void addScene(const std::string& name, Scene* scene);

	static Scene* getActiveScene();
	static void setActiveScene(const std::string& name);

private:
	static SceneManager* instance;
	
	std::map<std::string, Scene*> scenes;

	Scene* activeScene;
};