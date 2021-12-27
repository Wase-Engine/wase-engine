#include "component.h"

namespace wase
{
	void Component::start()
	{
	}

	void Component::update(float dt)
	{
	}

	void Component::render()
	{
	}

	void Component::destroy()
	{
	}

	void Component::onStateChange(const bool state)
	{
	}

	bool Component::isActive() const
	{
		return m_Active;
	}

	void Component::setActive(const bool state)
	{
		m_Active = state;
		onStateChange(state);
	}

	Component::~Component()
	{
	}
}