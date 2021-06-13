#pragma once

#include "entity.h"

#include <string>
#include <memory>
#include <map>

class Entity;

class EntityManager
{
public:
	void update(float dt);
	void render();

	Entity* addEntity(const std::string& name);
	Entity* getEntity(const std::string& name);

private:
	std::map<std::string, std::shared_ptr<Entity>> entities;
};