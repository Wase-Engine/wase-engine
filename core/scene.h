#pragma once

#include "../ecs/entity_manager.h"

class Scene
{
public:
	void startScene();
	void updateScene();
	void renderScene();

protected:
	EntityManager entityManager;

protected:
	virtual void start();
	virtual void update();
	virtual void render();
};