#include "label.h"

#include "../../../core/managers/resource_manager.h"
#include "../../../core/renderer.h"

#include <SDL_ttf.h>

namespace wase
{
	Label::Label(const char* t_Text, const char* t_Font, const SDL_Color& t_Color) : m_Text(t_Text), m_Font(t_Font), m_Color(t_Color)
	{
		updateText();
	}

	void Label::start()
	{
		m_Transform = owner->getComponent<Transform>();
		m_Camera = &m_Transform->owner->entityManager->camera;
	}

	void Label::update(float dt)
	{
		if (owner->parent && !m_ParentTransform)
			m_ParentTransform = owner->parent->getComponent<Transform>();

		if (!owner->parent)
			m_ParentTransform = nullptr;

		m_Position.x = !m_ParentTransform ? (int)(m_Transform->position.x - m_Camera->position.x) : (int)(m_Transform->position.x + m_ParentTransform->position.x - m_Camera->position.x);
		m_Position.y = !m_ParentTransform ? (int)(m_Transform->position.y - m_Camera->position.y) : (int)(m_Transform->position.y + m_ParentTransform->position.y - m_Camera->position.y);
	}

	void Label::render()
	{
		SDL_RenderCopy(Renderer::getRenderer(), m_Texture, NULL, &m_Position);
	}

	void Label::setText(const std::string& text)
	{
		this->m_Text = text;

		updateText();
	}

	void Label::setFont(const char* font)
	{
		this->m_Font = font;

		updateText();
	}

	void Label::setColor(SDL_Color& color)
	{
		this->m_Color = color;

		updateText();
	}

	Size Label::getSize() const
	{
		Size size;

		TTF_SizeText(ResourceManager::getFont(m_Font), m_Text.c_str(), &size.w, &size.h);

		return size;
	}

	void Label::updateText()
	{
		SDL_Surface* surface = TTF_RenderText_Blended(ResourceManager::getFont(m_Font), m_Text.c_str(), m_Color);

		m_Texture = SDL_CreateTextureFromSurface(Renderer::getRenderer(), surface);

		SDL_FreeSurface(surface);

		SDL_QueryTexture(m_Texture, nullptr, nullptr, &m_Position.w, &m_Position.h);
	}
}