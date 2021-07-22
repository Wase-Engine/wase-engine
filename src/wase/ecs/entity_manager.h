#pragma once

#include "entity.h"
#include "camera.h"

#include <string>
#include <memory>
#include <map>

namespace wase
{
	class Entity;

	class EntityManager
	{
	public:
		Camera camera;

	public:
		void update(float dt);
		void render();

		Entity* addEntity(const std::string& name);
		Entity* getEntity(const std::string& name);

	private:
		std::map<std::string, std::shared_ptr<Entity>> entities;
	};
}