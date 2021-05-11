#pragma once

#include "../component.h"

class Transform : public Component
{
public:
	float x, y;

public:
	Transform(const float x, const float y)
	{
		this->x = x;
		this->y = y;
	}

	void init()
	{
	}

	void update(float dt)
	{
	}

	void render()
	{
	}
};