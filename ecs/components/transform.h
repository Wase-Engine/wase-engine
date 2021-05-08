#pragma once

#include "../component.h"

class Transform : public Component
{
public:
	int x, y;

	Transform(const int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void init() override
	{
	}

	void update() override
	{
	}

	void render() override
	{
	}
};