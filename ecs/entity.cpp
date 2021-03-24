#include "entity.h"

Entity::Entity(const std::string& name)
{
	this->name = name;
}

Entity::~Entity()
{
	for (std::pair<const char*, Component*> component : components)
	{
		delete component.second;
	}

	components.clear();
}

void Entity::init()
{
	for (std::pair<const char*, Component*> component : components)
	{
		component.second->init();
	}
}

void Entity::events()
{
	for (std::pair<const char*, Component*> component : components)
	{
		if (component.second->isActive())
		{
			component.second->events();
		}
	}
}

void Entity::update()
{
	for (std::pair<const char*, Component*> component : components)
	{
		if (component.second->isActive())
		{
			component.second->update();
		}
	}
}

void Entity::render()
{
	for (std::pair<const char*, Component*> component : components)
	{
		if (component.second->isActive())
		{
			component.second->render();
		}
	}
}