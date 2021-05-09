#pragma once

#include "entity.h"

#include <string>
#include <memory>

class EntityManager
{
public:
	void update();
	void render();

	std::shared_ptr<Entity> addEntity(const std::string& name);
	std::shared_ptr<Entity> getEntity(const std::string& name);

private:
	std::map<std::string, std::shared_ptr<Entity>> entities;
};