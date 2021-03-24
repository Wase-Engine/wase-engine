#pragma once

#include "entity.h"
#include <iostream>

class Entity;

class Component
{
private:
	bool active = true;

public:
	Entity* owner;
	virtual void init() = 0;
	virtual void events() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void onStateChange(bool state);
	bool isActive();
	void setActive(bool state);
	virtual ~Component();
};