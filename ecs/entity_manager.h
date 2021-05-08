#pragma once

#include "entity.h"

class EntityManager
{
public:
	void update();
	void render();

	Entity* addEntity(const char* name);
	Entity* getEntity(const char* name);

	~EntityManager();

private:
	std::map<const char*, Entity*> entities;
};