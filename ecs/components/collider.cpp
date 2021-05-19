#include "collider.h"

#include "../../core/input.h"

Collider::Collider()
{

}

void Collider::init()
{
	transform = owner->getComponent<Transform>();
}

bool Collider::onMouseDown(const int button)
{
	if (!mouseHover)
		return false;

	return input::getMouseButtonDown(button);
}

bool Collider::onMouseUp(const int button)
{
	if (!mouseHover)
		return false;

	return input::getMouseButtonUp(button);
}