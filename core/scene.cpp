#include "scene.h"

void Scene::startScene()
{
	start();
}

void Scene::updateScene(float dt)
{
	entityManager.update(dt);
	update(dt);
}

void Scene::renderScene()
{
	entityManager.render();
	render();
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