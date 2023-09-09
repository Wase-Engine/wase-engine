#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>

#include <ecs/systems/sprite_renderer.h>
#include <ecs/components/transform.h>
#include <ecs/components/texture.h>
#include <resources/image.h>

namespace wase::ecs::systems
{
	SpriteRenderer::SpriteRenderer(const std::shared_ptr<resources::ResourcePool> resourcePool, const std::shared_ptr<rendering::OrthographicCamera> camera)
		: m_ResourcePool(resourcePool), m_Camera(camera)
	{
		getFilter().require<components::TransformComponent>();
		getFilter().require<components::TextureComponent>();
	}

	void SpriteRenderer::onEntityAdded(Entity* entity)
	{
		components::TextureComponent& texture = m_ComponentPool->getComponent<components::TextureComponent>(entity->getId());

		float vertices[] = {
			// Positions  // TexCoords
			 0.1f,  0.1f, 1.0f, 1.0f,  // TR
			 0.1f, -0.1f, 1.0f, 0.0f,  // BR
			-0.1f, -0.1f, 0.0f, 0.0f,  // BL
			-0.1f,  0.1f, 0.0f, 1.0f   // TL 
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
		layout.pushFloat(2);

		texture.vao->addBuffer(texture.vbo.get(), layout);

		texture.texture = std::make_shared<rendering::Texture>(m_ResourcePool->getImage(texture.image), 0);
		
		texture.shader = std::make_shared<rendering::Shader>("wase-assets/shaders/sprite.vert", "wase-assets/shaders/sprite.frag");
	}

	void SpriteRenderer::update(const float deltaTime)
	{
		for (Entity* entity : m_EnabledEntities)
		{
			components::TransformComponent& transform = m_ComponentPool->getComponent<components::TransformComponent>(entity->getId());
			components::TextureComponent& texture = m_ComponentPool->getComponent<components::TextureComponent>(entity->getId());

			texture.shader->bind();
			texture.shader->setMat4("u_ViewProjection", m_Camera->getViewProjectionMatrix());
			
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::scale(model, transform.scale.toGlmVec3());
			model = glm::translate(model, glm::vec3(transform.position.x, transform.position.y, transform.position.z));
			model = glm::rotate(model, glm::radians(transform.rotation.x), glm::vec3(1, 0, 0));
			model = glm::rotate(model, glm::radians(transform.rotation.y), glm::vec3(0, 1, 0));
			model = glm::rotate(model, glm::radians(transform.rotation.z), glm::vec3(0, 0, 1));
			texture.shader->setMat4("u_Model", model);
			
			texture.vao->bind();
			texture.texture->bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		}
	}
}