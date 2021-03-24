#pragma once

#include "entity.h"

class EntityManager
{
private:
	static EntityManager* instance;

	std::map<std::string, Entity*> entities;

public:
	void init();
	void events();
	void update();
	void render();

	Entity* addEntity(const std::string& name);
	Entity* getEntity(const std::string& name);

	~EntityManager();

	static EntityManager* getInstance();
};