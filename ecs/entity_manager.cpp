#include "entity_manager.h"

void EntityManager::update()
{
	for (std::pair<std::string, Entity*> entity : entities)
	{
		entity.second->update();
	}
}

void EntityManager::render()
{
	for (std::pair<std::string, Entity*> entity : entities)
	{
		entity.second->render();
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
	for (std::pair<std::string, Entity*> entity : entities)
	{
		delete entity.second;
	}

	entities.clear();
}