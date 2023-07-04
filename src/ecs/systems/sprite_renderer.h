#pragma once

#include <memory>

#include <ecs.h>

#include <resources/resource_pool.h>

namespace wase::ecs::systems
{
	class SpriteRenderer : public System
	{
	public:
		SpriteRenderer(const std::shared_ptr<resources::ResourcePool> resourcePool);

		void onEntityAdded(Entity* entity) override;

		void update(const float deltaTime) override;

	private:
		std::shared_ptr<resources::ResourcePool> m_ResourcePool;
	};
}