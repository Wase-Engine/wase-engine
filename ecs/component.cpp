#include "component.h"

void Component::init()
{
}

void Component::events()
{
}

void Component::update()
{
}

void Component::render()
{
}

void Component::onStateChange(bool state)
{
}

bool Component::isActive()
{
	return active;
}

void Component::setActive(bool state)
{
	active = state;
	onStateChange(state);
}

Component::~Component()
{
}