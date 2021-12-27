#include "sprite_renderer.h"

#include "animator.h"

namespace wase
{
	SpriteRenderer::SpriteRenderer(const std::string& t_Name, const int t_SizeX, const int t_SizeY)
		: m_SizeX(t_SizeX), m_SizeY(t_SizeY)
	{
		m_Texture = ResourceManager::getTexture(t_Name);
	}

	void SpriteRenderer::start()
	{
		m_Transform = owner->getComponent<Transform>();
		m_Camera = &m_Transform->owner->entityManager->camera;
	}

	void SpriteRenderer::update(float dt)
	{
		if (owner->parent && !m_ParentTransform)
			m_ParentTransform = owner->parent->getComponent<Transform>();

		if (!owner->parent)
			m_ParentTransform = nullptr;

		rect.x = m_ParentTransform ? (int)(m_Transform->position.x + m_ParentTransform->position.x - m_Camera->position.x) : (int)(m_Transform->position.x - m_Camera->position.x);
		rect.y = m_ParentTransform ? (int)(m_Transform->position.y + m_ParentTransform->position.y - m_Camera->position.y) : (int)(m_Transform->position.y - m_Camera->position.y);

		rect.w = (int)(m_SizeX);
		rect.h = (int)(m_SizeY);
	}

	void SpriteRenderer::render()
	{
		SDL_SetTextureColorMod(m_Texture, color.r, color.g, color.b);

		if (owner->hasComponent<Animator>())
		{
			SDL_RenderCopy(Renderer::getRenderer(), m_Texture, &owner->getComponent<Animator>()->rect, &rect);
		}
		else
		{
			SDL_RenderCopy(Renderer::getRenderer(), m_Texture, NULL, &rect);
		}
	}
}