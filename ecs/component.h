#pragma once

#include "entity.h"

class Entity;

class Component
{
public:
	Entity* owner = nullptr;

public:
	virtual void init() = 0;
	virtual void update(float dt) = 0;
	virtual void render() = 0;

	virtual void onStateChange(const bool state);

	bool isActive();
	void setActive(const bool state);

private:
	bool active = true;
};