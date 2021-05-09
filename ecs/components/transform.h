#pragma once

#include "../component.h"

class Transform : public Component
{
public:
	int x, y;

public:
	Transform(const int x, const int y)
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