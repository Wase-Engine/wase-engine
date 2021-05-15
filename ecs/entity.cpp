#include "entity.h"

#include "components/transform.h"

#include <string>

Entity::Entity(const std::string& name)
{
	this->name = name;
	this->addComponent<Transform>();
}

void Entity::update(float dt)
{
	for (const auto&[componentName, componentPtr] : components)
	{
		if (componentPtr->isActive())
		{
			componentPtr->update(dt);
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
		componentPtr->destroy();
	}
}