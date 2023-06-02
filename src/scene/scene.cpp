#include <scene/scene.h>

namespace wase::scene
{
	void Scene::initialize(const SceneContext& context)
	{
		m_Context = context;
	}

	void Scene::updateWorld(const float deltaTime)
	{
		m_World.update(deltaTime);
	}

	void Scene::start()
	{

	}
	
	void Scene::update(const float deltaTime)
	{
		
	}
}