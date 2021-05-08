#pragma once

#include "component.h"

#include <iostream>
#include <map>

class Component;

class Entity
{
public:
	Entity(const char* name);
	~Entity();

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

		T* component = new T(std::forward<TArgs>(args)...);

		component->owner = this;
		component->init();

		components[typeid(T).name()] = component;
	}

	template<typename T>
	inline T* getComponent()
	{
		T* component = static_cast<T*>(components[typeid(T).name()]);

		if (component == nullptr) {
			std::cerr << "Entity " << name << " does not have a " << typeid(T).name() << "\n";
			std::cerr << "Closing the application...\n";
			exit(0);
		}

		return component;
	}

private:
	const char* name;
	bool enabled = true;
	std::map<const char*, Component*> components;
};