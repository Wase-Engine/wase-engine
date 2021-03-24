#pragma once

#include "entity.h"

class EntityManager
{
private:
	static EntityManager* instance;

	std::map<const char*, Entity*> entities;

public:
	void events();
	void update();
	void render();

	Entity* addEntity(const char* name);
	Entity* getEntity(const char* name);

	~EntityManager();

	static EntityManager* getInstance();
};