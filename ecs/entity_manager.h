#pragma once

#include "entity.h"

#include <string>

class EntityManager
{
public:
	void update();
	void render();

	Entity* addEntity(const std::string& name);
	Entity* getEntity(const std::string& name);

	~EntityManager();

private:
	std::map<std::string, Entity*> entities;
};