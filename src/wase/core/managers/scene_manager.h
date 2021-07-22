#pragma once

#include "../scene.h"

#include <map>
#include <string>
#include <memory>

namespace wase
{
	class SceneManager
	{
	public:
		static void addScene(const std::string& name, const std::shared_ptr<Scene> scene);

		static Scene* getActiveScene();
		static void setActiveScene(const std::string& name);

	private:
		static std::shared_ptr<SceneManager> instance;

		std::map<std::string, std::shared_ptr<Scene>> scenes;

		std::shared_ptr<Scene> activeScene;

	private:
		static std::shared_ptr<SceneManager> getInstance();
	};
}