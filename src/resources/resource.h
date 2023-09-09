#pragma once

#include <string>

#include <resources/resource_type.h>

namespace wase::resources
{
	struct Resource
	{
		std::string name;
		ResourceType type;
		std::string path;
	};
}