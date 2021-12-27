#pragma once

#include "../core/engine.h"
#include "../core/utils/log_utils.h"
#include "component.h"
#include "entity_manager.h"

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>

namespace wase
{
	class Component;
	class EntityManager;

	class Entity
	{
	public:
		EntityManager* entityManager = nullptr;
		Entity* parent = nullptr;
		std::vector<Entity*> children;

	public:
		Entity(const std::string& t_Name);
		~Entity();

		void update(float dt);
		void render();
		void setParent(Entity* entity);

		template<typename T, typename... TArgs>
		inline T* addComponent(TArgs&&... args)
		{
			if (m_Components[typeid(T).name()] != nullptr)
			{
				log_utils::error("The entity " + m_Name + " already has the " + typeid(T).name() + " component");
				return nullptr;
			}

			std::shared_ptr<T> component = std::make_shared<T>(T(std::forward<TArgs>(args)...));

			component->owner = this;
			component->start();

			m_Components[typeid(T).name()] = component;

			return component.get();
		}

		template<typename T>
		inline T* getComponent()
		{
			std::shared_ptr<T> component = std::static_pointer_cast<T>(m_Components[typeid(T).name()]);

			if (component == nullptr)
			{
				Engine::terminate("Entity " + m_Name + " does not have a " + typeid(T).name());
				return nullptr;
			}

			return component.get();
		}

		template<typename T>
		inline bool hasComponent()
		{
			for (const auto& [name, componentPtr] : m_Components)
			{
				if (name == typeid(T).name())
				{
					return true;
				}
			}

			return false;
		}

		template<typename T>
		inline void removeComponent()
		{
			if (hasComponent<T>())
			{
				m_Components.erase(components.find(typeid(T).name()));
			}
			else
			{
				log_utils::error(m_Name + " doesn't have a " + typeid(T).name() + " component. Can't remove it.");
			}
		}

	private:
		std::string m_Name;
		bool m_Enabled = true;
		std::map<std::string, std::shared_ptr<Component>> m_Components;
	};
}