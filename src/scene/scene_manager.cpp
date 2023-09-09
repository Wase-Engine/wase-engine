#include <scene/scene_manager.h>
#include <debugging/log.h>
#include <rendering/vao.h>
#include <rendering/vbo.h>
#include <rendering/ibo.h>
#include <rendering/texture.h>
#include <rendering/shader.h>

namespace wase::scene
{
	bool SceneManager::initialize(system::Configuration& config, const std::shared_ptr<SceneContext> context)
	{
		this->m_Context = context;
		this->m_SceneFunctions = config.scenes;

		if (!this->hasScene(config.startScene))
		{
			WASE_CORE_CRITICAL("Failed to find start scene");

			return false;
		}

		this->setActiveScene(config.startScene);

		return true;
	}
	
	void SceneManager::update(const float deltaTime)
	{
		if (m_NewCurrentScene)
		{
			rendering::Texture::unbind();
			rendering::VAO::unbind();
			rendering::VBO::unbind();
			rendering::IBO::unbind();
			rendering::Shader::unbind();
			
			m_CurrentScene = m_NextScene;
			m_CurrentScene->start();
			m_NewCurrentScene = false;
		}
		
		m_CurrentScene->update(deltaTime);
		m_CurrentScene->updateWorld(deltaTime);
	}

	void SceneManager::setActiveScene(const std::string& name)
	{
		m_NextScene = m_SceneFunctions[name]();
		
		if (!this->hasScene(name))
		{
			WASE_CORE_CRITICAL("Failed to find {0} scene", name);

			return;
		}

		m_NewCurrentScene = true;
		m_NextScene->initialize(m_Context);
	}

	bool SceneManager::hasScene(const std::string& name) const
	{
		return m_SceneFunctions.count(name);
	}
}