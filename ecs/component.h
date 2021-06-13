#pragma once

#include "entity.h"

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

	bool isActive();
	void setActive(const bool state);

private:
	bool active = true;
};