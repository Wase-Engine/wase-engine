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
		transform = owner->getComponent<Transform>();
	}

	bool Collider::onMouseHold(const int button)
	{
		return mouseHover && input::getMouseButton(button);
	}

	bool Collider::onMouseDown(const int button)
	{
		return mouseHover && input::getMouseButtonDown(button);
	}

	bool Collider::onMouseUp(const int button)
	{
		return mouseHover && input::getMouseButtonUp(button);
	}
}