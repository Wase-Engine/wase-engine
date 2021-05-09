#pragma once

#include "component.h"

#include <iostream>
#include <string>
#include <map>
#include <memory>

class Component;

class Entity
{
public:
	Entity(const std::string& name);

	void update();
	void render();

	template<typename T, typename... TArgs>
	inline void addComponent(TArgs&&... args)
	{
		if (components[typeid(T).name()] != nullptr)
		{
			std::cerr << "The entity " << name << " already has the " << typeid(T).name() << " component\n";
			return;
		}

		std::shared_ptr<T> component = std::make_shared<T>(T(std::forward<TArgs>(args)...));

		component->owner = this;
		component->init();

		components[typeid(T).name()] = component;
	}

	template<typename T>
	inline std::shared_ptr<T> getComponent()
	{
		std::shared_ptr<T> component = std::static_pointer_cast<T>(components[typeid(T).name()]);

		if (component == nullptr) {
			std::cerr << "Entity " << name << " does not have a " << typeid(T).name() << "\n";
			std::cerr << "Closing the application...\n";
			exit(0);
		}

		return component;
	}

private:
	std::string name;
	bool enabled = true;
	std::map<std::string, std::shared_ptr<Component>> components;
};