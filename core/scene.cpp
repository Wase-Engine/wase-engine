#include "scene.h"

void Scene::startScene()
{
	start();
}

void Scene::updateScene()
{
	entityManager.update();
	update();
}

void Scene::renderScene()
{
	entityManager.render();
	render();
}

void Scene::start()
{

}

void Scene::update()
{

}

void Scene::render()
{

}