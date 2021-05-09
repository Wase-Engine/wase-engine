#include "entity_manager.h"

void EntityManager::update()
{
	for (const auto&[entityName, entityPtr] : entities)
	{
		entityPtr->update();
	}
}

void EntityManager::render()
{
	for (const auto& [entityName, entityPtr] : entities)
	{
		entityPtr->render();
	}
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& name)
{
	std::shared_ptr<Entity> entity = std::make_shared<Entity>(name);

	entities[name] = entity;

	return entity;
}

std::shared_ptr<Entity> EntityManager::getEntity(const std::string& name)
{
	return entities[name];
}