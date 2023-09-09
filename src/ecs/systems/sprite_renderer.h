#pragma once

#include <memory>

#include <ecs.h>

#include <resources/resource_pool.h>
#include <rendering/orthographic_camera.h>

namespace wase::ecs::systems
{
	class SpriteRenderer : public System
	{
	public:
		SpriteRenderer(const std::shared_ptr<resources::ResourcePool> resourcePool, const std::shared_ptr<rendering::OrthographicCamera> camera);

		void onEntityAdded(Entity* entity) override;

		void update(const float deltaTime) override;

	private:
		std::shared_ptr<resources::ResourcePool> m_ResourcePool;
		std::shared_ptr<rendering::OrthographicCamera> m_Camera;
	};
}