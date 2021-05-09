#include "entity.h"

#include "components/transform.h"

#include <string>

Entity::Entity(const std::string& name)
{
	this->name = name;
	this->addComponent<Transform>(0, 0);
}

void Entity::update()
{
	for (const auto&[componentName, componentPtr] : components)
	{
		if (componentPtr->isActive())
		{
			componentPtr->update();
		}
	}
}

void Entity::render()
{
	for (const auto& [componentName, componentPtr] : components)
	{
		if (componentPtr->isActive())
		{
			componentPtr->render();
		}
	}
}

Entity::~Entity()
{
	for (const auto& [componentName, componentPtr] : components)
	{
		delete componentPtr;
	}

	components.clear();
}