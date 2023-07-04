#include <GL/glew.h>

#include <ecs/systems/sprite_renderer.h>
#include <ecs/components/transform.h>
#include <ecs/components/texture.h>
#include <resources/image.h>

namespace wase::ecs::systems
{
	SpriteRenderer::SpriteRenderer(const std::shared_ptr<resources::ResourcePool> resourcePool)
		: m_ResourcePool(resourcePool)
	{
		getFilter().require<components::TransformComponent>();
		getFilter().require<components::TextureComponent>();
	}

	void SpriteRenderer::onEntityAdded(Entity* entity)
	{
		components::TextureComponent& texture = m_ComponentPool->getComponent<components::TextureComponent>(entity->getId());

		float vertices[] = {
			 0.5f,  0.5f,  // TR
			 0.5f, -0.5f,  // BR
			-0.5f, -0.5f,  // BL
			-0.5f,  0.5f   // TL 
		};

		unsigned int indices[] = {
			0, 1, 3,
			1, 2, 3
		};

		texture.vao = std::make_shared<rendering::VAO>();
		texture.vao->bind();

		texture.vbo = std::make_shared<rendering::VBO>();
		texture.vbo->bind();
		texture.vbo->setData(vertices, sizeof(vertices));

		texture.ibo = std::make_shared<rendering::IBO>();
		texture.ibo->bind();
		texture.ibo->setData(indices, sizeof(indices));
	
		rendering::VertexBufferLayout layout;
		layout.pushFloat(2);

		texture.vao->addBuffer(texture.vbo.get(), layout);
		
		texture.shader = std::make_shared<rendering::Shader>("assets/shader.vert", "assets/shader.frag");
	}

	void SpriteRenderer::update(const float deltaTime)
	{
		for (Entity* entity : m_EnabledEntities)
		{
			components::TransformComponent& transform = m_ComponentPool->getComponent<components::TransformComponent>(entity->getId());
			components::TextureComponent& texture = m_ComponentPool->getComponent<components::TextureComponent>(entity->getId());

			//glActiveTexture(GL_TEXTURE0);
			//glBindTexture(GL_TEXTURE_2D, texture.id);

			texture.shader->bind();
			texture.vao->bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		}
	}
}