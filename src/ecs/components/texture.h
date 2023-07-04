#pragma once

#include <string>
#include <memory>

#include <ecs.h>

#include <resources/image.h>
#include <resources/color.h>
#include <rendering/vbo.h>
#include <rendering/ibo.h>
#include <rendering/vao.h>
#include <rendering/shader.h>

namespace wase::ecs::components
{
	struct TextureComponent : Component
	{
		unsigned int id;
		std::string image; // The reference in the ResourcePool
		resources::Color color;
		
		std::shared_ptr<rendering::VAO> vao;
		std::shared_ptr<rendering::VBO> vbo;
		std::shared_ptr<rendering::IBO> ibo;
		std::shared_ptr<rendering::Shader> shader;
	};
}