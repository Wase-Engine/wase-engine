#include "entity.h"

#include "components/transform.h"

Entity::Entity(const char* name)
{
	this->name = name;
	this->addComponent<Transform>(0, 0);
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

Entity::~Entity()
{
	for (std::pair<const char*, Component*> component : components)
	{
		delete component.second;
	}

	components.clear();
}