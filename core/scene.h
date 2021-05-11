#pragma once

#include "../ecs/entity_manager.h"

class Scene
{
public:
	void startScene();
	void updateScene(float dt);
	void renderScene();

protected:
	EntityManager entityManager;

protected:
	virtual void start();
	virtual void update(float dt);
	virtual void render();
};