#include "entity_manager.h"

#include "components/transform.h"
#include "component.h"

namespace wase
{
	void EntityManager::update(float dt)
	{
		for (const auto& [entityName, entityPtr] : entities)
		{
			entityPtr->update(dt);
		}
	}

	void EntityManager::render()
	{
		std::multimap<int, Entity*> depthMap;

		// Put the entities in a new map where they are sorted based on the depth
		for (const auto& [entityName, entityPtr] : entities)
		{
			depthMap.insert(std::pair<int, Entity*>(entityPtr->getComponent<Transform>()->depth, entityPtr.get()));
		}

		// Render the sorted depthMap
		for (const auto& [depth, entityPtr] : depthMap)
		{
			entityPtr->render();
		}
	}

	Entity* EntityManager::addEntity(const std::string& name)
	{
		std::shared_ptr<Entity> entity = std::make_shared<Entity>(name);
		entity->entityManager = this;

		entities[name] = entity;

		return entity.get();
	}

	Entity* EntityManager::getEntity(const std::string& name)
	{
		return entities[name].get();
	}
}