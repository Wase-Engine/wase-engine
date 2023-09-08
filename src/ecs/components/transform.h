#pragma once

#include <ecs.h>

#include <math/vector3.h>

namespace wase::ecs::components
{
	struct TransformComponent : Component
	{
		math::Vector3 position;
		math::Vector3 rotation;
		math::Vector3 scale { 1, 1, 1 };
	};
}