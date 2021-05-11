#include "component.h"

void Component::init()
{
}

void Component::update(float dt)
{
}

void Component::render()
{
}

void Component::onStateChange(const bool state)
{
}

bool Component::isActive()
{
	return active;
}

void Component::setActive(const bool state)
{
	active = state;
	onStateChange(state);
}