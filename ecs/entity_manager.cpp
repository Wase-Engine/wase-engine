#include "entity_manager.h"

EntityManager* EntityManager::instance = nullptr;

void EntityManager::events()
{
	for (std::pair<const char*, Entity*> entity : entities)
	{
		entity.second->events();
	}
}

void EntityManager::update()
{
	for (std::pair<const char*, Entity*> entity : entities)
	{
		entity.second->update();
	}
}

void EntityManager::render()
{
	for (std::pair<const char*, Entity*> entity : entities)
	{
		entity.second->render();
	}
}

Entity* EntityManager::addEntity(const char* name)
{
	Entity* entity = new Entity(name);

	entities[name] = entity;

	return entity;
}

Entity* EntityManager::getEntity(const char* name)
{
	return entities[name];
}

EntityManager* EntityManager::getInstance()
{
	return instance = (instance != nullptr) ? instance : new EntityManager();
}

EntityManager::~EntityManager()
{
	for (std::pair<const char*, Entity*> entity : entities)
	{
		delete entity.second;
	}

	entities.clear();
}