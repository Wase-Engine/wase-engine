#pragma once

#include "../ecs/entity_manager.h"

namespace wase
{
	class Scene
	{
	public:
		virtual ~Scene();
		void startScene();
		void updateScene(float dt);
		void renderScene();

		EntityManager* getEntityManager();

	protected:
		EntityManager m_EntityManager;

	protected:
		virtual void start();
		virtual void update(float dt);
		virtual void render();
	};
}