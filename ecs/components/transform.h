#pragma once

#include "../component.h"

#include <iostream>

class Transform : public Component
{
public:
	int x, y;

	Transform(const int x, const int y) : x(x), y(y)
	{
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