#pragma once

#include "entity.h"

class Entity;

class Component
{
public:
	Entity* owner;

public:
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	virtual void onStateChange(bool state);

	bool isActive();
	void setActive(bool state);

private:
	bool active = true;
};