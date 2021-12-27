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
		SceneManager(const SceneManager&) = delete;

		static void addScene(const std::string& name, const std::shared_ptr<Scene> scene);

		static Scene* getActiveScene();
		static void setActiveScene(const std::string& name);

	private:
		std::map<std::string, std::shared_ptr<Scene>> scenes;

		std::shared_ptr<Scene> activeScene;

	private:
		SceneManager() {}

		void iAddScene(const std::string& name, const std::shared_ptr<Scene> scene);

		Scene* iGetActiveScene();
		void iSetActiveScene(const std::string& name);

		static SceneManager& get();
	};
}