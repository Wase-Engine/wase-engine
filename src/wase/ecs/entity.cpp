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
	if (!entity)
	{
		if (parent)
			parent->children.erase(std::remove(parent->children.begin(), parent->children.end(), this), parent->children.end());

		parent = nullptr;
		return;
	}

	// If the entity already has a parent remove the entity from the current parent its list of children
	if (parent)
	{
		parent->children.erase(std::remove(parent->children.begin(), parent->children.end(), this), parent->children.end());
	}

	// Add the entity to the list of children from the parent
	entity->children.emplace_back(this);

	// Set the parent for the entity
	parent = entity;
}

Entity::~Entity()
{
	for (const auto& [componentName, componentPtr] : components)
	{
		if (componentPtr)
		{
			componentPtr->destroy();
		}
	}
}