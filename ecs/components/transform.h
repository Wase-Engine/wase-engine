#pragma once

#include "../component.h"

class Transform : public Component
{
public:
	int x, y;

	Transform(const int x, const int y)
	{
		this->x = x;
		this->y = y;
	}

	void init() override
	{
	}

	void events() override
	{
	}

	void update() override
	{
	}

	void render() override
	{
	}
};