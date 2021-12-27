#pragma once

#include "../component.h"
#include "../../core/vector2.h"

namespace wase
{
	class Transform : public Component
	{
	public:
		Vector2 position;
		int depth;

	public:
		Transform(const float t_X = 0, const float t_Y = 0, const int t_Depth = 0)
			: depth(t_Depth)
		{
			this->position.x = t_X;
			this->position.y = t_Y;
		}

		void setPosition(float x, float y)
		{
			this->position.x = x;
			this->position.y = y;
		}
	};
}