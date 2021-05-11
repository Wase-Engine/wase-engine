#include "entity.h"

#include "components/transform.h"

#include <string>

Entity::Entity(const std::string& name)
{
	this->name = name;
	this->addComponent<Transform>(0.0f, 0.0f);
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