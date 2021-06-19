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

void Entity::setParent(Entity* entity)
{
	if (parent)
	{
		parent->children.erase(std::remove(parent->children.begin(), parent->children.end(), this), parent->children.end());
	}

	entity->children.emplace_back(this);
	parent = entity;
}

Entity::~Entity()
{
	for (const auto& [componentName, componentPtr] : components)
	{
		componentPtr->destroy();
	}
}