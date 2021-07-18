#pragma once

#include "../component.h"
#include "../../core/vector2.h"

class Transform : public Component
{
public:
	Vector2 position;
	int depth;

public:
	Transform(const float x = 0, const float y = 0, const int depth = 0)
	{
		this->position.x = x;
		this->position.y = y;
		this->depth = depth;
	}

	void setPosition(float x, float y)
	{
		this->position.x = x;
		this->position.y = y;
	}
};