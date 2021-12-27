#include "collider.h"

#include "../../../core/input.h"

namespace wase
{
	Collider::~Collider()
	{
	}

	Collider::Collider()
	{

	}

	void Collider::start()
	{
		m_Transform = owner->getComponent<Transform>();
	}

	bool Collider::onMouseHold(const int button)
	{
		return m_MouseHover && input::getMouseButton(button);
	}

	bool Collider::onMouseDown(const int button)
	{
		return m_MouseHover && input::getMouseButtonDown(button);
	}

	bool Collider::onMouseUp(const int button)
	{
		return m_MouseHover && input::getMouseButtonUp(button);
	}
}