#pragma once

#include "entity.h"

namespace wase
{
	class Entity;

	class Component
	{
	public:
		Entity* owner = nullptr;

	public:
		virtual void start();
		virtual void update(float dt);
		virtual void render();
		virtual void destroy();

		virtual void onStateChange(const bool state);

		bool isActive() const;
		void setActive(const bool state);

	protected:
		virtual ~Component();

	private:
		bool m_Active = true;
	};
}