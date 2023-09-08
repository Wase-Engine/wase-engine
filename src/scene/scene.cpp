#include <scene/scene.h>
#include <ecs/systems/sprite_renderer.h>

namespace wase::scene
{
	void Scene::initialize(const SceneContext& context)
	{
		m_Context = context;

		m_World.registerSystem<ecs::systems::SpriteRenderer>(m_Context.resourcePool);
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