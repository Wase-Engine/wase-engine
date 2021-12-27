#include "scene.h"

namespace wase
{
	void Scene::startScene()
	{
		start();
	}

	void Scene::updateScene(float dt)
	{
		m_EntityManager.update(dt);
		update(dt);
	}

	void Scene::renderScene()
	{
		m_EntityManager.render();
		render();
	}

	EntityManager* Scene::getEntityManager()
	{
		return &m_EntityManager;
	}

	Scene::~Scene()
	{
	}

	void Scene::start()
	{

	}

	void Scene::update(float dt)
	{

	}

	void Scene::render()
	{

	}
}