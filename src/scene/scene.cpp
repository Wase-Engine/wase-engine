#include <scene/scene.h>
#include <ecs/systems/sprite_renderer.h>

namespace wase::scene
{
	Scene::Scene()
		: m_Camera(std::make_shared<rendering::OrthographicCamera>(-1.6f, 1.6f, -0.9f, 0.9f)), m_PhysicsWorld(b2Vec2(0.0f, -9.81f))
	{

	}
	
	void Scene::initialize(const std::shared_ptr<SceneContext> context)
	{
		m_Context = context;
		
		m_ECSWorld.registerSystem<ecs::systems::SpriteRenderer>(m_Context->resourcePool, m_Camera);
	}

	void Scene::updateWorld(const float deltaTime)
	{
		m_ECSWorld.update(deltaTime);
	}

	void Scene::start()
	{

	}
	
	void Scene::update(const float deltaTime)
	{
		
	}
}