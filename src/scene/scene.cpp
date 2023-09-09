#include <scene/scene.h>
#include <ecs/systems/sprite_renderer.h>

namespace wase::scene
{
	Scene::Scene()
		: m_Camera(std::make_shared<rendering::OrthographicCamera>(-1.6f, 1.6f, -0.9f, 0.9f))
	{

	}
	
	void Scene::initialize(const std::shared_ptr<SceneContext> context)
	{
		m_Context = context;
		
		m_World.registerSystem<ecs::systems::SpriteRenderer>(m_Context->resourcePool, m_Camera);
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