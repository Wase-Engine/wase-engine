#pragma once

#include "component.h"
#include "entity_manager.h"

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>

class Component;
class EntityManager;

class Entity
{
public:
	EntityManager* entityManager = nullptr;
	Entity* parent = nullptr;
	std::vector<Entity*> children;

public:
	Entity(const std::string& name);
	~Entity();

	void update(float dt);
	void render();
	void setParent(Entity* entity);

	template<typename T, typename... TArgs>
	inline T* addComponent(TArgs&&... args)
	{
		if (components[typeid(T).name()] != nullptr)
		{
			std::cerr << "The entity " << name << " already has the " << typeid(T).name() << " component\n";
			return nullptr;
		}

		std::shared_ptr<T> component = std::make_shared<T>(T(std::forward<TArgs>(args)...));

		component->owner = this;
		component->start();

		components[typeid(T).name()] = component;

		return component.get();
	}

	template<typename T>
	inline T* getComponent()
	{
		std::shared_ptr<T> component = std::static_pointer_cast<T>(components[typeid(T).name()]);

		if (component == nullptr) {
			std::cerr << "Entity " << name << " does not have a " << typeid(T).name() << "\n";
			std::cerr << "Closing the application...\n";
			exit(0);
		}

		return component.get();
	}

	template<typename T>
	inline bool hasComponent()
	{
		for (const auto&[name, componentPtr] : components)
		{
			if (name == typeid(T).name())
			{
				return true;
			}
		}
		
		return false;
	}

private:
	std::string name;
	bool enabled = true;
	std::map<std::string, std::shared_ptr<Component>> components;
};