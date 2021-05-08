#pragma once

#include "scene.h"

#include <map>

class SceneManager
{
public:
	~SceneManager();

	static SceneManager* getInstance();

	static void addScene(const char* name, Scene* scene);

	static Scene* getActiveScene();
	static void setActiveScene(const char* name);

private:
	static SceneManager* instance;
	
	std::map<const char*, Scene*> scenes;

	Scene* activeScene;
};