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

Entity* EntityManager::addEntity(const std::string& name)
{
	Entity* entity = new Entity(name);

	entities[name] = entity;

	return entity;
}

Entity* EntityManager::getEntity(const std::string& name)
{
	return entities[name];
}

EntityManager::~EntityManager()
{
	for (const auto&[entityName, entityPtr] : entities)
	{
		delete entityPtr;
	}

	entities.clear();
}