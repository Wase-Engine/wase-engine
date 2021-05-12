#include "entity_manager.h"

void EntityManager::update(float dt)
{
	for (const auto&[entityName, entityPtr] : entities)
	{
		entityPtr->update(dt);
	}
}

void EntityManager::render()
{
	for (const auto& [entityName, entityPtr] : entities)
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