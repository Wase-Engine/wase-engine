#include "entity_manager.h"

#include "components/transform.h"

#include <map>

void EntityManager::update(float dt)
{
	for (const auto&[entityName, entityPtr] : entities)
	{
		entityPtr->update(dt);
	}
}

void EntityManager::render()
{
	std::map<int, Entity*> depthMap;

	// Put the entities in a new map where they are sorted based on the depth
	for (const auto& [entityName, entityPtr] : entities)
	{
		depthMap[entityPtr->getComponent<Transform>()->depth] = entityPtr.get();
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

	entities[name] = entity;

	return entity.get();
}

Entity* EntityManager::getEntity(const std::string& name)
{
	return entities[name].get();
}